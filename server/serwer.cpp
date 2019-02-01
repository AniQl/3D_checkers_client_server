// serwer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#ifdef WIN32
#pragma comment(lib,"ws2_32")
#endif 
#include "winsock2.h"
#include "ServerWSA.h"
#include "conio.h"
#include <string>
#include <iostream>

using namespace std;


CServerWSA server;
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <winsock.h>  // our thread for recving commands 

SOCKET client1 = 0;
SOCKET client2 = 0;



DWORD WINAPI receive_cmds(LPVOID lpParam)
{
	printf("Utworzono watek obslugujacy klienta %d\r\n", lpParam);      // set our socket to the socket passed in as a parameter      
	SOCKET current_client = (SOCKET)lpParam;       // buffer to hold our recived data    
	while (true)
	{
		server.bytesRecv = -1;
		server.clearBuff();

		server.receiveData(current_client);

		server.sprawdz();

		if (server.winner> 0)
		{
			server.clearBuff();
			if (server.winner == 1)
			{
				server.outbuff.d2 = 1;
				server.sendData(client1);
				server.outbuff.d2 = 2;
				server.sendData(client2);
			}
			else if (server.winner == 2)
			{
				server.outbuff.d2 = 2;
				server.sendData(client1);
				server.outbuff.d2 = 1;
				server.sendData(client2);
			}

			/*for (int i = 0; i < 36; i++)
			{
				server.pola[i] = 0;
			}*/

		}


		if (current_client == client1)
		{
			int wynik;
			wynik = server.inbuff.d1;

			server.clearBuff();

			server.pola[wynik] = 1;


			server.outbuff.flag = 1;
			//server.outbuff.d2 = server.sprawdz();
			server.outbuff.d3 = wynik;
			server.sendData(client2);
		}

		if (current_client == client2)
		{
			int wynik;
			wynik = server.inbuff.d1;

			server.clearBuff();

			server.pola[wynik] = 2;


			server.outbuff.flag = 1;
			//server.outbuff.d2 = server.sprawdz();
			server.outbuff.d3 = wynik;
			server.sendData(client1);
		}
		//czyscimy bufor
		server.bytesRecv = -1;
		server.clearBuff();
	}

}



int _tmain(int argc, _TCHAR* argv[])
{
	DWORD thread;

	// Initialize Winsock.
	server.initializeWSA();
	// Create a socket.
	server.socketCreate();
	// bind socket.
	server.bindSocket(10000);
	// waiting for client
	server.serverListen();

	SOCKET client;
	sockaddr_in from;
	int fromlen = sizeof(from);
	printf("Serwer ustawiony\n Nasluchuje na porcie 10000\n");

	while (true)  {    // accept connections   
		client = accept(server.m_socket, (struct sockaddr*)&from, &fromlen);//czekamy na polaczenie od klienta
		printf("Nazwiazano polaczenie z komputerem o adresie: %d.%d.%d.%d\n", from.sin_addr.S_un.S_un_b.s_b1, from.sin_addr.S_un.S_un_b.s_b2, from.sin_addr.S_un.S_un_b.s_b3, from.sin_addr.S_un.S_un_b.s_b4);
		if (client1 == 0)
			client1 = client;
		else
		{
			client2 = client;
		}
		CreateThread(NULL, 0, receive_cmds, (LPVOID)client, 0, &thread);
	}
	// shutdown winsock  
	closesocket(server.m_socket); //release socket
	WSACleanup();//czyscimy po sobie


	system("pause");
	return 0;
}

