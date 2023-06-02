#pragma once
#include "GameState.h"
class MainMenuState :
    public State
{
private:
	void initKeyBinds();
	sf::RectangleShape background;

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~MainMenuState();

	//functions
	void endState();

	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target);
};
