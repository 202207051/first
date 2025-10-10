#include "framework.h"
#include "게임과제.h"
#include <stdlib.h>
#include <time.h>

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
	LoadStringW(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY));

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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY);
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

RECT g_me, g_you1, g_you2;

BOOL g_gameover;

int g_interval = 1000;

BOOL g_cheat;

int g_my_life = 5;

RECT g_p1, g_p2, g_p3, g_p4, g_p5, g_p6;

int g_my_size = 150;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		srand(time(NULL));
		g_me.left = 10;
		g_me.top = 10;
		g_me.right = 150;
		g_me.bottom = 150;

		g_you1.left = 490;
		g_you1.top = 490;
		g_you1.right = 560;
		g_you1.bottom = 560;

		g_you2.left = 230;
		g_you2.top = 230;
		g_you2.right = 300;
		g_you2.bottom = 300;

		g_p1.left = 740; g_p1.top = 10; g_p1.right = 790; g_p1.bottom = 60;
		g_p2.left = 10; g_p2.top = 550; g_p2.right = 60; g_p2.bottom = 600;

		g_p3.left = 10; g_p3.top = 300; g_p3.right = 60; g_p3.bottom = 350;
		g_p4.left = 740; g_p4.top = 400; g_p4.right = 790; g_p4.bottom = 450;

		g_p5.left = 350; g_p5.top = 10; g_p5.right = 400; g_p5.bottom = 60;
		g_p6.left = 350; g_p6.top = 550; g_p6.right = 400; g_p6.bottom = 600;

		SetTimer(hWnd, 1, g_interval, NULL);
	}
	break;
	case WM_KEYDOWN:
	{
		const int MOVE_AMOUNT = 10;
		const int BOUNDARY_LEFT = 10;
		const int BOUNDARY_TOP = 10;
		const int BOUNDARY_RIGHT = 800;
		const int BOUNDARY_BOTTOM = 600;
		const int ME_WIDTH = g_me.right - g_me.left;
		const int ME_HEIGHT = g_me.bottom - g_me.top;

		int new_left = g_me.left;
		int new_right = g_me.right;
		int new_top = g_me.top;
		int new_bottom = g_me.bottom;

		switch (wParam)
		{
		case VK_LEFT:
		{
			new_left = g_me.left - MOVE_AMOUNT;
			new_right = g_me.right - MOVE_AMOUNT;

			if (new_left < BOUNDARY_LEFT) {
				new_left = BOUNDARY_LEFT;
				new_right = new_left + ME_WIDTH;
			}
		}
		break;
		case VK_RIGHT:
		{
			new_left = g_me.left + MOVE_AMOUNT;
			new_right = g_me.right + MOVE_AMOUNT;

			if (new_right > BOUNDARY_RIGHT) {
				new_right = BOUNDARY_RIGHT;
				new_left = new_right - ME_WIDTH;
			}
		}
		break;
		case VK_UP:
		{
			new_top = g_me.top - MOVE_AMOUNT;
			new_bottom = g_me.bottom - MOVE_AMOUNT;

			if (new_top < BOUNDARY_TOP) {
				new_top = BOUNDARY_TOP;
				new_bottom = new_top + ME_HEIGHT;
			}
		}
		break;
		case VK_DOWN:
		{
			new_top = g_me.top + MOVE_AMOUNT;
			new_bottom = g_me.bottom + MOVE_AMOUNT;

			if (new_bottom > BOUNDARY_BOTTOM) {
				new_bottom = BOUNDARY_BOTTOM;
				new_top = new_bottom - ME_HEIGHT;
			}
		}
		break;
		}

		g_me.left = new_left;
		g_me.right = new_right;
		g_me.top = new_top;
		g_me.bottom = new_bottom;

		InvalidateRect(hWnd, NULL, TRUE);
	}
	break;
	case WM_TIMER:
	{
		if (1 == wParam)
		{
			if (g_me.left < g_you1.left)
			{
				g_you1.left -= 10;
				g_you1.right -= 10;
			}
			else
			{
				g_you1.left += 10;
				g_you1.right += 10;
			}
			if (g_me.top < g_you1.top)
			{
				g_you1.top -= 10;
				g_you1.bottom -= 10;
			}
			else
			{
				g_you1.top += 10;
				g_you1.bottom += 10;
			}
			if (g_me.left < g_you2.left)
			{
				g_you2.left -= 10;
				g_you2.right -= 10;
			}
			else
			{
				g_you2.left += 10;
				g_you2.right += 10;
			}
			if (g_me.top < g_you2.top)
			{
				g_you2.top -= 10;
				g_you2.bottom -= 10;
			}
			else
			{
				g_you2.top += 10;
				g_you2.bottom += 10;
			}

			if (!g_cheat)
			{
				RECT ret;
				if (IntersectRect(&ret, &g_me, &g_you1))
				{
					g_me.left = 10;
					g_me.top = 10;
					g_me.right = 150;
					g_me.bottom = 150;

					g_you1.left = 490;
					g_you1.top = 490;
					g_you1.right = 560;
					g_you1.bottom = 560;

					g_my_life--;

					if (0 > g_my_life)
					{
						g_my_life = 0;
						KillTimer(hWnd, 1);
						g_gameover = TRUE;
						MessageBox(hWnd, L"자바써", L"게임끗", MB_OK);
					}
				}

				if (IntersectRect(&ret, &g_me, &g_you2))
				{
					g_me.left = 10;
					g_me.top = 10;
					g_me.right = 150;
					g_me.bottom = 150;

					g_you2.left = 230;
					g_you2.top = 230;
					g_you2.right = 300;
					g_you2.bottom = 300;

					g_my_life--;

					if (0 > g_my_life)
					{
						g_my_life = 0;
						KillTimer(hWnd, 1);
						g_gameover = TRUE;
						MessageBox(hWnd, L"자바써", L"게임끗", MB_OK);
					}
				}

				if (IntersectRect(&ret, &g_you1, &g_you2))
				{
					int overlap_width = ret.right - ret.left;
					int overlap_height = ret.bottom - ret.top;

					if (g_you1.left < g_you2.left) {
						g_you2.left += overlap_width;
						g_you2.right += overlap_width;
					}
					if (g_you1.top < g_you2.top) {
						g_you2.top += overlap_height;
						g_you2.bottom += overlap_height;
					}
				}

				if (IntersectRect(&ret, &g_me, &g_p1))
				{
					g_me.left = g_p2.left + 60;
					g_me.top = g_p2.top + 60;
					g_me.top = g_p2.top - g_my_size - 10;
					g_me.top = 500;

					g_me.right = g_me.left + g_my_size;
					g_me.bottom = g_me.top + g_my_size;
				}

				if (IntersectRect(&ret, &g_me, &g_p2))
				{
					g_me.left = g_p1.left + 60;
					g_me.left = g_p1.left - g_my_size - 10;
					g_me.left = 580;
					g_me.top = g_p1.top + 60;

					g_me.right = g_me.left + g_my_size;
					g_me.bottom = g_me.top + g_my_size;
				}

				if (IntersectRect(&ret, &g_me, &g_p3))
				{
					g_me.left = g_p4.left - g_my_size - 10;
					g_me.top = g_p4.top;
					g_me.right = g_me.left + g_my_size;
					g_me.bottom = g_me.top + g_my_size;
				}

				if (IntersectRect(&ret, &g_me, &g_p4))
				{
					g_me.left = g_p3.left + g_p3.right - g_p3.left + 10;
					g_me.top = g_p3.top;

					g_me.right = g_me.left + g_my_size;
					g_me.bottom = g_me.top + g_my_size;
				}

				if (IntersectRect(&ret, &g_me, &g_p5))
				{
					g_me.left = g_p6.left;
					g_me.top = g_p6.top - g_my_size - 10;
					g_me.right = g_me.left + g_my_size;
					g_me.bottom = g_me.top + g_my_size;
				}

				if (IntersectRect(&ret, &g_me, &g_p6))
				{
					g_me.left = g_p5.left;
					g_me.top = g_p5.top + g_p5.bottom - g_p5.top + 10;

					g_me.right = g_me.left + g_my_size;
					g_me.bottom = g_me.top + g_my_size;
				}
			}

			InvalidateRect(hWnd, NULL, TRUE);
		}
	}
	break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
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

		Rectangle(hdc, 10, 10, 800, 600);
		Rectangle(hdc, g_me.left, g_me.top, g_me.right, g_me.bottom);
		Ellipse(hdc, g_you1.left, g_you1.top, g_you1.right, g_you1.bottom);
		Ellipse(hdc, g_you2.left, g_you2.top, g_you2.right, g_you2.bottom);

		WCHAR buf[128] = { 0, };
		wsprintf(buf, L"남은 생명력 : %d개", g_my_life);
		TextOut(hdc, 700, 10, buf, lstrlenW(buf));

		HPEN hOldPen = (HPEN)GetStockObject(BLACK_PEN);
		HBRUSH hOldBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);

		HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HBRUSH hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
		hOldPen = (HPEN)SelectObject(hdc, hRedPen);
		hOldBrush = (HBRUSH)SelectObject(hdc, hRedBrush);
		Ellipse(hdc, g_p1.left, g_p1.top, g_p1.right, g_p1.bottom);
		Ellipse(hdc, g_p2.left, g_p2.top, g_p2.right, g_p2.bottom);
		SelectObject(hdc, hOldPen);
		SelectObject(hdc, hOldBrush);
		DeleteObject(hRedPen);
		DeleteObject(hRedBrush);

		HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
		hOldPen = (HPEN)SelectObject(hdc, hGreenPen);
		hOldBrush = (HBRUSH)SelectObject(hdc, hGreenBrush);
		Ellipse(hdc, g_p3.left, g_p3.top, g_p3.right, g_p3.bottom);
		Ellipse(hdc, g_p4.left, g_p4.top, g_p4.right, g_p4.bottom);
		SelectObject(hdc, hOldPen);
		SelectObject(hdc, hOldBrush);
		DeleteObject(hGreenPen);
		DeleteObject(hGreenBrush);

		HPEN hBluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
		hOldPen = (HPEN)SelectObject(hdc, hBluePen);
		hOldBrush = (HBRUSH)SelectObject(hdc, hBlueBrush);
		Ellipse(hdc, g_p5.left, g_p5.top, g_p5.right, g_p5.bottom);
		Ellipse(hdc, g_p6.left, g_p6.top, g_p6.right, g_p6.bottom);
		SelectObject(hdc, hOldPen);
		SelectObject(hdc, hOldBrush);
		DeleteObject(hBluePen);
		DeleteObject(hBlueBrush);

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
