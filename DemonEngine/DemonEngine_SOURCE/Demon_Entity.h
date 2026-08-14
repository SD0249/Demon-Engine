#pragma once
#include "CommonInclude.h"

namespace Demon
{
	// Any object that inherits this class will hold a name for the purpose of making debugging easier
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { _name = name; }
		std::wstring& GetName() { return _name; }

	private:
		std::wstring _name;	
	};
}

