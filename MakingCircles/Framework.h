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

	//I think what's happening is that the Circle class is calling Framework constructor, which sets SDL_Window* window and renderer to nullptr, getting rid of the window. 


	//use midpoint circle algorithm to draw a circle to the screen
};




#endif


//can't get this function to work... I'm doing something wrong here.

		/*void changeColour(int red, int green, int blue, int alpha)
		{
			for (int r = red; r <= 254; r++)
			{
				for (int g = green; g <= 254; g++)
				{
					for (int b = blue; b <= 254; b++)
					{
						SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
					}
				}

			}
		}*/