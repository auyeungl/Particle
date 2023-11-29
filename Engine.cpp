#include "Engine.h"


void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) m_Window.close();
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				std::cout << "the left button was pressed" << std::endl;
				std::cout << "mouse x: " << event.mouseButton.x << std::endl;
				std::cout << "mouse y: " << event.mouseButton.y << std::endl;

			}
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		m_Window.close();
	}
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
