ALGORITHM
1. Start
2. put  Int M1,M2,M3,M4,M5
3. Put  Float TOTAL,AVERAGE,PERCENTAGE
4.Read  M1,M2,M3,M4,M5.
5.TOTAL = M1+M2+M3+M4+M5.
6.AVERAGE MARKS = (M1+M2+M3+M4+M5)/5.
7.PERCENTAGE = (TOTAL/500) X 100
8.print the TOTAL,AVERAGE,PERCENTAGE
9.stop 
  
PROGRAM:
#include<stdio.h>
int main(){
float m1,m2,m3,m4,m5,percentage,total,average;
printf("Enter mark1:\n");
scanf("%f",&m1);
printf("Enter mark2:\n");
scanf("%f",&m2);
printf("Enter mark3:\n");
scanf("%f",&m3);
printf("Enter mark4:\n");
scanf("%f",&m4);
printf("Enter mark5:\n");
scanf("%f",&m5);
total=m1+m2+m3+m4+m5;
percentage=(total/5);
average=(total/500)*100;
printf("Enter total :%f\n",total);
printf("Enter average:%f\n",average);
printf("Enter percentage :%f\n",percentage);
return 0;
}

