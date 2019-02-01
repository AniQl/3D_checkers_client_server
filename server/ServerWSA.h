#pragma once
#ifdef WIN32
#pragma comment(lib,"ws2_32")
#endif 
#include "winsock2.h"

struct Fdata
{
	int flag;
	float d1;
	float d2;
	float d3;
	char a1W[20];
};

class CServerWSA
{
public:
	CServerWSA(void);
public:
	~CServerWSA(void);
	void clearBuff(void);
	void initializeWSA(); // Initialize Winsock.
	void socketCreate(); // Create a socket.
	void bindSocket(unsigned short port);
	void sendData(SOCKET client); //send sendbuff
	void receiveData(SOCKET client); //receive data
	void serverListen();
	void sprawdz();
public:
	SOCKET m_socket;//socket
	sockaddr_in server_service; // struktura zwiazana z serwerem - patrz bindSocket
	char sendbuf[56]; //bufor wyjœciowy
	char recvbuf[56]; // bufor wejœciowy
	char msg2client1[32];
	char msg2client2[32];
	char msg2client3[32];
	int bytesRecv; // liczba odebranych bajtow
	Fdata inbuff;
	Fdata outbuff;
	char pola[36];
	int winner=0;
};