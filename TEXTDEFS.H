
//**************************************************************************
//**
//** textdefs.h : Heretic 2 : Raven Software, Corp.
//**
//** $RCSfile: textdefs.h,v $
//** $Revision: 1.33 $
//** $Date: 95/10/13 03:00:24 $
//** $Author: cjr $
//**
//**************************************************************************

// MN_menu.c ---------------------------------------------------------------

#define PRESSKEY	"press a key."
#define PRESSYN		"press y or n."
#define TXT_PAUSED	"PAUSED"
#define QUITMSG		"are you sure you want to\nquit this great game?"
#define LOADNET		"you can't do load while in a net game!\n\n"PRESSKEY
#define QLOADNET	"you can't quickload during a netgame!\n\n"PRESSKEY
#define QSAVESPOT	"you haven't picked a quicksave slot yet!\n\n"PRESSKEY
#define SAVEDEAD 	"you can't save if you aren't playing!\n\n"PRESSKEY
#define QSPROMPT 	"quicksave over your game named\n\n'%s'?\n\n"PRESSYN
#define QLPROMPT	"do you want to quickload the game named"\
					"\n\n'%s'?\n\n"PRESSYN
#define NEWGAME		"you can't start a new game\n"\
					"while in a network game.\n\n"PRESSKEY
#define NIGHTMARE	"are you sure? this skill level\n"\
					"isn't even remotely fair.\n\n"PRESSYN
#define SWSTRING	"this is the shareware version of doom.\n\n"\
					"you need to order the entire trilogy.\n\n"PRESSKEY
#define MSGOFF		"Messages OFF"
#define MSGON		"Messages ON"
#define NETEND		"you can't end a netgame!\n\n"PRESSKEY
#define ENDGAME		"are you sure you want to end the game?\n\n"PRESSYN
#define DOSY		"(press y to quit to dos.)"
#define DETAILHI	"High detail"
#define DETAILLO	"Low detail"
#define TXT_GAMMA_LEVEL_OFF	"GAMMA CORRECTION OFF"
#define TXT_GAMMA_LEVEL_1	"GAMMA CORRECTION LEVEL 1"
#define TXT_GAMMA_LEVEL_2	"GAMMA CORRECTION LEVEL 2"
#define TXT_GAMMA_LEVEL_3	"GAMMA CORRECTION LEVEL 3"
#define TXT_GAMMA_LEVEL_4	"GAMMA CORRECTION LEVEL 4"
#define	EMPTYSTRING	"empty slot"

// P_inter.c ---------------------------------------------------------------

// Mana

#define TXT_MANA_1				"BLUE MANA"
#define TXT_MANA_2				"GREEN MANA"
#define TXT_MANA_BOTH			"COMBINED MANA"

// Keys

#define	TXT_KEY_STEEL		"STEEL KEY"
#define	TXT_KEY_CAVE		"CAVE KEY"
#define	TXT_KEY_AXE			"AXE KEY"
#define	TXT_KEY_FIRE		"FIRE KEY"
#define	TXT_KEY_EMERALD		"EMERALD KEY"
#define	TXT_KEY_DUNGEON		"DUNGEON KEY"
#define	TXT_KEY_SILVER		"SILVER KEY"
#define	TXT_KEY_RUSTED		"RUSTED KEY"
#define	TXT_KEY_HORN		"HORN KEY"
#define	TXT_KEY_SWAMP		"SWAMP KEY"
#define TXT_KEY_CASTLE		"CASTLE KEY"

// Artifacts

#define TXT_ARTIINVULNERABILITY		"ICON OF THE DEFENDER"
#define TXT_ARTIHEALTH				"QUARTZ FLASK"
#define TXT_ARTISUPERHEALTH			"MYSTIC URN"
#define TXT_ARTISUMMON				"DARK SERVANT"
#define TXT_ARTITORCH				"TORCH"
#define TXT_ARTIEGG					"PORKALATOR"
#define TXT_ARTIFLY					"WINGS OF WRATH"
#define TXT_ARTITELEPORT			"CHAOS DEVICE"
#define TXT_ARTIPOISONBAG			"FLECHETTE"
#define TXT_ARTITELEPORTOTHER		"BANISHMENT DEVICE"
#define TXT_ARTISPEED				"BOOTS OF SPEED"
#define TXT_ARTIBOOSTMANA			"KRATER OF MIGHT"
#define TXT_ARTIBOOSTARMOR			"DRAGONSKIN BRACERS"
#define TXT_ARTIBLASTRADIUS			"DISC OF REPULSION"
#define TXT_ARTIHEALINGRADIUS		"MYSTIC AMBIT INCANT"

