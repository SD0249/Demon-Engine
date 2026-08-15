#pragma once
#include "CommonInclude.h"
#include "Demon_Entity.h"

namespace Demon {

	class GameObject; // Since gameobject includes component, here we use forward declaration 
					  // to avoid them referencing each other like a loop (only can use as pointer or reference)			
	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* owner) { _owner = owner; }
		GameObject* GetOwner() { return _owner; }

	private:
		GameObject* _owner;	// A component class instance needs to know which game object it belongs to.
	};
}

