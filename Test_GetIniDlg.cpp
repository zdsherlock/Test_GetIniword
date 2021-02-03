
// Test_GetIniDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Test_GetIni.h"
#include "Test_GetIniDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CTest_GetIniDlg 对话框




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


// CTest_GetIniDlg 消息处理程序

BOOL CTest_GetIniDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTest_GetIniDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTest_GetIniDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTest_GetIniDlg::OnBnClickedGetPath()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	CString strPath = _T("E:\\DSuanLiangTest\\export\\ddll\\工程库\\1\\ProjectConfig.ini");
	//m_strPath.GetWindowTextW(strPath);
	CString strInfo = _T("SoftInfo");
	CString strCommandLast = _T("lastcommand");
	CString strError = _T("error");
	CString strValue;

	GetPrivateProfileString(strInfo, strCommandLast, strError, strValue.GetBuffer(MAX_PATH), MAX_PATH, strPath);

	m_strPath.SetWindowTextW(strValue);

}
