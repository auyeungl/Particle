#include "Engine.h"
#include "Matrices.h"
#include "Particle.h"
const double PI = 3.1415;

using namespace std;
//using namespace sf;
using namespace Matrices;

int main()
{
	// Create a video mode object
	int pixelWidth = VideoMode::getDesktopMode().width / 2;
	int pixelHeight = VideoMode::getDesktopMode().height / 2;
	VideoMode vm(pixelWidth, pixelHeight);
	// Create and open a window for the game
	RenderWindow window(vm, "Particle", Style::Default);

	while (window.isOpen())
	{

		/*
		****************************************
		Handle the players input
		****************************************
		*/

		

		/*
		****************************************
		Update the scene
		****************************************
		*/


		/*
		****************************************
		Draw the scene
		****************************************
		*/

		window.clear();
		window.display();
	}
	return 0;
}




