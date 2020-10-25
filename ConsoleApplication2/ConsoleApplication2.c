#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char *argv[])
{
    WSADATA wsa;

    printf("Initializing WinSock2...\n");

    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0)
    {
        printf("Failed. Error code: %d\n", WSAGetLastError());
        return 1;
    }

    printf("Initialized\n");

    return 0;
}
