#pragma once

// CListenSocket ��� ����Դϴ�.

class CListenSocket : public CAsyncSocket
{
public:
	CListenSocket();
	virtual ~CListenSocket();

	void CloseClientSocket(CSocket* pClient);
	void SendChatDataAll(TCHAR* pszMessage);

	CPtrList m_ptrClientSocketList;//CPtrList Ŭ���� ��ü�� ����� �߰��մϴ�.
	virtual void OnAccept(int nErrorCode);
};


