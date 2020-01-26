#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	text.setFont(font);
	text.setString("Mouse Pos:");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(0, 0);

	circle.setRadius(50);
	circle.setPosition(-100, -100);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(5.f);
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W key was pressed\n";
	}

	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "keys J, K and L were all pressed\n";
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		window->close();
	}

	if (input->isMouseLDown() == true)
	{
		if (firstRun == true)
		{
			startX = input->getMouseX();
			startY = input->getMouseY();
			firstRun = false;
		}
		else
		{
			endX = input->getMouseX();
			endY = input->getMouseY();
		}
		
		leftClick = true;
		noClick = false;
	}
	else
	{
		noClick = true;
		firstRun = true;
	}

	if (leftClick == true && noClick == true)
	{
		diffX = endX - startX;
		diffY = endY - startY;

		std::cout << "diffX: " + std::to_string(diffX) + " diffY: " + std::to_string(diffY) + "\n";

		leftClick = false;
	}

	if (input->isMouseRDown() == true)
	{
		circle.setPosition(input->getMouseX(), input->getMouseY());
	}
}

// Update game objects
void Level::update()
{
	int posX = input->getMouseX();
	int posY = input->getMouseY();

	std::string output("Mouse Pos: " + std::to_string(posX) + ", " + std::to_string(posY));
	text.setString(output);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(text);
	window->draw(circle);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}
