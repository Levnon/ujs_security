
// NetWork_ClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "NetWork_Client.h"
#include "NetWork_ClientDlg.h"
#include "afxdialogex.h"
#include "Login.h"
#include "HelpBox.h"
#include "AboutBox.h"
#include "Linking.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern server_info s_info;
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CNetWork_ClientDlg �Ի���



CNetWork_ClientDlg::CNetWork_ClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNetWork_ClientDlg::IDD, pParent)
	, v_textmsg(_T(""))
	, u_talking(_T(""))
	, m_members(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetWork_ClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, v_textmsg);
	DDX_Text(pDX, IDC_EDIT1, u_talking);
	DDX_Text(pDX, IDC_EDIT3, m_members);
}

BEGIN_MESSAGE_MAP(CNetWork_ClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CNetWork_ClientDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CNetWork_ClientDlg::OnBnClickedOk)
	ON_WM_TIMER()
	ON_COMMAND(ID_Menu, &CNetWork_ClientDlg::OnMenu)
	ON_COMMAND(ID_32772, &CNetWork_ClientDlg::On32772)
	ON_COMMAND(ID_32773, &CNetWork_ClientDlg::On32773)
	ON_COMMAND(ID_32774, &CNetWork_ClientDlg::On32774)
	ON_BN_CLICKED(IDC_Clean, &CNetWork_ClientDlg::OnBnClickedClean)
END_MESSAGE_MAP()


// CNetWork_ClientDlg ��Ϣ�������

BOOL CNetWork_ClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetTimer(1, 1000, NULL);//���ü�ʱ��
	Connect_Server();
	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	SetDlgItemText(IDC_STATUS,L"����");

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CNetWork_ClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CNetWork_ClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CNetWork_ClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNetWork_ClientDlg::OnBnClickedCancel()
{

	// TODO: Add your control notification handler code here
	int nRet=::MessageBox(NULL, L"ȷ��Ҫ�ǳ���", L"��ʾ", MB_YESNO | MB_ICONQUESTION);
	if (nRet==IDNO)
	{
		return;
	}
	
	closesocket(sClient);
	WSACleanup();
	CDialogEx::OnCancel();
	::MessageBox(NULL, L"�ǳ��ɹ�", L"��ʾ", MB_OK | MB_ICONINFORMATION);
	CLogin ldlg;
	if (ldlg.DoModal() == IDOK)
	{
		CNetWork_ClientDlg dlg;
		//m_pMainWnd = &dlg;
		INT_PTR nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO:  �ڴ˷��ô����ʱ��
			//  ��ȷ�������رնԻ���Ĵ���
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO:  �ڴ˷��ô����ʱ��
			//  ��ȡ�������رնԻ���Ĵ���
		}
		else if (nResponse == -1)
		{
			TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
			TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
		}
	}
	else if (ldlg.DoModal() == IDCANCEL)
	{

	}
	else
	{
		
	}

	
	return;
}

