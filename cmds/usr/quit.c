int main(object me)
{
	object ob,room;
	me->save();
	if(ob = me->query_tmp("link_ob"))
		ob->save();
	room = environment(me);
	if(room) {
		tell_room(room,me->query("id")+((me->query_tmp("netdead"))?"断线时间过长，":"")+"退出了游戏。\n",({me}));
	}
	tell_object(me,"你离开了游戏。\n");
	destruct(me);
	return 1;
}
