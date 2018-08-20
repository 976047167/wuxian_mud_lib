inherit F_ROOM;

void create()
{
	set("short","世界的中心");
	set("long","这里就是世界的中心。人来人往，车水马龙。\n到处都是人，摩肩接踵的。。。。非常热闹。\n");
	set("exits",([
		"west":__DIR__"westyard",
	]));
	add_mob();
}
