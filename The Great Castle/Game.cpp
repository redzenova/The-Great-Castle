#include "Game.h"

/*Static Function*/

/*Initializer*/

void Game::inintWindow()
{
	/*window.ini file*/
	std::ifstream ifs("window.ini");

	std::string title = "TGC";
	sf::VideoMode window_res(1080, 720);
	unsigned fps_limit = 120;
	bool vsync_enable = false;
	
	
	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_res.width >> window_res.height;
		ifs >> fps_limit;
		ifs >> vsync_enable;
	}

	else std::cout << "Can't open file" << "\n";

	ifs.close();

	this->window = new sf::RenderWindow(window_res, title);
	this->window->setFramerateLimit(fps_limit);
	this->window->setVerticalSyncEnabled(vsync_enable);
}

void Game::initStates()
{
	//this->states.push(new GameState(this->window));
}

/* Constructor|Destructors */
Game::Game()
{
	this->inintWindow();
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


void Game::updateDT()
{
	/*Update and render time per one frame*/
	this->dt = this->dtClock.restart().asSeconds();
	
	//system("cls");
	//std::cout << this->dt << "\n";
}

/*============= Functions ================*/
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
		this->states.top()->update(this->dt);
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
