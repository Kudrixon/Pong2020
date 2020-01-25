#include "window.h"
#include "Rect.h"
#include "Ball.h"
#include "Text2.h"
#include <iostream>
#include <SDL_ttf.h>
#include <random>
#include <ctime>


int main(int argc, char **argv)
{

	std::string p1score; //Wynik startowy
	std::string p2score;
	int tempscore1 = 0;
	int tempscore2 = 0;
	p1score = "0";
	p2score = "0";


	Window window("KudriPong", 800, 600);
	Rect rect(40, 160, 10, 220, 255, 0, 0, 255);
	Rect rect2(40, 160, 750, 220, 255, 0, 0, 255);
	Rect line(5, 600, 396, 0, 255, 255, 255, 255);
	Ball ball(20, 20, 390, 290, 200, 0, 200, 255);

	srand(time(NULL));
	int aiFault = rand() % 20;//wyznacza omyslnosc przeciwnika

	int counter = 0; //liczy ile razy sie odbiła piłka

	while (window.opened() && (tempscore1 < 11) && (tempscore2 < 11)) 
	{
		
		Text text(Window::renderer, "Roboto-Black.ttf", 50, p1score, { 255, 255, 255, 255 });
		Text text2(Window::renderer, "Roboto-Black.ttf", 50, p2score, { 255, 255, 255, 255 });

		if (counter < aiFault) //odpowiedzialne za bledy przeciwnika
		{
			if( ball.ycollider() <= 65 || ball.ycollider() >= 505)
			{

			}
			else 
			{
				rect2._yrect = (ball._yrect - 60);
			}
		}
		else
		{
			rect2._yrect = (ball._yrect + 30);
		}


		int arr[180]; //tablica odpowiedzialna za sprawdzanie czy piłka zdrzeyła sie z rakietką
		int arr2[180];

		for (int i = 0; i < 180; i++)
		{
			arr[i] = (rect.yer() - 20) + i; // -20 bo y pilki ma 20
			arr2[i] = (rect2.yer() - 20) + i;
		}



		bool existsp1 = std::find(std::begin(arr), std::end(arr), ball.ycollider()) != std::end(arr); //sprawdza czy wspolrzedna pilki znajduje sie w tablicy w ktorej są wspolrzedne paletki
		bool existsp2 = std::find(std::begin(arr2), std::end(arr2), ball.ycollider()) != std::end(arr2);


		if (existsp1 && ball.xcollider() <= 50) // odpowiedzialne za przyznawanie pkt i reset jak przegrasz
		{ 
			std::cout << "Obroniles sie" << std::endl;
			counter++;

		}
		else if (ball.xcollider() <= 50 && !existsp1)
		{
			ball.resposition();
			tempscore2++;
			p2score = std::to_string(tempscore2);
		}
		else if (existsp2 && ball.xcollider() >= 730)
		{
			std::cout << "Obroniles sie" << std::endl;
		}
		else if (ball.xcollider() >= 730 && !existsp2)
		{
			counter = 0; //kasuje zle polozenie paletki przeciwnika
			aiFault = rand() % 20;
			tempscore1++;
			p1score = std::to_string(tempscore1);
			ball.resposition();
			//ball.speedup(); <--------Tylko dla odwaznych
		}

		
		text.show(350, 20, Window::renderer);
		text2.show(420, 20, Window::renderer);
		rect.draw();
		rect2.draw();
		SDL_Delay(5); //zmiana opoznienia wplywa na tempo gry ale tez predkosc reakcji obiektów
		rect.keyevent();
		ball.keyspeedup();
		ball.draw();
		line.draw();
		ball.movement();
		window.background(50, 50, 50); //podajemy kolor tła
		window.buttonevent();
	}
	
	return 0;
}
