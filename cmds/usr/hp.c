int main(object me,string arg)
{
	string tmp;
	tmp  = "\n";
	tmp += HIY +"气血:"+NOR+me->query("hp")+"/"+me->query("max_hp")+"\n";
	tmp += HIY +"精神:"+NOR+me->query("mp")+"/"+me->query("max_mp")+"\n";
	tmp += HIG +"等级:"+NOR+me->query("level")+"\n";
	tmp += HIG +"经验:"+NOR+me->query("combat_exp")+"\n";
	write(tmp);
	return 1;
}
