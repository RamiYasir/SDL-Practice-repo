#ifndef _FRAMEWORK_H
#define _FRAMEWORK_H

#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>


class Framework
{
public:
	Framework(){}

	//constructor
	Framework(int height_, int width_) 
	{
		height = height_;
		width = width_;

		SDL_Init(SDL_INIT_VIDEO);
		SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	//destructor
	~Framework()
	{
		SDL_DestroyRenderer(renderer);
		renderer = nullptr;
		SDL_DestroyWindow(window);
		window = nullptr;
		SDL_Quit();
	}

	int getRandomNumber(int min, int max) {
		static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
		return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
	}

private:
	int height{ 0 };
	int width{ 0 };
	SDL_Window* window = nullptr;

public:
	SDL_Renderer* renderer = nullptr;
};




#endif