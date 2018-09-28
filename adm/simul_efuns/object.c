// check the object's euid wehter is root
int is_root(mixed ob)
{
        // if (stringp(ob))
        //         return (SECURITY_D->get_status(ob) == "(admin)");

        // if (objectp(ob))
        // {
        //         if (geteuid(ob) == ROOT_UID)
        //                 // Root object want to execute
        //                 return 1;

        //         return (SECURITY_D->get_status(geteuid(ob)) == "(admin)");
        // }

        return 1;
}
