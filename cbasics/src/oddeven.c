/* Run an infinite loop trying to accept user inputs, validate them for positive. If number is invalid, don't process and go back to input request. If valid: check if it's even number add it to a variable which holds the sum of all even numbers input so far. If odd number, save it in another variable which always gets updated with odd numbers such that it has only the largest odd number entered so far. If user gives zero as input at any point, get out of the loop immediately and print the even-summation variable and the max odd number storage variable. Do not use 'else' anywhere in the code.*/
#include"../inc/oddeven.h"

void main()
{
	int odd=0,even=0,num=1;

	printf("\n===============number system=================");
	while(num!=0)
	{
		printf("\nenter a number :");
		scanf("%d",&num);
		if(num<=-1)
		{
			printf("\ninvalid number, try again...");
			continue;
		}
		if(num%2==0)
		{
			even=even+num;
			continue;
		}
		if(odd<num)
		{
			odd=num;
			continue;
		}
	}
	printf("sum of even = %d \n largest of odd = %d",even,odd);
}
