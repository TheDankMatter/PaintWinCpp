// HelloWindowsDesktop.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("DesktopApp");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Paint App");

HINSTANCE hInst;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // Store instance handle in our global variable
    hInst = hInstance;

    // The parameters to CreateWindow explained:
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application does not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindow(
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        500, 100,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Paint Hello world!");
	TCHAR greeting1[] = _T("GUI /Windows example");
    switch (message)
    {
        case WM_CREATE: {
             // Add menu items
            HMENU hMenuBar = CreateMenu();
            HMENU hFile = CreateMenu();
            HMENU hEdit = CreateMenu();
            HMENU hOptions = CreateMenu();
            HMENU hShapes = CreateMenu();
            HMENU hHelp = CreateMenu();

            // Append menu items to main bar
            AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hFile, LPCWSTR(L"File"));
            AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hEdit, LPCWSTR(L"Edit"));
            AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hOptions, LPCWSTR(L"Options"));
            AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hShapes, LPCWSTR(L"Shapes"));
            AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hHelp, LPCWSTR(L"Help"));

            // Append items to "File" menu
            AppendMenu(hFile, MF_STRING, NULL, LPCWSTR(L"Save")); //Replace 'NULL' with ID_Save
            AppendMenu(hFile, MF_STRING, NULL, LPCWSTR(L"Load"));
            AppendMenu(hFile, MF_STRING, NULL, LPCWSTR(L"Exit"));

            // Append items to "Options" menu
            AppendMenu(hOptions, MF_STRING, NULL, LPCWSTR(L"Line Width"));

            // Append items to "Edit" menu
            AppendMenu(hEdit, MF_STRING, NULL, LPCWSTR(L"Clear All"));
            AppendMenu(hEdit, MF_STRING, NULL, LPCWSTR(L"Undo"));
            AppendMenu(hEdit, MF_STRING, NULL, LPCWSTR(L"Redo"));

            // Append items to "Shapes" menu
            AppendMenu(hShapes, MF_STRING, NULL, LPCWSTR(L"Line"));
            AppendMenu(hShapes, MF_STRING, NULL, LPCWSTR(L"Circle"));
            AppendMenu(hShapes, MF_STRING, NULL, LPCWSTR(L"Rectangle"));
            AppendMenu(hShapes, MF_STRING, NULL, LPCWSTR(L"Triangle"));

            AppendMenu(hHelp, MF_STRING, NULL, LPCWSTR(L"Get help"));


            SetMenu(hWnd, hMenuBar);
            break;
        }
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);

            // Here your application is laid out.
            // For this introduction, we just print out "Hello, Windows desktop!"
            // in the top left corner.
            TextOut(hdc,
                5, 5,
                greeting, _tcslen(greeting));
            TextOut(hdc,
                5, 25,
                greeting1, _tcslen(greeting1));
            
            // Draw rectangle
            Rectangle(hdc, 100, 100, 300, 300);

            // End application-specific layout section.

            EndPaint(hWnd, &ps);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
            break;
    }

    return 0;
}