int main(object me,string arg)
{
	string tmp;
	tmp  = "\n";
	tmp += HIY +"��Ѫ:"+NOR+me->query("hp")+"/"+me->query("max_hp")+"\n";
	tmp += HIY +"����:"+NOR+me->query("mp")+"/"+me->query("max_mp")+"\n";
	tmp += HIG +"�ȼ�:"+NOR+me->query("level")+"\n";
	tmp += HIG +"����:"+NOR+me->query("combat_exp")+"\n";
	write(tmp);
	return 1;
}
