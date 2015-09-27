#include "App.h"

#include <string>
#include <iostream>

using namespace std;

App::App()
{
}


App::~App()
{
	close();
}

bool App::init(int width, int height)//Screen dimension constants
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError();
		return false;
	}
	
	//Create window
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenWidth, _screenheight, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	
	if (gWindow == NULL)
	{
		cerr << "Window could not be created! SDL_Error: " << SDL_GetError();
		return false;
	}

	//Get window surface
	gScreenSurface = SDL_GetWindowSurface(gWindow);
}

void App::run()
{
	if (init())
		gameLoop();
}

bool App::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP(util::GetRourcePath("hello_world.bmp").c_str());
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void App::close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void App::initSystems()
{

}
void App::gameLoop()
{
	while (_gamestate != GameState::EXIT) 
	{
		processInput();
	}
}
void App::processInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			_gamestate = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			cout << event.motion.x << " " << event.motion.y << endl;
			break;
		}
	}
}

GAMEDLL_API void CreateApp() {
	App app;

	//Start up SDL and create window
	if (!app.init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!app.loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Apply the image
			SDL_BlitSurface(app.gHelloWorld, NULL, app.gScreenSurface, NULL);

			//Update the surface
			SDL_UpdateWindowSurface(app.gWindow);

			//Wait two seconds
			SDL_Delay(2000);
		}
	}

	SDL_Delay(2000);

	//Free resources and close SDL
	app.close();
}