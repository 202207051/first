// test.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "test.h"
#include <stdio.h> // swprintf_s 사용을 위함
#include <windows.h>

#define MAX_LOADSTRING 100

// hMenu를 위한 ID값 선언
#define IDM_BTN_CLICK 999

// 스도쿠 관련 전역 상수 및 변수 선언
const int GRID_SIZE = 4;

// 셀 크기 및 모드 시작 위치
const int CELL_SIZE = 70;
const int BOARD_START_X = 20; // 현재 선택된 행(-1 : 선택되지 않음)
const int BOARD_START_Y = 20; // 현재 선택된 열(-1 : 선택되지 않음)

// SudokuGrid 자료형 선언
typedef int SudokuGrid[GRID_SIZE][GRID_SIZE];

// 게임 상태 변수
int selectedRow = -1; // 현재 행이 선택되지 않음
int selectedCol = -1; // 현재 열이 선택되지 않음

// 4 * 4 문제
SudokuGrid initalPuzzle{
    {1, 0, 0, 3},
    {0, 4, 1, 0},
    {4, 0, 0, 1},
    {0, 1, 3, 0}};

// 4 * 4 정답
SudokuGrid solutionPuzzle{
    {1, 2, 4, 3},
    {3, 4, 1, 2},
    {4, 3, 2, 1},
    {2, 1, 3, 4}};

// 플레이어가 입력한 값
SudokuGrid currentGame;

// initializeGame() 함수의 원형
void initializeGame();

// 전역 변수:
HINSTANCE hInst;                     // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];       // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING]; // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPWSTR lpCmdLine,
                      _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TEST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEST));

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
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEST));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TEST);
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

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
                              CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    // 게임 초기화 함수 선언
    initializeGame();

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

// initializeGame() 함수 선언
void initializeGame()
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
            // 4 * 4문제를 현재 게임 보드에 복사
            currentGame[i][j] = initalPuzzle[i][j];
    }
}

// 정답 확인
BOOL checkAnswer()
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            // 빈칸이나 오답일 경우
            if (currentGame[i][j] != solutionPuzzle[i][j])
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

