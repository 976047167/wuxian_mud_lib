int main(object me,string arg)
{
	object ob;
	mixed err;
	if(!arg)
		return notify_fail("参数错误！\n");
	write("开始编译\n");
	if(objectp(ob = find_object(arg))) {
		destruct(ob);
		err = catch(load_object(arg));
	} else {
		err = catch(load_object(arg));
	}
	printf("编译%s，结果：%O\n",arg,err);	
	return 1;
}
