// inherit of ROOM
// created by akuma@mud.com.cn
// 2009-10-07

inherit F_DBASE;

int add_mob()
{
	object mob;
	mob = new(MOVE_OB);
	mob->move(this_object());
}

