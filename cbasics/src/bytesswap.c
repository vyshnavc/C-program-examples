#include"../inc/bytesswap.h"

int main()
{
	int data=0x1234;
        printf("\nbefore swapping : %X",data);
	data= ((data<<8)&0xff00)|((data>>8)&0x00ff);
	printf("\nafter swapping  : %X",data);
}


