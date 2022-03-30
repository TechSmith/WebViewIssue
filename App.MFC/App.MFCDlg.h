#pragma once

class CAppMFCDlg : public CDialogEx
{
public:
   CAppMFCDlg( CWnd* pParent = nullptr );

#ifdef AFX_DESIGN_TIME
   enum { IDD = IDD_APPMFC_DIALOG };
#endif

protected:
   virtual void DoDataExchange( CDataExchange* pDX );	// DDX/DDV support

protected:
   HICON m_hIcon;

   // Generated message map functions
   virtual BOOL OnInitDialog();
   afx_msg void OnPaint();
   afx_msg HCURSOR OnQueryDragIcon();
   afx_msg void OnShowButtonClicked();
   DECLARE_MESSAGE_MAP()
};