// 정답 확인 버튼
HWND g_button;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_LBUTTONDOWN:
    {
        // 클릭된 마우스 좌표
        int x = LOWORD(lParam);
        int y = HIWORD(lParam);

        // 보드판 크기
        int boardWidth = GRID_SIZE * CELL_SIZE;
        int boardHeight = GRID_SIZE * CELL_SIZE;

        // 클릭이 보드판 영역에 있는지 확인
        if (x >= BOARD_START_X && x < BOARD_START_X + boardWidth &&
            y >= BOARD_START_Y && y < BOARD_START_Y + boardHeight)
        {
            // 픽셀 좌표를 행(Row)과 열(Col) 인덱스로 변환
            selectedCol = (x - BOARD_START_X) / CELL_SIZE;
            selectedRow = (y - BOARD_START_Y) / CELL_SIZE;

            // 창 다시 그리기
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else
        {
            // 보드판 밖의 영역 클릭 처리
            selectedCol = -1;
            selectedRow = -1;

            // 창 다시 그리기
            InvalidateRect(hWnd, NULL, TRUE);
        }
    }
    break;
    case WM_CHAR:
    {
        // 셀이 선택되었는지 확인
        if (selectedRow != -1 && selectedCol != -1)
        {
            // 선택된 칸이 질문칸인지 확인
            BOOL isQuestionCell = (initalPuzzle[selectedRow][selectedCol] != 0);

            // 문제칸 입력 처리
            if (!isQuestionCell)
            {
                int inputNum = -1;

                // 1 ~ 4 숫자값 입력 처리
                if (wParam >= '1' && wParam <= '4')
                {
                    inputNum = wParam - '0';
                }

                // 유효한 숫자(1 ~ 4)가 입력된 경우
                if (inputNum != -1)
                {
                    currentGame[selectedRow][selectedCol] = inputNum;
                    InvalidateRect(hWnd, NULL, TRUE);
                }
            }
        }
    }
    break;
    case WM_KEYDOWN:
    {
        // 지우기 처리
        if ((wParam == VK_BACK || wParam == VK_DELETE) && selectedRow != -1 && selectedCol != -1 && initalPuzzle[selectedRow][selectedCol] == 0)
        {
            currentGame[selectedRow][selectedCol] = 0;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
    }
    break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case IDM_BTN_CLICK:
        {
            // 플레이어가 입력한 값 정답확인 버튼
            if (checkAnswer())
            {
                MessageBox(hWnd, L"정답입니다", L"결과", MB_OK);
            }
            else
            {
                MessageBox(hWnd, L"오답입니다", L"결과", MB_OK);
            }
        }
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
    case WM_CREATE:
    {
        int boardEnd_Y = BOARD_START_Y + GRID_SIZE * CELL_SIZE; // 보드판 끝 y 좌표
        int button_Y = boardEnd_Y + 20;                         // 보드판 아래 20픽셀 떨어진 곳

        // 버튼 생성
        g_button = CreateWindow(L"Button", L"checkAnwer", WS_CHILD | WS_VISIBLE, BOARD_START_X, button_Y, 200, 40, hWnd, (HMENU)IDM_BTN_CLICK, hInst, NULL);
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

        // 펜 / 브러시
        HPEN hThinPen = CreatePen(PS_SOLID, 1, RGB(100, 100, 100)); // 얇은 회색선
        HPEN hThickPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));      // 두꺼운 검은색선
        HPEN osPen = (HPEN)SelectObject(hdc, hThinPen);             // 반환 펜

        // 격자 셀 및 숫자 출력
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE; j++)
            {
                int x1 = BOARD_START_X + j * CELL_SIZE;
                int y1 = BOARD_START_Y + i * CELL_SIZE;
                int x2 = x1 + CELL_SIZE;
                int y2 = y1 + CELL_SIZE;

                // 선택된 셀 강조
                if (i == selectedRow && j == selectedCol)
                {
                    HBRUSH hBrush = CreateSolidBrush(RGB(200, 200, 255));
                    RECT cellRect = {x1 + 1, y1 + 1, x2, y2};
                    FillRect(hdc, &cellRect, hBrush);
                    DeleteObject(hBrush);
                }

                // 셀 경계선 그리기(얇은 선)
                Rectangle(hdc, x1, y1, x2, y2);

                // 숫자 출력
                if (currentGame[i][j] != 0)
                {
                    WCHAR buff[32];
                    swprintf_s(buff, L"%d", currentGame[i][j]); // 숫자를 문자열로 변환

                    RECT rect = {x1, y1, x2, y2};
                    SetBkMode(hdc, TRANSPARENT); // 배경색 투명

                    // 초기 숫자값 == 검은색
                    if (initalPuzzle[i][j] != 0)
                    {
                        SetTextColor(hdc, RGB(0, 0, 0));
                    }
                    // 플레이어가 입력한 숫자값 == 파란색
                    else
                    {
                        SetTextColor(hdc, RGB(0, 0, 255));
                    }

                    // 셀 중앙에 숫자 출력
                    DrawText(hdc, buff, -1, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                }
            }
        }

        // 2 * 2 블록 강조선(굵은선)
        SelectObject(hdc, hThickPen);
        int boardEnd = BOARD_START_X + GRID_SIZE * CELL_SIZE;

        // 4 * 4 스도구 블록 강조선
        for (int i = 0; i <= GRID_SIZE; i += 2)
        {
            // 수직선
            MoveToEx(hdc, BOARD_START_X + i * CELL_SIZE, BOARD_START_Y, NULL);
            LineTo(hdc, BOARD_START_X + i * CELL_SIZE, BOARD_START_Y + GRID_SIZE * CELL_SIZE);
            // 수평선
            MoveToEx(hdc, BOARD_START_X, BOARD_START_Y + i * CELL_SIZE, NULL);
            LineTo(hdc, boardEnd, BOARD_START_Y + i * CELL_SIZE);
        }

        // 사용한 GDI 객체 반환
        SelectObject(hdc, osPen);
        DeleteObject(hThinPen);
        DeleteObject(hThickPen);

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
