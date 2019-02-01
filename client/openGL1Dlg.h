
// openGL1Dlg.h : header file
//
 


#pragma once

#include"GL/glut.h"
#include "afxcmn.h"
// CopenGL1Dlg dialog
class CopenGL1Dlg : public CDialogEx
{
// Construction
public:
	CopenGL1Dlg(CWnd* pParent = NULL);




// Dialog Data
	enum { IDD = IDD_OPENGL1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();

public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnIpnFieldchangedIpaddress3(NMHDR *pNMHDR, LRESULT *pResult);
	CIPAddressCtrl adresik;
};
