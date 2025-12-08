#include "framework.h"
#include "test.h"
#include <stdio.h> // swprintf_s를 사용하기위함

#define MAX_LOADSTRING 100

// checkAnswer 버튼 ID 정의
#define IDM_BTN_CLICK 999

// 초기값은 4 * 4 모드
int g_currentMode = 4;

const int CELL_SIZE_4x4 = 70; // 4 * 4 모드에서 셀의 크기 정의
const int CELL_SIZE_9x9 = 40; // 9 * 9 모드에서 셀의 크기 정의
const int BOARD_START_X = 20; // 스도쿠 보드가 시작되는 x 좌표 정의
const int BOARD_START_y = 20; // 스도쿠 보드가 시작되는 y 좌표 정의

// 최대 그리드 크기 (9) 정의
#define MAX_GRID_SIZE 9

// 스도쿠 그리드 (9 * 9) 정의
typedef int SudokuGrid[MAX_GRID_SIZE][MAX_GRID_SIZE];

int selectedRow = -1; // (-1 : 선택되지 않음)
int selectedCol = -1; // (-1 : 선택되지 않음)

// 4 * 4 문제 (정답 확인 시 이제 이 배열은 사용되지 않음)
SudokuGrid initialPuzzle4x4
{
    {1, 0, 0, 3},
    {0, 4, 1, 0},
    {4, 0, 0, 1},
    {0, 1, 3, 0}
};

// 4 * 4 정답 (정답 확인 시 이제 이 배열은 사용되지 않음)
SudokuGrid solutionPuzzle4x4
{
    {1, 2, 4, 3},
    {3, 4, 1, 2},
    {4, 3, 2, 1},
    {2, 1, 3, 4}
};

// 9 * 9 문제 (정답 확인 시 이제 이 배열은 사용되지 않음)
SudokuGrid initialPuzzle9x9
{
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

// 9 * 9 정답 (정답 확인 시 이제 이 배열은 사용되지 않음)
SudokuGrid solutionPuzzle9x9
{
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
};

// 사용자의 입력값 저장
SudokuGrid currentGame;

// 현재 모드의 초기 퍼즐 복사하여 저장하는 임시 그리드
SudokuGrid g_tempInitialPuzzle;

// 현재 모드의 정답 퍼즐을 복사하여 저장하는 임시 그리드 (checkAnswer 수정으로 인해 현재는 사용되지 않음)
SudokuGrid g_tempSolutionPuzzle;

int getCurrentGridSize();          // 현재 그리드 크기값 반환 함수
int getCurrentCellSize();          // 현재 셀 크기값 반환 함수
void setGameMode(int newMode);     // 게임 모드 변경 후 게임 초기화 함수
void setButtonPosition(HWND hWnd); // checkAnswer 버튼 위치 설정 함수

// currentGame 및 임시 퍼즐 그르 초기화
void initializeGame();

// 스도쿠 규칙 검사를 위한 헬퍼 함수 추가
BOOL isSafe(SudokuGrid grid, int row, int col, int num, int size);

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

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

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TEST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEST));

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
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEST));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TEST);
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

    initializeGame();

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

// initializeGame() : 게임 데이터 초기화
void initializeGame()
{
    int size = getCurrentGridSize();

    // 현재 모드에 따라 초기 퍼즐과 정답 퍼즐 복사
    if (size == 4)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                g_tempInitialPuzzle[i][j] = initialPuzzle4x4[i][j];
                g_tempSolutionPuzzle[i][j] = solutionPuzzle4x4[i][j];

                // 현재 게임 상태를 초기 퍼즐로 설정
                currentGame[i][j] = g_tempInitialPuzzle[i][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                g_tempInitialPuzzle[i][j] = initialPuzzle9x9[i][j];
                g_tempSolutionPuzzle[i][j] = solutionPuzzle9x9[i][j];
                currentGame[i][j] = g_tempInitialPuzzle[i][j];
            }
        }
    }
}

// isSafe() : 스도쿠 규칙 맞는지 확인
BOOL isSafe(SudokuGrid grid, int row, int col, int num, int size)
{
    // 같은 행에 num이 있는지 확인 (현재 셀 제외)
    for (int i = 0; i < size; i++)
    {
        if (grid[row][i] == num && i != col)
        {
            return FALSE;
        }
    }

    // 같은 열에 num이 있는지 확인 (현재 셀 제외)
    for (int j = 0; j < size; j++)
    {
        if (grid[j][col] == num && j != row)
        {
            return FALSE;
        }
    }

    // 3. 3x3 (또는 2x2) 블록에 num이 있는지 확인 (현재 셀 제외)
    int block_size;
    if (size == 4)
    {
        block_size = 2; // 4x4 모드는 2x2 블록 사용
    }
    else // size == 9 인 경우
    {
        block_size = 3; // 9x9 모드는 3x3 블록 사용
    }

    int startRow = row - row % block_size;
    int startCol = col - col % block_size;

    for (int r = 0; r < block_size; r++)
    {
        for (int c = 0; c < block_size; c++)
        {
            if (grid[startRow + r][startCol + c] == num && (startRow + r) != row && (startCol + c) != col)
            {
                return FALSE;
            }
        }
    }

    return TRUE;
}

