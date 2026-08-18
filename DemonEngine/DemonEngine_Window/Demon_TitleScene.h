#pragma once
#include "../DemonEngine_SOURCE/Demon_Scene.h"
#include "../DemonEngine_SOURCE/Demon_SceneManager.h"

namespace Demon {
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		// Some of the core main loop functions are needed here too
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		
	};
}


