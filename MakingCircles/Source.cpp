#include <SDL.h>
#include <iostream>
#include "Framework.h"
#include "Circle.h"


int main(int argc, char* argv[])
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	static int circleCounter{ 0 };

	Framework fw(640, 640);
	//fw.drawCircle(fw.getRandomNumber(10, 630), fw.getRandomNumber(10, 630), fw.getRandomNumber(20, 200));

	
	SDL_Event ev;
	bool isRunning = true;

	//game loop
	while (isRunning)
	{

		while (SDL_PollEvent(&ev) != 0)
		{

			if (ev.type == SDL_QUIT)
				isRunning = false;
		}

		if (circleCounter < 15) {
			Circle circle(fw.getRandomNumber(10, 630), fw.getRandomNumber(10, 630), fw.getRandomNumber(20, 200));
			SDL_Delay(fw.getRandomNumber(100, 1000));
			circle.drawCircle(fw);
			circleCounter++;
		}
		else {
			continue;
		}
	
	}

	return 0;

}