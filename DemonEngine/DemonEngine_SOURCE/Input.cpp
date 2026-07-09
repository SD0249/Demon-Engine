#include "Input.h"

namespace Demon {

	std::vector<Input::Key> Input::mKeys{};

	// ASCII Code of keys
	int ASCII[(UINT)eKeyCode::End]{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M'
	};

	/// <summary>
	/// Initialize input state of keys 
	/// </summary>
	void Input::Initialize()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key{};
			key.keyCode = (eKeyCode)i;
			key.pressed = false;
			key.state = eKeyState::None;

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++) {
			// When key pressed
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// Pressed one frame before
				if (mKeys[i].pressed == true)
				{
					mKeys[i].state = eKeyState::Pressed;
				}
				// Wasn't pressed one frame before
				else
				{
					mKeys[i].state = eKeyState::Down;
				}

				mKeys[i].pressed = true;
			}
			// When key not pressed
			else
			{
				// Pressed one frame before
				if (mKeys[i].pressed == true) {
					mKeys[i].state = eKeyState::Up;
				}
				// Wasn't pressed one frame before
				else
				{
					mKeys[i].state = eKeyState::None;
				}

				mKeys[i].pressed = false;
			}
		}
	}

}