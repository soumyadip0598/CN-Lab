#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
int main(){
	//socket object creation
	int server_socket;
	server_socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//Defining socket address
	struct sockaddr_in socket_address;
	socket_address.sin_family=AF_INET;
	socket_address.sin_port=htons(9995);
	socket_address.sin_addr.s_addr=inet_addr("127.0.0.1");
	//bind
	bind(server_socket,(struct sockaddr*)&socket_address,sizeof(socket_address));
	//listen
	listen(server_socket,10);
	//accept
	int client_socket;
	client_socket=accept(server_socket,NULL,NULL);
	char str[100];
	//receive
	recv(client_socket,str,sizeof(str),0);
	
	int len=strlen(str);
	int count=0;
	for(int i=0;i<len;i++){
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
				printf("No error for even parity");
			}
			else{
				printf("Error for even parity");
			}
		break;
		case 'o':
			if(count%2==0){
				printf("Error for odd parity");
			}
			else{
				printf("No error for odd parity");
			}
		break;
		default:
			printf("Invalid Choice");
			return 1;
	}
	close(server_socket);
	close(client_socket);
	return 0;
}

	