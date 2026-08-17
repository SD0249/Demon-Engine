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
		// Initialize background object
		GameObject* bg = new GameObject();

		Transform* tr = bg->AddComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));
		tr->SetName(L"Transform");

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SpriteRenderer");
		sr->ImageLoad(L"../Resources/NYCbg.png");

		AddGameObject(bg);
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