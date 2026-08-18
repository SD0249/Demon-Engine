#pragma once
#include "../DemonEngine_SOURCE/Demon_SceneManager.h"
#include "Demon_PlayScene.h"
#include "Demon_TitleScene.h"

namespace Demon
{
	/// <summary>
	/// Creates all scenes from program and loads the starting scene
	/// </summary>
	void LoadScenes() {
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		// SceneManager::CreateScene<EndScene>(L"PlayScene");
		// SceneManager::CreateScene<TitleScene>(L"PlayScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}