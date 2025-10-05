// Editor_Window.cpp : Defines the entry point for the application.
//

// *** How a Window is Created
// 1) Define WndClass
// 2) CreateWindow in memory
// 3) ShowWindow to display Window on the screen
// 4) Message Loop take cares of the message given from the user

// *** 3 Connected Library of Windows
// 1. Manager of Memory and Execution : KERNEL
// 2. Manager of User Interface and Window : USER
// 3. Manager of screen handling and graphics : GDI(Graphics Device Interface)
//    --> DC(Device Context): The module that stores all of the data related to drawing/printing

#include "framework.h"
#include "Editor_Window.h"

#include "..\DemonEngine_SOURCE\Demon_Application.h"

Demon::Application application;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


// Purpose: Makes a Window and prints it to the screen(Not really different to other programs)
// A Window Main function like the Main function in main.cpp
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,                 // Current Program's Instance Handle(Process ID) / Points to the current window and all of the things related to it(including its DC) [EX. Program that runs now is the Editor Window Instance]
                     _In_opt_ HINSTANCE hPrevInstance,          // Previous Program's Instance Handle. WIN32 = Always NULL
                     _In_ LPWSTR    lpCmdLine,                  // Command Line Arguments (Provides a single string containing all the arguments, 
                                                                // excluding the program's name/Speeds up the commands and lets multiple windows get inputs from each other)
                     _In_ int       nCmdShow)                   // The 'shape' of the program (default shape etc)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EDITORWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EDITORWINDOW));

    MSG msg;

    // Game Logic(Loop) is created here, taking reference of how the Main Message Loop is played out
    while (true)
    {
        // If there is message
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg); // WndProc is called here 
                DispatchMessage(&msg);
            }
        }
        // Even when there is no message, the game should still be running
        else
        {
            // Game Logic Goes here
            application.Run();
        }
    }


    // Main message loop:
    // Underlying structure -> Message Queue
    //while (GetMessage(&msg, nullptr, 0, 0))
    //{
    //    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
    //    {
    //        TranslateMessage(&msg); // WndProc is called here
    //        DispatchMessage(&msg);
    //    }
    //}

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;  // Determines the Window Style to be used
    wcex.lpfnWndProc    = WndProc;                  // Stores the function that deals with Window's Message to tackle tasks
    wcex.cbClsExtra     = 0;                        // A place reserved for Windows to use Internally
    wcex.cbWndExtra     = 0;                        // A place reserved for Windows to use Internally
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EDITORWINDOW)); // Icon to print when the window was minimalized
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);                         // The cursor that this window will use
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);                               // Determines the window's background. To be precise, determines the brush that the window will use to paint its background.
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EDITORWINDOW);                     // Determines the menu that this program will use/Made by the resource editor and combined when linked
    wcex.lpszClassName  = szWindowClass;                                          // Determines the Window Class name. Passed into CreateWindow function
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   // CreateWindow makes all of the information regarding the window inside the memory and returns a window handle of this window
   HWND hWnd = CreateWindowW(szWindowClass, // Determines the Window Class name we are going to create
                             szTitle,       // The title that will show up in the Window's title bar
                             WS_OVERLAPPEDWINDOW, // The value that determines the structure of a window. Supports various forms
                             CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, // Determines the location and the size of the Window
                             nullptr,                            // If there is a parent window, it refers to the parent window handler 
                             nullptr,                            // Determines the handle of the menu for the window to use. By default uses the one defined before in MyRegisterClass, but to override, define one here
                             hInstance,                          // This program's handle
                             nullptr);                           // The place to store things from CREATESTRUCT/Usually uses NULL value

   application.Initialize(hWnd);

   if (!hWnd)
   {
      return FALSE;
   }

   // ** hWnd: The handle of this window
   // ** nCmdShow: The way to show the window on the screen. Has various values such as SW_HIDE, SW_RESTORE, SW_SHOW, etc
   //              But what you need to do here is just to pass in the argument given from the WinMain function
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window. -> Handles Inputs! Incorporate changes
//  !!! VERY DIFFERENT PROGRAM BY PROGRAM !!!
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
// LRESULT: Pointer of the function
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
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
    case WM_PAINT: // Called once when the program starts, and doesn't draw unless user requests or sends a message 
        // 메시지 호출 시에만 화면에 그렸다 
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps); // To access to DC of this window, we need the HANDLE of this window

            // Code related to drawing is handled here by DC
            // The things on the window was drawn here, but we are aiming to move this to the render logic

            // MOVED TO RENDER LOGIC
            /*
            //// Create blue brush
            //HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

            //// Select the blue brush on DC and DON'T FORGET TO SAVE THE DEFAULT white brush (Returns Handle of previous brush)
            //HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

            //// Draw a rectangle
            //Rectangle(hdc, 100, 100, 200, 200);

            //// Select default brush
            //SelectObject(hdc, oldBrush);

            //// Delete old brush -> No wasting memory
            //DeleteObject(blueBrush);

            //// Do the same thing with pen
            //HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
            //HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
            //Ellipse(hdc, 200, 200, 300, 300);

            //SelectObject(hdc, oldPen);
            //DeleteObject(redPen);

            //// Using Stock Objects to draw / Don't need to save the default again, already there as stock object
            //HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
            //oldBrush = (HBRUSH)SelectObject(hdc, grayBrush);
            //Rectangle(hdc, 400, 400, 500, 500);
            //SelectObject(hdc, oldBrush); */
            
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    // A Logic of where player shoots the gun or moves to another place?
    // -> I.e. cutscene?
    // case WM_LBUTTONDOWN:
    // {
        // int a = 0;
    // }
    // break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
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
