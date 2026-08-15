#pragma once
#include "CommonInclude.h"
#include "Demon_GameObject.h"
#include "Demon_SceneManager.h"

namespace Demon{

	class Application {
	public:
		// Constructor and Destructor for resetting and deallocating memory when program ends
		Application();
		~Application();

		// Main Game Loop functions
		void Initialize(HWND hwnd, UINT width, UINT height);

		void Run();

		void Update();
		void LateUpdate();

		void Render(); 

	private:
		void clearRenderTarget();
		void copyRenderTarget();
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();

	private:
		HWND mHwnd; // Handle value for this current window returned from Windows.h.
		HDC mHdc;   // This will also be used a lot for drawing and moving the drawing on window to Render logic here

		HDC mBackHdc;			// You would have to swap Back Buffer with the Front Buffer consistently to draw on the correct buffer object
								// but making a new DC you can move the things drawn from the back buffer to the front buffer to avoid flickering
		HBITMAP mBackBuffer;	// Area(like a white paper) where things will be drawn | Drawing File that has not been compressed

		UINT mWidth;	// Screen Width		(Related to Resolution)
		UINT mHeight;	// Screen Height	(Related to Resolution)
		
		// In one scene, there are various game objects. SceneManager handles managing the scene for the application to only run
	};
};


