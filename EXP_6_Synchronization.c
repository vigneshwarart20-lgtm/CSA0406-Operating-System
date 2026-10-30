#include<stdio.h>
int buff[20],size,n=-1;
void reader()
{
	if(n<0)
	{
	 printf("\nThe Buffer is empty!");	
	}
	else {
		printf("\nThe values read is %d",buff[n]);
		n--;
	}
}
void writer()
{
	int a;
	if(n==size-1){
		printf("\nthe buffer is full!");
	}
	else {
		printf("\nEnter the value to Write: ");
		scanf("%d0",&a);
		buff[++n]=a;
	}
}
int main()
{
	int ch,m;
	printf("\nEnter the size of Buffer: ");
	scanf("%d",&size);
	do{
		printf("\nEnter ur choice 1.Read 2.Write :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: reader();break;
			case 2: writer();break;
		}
		printf("\nEnter 1 to Reapet the process: ");
		scanf("%d",&m);
	}
	while(m==1);
	return 0;
}
