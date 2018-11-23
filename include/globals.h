#ifndef __GLOBALS_H__
#define __GLOBALS_H__
#include <ansi.h>
#include <syntax.h>
#define LOG_DIR 		"/log/"
#define DATA_DIR		"/data/"

#define USER_OB			"/clone/user.c"
#define LOGIN_OB		"/clone/login.c"
#define CLASS_OB		"/clone/class_container.c"
#define ITEM_OB			"/clone/item.c"
#define MOVE_OB			"/clone/mob.c"

#define CMD_D			"/adm/daemons/cmd_d.c"
#define LOGIN_D			"/adm/daemons/login_d.c"
#define SECURITY_D		"/adm/daemons/security_d.c"
#define CHAR_D			"/adm/daemons/char_d.c"
#define CHINESE_D		"/adm/daemons/chinese_d.c"
#define CLASS_D			"/adm/daemons/class_d.c"
#define ITEM_D			"/adm/daemons/item_d.c"
#define EQUIP_D			"/adm/daemons/equip_d.c"
#define COMBAT_D		"/adm/daemons/combat_d.c"

#define F_DBASE			"/feature/dbase.c"
#define F_SAVE			"/feature/user_save.c"
#define F_MOVE			"/feature/move.c"
#define F_ITEM_MOVE		"/feature/item_move.c"
#define F_NAME			"/feature/name.c"
#define F_ATTACK		"/feature/attack.c"
#define F_TREEMAP		"/feature/treemap.c"
#define F_CLEAN_UP		"/feature/clean_up.c"

#define ROOM			"/inherit/room/room.c"


#define START_ROOM		"/d/wiz/center.c"

#define CMD_LOOK		"/cmds/usr/look.c"
#define CMD_QUIT		"/cmds/usr/quit.c"


#define WIZLIST			"/etc/wizlist"
#define WELCOME			"/etc/welcome"
#define LEVEL_MODIFY		"/etc/level_modify"


// User IDs
#define ROOT_UID        "Root"
#define BACKBONE_UID    "Backbone"
#endif
