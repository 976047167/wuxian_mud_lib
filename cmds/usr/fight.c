int main(object me,string arg)
{
	object target;
	if(!arg || arg == "") {
		return notify_fail("��Ҫ��˭������\n");
	}
	if(!objectp(target = present(arg, environment(me)))) {
		return notify_fail("����û������ˡ�\n");
	}
	if(!target->is_character()) {
		return notify_fail("��������ǲ��ǻ��ˡ�\n");
	}
	if(me->is_fighting(target)) {
		return notify_fail("����㣡���Ѿ��ںͶԷ������ˡ�\n");
	}

	me->add_enemy(target);
	if(!target->is_fighting(me))
		target->add_enemy(me);
	tell_room(environment(me),me->query("name")+"׼����"+target->query("name")+"���н�����\n");
	return 1;
}
