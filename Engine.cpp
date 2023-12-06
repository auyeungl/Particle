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
				for (int i = 0; i < 5; i++)
				{
					Particle* particlePtr = new Particle(m_Window, rand()%25 + 25, Vector2i(event.mouseButton.x, event.mouseButton.y));
					m_particles.push_back(*particlePtr);
				}

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
	for (int i = 0, size = m_particles.size(); i <size;)
	{
		if (m_particles[i].getTTL() > 0)
		{
			m_particles[i].update(dtAsSeconds);
			i++;
		}
		else
		{
			m_particles.erase(m_particles.begin()+i);
			size--;
		}
	}

}
void Engine::draw()
{
	m_Window.clear();
	for (int i = 0; i < m_particles.size(); i++)
	{
		m_Window.draw(m_particles[i]);
	}
	m_Window.display();
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
	Clock clockThing;
	
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	
	cout << "Unit tests complete.  Starting engine..." << endl;
	while (m_Window.isOpen())
	{
		double secondsPassed = (clockThing.restart()).asSeconds();
		this->input();
		this->update(secondsPassed);
		this->draw();
	}
	
}
