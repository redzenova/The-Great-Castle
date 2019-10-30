#ifndef GAME_H
#define GAME_H

#include "GameState.h"

class Game
{

private:
	/*Variables*/
	sf::RenderWindow *window;
	sf::Event event;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	/*Initialization*/
	void inintWindow();
	void initStates();

public:
	/* Constructor|Destructors */
	Game();
	virtual ~Game();

	/* Functions */
	void updateDT();
	void updateSFMLEvents();
	void update();
	void render();
	void run();

};

#endif