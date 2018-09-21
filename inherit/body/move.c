// inherit of F_MOVE

varargs int move(mixed dest, int silently) 
{
	object ob,env;
	if(objectp(dest)) {
		ob = dest;
	} else if(stringp(dest)) {
		ob = load_object(dest);
	}
	
	log_file("move",sprintf("%O\n",ob));
	if(objectp(ob)) {
		env = this_object();
		if(env == ob) {
			return 0;
		} else {
			move_object(ob);
			if(interactive()) {
				CMD_LOOK->main(this_object());
			}
			return 1;
		}
	} 

	return 0;
}
		
