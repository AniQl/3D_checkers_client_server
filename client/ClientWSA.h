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
	char a1W[10];
};
class CClientWSA
{
public:
	CClientWSA(void);
public:
	~CClientWSA(void);
	void initializeWSA(); // inicjalizuje Winsock. 
	void socketCreate(); // tworzy socket. 
	void connectToServer(const char * addr, unsigned short port); //po��czenie z serwerem 
	void sendData(); //wysy�a sendbuff 
	void receiveData(); //odbiera recvbuff 
	void clearBuff(void);//czysci bufor wejsciowy i wyjsciowy 
public:
	SOCKET m_socket;//socket 
	sockaddr_in clientService; // struktura zwiazana z serwerem - patrz connectToServer 
	char sendbuf[56]; //bufor wyj�ciowy 
	char recvbuf[56]; // bufor wej�ciowy 
	int bytesRecv;//liczba otrzymanych bajtow; 
	Fdata inbuff;
	Fdata outbuff;
};