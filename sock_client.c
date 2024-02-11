/*# this is the client that will connect to our remote server using connect() function.. the addres of our remote server is server_address ..the client 
will make the connection via net_socket (a socket) . the received data will be stored in a string ccalled server_response 
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
int main(){
    //create a socket
    int net_socket;
    net_socket=socket(AF_INET,SOCK_STREAM,0);

    //specify address for a socket
    struct sockaddr_in server_address;
    server_address.sin_family= AF_INET;
    server_address.sin_port=htons(3000);
    server_address.sin_addr.s_addr=INADDR_ANY;

    //connect to remote server
    int connection_status= connect(net_socket,(struct sockaddr*) &server_address,sizeof(server_address));// 0 means all 0 , -1 means didn't work as expected
    if(connection_status==0) {
        printf("connection working");
    }else {
        printf("didn't connect");
    }

    //receive data from server
    char server_response[256];
    recv(net_socket,&server_response,sizeof(server_response),0);

    //print data received from the server
    printf("the server sent the data %s",server_response);
    
    //close the connection
    close(net_socket);

    //printf("hello wotttrld");
    return 0;
}

