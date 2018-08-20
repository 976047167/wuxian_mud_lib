void hit_ob(object me,object op)
{
	
	op->add("hp",-1);
	tell_room(environment(me),me->query("name")+"挥拳攻击了"+op->query("name")+"，结果造成了一点伤害！\n");
}
