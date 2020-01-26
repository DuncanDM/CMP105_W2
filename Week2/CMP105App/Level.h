#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	int startX = 0;
	int startY = 0;
	int endX = 0;
	int endY = 0;
	int diffX = 0;
	int diffY = 0;

	bool noClick = false;
	bool leftClick = false;
	bool firstRun = true;

	void handleInput();
	void update();
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// Add your object here
	sf::CircleShape circle;

	sf::Font font;
	sf::Text text;
};