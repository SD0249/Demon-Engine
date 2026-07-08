#pragma once
#include "CommonInclude.h"
#include <memory>
#include <string>
#include <random>

namespace Demon
{
	// Forward Declaration needed to used below input system
	class GameObject;

	//---------------------------------------------------------------
	// Different Input Implementation for Game Object Instances (State Pattern)
	//---------------------------------------------------------------
	
	// Base Class
	class InputState {
	public:
		virtual void HandleInput(float& mX, float& mY) = 0;	// '= 0' Pure Specifier - Used to declare a Pure Virtual Function
		virtual ~InputState() = default;
	};

	// Implementation of Base class
	class WASDInput : public InputState {
	public:
		WASDInput() {};

		void HandleInput(float& mX, float& mY) {

			if (GetAsyncKeyState(0x44) & 0x8000)
			{
				mX += 0.01f;
			}

			if (GetAsyncKeyState(0x41) & 0x8000)
			{
				mX -= 0.01;
			}

			if (GetAsyncKeyState(0x57) & 0x8000)
			{
				mY -= 0.01f;
			}

			if (GetAsyncKeyState(0x53) & 0x8000)
			{
				mY += 0.01f;
			}
		}
	};

	class ArrowInput : public InputState {
	public:
		ArrowInput() {};

		void HandleInput(float& mX, float& mY) {

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
	};

	// ** ACTOR
	// Game Object Class Definition
	class GameObject {

	public:
		// Constructor and Destructor
		GameObject(std::unique_ptr<InputState> inputState = nullptr, COLORREF color = RGB(0, 255, 0), std::string shape = "Rectangle");
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		// Since the Position Members are private, it needs a function that makes it accessible to other classes
		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX() { return mX; }

		float GetPositionY() { return mY; }

	private:
		// Game Object's Coordinate
		float mX;
		float mY;

		// InputState Obj --> unique_ptr cannot be copied as an argument; it must be moved(std::move)
		std::unique_ptr<InputState> inputState_;

		// Color Value
		COLORREF color_;

		// Shape Data
		std::string shape_;
	};
};

