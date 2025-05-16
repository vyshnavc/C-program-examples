#include <stdio.h>
#include <stdint.h>

#define SWAP_INT32(x) (x = (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24)))

uint32_t Reverse32(uint32_t value) 
{
    return (((value & 0x0000000F) << 24) |
    	    ((value & 0x000000F0) << 12) |
    	    ((value & 0x00000F00) << 8) |
    	    ((value & 0x0000F000) << 4) |
            ((value & 0x000F0000) >>  4) |
            ((value & 0x00F00000) >>  8) |
            ((value & 0x0F000000) >>  12) |
            ((value & 0xF0000000) >> 24));
/*
    return (((value & 0x000000FF) << 24) |
            ((value & 0x0000FF00) <<  8) |
            ((value & 0x00FF0000) >>  8) |
            ((value & 0xFF000000) >> 24));

    return (((value) << 24) |
            ((value & 0x0000FF00) <<  8) |
            ((value & 0x00FF0000) >>  8) |
            ((value) >> 24));
*/
}

uint16_t Reverse16(uint16_t value)
{
    return (((value & 0x00FF) << 8) |
            ((value & 0xFF00) >> 8));
}

int main()
{

	uint32_t num = 0x12345678;

	printf("Before: %X\n", num);
	printf("After: %X\n", Reverse32(num));
	printf("After: %X\n", Reverse16(num));
	printf("After: %X\n", SWAP_INT32(num));

}
