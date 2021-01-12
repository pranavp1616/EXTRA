#include "Calculator.h"

CalculatorApp Object;

BEGIN_MESSAGE_MAP(CalcWindow,CFrameWnd)
	ON_WM_PAINT()
	ON_BN_CLICKED(1,OnButton1)
	ON_BN_CLICKED(2, OnButton2)
	ON_BN_CLICKED(3, OnButton3)
	ON_BN_CLICKED(4, OnButton4)
	ON_BN_CLICKED(5, OnButton5)
	ON_BN_CLICKED(6, OnButton6)
	ON_BN_CLICKED(7, OnButton7)
	ON_BN_CLICKED(8, OnButton8)
	ON_BN_CLICKED(9, OnButton9)
	ON_BN_CLICKED(10, OnButton10)

	ON_BN_CLICKED(12, OnButton12)
	ON_BN_CLICKED(13, OnButton13)
	ON_BN_CLICKED(14, OnButton14)
	ON_BN_CLICKED(15, OnButton15)
	ON_BN_CLICKED(16, OnButton16)
	ON_BN_CLICKED(17, OnButton17)

	ON_BN_CLICKED(18, OnButton18)
	ON_BN_CLICKED(19, OnButton19)
	
END_MESSAGE_MAP()

BOOL CalculatorApp::InitInstance()
{
	CalcWindow *m = new CalcWindow();
	m->ShowWindow(1);
	m->UpdateWindow();
	m_pMainWnd = m;
	return TRUE;
}

CalcWindow::CalcWindow()
{
	Create(NULL, TEXT("Calculator"), WS_OVERLAPPEDWINDOW,CRect(0,0,350,400));
	operand = 0.0;
	ans = 0.0;
	operation = 1;
	FirstCalculation = true;

	Button[0].Create(TEXT("7"), WS_VISIBLE | WS_CHILD, CRect(20, 100, 70, 150), this, 1);
	Button[1].Create(TEXT("8"), WS_VISIBLE | WS_CHILD, CRect(80, 100, 130, 150), this, 2);
	Button[2].Create(TEXT("9"), WS_VISIBLE | WS_CHILD, CRect(140, 100, 190, 150), this, 3);
	Button[3].Create(TEXT("4"), WS_VISIBLE | WS_CHILD, CRect(20, 160, 70, 210), this, 4);
	Button[4].Create(TEXT("5"), WS_VISIBLE | WS_CHILD, CRect(80, 160, 130, 210), this, 5);
	Button[5].Create(TEXT("6"), WS_VISIBLE | WS_CHILD, CRect(140, 160, 190, 210), this, 6);
	Button[6].Create(TEXT("1"), WS_VISIBLE | WS_CHILD, CRect(20, 220, 70, 270), this, 7);
	Button[7].Create(TEXT("2"), WS_VISIBLE | WS_CHILD, CRect(80, 220, 130, 270), this, 8);
	Button[8].Create(TEXT("3"), WS_VISIBLE | WS_CHILD, CRect(140, 220, 190, 270), this, 9);
	Button[9].Create(TEXT("0"), WS_VISIBLE | WS_CHILD, CRect(20, 280, 70, 330), this, 10);
	Button[11].Create(TEXT("="), WS_VISIBLE | WS_CHILD, CRect(80, 280, 190, 330), this, 12);
	Button[12].Create(TEXT("+"), WS_VISIBLE | WS_CHILD, CRect(200, 220, 250, 330), this, 13);
	Button[13].Create(TEXT("-"), WS_VISIBLE | WS_CHILD, CRect(200, 160, 250, 210), this, 14);
	Button[14].Create(TEXT("*"), WS_VISIBLE | WS_CHILD, CRect(200, 100, 250, 150), this, 15);
	Button[15].Create(TEXT("/"), WS_VISIBLE | WS_CHILD, CRect(260, 100, 310, 150), this, 16);
	Button[16].Create(TEXT("C"), WS_VISIBLE | WS_CHILD, CRect(260, 160, 310, 210), this, 17);
	Button[17].Create(TEXT("^"), WS_VISIBLE | WS_CHILD, CRect(260, 220, 310, 270), this, 18);
	Button[18].Create(TEXT("<-"), WS_VISIBLE | WS_CHILD, CRect(260, 280, 310, 330), this, 19);


	flag = TextField.Create(ES_READONLY| ES_LEFT| WS_VISIBLE, CRect(20, 20, 310, 70), this, 21);
	
}

void CalcWindow::OnPaint()
{
	text_size = wsprintf(text, TEXT("%i : %i"), (int)ans, (int)operand);
	CDC* dc = GetDC();
	dc->TextOut(100, 0, text, text_size);
	ReleaseDC(dc);
}

void CalcWindow::OnButton1()  // 7
{
	operand = operand * 10.0 + 7.0;
	text_size = wsprintf(text, TEXT("%d"),(int)operand);
	TextField.SetWindowText(text);
	this->UpdateWindow();
}

