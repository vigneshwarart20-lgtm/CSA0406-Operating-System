#include<stdio.h>
#include<pthread.h>
void *odd_even(void *arg)
{
	int n;
	printf("\nEnter a num:");
	scanf("%d",&n);
	if(n%2==0){
		printf("\nEVEN");
	}
	else{
		printf("\nODD");
	}
	return NULL;
}
void *fibonacci(void *arg)
{
	int n,a=0,b=1,c,i;
	printf("\nEnter a num:");
	scanf("%d",&n);
	printf("\nFibinacci series");
	printf("%d\t%d",a,b);
	for(i=3;i<=n;i++){
		c=a+b;
		a=b;
		b=c;
		printf("\t%d\t",c);
	}
	return NULL;
}
int main()
{
	pthread_t thread1, thread2;
	pthread_create(&thread1,NULL,odd_even,NULL);
	pthread_create(&thread2,NULL,fibonacci,NULL);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}
