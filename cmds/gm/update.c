int main(object me,string arg)
{
	object ob;
	mixed err;
	if(!arg)
		return notify_fail("��������\n");
	write("��ʼ����\n");
	if(objectp(ob = find_object(arg))) {
		destruct(ob);
		err = catch(load_object(arg));
	} else {
		err = catch(load_object(arg));
	}
	printf("����%s�������%O\n",arg,err);	
	return 1;
}
