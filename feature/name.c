// F_NAME
mixed query(mixed prop);

int id(string id)
{
	if(id == query("id"))
		return 1;
	return 0;
}
