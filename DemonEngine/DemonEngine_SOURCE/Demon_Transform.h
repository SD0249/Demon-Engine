#pragma once
#include "CommonInclude.h"
#include "Demon_Component.h"

namespace Demon {

	using namespace Demon::math;
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

		void SetPosition(Vector2 pos) { _position._x = pos._x; _position._y = pos._y; }
		Vector2 GetPosition() { return _position; }

	private:
		Vector2 _position;
	};
}


