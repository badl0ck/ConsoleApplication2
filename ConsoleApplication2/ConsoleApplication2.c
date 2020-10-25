#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char *argv[])
{
    WSADATA wsa;
    SOCKET s;

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

    return 0;
}
