#include<stdio.h>
#include<stdlib.h>
int main(){
	char so[10],ou[10],ch;
	FILE *fp1,*fp2;
	printf("Enter Source File name:\n");
	scanf("%s",so);
	printf("Enter the output file:\n");
	scanf("%s",ou);
	fp1=fopen(so,"r");
	fp2=fopen(ou,"w");
	if (fp1==NULL||fp2==NULL){
		printf("Unable to read/write file\n");
		exit(0);
	}
	ch=fgetc(fp1);
	while(ch!=EOF){
		fputc(ch,fp2);
		ch=fgetc(fp1);
	}
	printf("The file is copied sucessfuly!\n");
	fclose(fp1);
	fclose(fp2);
	return 0;
}
