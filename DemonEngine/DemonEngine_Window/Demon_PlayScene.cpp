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
		bg = new Player();

		Transform* tr = bg->AddComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));
		tr->SetName(L"Transform");

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SpriteRenderer");
		sr->ImageLoad(L"../Resources/NYCbg.png");

		AddGameObject(bg, LayerType::BackGround);
	}

	void PlayScene::Update()
	{
		Scene::Update();	// Calling the parent scene update (fully call the function) to control all gameobjects in this scene
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
			SceneManager::LoadScene(L"TitleScene");
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void PlayScene::OnEnter()
	{
	}

	void PlayScene::OnExit()
	{
		Transform* tr = bg->GetComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));
	}
}