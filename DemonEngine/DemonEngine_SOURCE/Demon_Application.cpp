#include "Demon_Application.h"
#include "Input.h"
#include "DTime.h"

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
		// Render Time (testing purposes)
		DTime::Render(mHdc);

		// Even though we want the player to handle their own drawing, 
		// they don't have access for HDC, so we should pass that in as an argument
		// --> OBJECT RENDER LOGIC moved inside Object Rendering (Each object handles their own rendering)
		Player1.Render(mHdc);
		Player2.Render(mHdc);
		// Player3.Render(mHdc);
	}

}
