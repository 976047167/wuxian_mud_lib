// equip_d.c
// by akuma@mud.com.cn
// 
#include <equip_d.h>
void setup();
mixed equips = ([]);
void create()
{
	setup();
}

void setup()
{
	mixed s;
	int i,j,sz;
	mixed tmp;//,tmp2;
	s = seperate_file(EQUIP_FILE);
	sz = sizeof(s);
	for(i=0;i<sz;i++) {
		if(!stringp(s[i]) || s[i]=="")
			continue;
		tmp = iexplode(s[i],",");
		int equip_id;
		sscanf(tmp[EQUIP_ID],"%d",equip_id);
		if(!intp(equip_id))  //注释，或其他错误。。。。
			continue;
		if(sizeof(tmp)!=EQUIP_CHECK) {//这样来说，这行肯定有错，也可能是分隔符错误，抛出log
			log_file("equip_log",EQUIP_FILE+" wrong with line "+i+"\n");
			continue;
		}
//		tmp2 = ({});
//		for(j=1;j<EQUIP_CHECK;j++) {
//			tmp2 += ({tmp[j]});
//		}
		equips[equip_id] = copy(tmp);
	}
	log_file("equip_d",sprintf("%O\n",equips));
}

object setup_equip(object ob,int id,string arg)
{
	//先不管arg。。。。
	if(!undefinedp(equips[id])) {
		ob->set("iid",equips[id][EQUIP_ID]); //item_id ....
		ob->set("name",equips[id][EQUIP_NAME]);
		ob->set("id",equips[id][EQUIP_EID]);//用于进行present查询的英文id,eid
		ob->set("valid_comb",equips[id][EQUIP_VALID_COMB]);
		ob->set("type",equips[id][EQUIP_TYPE]);
		ob->set("subtype",equips[id][EQUIP_SUBTYPE]);
		ob->set("p_att",equips[id][EQUIP_P_ATT]);
		ob->set("s_att",equips[id][EQUIP_S_ATT]);
		ob->set("p_def",equips[id][EQUIP_P_DEF]);
		ob->set("s_def",equips[id][EQUIP_S_DEF]);
	}
	//再处理arg
	return ob;
}
