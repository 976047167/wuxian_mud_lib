// F_ROOM_DBASE
// create by akuma@mud.com.cn
// 2009-10-07

mapping dbase = ([]);

mixed set(mixed prop,mixed data)
{
	return dbase[prop] = data;
}

mixed query(mixed prop)
{
	return dbase[prop];
}

void delete(mixed prop)
{
	map_delete(dbase,prop);
}
