int main(object me,string arg)
{
	object room;
	mixed exits;
	int ret;
	room = environment(me);
	if(!objectp(room))
		return notify_fail("��ʲô�������ڸ���û�л������Ϲ�ߡ�����\n");
	if(!arg || arg=="")
		return notify_fail("��Ҫ�������ߣ�\n");

	exits = room->query("exits");
	if(mapp(exits)) {
		if(exits[arg]) {
			if(me->move(exits[arg])) {
				tell_room(room,me->query("id")+"��"+arg+"�����뿪��\n");
				tell_room(environment(me),me->query("id")+"���˹�����\n",({me}));
				return 1;
			}
		} else {
			return notify_fail("û���������\n");
		} 
	} else {
		return notify_fail("����û�����Եĳ�·��\n");
	}
}
