#pragma once

#include "stdafx.h"
#include "GameDll.h"

enum class GameState {PLAY, EXIT};

class GAMEDLL_API App
{
public:
	SDL_Window* gWindow = NULL;
	SDL_Surface* gScreenSurface = NULL;
	SDL_Surface* gHelloWorld = NULL;

	App();
	~App();

	bool init(int width = 640, int height = 480);
	void run();

	bool loadMedia();
	void close();

private:
	int _screenWidth = 640;
	int _screenheight = 480;
	GameState _gamestate = GameState::PLAY;

	void initSystems();
	void gameLoop();
	void processInput();
};

extern "C" GAMEDLL_API void CreateApp();