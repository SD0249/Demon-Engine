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
		for (int i = 0; i < 3; i++)
		{
			GameObject* gameObj = new GameObject();

			Transform* tr = gameObj->AddComponent<Transform>();
			tr->SetPosition(rand() % 1601, rand() % 901);
			tr->SetName(L"Transform");

			SpriteRenderer* sr = gameObj->AddComponent<SpriteRenderer>();
			sr->SetName(L"SpriteRenderer");

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