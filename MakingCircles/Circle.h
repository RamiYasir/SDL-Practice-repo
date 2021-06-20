#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Framework.h"


class Circle {

public:
	Circle() {}

	//do I really need to keep this?
	Circle(int centerX, int centerY, int radius){
	
		m_centerX = centerX;
		m_centerY = centerY;
		m_radius = radius;

	}

	//draw circle onto screen using midpoint algorithm
	void drawCircle(Framework& fw, bool maxCirclesDisplayed)
	{
		if (maxCirclesDisplayed == false) {
			setRandomCircleColour(fw);
		}
		if (maxCirclesDisplayed == true) {
			setCircleColourToBlack(fw);
		}
		SDL_SetRenderDrawBlendMode(fw.renderer, SDL_BLENDMODE_BLEND);

		const int32_t diameter = (m_radius * 2);

		int32_t x = (m_radius - 1);
		int32_t y = 0;
		int32_t tx = 1;
		int32_t ty = 1;
		int32_t error = (tx - diameter);

		while (x >= y)
		{
			SDL_RenderDrawPoint(fw.renderer, m_centerX + x, m_centerY - y);
			SDL_RenderDrawPoint(fw.renderer, m_centerX + x, m_centerY + y);
			SDL_RenderDrawPoint(fw.renderer, m_centerX - x, m_centerY - y);
			SDL_RenderDrawPoint(fw.renderer, m_centerX - x, m_centerY + y);
			SDL_RenderDrawPoint(fw.renderer, m_centerX + y, m_centerY - x);
			SDL_RenderDrawPoint(fw.renderer, m_centerX + y, m_centerY + x);
			SDL_RenderDrawPoint(fw.renderer, m_centerX - y, m_centerY - x);
			SDL_RenderDrawPoint(fw.renderer, m_centerX - y, m_centerY + x);

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

		SDL_RenderPresent(fw.renderer);
	}

	void setSizeOfCircle(Framework& fw) {
		m_centerX = fw.getRandomNumber(10, 630);
		m_centerY = fw.getRandomNumber(10, 630);
		m_radius = fw.getRandomNumber(20, 200);
	}

private:

	int setRandomCircleColour(Framework& fw) {

		int red = fw.getRandomNumber(0, 255);
		int blue = fw.getRandomNumber(0, 255);
		int green = fw.getRandomNumber(0, 255);

		return (SDL_SetRenderDrawColor(fw.renderer, red, blue, green, 255));
	}

	int setCircleColourToBlack(Framework& fw) {

		return (SDL_SetRenderDrawColor(fw.renderer, 0, 0, 0, 255));
	}

private:
	int m_centerX{ 0 };
	int m_centerY{ 0 };
	int m_radius{ 0 };

};

#endif // !_CIRCLE_H