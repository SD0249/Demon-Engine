#include "Demon_Application.h"

namespace Demon {

	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		
		mPlayer.SetPosition(0, 0);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		// Game Object Update was handled directly here. It shouldn't!
		// Game Object by OOP should handle it's own update
		/*
		//// Retrieve the position from Game Object Member function
		//float x = mPlayer.GetPositionX();
		//float y = mPlayer.GetPositionY();

		//// Integrate changes with input
		//if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		//{
		//	x -= 0.01f;
		//}

		//if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		//{
		//	x += 0.01f;
		//}

		//if (GetAsyncKeyState(VK_UP) & 0x8000)
		//{
		//	y -= 0.01f;
		//}

		//if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		//{
		//	y += 0.01f;
		//}

		//// Put the changes back to the object position
		//mPlayer.SetPosition(x, y); */
		// Condensed like this
		mPlayer.Update();

	}

	void Application::LateUpdate()
	{

	}

	// 매 프래임, 아무 메시지가 없어도 물체를 계속 그린다 -> That's why we used Peek Message instead of Get Message
	void Application::Render()
	{
		// Even though we want the player to handle their own drawing, 
		// they don't have access for HDC, so we should pass that in as an argument
		// --> OBJECT RENDER LOGIC moved inside Object Rendering (Each object handles their own rendering)
		/*
		//// Create blue brush
		//HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		//// Select the blue brush on DC and DON'T FORGET TO SAVE THE DEFAULT white brush (Returns Handle of previous brush)
		//HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

		//// Player Position retrive after integration (Update)
		//int x = mPlayer.GetPositionX();
		//int y = mPlayer.GetPositionY();

		//// Draw a rectangle with the constantly updated value
		//Rectangle(mHdc, 100 + x, 100 + y, 200 + x, 200 + y);

		//// Select default brush
		//SelectObject(mHdc, oldBrush);

		//// Delete old brush -> No wasting memory
		//DeleteObject(blueBrush); 
		*/
		mPlayer.Render(mHdc);
	}

}
