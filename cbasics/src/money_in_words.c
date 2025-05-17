/*write a program to print money in words 
  100 = one hundred , 456 = four hundred fifty six */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void One_Digi(int *,int,int);
void Two_Digi(int *,int,int,int);
void Three_Digi(int *,int);
void Four_Digi(int *,int);
void Five_Digi(int *,int);
void Six_Digi(int *,int);

int main()
{

    int number,dup,digi_count=0,ret;

    printf("\n\033[1;31m======= Number to Word Converter ======= \033[0m\n");
    while(1){
        printf("\nenter the number = ");
        ret=scanf("%d",&number);
        if(ret==0)
        {
            printf("\nWrong input....... \n");
            scanf("%*s");
            continue;
        }
        break;
    }
    dup=number;

    while(dup){
        dup=dup/10;
        digi_count++;
    }

    int *array=malloc(sizeof(int)*digi_count);

    dup=number;
    int count=digi_count;
    while(dup){
        array[count-1]=dup%10;
        dup=dup/10;
        count--;
    }
    switch(digi_count){
        case 1 :
            One_Digi(array,digi_count,0);
            break;
        case 2 :
            Two_Digi(array,digi_count,0,0);
            break;
        case 3 :
            Three_Digi(array,digi_count);
            break;
        case 4 :
            Four_Digi(array,digi_count);
            break;
        case 5 :
            Five_Digi(array,digi_count);
            break;
        case 6 :
            Six_Digi(array,digi_count);
            break;
        default:
            printf("\nenter valied number");
            break;
    }

}
void One_Digi(int *array,int digi_count,int count)
{

    char *Number_0[]={"NINE","EIGHT","SEVEN","SIX","FIVE","FOUR","THREE","TWO","ONE"};
    if(count>0){
        printf("%s",Number_0[9-array[digi_count-count]]);
    }
    else if(array[digi_count-1]!=0){
        printf(" %s",Number_0[9-array[digi_count-1]]);
    }
    else;
}
void Two_Digi(int *array,int digi_count,int count,int flag)
{
    char *Number_1[]={"NINTEEN","EIGHTEEN","SEVENTEEN","SIXTEEN","FIFTEEN","FOURTEEN","THIRTEEN","TWELVE","ELEVEN"};
    char *Number_2[]={"NINTY","EIGHTY","SEVENTY","SIXTY","FIFTY","FOURTY","THIRTY","TWENTY","TEN"};
    if(count>0){
        if(flag==1){
            printf(" %s",Number_1[9-array[digi_count-count]]);     
        }
        else{
        printf("%s",Number_2[9-array[digi_count-count]]);
        }
    }
    else if(array[digi_count-2]==1&&array[digi_count-1]!=0){
        printf(" %s",Number_1[9-array[digi_count-1]]);     
    }
    else{
        if(array[digi_count-2]==0)
            One_Digi(array,digi_count,0);
        else{
            printf(" %s",Number_2[9-array[digi_count-2]]);
            One_Digi(array,digi_count,0);
        }

    }
}
void Three_Digi(int *array,int digi_count)
{

    if(array[digi_count-3]==0){
        Two_Digi(array,digi_count,0,0);
    }
    else{
        One_Digi(array,digi_count,3);
        printf(" HUNDRED ");
        Two_Digi(array,digi_count,0,0);
    }
}
void Four_Digi(int *array,int digi_count)
{

    if(array[digi_count-4]==0){
        Three_Digi(array,digi_count);
    }
    else{
        One_Digi(array,digi_count,4);
        printf(" THOUSAND ");
        Three_Digi(array,digi_count);
    }
}
void Five_Digi(int *array,int digi_count)
{
    if(array[digi_count-5]==0){
        Four_Digi(array,digi_count);
    }
    else{
        if(array[digi_count-5]==1&&array[digi_count-4]!=0){
        Two_Digi(array,digi_count,4,1);
        printf(" THOUSAND ");
        Three_Digi(array,digi_count);
        }
        if(array[digi_count-5]==1&&array[digi_count-4]==0){
        Two_Digi(array,digi_count,5,0);
        printf(" THOUSAND ");
        Three_Digi(array,digi_count);
        }
        else{
        Two_Digi(array,digi_count,5,0);
        Four_Digi(array,digi_count);
        }
    }
}
void Six_Digi(int *array,int digi_count)
{
    if(array[digi_count-6]==0){
        Five_Digi(array,digi_count);
    }
    else{
        One_Digi(array,digi_count,6);
        printf(" lakh ");
        Five_Digi(array,digi_count);
    }
}
