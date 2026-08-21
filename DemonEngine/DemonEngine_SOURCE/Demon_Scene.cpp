#include "Demon_Scene.h"

namespace Demon
{
	Scene::Scene()
		: Layers{}
	{
		Layers.resize((UINT)enums::LayerType::Max);	
		/*for (size_t i = 0; i < (UINT)LayerType::Max; i++) {
			Layers[i] = new Layer();
		}*/

		std::for_each(Layers.begin(), Layers.end(), 
			[](Layer*& layer)						// Layer*& should be used. (Layer* modifies what is inside the object / Layer*& changes where the pointer points)
											        // Basically if the pointer points to a new address that points to new object,
													// it is thrown away after the function ends, because it modified the copy (pointer is a VALUE and it is copied when passed as a parameter)
													// Using Layer*, the value inside pointer(address to obj) is copied(pointer itself is given a new address).
													// However, using Layer*&, the pointer keeps its original address and points to the new object created
			{
				layer = new Layer();
			});
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize() {
		for (Layer* layer : Layers) {
			if (layer == nullptr) continue;

			layer->Initialize();
		}
	}

	void Scene::Update() {
		// Update all game objects inside scene
		for (Layer* layer : Layers) {
			if (layer == nullptr) continue;

			layer->Update();
		}
	}

	void Scene::LateUpdate() {
		// Late update all game objects inside scene
		for (Layer* layer : Layers) {
			if (layer == nullptr) continue;

			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc) {
		// Render all game objects inside scene
		for (Layer* layer : Layers) {
			if (layer == nullptr) continue;

			layer->Render(hdc);
		}
	}


	void Scene::AddGameObject(GameObject* gameObj, enums::LayerType type)
	{
		if (gameObj == nullptr) return;

		Layers[(UINT)type]->AddGameObject(gameObj);
	}

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{
	}
	
}