// Puzzle artifacts

#define TXT_ARTIPUZZSKULL			"YORICK'S SKULL"
#define TXT_ARTIPUZZGEMBIG			"HEART OF D'SPARIL"
#define TXT_ARTIPUZZGEMRED			"RUBY PLANET"
#define TXT_ARTIPUZZGEMGREEN1		"EMERALD PLANET"
#define TXT_ARTIPUZZGEMGREEN2		"EMERALD PLANET"
#define TXT_ARTIPUZZGEMBLUE1		"SAPPHIRE PLANET"
#define TXT_ARTIPUZZGEMBLUE2		"SAPPHIRE PLANET"
#define TXT_ARTIPUZZBOOK1			"DAEMON CODEX"
#define TXT_ARTIPUZZBOOK2			"LIBER OSCURA"
#define TXT_ARTIPUZZSKULL2			"FLAME MASK"
#define TXT_ARTIPUZZFWEAPON			"GLAIVE SEAL"
#define TXT_ARTIPUZZCWEAPON			"HOLY RELIC"
#define TXT_ARTIPUZZMWEAPON			"SIGIL OF THE MAGUS"
#define TXT_ARTIPUZZGEAR			"CLOCK GEAR"
#define TXT_USEPUZZLEFAILED			"YOU CANNOT USE THIS HERE"


// Items

#define TXT_ITEMHEALTH			"CRYSTAL VIAL"
#define TXT_ITEMBAGOFHOLDING	"BAG OF HOLDING"
#define TXT_ITEMSHIELD1			"SILVER SHIELD"
#define TXT_ITEMSHIELD2			"ENCHANTED SHIELD"
#define TXT_ITEMSUPERMAP		"MAP SCROLL"
#define TXT_ARMOR1				"MESH ARMOR"
#define TXT_ARMOR2				"FALCON SHIELD"
#define TXT_ARMOR3				"PLATINUM HELMET"
#define TXT_ARMOR4				"AMULET OF WARDING"

// Weapons

#define TXT_WEAPON_F2			"TIMON'S AXE"
#define TXT_WEAPON_F3			"HAMMER OF RETRIBUTION"
#define TXT_WEAPON_F4			"QUIETUS ASSEMBLED"
#define TXT_WEAPON_C2			"SERPENT STAFF"
#define TXT_WEAPON_C3			"FIRESTORM"
#define TXT_WEAPON_C4			"WRAITHVERGE ASSEMBLED"
#define TXT_WEAPON_M2			"FROST SHARDS"
#define TXT_WEAPON_M3			"ARC OF DEATH"
#define TXT_WEAPON_M4			"BLOODSCOURGE ASSEMBLED"
#define TXT_QUIETUS_PIECE		"SEGMENT OF QUIETUS"
#define TXT_WRAITHVERGE_PIECE	"SEGMENT OF WRAITHVERGE"
#define TXT_BLOODSCOURGE_PIECE	"SEGMENT OF BLOODSCOURGE"


// SB_bar.c ----------------------------------------------------------------

#define TXT_CHEATGODON			"GOD MODE ON"
#define TXT_CHEATGODOFF			"GOD MODE OFF"
#define TXT_CHEATNOCLIPON		"NO CLIPPING ON"
#define TXT_CHEATNOCLIPOFF		"NO CLIPPING OFF"
#define TXT_CHEATWEAPONS		"ALL WEAPONS"
#define TXT_CHEATHEALTH			"FULL HEALTH"
#define TXT_CHEATKEYS			"ALL KEYS"
#define TXT_CHEATSOUNDON		"SOUND DEBUG ON"
#define TXT_CHEATSOUNDOFF		"SOUND DEBUG OFF"
#define TXT_CHEATTICKERON		"TICKER ON"
#define TXT_CHEATTICKEROFF		"TICKER OFF"
#define TXT_CHEATARTIFACTS3		"ALL ARTIFACTS"
#define TXT_CHEATARTIFACTSFAIL	"BAD INPUT"
#define TXT_CHEATWARP			"LEVEL WARP"
#define TXT_CHEATSCREENSHOT		"SCREENSHOT"
#define TXT_CHEATIDDQD			"TRYING TO CHEAT, EH?  NOW YOU DIE!"
#define TXT_CHEATIDKFA			"CHEATER - YOU DON'T DESERVE WEAPONS"
#define TXT_CHEATBADINPUT		"BAD INPUT"
#define TXT_CHEATNOMAP			"CAN'T FIND MAP"

