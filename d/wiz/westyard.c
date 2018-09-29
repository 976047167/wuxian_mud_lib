inherit ROOM;

void create()
{
	set("short","西院");
	set("long","这里是西院。。。。。你可以走来走去的。。。\n往东就是世界的中心，测试走路测试啊测试。。。\n");
	set("exits",([
		"east":__DIR__"center",
	]));
	setup()
	replace_program(ROOM);

}
