#include "Engine.h"
#include "Matrices.h"
#include "Particle.h"

using namespace std;
using namespace sf;
using namespace Matrices;

int main()
{
	// Create a video mode object
	int pixelWidth = VideoMode::getDesktopMode().width / 2;
	int pixelHeight = VideoMode::getDesktopMode().height / 2;
	VideoMode vm(pixelWidth, pixelHeight);
	// Create and open a window for the game
	RenderWindow window(vm, "Particle", Style::Default);
	Engine engineTest;
	engineTest.run();


	return 0;
}




