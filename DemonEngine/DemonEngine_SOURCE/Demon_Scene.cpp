#include "Demon_Scene.h"

namespace Demon
{
	Scene::Scene()
		: Layers{}
	{
		Layers.resize((UINT)LayerType::Max);	
		/*for (size_t i = 0; i < (UINT)LayerType::Max; i++) {
			Layers[i] = new Layer();
		}*/

		std::for_each(Layers.begin(), Layers.end(), 
			[](Layer*& layer)						// Layer*& because the pointer points to nothing. (Layer* modifies what is inside the object / Layer*& changes where the pointer points)
											        // Basically if the pointer assigns the new object with a new address,
													//it is thrown away after the function ends
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


	void Scene::AddGameObject(GameObject* gameObj, LayerType type)
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