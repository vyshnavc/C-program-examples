/*4. Write a program to find system is little endian or big endia*/
#include"../inc/lorbendian.h"
union test
{
	int x;
	char y;
};
void main()
{
	union test t;
	t.x=1;
	if(t.y==1)
		printf("\nlittle endian\n");
	else
		printf("\nbig endian\n");
}

