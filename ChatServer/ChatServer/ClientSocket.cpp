// ClientSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatServer.h"
#include "ClientSocket.h"
#include "ListenSocket.h"
#include "ChatServerDlg.h"

// CClientSocket

CClientSocket::CClientSocket()
{
	m_pListenSocket = NULL; //CListenSocket Ŭ���� ��ü�� �ּҸ� �����ϴ� ��� m_pListenSocket�� �߰��ϰ� �����ڿ��� NULL�� �ʱ�ȭ�մϴ�.

 
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket ��� �Լ�
void CClientSocket::SetListenSocket(CAsyncSocket* pSocket)
{
	m_pListenSocket = pSocket;
}

void CClientSocket::OnClose(int nErrorCode) //CAsyncSocket Ŭ������ OnClose() �Լ��� ������ ����Ǵ� ������ ȣ��˴ϴ�.
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	CSocket::OnClose(nErrorCode);

	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	pServerSocket->CloseClientSocket(this);
}


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CString strTmp = L"";
	CString strIPAdress = L"";
	UINT uPortNumber = 0;
	TCHAR szBuffer[1024];
	::ZeroMemory(szBuffer, sizeof(szBuffer));

	GetPeerName(strIPAdress, uPortNumber);//Ŭ���̾�Ʈ�� IP �ּҿ� ��Ʈ ��ȣ�� strIPAdress�� uPortNumber ������ �����մϴ�.
	if (Receive(szBuffer, sizeof(szBuffer)) > 0) //Ŭ���̾�Ʈ�κ��� ������ �����Ͽ� szBuffer ������ �����մϴ�. Receive() �޼���� CAsyncSocket Ŭ������ �޼����̸�, Ŭ���̾�Ʈ�κ��� �����͸� ������ ������ ����մϴ�.
	{
		CChatServerDlg* pMain = (CChatServerDlg*)AfxGetMainWnd();//���� �������� �����͸� �����ɴϴ�.
		pMain->strIPAdress = strIPAdress;//���� �������� ��� ������ strIPAdress�� Ŭ���̾�Ʈ�� IP �ּҸ� �����մϴ�.
		strTmp.Format(_T("[%s:%d] : %s"), strIPAdress, uPortNumber, szBuffer); //������ ������ ���Ŀ� �°� ���ڿ��� �����մϴ�.
		pMain->m_List.AddString(strTmp); //������ ������ ����Ʈ �ڽ��� �߰��մϴ�.
		pMain->m_List.SetCurSel(pMain->m_List.GetCount() - 1); //����Ʈ �ڽ��� ��ũ�ѹٸ� �� �Ʒ��� �����ϴ�.

		CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
		pServerSocket->SendChatDataAll(szBuffer);//������ ������ ��� Ŭ���̾�Ʈ���� �����մϴ�.
		
		
		//CAsyncSocket Ŭ������ OnReceive() �޼���� Ŭ���̾�Ʈ�κ��� ������ �����ؾ� �� �� ȣ��˴ϴ�.
	}
	CSocket::OnReceive(nErrorCode); //�θ� Ŭ������ CSocket�� OnReceive() �޼��带 ȣ���մϴ�.
}


void OnConnect(int nErrorCode);