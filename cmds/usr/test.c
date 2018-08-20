int main(object me,string arg)
{
	object ob;
	ob = ITEM_D->create_item("10001,1");
	printf("%O\n",ob);
	if(objectp(ob))
		ob->move(me);
	return 1;
}
