int main(object me)
{
	object ob,room;
	me->save();
	if(ob = me->query_temp("link_ob"))
		ob->save();
	room = environment(me);
	if(room) {
		tell_room(room,me->query("id")+((me->query_temp("netdead"))?"����ʱ�������":"")+"�˳�����Ϸ��\n",({me}));
	}
	tell_object(me,"���뿪����Ϸ��\n");
	destruct(me);
	return 1;
}
