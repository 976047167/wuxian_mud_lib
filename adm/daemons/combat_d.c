void hit_ob(object me,object op)
{
	
	op->add("hp",-1);
	tell_room(environment(me),me->query("name")+"��ȭ������"+op->query("name")+"����������һ���˺���\n");
}
