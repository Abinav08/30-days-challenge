PROGRAM:
#include<stdio.h>
int main(){
float expense;
float smalltotal=0,mediumtotal=0,largetotal=0;
float total=0,average;
int smallcount=0,mediumcount=0,largecount=0;
int validcount=0;
while(1)
{
printf("enter expense : ");
scanf("%f",&expense);
if(expense==0)
{
  break;
}
else if(expense<0)
{
printf("invalid expense /n");
continue;
}
else
{
validcount++;
total = total + expense;
if(expense < 100)
{
smallcount++;
smalltotal = smalltotal + expense;
printf("category:small\n");
}
else if(expense<500){
mediumcount++;
mediumtotal = mediumtotal + expense;
printf("category:medium\n");
}
else{
largecount++;
largetotal = largetotal + expense;
printf(" category:large\n");
}
}
}
printf("number of validexpenses : %d\n",validcount);
printf("total of validexpenses : %f\n",total);
printf("number of smallcounut : %d\n",smallcount);
printf("total of smallexpenses : %f\n",smalltotal);
printf("number of mediumcount : %d\n",mediumcount);
printf("total of mediumexpense : %f\n",mediumtotal);
printf("number of largeexpense : %d\n",largecount);
printf("total of largeexpense : %f\n",largetotal);
if(validcount>0)
{
average = total / validcount;
printf("average of valid expense = Rs %f",average);
}
else
{
printf("invalid expense entered/n");
}
return 0;
}
ALGORITHM:
1.START.
2.INSERT A VARIABLE          EXPENSE,SMALLTOTAL,MEDIUMTOTAL,LARGETOTAL,TOTAL,AVERAGE,SMALLCOUNT,MEDIUMCOUNT,LARGECOUNT,
VALIDCOUNT.
3.INSERT A VALUE 0 FOR THE VARIABLES SMALLTOTAL,LARGETOTAL,MEDIUMTOTAL,TOTAL,SMALLCOUNT,MEDIUMCOUNT,LARGECOUNT,VALIDCOUNT.
4.USE WHILE LOOP WE CAN GET THE EXPENSE.
5.USE IF ELSE STATEMENT TO DISPLAY THE VARIOUS CATEGORY.
6.IF EXPENSE =0 YOU NEED TO STOP, IF EXPENSE<0 PRINT INVALID, IF EXPENSE<100 PRINT SMALL, IF EXPENSE<500 PRINT MEDIUM,  ELSE PRINT LARGE.
7.NOW COUNT THEIR TOTAL BY ADDING WITH EXPENSE.FINALLY PRINT IF VALIDCOUNT >0 PRINT AVERAGE.
8.AVERAGE=TOTAL/VALIDCOUNT PRINT THIS AT IF STATEMENT
9.STOP.
