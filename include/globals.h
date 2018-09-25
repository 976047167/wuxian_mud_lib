#ifndef __GLOBALS_H__
#define __GLOBALS_H__
#include <ansi.h>
#define LOG_DIR 		"/log/"
#define DATA_DIR		"/data/"

#define USER_OB			"/obj/user.c"
#define LOGIN_OB		"/obj/login.c"
#define CLASS_OB		"/obj/class_container.c"
#define ITEM_OB			"/obj/item.c"

#define CMD_D			"/adm/daemons/cmd_d.c"
#define LOGIN_D			"/adm/daemons/login_d.c"
#define SECURITY_D		"/adm/daemons/security_d.c"
#define CHAR_D			"/adm/daemons/char_d.c"
#define CHINESE_D		"/adm/daemons/chinese_d.c"
#define CLASS_D			"/adm/daemons/class_d.c"
#define ITEM_D			"/adm/daemons/item_d.c"
#define EQUIP_D			"/adm/daemons/equip_d.c"
#define COMBAT_D		"/adm/daemons/combat_d.c"

#define F_DBASE			"/inherit/body/user_dbase.c"
#define F_ITEM_DBASE	"/inherit/body/item_dbase.c"
#define F_MOB_DBASE		"/inherit/body/mob_dbase.c"
#define F_SAVE			"/inherit/body/user_save.c"
#define F_MOVE			"/inherit/body/move.c"
#define F_ITEM_MOVE		"/inherit/body/item_move.c"
#define F_ROOM_DBASE	"/inherit/body/room_dbase.c"
#define F_ROOM			"/inherit/room.c"
#define F_NAME			"/inherit/body/name.c"
#define F_ATTACK		"/inherit/body/attack.c"

#define START_ROOM		"/d/wiz/center.c"

#define CMD_LOOK		"/cmds/usr/look.c"
#define CMD_QUIT		"/cmds/usr/quit.c"


#define WIZLIST			"/etc/wizlist"
#define WELCOME			"/etc/welcome"
#define LEVEL_MODIFY		"/etc/level_modify"
#endif
