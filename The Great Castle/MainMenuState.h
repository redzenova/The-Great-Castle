#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "Button.h"

class MainMenuState :
	public State
{
private:
	//Variables
	sf::Texture logoTexture;
	sf::RectangleShape logo;

	sf::Texture bgTextue;
	sf::RectangleShape background;
	sf::Font font;

	std::map<std::string, Button*> buttons;

	//Functions
	void initLogo();
	void initVariables();
	void initBackground();
	void initFonts();
	void initKeybinds();
	void initButton();

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();

	//Functions
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* Target = NULL);
	void render(sf::RenderTarget* target = NULL);
};

#endif
