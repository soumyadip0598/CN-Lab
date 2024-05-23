#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
void main(void){
	char data[50],s1[10]={'1'},s2[10]={'0'};
	//socket
	int server_socket;
	server_socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//Assigning
	struct sockaddr_in socket_address;
	socket_address.sin_family=AF_INET;
	socket_address.sin_port=htons(9995);
	socket_address.sin_addr.s_addr=inet_addr("127.0.0.1");
	//bind
	bind(server_socket,(struct sockaddr*)&socket_address,sizeof(socket_address));
	//listen
	listen(server_socket,10);
	//acept
	int client_socket;
	client_socket=accept(server_socket,NULL,NULL);
	recv(client_socket,data,sizeof(data),0);
	printf("Received Data is %s",data);
	int count=0;
	int dl=strlen(data);
	for(int i=0;i<dl;i++){
		if(data[i]=='1'){
			count++;
		}
	}
	char ch;
	printf("Enter e for even parity and o for odd parity\n");
	scanf("%c",&ch);
	switch(ch){
		case 'e':
			if(count%2==0){
				printf("No error");
			}
			else
			{
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
}
