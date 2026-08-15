#pragma once
#include "CommonInclude.h"
#include "Demon_Scene.h"

namespace Demon
{
	// Handles managing different scenes. Holds static fields/functions because of there needing to be one entity
	class SceneManager
	{
	public:

		// Create new Scene (existing child scene type)
		template <typename T> // Types of scenes will be implemented as different classes, so Template is used here
		static Scene* CreateScene(const std::wstring& name) {
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			Scenes.insert(std::make_pair(name, scene));

			return scene;
		}

		// Load a certain scene by name, it becomes the active scene
		static Scene* LoadScene(const std::wstring& name) {
			// List, map, etc, returns a pointer of that object
			std::map<std::wstring, Scene*>::iterator iter = Scenes.find(name);

			// If the scene does not exist
			if (iter == Scenes.end()) return nullptr;

			activeScene = iter->second;

			return iter->second;	// Return value of map
		}


		// Scene manager also needs some of the sub main loop functions from Application
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		// Static fields declared belongs to the entire class. 
		// But the class itself doesn't assign space to the static fields unlike other non-static fields. (If you don't, it causes an unresolved external symbol error..)
		// Therefore, these need to be defined(allocated space) in the .cpp file.
		static std::map<std::wstring, Scene*> Scenes;	// The tree structure is easier to find scene by name than lists
		static Scene* activeScene;				// However only one scene should be active(played)
	};

}

