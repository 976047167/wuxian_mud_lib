// inherit of ROOM
// created by akuma@mud.com.cn
// 2009-10-07

inherit F_DBASE;
inherit F_CLEAN_UP;
#define MAX_ITEM_IN_ROOM        30
object make_inventory(string file)
void setup()
{
    reset();
}

void reset()
{
        mapping ob_list, ob;
        array list;
        int i,j;
        mapping guards;
        object *obs;


        // clear object
        obs = all_inventory();
        if (sizeof(obs) > MAX_ITEM_IN_ROOM)
        {
                // too much objects
                if (arrayp(query_temp("objects")))
                        obs -= query_temp("objects");
                obs = filter_array(obs, (: clonep($1) && ! $1->is_character() :));
                if (sizeof(obs) > MAX_ITEM_IN_ROOM)
                {
                        obs = obs[MAX_ITEM_IN_ROOM..<1];
                        foreach (ob in obs)
                                destruct(ob);
                        if (query("outdoors"))
                                message("vision", "一阵风吹过，卷走了一些东西。\n",
                                        this_object());
                        else
                                message("vision", "突然叮叮咣咣一阵响声过后，好像少了点什么似的。\n",
                                        this_object());
                }
        }
        
		set("no_clean_up", 0);
        ob_list = query("objects");
        if (! mapp(ob_list)) return;
        
        if (! mapp(ob = query_temp("objects")))
                ob = allocate_mapping(sizeof(ob_list));
        list = keys(ob_list);
        for (i = 0; i < sizeof(list); i++)
        {
                // Allocate an array if we have multiple same object specified.
                if (undefinedp(ob[list[i]]) &&
                    intp(ob_list[list[i]]) &&
                    ob_list[list[i]] > 1)
                        ob[list[i]] = allocate(ob_list[list[i]]);

                switch (ob_list[list[i]])
                {
                case 1:
                        if (! ob[list[i]]) ob[list[i]] = make_inventory(list[i]);
                        if (environment(ob[list[i]]) != this_object() &&
                            ob[list[i]]->is_character())
                        {
                                if (! ob[list[i]]->return_home(this_object()))
                                        add("no_clean_up", 1);
                        }
                        break;
                default:
                        for (j = 0; j < ob_list[list[i]]; j++)
                        {
                                // If the object is gone, make another one.
                                if (! objectp(ob[list[i]][j]))
                                {
                                        ob[list[i]][j] = make_inventory(list[i]);
                                        continue;
                                }
                                // Try to call the wandering npc come back here.
                                if (environment(ob[list[i]][j]) != this_object() &&
                                    ob[list[i]][j]->is_character())
                                {
                                        if (! ob[list[i]][j]->return_home(this_object()))
                                                add("no_clean_up", 1);
                                }
                        }
                }
        }
        set_temp("objects", ob);
}
object make_inventory(string file)
{
        object ob;

        ob = new(file);
        ob->set("startroom", base_name(this_object()));
        ob->move(this_object());
        return ob;
}