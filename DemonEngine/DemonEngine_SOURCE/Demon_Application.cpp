#include "Demon_Application.h"
#include "Demon_Input.h"
#include "Demon_Time.h"

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

		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeEtc();

		SceneManager::Initialize();
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
		Time::Update();
		
		// Game Object Update was handled directly here. It shouldn't!
		// Game Object by OOP should handle it's own update --> This is now handled inside each respective scenes
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		
	}

	// 매 프래임, 아무 메시지가 없어도 물체를 계속 그린다 -> That's why we used Peek Message instead of Get Message
	void Application::Render()
	{
		clearRenderTarget();

		// Render Time (testing purposes)
		Time::Render(mBackHdc);

		// Even though we want the player to handle their own drawing, 
		// they don't have access for HDC, so we should pass that in as an argument
		// --> OBJECT RENDER LOGIC moved inside Object Rendering (Each object handles their own rendering)
		// This also gets encapsulated inside each respective scenes
		SceneManager::Render(mBackHdc);

		copyRenderTarget();
		
	}

	// -----------------------------------------------------------------
	// Private in-class helper functions
	// -----------------------------------------------------------------
	void Application::clearRenderTarget() {
		// Clear 
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);
	}

	void Application::copyRenderTarget()
	{
		// *** Move things drawn on backDC's buffer to frontDC's buffer
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}


	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height) {
		RECT rectangle = { 0, 0, width, height };
		AdjustWindowRect(&rectangle, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHwnd, nullptr, 0, 0, rectangle.right - rectangle.left, rectangle.bottom - rectangle.top, 0);
		ShowWindow(mHwnd, true);
	}


	void Application::createBuffer(UINT width, UINT height) {
		// Create a Bitmap that is compatible with the window resolution
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		// DC that will point to the back buffer
		mBackHdc = CreateCompatibleDC(mHdc);

		// Delete the bitmap that was created with Back DC and assign the one we have reference to
		HBITMAP oldBitMap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitMap);
	}


	void Application::initializeEtc() {
		Input::Initialize();
		Time::Initialize();
	}
}
