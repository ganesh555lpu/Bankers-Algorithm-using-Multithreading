#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>     
 int i,j,m,n;   
void *f1(void *a);
int main()
{
do{

printf("enter the no of process\n :");
scanf("%d",&n);
  
  if(n<=0)
  {
  	printf(" Number of process  can not be negative and zero \n");
  }
}while(n<=0);

do{
printf("enter the no of type of resources\n :");
scanf("%d",&m);
   if(m<=0){
   	 printf(" resources value can not be negative and zero\n");   	
   }
}while(m<=0);
int available[m];
int max[n][m]; 
int allocation[n][m];
int need[n][m];     
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
	
printf("enter alocation of resource %d to process %d :",j,i);
scanf("%d",&allocation[i][j]);

if(allocation[i][j]<0)
{
 printf("Alloction can not be negative\n");
 printf(" Re enter alocation of resource %d to process %d : ",j,i);
scanf("%d",&allocation[i][j]);
}
}
}
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("enter the max  to process %d  of resources  %d : ",j,i);
scanf("%d",&max[i][j]);
if(max[i][j]<0)
{
	printf("max need can not be negative\n");
	printf("enter the max  to process %d  of resources  %d : ",j,i);
     scanf("%d",&max[i][j]);
}
need[i][j]=max[i][j]-allocation[i][j];
}
}

for(i=0;i<m;i++)
{
printf("enter the available resources of type R%d: ",i);
scanf("%d",&available[i]);
if(available[i]<0)
{
	printf(" availabe resources can not be negative\n");
	printf("enter the available resources of type R%d: ",i);
     scanf("%d",&available[i]);
}

}
printf("proces  allocaton     max       need \n ");
for(i=0;i<3;i++)
{printf("\t");
for(j=0;j<m;j++)
{
printf(" r%d ",j);
}
}
printf("\n");
for(i=0;i<n;i++)
{printf("p%d\t",i);
for(j=0;j<m;j++)
{
printf("%d ",allocation[i][j]);
}
printf("\t");
for(j=0;j<m;j++)
{
printf("%d ",max[i][j]);
}
printf("\t");
for(j=0;j<m;j++)
{
need[i][j]=max[i][j]-allocation[i][j];
printf("%d ",need[i][j]);
}

printf("\n");
}
printf(" available resources are\n");

for(i=0;i<m;i++)
{
	printf("R%d : ",i);
	printf("%d",available[i]);

	printf("\t");
}
}

/*int main()
{
int q;
pthread_t p[10];
res_allocation();
display();
}*/
//printf("enter no of threads requeired :");
//scanf("%d",&q);
/*for(i=0;i<q;i++)
{
pthread_create(&p[i],NULL,f1,(void *)i);

}

for(i=0;i<q;i++)
{
pthread_join(p[i],NULL);
}
}*/

