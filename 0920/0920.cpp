// 0920.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "0920.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
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

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY0920, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0920));

    MSG msg;

    // 기본 메시지 루프입니다:
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



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
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

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

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

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
int x, y;
int g_x, g_y;
int g_flag;
BOOL g_push;
int g_penWidth = 1;
COLORREF g_penColor = RGB(0, 0, 0);
COLORREF g_brushColor = RGB(255, 255, 255); // 기본 면 색상 흰색

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
        g_push = FALSE;

        if (0 == g_flag || g_flag == 4)
        {
            break;
        }

        int x = LOWORD(lParam);
        int y = HIWORD(lParam);

        HDC hdc = GetDC(hWnd);

        HPEN hPen, hOldPen;
        hPen = CreatePen(PS_SOLID, g_penWidth, g_penColor);
        hOldPen = (HPEN)SelectObject(hdc, hPen);

        // 브러시 생성 및 선택
        HBRUSH hBrush, hOldBrush;
        hBrush = CreateSolidBrush(g_brushColor);
        hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

        if (1 == g_flag)
        {
            MoveToEx(hdc, g_x, g_y, NULL);
            LineTo(hdc, x, y);
        }
        else if (2 == g_flag)
        {
            Rectangle(hdc, g_x, g_y, x, y);
        }
        else if (3 == g_flag)
        {
            Ellipse(hdc, g_x, g_y, x, y);
        }

        // 브러시와 펜 복원 및 삭제
        SelectObject(hdc, hOldBrush);
        DeleteObject(hBrush);

        SelectObject(hdc, hOldPen);
        DeleteObject(hPen);

        ReleaseDC(hWnd, hdc);
    }
    break;

    case WM_MOUSEMOVE:
    {
        if (g_push && g_flag == 4)
        {
            HDC hdc = GetDC(hWnd);
            HPEN hPen, hOldPen;
            hPen = CreatePen(PS_SOLID, g_penWidth, g_penColor);
            hOldPen = (HPEN)SelectObject(hdc, hPen);

            MoveToEx(hdc, g_x, g_y, NULL);
            LineTo(hdc, LOWORD(lParam), HIWORD(lParam));
            g_x = LOWORD(lParam);
            g_y = HIWORD(lParam);

            SelectObject(hdc, hOldPen);
            DeleteObject(hPen);
            ReleaseDC(hWnd, hdc);
        }
    }
    break;

    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
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
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
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

// 정보 대화 상자의 메시지 처리기입니다.
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