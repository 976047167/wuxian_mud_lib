varargs void tell_room(mixed ob, string str, object *exclude,mixed type)
{
        mixed inv;
        mixed sets;
        int i;
        if(type == "combat_msg") {
                if(!ob)
                        return;
                sets = ({});
                inv = all_inventory(ob);
                for(i=0;i<sizeof(inv);i++) {
                        if(userp(inv[i]) && !inv[i]->query("env/combat_brief")) {
                                sets += ({inv[i]});
                        }
                }
                message("tell_room", str, sets , exclude);
        } else {
                if( ob ) message("tell_room", str, ob, exclude);
        }
}

