#include "State.h"

State::State(sf::RenderTarget* target,std::map<std::string,int>* supportedKeys)
{
	this->window = target;
	this->quit = false;
	this->supportedKeys = supportedKeys;
}

State::~State()
{
}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::checkQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["CLOSE"]))) {
		this->quit = true;
	}
}