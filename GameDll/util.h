#pragma once

#include <string>
#include "GameDll.h"

namespace util {
	extern "C" GAMEDLL_API inline std::string GetRourcePath(std::string s) {
		return "D:/Development/Visual Studio Projects/mysdlproject/resources/" + s;
	}
} // namespace util
