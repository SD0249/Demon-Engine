#pragma once
#include "CommonInclude.h"
#include <memory>
#include <random>
#include "Demon_Input.h"
#include "Demon_Time.h"

namespace Demon
{
	// Forward Declaration needed to used below input system
	class GameObject;

	//---------------------------------------------------------------
	// Different Input Implementation for Game Object Instances (Strategy Pattern - just implements the same behavior in different ways)
	// ** Not State pattern (doesn't have internal state changes(and hence the behavior changes))
	//---------------------------------------------------------------
	
	// Base Class
	class InputState {
	public:
		virtual void HandleInput(float& mX, float& mY, const float speed) = 0;	// '= 0' Pure Specifier - Used to declare a Pure Virtual Function
		virtual ~InputState() = default;
	};

	// Implementation of Base class
	class WASDInput : public InputState {
	public:
		WASDInput() {};

		void HandleInput(float& mX, float& mY, const float speed) {

			if (Input::GetKey(eKeyCode::D))
			{
				mX += speed * Time::DeltaTime();
			}

			if (Input::GetKey(eKeyCode::A))
			{
				mX -= speed * Time::DeltaTime();
			}

			if (Input::GetKey(eKeyCode::W))
			{
				mY -= speed * Time::DeltaTime();
			}

			if (Input::GetKey(eKeyCode::S))
			{
				mY += speed * Time::DeltaTime();
			}
		}
	};

	class ArrowInput : public InputState {
	public:
		ArrowInput() {};

		void HandleInput(float& mX, float& mY, const float speed) {

			if (Input::GetKey(eKeyCode::Left))
			{
				mX -= speed * Time::DeltaTime();
			}

			if (Input::GetKey(eKeyCode::Right))
			{
				mX += speed * Time::DeltaTime();
			}

			if (Input::GetKey(eKeyCode::Up))
			{
				mY -= speed * Time::DeltaTime();
			}

			if (Input::GetKey(eKeyCode::Down))
			{
				mY += speed * Time::DeltaTime();
			}
		}
	};

	// ** ACTOR
	// Game Object Class Definition
	class GameObject {

	public:
		// Constructor and Destructor
		GameObject(std::unique_ptr<InputState> inputState = std::make_unique<WASDInput>(),	// Default: WASD Input
				   COLORREF color = RGB(rand() % 256, rand() % 256, rand() % 256),			// Default: Random Color
				   std::string shape = "Rectangle");										// Default: Rectangle
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

