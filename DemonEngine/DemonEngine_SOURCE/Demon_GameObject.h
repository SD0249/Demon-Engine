#pragma once
#include "CommonInclude.h"

namespace Demon
{
	// Actor
	class GameObject {

	public:
		// Constructor and Destructor
		GameObject();
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
	};

};

