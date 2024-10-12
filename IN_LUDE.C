
//**************************************************************************
//**
//** in_lude.c : Heretic 2 : Raven Software, Corp.
//**
//** $RCSfile: in_lude.c,v $
//** $Revision: 1.17 $
//** $Date: 95/10/12 18:01:20 $
//** $Author: cjr $
//**
//**************************************************************************

#include "h2def.h"
#include <ctype.h>

// MACROS ------------------------------------------------------------------

#define	TEXTSPEED	3
#define	TEXTWAIT	140

// TYPES -------------------------------------------------------------------

typedef enum
{
	SINGLE,
	COOPERATIVE,
	DEATHMATCH
} gametype_t;

// EXTERNAL FUNCTION PROTOTYPES --------------------------------------------

// PUBLIC FUNCTION PROTOTYPES ----------------------------------------------

void IN_Start(void);
void IN_Ticker(void);
void IN_Drawer(void);

// PRIVATE FUNCTION PROTOTYPES ---------------------------------------------

static void WaitStop(void);
static void Stop(void);
static void LoadPics(void);
static void UnloadPics(void);
static void CheckForSkip(void);
static void InitStats(void);
static void DrawDMStats(void);
static void DrawNumber(int val, int x, int y, int digits);
static void DrTextB(char *text, int x, int y);
static void DrawVerticalText(char *text, int x, int y);
static void DrawHubText(void);

// EXTERNAL DATA DECLARATIONS ----------------------------------------------

// PUBLIC DATA DECLARATIONS ------------------------------------------------

boolean intermission;

// PRIVATE DATA DEFINITIONS ------------------------------------------------

static boolean skipintermission;
static int interstate = 0;
static int intertime = -1;
static gametype_t gametype;
static int cnt;
static int slaughterboy; // in DM, the player with the most kills
static patch_t *patchINTERPIC;
static patch_t *FontBNumbers[10];
static patch_t *FontBNegative;
static patch_t *FontBSlash;
static patch_t *FontBPercent;
static int FontABaseLump;
static int FontBLump;
static int FontBLumpBase;

static signed int totalFrags[MAXPLAYERS];
static char *KillersText = { "KILLERS" };

static int HubCount;
static char *HubText;

// CODE --------------------------------------------------------------------

//========================================================================
//
// IN_Start
//
//========================================================================

extern void AM_Stop (void);

void IN_Start(void)
{
	int i;
	I_SetPalette(W_CacheLumpName("PLAYPAL", PU_CACHE));
	InitStats();
	LoadPics();
	intermission = true;
	interstate = 0;
	skipintermission = false;
	intertime = 0;
	AM_Stop();
	for(i = 0; i < MAXPLAYERS; i++)
	{
		players[i].messageTics = 0;
		players[i].message[0] = 0;
	}
	SN_StopAllSequences();	
}

//========================================================================
//
// WaitStop
//
//========================================================================

void WaitStop(void)
{
	if(!--cnt)
	{
		Stop();
//		gamestate = GS_LEVEL;
//		G_DoLoadLevel();
		gameaction = ga_leavemap;
//		G_WorldDone();
	}
}

//========================================================================
//
// Stop
//
//========================================================================

static void Stop(void)
{
	intermission = false;
	UnloadPics();
	SB_state = -1;
	BorderNeedRefresh = true;
}

//========================================================================
//
// InitStats
//
// 	Initializes the stats for single player mode
//========================================================================

char *HubTextDefs[] = 
{
	TXT_INTER_HUB1,
	TXT_INTER_HUB2,
	TXT_INTER_HUB3,
	TXT_INTER_HUB4
};

static void InitStats(void)
{
	int oldCluster;
	int i;
	int j;
	signed int slaughterfrags;
	int posnum;
	int slaughtercount;
	int playercount;

	extern int LeaveMap;

	if(!deathmatch)
	{
		gametype = SINGLE;
		HubCount = 0;
		oldCluster = P_GetMapCluster(gamemap);
		if(oldCluster != P_GetMapCluster(LeaveMap))
		{
			if(oldCluster >= 1 && oldCluster <= 5)
			{ 
				HubText = HubTextDefs[oldCluster-1];
				HubCount = strlen(HubText)*TEXTSPEED+TEXTWAIT;
				S_StartSongName("hub", true);
			}
		}
	}
	else
	{
		gametype = DEATHMATCH;
		slaughterboy = 0;
		slaughterfrags = -9999;
		posnum = 0;
		playercount = 0;
		slaughtercount = 0;
		for(i=0; i<MAXPLAYERS; i++)
		{
			totalFrags[i] = 0;
			if(playeringame[i])
			{
				playercount++;
				for(j=0; j<MAXPLAYERS; j++)
				{
					if(playeringame[j])
					{
						totalFrags[i] += players[i].frags[j];
					}
				}
				posnum++;
			}
			if(totalFrags[i] > slaughterfrags)
			{
				slaughterboy = 1<<i;
				slaughterfrags = totalFrags[i];
				slaughtercount = 1;
			}
			else if(totalFrags[i] == slaughterfrags)
			{
				slaughterboy |= 1<<i;
				slaughtercount++;
			}
		}
		if(playercount == slaughtercount)
		{ // don't do the slaughter stuff if everyone is equal
			slaughterboy = 0;
		}
		S_StartSongName("hub", true);
	}
}

