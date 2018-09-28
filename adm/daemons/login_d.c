// logind
// create by akuma@mud.com.cn
// 2009-10-04

void gt_id(string arg,object ob);
object find_body(string id);
int check_legal_name(string name)
{
	return 1;
}
int check_legal_id(string id)
{
        int i,sz;
        sz = strlen(id);
        if( sz < 3 || sz > 10  ) {
                return -1;
        }
        for(i=0;i<sz;i++) {
                if(id[i]<91 || id[i]>122) {
                        return -2;
			break;
                }
        }
        return 1;
}

varargs void enter_world(object ob,int relogin)
{
	mixed slevel;
	slevel = SECURITY_D->setup_player_security(ob);
	write("目前权限："+ob->query_temp("slevel")+"\n");
	write("目前指令目录："+sprintf("%O",ob->query_temp("cmdpath"))+"\n");
	
	ob->set_temp("login_ok",1);
	if(!relogin) {
		ob->setup();
		ob->move(START_ROOM);
		tell_room(environment(ob),ob->query("id")+"连线进入这个世界。\n",({ob}));
	} else {
		tell_room(environment(ob),ob->query("id")+"重新连线。\n",({ob}));
	}
}

void logon(object ob)
{
//	write(HIY+read_file(WELCOME)+NOR);
	write("欢迎来到测试MUD\n请输入您的ID:\n");
	input_to("get_id", ob);
}

void get_id(string arg,object ob)
{
	int ret;
	ob->set("id",arg);
	if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
		if(ob->restore()) {
			write("读取登录数据成功，请输入密码：\n");
			input_to("get_passwd",ob);
		} else {
			write("读取登录数据失败，无法进入游戏，强制断线。\n");
			destruct(ob);
		}
	} else { //no data,it's a new user
		if(check_legal_id(arg)>0) {
			write("欢迎，新来的。。。。请输入中文名:\n");
			//input_to("new_passwd",ob);
			input_to("get_name",ob);
		} else {
			write("ID不合法，应该为3～10位的小写英文字母，请重新输入：\n");
			input_to("get_id", ob);
		}
	}
}
void get_name(string arg,object ob)
{
	if(check_legal_name(arg)>0) {
		ob->set("name",arg);
		write("请输入密码：\n");
		input_to("new_passwd",ob);
	} else {
		write("中文名不合法，请重新输入：\n");
		input_to("get_name", ob);
	}
}
void new_passwd(string arg,object ob)
{
	ob->set("passwd",arg);
	write("再次输入密码：\n");
	input_to("confirm_passwd",ob);
}

void confirm_passwd(string arg,object ob)
{
	object usr;
	int ret;
	int time;
	if(arg == ob->query("passwd")) {
		time = time();
		ob->set("last_login",time);
		ret = ob->save();
		write("登录数据存盘结果："+ret+"\n");
		usr = new(USER_OB);
		usr->set("birth",time);
		usr->set("id",ob->query("id"));
		usr->set("name",ob->query("name"));
		usr->set_temp("login_ob",ob);
		ob->delete_temp("login_temp");
		CHAR_D->setup_new_player(usr);
		ret = usr->save();
		write("游戏数据存盘结果："+ret+"\n");
		exec(usr,ob);
		enter_world(usr,0);
	} else {
		write("两次输入密码不同，请重新输入密码：\n");
		input_to("new_passwd",ob);
	}
}
void get_passwd(string arg,object ob)
{
	object usr,old_link;
	int ret;

	ret = 0;
	if(arg == ob->query("passwd")) {
		if(!objectp(usr=find_body(ob->query("id")))) {
			usr = new(USER_OB);
			usr->set("id",ob->query("id"));
			ret = usr->restore();
		} else if(!usr->query_temp("netdead")){
			old_link = usr->query_temp("login_ob");
			tell_object(usr,"有人重新登录，取代了你的连线，再见。。。\n");
			exec(old_link,usr);
			destruct(old_link);
			ret = -1;
		} else {
			usr->delete_temp("netdead");
			ret = -1;
		}
		if(ret) {
			exec(usr,ob);
			if(ret > 0)
				write("读取游戏数据成功，开始进入游戏。\n");
			else
				write("重新连线完毕，进入游戏。\n");
			printf("%O\n",usr);
			ob->set("last_login",time());
			ob->save();
			ob->delete_temp("login_temp");
			usr->set_temp("login_ob",ob);
			if(ret > 0)
				enter_world(usr,0);
			else
				enter_world(usr,1);
		} else {
			write("读取游戏数据失败，无法进入游戏，强制断线。\n");
			destruct(ob);
			destruct(usr);
		}
	} else {
		write("密码错误，退出。\n");
		destruct(ob);
	}
}

object find_body(string id)
{
	object ob, *body;
	
	if( objectp(ob = find_player(id)) )
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
		if( clonep(body[i]) && body[i]->query("id") == id ) 
			return body[i];
	return 0;
}
