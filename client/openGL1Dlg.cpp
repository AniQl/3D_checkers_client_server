#ifdef WIN32 
#pragma comment(lib,"ws2_32") 
#endif 

#include "stdafx.h"
#include "openGL1.h"
#include "openGL1Dlg.h"
#include "openGLview.h"
#include "GL/glut.h" // GL/glut.h includes gl.h and glu.h
#include "zpr.h"
#include "Figura.h"
#include "afxdialogex.h"

#include "winsock2.h" 
#include "ClientWSA.h" 
#include "conio.h" 
#include <string> 
#include <iostream> 
#include <windows.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h>
#include <winsock.h> // our thread for recving commands 
using namespace std;

DWORD WINAPI receive_cmds(LPVOID lpParam);
//
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
openGLview gl; // deklaracja
//SIEC
CClientWSA klient;
CClientWSA klient2;//dodane

CString adres;
int wysylanie = 1;

void display(void)
{
	gl.display();
}
void resize(int w, int h)
{
	gl.resize(w, h);
}

void keyboard(unsigned char key, int x, int y)
{
	gl.keyboard(key, x, y);
}

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CopenGL1Dlg dialog




CopenGL1Dlg::CopenGL1Dlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CopenGL1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CopenGL1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS3, adresik);
}

BEGIN_MESSAGE_MAP(CopenGL1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CopenGL1Dlg::OnBnClickedOk)
	ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS3, &CopenGL1Dlg::OnIpnFieldchangedIpaddress3)
END_MESSAGE_MAP()


// CopenGL1Dlg message handlers

BOOL CopenGL1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CopenGL1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CopenGL1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CopenGL1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void pick(GLint name) // wybrany zostal, ktorys z elementow na scenie 
{

	if (gl.dostep == 1)
	{
		gl.numer = name;//przepisujemy do klasy opisujacej scene numer wybranego obiektu 
		if (gl.numer < 36)
		{
			if (gl.figury[gl.numer + 72]->hide == 1 && gl.figury[gl.numer + 36]->hide == 1)
			{
				gl.figury[72 + gl.numer]->Pokaz();
				gl.dostep = 0;
			}
		}

	}
	if (gl.dostep == 0 && wysylanie == 1)
	{
		klient.outbuff.flag = 1;
		klient.outbuff.d1 = gl.numer;
		//klient.outbuff.d2 = 0;
		klient.sendData();
		//klient.bytesRecv = -1;
		//gl.dostep = 0;
		wysylanie = 0;
		gl.pola[gl.numer] = 1;
	}
}


/*void animacja(int value)
{
gl.animacja();
glutTimerFunc(30, animacja, 0);
}*/

DWORD WINAPI receive_cmds(LPVOID lpParam)
{
	while (1)
	{
		klient.bytesRecv = -1;
		while (klient.bytesRecv < 0)
		{
			klient.receiveData();
		}
		gl.numerek = klient.inbuff.d3;
		gl.dostep = klient.inbuff.flag;



		if (gl.numerek < 36)
		{
			if (gl.figury[gl.numerek + 36]->hide == 1 && gl.figury[gl.numerek + 72]->hide == 1)
			{
				gl.figury[gl.numerek + 36]->Pokaz();
				//gl.pola[gl.numer] = 2;
			}
		}

		if (klient.inbuff.d2 == 1)
		{
			//gl.gracz1++;
			gl.winner = 1;
		}
		else if (klient.inbuff.d2 == 2)
		{
			//gl.gracz2++;
			gl.winner = 2;
		}

		klient.clearBuff();
		wysylanie = 1;
	}


	return 0;
}


void CopenGL1Dlg::OnBnClickedOk()
{
	char ipAddress[20] = "127.0.0.1";

	strcpy(ipAddress, CT2A(adres));


	DWORD thread;
	klient.initializeWSA();
	klient.socketCreate();
	klient.connectToServer(ipAddress, 10000);
	CreateThread(NULL, 0, receive_cmds, 0, 0, &thread);

	// TODO: Add your control notification handler code here
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);//ustawienie kolorów, precyzji i g³êbi
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGl Test");//tworzymy nowe okno 
	// ustawienie odpowiednich funkcji, które bêd¹ wywo³ywane przy odpowiednich zdarzeniach:

	//glutTimerFunc(30, animacja, 0); //ustawiamy funkcje timera
	zprInit(); // inicjalizacja obslugi myszki 
	zprSelectionFunc(display); // wskazujemy funkcje rysujaca obiekty na scenie 
	zprPickFunc(pick); // wskazujemy funkcje obslugujaca zdarzenie wybrania 

	glutDisplayFunc(display);//ustawiamy funkcje display
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(resize);//ustawiamy funkcje resize


	this->ShowWindow(SW_HIDE);// ukrywamy g³ówne okn


	glutMainLoop(); //uruchamiamy pêtlê openGL
	glutKeyboardFunc(keyboard); 
}

/*
closesocket(klient.m_socket);//release socket
WSACleanup();//czyscimy po sobie

*/

void CopenGL1Dlg::OnIpnFieldchangedIpaddress3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	adresik.GetWindowText(adres);

}
