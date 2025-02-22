#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <memory>

#include "raylib-include/raylib.h"
#include "raylib-include/raygui.h"


class BaseLoader {
public:

	uint8_t progressLoading;

	virtual bool load() = 0;

};

class Loader : BaseLoader {
private:

	
public:

	bool load();	

	std::unordered_map<std::string, Texture2D> textureMap;
	std::unordered_map<std::string, Music> musicMap;
	std::unordered_map<std::string, AudioCallback> audioMap;


};
