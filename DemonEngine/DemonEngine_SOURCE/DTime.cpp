#include "DTime.h"

namespace Demon
{
	LARGE_INTEGER DTime::CpuFrequency = {};
	LARGE_INTEGER DTime::PrevFrequency = {};
	LARGE_INTEGER DTime::CurrentFrequency = {};
	float		  DTime::DeltaTimeValue = 0.0f;

	void DTime::Initialize() {
		// Retrieve CPU's frequency
		QueryPerformanceFrequency(&CpuFrequency);

		// Frequency when program(engine) first started running 
		QueryPerformanceCounter(&PrevFrequency);
	}

	void DTime::Update() {
		// Retrieve current frequency 
		QueryPerformanceCounter(&CurrentFrequency);

		// Find frequency difference between Application Update
		float difference
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		// Divide the difference with cpu frequency to get deltaTime (the elapsed time in seconds since the last frame was rendered)
		// * Using Delta Time makes your game frame rate independent, 
		//   though the frame rate that is being rendered on the screen needs to be at least 60 frame to ensure smooth movement in human eye
		DeltaTimeValue = difference / static_cast<float>(CpuFrequency.QuadPart);

		// Current Frequency becomes previous frequency 
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void DTime::Render(HDC hdc) {
		static float time = 0.0f;

		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		wchar_t str[50] = L"";		// wchar_t used to store 'wide characters' -> Takes 2 to 4 bytes(Size is implementation defined) 
									// Standard data type for WindowsAPI for string parameters. Modern C++ recommends to use char16_t or char32_t instead
		
		swprintf_s(str, 50, L"Time: %f", time);		// swprintf_s --> Used to format and store a series of characters and values in a string buffer
													// To use std::wcout, the above - whether wchar is 2 or 4 byte needs to be determined
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}