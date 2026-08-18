#include "Demon_TitleScene.h"

namespace Demon {
	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
			SceneManager::LoadScene(L"PlayScene");
	}

	void TitleScene::Render(HDC hdc)
	{
		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 1350, 0, str, 11);
	}

	void TitleScene::OnEnter()
	{
	}

	void TitleScene::OnExit()
	{
	}
}