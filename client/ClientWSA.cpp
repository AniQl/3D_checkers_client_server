#include "stdafx.h" 
#include "ClientWSA.h" 
#include <stdio.h> 


CClientWSA::CClientWSA(void)
{
}


CClientWSA::~CClientWSA(void)
{
}


void CClientWSA::initializeWSA()
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);//initialize Windows Sockets API 

	if (iResult != NO_ERROR)
		printf("Error at WSAStartup()\n");
}

void CClientWSA::socketCreate()
{
	m_socket = socket(AF_INET, SOCK_STREAM, 0); // tworzony jest socket 
	if (m_socket == INVALID_SOCKET) { // obs³uga b³êdu 
		printf("Error at socket(): %ld\n", WSAGetLastError());
		WSACleanup();
		return;
	}
}

void CClientWSA::connectToServer(const char * addr, unsigned short port)
{
	clientService.sin_family = AF_INET;
	clientService.sin_addr.s_addr = inet_addr(addr);
	clientService.sin_port = htons(port);//htons( 10000 );- konwersja zapsiu bitowego w bajtach 
	if (connect(m_socket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR)
	{
		printf("Failed to connect.\n"); //obs³uga b³êdu 
		WSACleanup();//w przypadu b³edu nale¿y równie¿ od³¹czyæ bibliotekê 
		return;
	}
}


void CClientWSA::sendData()
{
	void * wsk_void;
	wsk_void = &outbuff;
	char * wsk_char = (char *)wsk_void;
	int k = sizeof(outbuff);
	for (int i = 0; i<sizeof(outbuff); i++) {
		sendbuf[i] = wsk_char[i];
	}

	int bytesSent = send(m_socket, sendbuf, sizeof(outbuff), 0);
	printf("Bytes Sent: %ld\n", bytesSent);
}


void CClientWSA::receiveData()
{
	bytesRecv = SOCKET_ERROR;

	while (bytesRecv == SOCKET_ERROR) {
		bytesRecv = recv(m_socket, recvbuf, 56, 0);
		if (bytesRecv == 0 || bytesRecv == WSAECONNRESET) {
			printf("Connection Closed.\n");
			break;
		}
		if (bytesRecv < 0)
			return;

		void * wsk_void;
		wsk_void = &inbuff;
		char * wsk_char = (char *)wsk_void;
		int k = sizeof(inbuff);
		for (int i = 0; i<sizeof(inbuff); i++) {
			wsk_char[i] = recvbuf[i];
		}
		printf("Bytes Recv: %ld\n", bytesRecv);
	}

}

void CClientWSA::clearBuff(void)
{
	for (int i = 0; i<56; i++)
	{
		sendbuf[i] = 0;
		recvbuf[i] = 0;
	}
	for (int i = 1; i<20; i++)
	{
		inbuff.a1W[i] = 0;
		outbuff.a1W[i] = 0;
	}
	inbuff.flag = 0;
	outbuff.flag = 0;
	inbuff.d1 = 0;
	outbuff.d1 = 0;
	inbuff.d2 = 0;
	outbuff.d2 = 0;
	inbuff.d3 = 0;
	outbuff.d3 = 0;
	bytesRecv = -1;
}