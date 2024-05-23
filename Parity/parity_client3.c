#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char data[50],s1[10]={'1'},s2[10]={'0'};
	printf("Enter the data\n");
	gets(data);
	int len,i,j;
	len=strlen(data);
	int count=0;
	for(int i=0;i<len;i++){
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
				strcat(data,s2);
			}
			else{
				strcat(data,s1);
			}
		break;
		case 'o':
			if(count%2==0){
				strcat(data,s1);
			}
			else{
				strcat(data,s2);
			}
		break;
		default:
		printf("Invalid Choice");
	}
	printf("Updated data is %s",&data);
	return 0;
}