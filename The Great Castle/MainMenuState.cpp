#include "MainMenuState.h"


//Initionlization Function
void MainMenuState::initLogo()
{
	this->logo.setPosition(365, 20);
	this->logo.setSize(sf::Vector2f(212.f,224.f));
	if (!this->logoTexture.loadFromFile("Resource/image/TGC logo.png"))
	{
		std::cout << "ERROR::MAIN_MENU_STATE::FALED_TO_LOAD_LOGO_TEXTURE" << "\n";
	}
	this->logo.setTexture(&this->logoTexture);
}
void MainMenuState::initVariables()
{

}

void MainMenuState::initBackground()
{
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x), 
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->bgTextue.loadFromFile("Resource/image/backgound.png"))
	{
		std::cout << "ERROR::MAIN_MENU_STATE::FALED_TO_LOAD_BACKGROUND_TEXTURE" << "\n";
	}
	this->background.setTexture(&this->bgTextue);
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/RSU_Regular.ttf"))
	{
		std::cout << "ERROR::MAINMENUSTATE::COULD NOT LOAD FONT" << "\n";
	}
}

void MainMenuState::initKeybinds()
{

	std::ifstream ifs("Config/mainmenustate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();

}

void MainMenuState::initButton()
{
	this->buttons["GAME_STATE"] = new Button(400, 260, 150, 45,
		&this->font, "NEW GAME",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

	this->buttons["SCORE"] = new Button(400, 310, 150, 45,
		&this->font, "SCORE",
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

	this->buttons["OPTION"] = new Button(400, 360, 150, 45,
		&this->font, "OPTION",
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

	this->buttons["EXIT_STATE"] = new Button(400, 410, 150, 45,
		&this->font, "QUIT",
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
}


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{	
	this->initVariables();
	this->initBackground();
	this->initLogo();
	this->initFonts();
	this->initKeybinds();
	this->initButton();



	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		it->second;
	}
}


void MainMenuState::endState()
{
	std::cout << "Ending MainMenuState!" << "\n";
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();


}

void MainMenuState::updateButtons()
{
	// Update all the button and handle thier functionality
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//NEW GAME
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}

	//SCORE
	if (this->buttons["SCORE"]->isPressed())
	{
		
	}

	//OPTION
	if (this->buttons["OPTION"]->isPressed())
	{
		
	}

	//QUIT
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->quit = true;
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();

	//system("cls");
	//std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";

}

void MainMenuState::renderButtons(sf::RenderTarget* Target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(Target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	target->draw(this->logo);

	this->renderButtons(target);

	//Remove 
	/*sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x , this->mousePosView.y - 50 );
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(16);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());
	target->draw(mouseText);*/
}
