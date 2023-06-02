#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Map
{	
	char arr[5][5] = {'A','B','C','D','E',
					  'F','G','H','I','J',
					  'K','L','M','N','O',
					  'P','Q','R','S','T',
					  'U', 'V','W','X','Y'
	};
	int visted[26];
	RectangleShape vertex;
	RectangleShape horEdge;
	RectangleShape vertEdge;
	
	Font font;
	Text text;

	void initmap();
public:
	Map();
	virtual ~Map();
	
	void update(RenderWindow& target);
	void render(RenderWindow& target,char key);

};
