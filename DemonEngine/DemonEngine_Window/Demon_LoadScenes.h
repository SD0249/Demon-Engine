#pragma once
#include "../DemonEngine_SOURCE/Demon_SceneManager.h"
#include "Demon_PlayScene.h"

namespace Demon
{
	void LoadScenes() {

		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		// SceneManager::CreateScene<EndScene>(L"PlayScene");
		// SceneManager::CreateScene<TitleScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}