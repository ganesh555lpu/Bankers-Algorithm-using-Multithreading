#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/types.h>
int s,i,j,n,m,count,w=0,x=0,temp1[200][200],l,z,v,w;
int allocation[200][200],max[200][200],need[200][200],available[200],temp[200],h[200];
void *f1(void*a);
void test();
pthread_mutex_t an;
int res_allocation()
{
printf("enter the no of Threads :");
scanf("%d",&n);
	if(n<=0)
  {
  	printf(" Number of Threads can not be negative and zero \n");
  	printf("enter number of Threads : "); 
		scanf("%d",&n);  
  }
printf("enter the no of type of resources :");
scanf("%d",&m);
if(m<=0){
   	 printf(" resources value can not be negative and zero\n"); 
   	 printf("enter the no of type of resources :");
		scanf("%d",&m);  	
   }
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("enter alocation of resource %d to Thread %d :",j,i);
scanf("%d",&allocation[i][j]);
if(allocation[i][j]<0)
{
 printf("Alloction can not be negative\n");
 printf(" Re enter alocation of resource %d to Thread %d : ",j,i);
scanf("%d",&allocation[i][j]);
}
printf("enter the max  to process %d  of Thread  %d :",j,i);
scanf("%d",&max[i][j]);
if(max[i][j]<0)
{
	printf("max need can not be negative\n");
	printf("enter the max  to Thread %d  of resources  %d : ",j,i);
     scanf("%d",&max[i][j]);
}
need[i][j]=max[i][j]-allocation[i][j];
if(need[i][j]<0)
  {
  	printf(" Max can not Be less than allocation\n ");
  	printf("enter the max  to Thread %d  of resources  %d : ",j,i);
     scanf("%d",&max[i][j]);
  }
}
}
for(i=0;i<m;i++)
{
printf("enter the available resources of type R%d :",i);
scanf("%d",&available[i]);
}
}
void display()
{
printf("Thread  allocaton     max       need \n ");
for(i=0;i<3;i++)
{printf("\t");
for(j=0;j<m;j++)
{
printf(" r%d ",j);
}
}
printf("\n");
for(i=0;i<n;i++)
{printf("T%d\t",i);
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
for(i=0;i<m;i++)
{
printf("enter the available resources of type R%d :",i);
printf("%d",available[i]);
printf("\n");
}
printf("\n");
}
int main()
{
int q,d;
pthread_t p[n];
res_allocation();
display();
if(pthread_mutex_init(&an,NULL)<0)
{
	printf(" error\n");
}
else
{
printf(" enter No of threads requesting: ");
scanf("%d",&d);
int r=d;
for(i=0;i<d;i++)
{
pthread_create(&p[i],NULL,f1,(void*)i);
}
for(i=0;i<d;i++)
{
pthread_join(p[i],NULL);
}
}
}
void *f1(void *a)
{
pthread_mutex_lock(&an);
int d,r;
int q=(int)a;
A:	
printf("Thread Id  %d requesting for resources :\n",q);
if(q<n)
{
for( r=0;r<d;r++)
{
for(l=0;l<m;l++)
{
printf("enter instances of resources is r%d is requesting ;",l);
scanf("%d",&temp1[q][l]);
}
for(l=0;l<m;l++)
{
if(temp1[q][l]<=need[q][l])
{
if(temp1[q][l]<=available[l])
{
allocation[q][l]+=temp1[q][l];
need[q][l]-=temp1[q][l];
available[l]+=allocation[q][l];
}
else
{
printf("resources are not available for grant resources :\n");

break;
}
}
else
{
printf("error due to   max claim\n");
break;
}
x=0;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{ count=0;
  int k;
for( k=0;k<m;k++)
{
if(temp[j]==0&&need[j][k]<=available[k])
{
available[k]+=allocation[j][k];
count++;
if(count==m)
{
temp[j]=1;
printf("allocation  of resources to Thread %d has done\n",j);
h[w]=j;
w++;
}
continue;
}
break;
}
}
}
for( z=0;z<n;z++)
{
if(temp[z]==0)
{
printf("system is unsafe state\n");
x=1;
break;
}
}
if(x==0)
{
printf("\n     SAFE STATE\n");
for( v=0;v<n;v++)//v
{
printf("T[%d]->",h[v]);
}
}
printf("\n");
pthread_mutex_unlock(&an);
//printf("updated tabale");
display();
//printf("\n");
}
}
}
else
{
	printf("check thread id\n");
	goto A;
}
}

