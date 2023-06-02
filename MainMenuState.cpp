#include "MainMenuState.h"


void MainMenuState::initKeyBinds()
{
	/*std::ifstream ifs("Config/supported_keyBinds.ini");
	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";
		while (ifs >> key >> key2) {
			this->keyBinds[key] = this->supportedKeys->at(key2);
		}
	}
	else {
		std::cout << "ooopphhgff";
	}
	ifs.close();*/
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	:State(window, supportedKeys)
{
	this->initKeyBinds();
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
}


void MainMenuState::endState()
{
	std::cout << "Ending gamestate";
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkQuit();

	//Update player Input

}

void MainMenuState::update(const float& dt)
{
	this->updateInput(dt);
}

void MainMenuState::render(sf::RenderTarget* target = nullptr)
{
	if (!target)
		target = this->window;
	target->draw(this->background);
}
