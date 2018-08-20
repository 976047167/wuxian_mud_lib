// by akuma@mud.com.cn

#define MINI_LEVEL 	12
mixed level_modify = ({});
void setup();

void create()
{
	setup();
}

string add_color(string col,string arg)
{
	switch(col) {
	case 	"YEL":
		arg = YEL+arg;
		break;
	case	"BLU":
		arg = BLU+arg;
		break;
	case	"MAG":
		arg = MAG+arg;
		break;
	case	"CYN":
		arg = CYN+arg;
		break;
	case	"WHT":
		arg = WHT+arg;
		break;
	case	"HIY":
		arg = HIY+arg;
		break;
	case	"HIB":
		arg = HIB+arg;
		break;
	case	"HIM":
		arg = HIM+arg;
		break;
	case	"HIC":
		arg = HIC+arg;
		break;
	case	"HIW":
		arg = HIW+arg;
		break;
	case	"BLK":
		arg = BLK+arg;
		break;
	case	"RED":
		arg = RED+arg;
		break;
	case	"GRN":
		arg = GRN+arg;
		break;
	case	"HIR":
		arg = HIR+arg;
		break;
	case	"HIG":
		arg = HIG+arg;
		break;
	default :
		break;
	}
	return arg+NOR;
}		

void setup()
{
	mixed tmp,tmp2;
	int i,sz;
	tmp = explode(read_file(LEVEL_MODIFY),"\n");	
	sz = sizeof(tmp);
	for(i=0;i<sz;i++) {
		tmp2 = explode(tmp[i],",");
		level_modify += ({add_color(tmp2[0],tmp2[1])});
	}
}

string query_level_modify(int level)
{
	int lv,minilv;
	if(level <= 0) {
		lv = 0;
		minilv = 0;
	} else if(level > sizeof(level_modify)*MINI_LEVEL) {
		lv = sizeof(level_modify)-1;
		minilv = MINI_LEVEL;
	} else {
		lv = (level-1) / MINI_LEVEL;
		minilv = (level-1) % MINI_LEVEL+1;
	}
	return level_modify[lv]+"ÆÚ"+chinese_number(minilv)+"½×";
}

int setup_new_player(object usr)
{
	if(!objectp(usr))
		return 0;
	usr->set("hp",100);
	usr->set("mp",100);
	usr->set("max_hp",100);
        usr->set("max_mp",100);
	usr->set("exp",0);
	usr->set("level",1);
	return 1;
	
}
