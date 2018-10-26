#pragma once


// DropboxInfo dialog

class DropboxInfo : public CDialogEx
{
	DECLARE_DYNAMIC(DropboxInfo)

public:
	DropboxInfo(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DropboxInfo();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DROPBOX_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonGetToken();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
