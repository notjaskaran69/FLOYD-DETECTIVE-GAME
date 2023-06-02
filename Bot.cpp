#include "bot.h"

void bot::initSprite()
{

	if (!this->texture.loadFromFile("Textures/newimage.png")) {
		cout << "Cant lod texture";
	}

	this->sprite.setTexture(this->texture);
	this->sprite.setPosition({ 50.f,0 });
	this->sprite.setScale({ 0.2f,0.1f });
}

bot::bot()
{
	initSprite();
}

bot::~bot()
{
}

void bot::move(int direction)
{
	//left
	if (direction == 1) { 
		this->sprite.move({ this->speed * -1,0 });
	}
	//right
	else if (direction == 2) {
		this->sprite.move({ this->speed,0 });
	}
	//up
	else if (direction == 3) {
		this->sprite.move({ 0,this->speed* -1 });
	}
	//down
	else {
		this->sprite.move({0, this->speed });
	}


}

void bot::update(int direction, float speed)
{
	this->speed = speed;
	this->move(direction);
}

void bot::render(RenderWindow& target)
{
	//target.draw(this->car);
	target.draw(this->sprite);
}