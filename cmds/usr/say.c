int main(object me,string arg)
{
	object room;
	if(room = environment(me)) {
		if(arg)
			tell_room(room,HIG+me->query("id")+"说："+arg+"\n"+NOR);
		else 
			tell_room(room,HIG+me->query("id")+"自言自语不知道说了些什么。\n"+NOR);
	}
	return 1;
}
