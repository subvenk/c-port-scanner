#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include "scanner.h"

void scan_ports(char *ip, int start_port, int end_port)
{
	int sock;
	struct sockaddr_in server;
	
	for(int port = start_port; port <= end_port; port++)
	{
		printf("Scanning port %d\n",port);
		sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock == -1)
		{
			printf("Could not create socket\n");
			return;
		}
		server.sin_addr.s_addr = inet_addr(ip);
		server.sin_family = AF_INET;
		server.sin_port = htons(port);
		
		if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0)
		{
			printf("\nPort %d is open\n\n",port);
		}
		close(sock);
	}
}

