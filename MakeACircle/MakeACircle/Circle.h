#ifndef _FRAMEWORK_H
#define _FRAMEWORK_H

#include <SDL.h>
#include <iostream>

class Framework
{
public:
	//constructor
	Framework(int height_, int width_) : height(height_), width(width_)
	{
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

	//use midpoint circle algorithm to draw a circle to the screen
	void drawCircle(int centerX, int centerY, int radius)
	{

		SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

		const int32_t diameter = (radius * 2);

		int32_t x = (radius - 1);
		int32_t y = 0;
		int32_t tx = 1;
		int32_t ty = 1;
		int32_t error = (tx - diameter);

		while (x >= y)
		{
			SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
			SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
			SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
			SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
			SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
			SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
			SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);
			SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);

			if (error <= 0)
			{
				++y;
				error += ty;
				ty += 2;
			}

			if (error > 0)
			{
				--x;
				tx += 2;
				error += (tx - diameter);
			}
		}

		SDL_RenderPresent(renderer);
	}


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


private:
	int height;
	int width;
	SDL_Renderer* renderer = nullptr;
	SDL_Window* window = nullptr;

};


#endif