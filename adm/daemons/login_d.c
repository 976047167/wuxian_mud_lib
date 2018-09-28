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
	write("ĿǰȨ�ޣ�"+ob->query_temp("slevel")+"\n");
	write("Ŀǰָ��Ŀ¼��"+sprintf("%O",ob->query_temp("cmdpath"))+"\n");
	
	ob->set_temp("login_ok",1);
	if(!relogin) {
		ob->setup();
		ob->move(START_ROOM);
		tell_room(environment(ob),ob->query("id")+"���߽���������硣\n",({ob}));
	} else {
		tell_room(environment(ob),ob->query("id")+"�������ߡ�\n",({ob}));
	}
}

void logon(object ob)
{
//	write(HIY+read_file(WELCOME)+NOR);
	write("��ӭ��������MUD\n����������ID:\n");
	input_to("get_id", ob);
}

void get_id(string arg,object ob)
{
	int ret;
	ob->set("id",arg);
	if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
		if(ob->restore()) {
			write("��ȡ��¼���ݳɹ������������룺\n");
			input_to("get_passwd",ob);
		} else {
			write("��ȡ��¼����ʧ�ܣ��޷�������Ϸ��ǿ�ƶ��ߡ�\n");
			destruct(ob);
		}
	} else { //no data,it's a new user
		if(check_legal_id(arg)>0) {
			write("��ӭ�������ġ�������������������:\n");
			//input_to("new_passwd",ob);
			input_to("get_name",ob);
		} else {
			write("ID���Ϸ���Ӧ��Ϊ3��10λ��СдӢ����ĸ�����������룺\n");
			input_to("get_id", ob);
		}
	}
}
void get_name(string arg,object ob)
{
	if(check_legal_name(arg)>0) {
		ob->set("name",arg);
		write("���������룺\n");
		input_to("new_passwd",ob);
	} else {
		write("���������Ϸ������������룺\n");
		input_to("get_name", ob);
	}
}
void new_passwd(string arg,object ob)
{
	ob->set("passwd",arg);
	write("�ٴ��������룺\n");
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
		write("��¼���ݴ��̽����"+ret+"\n");
		usr = new(USER_OB);
		usr->set("birth",time);
		usr->set("id",ob->query("id"));
		usr->set("name",ob->query("name"));
		usr->set_temp("login_ob",ob);
		ob->delete_temp("login_temp");
		CHAR_D->setup_new_player(usr);
		ret = usr->save();
		write("��Ϸ���ݴ��̽����"+ret+"\n");
		exec(usr,ob);
		enter_world(usr,0);
	} else {
		write("�����������벻ͬ���������������룺\n");
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
			tell_object(usr,"�������µ�¼��ȡ����������ߣ��ټ�������\n");
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
				write("��ȡ��Ϸ���ݳɹ�����ʼ������Ϸ��\n");
			else
				write("����������ϣ�������Ϸ��\n");
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
			write("��ȡ��Ϸ����ʧ�ܣ��޷�������Ϸ��ǿ�ƶ��ߡ�\n");
			destruct(ob);
			destruct(usr);
		}
	} else {
		write("��������˳���\n");
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
