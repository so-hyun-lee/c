
// ChatClientDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "ConnectSocket.h"

// CChatClientDlg ��ȭ ����
class CChatClientDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CChatClientDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	CConnectSocket m_Socket; // CConnectSocket Ŭ���� ��ü�� ����� ����մϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CHATCLIENT_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	CListBox m_list;
	afx_msg void OnEnChangeEdit1();
	CEdit m_Edit;
	CString m_strMessage;
};
