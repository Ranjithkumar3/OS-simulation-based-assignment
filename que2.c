#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
int n;

void* min(void* arg);
void* max(void* arg);
void* avg(void* arg);
int main()
{

	printf("Enter the number of elements you want to enter \n");
	scanf("%d",&n);
	int array[n];
	printf("\nEnter the elements of the array\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	pthread_t mini,maxi,avger;
	pthread_create(&mini,NULL,min,(void*)array);
	pthread_create(&maxi,NULL,max,(void*)array);
	pthread_create(&avger,NULL,avg,(void*)array);
	pthread_join(mini,NULL);
	pthread_join(maxi,NULL);
	pthread_join(avger,NULL);
	printf("\nThat's all folks\n");
	return 0;
}
void* min(void* arg)
{
	int *myarr=(int *)arg;
	int minize=myarr[0];
	for(int i=0;i<n;i++)
	{
		if(minize>myarr[i])
			minize=myarr[i];
	}
	printf("\n The minimum is %d",minize);
}
void* max(void* arg)
{
	int *myarr=(int *)arg;
	int maxize=myarr[0];
	for(int i=0;i<n;i++)
	{
		if(maxize<myarr[i])
			maxize=myarr[i];
	}
	printf("\n The maximum is %d",maxize);
}
void* avg(void* arg)
{
	int *myarr=(int *)arg;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=myarr[i];
	}
	float avgize=(float)sum/n;
	printf("\n The average is %f",avgize);
}
