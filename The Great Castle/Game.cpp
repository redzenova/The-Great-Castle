#include "Game.h"

/*Static Function*/

/*Initializer*/
void Game::initVaribles()
{
	this->window = NULL;
	this->fullscreen = false;
	this->dt = 0.f;
}

void Game::inintWindow()
{
	/*window.ini file*/
	std::ifstream ifs("Config/window.ini");
	this->videoModes = sf::VideoMode::getFullscreenModes();


	std::string title = "TGC";
	sf::VideoMode window_res = sf::VideoMode::getDesktopMode();
	bool fullscreen = false;
	unsigned fps_limit = 120;
	bool vsync_enable = false;
	unsigned antialiasing_level = 0;
	
	
	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_res.width >> window_res.height;
		ifs >> fullscreen;
		ifs >> fps_limit;
		ifs >> vsync_enable;
		ifs >> antialiasing_level;
	}

	else std::cout << "Can't open file" << "\n";
	
	ifs.close();

	this->fullscreen = fullscreen;
	this->windowSettings.antialiasingLevel = antialiasing_level;
	
	if(this->fullscreen)
		this->window = new sf::RenderWindow(window_res, title , sf::Style::Fullscreen , windowSettings);
	else
		this->window = new sf::RenderWindow(window_res, title, sf::Style::Titlebar | sf::Style::Close, windowSettings);

	this->window->setFramerateLimit(fps_limit);
	this->window->setVerticalSyncEnabled(vsync_enable);
}

void Game::initKeys()
{
	this->supportedKeys.emplace("Escape", sf::Keyboard::Key::Escape);
	this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
	this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
	this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
	this->supportedKeys.emplace("S", sf::Keyboard::Key::S);

	//DEBUG
	for (auto i : this->supportedKeys)
	{
		std::cout << i.first << " " << i.second << "\n";
	}
}

void Game::initStates()
{
	this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}



/* Constructor|Destructors */
Game::Game()
{
	this->inintWindow();
	this->initKeys();
	this->initStates();
	
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}



/*============= Functions ================*/
void Game::endApplication()
{
	std::cout << "Ending Application" << "\n";
}

void Game::updateDT()
{
	/*Update and render time per one frame*/
	this->dt = this->dtClock.restart().asSeconds();

	//system("cls");
	//std::cout << this->dt << "\n";
}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}

}

void Game::update()
{
	this->updateSFMLEvents();

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}

	//Close App
	else
	{
		this->endApplication();
		this->window->close();
	}
}

void Game::render()
{
	this->window->clear();
	
	//render items here !
	if (!this->states.empty())
		this->states.top()->render(this->window);


	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDT();
		this->update();
		this->render();
	}
}
