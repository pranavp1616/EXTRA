// PAINT

#include<windows.h>
#include<string>

LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);
void MyDraw(HDC hdc,int tool,int x,int y,int width,COLORREF col);

bool flag=false;
int tool = 1;
int width = 5;
COLORREF col=RGB(0,0,0);
WNDCLASS wincl;


int WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszArgs,int nCmdShow)
{
    HWND hwnd;
    MSG messages;

    wincl.hInstance = hInstance;
    wincl.lpszClassName = TEXT("paint");
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_HREDRAW;
    wincl.hIcon =  LoadIcon(NULL,IDI_ERROR);
    wincl.hCursor = LoadCursor(NULL,IDC_HAND);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground =  (HBRUSH) COLOR_BACKGROUND;;

if(!RegisterClass(&wincl))
    {

          return 0;
    }
    hwnd = CreateWindow (
           TEXT("paint"),
           TEXT("PAINT"),
          WS_OVERLAPPEDWINDOW,
           100,
           100,
           1000,
           600,
           NULL,
           NULL,
           hInstance,
           NULL
           );

    ShowWindow (hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam)
{

    switch (msg)
    {
    case WM_SIZE:
        {

            HDC hdc = GetDC(handle);
            RECT rect;
            GetClientRect(handle,&rect);
            FillRect(hdc,&rect,WHITE_BRUSH);
            ReleaseDC(handle,hdc);
            break;
        }

        case WM_KEYUP:
        {

            HDC hdc = GetDC(handle);
            RECT rect;
            GetClientRect(handle,&rect);
            int key = LOWORD(wParam);

            if(key==27) // quit
            {
                    PostQuitMessage(WM_CLOSE);
            }
            else if(key==66) // Brush
            {
                 TextOut(hdc,110,1,TEXT("BRUSH     "),10);
                 tool = 1;
            }
            else if(key == 69)
            {
                 TextOut(hdc,110,1,TEXT("ERASOR    "),10);
                 tool = 0;
            }
            else if(key == 187) // increase width
            {
                width+=2;
            }
            else if(key ==189) // decrease width
            {
                width-=2;
                if(width<=2)
                    width=2;
            }
            else if(key==67)//clear
            {
                FillRect(hdc,&rect,WHITE_BRUSH);
            }
            ReleaseDC(handle,hdc);
            break;
        }
        case WM_LBUTTONDOWN:
            {
                flag=true;
                int x = LOWORD(lParam);
                int y = HIWORD(lParam);
                if( x>=10 && x<=30 && y>=170 && y<=180)
                {
                    col=RGB(255,0,0);
                }
                else if( x>=10 && x<=30 && y>=190 && y<=200)
                    {
                        col=RGB(0,255,0);
                    }
                else if( x>=10 && x<=30 && y>= 210 && y<=220)
                {
                    col=RGB(0,0,255);
                }
                else if( x>=10 && x<=30 && y>= 230 && y<=240)
                {
                    col=RGB(0,0,0);
                }
                break;
            }
        case WM_LBUTTONUP:
            {
                flag=false;

                break;
            }
        case WM_MOUSEMOVE:
            {

                if(flag==true)
                {
                    int x=LOWORD(lParam);
                    int y=HIWORD(lParam);
                    HDC hdc=GetDC(handle);
                    MyDraw(hdc,tool,x,y,width,col);
                    ReleaseDC(handle,hdc);
                }
                    break;
            }
        case WM_PAINT:
        {
            HDC hdc = GetDC(handle);
            TextOut(hdc,5,1,TEXT("Tool Selected"),13);
            TextOut(hdc,5,27,TEXT("TOOLBOX"),7);
            MoveToEx(hdc,5,42,NULL);
            LineTo(hdc,75,42);
            TextOut(hdc,5,45,TEXT("B-Brush"),7);
            TextOut(hdc,5,60,TEXT("E-Erasor"),8);
            TextOut(hdc,5,75,TEXT("+ IncBrush"),10);
            TextOut(hdc,5,90,TEXT("-  DecBrush"),11);
            TextOut(hdc,5,105,TEXT("C-clear"),8);
            TextOut(hdc,5,120,TEXT("Esc-Quit"),8);
            TextOut(hdc,5,140,TEXT("Color Picker"),12);
            MoveToEx(hdc,5,155,NULL);
            LineTo(hdc,75,155);
            MoveToEx(hdc,85,20,NULL);
            LineTo(hdc,950,20);
            LineTo(hdc,950,540);
            LineTo(hdc,85,540);
            LineTo(hdc,85,20);
            // COLOR PICKER
            for(int i=10;i<=30;i++)
            {
                for(int j=170; j<=180; j++)
                    SetPixel(hdc,i,j,RGB(255,0,0));
            }
            for(int i=10;i<=30;i++)
            {
                for(int j=190; j<=200; j++)
                    SetPixel(hdc,i,j,RGB(0,255,0));
            }
            for(int i=10;i<=30;i++)
            {
                for(int j=210; j<=220; j++)
                    SetPixel(hdc,i,j,RGB(0,0,255));
            }
            for(int i=10;i<=30;i++)
            {
                for(int j=230; j<=240; j++)
                    SetPixel(hdc,i,j,RGB(0,0,0));
            }
            ReleaseDC(handle,hdc);
            break;
        }
        case WM_DESTROY:
                PostQuitMessage (0);
            break;

          default:
                return DefWindowProc (handle, msg, wParam, lParam);
    }
}

void MyDraw(HDC hdc,int tool,int x,int y,int width,COLORREF col)
{
    int x_max = x+width;
    int y_max= y+width;
    if(x_max>=85 && x_max<=950 && y_max>=20 && y_max<=540)
    {   if(tool == 1) // brush
        {
            for(int i=y;i<=y_max;i++)
            {
                for(int j=x; j<=x_max; j++)
                    SetPixel(hdc,j,i,col);
            }
        }
        else if(tool ==0) // erasor
        {

            for(int i=y;i<=y_max;i++)
            {
                for(int j=x; j<=x_max; j++)
                    SetPixel(hdc,j,i,RGB(255,255,255));
            }
        }
    }
}
