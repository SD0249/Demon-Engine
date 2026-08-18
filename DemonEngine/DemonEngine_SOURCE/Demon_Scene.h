#pragma once
#include "Demon_Entity.h"
#include "Demon_GameObject.h"
#include "Demon_Input.h"
#include "Demon_Layer.h"

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

		virtual void OnEnter();		// Triggers things when player enters scene
		virtual void OnExit();		// Trigger things like resetting position & HP etc when player leaves scene

		void AddGameObject(GameObject* gameObj, LayerType type);

	private: 
		std::vector<Layer*> Layers;				// Each layer holds the game objects that belong to them
	};
}


