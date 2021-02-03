
// Test_GetIniDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Test_GetIni.h"
#include "Test_GetIniDlg.h"
#include "afxdialogex.h"

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


// CTest_GetIniDlg �Ի���




CTest_GetIniDlg::CTest_GetIniDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTest_GetIniDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_GetIniDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SHOW_STRING, m_strPath);
	DDX_Control(pDX, IDC_EDIT_GETPATH, m_CEdit_Path);
}

BEGIN_MESSAGE_MAP(CTest_GetIniDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GET_PATH, &CTest_GetIniDlg::OnBnClickedGetPath)
	ON_BN_CLICKED(IDC_BUTTON_GET_APP, &CTest_GetIniDlg::OnBnClickedButtonGetApp)
END_MESSAGE_MAP()


// CTest_GetIniDlg ��Ϣ�������

BOOL CTest_GetIniDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTest_GetIniDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTest_GetIniDlg::OnPaint()
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
HCURSOR CTest_GetIniDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTest_GetIniDlg::OnBnClickedGetPath()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strPath;
	LPCTSTR strFiler = _T("ini(*.ini)|*.ini|any(*.*)|*.*||");
	
	CFileDialog dlgFileOpenIni(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,strFiler,NULL);

	if (dlgFileOpenIni.DoModal() == IDOK)
	{
		strPath = dlgFileOpenIni.GetPathName();
	}
	else
	{
		return;
	}

	m_CEdit_Path.SetWindowTextW(strPath);
}


void CTest_GetIniDlg::OnBnClickedButtonGetApp()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strPath = _T("E:\\DSuanLiangTest\\export\\ddll\\���̿�\\1\\ProjectConfig.ini");
	//m_strPath.GetWindowTextW(strPath);
	CString strInfo = _T("SoftInfo");
	CString strCommandLast = _T("lastcommand");
	CString strError = _T("error");
	CString strValue;

	GetPrivateProfileString(strInfo, strCommandLast, strError, strValue.GetBuffer(MAX_PATH), MAX_PATH, strPath);

	m_strPath.SetWindowTextW(strValue);

}
