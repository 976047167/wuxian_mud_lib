#include <item_d.h>
void create()
{

}

object create_item(string arg)
{
	object ob;
	mixed tmp;
	int item_type;
	tmp = iexplode(arg,",");
	item_type = tmp[0]/10000;
	ob = new(ITEM_OB);
	// check arg ...
	switch(item_type) {
	case ITEM_EQUIP :
		ob = EQUIP_D->setup_equip(ob,tmp[0],arg);
		break;
	default :
		break;
	}
	return ob;
}
