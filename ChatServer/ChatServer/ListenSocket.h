#pragma once

// CListenSocket 명령 대상입니다.

class CListenSocket : public CAsyncSocket
{
public:
	CListenSocket();
	virtual ~CListenSocket();

	void CloseClientSocket(CSocket* pClient);
	void SendChatDataAll(TCHAR* pszMessage);

	CPtrList m_ptrClientSocketList;//CPtrList 클래스 객체를 멤버로 추가합니다.
	virtual void OnAccept(int nErrorCode);
};


