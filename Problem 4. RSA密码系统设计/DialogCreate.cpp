// DialogCreate.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Problem 4. RSA����ϵͳ���.h"
#include "DialogCreate.h"
#include "afxdialogex.h"


// DialogCreate �Ի���

IMPLEMENT_DYNAMIC(DialogCreate, CDialogEx)

DialogCreate::DialogCreate(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, editN(_T(""))
	, editE(_T(""))
	, editP(_T(""))
	, editQ(_T(""))
	, editD(_T(""))
	, editBitLen(_T(""))
{

}

DialogCreate::~DialogCreate()
{
}

void DialogCreate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT5, editN);
	DDX_Text(pDX, IDC_EDIT6, editE);
	DDX_Text(pDX, IDC_EDIT7, editP);
	DDX_Text(pDX, IDC_EDIT8, editQ);
	DDX_Text(pDX, IDC_EDIT9, editD);
	DDX_Text(pDX, IDC_EDIT10, editBitLen);
}


BEGIN_MESSAGE_MAP(DialogCreate, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON7, &DialogCreate::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &DialogCreate::OnBnClickedButton8)
END_MESSAGE_MAP()


// DialogCreate ��Ϣ�������


#define TEST(x) 

#define STR_MAX_LEN 12560
char strt[STR_MAX_LEN];

void DialogCreate::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	clock_t start_time, end_time;
	start_time = clock();

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	int len = _ttoi(editBitLen);
	if (len < 1) {
		AfxMessageBox(_T("λ������С��2"));
		return;
	}
loop:
	LINT p = Produce(len);
	memset(strt, 0, sizeof strt);
	p.Display(strt);
	editP = strt;

	LINT q;
	do {
		q = Produce(len);
	} while (q == p);
	memset(strt, 0, sizeof strt);
	q.Display(strt);
	editQ = strt;

	LINT N = p * q;
	memset(strt, 0, sizeof strt);
	N.Display(strt);
	editN = strt;

	LINT d, gcd, e, phiN = (p - one_l) * (q - one_l), temp;
	int count1 = 0;
	do {
		d = Produce(len * 2);
		LINT::Inv(d, phiN, gcd, e);
		if (++count1 > 2)
			goto loop;
	} while (gcd != one_l || d == e);
	memset(strt, 0, sizeof strt);
	d.Display(strt);
	editD = strt;
	LINT m, c, t;
	t = m = 0x1234;
	c = LINT::MQPower(m, e, N);
	m = LINT::MQPower(c, d, N);
	if (m != t)
		goto loop;
	memset(strt, 0, sizeof strt);
	e.Display(strt);
	editE = strt;

	UpdateData(FALSE);
	end_time = clock();

	//cout << "Running time is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;//�������ʱ��
	sprintf(strt, "%.2lf", static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000);
	AfxMessageBox(_T("���ɳɹ�����ʱ��" + (CString)strt + "ms"));
}


void DialogCreate::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	LINT p, q;
	char* charSource; //����char*
	CString cstrT;

	cstrT = editP;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	p.KeyIn(charSource, cstrT.GetLength());
	cstrT = editQ;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	q.KeyIn(charSource, cstrT.GetLength());

	LINT N = p * q;
	int len = N.val[0] * 16;
	memset(strt, 0, sizeof strt);
	N.Display(strt);
	editN = strt;

	LINT d, gcd, e, phiN = (p - one_l) * (q - one_l);
	do {
		d = Produce(len);
		LINT::Inv(d, phiN, gcd, e);
	} while (gcd != one_l || d == e);
	memset(strt, 0, sizeof strt);
	d.Display(strt);
	editD = strt;

	memset(strt, 0, sizeof strt);
	e.Display(strt);
	editE = strt;

	UpdateData(FALSE);
}
