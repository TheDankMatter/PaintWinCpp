#pragma once
/****************************** Module Header ******************************\
* Module Name:	Paint_Programing.h
* Project:		Paint
* Verson: 0.1
\***************************************************************************/
#include "Resource.h"
#include <string>
#include "DrawObj.h"
// inlcude Funtions Using Paint_Programing
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    ChildWndProc(HWND, UINT, WPARAM, LPARAM);
void				AutoScroll(HWND, int, int, int, int, RECT);
RECT				GetLocalCoordinates(HWND hWnd);
void				CleanObjects(HWND);
void				SetTitle(std::string, HWND);
void				ChangeToolsSelectionState(int, HMENU);
void				ChangeColorsSelectionState(int, HMENU);
void				ChangeBGSelectionState(int, HMENU);
void				ChangeLineSelectionState(int, HMENU);
void				AutoScrollObject(HWND, const DrawObj*, int, int, RECT);
void				AutoScrollObjectResize(HWND, const DrawObj*, int, int, RECT);
void				AutoScrollObjectWhenDrawing(HWND, const DrawObj*, int, int, RECT);