//
inherit F_DBASE;
inherit F_SAVE;
inherit F_MOVE;
// inherit feature attack here
inherit F_ATTACK;

int setup();

void create()
{
}
// for global alias
string process_input(string arg)
{
	int len;
	len = strlen(arg);
	if(len == 1) {
		switch(arg) {
		case "l":
			return "look";
		case "'":
			return "say";
		case "n":
			return "go north";
		case "w":
			return "go west";
		case "s":
			return "go south";
		case "e":
			return "go east";
		default :
			return arg;
		}
	}
	if(arg[0..0]=="'")
		return "say "+arg[1..len-1];
	if(arg[0..1]=="l ")
		return "look "+arg[2..len-1];
	switch(arg) {
	case "north":
		return "go north";
	case "west":
		return "go west";
	case "south":
		return "go south";
	case "east":
		return "go east";
	default:
		return arg;
	}
}
int setup()
{
	log_file("user",sprintf("%O setup at %s\n",this_object(),ctime(time())));
	set_living_name(query("id"));
	enable_commands();
	add_action("cmd_hook","",1);
	// ×¢²áÐÄÌø
	set_heart_beat(1);
	return 1;
}

void heart_beat()
{
	if(is_fighting()) {
		do_attack();	
	}
	
}
int cmd_hook(string arg)
{
	string verb = query_verb();
	return CMD_D->do_cmd(this_object(),verb,arg);	
}

string query_save_file()
{
	string id;
	//fixme later...
	if(!stringp(id=query("id")))
		return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

void net_dead()
{
	object link_ob;
	if( objectp(link_ob = query_temp("link_ob")) )
		destruct(link_ob);
	set_temp("netdead",1);
	call_out("user_dump",30); // 5 min to quit
}

void user_dump()
{
	if(query_temp("netdead")) {
		CMD_QUIT->main(this_object());
	}
}