DWORD WINAPI SendMsg(LPVOID p)
{
	CNetWork_ClientDlg *cdlg = (CNetWork_ClientDlg *)p;
	//CString ת char*
	
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, cdlg->v_textmsg, -1, NULL, NULL, 0, NULL);
	char *sendtext = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP, NULL, cdlg->v_textmsg, -1, sendtext, dwNum, 0, NULL);
	//
	char *Encrypt_SendText = new char[5000];//���ܺ������
	HMODULE h = LoadLibrary(L"dllcrypt.dll");//����DLL
	pFun pf = (pFun)GetProcAddress(h, "Crypt3Des");//Ѱ��DLL�еĺ���
	char key_crypt[49] ="12345678909835671097aabcffaa12345678909835671097";//��Կ
	while (strlen(sendtext) % 8)
	{
		strcat(sendtext, "\x06");
	}
	int nRe=pf(ENCRYPT, sendtext, key_crypt, Encrypt_SendText);//����
	
	if (nRe<0)
	{
		cdlg->SetDlgItemText(IDC_STATUS, L"����ʧ��");
		return 0;
	}
	cdlg->ret = send(cdlg->sClient, Encrypt_SendText, 5000, 0);//��������
	FreeLibrary(h);
		//send(cdlg->sClient, "abcasdfghjklqwertwerferwdscseweeqeqwqdcsx", 44, 0);
	//Sleep(1500);
	if (cdlg->ret == SOCKET_ERROR)
	{
		//::MessageBox(NULL, L"����ʧ�ܣ�", L"����", MB_OK | MB_ICONERROR);
		cdlg->SetDlgItemText(IDC_STATUS, L"����ʧ��");//�Ի�������ʾ����ʧ��
	}
	else
	{
		//::MessageBox(NULL, L"���ͳɹ���", L"��ʾ", MB_OK | MB_ICONINFORMATION);
		cdlg->SetDlgItemText(IDC_STATUS, L"���ͳɹ�");//�Ի�������ʾ���ͳɹ�
	}
	delete[]sendtext;
	delete[]Encrypt_SendText;
	return 0;
}

DWORD WINAPI RecvMsg(LPVOID p)
{
	CNetWork_ClientDlg *cdlg = (CNetWork_ClientDlg *)p;
	char* recvtext=new char[5000] ;
	char *com = new char[5000];
	char *Encrypt_text = new char[5000];
	HMODULE h = LoadLibrary(L"dllcrypt.dll");//����DLL
	pFun pf = (pFun)GetProcAddress(h, "Crypt3Des");//Ѱ��DLL�еĺ���
	char key_crypt[49] = "12345678909835671097aabcffaa12345678909835671097";//��Կ
	
	int i = -1;
	do 
	{
		
		i = recv(cdlg->sClient, Encrypt_text, 5000, 0);//��������
		int nRe = pf(DECRYPT, Encrypt_text, key_crypt, recvtext);//����
		if (nRe < 0)
		{
			cdlg->SetDlgItemText(IDC_STATUS, L"����ʧ��");
			return 0;
		}
		
		CString temp;
		for (int j = 0; j < strlen(recvtext);j++)
		{
			if (recvtext[j]==6)
			{
				recvtext[j] = '\0';
				break;
			}
		}
		
		/*for (int j = 0; j < strlen(recvtext);j++)
		{
			if (recvtext[j]==5)
			{
				
				recvtext[j] = 0;
				for (int k = 0; k < j;k++)
				{
					com[k] = recvtext[k];
				}
				com[j] = '\0';
				temp = com ;
				int ret_=cdlg->m_members.Find(temp);
				for (int k = j; k < strlen(recvtext); k++)
				{
					recvtext[k - j] = recvtext[k];
				}
				recvtext[strlen(recvtext) - j] = '\0';
				if (ret_ >= 0)
				{
					break;
				}
				cdlg->m_members = cdlg->m_members + temp + L"\r\n";

				
				break;
			}

		}
		*/
		temp = recvtext;
		if (temp.Find(L"[")>=0)//�����������[
		{
			goto LOOP;//��һ�����������������
		}
		else//������һ�������ǶԷ���IP�Ͷ˿ں�
		{
			int ret_ = cdlg->m_members.Find(temp);
			if (ret_ >= 0)
			{
				continue;
			}
			cdlg->m_members = cdlg->m_members + temp + L"\r\n";//�ڳ�Ա�б�����ʾ
			continue;
		}
LOOP:		for (int k = 0; k < strlen(recvtext);k++)
		{
			if (recvtext[k] < 10 && recvtext[k] >=0)
			{
				for (int l = k; l < strlen(recvtext) - 1;l++)
				{
					recvtext[l] = recvtext[l + 1];
				}
				recvtext[strlen(recvtext) - 1] = '\0';
			}
		}
		temp = recvtext;

		cdlg->u_talking = cdlg->u_talking + temp + L"\r\n";//�����촰������ʾ
		
		
		

	} 
	while (i>0);
	delete[]recvtext;
	delete[]com;
	delete[]Encrypt_text;
	FreeLibrary(h);
	
	return 0;
}




