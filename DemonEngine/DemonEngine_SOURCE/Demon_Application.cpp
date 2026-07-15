#include "Demon_Application.h"
#include "Input.h"
#include "DTime.h"

namespace Demon {

	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBuffer(NULL)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		mWidth = width;
		mHeight = height;

		RECT rectangle = { 0, 0, width, height };
		AdjustWindowRect(&rectangle, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHwnd, nullptr, 0, 0, rectangle.right - rectangle.left, rectangle.bottom - rectangle.top, 0);
		ShowWindow(mHwnd, true);

		// Create a Bitmap that is compatible with the window resolution
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		// DC that will point to the back buffer
		mBackHdc = CreateCompatibleDC(mHdc);

		// Delete the bitmap that was created with Back DC and assign the one we have reference to
		HBITMAP oldBitMap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitMap);

		Input::Initialize();
		DTime::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		// Update Input
		Input::Update();

		// Update Time
		DTime::Update();
		
		// Game Object Update was handled directly here. It shouldn't!
		// Game Object by OOP should handle it's own update
		// Put the changes back to the object position
		// Condensed like this
		Player1.Update();
		Player2.Update();
		// Player3.Update();
	}

	void Application::LateUpdate()
	{

	}

	// 매 프래임, 아무 메시지가 없어도 물체를 계속 그린다 -> That's why we used Peek Message instead of Get Message
	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, mWidth, mHeight);

		// Render Time (testing purposes)
		DTime::Render(mBackHdc);

		// Even though we want the player to handle their own drawing, 
		// they don't have access for HDC, so we should pass that in as an argument
		// --> OBJECT RENDER LOGIC moved inside Object Rendering (Each object handles their own rendering)
		Player1.Render(mBackHdc);
		Player2.Render(mBackHdc);
		// Player3.Render(mHdc);

		// Move things drawn on backDC's buffer to frontDC's buffer
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}

}
