#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include <netinet/in.h>

int main(){
    char server_data[256]="hello world";
    //created socekt
    int sock_server=socket(AF_INET,SOCK_STREAM,0);

    //created address
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(3000);
    server_address.sin_addr.s_addr=INADDR_ANY;

    //binding the socket and server address
    int bind_status=bind(sock_server,(struct sockaddr*) &server_address,sizeof(server_address));
    if(bind_status==-1) {
        printf("didn't bind");
    }

    //listen
    int listStatus =listen(sock_server,SOMAXCONN);
    if(listStatus==-1){
        printf("didnt listen :(");
    }

    struct sockaddr_in client_address;
    int client_socket;
    client_socket=accept(sock_server,NULL,NULL);

    send(client_socket,server_data,sizeof(server_data),0);

    close(sock_server);

    
    //amking the connection
    /* int connection_status=connect(sock_server,(struct sockaddr*) &client_address,sizeof(client_address));
    if(connection_status==-1){ 
        printf("didnt connect")
    }; */


    return 0;
}