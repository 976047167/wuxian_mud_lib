void look_room_target(object me, object ob)
{
	string desc;
	desc = "";
	desc += ob->query("name")+"("+ob->query("id")+")\n";
	write(desc);
}

void look_bag_target(object me,object ob)
{
        string desc;
        desc = "";
        desc += ob->query("name")+"("+ob->query("id")+")\n";
        write(desc);
}
int look_something(object me,string arg)
{
	object room;
	object ob;
	room = environment(me);
	if(room) {
		if(objectp(ob = present(arg,room))) {
			look_room_target(me,ob);
			return 1;
		} else if (objectp(ob = present(arg,me))) {
			look_bag_target(me,ob);
			return 1;
		} else {
			return 0;
		}
	} else if (objectp(ob = present(arg,me))) {
		look_bag_target(me,ob);
		return 1;
	} else {
		return 0;
	}
}

int main(object me,string arg)
{
	object room;
	mixed inv;
	mixed exits,key;
	string desc;
	int size,i;
	int ret;
	
	if(stringp(arg) && arg != "") 
		ret = look_something(me,arg);
	if(ret)
		return 1;
	room = environment(me);
	desc = "";
	if(room) {
		desc += room->query("short")+" - \n";
		desc += "    "+room->query("long")+"\n";
		exits = room->query("exits");
		if(!exits || !mapp(exits) || !(size = sizeof(exits)))
			desc += "    这里没有明显的出口。\n";
		else {
			desc += "    这里明显的出口是：";
			key = keys(exits);
			for(i=0;i<size-1;i++) {
				desc += key[i]+"，";
			}
			desc += key[i]+"。";
			desc += "\n";
		}
		inv = all_inventory(room);
		size = sizeof(inv);
		if(!size)
			desc += "    这里什么也没有。\n";
		else {
			for(i=0;i<size;i++) {
				if(inv[i]!=me)
					desc +="  "+inv[i]->query("name")+"("+inv[i]->query("id")+")"+((inv[i]->query_tmp("netdead")?"<断线中>":""))+"\n";
			}
		}
		write(desc);
		return 1;
	}
	return 0;
}

