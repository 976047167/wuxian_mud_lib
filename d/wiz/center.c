inherit F_ROOM;

void create()
{
	set("short","���������");
	set("long","���������������ġ�������������ˮ������\n���������ˣ�Ħ�����ġ��������ǳ����֡�\n");
	set("exits",([
		"west":__DIR__"westyard",
	]));
	add_mob();
}