// checkAnswer() : 정답 확인 (스도쿠 규칙 검사 방식)
BOOL checkAnswer()
{
    int size = getCurrentGridSize();

    // 1. 모든 셀이 채워져 있는지 확인 (완성도 검사)
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (currentGame[i][j] == 0)
            {
                // 빈 칸이 남아있다면 정답이 아님
                return FALSE;
            }
        }
    }

    // 모든 채워진 숫자가 스도쿠 규칙을 만족하는지 확인 (유효성 검사)
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // 현재 셀의 숫자가 스도쿠 규칙을 위반하는지 isSafe로 확인
            // isSafe는 현재 셀의 숫자를 제외하고 규칙을 위반하는지 확인
            if (!isSafe(currentGame, i, j, currentGame[i][j], size))
            {
                // 규칙 위반 (오답)
                return FALSE;
            }
        }
    }

    // 3. 모든 셀이 채워졌고, 규칙을 만족함 (정답)
    return TRUE;
}

// 헬퍼 함수 정의
int getCurrentGridSize() // 현재 스도쿠 보드의 그리드 크기 반환
{
    return g_currentMode;
}

int getCurrentCellSize() // 현재 모드에 해당하는 개별 셀의 크기 반환
{
    if (g_currentMode == 4)
    {
        return CELL_SIZE_4x4;
    }
    else
    {
        return CELL_SIZE_9x9;
    }
}

// 게임 모드를 새로운 크기로 설정하고, 해당 모드에 맞춰 게임을 다시 시작
void setGameMode(int newMode)
{
    g_currentMode = newMode;
    initializeGame();
}

// checkAnswer 버튼 핸들
HWND g_button;

