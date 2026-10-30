PROGRAM:
#include <stdio.h>
int main()
{
int n,a[15],i,j,id,count;
int missing=0,duplicate=0;
int out=0,r,target;
printf("Enter N: ");
scanf("%d",&n);
if(n<5||n>15)
{
printf("Invalid N");
return 0;
}
for(i=0;i<n;i++)
{
printf("Enter ticket ID: ");
scanf("%d",&a[i]);
}
printf("\nOriginal tickets: ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
for(id=1;id<=n;id++)
{
count=0;
for(i=0;i<n;i++)
{
if(a[i]==id)
count++;
}
if(count==0)
missing=id;
if(count==2)
duplicate=id;
}
if(missing==0||duplicate==0)
{
printf("\nInvalid scan log");
}
else
{
printf("\nDuplicate ID: %d",duplicate);
printf("\nMissing ID: %d",missing);
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
out++;
}
}
printf("\nOut of order pairs: %d",out);
printf("\nEnter last two digits of register number: ");
scanf("%d",&r);
target=(r%n)+1;
printf("Target ID: %d",target);
printf("\nPositions: ");
count=0;
for(i=0;i<n;i++)
{
if(a[i]==target)
{
printf("%d ",i+1);
count++;
}
}
printf("\nOccurrence count: %d",count);
}
return 0;
}
