#include "Demon_GameObject.h"

namespace Demon
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		// Integrate changes with input
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
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
		}
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		// Create blue brush
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// Select the blue brush on DC and DON'T FORGET TO SAVE THE DEFAULT white brush (Returns Handle of previous brush)
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		// Draw a rectangle with the constantly updated value
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		// Select default brush
		SelectObject(hdc, oldBrush);

		// Delete old brush -> No wasting memory
		DeleteObject(blueBrush);
	}
}

