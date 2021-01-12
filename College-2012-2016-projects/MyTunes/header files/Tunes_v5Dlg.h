
// Tunes_v5Dlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// Additional includes

#include <bass.h>
#include <list>

using namespace std;


// CTunes_v5Dlg dialog
class CTunes_v5Dlg : public CDialogEx
{
// Construction
public:
	CTunes_v5Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TUNES_V5_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// SEEKBAR DATA
	CSliderCtrl SeekBar;
	long SeekPositionStart;
	bool StartThread;
	float SleepTime;

	// CURRENT SONG DATA
	int stream;
	CString SongPath;

	bool pause; // True means paused 
			
 
	afx_msg void OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();


	float CalculateSleepTime();
	void PlaySong();
	void StopSong();
	void PauseSong();
	void UpdateVolume();

	CSliderCtrl VolumeSlider;
	afx_msg void OnNMReleasedcaptureSlider2(NMHDR *pNMHDR, LRESULT *pResult);

	//PLalist 
	list<CString> SongsList;
	CListBox SongsLB;
	list<CString>::iterator CurrentSongItr;
	void UpdateList(CString NewPath);
	afx_msg void OnBnClickedButton5();
	afx_msg void OnLbnDblclkList1();
	CString SongSelectedLB;
	CString CurrentSongTextFieldVar;
};

UINT ThreadProc(LPVOID p);
