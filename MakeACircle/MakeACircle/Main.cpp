#include "Circle.h"

//programme draws a blue circle to the screen and waits for user to click x out of programme.

int main(int argc, char* argv[])
{
	Framework fw(640, 640);

	//draw a circle at position.x = 320, position.y = 320 and radius of 100
	fw.drawCircle(320, 320, 100);

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
	}

	return 0;

}