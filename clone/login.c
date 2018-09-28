// login.c login ob
// created by akuma@mud.com.cn
// 2009-10-09

inherit F_DBASE;
inherit F_SAVE;
inherit F_MOVE;

int setup();

void create()
{
}

// apply of user_ob :: logon()
// after master->connect(),mudos calls user_ob->logon()
// we use this to put user_ob into LOGIN_D
// and start Login authentication
void logon()
{
	call_out("login_timeout",60);
	set_temp("login_temp",1);
	LOGIN_D->logon(this_object());
}

void login_timeout()
{
	tell_object(this_object(),"login_timeout");
	if(query_temp("login_temp"))
		destruct(this_object());
}

string query_save_file()
{
	string id;
	//fixme later...
	if(!stringp(id=query("id")))
		return 0;
	return sprintf(DATA_DIR "login/%c/%s", id[0], id);
}
