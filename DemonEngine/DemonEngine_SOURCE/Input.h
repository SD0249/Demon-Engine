#pragma once
#include "CommonInclude.h"

namespace Demon
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		End
	};

	/// <summary>
	/// Recieves and holds information regarding input
	/// </summary>
	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool pressed;
		};

		static void Initialize();
		static void Update();

		static bool GetKeyDown(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Down; };
		static bool GetKeyUp(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Up; };
		static bool GetKey(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Pressed; };

	private:
		// Only one instance/state information in class(Each instance of input won't hold different information)
		// Can be accessed and changed only by accessing the input class
		static std::vector<Key> mKeys;
	};
}


