#pragma once
#include "CommonInclude.h"
#include "Demon_Component.h"

namespace Demon {
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		// * Side note: Adding override makes the parent version of the function being called optional
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(float x, float y) { X = x; Y = y; }
		float GetX() { return X; }
		float GetY() { return Y; }

	private:
		float X;
		float Y;
	};
}


