#include<stdio.h>
#include<stdlib.h>
#include "scanner.h"

int main(int argc, char *argv[])
{
	if(argc!=4)
	{
		printf("Usage: %s <IP> <start_port> <end_port>\n",argv[0]);
		return 1;
	}
	char *ip = argv[1];
	int start_port = atoi(argv[2]);
	int end_port = atoi(argv[3]);
	if (start_port < 1 || end_port > MAX_PORT || start_port > end_port) {
    		printf("Invalid port range\n");
    	return 1;
}
	scan_ports(ip,start_port,end_port);
	return 0;
}