void CNetWork_ClientDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	UpdateData(TRUE);
	//v_textmsg = v_textmsg + L"\n";
	CNetWork_ClientDlg *p1 = this;
	CNetWork_ClientDlg *&q1 = p1;
	HANDLE h_recv = CreateThread(NULL, 0, RecvMsg, q1, 0, NULL);
	UpdateData(FALSE);

	CNetWork_ClientDlg *p = this;
	CNetWork_ClientDlg *&q = p;
	HANDLE h_send = CreateThread(NULL, 0, SendMsg, q, 0, NULL);
	Sleep(200);
	v_textmsg.Empty();
	UpdateData(FALSE);
	Sleep(200);
	TerminateThread(h_recv,0);
	TerminateThread(h_send,0);
	CloseHandle(h_recv);
	CloseHandle(h_send);
}


void CNetWork_ClientDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	
	

	
	
	
	
	
	
	CString strTime;
	CTime tm;
	tm = CTime::GetCurrentTime();
	strTime = tm.Format("%Y-%m-%d %H:%M:%S");
	SetDlgItemText(IDC_SHOWTIME, strTime);        //��ʾϵͳʱ��
	SetDlgItemText(IDC_EDIT1, u_talking);
	CEdit* pedit = (CEdit*)GetDlgItem(IDC_EDIT1);
	pedit->LineScroll(pedit->GetLineCount());
	SetDlgItemText(IDC_EDIT3, m_members);
	
	CDialogEx::OnTimer(nIDEvent);

	
	

	

}


void CNetWork_ClientDlg::OnMenu()
{
	// TODO: Add your command handler code here
	CDialogEx::OnCancel();
	CLogin ldlg;
	if (ldlg.DoModal() == IDOK)
	{
		CNetWork_ClientDlg dlg;
		//m_pMainWnd = &dlg;
		INT_PTR nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO:  �ڴ˷��ô����ʱ��
			//  ��ȷ�������رնԻ���Ĵ���
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO:  �ڴ˷��ô����ʱ��
			//  ��ȡ�������رնԻ���Ĵ���
		}
		else if (nResponse == -1)
		{
			TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
			TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
		}
	}
	else if (ldlg.DoModal() == IDCANCEL)
	{

	}
	else
	{

	}


	return;
}


void CNetWork_ClientDlg::On32772()
{
	
	// TODO: Add your command handler code here
	int nRe = ::MessageBox(NULL, L"ȷ���˳���", L"��ȷ��", MB_YESNO|MB_ICONWARNING);
	if (nRe==IDNO)
	{
		return;
	}
	CDialogEx::OnCancel();
	return;
}


void CNetWork_ClientDlg::On32773()
{
	// TODO: Add your command handler code here
	CHelpBox clg;
	clg.DoModal();
	return;
}


void CNetWork_ClientDlg::On32774()
{
	CAboutDlg clg;
	clg.DoModal();
	// TODO: Add your command handler code here
}
DWORD WINAPI func(LPVOID p)
{
	CLinking cdlg;
	cdlg.DoModal();
	
	return 0;
}

