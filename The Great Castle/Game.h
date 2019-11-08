#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"

class Game
{

private:
	/*Variables*/
	sf::RenderWindow *window;
	sf::Event event;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;

	bool fullscreen = false;
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	/*Initialization*/
	void initVaribles();
	void inintWindow();
	void initStates();
	void initKeys();

public:
	/* Constructor|Destructors */
	Game();
	virtual ~Game();

	/* Functions */

	//Regular
	void endApplication();


	//Update
	void updateDT();
	void updateSFMLEvents();
	void update();

	//render
	void render();

	//Core
	void run();

};

#endif