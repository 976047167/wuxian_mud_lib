int main(object me,string arg)
{
	object room;
	if(room = environment(me)) {
		if(arg)
			tell_room(room,HIG+me->query("id")+"˵��"+arg+"\n"+NOR);
		else 
			tell_room(room,HIG+me->query("id")+"�������ﲻ֪��˵��Щʲô��\n"+NOR);
	}
	return 1;
}
