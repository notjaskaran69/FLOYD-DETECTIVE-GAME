#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class bot
{
	Sprite sprite;
	Texture texture;

	
	void initSprite();

public:
	bot();
	virtual ~bot();

	float speed ;
	void move(int direction);
	void update(int direction,float speed);
	void render(RenderWindow& target);

};
