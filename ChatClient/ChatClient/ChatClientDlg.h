
// ChatClientDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "ConnectSocket.h"

// CChatClientDlg 대화 상자
class CChatClientDlg : public CDialogEx
{
// 생성입니다.
public:
	CChatClientDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	CConnectSocket m_Socket; // CConnectSocket 클래스 객체를 멤버로 등록합니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CHATCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
