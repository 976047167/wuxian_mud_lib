// by akuma@mud.com.cn
mapping security = ([]);
mapping cmdpath = (["player":({"/cmds/usr/"}),"gm":({"/cmds/usr/","/cmds/gm/"})]);
void setup();
void setup_player_cmd_path(object ob);
void create()
{
	setup();
}

void setup()
{
	string tmp,user,level;
	mixed list;
	int sz,i;
	tmp = read_file(WIZLIST);
	if(stringp(tmp) && strlen(tmp)) {
		tmp = replace_string(tmp,"\r","");
		list = explode(tmp,"\n");
		sz = sizeof(list);
		if(sz) {
			for(i=0;i<sz;i++) {
				if(strlen(list[i])) {
					if(sscanf(list[i],"%s %s",user,level)== 2) {
						security[user] = level;
					}
				}
			}
		}
	}
}

void setup_player_security(object ob)
{
	string id;
	id = ob->query("id");
	if(!undefinedp(security[id])) {
		ob->set_tmp("slevel",security[id]);
	} else {
		ob->set_tmp("slevel","player");
	}
	setup_player_cmd_path(ob);
}

void setup_player_cmd_path(object ob)
{
	string slevel;
	slevel = ob->query_tmp("slevel");
	if(!undefinedp(cmdpath[slevel])) {
		ob->set_tmp("cmdpath",cmdpath[slevel]);
	} else {
		ob->set_tmp("cmdpath",cmdpath["player"]);
	}
}
