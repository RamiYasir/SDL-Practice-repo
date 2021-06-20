#include <SDL.h>
#include <iostream>
#include "Framework.h"
#include "Circle.h"


int main(int argc, char* argv[])
{
	//seed rng
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	//initialise framework
	Framework fw(640, 640);
	
	//initialise event
	SDL_Event ev;

	//game looop bool
	bool isRunning = true;

	//game loop
	while (isRunning)
	{

		//max circle objects that can be displayed onscreen
		bool maxCirclesDisplayed = false;
		Circle circles[20];

		//draw circle objects onto screen
		for (int i = 0; i < 20; i++) {
			circles[i].setSizeOfCircle(fw);
			SDL_Delay(fw.getRandomNumber(100, 1000));
			circles[i].drawCircle(fw, maxCirclesDisplayed);

			while (SDL_PollEvent(&ev) != 0)						//ugly that this is here and repeated twice...
			{

				if (ev.type == SDL_QUIT)
					isRunning = false;
			}
		}

		//redraw circle objects, first as black and then with a new size and colour
		//is there a better way to do all this?
		while (isRunning) {
			for (int i = 0; i < 20; i++) {
				maxCirclesDisplayed = true;
				SDL_Delay(fw.getRandomNumber(100, 1000));
				circles[i].drawCircle(fw, maxCirclesDisplayed);
				circles[i].setSizeOfCircle(fw);
				maxCirclesDisplayed = false;
				circles[i].drawCircle(fw, maxCirclesDisplayed);

				while (SDL_PollEvent(&ev) != 0)					//hate having this twice. Make into a function? Figure out a way to redraw circles without this much nested looping? 
				{

					if (ev.type == SDL_QUIT)
						isRunning = false;
				}
			}
		}
	

		
	}
	

	return 0;

}