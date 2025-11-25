// 1118.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "1118.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// 자식 프로세스의 PID 값 보관을 위한 변수 선언
int g_pid = 0;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
    // 인수로 전달된 PID 문자열을 숫자로 변환
    g_pid = _wtoi(lpCmdLine);
    // C / atoi() --> ASCII to Integer   
    // // C++ wtoi() --> Wchar to Integer
    // 문자열로 구성되어 있는 숫자를 숫자 형태로 변환
    // 
    // WINDOW 계열 우리 예제 프로그램
    // g_pid == 0 이면 : 부모
    // g_pid != 0 이면 : 자식
    // 
    // UNIX/LINUX 계열
    // pid = fork();
    // if( pid == 0 ) ==> 자식
    // if( pid != 0) ==> 부모

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY1118, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY1118));

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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY1118));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY1118);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
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

PROCESS_INFORMATION pi;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_LBUTTONDOWN:
    {
        if (g_pid != 0)
            break;

        // 프로세스 생성을 위해 필요한 자료형 선언
        STARTUPINFO si = { 0, };

        // 프로세스 생성 API
        wchar_t pName[32] = L"mspaint.exe";
        CreateProcess(NULL, pName, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

        memset(pName, 0x00, 32);
        wsprintf(pName, L"1118.exe %d", pi.dwProcessId);
        CreateProcess(NULL, pName, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
    }
        break;
    case WM_RBUTTONDOWN:
    {
        if (g_pid == 0)
            break;

        // 자식 프로세스가 알고 있는 정보 : PID only
        // 프로세스 종료시 필요한 자료형 : HADNLE
        // PID로 프로세스의 HANDLE을 얻는 API

        HANDLE h = OpenProcess(PROCESS_ALL_ACCESS, FALSE, g_pid);

        TerminateProcess(h, 0);
        // 자식 스레드의 제어 : 일시 정지
        //SuspendThread(pi.hThread);

        /*
        // 자식 프로세스 강제 종료
        TerminateProcess(pi.hProcess, 0);
        Sleep(1000);
        TerminateProcess(GetCurrentProcess(), 0);
        */
    }
        break;
    case WM_KEYDOWN:
    {
        // 자식 스레드의 제어 : 일시 정지된 스레드의 재개
        ResumeThread(pi.hThread);
    }
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
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
            WCHAR buf[128] = { 0, };
            wsprintf(buf, L"My Process Info : PID[ %d ] TID[ %d ]", GetCurrentProcessId(), GetCurrentThreadId());
            TextOut(hdc, 10, 10, buf, lstrlen(buf));
            // 버퍼초기화
            memset(buf, 0x00, 128);
            wsprintf(buf, L"Child Process Info : PID[ %d ] TID[ %d ]", pi.dwProcessId, pi.dwThreadId);
            TextOut(hdc, 10, 25, buf, lstrlen(buf));
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
