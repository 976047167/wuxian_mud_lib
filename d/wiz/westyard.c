inherit ROOM;

void create()
{
	set("short","��Ժ");
	set("long","��������Ժ���������������������ȥ�ġ�����\n����������������ģ�������·���԰����ԡ�����\n");
	set("exits",([
		"east":__DIR__"center",
	]));
	setup()
	replace_program(ROOM);

}
