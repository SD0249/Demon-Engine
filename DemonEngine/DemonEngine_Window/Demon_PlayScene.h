#pragma once
#include "../DemonEngine_SOURCE/Demon_Scene.h"

namespace Demon
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		// Some of the core main loop functions are needed here too
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}


