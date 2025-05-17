/* program to swap two bits of a byte*/
#include"../inc/bitsswap.h"
void main()
{
	int a=10,i;
	for(i=0;i<8;i++)
	{
		if((a>>i&1)!=(a>>i+1&1))
		{
			a=a^1<<i;
			a=a^1<<i+1;
		}
	}
	printf("%d",a);
}
