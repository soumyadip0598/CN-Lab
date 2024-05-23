#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char data[50];
	printf("Enter the data\n");
	gets(data);
	int len,i,j;
	len=strlen(data);
	int count=0;
	for(i=0;i<len;i++){
		if(data[i]=='1'){
			count++;
		}
	}
	char sh;
	printf("Enter e for even o for odd\n");
	scanf("%c",&sh);
	switch(sh){
		case 'e':
			if(count%2==0){
				printf("No error");
			}
			else{
				printf("Error");
			}
		break;
		case 'o':
			if(count%2==0){
				printf("Error");
			}
			else{
				printf("No error");
			}
		break;
		default:
		printf("Invalid Choice");
	}
	return 0;
}