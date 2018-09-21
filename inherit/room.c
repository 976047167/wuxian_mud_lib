// inherit of ROOM
// created by akuma@mud.com.cn
// 2009-10-07

inherit F_ROOM_DBASE;

int add_mob()
{
	object mob;
	mob = new("/obj/mob.c");
	mob->move(this_object());
}

