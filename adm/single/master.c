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
	res = (caught) ? "����ѶϢ������: " : "����";
	res = sprintf("%s\nִ��ʱ�δ���%s\n��ʽ��%s �� %i ��\n���: %O\n����%O\n",
		res, 
		error["error"],
		error["program"], 
		error["line"],
		error["object"],
		this_player()
	);

	for (i=0, s = sizeof(error["trace"]); i < s; i++)
		res = sprintf("%s�������ԣ�%s �� %s() �� %i �У������ %O\n",
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
	return "Root";
}

//master apply::get_bb_uid
//get backbone uid
string get_bb_uid()
{
	return "Backbone";
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
		str = sprintf("Ԥ���룺%s��������%s��\n", file, err);
	else
		str = sprintf("Ԥ���룺%s�ɹ���\n", file);
	
	write(str);
	return;
}

int valid_socket(object caller, string func, mixed *info)
{
        return 1;
}

