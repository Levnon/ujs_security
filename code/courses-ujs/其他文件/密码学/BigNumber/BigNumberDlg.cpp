
// BigNumberDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BigNumber.h"
#include "BigNumberDlg.h"
#include "afxdialogex.h"
#include "BigInt.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CBigNumberDlg �Ի���



CBigNumberDlg::CBigNumberDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBigNumberDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBigNumberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_a);
	DDX_Control(pDX, IDC_EDIT2, edit_b);
	DDX_Control(pDX, IDC_EDIT3, edit_result);
}

BEGIN_MESSAGE_MAP(CBigNumberDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &CBigNumberDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SUB, &CBigNumberDlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MUL, &CBigNumberDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIV, &CBigNumberDlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_MOD, &CBigNumberDlg::OnBnClickedMod)
END_MESSAGE_MAP()


// CBigNumberDlg ��Ϣ�������

BOOL CBigNumberDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CBigNumberDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBigNumberDlg::OnPaint()
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
HCURSOR CBigNumberDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBigNumberDlg::OnBnClickedAdd()
{
	// TODO: Add your control notification handler code here
	CBigInt a, b, c;
	CString str1, str2, str3;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str1);
	GetDlgItem(IDC_EDIT2)->GetWindowText(str2);
	a.Get(str1, 10);
	b.Get(str2, 10);
	c = a + b;
	c.Put(str3, 10);
	GetDlgItem(IDC_EDIT3)->SetWindowText(str3);
}


void CBigNumberDlg::OnBnClickedSub()
{
	// TODO: Add your control notification handler code here
	CBigInt a, b, c;
	CString str1, str2, str3;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str1);
	GetDlgItem(IDC_EDIT2)->GetWindowText(str2);
	a.Get(str1, 10);
	b.Get(str2, 10);
	c = a - b;
	c.Put(str3, 10);
	GetDlgItem(IDC_EDIT3)->SetWindowText(str3);
}


void CBigNumberDlg::OnBnClickedMul()
{
	// TODO: Add your control notification handler code here
	CBigInt a, b, c;
	CString str1, str2, str3;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str1);
	GetDlgItem(IDC_EDIT2)->GetWindowText(str2);
	a.Get(str1, 10);
	b.Get(str2, 10);
	c = a * b;
	c.Put(str3, 10);
	GetDlgItem(IDC_EDIT3)->SetWindowText(str3);
}


void CBigNumberDlg::OnBnClickedDiv()
{
	// TODO: Add your control notification handler code here
	CBigInt a, b, c;
	CString str1, str2, str3;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str1);
	GetDlgItem(IDC_EDIT2)->GetWindowText(str2);
	a.Get(str1, 10);
	b.Get(str2, 10);
	c = a / b;
	c.Put(str3, 10);
	GetDlgItem(IDC_EDIT3)->SetWindowText(str3);
}


void CBigNumberDlg::OnBnClickedMod()
{
	// TODO: Add your control notification handler code here
	CBigInt a, b, c;
	CString str1, str2, str3;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str1);
	GetDlgItem(IDC_EDIT2)->GetWindowText(str2);
	a.Get(str1, 10);
	b.Get(str2, 10);
	c = a % b;
	c.Put(str3, 10);
	GetDlgItem(IDC_EDIT3)->SetWindowText(str3);
}
