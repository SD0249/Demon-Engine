#pragma once
#include "Demon_Entity.h"
#include "Demon_GameObject.h"

namespace Demon {
	// Represents different stage/scene in games. Manages all the game objects in itself.
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		// Scene also needs some of the sub main loop functions from Application 
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObj);

	private: // Child Scene classes also need access to game objects
		std::vector<GameObject*> GameObjects;

	};
}


