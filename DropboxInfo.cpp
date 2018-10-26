// DropboxInfo.cpp : implementation file
//

#include "stdafx.h"
#include "CP_Main.h"
#include "DropboxInfo.h"
#include "afxdialogex.h"
#include "DropboxRestClient.h"


// DropboxInfo dialog

IMPLEMENT_DYNAMIC(DropboxInfo, CDialogEx)

DropboxInfo::DropboxInfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DROPBOX_INFO, pParent)
{
}

DropboxInfo::~DropboxInfo()
{
}

void DropboxInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(DropboxInfo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_GET_TOKEN, &DropboxInfo::OnBnClickedButtonGetToken)
	ON_BN_CLICKED(IDOK, &DropboxInfo::OnBnClickedOk)
END_MESSAGE_MAP()

void DropboxInfo::OnBnClickedButtonGetToken()
{
	DropboxRestClient::Authenticate();	
}

void DropboxInfo::OnBnClickedOk()
{
	CString cs;
	GetDlgItem(IDC_EDIT_TOKEN)->GetWindowText(cs);
	CGetSetOptions::SetDropboxToken(cs);

	GetDlgItem(IDC_EDIT_EMAIL)->GetWindowText(cs);
	CGetSetOptions::SetDropboxEmail(cs);

	GetDlgItem(IDC_EDIT_NAME)->GetWindowText(cs);
	CGetSetOptions::SetDropboxName(cs);
	
	CDialogEx::OnOK();
}

BOOL DropboxInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	GetDlgItem(IDC_EDIT_TOKEN)->SetWindowText(CGetSetOptions::GetDropboxToken());
	GetDlgItem(IDC_EDIT_EMAIL)->SetWindowText(CGetSetOptions::GetDropboxEmail());
	GetDlgItem(IDC_EDIT_NAME)->SetWindowText(CGetSetOptions::GetDropboxName());

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
