
// Test_GetIniDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CTest_GetIniDlg �Ի���
class CTest_GetIniDlg : public CDialogEx
{
// ����
public:
	CTest_GetIniDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TEST_GETINI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