void CalcWindow::OnButton2() // 8
{
	operand = operand * 10.0 + 8.0;
	text_size = wsprintf(text, TEXT("%d"), (int)operand);
	TextField.SetWindowText(text);
	this->UpdateWindow();
}

void CalcWindow::OnButton3() // 9
{
	operand = operand * 10.0 + 9.0;
	text_size = wsprintf(text, TEXT("%d"), (int)operand);
	TextField.SetWindowText(text);
	this->UpdateWindow();

}
void CalcWindow::OnButton4()  // 4
{
	operand = operand * 10.0 + 4.0;
	text_size = wsprintf(text, TEXT("%d"), (int)operand);
	TextField.SetWindowText(text);
	this->UpdateWindow();

}
void CalcWindow::OnButton5()  // 5
{
	operand = operand * 10.0 + 5.0;
	text_size = wsprintf(text, TEXT("%d"), (int)operand);
	TextField.SetWindowText(text);
	this->UpdateWindow();

}
void CalcWindow::OnButton6() // 6
{
	operand = operand * 10.0 + 6.0;
	text_size = wsprintf(text, TEXT("%d"), (int)operand);
	TextField.SetWindowText(text);
	this->UpdateWindow();

}
void CalcWindow::OnButton7() // 1
{
	operand = operand * 10.0 + 1.0;
	text_size = wsprintf(text, TEXT("%d"), (int)operand);
	TextField.SetWindowText(text);
	this->UpdateWindow();

}
void CalcWindow::OnButton8() // 2
{
	operand = operand * 10.0 + 2.0;
	text_size = wsprintf(text, TEXT("%d"), (int)operand);
	TextField.SetWindowText(text);
	this->UpdateWindow();

}
void CalcWindow::OnButton9()  // 3
{
	operand = operand * 10.0 + 3.0;
	text_size = wsprintf(text, TEXT("%d"), (int)operand);
	TextField.SetWindowText(text);
	this->UpdateWindow();

}
void CalcWindow::OnButton10() // 0
{
	operand = operand * 10.0 + 0.0;
	text_size = wsprintf(text, TEXT("%d"), (int)operand);
	TextField.SetWindowText(text);
	this->UpdateWindow();

}

void CalcWindow::OnButton12() // =
{
	this->Calculate();
	text_size = wsprintf(text, TEXT("%i"),(int) ans);
	TextField.SetWindowText(text);
	this->UpdateWindow();
}
void CalcWindow::OnButton13() // +
{
	operation = 1;
	this->Calculate();
	text_size = wsprintf(text, TEXT("%i"),ans);
	TextField.SetWindowText(text);
	this->UpdateWindow();

}

void CalcWindow::OnButton14() // -
{
	operation = 2;
	this->Calculate();
	text_size = wsprintf(text, TEXT("%i"), ans);
	TextField.SetWindowText(text);
	this->UpdateWindow();
}
void CalcWindow::OnButton15() // *
{
	operation = 3;
	this->Calculate();
	text_size = wsprintf(text, TEXT("%i"), ans);
	TextField.SetWindowText(text);
	this->UpdateWindow();
}
void CalcWindow::OnButton16() // /
{
	operation = 4;
	this->Calculate();
	text_size = wsprintf(text, TEXT("%i"),ans);
	TextField.SetWindowText(text);
	this->UpdateWindow();
}
void CalcWindow::OnButton17() // C clear
{
	operand = 0;
	ans = 0;
	FirstCalculation = true;	
	text_size = wsprintf(text, TEXT("%i"), (int)ans);
	TextField.SetWindowText(text);
	this->UpdateWindow();
}

void CalcWindow::OnButton18() // ^
{

	operation = 6;
	this->Calculate();
	text_size = wsprintf(text, TEXT("%i"), (int)ans);
	TextField.SetWindowText(text);
}

void CalcWindow::OnButton19() // backspace   <-
{
	TCHAR text[MAX];
	operand = operand / 10;
	text_size = wsprintf(text, TEXT("%d"), operand);
	TextField.SetWindowText(text);
	this->UpdateWindow();
}
void CalcWindow::Calculate()
{
	if (FirstCalculation == true)
	{
		ans = operand;
		operand = 0;
		FirstCalculation = false;
	}
	else
	{
		//if (operand != 0)
		{
			if (operation == 1) // +
			{
				ans = ans + operand;
				operand = 0;
			}
			else if (operation == 2) // -
			{
				ans = ans - operand;
				operand = 0;
			}
			else if (operation == 3) // *
			{
				if (operand == 0)
					operand = 1;
				ans = ans * operand;
				operand = 0;
			}
			else if (operation == 4) // /
			{
				if (operand == 0)
					operand = 1;
				ans = ans / operand;
				operand = 0;
			}
			else if (operation == 6) // ^
			{
				int n = operand;
				int s = 1;
				for (int i = 1; i <= n; i++)
					s = ans * s;
				ans = s;
			}
			
		}

	}
}
