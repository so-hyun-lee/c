// ClientSocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ChatServer.h"
#include "ClientSocket.h"
#include "ListenSocket.h"
#include "ChatServerDlg.h"

// CClientSocket

CClientSocket::CClientSocket()
{
	m_pListenSocket = NULL; //CListenSocket 클래스 객체의 주소를 저장하는 멤버 m_pListenSocket를 추가하고 생성자에서 NULL로 초기화합니다.

 
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket 멤버 함수
void CClientSocket::SetListenSocket(CAsyncSocket* pSocket)
{
	m_pListenSocket = pSocket;
}

void CClientSocket::OnClose(int nErrorCode) //CAsyncSocket 클래스의 OnClose() 함수는 연결이 종료되는 시점에 호출됩니다.
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CSocket::OnClose(nErrorCode);

	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	pServerSocket->CloseClientSocket(this);
}


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CString strTmp = L"";
	CString strIPAdress = L"";
	UINT uPortNumber = 0;
	TCHAR szBuffer[1024];
	::ZeroMemory(szBuffer, sizeof(szBuffer));

	GetPeerName(strIPAdress, uPortNumber);//클라이언트의 IP 주소와 포트 번호를 strIPAdress와 uPortNumber 변수에 저장합니다.
	if (Receive(szBuffer, sizeof(szBuffer)) > 0) //클라이언트로부터 정보를 수신하여 szBuffer 변수에 저장합니다. Receive() 메서드는 CAsyncSocket 클래스의 메서드이며, 클라이언트로부터 데이터를 수신할 때까지 대기합니다.
	{
		CChatServerDlg* pMain = (CChatServerDlg*)AfxGetMainWnd();//메인 윈도우의 포인터를 가져옵니다.
		pMain->strIPAdress = strIPAdress;//메인 윈도우의 멤버 변수인 strIPAdress에 클라이언트의 IP 주소를 저장합니다.
		strTmp.Format(_T("[%s:%d] : %s"), strIPAdress, uPortNumber, szBuffer); //수신한 정보를 형식에 맞게 문자열로 저장합니다.
		pMain->m_List.AddString(strTmp); //수신한 정보를 리스트 박스에 추가합니다.
		pMain->m_List.SetCurSel(pMain->m_List.GetCount() - 1); //리스트 박스의 스크롤바를 맨 아래로 내립니다.

		CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
		pServerSocket->SendChatDataAll(szBuffer);//수신한 정보를 모든 클라이언트에게 전송합니다.
		
		
		//CAsyncSocket 클래스의 OnReceive() 메서드는 클라이언트로부터 정보를 수신해야 할 때 호출됩니다.
	}
	CSocket::OnReceive(nErrorCode); //부모 클래스인 CSocket의 OnReceive() 메서드를 호출합니다.
}


void OnConnect(int nErrorCode);