void CNetWork_ClientDlg::Connect_Server()
{
	HANDLE h=CreateThread(NULL, 0, func, NULL, 0, NULL);
	//WinSock��ʼ��  
	wVersionRequested = MAKEWORD(2, 2); //ϣ��ʹ�õ�WinSock DLL�İ汾  
	ret = WSAStartup(wVersionRequested, &wsaData);  //�����׽��ֿ� 
	if (ret != 0)
	{
		TerminateThread(h, 1);
		CloseHandle(h);
		TRACE(traceAppMsg, 0, "Warning:WSAStartup() failed!\n");
		::MessageBox(NULL, L"�׽��ֳ�ʼ���쳣��", L"����", MB_ICONERROR | MB_OK);
		//printf("WSAStartup() failed!\n");
		system("del a.csv");
		CDialogEx::OnCancel();
		
		return;
	}
	//ȷ��WinSock DLL֧�ְ汾2.2  
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		TerminateThread(h, 1);
		CloseHandle(h);
		WSACleanup();   //�ͷ�Ϊ�ó���������Դ����ֹ��winsock��̬���ʹ��  
		TRACE(traceAppMsg, 0, "Warning:Invalid WinSock version!\n");
		::MessageBox(NULL, L"��Ч���׽��ְ汾��", L"����", MB_ICONERROR | MB_OK);
		//printf("Invalid WinSock version!\n");
		system("del a.csv");
		CDialogEx::OnCancel();
		
		return;
	}
	sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//����socket
	if (sClient == INVALID_SOCKET)
	{
		TerminateThread(h, 1);
		CloseHandle(h);
		WSACleanup();
		TRACE(traceAppMsg, 0, "Warning:socket() failed!\n");
		::MessageBox(NULL, L"���������쳣��", L"����", MB_ICONERROR | MB_OK);
		//printf("socket() failed!\n");
		system("del a.csv");
		CDialogEx::OnCancel();
		
		return;
	}

	//sc = sClient;
	//������������ַ��Ϣ  
	saServer.sin_family = AF_INET; //��ַ����  
	saServer.sin_port = htons(s_info.port_num); //ת��Ϊ�������
	//char *ip = ;
	
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, s_info.ip_add , -1, NULL, NULL, 0, NULL);
	char *ip = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP, NULL, s_info.ip_add , -1, ip, dwNum, 0, NULL);
		//(LPSTR)(LPCTSTR)s_info.ip_add;
	saServer.sin_addr.S_un.S_addr = inet_addr(ip);
	ret = connect(sClient, (struct sockaddr *)&saServer, sizeof(saServer));
	if (ret == SOCKET_ERROR)
	{
		TerminateThread(h, 1);
		CloseHandle(h);
		TRACE(traceAppMsg, 0, "Warning:connect() failed!\n");
		::MessageBox(NULL, L"δ�����ӵ���������", L"����", MB_ICONERROR | MB_OK);
		//printf("connect() failed!\n");
		system("del a.csv");
		closesocket(sClient); //�ر��׽���  
		WSACleanup();
		CDialogEx::OnCancel();
		
		return;
	}
	//send(sClient, "abcasdfghjklqwertwerferwdscseweeqeqwqdcsx", 44, 0);
	Sleep(1500);
	TerminateThread(h, 0);
	CloseHandle(h);
	//::MessageBox(NULL, L"��½�ɹ�", L"��ʾ", MB_ICONINFORMATION | MB_OK);
	SetDlgItemText(IDC_STATUS, L"��½�ɹ�");
	CNetWork_ClientDlg *p = this;
	CNetWork_ClientDlg *&q = p;
	HANDLE hh = CreateThread(NULL, 0, RecvMsg, q, 0, NULL);
	delete[]ip;
}








void CNetWork_ClientDlg::OnBnClickedClean()
{
	u_talking.Empty();
	UpdateData(FALSE);
	return;
	// TODO: Add your control notification handler code here
}
BOOL CNetWork_ClientDlg::ReleaseRes(CString strFileName, WORD wResID, CString strFileType)
{
	// ��Դ��С  
	DWORD   dwWrite = 0;

	// �����ļ�  
	HANDLE  hFile = CreateFile(strFileName, GENERIC_WRITE, FILE_SHARE_WRITE, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	// ������Դ�ļ��С�������Դ���ڴ桢�õ���Դ��С  
	HRSRC   hrsc = FindResource(NULL, MAKEINTRESOURCE(wResID), strFileType);
	HGLOBAL hG = LoadResource(NULL, hrsc);
	DWORD   dwSize = SizeofResource(NULL, hrsc);

	// д���ļ�  
	WriteFile(hFile, hG, dwSize, &dwWrite, NULL);
	CloseHandle(hFile);
	return TRUE;
}