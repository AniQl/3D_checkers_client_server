#include "stdafx.h"
#include "ServerWSA.h"
#include <stdio.h>

CServerWSA::CServerWSA(void)
{
	bytesRecv = SOCKET_ERROR;
	clearBuff();

	for (int i = 0; i < 36; i++)
	{
		pola[i] = 0;
	}

}

CServerWSA::~CServerWSA(void)
{
}

// clear buffer
void CServerWSA::clearBuff(void)
{
	for (int i = 0; i < 56; i++)
	{
		sendbuf[i] = 0;
		recvbuf[i] = 0;
	}
	for (int i = 1; i < 20; i++)
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

// Initialize Winsock.
void CServerWSA::initializeWSA(void)
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);//initialize Windows Sockets API
	if (iResult != NO_ERROR)
		printf("Error at WSAStartup()\n");
}

// Create a socket.
void CServerWSA::socketCreate(void)
{
	//tworzone jest gniazdo dla rodziny adresów (AdresFamily) sieci internet dla trybu
	//strumieniowego przesy³ania danych), do obs³ugi tego trybu w seci internet s³u¿y protokó³
	//TCP/IP (IPPROTO_TCP)
	m_socket = socket(AF_INET, SOCK_STREAM, 0); // tworzony jest socket
	if (m_socket == INVALID_SOCKET) { // obs³uga b³êdu
		printf("Error at socket(): %ld\n", WSAGetLastError());
		WSACleanup();
		return;
	}
}

// Bind the socket.
void CServerWSA::bindSocket(unsigned short port){
	server_service.sin_family = AF_INET;
	server_service.sin_addr.s_addr = INADDR_ANY;
	server_service.sin_port = htons(port);
	if (bind(m_socket, (SOCKADDR*)&server_service, sizeof(server_service)) == SOCKET_ERROR) {
		printf("bind() failed.\n");
		closesocket(m_socket);
		return;
	}
}

//send buffor
void CServerWSA::sendData(SOCKET client){
	//wysy³a dane do gniazda serwera okreœlonego przez m_socket z bufora sendbuff. Wysy³ana
	//jest iloœæ bajtów podana przez strlen(sendbuf);

	void * wsk_void;
	wsk_void = &outbuff;
	char * wsk_char = (char *)wsk_void;
	int k = sizeof(outbuff);
	for (int i = 0; i < sizeof(outbuff); i++) {
		sendbuf[i] = wsk_char[i];
	}

	int bytesSent = send(client, sendbuf, sizeof(outbuff), 0);
	printf("Bytes Sent: %ld\n", bytesSent);


}

// Listen on the socket.
void CServerWSA::serverListen(){
	if (listen(m_socket, 10) == SOCKET_ERROR)
		printf("Error listening on socket.\n");
}

void CServerWSA::receiveData(SOCKET client){
	//Odebrane dane s¹ zapisywane do bufora recbuf, którego maksymalny rozmiar jet okreœlony
	//w wywo³aniu funkcji recv. Iloœæ danych odczytanych jest zwracana do zmiennej bytesRecv
	bytesRecv = SOCKET_ERROR;
	while (bytesRecv == SOCKET_ERROR) {
		bytesRecv = recv(client, recvbuf, 56, 0);
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
		for (int i = 0; i < sizeof(inbuff); i++) {
			wsk_char[i] = recvbuf[i];
		}
		printf("Bytes Recv: %ld\n", bytesRecv);
	}

}

void CServerWSA::sprawdz()
{
	//GRACZ 1111111111111111111111111111111111111111111111111111111111111111
	//poziom
	for (int i = 0; i < 6; i++)
	{
		for (int x = 0; x < 13; x += 6)
		{
			if (pola[x + i] == 1 && pola[x + i + 6] == 1 && pola[x + i + 12] == 1 && pola[x + i + 18] == 1)
			{
				winner = 1;
			}
		}
	}
	//pion
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 31; x += 6)
		{
			if (pola[x + i] == 1 && pola[x + i + 1] == 1 && pola[x + i + 2] == 1 && pola[x + i + 3] == 1)
			{
				winner = 1;
			}
		}
	}
	//skos co 5
	for (int i = 0; i < 3; i++)
	{
		if (pola[i + 3] == 1 && pola[i + 8] == 1 && pola[i + 13] == 1 && pola[i + 18] == 1)
		{
			winner = 1;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (pola[i + 9] == 1 && pola[i + 14] == 1 && pola[i + 19] == 1 && pola[i + 24] == 1)
		{
			winner = 1;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (pola[i + 15] == 1 && pola[i + 20] == 1 && pola[i + 25] == 1 && pola[i + 30] == 1)
		{
			winner = 1;
		}
	}
	//skos co 7
	for (int i = 0; i < 3; i++)
	{
		if (pola[i] == 1 && pola[i + 7] == 1 && pola[i + 14] == 1 && pola[i + 21] == 1)
		{
			winner = 1;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (pola[i + 6] == 1 && pola[i + 13] == 1 && pola[i + 20] == 1 && pola[i + 27] == 1)
		{
			winner = 1;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (pola[i + 12] == 1 && pola[i + 19] == 1 && pola[i + 26] == 1 && pola[i + 33] == 1)
		{
			winner = 1;
		}
	}
	//GRACZ22222222222222222222222222222222222222222222222222222222222222222
	//poziom
	for (int i = 0; i < 6; i++)
	{
		for (int x = 0; x < 13; x += 6)
		{
			if (pola[x + i] == 2 && pola[x + i + 6] == 2 && pola[x + i + 12] == 2 && pola[x + i + 18] == 2)
			{
				winner = 2;
			}
		}
	}
	//pion
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 31; x += 6)
		{
			if (pola[x + i] == 2 && pola[x + i + 1] == 2 && pola[x + i + 2] == 2 && pola[x + i + 3] == 2)
			{
				winner = 2;
			}
		}
	}

	//skos co 5
	for (int i = 0; i < 3; i++)
	{
		if (pola[i+3] == 2 && pola[i + 8] == 2 && pola[i + 13] == 2 && pola[i + 18] == 2)
		{
			winner = 2;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (pola[i + 9] == 2 && pola[i + 14] == 2 && pola[i + 19] == 2 && pola[i + 24] == 2)
		{
			winner = 2;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (pola[i + 15] == 2 && pola[i + 20] == 2 && pola[i + 25] == 2 && pola[i + 30] == 2)
		{
			winner = 2;
		}
	}
	//skos co 7
	for (int i = 0; i < 3; i++)
	{
		if (pola[i] == 2 && pola[i + 7] == 2 && pola[i + 14] == 2 && pola[i + 21] == 2)
		{
			winner = 2;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (pola[i + 6] == 2 && pola[i + 13] == 2 && pola[i + 20] == 2 && pola[i + 27] == 2)
		{
			winner = 2;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (pola[i+12] == 2 && pola[i + 19] == 2 && pola[i + 26] == 2 && pola[i + 33] == 2)
		{
			winner = 2;
		}
	}

}

/*for (int i = 0; i < 6; i++)
{
//for (int x = 0; x < 13; x+=6)
//{
if (pola[x + i] == 1 && pola[x + i + 6] == 1 && pola[x + i + 12] == 1 && pola[x + i + 18] == 1)
{
return 1;
}
//}
}*/