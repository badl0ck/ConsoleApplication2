#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char *argv[])
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;

    printf("Initializing WinSock2...\n");

    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0)
    {
        printf("Failed. Error code: %d\n", WSAGetLastError());
        return 1;
    }

    printf("Initialized\n");

    if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        printf("Could not create a socket. Error: %d\n", WSAGetLastError());
        return 1;
    }

    printf("Socket Created\n");

    server.sin_addr.s_addr = inet_addr("108.177.14.138");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
       
    if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("connect error");
        return 1;
    }

    printf("connected");

    return 0;
}
