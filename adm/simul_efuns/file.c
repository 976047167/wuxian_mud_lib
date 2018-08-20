mixed seperate_file(string file)
{
	mixed s = ({});
	if(file_size(file)<= 0)
		return s;
	s = read_file(file);
	s = replace_string(s,"\r","");
	s = explode(s,"\n");
	return s;
}

void assure_file(string file)
{
        int i, j;
        string path, *dir;

        if (file_size(file) != -1)
                return;

        dir = explode(file, "/");
        dir = dir[0..sizeof(dir) - 2];
        path = "/";

        for ( i = 0, j = sizeof(dir); i < j; i++)
        {
                path += dir[i];
                mkdir(path);
                path += "/";
        }

        return;
}

void log_file(string file, string arg)
{
        catch(assure_file(LOG_DIR+file));

        catch(write_file(LOG_DIR+file, arg));

        return;
}

