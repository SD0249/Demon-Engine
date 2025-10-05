#pragma once
#include "CommonInclude.h"
#include "Demon_GameObject.h"

namespace Demon{

	class Application {
	public:
		// Constructor and Destructor for resetting and deallocating memory when program ends
		Application();
		~Application();

		// Main Game Loop functions
		void Initialize(HWND hwnd);

		void Run();

		void Update();
		void LateUpdate();

		void Render(); 

	private:
		HWND mHwnd; // Handle value for this current window returned from Windows.h.
		HDC mHdc; // This will also be used a lot for drawing and moving the drawing on window to Render logic here
		
		// Player -> Instead of storing every object and tracking them like this, we make a base class to handle EACH Game Objects
		// OBJECT ORIENTED PROGRAMMING!
		// float mX;
		// float mY;
		GameObject mPlayer;
	};
};


