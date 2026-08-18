#pragma once
#include "Demon_Entity.h"
#include "Demon_GameObject.h"

namespace Demon {
	/// <summary>
	/// Layer Class classifies the order of which things are drawn,
	/// and puts things to different compartments
	/// </summary>
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObj);

	private:
		// LayerType Type;
		std::vector<GameObject*> GameObjects;
	};
}