//========================================================================
//
// LoadPics
//
//========================================================================

static void LoadPics(void)
{
	int i;

	if(HubCount || gametype == DEATHMATCH)
	{
		patchINTERPIC = W_CacheLumpName("INTERPIC", PU_STATIC);
		FontBLumpBase = W_GetNumForName("FONTB16");
		for(i=0; i<10; i++)
		{
			FontBNumbers[i] = W_CacheLumpNum(FontBLumpBase+i, PU_STATIC);
		}
		FontBLump = W_GetNumForName("FONTB_S")+1;
		FontBNegative = W_CacheLumpName("FONTB13", PU_STATIC);
		FontABaseLump = W_GetNumForName("FONTA_S")+1;
	
		FontBSlash = W_CacheLumpName("FONTB15", PU_STATIC);
		FontBPercent = W_CacheLumpName("FONTB05", PU_STATIC);
	}
}

//========================================================================
//
// UnloadPics
//
//========================================================================

static void UnloadPics(void)
{
	int i;

	if(HubCount || gametype == DEATHMATCH)
	{
		Z_ChangeTag(patchINTERPIC, PU_CACHE);
		for(i=0; i<10; i++)
		{
			Z_ChangeTag(FontBNumbers[i], PU_CACHE);
		}
		Z_ChangeTag(FontBNegative, PU_CACHE);
		Z_ChangeTag(FontBSlash, PU_CACHE);
		Z_ChangeTag(FontBPercent, PU_CACHE);
	}
}

//========================================================================
//
// IN_Ticker
//
//========================================================================

void IN_Ticker(void)
{
	if(!intermission)
	{
		return;
	}
	if(interstate)
	{
		WaitStop();
		return;
	}
	skipintermission = false;
	CheckForSkip();
	intertime++;
	if(skipintermission || (gametype == SINGLE && !HubCount))
	{
		interstate = 1;
		cnt = 10;
		skipintermission = false;
		//S_StartSound(NULL, sfx_dorcls);
	}
}

//========================================================================
//
// CheckForSkip
//
// 	Check to see if any player hit a key
//========================================================================

static void CheckForSkip(void)
{
  	int i;
	player_t *player;
	static boolean triedToSkip;

  	for(i = 0, player = players; i < MAXPLAYERS; i++, player++)
	{
    	if(playeringame[i])
    	{
			if(player->cmd.buttons&BT_ATTACK)
			{
				if(!player->attackdown)
				{
					skipintermission = 1;
				}
				player->attackdown = true;
			}
			else
			{
				player->attackdown = false;
			}
			if(player->cmd.buttons&BT_USE)
			{
				if(!player->usedown)
				{
					skipintermission = 1;
				}
				player->usedown = true;
			}
			else
			{
				player->usedown = false;
			}
		}
	}
	if(deathmatch && intertime < 140)
	{ // wait for 4 seconds before allowing a skip
		if(skipintermission == 1)
		{
			triedToSkip = true;
			skipintermission = 0;
		}
	}
	else
	{
		if(triedToSkip)
		{
			skipintermission = 1;
			triedToSkip = false;
		}
	}
}

//========================================================================
//
// IN_Drawer
//
//========================================================================

void IN_Drawer(void)
{
	if(!intermission)
	{
		return;
	}
	if(interstate)
	{
		return;
	}
	UpdateState |= I_FULLSCRN;
	memcpy(screen, (byte *)patchINTERPIC, SCREENWIDTH*SCREENHEIGHT);

	if(gametype == SINGLE)
	{
		if(HubCount)
		{
			DrawHubText();
		}
	}
	else
	{	
		DrawDMStats();
	}
}

//========================================================================
//
// DrawDMStats
//
//========================================================================

static char *PlayerColors[] = { "BLUE", "RED", "YELLOW", "GREEN" };

