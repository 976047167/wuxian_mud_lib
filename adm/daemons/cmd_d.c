void create()
{

}

int do_cmd(object me,string verb,string arg)
{
	object cmd;
	mixed cmdpath;
	int i;
	cmdpath = me->query_tmp("cmdpath");
	for(i=sizeof(cmdpath)-1;i>=0;i--) {
		cmd = load_object(cmdpath[i]+verb);
		if(objectp(cmd))
			return cmd->main(me,arg);
	}
	tell_object(me,"没有这个指令。\n");
	return 0;
}
