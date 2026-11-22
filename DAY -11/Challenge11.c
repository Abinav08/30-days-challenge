#include<stdio.h>
#define ZONES 5
#define DAYS 7
char*name[5]={"Academic","Hostel","Library","Cafeteria","Sports"};
void inputWaterData(int u[5][7],int t[5]){
int i,j;
for(i=0;i<5;i++){
printf("\nEnter target for %s: ",name[i]);
scanf("%d",&t[i]);
while(t[i]<100||t[i]>50000){
printf("Invalid target. Enter again: ");
scanf("%d",&t[i]);
}
for(j=0;j<7;j++){
printf("Day %d usage: ",j+1);
scanf("%d",&u[i][j]);
while(u[i][j]<0||u[i][j]>50000){
printf("Invalid reading. Enter again: ");
scanf("%d",&u[i][j]);
}
}
}
}
void displayWaterData(int u[5][7],int t[5]){
int i,j;
printf("\nZone\t");
for(j=0;j<7;j++)
printf("D%d ",j+1);
printf("Target\n");
for(i=0;i<5;i++){
printf("%s\t",name[i]);
for(j=0;j<7;j++)
printf("%d ",u[i][j]);
printf("%d\n",t[i]);
}
}
void calculateZoneStats(int*p,int*total,float*average,int*peak,int*peakDay){
int i;
*total=0;
*peak=*p;
*peakDay=1;
for(i=0;i<7;i++){
*total+=*(p+i);
if(*(p+i)>*peak){
*peak=*(p+i);
*peakDay=i+1;
}
}
*average=*total/7.0;
}
void detectWaterAlerts(int*p,int target,int*over,int*excess,int*spike,int*alert){
int i,flag;
*over=*excess=*spike=*alert=0;
for(i=0;i<7;i++){
flag=0;
if(*(p+i)>target){
(*over)++;
*excess+=*(p+i)-target;
flag=1;
}
if(i>0&&*(p+i)*10>*(p+i-1)*14){
(*spike)++;
flag=1;
}
if(flag)
(*alert)++;
}
}
void generateAuditReport(int u[5][7],int t[5],int e[5],int o[5],int s[5],int a[5]){
int i,total,peak,day;
float avg;
for(i=0;i<5;i++){
calculateZoneStats(&u[i][0],&total,&avg,&peak,&day);
detectWaterAlerts(&u[i][0],t[i],&o[i],&e[i],&s[i],&a[i]);
printf("\n%s Total: %d",name[i],total);
printf("\nAverage: %.2f",avg);
printf("\nHighest: %d on Day %d",peak,day);
printf("\nOver-limit days: %d",o[i]);
printf("\nExcess litres: %d",e[i]);
printf("\nSpike days: %d",s[i]);
printf("\nAlert days: %d\n",a[i]);
}
}
void rankZones(int e[5]){
int i,j,rank;
printf("\nZone Ranking:\n");
for(i=0;i<5;i++){
rank=1;
for(j=0;j<5;j++)
if(e[j]>e[i])
rank++;
printf("Rank %d: %s (%d litres)\n",rank,name[i],e[i]);
}
}
void displayConservationActions(int o[5],int s[5],int e[5]){
int i;
for(i=0;i<5;i++){
printf("\n%s: ",name[i]);
if(s[i]>0)
printf("Check leaks. ");
if(o[i]>=3)
printf("Water audit needed. ");
else if(o[i]>0)
printf("Inspect taps and valves. ");
if(o[i]==0&&s[i]==0)
printf("Maintain good practices.");
}
}
int main(){
int u[5][7],t[5];
int e[5]={0},o[5]={0};
int s[5]={0},a[5]={0};
int choice,report=0;
inputWaterData(u,t);
do{
printf("\n\n1. Display Water Data");
printf("\n2. Audit Report");
printf("\n3. Rank Zones");
printf("\n4. Conservation Actions");
printf("\n5. Exit");
printf("\nEnter choice: ");
scanf("%d",&choice);
if(choice==1)
displayWaterData(u,t);
else if(choice==2){
generateAuditReport(u,t,e,o,s,a);
report=1;
}
else if(choice==3){
if(report)
rankZones(e);
else
printf("Generate report first.");
}
else if(choice==4){
if(report)
displayConservationActions(o,s,e);
else
printf("Generate report first.");
}
else if(choice!=5)
printf("Invalid choice.");
}while(choice!=5);
return 0;
}
