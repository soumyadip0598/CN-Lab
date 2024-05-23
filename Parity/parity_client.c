#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
int main(){
	//socket object creation
	int network_socket;
	network_socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//Defining the address
	struct sockaddr_in socket_address;
	socket_address.sin_family=AF_INET;
	socket_address.sin_port=htons(9995);
	socket_address.sin_addr.s_addr=inet_addr("127.0.0.1");
	//connect
	int connection_status;
	connection_status=connect(network_socket,(struct sockaddr*)&socket_address,sizeof(socket_address));
	
	char str[100];
	char s1[10]={'1'};
	char s2[10]={'0'};
	printf("Enter the binary string\n");
	gets(str);
	int length=strlen(str);
	int count=0;
	for(int i=0;i<length;i++){
		if(str[i]=='1'){
			count++;
		}
	}
	char ch;
	printf("Enter e for even parity and o for odd parity\n");
	scanf("%c",&ch);
	switch(ch){
		case 'e':
			if(count%2==0){
				strcat(str,s2);
			}
			else{
				strcat(str,s1);
			}
		break;
		case 'o':
			if(count%2==0){
				strcat(str,s1);
			}
			else{
				strcat(str,s2);
			}
		break;
		default:
			printf("Invalid Choice");
			return 1;
	}
	printf("Updated string %s",str);
	
	send(network_socket,str,sizeof(str),0);
	close(network_socket);
	
	return 0;
}
	