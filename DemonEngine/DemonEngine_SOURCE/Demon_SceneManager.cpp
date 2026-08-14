#include "Demon_SceneManager.h"

namespace Demon
{
	// Define class static variables (allocate memory)
	std::map<std::wstring, Scene*> SceneManager::Scenes;
	Scene* SceneManager::activeScene;				

	void SceneManager::Initialize() {

	}

	void SceneManager::Update() {
		activeScene->Update();	// Only update active scene
	}

	void SceneManager::LateUpdate() {
		activeScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc) {
		activeScene->Render(hdc);
	}


}
