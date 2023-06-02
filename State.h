#pragma once

#include"Entity.h"
class State
{
private:

protected:
	sf::RenderTarget *window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keyBinds;
	bool quit;

	//Resources
	std::vector<sf::Texture> textures;


	//Functions
	
	virtual void initKeyBinds() = 0;

public:
	State(sf::RenderTarget* target, std::map<std::string, int>* supportedKeys);
	virtual ~State();
	const bool& getQuit() const ;

	virtual void checkQuit();

	virtual void endState() = 0;
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;   //pure virtual function
	virtual void render(sf:: RenderTarget* target = nullptr) = 0;
};
