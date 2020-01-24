#include "window.h"
#include "Rect.h"
#include "Ball.h"
#include <iostream>
#include <SDL_ttf.h>


int main(int argc, char **argv)
{
	Window window("KudriPong", 800, 600);
	Rect rect(window, 40, 160, 10, 220, 200, 0, 200, 255);
	Ball ball(window, 20, 20, 390, 290, 200, 0, 200, 255);
	Rect rect2(window, 40, 160, 750, 220, 200, 0, 200, 255);


	while (window.opened()) 
	{
		rect2._yrect = ball._yrect;

		int arr[120];

		for (int i = 0; i < 120; i++)
		{
			arr[i] = rect.yer() + i;
		}

		bool exists = std::find(std::begin(arr), std::end(arr), ball.ycollider()) != std::end(arr);

		if (exists && ball.xcollider() == 50) 
		{ 
			std::cout << "Obroniles sie" << std::endl;
		}
		else if (ball.xcollider() == 50 && !exists) 
		{
			ball.resposition();
		}

		

		rect.draw();
		rect2.draw();
		SDL_Delay(5);
		rect.keyevent();
		ball.speedup();
		ball.draw();
		ball.movement();
		window.background(50, 50, 50); //podajemy kolor tła
		window.buttonevent();
	}

	return 0;
}
