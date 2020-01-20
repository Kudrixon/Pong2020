#include "window.h"
#include "Rect.h"

int main(int argc, char **argv)
{
	Window window("KudriPong", 800, 600);
	Rect rect(window, 40, 160, 10, 220, 200, 0, 200, 255);

	while (window.opened()) 
	{
		rect.keyevent();
		rect.draw();
		window.background(50, 50, 50); //podajemy kolor t³a
		window.buttonevent();
	}

	return 0;
}