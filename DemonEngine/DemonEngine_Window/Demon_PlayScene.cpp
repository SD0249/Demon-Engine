#include "Demon_PlayScene.h"

namespace Demon
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		for (int i = 0; i < 100; i++)
		{
			GameObject* gameObj = new GameObject();
			gameObj->SetPosition(rand() % 1600, rand() % 900);
			AddGameObject(gameObj);
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();	// Calling the parent scene update (fully call the function) to control all gameobjects in this scene
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}