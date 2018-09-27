static mixed enemies = ({});
varargs int is_fighting(object him)
{
	int i,size;
	mixed myenv;
	mixed hisenv;
	object me;

	size = sizeof(enemies);
	if(!size ) {
		return 0;
	}
	myenv = environment();
	if(!myenv) {
		return 0;
	}
	me = this_object();
	if(objectp(him)) {
		hisenv = environment(him);
		if(!hisenv || hisenv != myenv) {
			return 0;
		}
		if(member_array(him,enemies)==-1) {
			return 0;
		}
		return 1;
	}
	for(i=0;i<size;i++) {
		if(objectp(enemies[i])) {
			hisenv = environment(enemies[i]);
			if(!hisenv || hisenv != myenv) {
				enemies[i]->remove_enemy(me);
				enemies[i] = 0;
			}
		}
	}
	enemies -= ({0});
	size = sizeof(enemies);
	if(!size)
		return 0;
	else
		return 1;
}

object select_opponent()
{
	int i,size;
	object me;
	object myenv,hisenv;
	size = sizeof(enemies);
	if(!size)
		return 0;
	myenv = environment();
	for(i=0;i<size;i++) {
                if(objectp(enemies[i])) {
                        hisenv = environment(enemies[i]);
                        if(!hisenv || hisenv != myenv) {
                                enemies[i]->remove_enemy(me);
                                enemies[i] = 0;
                        }
                }
        }
        enemies -= ({0});
	size = sizeof(enemies);
	if(!size) {
		return 0;
	}

	return enemies[random(size)];

}
mixed query_enemies()
{
	return enemies;
}
void add_enemy(object ob)
{
	if(member_array(ob,enemies)== -1) {
		enemies += ({ob});
	}
}

void remove_enemy(object ob)
{
	enemies -= ({ob});
}

void remove_all_enemy(object ob)
{
	int i,size;
	object me;
	size = sizeof(enemies);
	if(!size)
		return ;
	me = this_object();
	for(i=0;i<size;i++) {
		if(objectp(enemies[i])) {
			enemies[i]->remove_enemy(me);
		}
	}	
	enemies = ({});
}

int is_character()
{
	return 1;
}

void do_attack()
{
	object op;
	op = select_opponent();
	if(!op) {
		return ;
	} else {
		COMBAT_D->hit_ob(this_object(),op);
	}
}