// P_doors.c ---------------------------------------------------------------

#define TXT_NEEDBLUEKEY			"YOU NEED A BLUE KEY TO OPEN THIS DOOR"
#define TXT_NEEDGREENKEY		"YOU NEED A GREEN KEY TO OPEN THIS DOOR"
#define TXT_NEEDYELLOWKEY		"YOU NEED A YELLOW KEY TO OPEN THIS DOOR"

// G_game.c ----------------------------------------------------------------

#define TXT_GAMESAVED			"GAME SAVED"

// M_misc.c ----------------------------------------------------------------

#define HUSTR_CHATMACRO1 "I'm ready to kick butt!"
#define HUSTR_CHATMACRO2 "I'm OK."
#define HUSTR_CHATMACRO3 "I'm not looking too good!"
#define HUSTR_CHATMACRO4 "Help!"
#define HUSTR_CHATMACRO5 "You suck!"
#define HUSTR_CHATMACRO6 "Next time, scumbag..."
#define HUSTR_CHATMACRO7 "Come here!"
#define HUSTR_CHATMACRO8 "I'll take care of it."
#define HUSTR_CHATMACRO9 "Yes"
#define HUSTR_CHATMACRO0 "No"

// AM_map.c ----------------------------------------------------------------

#define AMSTR_FOLLOWON		"FOLLOW MODE ON"
#define AMSTR_FOLLOWOFF		"FOLLOW MODE OFF"

// IN_lude.c ---------------------------------------------------------------

#define TXT_INTER_HUB1 \
"having passed the seven portals\n"\
"which sealed this realm, a vast\n"\
"domain of harsh wilderness stretches\n"\
"before you. fire, ice and steel have\n"\
"tested you, but greater challenges\n"\
"remain ahead. the dense tangle of\n"\
"forest surely hides hostile eyes,\n"\
"but what lies beyond will be worse.\n\n"\
"barren desert, dank swamps and\n"\
"musty caverns bar your way, but you\n"\
"cannot let anything keep you from\n"\
"your fate, even if you might come\n"\
"to wish that it would.\n\n"\
"and beyond, flickering in the\n"\
"distance, the ever-shifting walls\n"\
"of the hypostyle seem to mock\n"\
"your every effort.\n"

#define TXT_INTER_HUB2 \
"your mind still reeling from your\n"\
"encounters within the hypostyle, you\n"\
"stagger toward what you hope is\n"\
"a way out. things seem to move faster\n"\
"and faster, your vision blurs and\n"\
"begins to fade...\n"\
"as the world collapses around you,\n"\
"the brightness of a teleportal\n"\
"engulfs you. a flash of light, and then\n"\
"you climb wearily to your feet.\n\n"\
"you stand atop a high tower, and\n"\
"from below come the screams of the\n"\
"damned. you step forward, and\n"\
"instantly the sound of demonic\n"\
"chanting chills your blood.\n"\
"by all the gods of death! what place\n"\
"have you come to? by all the gods of\n"\
"pain, how will you ever find your\n"\
"way out?"

#define TXT_INTER_HUB3 \
"the mightiest weapons and artifacts\n"\
"of the ancients barely sufficed to\n"\
"defeat the heresiarch and his\n"\
"minions, but now their foul remains\n"\
"lie strewn at your feet. gathering\n"\
"the last of your strength, you\n"\
"prepare to enter the portal which\n"\
"leads from the heresiarch's inner\n"\
"sanctum.\n\n"\
"above you, the ramparts of an\n"\
"immense castle loom. silent towers\n"\
"and bare walls surround a single\n"\
"spire of black stone, which squats\n"\
"in the center of the castle like a\n"\
"brooding giant. fire and shadow\n"\
"twist behind gaping windows, dozens\n"\
"of baleful eyes glaring down upon\n"\
"you.\n"\
"somewhere within, your enemies are\n"\
"waiting..."

