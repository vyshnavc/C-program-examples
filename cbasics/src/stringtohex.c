/*program to convert String into Hexadecimal*/
#include"../inc/stringtohex.h"

void main()
{
	char c[5]="ABCD",hex[20];
	int i,j;
	for(i=0,j;c[i];i++,j=j+2)
	{
		sprintf((hex+j),"%X",c[i]);
	}
	//printf("%d",a);
	printf("%s",hex);
}

