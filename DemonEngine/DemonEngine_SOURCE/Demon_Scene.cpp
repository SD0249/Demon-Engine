#include "Demon_Scene.h"

namespace Demon
{
	Scene::Scene()
		: GameObjects{}
	{

	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize() {

	}

	void Scene::Update() {
		// Update all game objects inside scene
		for (GameObject* gameObj : GameObjects) {
			gameObj->Update();
		}
	}

	void Scene::LateUpdate() {
		// Late update all game objects inside scene
		for (GameObject* gameObj : GameObjects) {
			gameObj->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc) {
		// Render all game objects inside scene
		for (GameObject* gameObj : GameObjects) {
			gameObj->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObj)
	{
		GameObjects.push_back(gameObj);
	}
}