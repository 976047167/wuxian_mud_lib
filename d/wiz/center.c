inherit F_ROOM;

void create()
{
	set("short","主神空间");
	set("long","你正站在一个空旷无比的巨大平台上。\n平台正中央是一颗巨大无比的光球，它仿佛太阳一样给整个平台提供了光亮，\n而大平台四方都是无边的黑暗，那是一种漆黑得连一丝光芒都没有的幽远黑暗。\n
");
	set("exits",([
		"west":__DIR__"westyard",
	]));
	add_mob();
}
