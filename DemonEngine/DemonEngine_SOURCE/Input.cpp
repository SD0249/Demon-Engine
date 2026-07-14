#include "Input.h"
#include <algorithm>

namespace Demon {

	std::vector<Input::Key> Input::Keys{};

	// ASCII Code of keys
	int ASCII[(UINT)eKeyCode::End]{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP
	};

	/// <summary>
	/// Initialize input state of keys - Called in Application Initialize
	/// </summary>
	void Input::Initialize()
	{
		createKeys();
	}

	/// <summary>
	/// Update each key state - Called in Application Update
	/// </summary>
	void Input::Update()
	{
		updateKeys();
	}


	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key{};
			key.keyCode = (eKeyCode)i;
			key.pressed = false;
			key.state = eKeyState::None;

			Keys.push_back(key);
		}
	}

	void Input::updateKeys()
	{
		std::for_each(Keys.begin(), Keys.end(), 
					  [](Input::Key& key) -> void {
							if (isKeyDown(key))
							{
								updateKeyDown(key);
							}
							else
							{
								updateKeyUp(key);
							}
					  });
	}

	bool Input::isKeyDown(Input::Key& key)
	{
		return GetAsyncKeyState(ASCII[(UINT)key.keyCode]) & 0x8000;
	}

	void Input::updateKeyDown(Input::Key& key)
	{
		// Pressed one frame before
		if (key.pressed == true)
		{
			key.state = eKeyState::Pressed;
		}
		// Not pressed one frame before
		else
		{
			key.state = eKeyState::Down;
		}

		key.pressed = true;
	}

	void Input::updateKeyUp(Input::Key& key)
	{
		// Pressed one frame before
		if (key.pressed == true)
		{
			key.state = eKeyState::Up;
		}
		// Not pressed one frame before
		else
		{
			key.state = eKeyState::None;
		}

		key.pressed = false;
	}

}