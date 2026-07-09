#pragma once
#include "CommonInclude.h"
#include <memory>
#include <string>
#include <random>
#include "input.h"

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

			if (Input::GetKey(eKeyCode::D))
			{
				mX += 0.01f;
			}

			if (Input::GetKey(eKeyCode::A))
			{
				mX -= 0.01;
			}

			if (Input::GetKey(eKeyCode::W))
			{
				mY -= 0.01f;
			}

			if (Input::GetKey(eKeyCode::S))
			{
				mY += 0.01f;
			}
		}
	};

	class ArrowInput : public InputState {
	public:
		ArrowInput() {};

		void HandleInput(float& mX, float& mY) {

			if (Input::GetKey(eKeyCode::Left))
			{
				mX -= 0.01f;
			}

			if (Input::GetKey(eKeyCode::Right))
			{
				mX += 0.01f;
			}

			if (Input::GetKey(eKeyCode::Up))
			{
				mY -= 0.01f;
			}

			if (Input::GetKey(eKeyCode::Down))
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

