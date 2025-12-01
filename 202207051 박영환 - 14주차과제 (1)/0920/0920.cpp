#include "framework.h"
#include "0920.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY0920, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0920));

    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0920));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY0920);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance;

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

int g_x, g_y;
int g_flag;
BOOL g_push;
int g_penWidth = 1;
COLORREF g_penColor = RGB(0, 0, 0);
COLORREF g_brushColor = RGB(255, 255, 255);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_LBUTTONDOWN:
    {
        g_x = LOWORD(lParam);
        g_y = HIWORD(lParam);
        g_push = TRUE;
    }
    break;

    case WM_LBUTTONUP:
    {
        HWND child = FindWindow(CHILD_WINDOW_CLASS, NULL);
        g_push = FALSE;

        if (0 == g_flag || g_flag == 4)
        {
            break;
        }

        int x = LOWORD(lParam);
        int y = HIWORD(lParam);

        DRAWINFO di;

        di.iShapeFlag = g_flag;
        di.iPenWidth = g_penWidth;
        di.crPenColor = g_penColor;
        di.crBrushColor = g_brushColor;
        di.x1 = g_x;
        di.y1 = g_y;
        di.x2 = x;
        di.y2 = y;

        if (child != NULL)
        {
            COPYDATASTRUCT cds;
            cds.dwData = WM_DRAW_SHAPE;
            cds.cbData = sizeof(DRAWINFO);
            cds.lpData = &di;

            SendMessage(child, WM_COPYDATA, (WPARAM)hWnd, (LPARAM)&cds);
        }
    }
    break;

    case WM_MOUSEMOVE:
    {
        if (g_push && g_flag == 4)
        {
            int current_x = LOWORD(lParam);
            int current_y = HIWORD(lParam);

            HDC hdc = GetDC(hWnd);
            HPEN hPen, hOldPen;
            hPen = CreatePen(PS_SOLID, g_penWidth, g_penColor);
            hOldPen = (HPEN)SelectObject(hdc, hPen);

            MoveToEx(hdc, g_x, g_y, NULL);
            LineTo(hdc, current_x, current_y);

            SelectObject(hdc, hOldPen);
            DeleteObject(hPen);
            ReleaseDC(hWnd, hdc);

            HWND child = FindWindow(CHILD_WINDOW_CLASS, NULL);

            DRAWINFO di;
            di.iShapeFlag = 1;
            di.iPenWidth = g_penWidth;
            di.crPenColor = g_penColor;
            di.crBrushColor = g_brushColor;
            di.x1 = g_x;
            di.y1 = g_y;
            di.x2 = current_x;
            di.y2 = current_y;

            if (child != NULL)
            {
                COPYDATASTRUCT cds;
                cds.dwData = WM_DRAW_SHAPE;
                cds.cbData = sizeof(DRAWINFO);
                cds.lpData = &di;

                SendMessage(child, WM_COPYDATA, (WPARAM)hWnd, (LPARAM)&cds);
            }

            g_x = current_x;
            g_y = current_y;
        }
    }
    break;

    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        switch (wmId)
        {
        case ID_DRAW_LINE:
            g_flag = 1;
            break;
        case ID_DRAWE_RECTANGLE:
            g_flag = 2;
            break;
        case ID_DRAW_ELLIPSE:
            g_flag = 3;
            break;
        case ID_DRAW_FREE:
            g_flag = 4;
            break;
        case ID_1px:
            g_penWidth = 1;
            break;
        case ID_5px:
            g_penWidth = 5;
            break;
        case ID_10px:
            g_penWidth = 10;
            break;
        case ID_colorRED:
            g_penColor = RGB(255, 0, 0);
            break;
        case ID_colorGreen:
            g_penColor = RGB(0, 255, 0);
            break;
        case ID_colorBlue:
            g_penColor = RGB(0, 0, 255);
            break;
        case ID_fullBlack:
            g_brushColor = RGB(0, 0, 0);
            break;
        case ID_fullWhite:
            g_brushColor = RGB(255, 255, 255);
            break;
        case ID_fullSkyred:
            g_brushColor = RGB(200, 100, 100);
            break;
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}