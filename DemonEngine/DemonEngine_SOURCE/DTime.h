#pragma once
#include "CommonInclude.h"

namespace Demon
{
	class DTime
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER CpuFrequency;		// Cpu's natural frequency (just like how time(clock) is measured in real life)
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float		 DeltaTimeValue;
	};
}


