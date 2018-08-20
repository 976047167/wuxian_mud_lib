int main(object me,string arg)
{
	object target;
	if(!arg || arg == "") {
		return notify_fail("你要和谁较量？\n");
	}
	if(!objectp(target = present(arg, environment(me)))) {
		return notify_fail("这里没有这个人。\n");
	}
	if(!target->is_character()) {
		return notify_fail("看清楚，那不是活人。\n");
	}
	if(me->is_fighting(target)) {
		return notify_fail("认真点！你已经在和对方较量了。\n");
	}

	me->add_enemy(target);
	if(!target->is_fighting(me))
		target->add_enemy(me);
	tell_room(environment(me),me->query("name")+"准备和"+target->query("name")+"进行较量。\n");
	return 1;
}
