#pragma once
#include "../DemonEngine_SOURCE/Demon_GameObject.h"
#include "../DemonEngine_SOURCE/Demon_Transform.h"

namespace Demon {
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}


