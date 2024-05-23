#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
void main(void){
	//socket
	int network_socket;
	network_socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//Assigning socket_address
	struct sockaddr_in socket_address;
	socket_address.sin_family=AF_INET;
	socket_address.sin_port=htons(9000);
	socket_address.sin_addr.s_addr=inet_addr("127.0.0.1");
	//connection
	int connection_status;
	connection_status=connect(network_socket,(struct sockaddr*)&socket_address,sizeof(socket_address));
	
	char data[50],data1[50],div[10];
	int i,j,dl,divl;
	printf("Enter the data\n");
	gets(data);
	printf("Enter the divisor\n");
	gets(div);
	dl=strlen(data);
	divl=strlen(div);
	for(i=0;i<divl-1;i++){
		data[dl+i]='0';
	}
	data[dl+i]='\0';
	//printf("Updated Data is %s",data);
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
	//printf("Data to send is %s",data);
	send(network_socket,data,sizeof(data),0);
	close(network_socket);
}