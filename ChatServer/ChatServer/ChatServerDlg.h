
// ChatServerDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "ListenSocket.h"

// CChatServerDlg ��ȭ ����
class CChatServerDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CChatServerDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	CListenSocket m_ListenSocket;
	CChatServerDlg* pMain;
	CString strIPAdress;
	//ListenSocket.h�� include�ϰ� CListenSocket Ŭ���� ��ü�� ����� �߰��մϴ�.
// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CHATSERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_List;
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedOk();
	afx_msg void OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult);
};
