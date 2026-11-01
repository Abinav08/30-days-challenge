ALGORITHM:
Start the program.
Read the grid size N.
Read all grid risk scores.
Read the threshold value T.
Find the highest row total.
Find the highest column total.
Find the highest risk score and its position.
Count the cells greater than or equal to T.
Calculate both diagonal totals.
Calculate the boundary total.
Find the local hotspots.
Display the final decision as CRITICAL, WARNING or NORMAL.
Stop the program.

  PROGRAM:
#include<stdio.h>
int main()
{
int a[6][6],n,T,i,j,sum,maxRow=-1,maxCol=-1;
int maxRisk,count=0,mainDiag=0,secDiag=0;
int boundary=0,hotspot=0;
do
{
printf("Enter N: ");
scanf("%d",&n);
}while(n<3 || n>6);
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
do
{
printf("Enter score: ");
scanf("%d",&a[i][j]);
}while(a[i][j]<0||a[i][j]>100);
}
}
do
{
printf("Enter N: ");
scanf("%d",&n);
if(n<3||n>6)
printf("INVALID! Please enter 3 to 6.\n");
}while(n<3||n>6);
do
{
printf("Enter T: ");
scanf("%d",&T);
}while(T<1||T>100);
for(i=0;i<n;i++)
{
sum=0;
for(j=0;j<n;j++)
sum+=a[i][j];
if(sum>maxRow)
maxRow=sum;
}
printf("Highest row total: %d\n",maxRow);
for(i=0;i<n;i++)
{
sum=0;
for(j=0;j<n;j++)
sum+=a[i][j];
if(sum==maxRow)
printf("Row %d\n",i+1);
}
for(j=0;j<n;j++)
{
sum=0;
for(i=0;i<n;i++)
sum+=a[i][j];
if(sum>maxCol)
maxCol=sum;
}
printf("Highest column total: %d\n",maxCol);
for(j=0;j<n;j++)
{
sum=0;
for(i=0;i<n;i++)
sum+=a[i][j];
if(sum==maxCol)
printf("Column %d\n",j+1);
}
maxRisk=a[0][0];
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]>maxRisk)
  maxRisk=a[i][j];
if(a[i][j]>=T)
count++;
}
}
printf("Highest risk: %d\n",maxRisk);
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]==maxRisk)
printf("Position: %d,%d\n",i+1,j+1);
}
}
printf("Threshold count: %d\n",count);
for(i=0;i<n;i++)
{
mainDiag+=a[i][i];
secDiag+=a[i][n-1-i];
}
printf("Main diagonal: %d\n",mainDiag);
printf("Secondary diagonal: %d\n",secDiag);
if(mainDiag==secDiag)
printf("Diagonals balanced\n");
else
printf("Diagonals not balanced\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(i==0||i==n-1||j==0||j==n-1)
boundary+=a[i][j];
}
}
printf("Boundary total: %d\n",boundary);
for(i=1;i<n-1;i++)
{
for(j=1;j<n-1;j++)
{
if(a[i][j]>a[i-1][j]&&a[i][j]>a[i+1][j]&&a[i][j]>a[i][j-1]&&a[i][j]>a[i][j+1]&&a[i][j]>=T)
{
printf("Hotspot: %d,%d\n",i+1,j+1);
hotspot++;
}
}
}
if(hotspot==0)
printf("No hotspots found\n");
if(hotspot>0)
printf("CRITICAL\n");
else if(count>=n)
printf("WARNING\n");
else
printf("NORMAL\n");
return 0;
}
