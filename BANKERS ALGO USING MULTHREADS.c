#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define n 5              
#define m 3            
int ProcCurr[5][3];     
    
int available[10]={3,3,2};        
int max[5][3] = { {7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3} }; 
int allocation[5][3] = { {0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2} }; 
int need[5][3];       
int i,j;
void *f1(void *a);


void display()
{printf("proces  allocaton     max       need \n ");
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
printf("available Resources are\n");
 printf("R0  R1  R2\n ");
  
 printf("3  3  2 \n");
 
}
int main()
{
int q;
pthread_t p[10];
display();

printf("enter no of threads requeired :");
scanf("%d",&q);
for(i=0;i<q;i++)
{
pthread_create(&p[i],NULL,f1,(void *)i);

}

for(i=0;i<q;i++)
{
pthread_join(p[i],NULL);
}
}

