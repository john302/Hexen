# --------------------------------------------------------------------------
#
#      4r  use 80486 timings and register argument passing
#       c  compile only
#      d1  include line number debugging information
#      d2  include full sybolic debugging information
#      ei  force enums to be of type int
#       j  change char default from unsigned to signed
#      oa  relax aliasing checking
#      od  do not optimize
#  oe[=#]  expand functions inline, # = quads (default 20)
#      oi  use the inline library functions
#      om  generate inline 80x87 code for math functions
#      ot  optimize for time
#      ox  maximum optimization
#       s  remove stack overflow checks
#     zp1  align structures on bytes
#      zq  use quiet mode
#  /i=dir  add include directories
#
# --------------------------------------------------------------------------

#CCOPTS = /d2 /omaxet /zp1 /4r /ei /j /zq /i=dmx

CCOPTS = /omaxet /zp1 /4r /ei /j /zq /i=dmx

LOCOBJS = &
 i_cdmus.obj &
 i_cyber.obj &
 i_ibm.obj &
 i_ibm_a.obj &
 i_sound.obj &
 linear.obj

GLOBOBJS = &
 am_map.obj &
 a_action.obj &
 ct_chat.obj &
 d_net.obj &
 f_finale.obj &
 g_game.obj &
 h2_main.obj &
 info.obj &
 in_lude.obj &
 mn_menu.obj &
 m_misc.obj &
 p_acs.obj &
 p_anim.obj &
 p_ceilng.obj &
 p_doors.obj &
 p_enemy.obj &
 p_floor.obj &
 p_inter.obj &
 p_lights.obj &
 p_map.obj &
 p_maputl.obj &
 p_mobj.obj &
 p_plats.obj &
 p_pspr.obj &
 p_setup.obj &
 p_sight.obj &
 p_spec.obj &
 p_switch.obj &
 p_telept.obj &
 p_tick.obj &
 p_things.obj &
 p_user.obj &
 po_man.obj &
 r_bsp.obj &
 r_data.obj &
 r_draw.obj &
 r_main.obj &
 r_plane.obj &
 r_segs.obj &
 r_things.obj &
 sb_bar.obj &
 sc_man.obj &
 sn_sonix.obj &
 st_start.obj &
 sv_save.obj &
 sounds.obj &
 tables.obj &
 v_video.obj &
 w_wad.obj &
 z_zone.obj

hex.exe : $(LOCOBJS) $(GLOBOBJS)
 wlink @hex.lnk
 ncopy hex.exe striphex.exe
 wstrip striphex.exe
 4gwbind 4gwpro.exe striphex.exe hexen.exe -V
 prsucc

#i_ibm.obj : i_ibm.c
# for the joystick to work, the /d2 option must be off
# wcc386 /d2 /wx /od /4r /zq /ei /j i_ibm.c

.c.obj :
 wcc386 $(CCOPTS) $[*

.asm.obj :
 tasm /mx $[*
