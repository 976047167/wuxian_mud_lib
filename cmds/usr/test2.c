int main(object me)
{
	mixed a;
	a = ({1,2,3,me});
	printf("%O\n",member_array(me,a));
	return 1;
}
