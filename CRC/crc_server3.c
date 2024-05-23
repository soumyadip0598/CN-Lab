#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(void){
	char data[50],div[10],data1[50];
	int i,j,dl,divl;
	printf("Enter the data\n");
	gets(data);
	printf("Enter the divisor\n");
	gets(div);
	dl=strlen(data);
	divl=strlen(div);
	strcpy(data1,data);
	for(i=0;i<dl-(divl-1);i++){
		if(data[i]=='1'){
			for(j=0;j<divl;j++){
				if(data[i+j]==div[j]){
					data[i+j]='0';
				}
				else{
					data[i+j]='1';
				}
			}
		}
	}
	j=0;
	for(i=dl-(divl-1);i<dl;i++){
		j=j+data[i]-48;
	}
	if(j==0){
		printf("Right Data\n");
		printf("Actual Data\n");
		for(i=0;i<dl-(divl-1);i++){
			printf("%c",data1[i]);
		}
	}
	else{
		printf("Wrong Data Received");
	}
	
}