// WindowsProject2.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProject2.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// --- [수정/추가] 요구사항 구현을 위한 전역 변수 ---
HWND g_hWnd;                        // 메인 윈도우 핸들
const int NUM_RECTS = 5;            // 1. 사각형 5개
int rectSizes[NUM_RECTS];           // 사각형 크기 배열
CRITICAL_SECTION g_cs;              // 7. 스레드 동기화를 위한 크리티컬 섹션
HANDLE g_hThread;                   // 7. 애니메이션 스레드 핸들
bool g_bThreadRun = true;           // 7. 스레드 실행 플래그
// ---

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// --- [추가] 7. 스레드로 구성 (요구사항 2-6 구현) ---
DWORD WINAPI AnimationThread(LPVOID lpParam)
{
    // 6. 2-5까지의 행동을 무한반복한다.
    while (g_bThreadRun)
    {
        // 2. 크기가 1씩 줄어든다
        // 3. 2의 행동을 5번 반복한다
        for (int i = 0; i < 5; i++)
        {
            if (!g_bThreadRun) break; // 종료 신호 감지

            EnterCriticalSection(&g_cs); // (동기화 시작)
            for (int j = 0; j < NUM_RECTS; j++)
            {
                rectSizes[j]--; // 크기 1 감소
            }
            LeaveCriticalSection(&g_cs); // (동기화 끝)

            InvalidateRect(g_hWnd, NULL, TRUE); // 윈도우 다시 그리기 요청
            Sleep(100); // 0.1초 대기
        }

        if (!g_bThreadRun) break; // 종료 신호 감지

        // 4. 크기를 1씩 증가한다.
        // 5. 4의 행동을 5번 증가한다. (5번 반복)
        for (int i = 0; i < 5; i++)
        {
            if (!g_bThreadRun) break; // 종료 신호 감지

            EnterCriticalSection(&g_cs); // (동기화 시작)
            for (int j = 0; j < NUM_RECTS; j++)
            {
                rectSizes[j]++; // 크기 1 증가
            }
            LeaveCriticalSection(&g_cs); // (동기화 끝)

            InvalidateRect(g_hWnd, NULL, TRUE); // 윈도우 다시 그리기 요청
            Sleep(100); // 0.1초 대기
        }
    }
    return 0;
}
// ---

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // --- [추가] 스레드 동기화 객체 초기화 ---
    InitializeCriticalSection(&g_cs);
    // ---

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT2));

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

    // --- [추가] 스레드 동기화 객체 파괴 ---
    DeleteCriticalSection(&g_cs);
    // ---

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
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT2));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT2);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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

    // [수정] 생성된 윈도우 핸들을 전역 변수 g_hWnd에 저장
    g_hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAFWndProc(HWND, UINT, WPARAM, LPARAM);
    INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

    // --- [추가] 7. 스레드로 구성 (요구사항 2-6 구현) ---
    DWORD WINAPI AnimationThread(LPVOID lpParam)
    {
        // 6. 2-5까지의 행동을 무한반복한다.
        while (g_bThreadRun)
        {
            // 2. 크기가 1씩 줄어든다
            // 3. 2의 행동을 5번 반복한다
            for (int i = 0; i < 5; i++)
            {
                if (!g_bThreadRun) break; // 종료 신호 감지

                EnterCriticalSection(&g_cs); // (동기화 시작)
                for (int j = 0; j < NUM_RECTS; j++)
                {
                    rectSizes[j]--; // 크기 1 감소
                }
                LeaveCriticalSection(&g_cs); // (동기화 끝)

                InvalidateRect(g_hWnd, NULL, TRUE); // 윈도우 다시 그리기 요청
                Sleep(100); // 0.1초 대기
            }

            if (!g_bThreadRun) break; // 종료 신호 감지

            // 4. 크기를 1씩 증가한다.
            // 5. 4의 행동을 5번 증가한다. (5번 반복)
            for (int i = 0; i < 5; i++)
            {
                if (!g_bThreadRun) break; // 종료 신호 감지

                EnterCriticalSection(&g_cs); // (동기화 시작)
                for (int j = 0; j < NUM_RECTS; j++)
                {
                    rectSizes[j]++; // 크기 1 증가
                }
                LeaveCriticalSection(&g_cs); // (동기화 끝)

                InvalidateRect(g_hWnd, NULL, TRUE); // 윈도우 다시 그리기 요청
                Sleep(100); // 0.1초 대기
            }
        }
        return 0;
    }
    // ---

    int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
        _In_opt_ HINSTANCE hPrevInstance,
        _In_ LPWSTR    lpCmdLine,
        _In_ int       nCmdShow)
    {
        UNREFERENCED_PARAMETER(hPrevInstance);
        UNREFERENCED_PARAMETER(lpCmdLine);

        // TODO: 여기에 코드를 입력합니다.

        // --- [추가] 스레드 동기화 객체 초기화 ---
        InitializeCriticalSection(&g_cs);
        // ---

        // 전역 문자열을 초기화합니다.
        LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
        LoadStringW(hInstance, IDC_WINDOWSPROJECT2, szWindowClass, MAX_LOADSTRING);
        MyRegisterClass(hInstance);

        // 애플리케이션 초기화를 수행합니다:
        if (!InitInstance(hInstance, nCmdShow))
        {
            return FALSE;
        }

        HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT2));

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

        // --- [추가] 스레드 동기화 객체 파괴 ---
        DeleteCriticalSection(&g_cs);
        // ---

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
        wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT2));
        wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT2);
        wcex.lpszClassName = szWindowClass;
        wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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

        // [수정] 생성된 윈도우 핸들을 전역 변수 g_hWnd에 저장
        g_hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

        if (!g_hWnd) // [수정] g_hWnd로 체크
        {
            return FALSE;
        }

        // --- [추가] 사각형 초기 크기 설정 ---
        for (int i = 0; i < NUM_RECTS; i++)
        {
            // 5개의 사각형이 겹쳐 보이도록 초기 크기를 다르게 설정
            rectSizes[i] = (i + 1) * 20 + 50; // 예: 70, 90, 110, 130, 150
        }
        // ---

        // --- [추가] 7. 애니메이션 스레드 생성 및 시작 ---
        g_hThread = CreateThread(NULL, 0, AnimationThread, NULL, 0, NULL);
        // ---

        ShowWindow(g_hWnd, nCmdShow); // [수정] g_hWnd 사용

        // --- [오류 수정] UpdateWindow는 인수를 하나만 받습니다. ---
        UpdateWindow(g_hWnd);
        // ---

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
    LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch (message)
        {
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
        case WM_PAINT: // [수정] 사각형 그리기 로직 추가
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            // 윈도우 클라이언트 영역의 크기를 얻어옵니다.
            RECT clientRect;
            GetClientRect(hWnd, &clientRect);
            int centerX = clientRect.right / 2;
            int centerY = clientRect.bottom / 2;

            // 스레드와 데이터 접근 동기화
            EnterCriticalSection(&g_cs); // (동기화 시작)

            // 1. 5개의 사각형을 그립니다.
            for (int i = 0; i < NUM_RECTS; i++)
            {
                int size = rectSizes[i]; // 현재 사각형의 크기 (중심으로부터의 거리)

                // 중심점(centerX, centerY) 기준으로 사각형 그리기
                Rectangle(hdc, centerX - size, centerY - size, centerX + size, centerY + size);
            }

            LeaveCriticalSection(&g_cs); // (동기화 끝)

            EndPaint(hWnd, &ps);
        }
        break;
        case WM_DESTROY: // [수정] 스레드 안전 종료 로직 추가

            // 7. 스레드 종료 처리
            g_bThreadRun = false; // 스레드 루프 종료 플래그 설정
            WaitForSingleObject(g_hThread, INFINITE); // 스레드가 끝날 때까지 대기
            CloseHandle(g_hThread); // 스레드 핸들 닫기

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
    PEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!g_hWnd) // [수정] g_hWnd로 체크
    {
        return FALSE;
    }

    // --- [추가] 사각형 초기 크기 설정 ---
    for (int i = 0; i < NUM_RECTS; i++)
    {
        // 5개의 사각형이 겹쳐 보이도록 초기 크기를 다르게 설정
        rectSizes[i] = (i + 1) * 20 + 50; // 예: 70, 90, 110, 130, 150
    }
    // ---

    // --- [추가] 7. 애니메이션 스레드 생성 및 시작 ---
    g_hThread = CreateThread(NULL, 0, AnimationThread, NULL, 0, NULL);
    // ---

    ShowWindow(g_hWnd, nCmdShow); // [수정] g_hWnd 사용

    // --- [오류 수정] UpdateWindow는 인수를 하나만 받습니다. ---
    UpdateWindow(g_hWnd);
    // ---

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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
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
    case WM_PAINT: // [수정] 사각형 그리기 로직 추가
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // 윈도우 클라이언트 영역의 크기를 얻어옵니다.
        RECT clientRect;
        GetClientRect(hWnd, &clientRect);
        int centerX = clientRect.right / 2;
        int centerY = clientRect.bottom / 2;

        // 스레드와 데이터 접근 동기화
        EnterCriticalSection(&g_cs); // (동기화 시작)

        // 1. 5개의 사각형을 그립니다.
        for (int i = 0; i < NUM_RECTS; i++)
        {
            int size = rectSizes[i]; // 현재 사각형의 크기 (중심으로부터의 거리)

            // 중심점(centerX, centerY) 기준으로 사각형 그리기
            Rectangle(hdc, centerX - size, centerY - size, centerX + size, centerY + size);
        }

        LeaveCriticalSection(&g_cs); // (동기화 끝)

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY: // [수정] 스레드 안전 종료 로직 추가

        // 7. 스레드 종료 처리
        g_bThreadRun = false; // 스레드 루프 종료 플래그 설정
        WaitForSingleObject(g_hThread, INFINITE); // 스레드가 끝날 때까지 대기
        CloseHandle(g_hThread); // 스레드 핸들 닫기

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