#define TXT_INTER_HUB4 \
"\"... and he shall journey into the\n"\
"realms of the dead, and contest with\n"\
"the forces therein, unto the very\n"\
"gates of despair. but whether he\n"\
"shall return again to the world of\n"\
"light, no man knows.\"\n"\
"                    \n"\
"                    \n"\
"                    \n"\
"                    \n"\
"                    \n"\
"damn.\n"

// F_finale.c --------------------------------------------------------------

#define TXT_FINALE_ORB1 \
"with a scream of agony you are\n"\
"wrenched from this world into\n"\
"another, every part of your body\n"\
"wreathed in mystic fire.  when your\n"\
"vision clears, you find yourself\n"\
"standing in a great hall, filled\n"\
"with ghostly echoes and menacing\n"\
"shadows.  in the distance you can\n"\
"see a raised dais, and upon it the\n"\
"only source of light in this world."

//(clear screen and begin to play this text with pic
//of sphere close-up; start ominous music low and 
//then grow louder)

#define TXT_FINALE_ORB2	\
"this can only be the chaos sphere,\n"\
"the source of korax's power.  with\n"\
"this, you can create worlds...  or\n"\
"destroy them.  by rights of battle\n"\
"and conquest it is yours, and with\n"\
"trembling hands you reach to grasp\n"\
"it.  perhaps, now, a new player will\n"\
"join the cosmic game of power.  like\n"\
"the pawn who is promoted to queen,\n"\
"suddenly the very reaches of the\n"\
"board seem to be within your grasp."

//(clear screen and begin to play this text with pic
//of chess-board, music shifts down tones and begin 
//repetitive drone)

#define TXT_FINALE_CHESS \
"                                    \n"\
"but there are other players mightier\n"\
"than you, and who can know their\n"\
"next moves?"

#define E1TEXT		"with the destruction of the iron\n"\
					"liches and their minions, the last\n"\
					"of the undead are cleared from this\n"\
					"plane of existence.\n\n"\
					"those creatures had to come from\n"\
					"somewhere, though, and you have the\n"\
					"sneaky suspicion that the fiery\n"\
					"portal of hell's maw opens onto\n"\
					"their home dimension.\n\n"\
					"to make sure that more undead\n"\
					"(or even worse things) don't come\n"\
					"through, you'll have to seal hell's\n"\
					"maw from the other side. of course\n"\
					"this means you may get stuck in a\n"\
					"very unfriendly world, but no one\n"\
					"ever said being a Heretic was easy!"

#define E2TEXT		"the mighty maulotaurs have proved\n"\
					"to be no match for you, and as\n"\
					"their steaming corpses slide to the\n"\
					"ground you feel a sense of grim\n"\
					"satisfaction that they have been\n"\
					"destroyed.\n\n"\
					"the gateways which they guarded\n"\
					"have opened, revealing what you\n"\
					"hope is the way home. but as you\n"\
					"step through, mocking laughter\n"\
					"rings in your ears.\n\n"\
					"was some other force controlling\n"\
					"the maulotaurs? could there be even\n"\
					"more horrific beings through this\n"\
					"gate? the sweep of a crystal dome\n"\
					"overhead where the sky should be is\n"\
					"certainly not a good sign...."

#define E3TEXT		"the death of d'sparil has loosed\n"\
					"the magical bonds holding his\n"\
					"creatures on this plane, their\n"\
					"dying screams overwhelming his own\n"\
					"cries of agony.\n\n"\
					"your oath of vengeance fulfilled,\n"\
					"you enter the portal to your own\n"\
					"world, mere moments before the dome\n"\
					"shatters into a million pieces.\n\n"\
					"but if d'sparil's power is broken\n"\
					"forever, why don't you feel safe?\n"\
					"was it that last shout just before\n"\
					"his death, the one that sounded\n"\
					"like a curse? or a summoning? you\n"\
					"can't really be sure, but it might\n"\
					"just have been a scream.\n\n"\
					"then again, what about the other\n"\
					"serpent riders?"
