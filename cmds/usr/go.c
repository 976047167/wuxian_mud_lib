int main(object me,string arg)
{
	object room;
	mixed exits;
	int ret;
	room = environment(me);
	if(!objectp(room))
		return notify_fail("搞什么，你现在根本没有环境嘛，别瞎走。。。\n");
	if(!arg || arg=="")
		return notify_fail("你要往哪里走？\n");

	exits = room->query("exits");
	if(mapp(exits)) {
		if(exits[arg]) {
			if(me->move(exits[arg])) {
				tell_room(room,me->query("id")+"向"+arg+"方向离开。\n");
				tell_room(environment(me),me->query("id")+"走了过来。\n",({me}));
				return 1;
			}
		} else {
			return notify_fail("没有这个方向。\n");
		} 
	} else {
		return notify_fail("这里没有明显的出路。\n");
	}
}
