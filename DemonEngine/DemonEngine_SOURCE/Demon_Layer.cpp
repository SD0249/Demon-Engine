#include "Demon_Layer.h"

namespace Demon {
	Layer::Layer() : GameObjects{} {

	}

	Layer::~Layer() {

	}

	void Layer::Initialize() {
		for (GameObject* gameObj : GameObjects) {
			if (gameObj == nullptr) continue;
			gameObj->Initialize();
		}
	}

	void Layer::Update() {
		for (GameObject* gameObj : GameObjects) {
			if (gameObj == nullptr) continue;
			gameObj->Update();
		}
	}

	void Layer::LateUpdate() {
		for (GameObject* gameObj : GameObjects) {
			if (gameObj == nullptr) continue;
			gameObj->LateUpdate();
		}
	}

	void Layer::Render(HDC hdc) {
		for (GameObject* gameObj : GameObjects) {
			if (gameObj == nullptr) continue;
			gameObj->Render(hdc);
		}
	}

	void Layer::AddGameObject(GameObject* gameObj) {
		if (gameObj == nullptr) return;

		GameObjects.push_back(gameObj);
	}
}