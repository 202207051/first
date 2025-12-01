#pragma once 

#include "resource.h"

typedef struct tagDRAWINFO
{
    int iShapeFlag;
    int iPenWidth;
    COLORREF crPenColor;
    COLORREF crBrushColor;
    int x1, y1;
    int x2, y2;
}DRAWINFO, * LPDRAWINFO;

#define WM_DRAW_SHAPE (WM_USER + 100)

#define CHILD_WINDOW_CLASS L"child"