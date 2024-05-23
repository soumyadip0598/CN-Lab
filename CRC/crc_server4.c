#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
void main(void){
	char data[50],data1[50],div[10];
	int i,j,dl,divl;
	//socket
	int server_socket;
	server_socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//Assigning the socket_address
	struct sockaddr_in socket_address;
	socket_address.sin_family=AF_INET;
	socket_address.sin_port=htons(9000);
	socket_address.sin_addr.s_addr=inet_addr("127.0.0.1");
	//binding
	bind(server_socket,(struct sockaddr*)&socket_address,sizeof(socket_address));
	//listen
	listen(server_socket,10);
	//accept
	int client_socket;
	client_socket=accept(server_socket,NULL,NULL);
	//receiving
	recv(client_socket,data,sizeof(data),0);
	//printf("Enter the data\n");
	//gets(data);
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
		printf("Right data received\n");
		printf("Actual Data\n");
		for(i=0;i<dl-(divl-1);i++){
			printf("%c",data1[i]);
		}
	}
	else{
		printf("Wrong data received");
	}
	close(server_socket);
	close(client_socket);
}