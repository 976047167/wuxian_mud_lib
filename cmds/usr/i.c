//
int main(object me)
{
	mixed inv;
	int i,sz;
	inv = all_inventory(me);
	if(!inv || (sz=sizeof(inv))==0) {
		write("你身上没有任何物品。\n");
		return 1;
	}
	for(i=sz-1;i>=0;i--) {
		printf("%O\n",inv[i]);
		printf("\t%O\n",inv[i]->query());
	}
	return 1;
}