static void DrawDMStats(void)
{
	int i;
	int j;
	int ypos;
	int xpos;
	int kpos;

	static int sounds;

	xpos = 68;
	ypos = 50;

	DrTextB("TOTAL", 270, 27);
	DrTextB("VICTIMS", 125, 8);
	for(i=0; i<7; i++)
	{
 		DrawVerticalText(KillersText, 7, 44);
	}
	if(intertime < 20)
	{
		sounds = 0;
		return;
	}
	if(intertime >= 20 && sounds < 1)
	{
		S_StartSound(NULL, SFX_PLATFORM_STOP);
		sounds++;
	}
	for(i=0; i<MAXPLAYERS; i++)
	{
		if(playeringame[i])
		{
			kpos = 50;
			for(j=0; j<MAXPLAYERS; j++)
			{
				if(playeringame[j])
				{
					DrawNumber(players[i].frags[j], kpos, ypos, 3);
					kpos += 50;
				}
	      	}
			if(slaughterboy&(1<<i))
			{
				if(!(intertime&16))
				{
					DrawNumber(totalFrags[i], 263, ypos, 3);
				}
			}
			else
			{
			 	DrawNumber(totalFrags[i], 263, ypos, 3);
			}
			if(i == consoleplayer)
			{
				MN_DrTextAYellow(PlayerColors[i], xpos, 35);
				MN_DrTextAYellow(PlayerColors[i], 28, ypos+5);
			}
			else
			{
				MN_DrTextA(PlayerColors[i], xpos, 35);
				MN_DrTextA(PlayerColors[i], 28, ypos+5);
			}
			xpos += 50;
			ypos += 30;
		}
	}
}

//========================================================================
//
// DrawNumber
//
//========================================================================

static void DrawNumber(int val, int x, int y, int digits)
{
	patch_t *patch;
	int xpos;
	int oldval;
	int realdigits;
	boolean neg;

	oldval = val;
	xpos = x;
	neg = false;
	realdigits = 1;

	if(val < 0)
	{ //...this should reflect negative frags
		val = -val;
		neg = true;
		if(val > 99)
		{
			val = 99;
		}
	}
	if(val > 9)
	{
		realdigits++;
		if(digits < realdigits)
		{
			realdigits = digits;
			val = 9;
		}
	}
	if(val > 99)
	{
		realdigits++;
		if(digits < realdigits)
		{
			realdigits = digits;
			val = 99;
		}
	}
	if(val > 999)
	{
		realdigits++;
		if(digits < realdigits)
		{
			realdigits = digits;
			val = 999;
		}
	}
	if(digits == 4)
	{
		patch = FontBNumbers[val/1000];
		V_DrawShadowedPatch(xpos+6-patch->width/2-12, y, patch);
	}
	if(digits > 2)
	{
		if(realdigits > 2)
		{
			patch = FontBNumbers[val/100];
			V_DrawShadowedPatch(xpos+6-patch->width/2, y, patch);
		}
		xpos += 12;
	}
	val = val%100;
	if(digits > 1)
	{
		if(val > 9)
		{
			patch = FontBNumbers[val/10];
			V_DrawShadowedPatch(xpos+6-patch->width/2, y, patch);
		}
		else if(digits == 2 || oldval > 99)
		{
			V_DrawShadowedPatch(xpos, y, FontBNumbers[0]);
		}
		xpos += 12;
	}
	val = val%10;
	patch = FontBNumbers[val];
	V_DrawShadowedPatch(xpos+6-patch->width/2, y, patch);
	if(neg)
	{
		patch = FontBNegative;
		V_DrawShadowedPatch(xpos+6-patch->width/2-12*(realdigits), y, patch);
	}
}

//========================================================================
//
// DrTextB
//
//========================================================================

static void DrTextB(char *text, int x, int y)
{
	char c;
	patch_t *p;

	while((c = *text++) != 0)
	{
		if(c < 33)
		{
			x += 8;
		}
		else
		{
			p = W_CacheLumpNum(FontBLump+c-33, PU_CACHE);
			V_DrawShadowedPatch(x, y, p);
			x += p->width-1;
		}
	}
}

//===========================================================================
//
// DrawHubText
//
//===========================================================================

static void DrawHubText(void)
{
	int		count;
	char	*ch;
	int		c;
	int		cx, cy;
	patch_t *w;

	cy = 5;
	cx = 10;
	ch = HubText;
	count = (intertime-10)/TEXTSPEED;
	if (count < 0)
	{
		count = 0;
	}
	for(; count; count--)
	{
		c = *ch++;
		if(!c)
		{
			break;
		}
		if(c == '\n')
		{
			cx = 10;
			cy += 9;
			continue;
		}
		c = toupper(c);
		if(c < 33)
		{
			cx += 5;
			continue;
		}
		w = W_CacheLumpNum(FontABaseLump+c-33, PU_CACHE);
		if(cx+w->width > SCREENWIDTH)
		{
			break;
		}
		V_DrawPatch(cx, cy, w);
		cx += w->width;
	}
}

//===========================================================================
//
// DrawVerticalText
//
//===========================================================================

static void DrawVerticalText(char *text, int x, int y)
{
	char c;
	patch_t *p;

	while((c = *text++) != 0)
	{
		if(c < 33)
		{
			y += 12;
		}
		else
		{
			p = W_CacheLumpNum(FontBLump+c-33, PU_CACHE);
			V_DrawShadowedPatch(x+(9-p->width/2), y, p);
			y += p->height+2;
		}
	}
}