void setButtonPosition(HWND hWnd)
{
    int size = getCurrentGridSize();
    int cell = getCurrentCellSize();

    // 보드 끝 y좌표 계산
    int boardEnd_y = BOARD_START_y + size * cell;

    // 버튼 y좌표를 보드 아래 + 20 픽셀로 설정
    int button_y = boardEnd_y + 20;

    // 버튼의 위치와 크기 설정
    SetWindowPos(g_button,
        NULL,
        BOARD_START_X, // 보드와 같은 x위치
        button_y,
        200, // 버튼 너비
        40,  // 버튼 높이
        SWP_NOZORDER);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_LBUTTONDOWN:
    {
        int x = LOWORD(lParam); // 마우스 클릭 x좌표
        int y = HIWORD(lParam); // 마우스 클릭 y좌표

        int size = getCurrentGridSize();
        int cell = getCurrentCellSize();

        int boardWidth = size * cell;
        int boardHeight = size * cell;

        // 클릭 위치가 보드 영역 내에 있는지 확인
        if (x >= BOARD_START_X && x < BOARD_START_X + boardWidth &&
            y >= BOARD_START_y && y < BOARD_START_y + boardHeight)
        {
            // 클릭한 위치에 해당하는 행과 열 계산
            selectedCol = (x - BOARD_START_X) / cell;
            selectedRow = (y - BOARD_START_y) / cell;

            // 윈도우 다시 그리기
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else
        {
            // 보드 밖을 클릭시 선택 해제
            selectedCol = -1;
            selectedRow = -1;

            InvalidateRect(hWnd, NULL, TRUE);
        }
    }
    break;

    case WM_CHAR:
    {
        // 셀이 선택된 경우
        if (selectedRow != -1 && selectedCol != -1)
        {
            // 초기 퍼즐에서 값이 0인 셀만 수정 가능
            if (g_tempInitialPuzzle[selectedRow][selectedCol] == 0)
            {
                int size = getCurrentGridSize();
                int inputNum = -1;

                // 입력된 문자가 현재 모드의 유효한 숫자 법위인지 검사
                if (wParam >= '1' && wParam <= ('0' + size))
                {
                    inputNum = wParam - '0';
                }

                if (inputNum != -1)
                {
                    // 현재 게임 상태 업데이트
                    currentGame[selectedRow][selectedCol] = inputNum;
                    InvalidateRect(hWnd, NULL, TRUE);
                }
            }
        }
    }
    break;

    case WM_KEYDOWN:
    {
        // 셀이 선택된 경우
        if (selectedRow != -1 && selectedCol != -1)
        {
            // Backspace 또는 Delete 키가 눌렀는지 확인
            if (wParam == VK_BACK || wParam == VK_DELETE)
            {
                // 초기 퍼즐값이 0인 셀만 지우기
                if (g_tempInitialPuzzle[selectedRow][selectedCol] == 0)
                {
                    // 현재 셀을 0으로 설정
                    currentGame[selectedRow][selectedCol] = 0;
                    InvalidateRect(hWnd, NULL, TRUE);
                }
            }
        }
    }
    break;

    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        switch (wmId)
        {
        case IDM_BTN_CLICK:
        {
            // checkAnswer() 함수 호출
            if (checkAnswer())
            {
                MessageBox(hWnd, L"정답입니다", L"결과", MB_OK);
            }
            else
            {
                // checkAnswer()는 오답 외에 '빈 칸'이 있어도 FALSE를 반환합니다.
                MessageBox(hWnd, L"오답이거나 빈 칸이 남아있습니다", L"결과", MB_OK);
            }
        }
        break;
        case IDM_MODE_4X4:
        {
            if (g_currentMode != 4)
            {
                setGameMode(4);
                setButtonPosition(hWnd); // 버튼 위치 재설정
                InvalidateRect(hWnd, NULL, TRUE);
            }
        }
        break;
        case IDM_MODE_9X9:
        {
            if (g_currentMode != 9)
            {
                setGameMode(9);
                setButtonPosition(hWnd); // 버튼 위치 재설정
                InvalidateRect(hWnd, NULL, TRUE);
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
        // checkAnswer 버튼 생성
        g_button = CreateWindow(L"Button", L"checkAnswer", WS_CHILD | WS_VISIBLE,
            0, 0, 200, 40, hWnd, (HMENU)IDM_BTN_CLICK, hInst, NULL);
        setButtonPosition(hWnd); // 버튼 위치 초기 설정
    }
    break;
    case WM_SIZE:
    {
        setButtonPosition(hWnd); // 윈도우 크기가 변하면 버튼 위치도 다시 설정
    }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        int size = getCurrentGridSize();
        int cell = getCurrentCellSize();
        int block_size; // 스도쿠 블록 크기

        if (size == 4)
        {
            block_size = 2;
        }
        else
        {
            block_size = 3;
        }

        // 펜 생성 : 얇은 선(셀 경계) 및 굵은 선(블록 경계)
        HPEN hThinPen = CreatePen(PS_SOLID, 1, RGB(100, 100, 100));
        HPEN hThickPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));

        // 현재 DC에 얇은 펜 선택
        HPEN osPen = (HPEN)SelectObject(hdc, hThinPen);

        // 셀 및 숫자 그리기
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                // 셀의 좌표 계산
                int x1 = BOARD_START_X + j * cell;
                int y1 = BOARD_START_y + i * cell;
                int x2 = x1 + cell;
                int y2 = y1 + cell;

                // 선택된 셀 하이라이트
                if (i == selectedRow && j == selectedCol)
                {
                    HBRUSH hBrush = CreateSolidBrush(RGB(200, 200, 255)); // 선택된 셀 --> 파란색
                    RECT cellRect = { x1 + 1, y1 + 1, x2, y2 };
                    FillRect(hdc, &cellRect, hBrush);
                    DeleteObject(hBrush);
                }

                // 셀 경계선 그리기(얇은 선)
                Rectangle(hdc, x1, y1, x2, y2);

                // 셀에 숫자가 있으면 그리기
                if (currentGame[i][j] != 0)
                {
                    WCHAR buff[32];

                    // 숫자를 문자열로 변환
                    swprintf_s(buff, L"%d", currentGame[i][j]);

                    RECT rect = { x1, y1, x2, y2 };
                    SetBkMode(hdc, TRANSPARENT);

                    // 초기값 --> 검정색, 사용자값 0 --> 파란색
                    if (g_tempInitialPuzzle[i][j] != 0)
                    {
                        SetTextColor(hdc, RGB(0, 0, 0)); // 검은색
                    }
                    else
                    {
                        SetTextColor(hdc, RGB(0, 0, 255)); // 파란색
                    }

                    // 숫자 중앙 배치
                    DrawText(hdc, buff, -1, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                }
            }
        }

        // 굵은 블록 경계 선 그리기
        SelectObject(hdc, hThickPen); // 굵은 펜 선택
        int boardEnd_X = BOARD_START_X + size * cell;
        int boardEnd_Y = BOARD_START_y + size * cell;

        // block_size 간격으로 선 그림
        for (int i = 0; i <= size; i += block_size)
        {
            // 세로 선
            MoveToEx(hdc, BOARD_START_X + i * cell, BOARD_START_y, NULL);
            LineTo(hdc, BOARD_START_X + i * cell, boardEnd_Y);

            // 가로 선
            MoveToEx(hdc, BOARD_START_X, BOARD_START_y + i * cell, NULL);
            LineTo(hdc, boardEnd_X, BOARD_START_y + i * cell);
        }

        // 사용한 GDI 반환
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