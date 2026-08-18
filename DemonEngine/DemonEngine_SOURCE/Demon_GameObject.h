#pragma once
#include "CommonInclude.h"
#include <memory>
#include <random>
#include "Demon_Input.h"
#include "Demon_Time.h"
#include "Demon_Component.h"

namespace Demon
{
	// Forward Declaration needed to used below input system
	class GameObject;

	//---------------------------------------------------------------
	// Different Input Implementation for Game Object Instances (Strategy Pattern - just implements the same behavior in different ways)
	// ** Not State pattern (doesn't have internal state changes(and hence the behavior changes))
	// ** Needs to be refactored as a component
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
		GameObject();										
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		// Add a component to game object (Creates desired component and assigns it to object)
		template <typename T>
		T* AddComponent() {
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);			// Component also needs reference to its owner object
			Components.push_back(comp);
			return comp;
		}

		// Return this component from inner components list
		template <typename T>
		T* GetComponent() {
			T* component = nullptr;	
			for (Component* comp : Components)		// Loop through components list to find it
			{
				component = dynamic_cast<T*>(comp);	// If c doesn't have the same type as comp, it won't be assigned - stay as nullptr
				if (component)						// If assigned, break out from loop
					break;
			}

			return component;
		}


	private:
		// A game object instance holds various components to support its functionalites
		std::vector<Component*> Components;

		//---------------------------------------------------------------------------
		// These functionalities will all be swtiched to components
		// InputState Obj --> unique_ptr cannot be copied as an argument; it must be moved(std::move)
		std::unique_ptr<InputState> inputState_;

		// Color Value
		COLORREF color_;

		// Shape Data
		std::string shape_;
		//---------------------------------------------------------------------------
	};
};

