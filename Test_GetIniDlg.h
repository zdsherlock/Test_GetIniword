
// Test_GetIniDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CTest_GetIniDlg 对话框
class CTest_GetIniDlg : public CDialogEx
{
// 构造
public:
	CTest_GetIniDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TEST_GETINI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedGetPath();
	CEdit m_strPath;
	afx_msg void OnBnClickedButtonGetApp();
	CEdit m_CEdit_Path;
};
