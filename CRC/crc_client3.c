#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(void){
	char data[50],div[10],data1[50];
	int i,j,dl,divl;
	printf("Enter the actual data or dividend\n");
	gets(data);
	printf("Enter the divisor\n");
	gets(div);
	dl=strlen(data);
	divl=strlen(div);
	for(i=0;i<divl-1;i++){
		data[dl+i]='0';
	}
	data[dl+i]='\0';
	printf("Updated data is %s",data);
	strcpy(data1,data);
	for(i=0;i<dl;i++){
		if(data1[i]=='1'){
			for(j=0;j<divl;j++){
				if(data1[i+j]==div[j]){
					data1[i+j]='0';
				}
				else{
					data1[i+j]='1';
				}
			}
		}
	}
	for(i=dl;i<dl+(divl-1);i++){
		data[i]=data1[i];
	}
	printf("Data to be send is %s",data);
}