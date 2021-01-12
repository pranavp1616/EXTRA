#include <afxwin.h>
#include <string>
#define MAX 100
using namespace std;

class CalculatorApp : public CWinApp
{
public:
	BOOL InitInstance();
};

class CalcWindow : public CFrameWnd
{
	
	float operand; // operand 1
	float temp; // operand 2
	int operation; 
	bool FirstCalculation;

	CButton Button[20];
	CEdit OUTPUT;

	public:

	CalcWindow();
	
	void OnPaint();

	void OnButton1();
	void OnButton2();
	void OnButton3();
	void OnButton4();
	void OnButton5();
	void OnButton6();
	void OnButton7();
	void OnButton8();
	void OnButton9();
	void OnButton10();
	void OnButton11();
	void OnButton12();
	void OnButton13();
	void OnButton14();
	void OnButton15();
	void OnButton16();
	void OnButton17();
	void OnButton18();
	void OnButton19();
	void OnButton20();

	float Calculate();
	
	DECLARE_MESSAGE_MAP()
};

