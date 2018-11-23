// master ob of my new mudlib
// core of a mudlib
// create by akuma@mud.com.cn
// 2009-08-08

// create of an object
void create()
{
	return;
}

// master apply::crash
// called when driver crashed
// output crash log if we can catch some info how it crashed
void crash(string error, object command_giver, object current_object)
{
        int i, kk, ii, size;
        object ob;
        mixed userlist, pets;
        mixed sql_str, file;
        
        assure_file("/log/CRASH");
        write_file("/log/CRASH", sprintf("%s:Driver crashed.\nerror=%s\ncommand_giver=%O\ncurrent_object=%O\n\n", ctime(time()), error, command_giver, current_object));
        
        return;
}

//master apply::log_error
//auto log compiling error
void log_error(string file, string message)
{
	catch(write_file("/log/LOG", sprintf("%s:%s\n%s\n\n", ctime(time()), file, message)));
	
	return;
}

//master apply::errr_handler
//auto log runtime error
void error_handler(mapping error, int caught)
{
	int i, s;
	string res;
	mixed trace, tmp;
	
	if (!mapp(error))
		return;

	log_file("error_handler", sprintf("Runtime Error at %s:\n", ctime(time())));
	res = (caught) ? "错误讯息被拦截: " : "错误";
	res = sprintf("%s\n执行时段错误：%s\n程式：%s 第 %i 行\n物件: %O\n对象：%O\n",
		res, 
		error["error"],
		error["program"], 
		error["line"],
		error["object"],
		this_player()
	);

	for (i=0, s = sizeof(error["trace"]); i < s; i++)
		res = sprintf("%s呼叫来自：%s 的 %s() 第 %i 行，物件： %O\n",
			res,
			error["trace"][i]["program"],
			error["trace"][i]["function"],
			error["trace"][i]["line"],
			error["trace"][i]["object"]
		);
	
	log_file("error_handler", res + "\n");
}
	
//master apply::get_root_uid
//get root uid
string get_root_uid()
{
	return ROOT_UID;
}

//master apply::get_bb_uid
//get backbone uid
string get_bb_uid()
{
	return BACKBONE_UID;
}

//master apply::connect
//notice: this apply is called by new login
//and return an object
//normally it should be "login_ob"
//but now,we just use user_ob instead
object connect()
{
	log_file("new_user_login",time()+"\n");
	return new(LOGIN_OB);
}

string creator_file()
{
	return "Root";
}

//master apply::epilog
//return file list to preload
string *epilog(int load_empty)
{
	return seperate_file("/etc/preload");
	
}

//master apply::preload
//preload file when a mudlib is starting
void preload(string file)
{
	string err, str;

	if (file_size(file) == -1)
		return;

	err = catch(load_object(file));
	
	if (err)
		str = sprintf("预载入：%s发生错误：%s。\n", file, err);
	else
		str = sprintf("预载入：%s成功。\n", file);
	
	write(str);
	return;
}

int valid_socket(object caller, string func, mixed *info)
{
        return 1;
}

mixed compile_object(string file)
{
        object daemon;
        mixed ob;

        if (file[0..1]=="/f") {
                ob = FUBEN_D->compile_object(file);
                if (objectp(ob))
                        ob->setup();
                return ob;
        } else if (daemon = find_object(VIRTUAL_D))
                return daemon->compile_object(file);
        else
                return 0;
}