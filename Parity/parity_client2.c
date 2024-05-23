#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
void main(void){
	//socket
	int network_socket;
	network_socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//assigning
	struct sockaddr_in socket_address;
	socket_address.sin_family=AF_INET;
	socket_address.sin_port=htons(9995);
	socket_address.sin_addr.s_addr=inet_addr("127.0.0.1");
	//connect
	int connection_status;
	connection_status=connect(network_socket,(struct sockaddr*)&socket_address,sizeof(socket_address));
	
	char data[100],s1[10]={'1'},s2[10]={'0'};
	int i,dl,count=0;
	char ch;
	printf("Enter the data\n");
	gets(data);
	dl=strlen(data);
	for(i=0;i<dl;i++){
		if(data[i]=='1'){
			count++;
		}
	}
	data[dl]='\0';
	printf("Total No of 1's are %d",count);
	printf("Enter e for even and o for odd parity\n");
	scanf("%c",&ch);
	switch(ch){
		case 'e':
			if(count%2==0){
				strcat(data,s2);
			}
			else
			{
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
	printf("Updated Data is %s",data);
	send(network_socket,data,sizeof(data),0);
	close(network_socket);
}