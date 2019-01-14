#pragma once
class ClientSocket :
	public CAsyncSocket
{
public:
	ClientSocket();
	~ClientSocket();

	void ClientSocket::OnReceive(int nErrorCode)
	{
		// Windows Socket Server Programming - client part sample code to receive data
		TCHAR buff[4096];
		CString m_strRecv;
		int nRead;
		nRead = Receive(buff, 4096);
		switch (nRead)
		{

		case 0:
			Close();
			break;
		case SOCKET_ERROR:
			if (GetLastError() != WSAEWOULDBLOCK)
			{
				AfxMessageBox("Error occurred");
				Close();
			}
			break;
		default:
			buff[nRead] = 0; //terminate the string
			CString szTemp(buff);
			m_strRecv += szTemp; // m_strRecv is a CString declared
			AfxMessageBox(m_strRecv);
			// in CMyAsyncSocket
			if (szTemp.CompareNoCase("bye") == 0) ShutDown();
		}
		CAsyncSocket::OnReceive(nErrorCode);
		// Windows Socket Programming - client part code to receive data
	}
};

