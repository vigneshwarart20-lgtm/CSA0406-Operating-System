#include<stdio.h>
int main()
{
	int n, bu[10],tat[10],wt[10],t_tat=0,t_wt=0,i,p[10];
	float avg_tat,avg_wt;
	printf("\nEnter the no.of process:");
	scanf("%d",&n);
	printf("\nEnter the Burst Time:");
	for(i=0;i<n;i++){
		scanf("%d",&bu[i]);
		p[i]=i+1;
	}
	wt[0]=0;
	for(i=1;i<n;i++){
		wt[i]=wt[i-1]+bu[i-1];
	}
	for(i=0;i<n;i++){
		tat[i]=bu[i]+wt[i];
		t_tat +=tat[i];
		t_wt+=wt[i];
	}
	avg_tat=(float)t_tat/n;
	avg_wt=(float)t_wt/n;
	printf("\nProcess        Turn Arount Time      Waiting Time");
	for(i=0;i<n;i++){
		printf("\nP%d\t\t%d\t\t%d",p[i],tat[i],wt[i]);
	}
	printf("\nAverage Turn Around Time :%2f",avg_tat);
	printf("\nAverage Waiting Time :%2f",avg_wt);
	return 0;
	
}
