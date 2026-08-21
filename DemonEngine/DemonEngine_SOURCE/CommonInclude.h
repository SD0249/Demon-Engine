#pragma once
#include <Windows.h> // Since this is going to be used widely accross all of the files in SOURCE / Access to window related stuff
#include <vector>
#include <algorithm>
#include <string>
#include <map>		// Basically a tree data structure. Ordered

#include "Demon_Math.h"

#include <mmsystem.h>					// mmsystem.h: Gives programs access to old multimedia features like audio services,
										//			   joystick control, multimedia timers, MCI support(play media files such as CDs and digital video)
#include <dinput.h>						// dinput.h: Handles input devices like joysticks, gamepads, mice, and keyboards 
										//			 in Windows applications and games 
#pragma comment(lib, "Msimg32.lib")		// Link to libaray to get implementations of functions given notice of above to the compiler
#pragma comment(lib, "winmm.lib")

#include <gdiplus.h>					// gdiplus.h: Allows applications to use 2D graphics, images, and typography
#pragma comment(lib, "gdiplus.lib")

#include "Demon_Enums.h"