#include "Engine.h"


void Engine::input()
{

}
void Engine::update(float dtAsSeconds)
{

}
void Engine::draw()
{

}

// The Engine constructor
Engine::Engine()
{	
	// constructs window titled "Particle" with the dimensions of half the screen - effectively making the area a fourth of the screen
	m_Window.create(VideoMode(VideoMode::getDesktopMode().width / 2, VideoMode::getDesktopMode().height / 2), "Particle");
}

// Run will call all the private functions
void Engine::run()
{
	Clock clock();
	
}
