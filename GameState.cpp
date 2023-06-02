#include "GameState.h"

void GameState::initKeyBinds()
{
	std::ifstream ifs("Config/supported_keyBinds.ini");
	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 ="";
		while (ifs >> key >> key2) {
			this->keyBinds[key] = this->supportedKeys->at(key2);
		}
	}
	else {
		std::cout << "ooopphhgff";
	}
	ifs.close();
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	:State(window,supportedKeys)
{
	this->initKeyBinds();
}

GameState::~GameState()
{
}


void GameState::endState()
{
	std::cout << "Ending gamestate";
}

void GameState::updateInput(const float& dt)
{
	this->checkQuit();

	//Update player Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))))
		this->player.move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_LEFT"))))
		this->player.move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
		this->player.move(dt, 0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_RIGHT"))))
		this->player.move(dt, 1.f, 0.f);

	//std::cout << "and " << this->supportedKeys->at("W");

}

void GameState::update(const float& dt)
{
	this->updateInput(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		std::cout << "A";
	}
}

void GameState::render(sf::RenderTarget* target = nullptr)
{
	this->player.render(*target);
}