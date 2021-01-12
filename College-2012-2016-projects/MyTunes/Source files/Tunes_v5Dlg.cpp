
// Tunes_v5Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Tunes_v5.h"
#include "Tunes_v5Dlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTunes_v5Dlg dialog



CTunes_v5Dlg::CTunes_v5Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTunes_v5Dlg::IDD, pParent)
	, SongSelectedLB(_T(""))
	, CurrentSongTextFieldVar(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTunes_v5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, SeekBar);
	DDX_Control(pDX, IDC_SLIDER2, VolumeSlider);
	DDX_Control(pDX, IDC_LIST1, SongsLB);
	DDX_LBString(pDX, IDC_LIST1, SongSelectedLB);
	DDX_Text(pDX, IDC_EDIT1, CurrentSongTextFieldVar);
}

BEGIN_MESSAGE_MAP(CTunes_v5Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, &CTunes_v5Dlg::OnNMReleasedcaptureSlider1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTunes_v5Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CTunes_v5Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CTunes_v5Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTunes_v5Dlg::OnBnClickedButton4)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER2, &CTunes_v5Dlg::OnNMReleasedcaptureSlider2)
	ON_BN_CLICKED(IDC_BUTTON5, &CTunes_v5Dlg::OnBnClickedButton5)
	ON_LBN_DBLCLK(IDC_LIST1, &CTunes_v5Dlg::OnLbnDblclkList1)

END_MESSAGE_MAP()


// CTunes_v5Dlg message handlers

BOOL CTunes_v5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	stream = 0;
	BASS_Init(-1, 44100, 0, 0, NULL);
	SeekBar.SetRange(0, 100,0);
	VolumeSlider.SetRange(0, 100, 0);
	StartThread = false;
	AfxBeginThread(ThreadProc, this);
	pause = false;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTunes_v5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTunes_v5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTunes_v5Dlg::OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	long NewPos = SeekBar.GetPos();
	// SeekBar Position change
	this->SeekPositionStart = NewPos;

	// Song change according to seek position
	long total = BASS_ChannelGetLength(stream, BASS_POS_BYTE);
	BASS_ChannelSetPosition(stream,(total*NewPos) / 100.0,BASS_POS_BYTE);
	

}


UINT ThreadProc(LPVOID p)
{
	CTunes_v5Dlg* AppObject = (CTunes_v5Dlg*)p;
	while (true)
	{
		if (AppObject->SeekPositionStart <= AppObject->SeekBar.GetRangeMax() && AppObject->StartThread == true)
		{
			AppObject->SeekBar.SetPos(AppObject->SeekPositionStart++);
			Sleep(AppObject->SleepTime);
		}
		if (AppObject->SeekPositionStart == 100.0)
		{
			BASS_ChannelStop(AppObject->stream);
			AppObject->stream = 0;
		}
	}
	return 0;
}


void CTunes_v5Dlg::OnBnClickedButton2()  // Browse Button
{
	CFileDialog FileDialog(true);

	if (FileDialog.DoModal() == IDOK)
	{
		SongPath = FileDialog.GetPathName();
		UpdateList(SongPath);
	}
}



void CTunes_v5Dlg::OnBnClickedButton1()
{
	PlaySong();
}
void CTunes_v5Dlg::PlaySong()
{
	if (pause == false) // start from begining
	{
		stream = BASS_StreamCreateFile(false, CurrentSongItr->GetString(), 0l, 0l, BASS_SAMPLE_LOOP);
		SeekPositionStart = 0;
		StartThread = true;
		SleepTime = CalculateSleepTime();
		BASS_ChannelPlay(stream, false);
	}
	else // was paused , so continue
	{
		BASS_ChannelPlay(stream, false);
		StartThread = true;
		pause = false;
	}
}
float CTunes_v5Dlg::CalculateSleepTime()
{
	long totalBytes = BASS_ChannelGetLength(stream, BASS_POS_BYTE);
	long toalSeconds = BASS_ChannelBytes2Seconds(stream, totalBytes);

	return (toalSeconds * 10.0); // ( totalseconds / 100) * 1000 
}


void CTunes_v5Dlg::OnBnClickedButton3() // Stop Button
{
	StopSong();
}

void CTunes_v5Dlg::StopSong()
{
	pause = false;
	BASS_ChannelStop(stream);
	stream = 0;
	StartThread = false;
	SeekPositionStart = 0;

}

void CTunes_v5Dlg::PauseSong()
{
	pause = true;
	BASS_ChannelPause(stream);
	StartThread = false;
}

void CTunes_v5Dlg::OnBnClickedButton4() // Pause Song
{
	PauseSong();
}


void CTunes_v5Dlg::OnNMReleasedcaptureSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	UpdateVolume();

}

void CTunes_v5Dlg::UpdateVolume()
{

	long NewPos = VolumeSlider.GetPos();
	BASS_SetVolume(NewPos / 100.0);
}

void CTunes_v5Dlg::UpdateList(CString NewPath)
{
	bool present=false;

	list<CString>::iterator itr = SongsList.begin(); 
	
	for (; itr != SongsList.end(); itr++)
	{
		if (itr->GetString() == NewPath)
		{
			present = true;
			break;
		}
	}
	if (present == false)
	{
		SongsList.push_back(NewPath);
		SongsLB.AddString(NewPath);
	}
	if (SongsList.size()==1)
		CurrentSongItr = SongsList.begin();

	CurrentSongTextFieldVar = CurrentSongItr->GetString();
	UpdateData(false);
}

void CTunes_v5Dlg::OnBnClickedButton5() // Next Button
{
	// TODO: Add your control notification handler code here
	StopSong();
	CurrentSongItr++;
	if (CurrentSongItr == SongsList.end())
		CurrentSongItr = SongsList.begin();
	PlaySong();

	CurrentSongTextFieldVar = CurrentSongItr->GetString();
	UpdateData(false);
}


void CTunes_v5Dlg::OnLbnDblclkList1()
{
	UpdateData(true);
	StopSong();
	list<CString>::iterator itr = SongsList.begin();
	for (; itr != SongsList.end(); itr++)
	{
		if (itr->GetString() == SongSelectedLB)
		{
			CurrentSongItr = itr;
			break;
		}
	}
	PlaySong();


	CurrentSongTextFieldVar = CurrentSongItr->GetString();
	UpdateData(false);
}


