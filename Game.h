#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Map.h"
#include "bot.h"
#include "Floyd.h"
#include <queue>

using namespace std;
using namespace sf;
class Game
{
	RenderWindow* window;
	VideoMode videomode;
	Event ev;
	
	//State variables
	bool pause = true;
	bool wait = false;
	bool end = false;
	int timer = 0;

	//Map
	Map map;

	char key;

	//Car

	bot car;
	float distance;
	int direction ;
	float speed;
	char location = 'A';
	int totalDistance = 0;

	int count;
	//text
	Font font;
	Text text, instruct, dist;
	//Floyd
	Floyd func;

	//queue
	int selectionQueue[2];
	int sp = -1;
	bool ready = true;

	//private functions;
	void initWindow();
	void initVariable();
public:
	//Constructor destructor
	Game();
	virtual ~Game();

	//Game functions
	void updateDir();
	bool isOpen();
	void pollEvent();
	void update();
	void render();


};
