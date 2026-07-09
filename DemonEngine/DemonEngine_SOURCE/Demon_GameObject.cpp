#include "Demon_GameObject.h"

namespace Demon
{
	GameObject::GameObject(std::unique_ptr<InputState> inputState, COLORREF color, std::string shape) : inputState_(std::move(inputState)), color_(color), shape_(shape)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
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

		// Exercise #1
		float& xAddress = mX;
		float& yAddress = mY;
		if (inputState_ != nullptr)
		{
			inputState_->HandleInput(xAddress, yAddress);
		}
		else
		{
			// Exercise #2
			// Can make a logic for it to bounce back when hitting the boundary but I will not lol
			// Need to retrieve window size and all to do that
			// Or this could be handled by just looping in the window
			int probablity = rand() % 100;

			if (probablity < 25)
			{
				xAddress += 0.5f;
			}
			else if (probablity < 50)
			{
				xAddress -= 0.1f;
			}
			else if (probablity < 75)
			{
				yAddress += 0.7f;
			}
			else if (probablity < 100)
			{
				yAddress -= 0.4f;
			}
		}
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		// Create color brush
		HBRUSH colorBrush = CreateSolidBrush(color_);

		// Select the color brush on DC and DON'T FORGET TO SAVE THE DEFAULT white brush (Returns Handle of previous brush)
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, colorBrush);

		// Draw a shape with the constantly updated value
		if (shape_ == "Rectangle")
		{
			Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		}
		else if (shape_ == "Circle")
		{
			Ellipse(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		}

		// Select default brush
		SelectObject(hdc, oldBrush);

		// Delete old brush -> No wasting memory
		DeleteObject(colorBrush);
	}
}

