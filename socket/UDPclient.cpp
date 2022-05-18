//The program to create a test UDP client
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define ADDRSERV "127.0.0.1"
#define PORTNO 8023
#define MAX 256
using namespace std;

int main() {
	struct sockaddr_in servaddr;
	char cmsg[MAX] = "Hello from client to server";
	char smsg[MAX];
	int sockfd,mlen,slen;
	socklen_t clen;
	 slen = sizeof(sockaddr_in);
	 memset(&servaddr,0,slen);
	 memset(smsg,0,MAX);

	 servaddr.sin_family = AF_INET;
         servaddr.sin_addr.s_addr = inet_addr(ADDRSERV);
	 servaddr.sin_port = htons(PORTNO);

	 sockfd = socket(AF_INET,SOCK_DGRAM,0);
	 mlen=sendto(sockfd,cmsg,strlen(cmsg),MSG_CONFIRM,(struct sockaddr *)&servaddr,slen);
	 cout<< "Message sent from the client" << endl;
	 mlen=recvfrom(sockfd,smsg,MAX,MSG_WAITALL,(struct sockaddr *)&servaddr,&clen);
	 cout<< smsg <<endl;
	 close(sockfd);
}
