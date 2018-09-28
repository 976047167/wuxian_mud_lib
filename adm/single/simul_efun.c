inherit "/adm/simul_efuns/file.c";
inherit "/adm/simul_efuns/object.c";

string chinese_number(int i)
{
	return CHINESE_D->chinese_number(i);
}
string base_name(object ob)
{
	return explode(file_name(ob), "#")[0];
}

