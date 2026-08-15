#include "Demon_GameObject.h"

namespace Demon
{
	GameObject::GameObject() 
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Initialize()
	{
		for (Component* comp : Components) {
			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : Components) {
			comp->Update();
		}


		// Integrate changes with input (Bitwise AND)
		/*if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}*/

		// Will be removed as components
		//// Exercise #1
		//float& xAddress = mX;
		//float& yAddress = mY;
		//const float speed = 100.0f;

		//if (inputState_ != nullptr)
		//{
		//	inputState_->HandleInput(xAddress, yAddress, speed);
		//}
		//else
		//{
		//	// Exercise #2
		//	// Can make a logic for it to bounce back when hitting the boundary but I will not lol
		//	// Need to retrieve window size and all to do that
		//	// Or this could be handled by just looping in the window
		//	int probablity = rand() % 100;

		//	if (probablity < 25)
		//	{
		//		xAddress += 0.5f * Time::DeltaTime();
		//	}
		//	else if (probablity < 50)
		//	{
		//		xAddress -= 0.1f * Time::DeltaTime();
		//	}
		//	else if (probablity < 75)
		//	{
		//		yAddress += 0.7f * Time::DeltaTime();
		//	}
		//	else if (probablity < 100)
		//	{
		//		yAddress -= 0.4f * Time::DeltaTime();
		//	}
		//}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : Components) {
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : Components) {
			comp->Render(hdc);
		}
	}
}

