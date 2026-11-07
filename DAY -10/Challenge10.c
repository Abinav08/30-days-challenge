#include<stdio.h>
char *getName(int i)
{
if(i==0) return "Academic Block";
if(i==1) return "Hostel";
if(i==2) return "Library";
if(i==3) return "Cafeteria";
return "Sports Area";
}
void inputData(float t[5][7],float h[5][7],int a[5][7])
{
int i,j;
for(i=0;i<5;i++)
{
printf("\n%s\n",getName(i));
for(j=0;j<7;j++)
{
do
{
printf("Temperature: ");
scanf("%f",&t[i][j]);
}while(t[i][j]<10||t[i][j]>50);
do
{
printf("Humidity: ");
scanf("%f",&h[i][j]);
}while(h[i][j]<0||h[i][j]>100);
do
{
printf("AQI: ");
scanf("%d",&a[i][j]);
}while(a[i][j]<0||a[i][j]>500);
}
}
}
void displayData(float t[5][7],float h[5][7],int a[5][7])
{
int i,j;
for(i=0;i<5;i++)
{
printf("\n%s\n",getName(i));
for(j=0;j<7;j++)
printf("%.1f ",t[i][j]);
printf("\n");
for(j=0;j<7;j++)
printf("%.1f ",h[i][j]);
printf("\n");
for(j=0;j<7;j++)
printf("%d ",a[i][j]);
printf("\n");
}
}
void calculateAverages(float t[5][7],float h[5][7],int a[5][7],float at[5],float ah[5],float aa[5])
{
int i,j;
float x,y,z;
for(i=0;i<5;i++)
{
x=0;y=0;z=0;
for(j=0;j<7;j++)
{
x=x+t[i][j];
y=y+h[i][j];
z=z+a[i][j];
}
at[i]=x/7;
ah[i]=y/7;
aa[i]=z/7;
printf("\n%s\n",getName(i));
printf("Average Temperature=%.2f\n",at[i]);
printf("Average Humidity=%.2f\n",ah[i]);
printf("Average AQI=%.2f\n",aa[i]);
}
}
void detectRiskZones(float t[5][7],float h[5][7],int a[5][7],int riskDays[5])
{
int i,j;
for(i=0;i<5;i++)
{
riskDays[i]=0;
printf("\n%s Risk Days: ",getName(i));
for(j=0;j<7;j++)
{
if(a[i][j]>150||t[i][j]>35||h[i][j]>80)
{
riskDays[i]++;
printf("%d ",j+1);
}
}
printf("\nTotal Risk Days=%d\n",riskDays[i]);
}
}
void computeGreenIndex(float at[5],float ah[5],float aa[5],float green[5])
{
int i;
float aq,tm,hu;
for(i=0;i<5;i++)
{
aq=100-aa[i]/5;
if(aq<0) aq=0;
if(at[i]>25)
tm=100-4*(at[i]-25);
else
tm=100-4*(25-at[i]);
if(tm<0) tm=0;
if(ah[i]>50)
hu=100-2*(ah[i]-50);
else
hu=100-2*(50-ah[i]);
if(hu<0) hu=0;
green[i]=0.4*aq+0.3*tm+0.3*hu;
}
}
void displayRanking(float green[5])
{
int i,j,rank;
printf("\nGREEN INDEX RANKING\n");
for(i=0;i<5;i++)
{
rank=1;
for(j=0;j<5;j++)
{
if(green[j]>green[i])
rank++;
}
printf("%s=%.2f Rank=%d\n",getName(i),green[i],rank);
}
}
void displayRecommendations(float at[5],float ah[5],float aa[5],int riskDays[5])
{
int i;
for(i=0;i<5;i++)
{
printf("\n%s: ",getName(i));
if(aa[i]>150)
printf("Reduce pollution. ");
if(at[i]>35)
printf("Plant more trees. ");
if(ah[i]>80)
printf("Improve ventilation. ");
if(riskDays[i]>0&&aa[i]<=150&&at[i]<=35&&ah[i]<=80)
printf("Check risk days. ");
if(riskDays[i]==0)
printf("Continue monitoring. ");
printf("\n");
}
}
int main()
{
float t[5][7],h[5][7];
int a[5][7];
float at[5],ah[5],aa[5],green[5];
int riskDays[5];
int choice,dataReady=0;
do
{
printf("\n1.Input Data\n");
printf("2.Display Data\n");
printf("3.Averages\n");
printf("4.Risk Days\n");
printf("5.Green Index and Ranking\n");
printf("6.Recommendations\n");
printf("7.Exit\n");
printf("Enter choice: ");
scanf("%d",&choice);
if(choice==1)
{
inputData(t,h,a);
dataReady=1;
}
else if(choice>=2&&choice<=6)
{
if(dataReady==0)
printf("Enter data first!\n");
else if(choice==2)
displayData(t,h,a);
else if(choice==3)
calculateAverages(t,h,a,at,ah,aa);
else if(choice==4)
detectRiskZones(t,h,a,riskDays);
else if(choice==5)
{
calculateAverages(t,h,a,at,ah,aa);
computeGreenIndex(at,ah,aa,green);
displayRanking(green);
}
else if(choice==6)
{
calculateAverages(t,h,a,at,ah,aa);
detectRiskZones(t,h,a,riskDays);
displayRecommendations(at,ah,aa,riskDays);
}
}
else if(choice==7)
printf("Thank you!\n");
else
printf("Invalid choice!\n");
}while(choice!=7);
return 0;
}
