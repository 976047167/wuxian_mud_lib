// F_ITEM_DBASE
// create by akuma@mud.com.cn
// 2010-05-11
inherit F_NAME;

mapping dbase = ([]);
nosave mapping tmp_dbase = ([]);


mixed set_tmp(mixed prop,mixed data)
{
	return tmp_dbase[prop] = data;
}

mixed query_tmp(mixed prop)
{
	if(!prop)
		return tmp_dbase;
	return tmp_dbase[prop];
}

void delete_tmp(mixed prop)
{
	map_delete(tmp_dbase,prop);
}

mixed set(mixed prop,mixed data)
{
	return dbase[prop] = data;
}

mixed query(mixed prop)
{
	if(!prop)
		return dbase;
	return dbase[prop];
}

void delete(mixed prop)
{
	map_delete(dbase,prop);
}
