#include "Map.h"

void Map::initmap()
{
	vertex.setFillColor(Color::Yellow);
	vertex.setSize({40.f, 40.f});

	vertEdge.setFillColor(Color::Red);
	vertEdge.setSize({ 10.f, 160.f });

	horEdge.setFillColor(Color::Red);
	horEdge.setSize({ 160.f, 10.f });

	this->font.loadFromFile("Fonts/Roboto-Light.ttf");

	this->text.setFont(font);
	this->text.setString("A");
	this->text.setPosition({ 40.f,40.f });
	this->text.setCharacterSize(50.f);
	this->text.setFillColor(Color::Blue);
}

Map::Map()
{
	initmap();
	for (int i = 0;i < 26;i++) {
		visted[i] = 0;
	}
}

Map::~Map()
{
}

void Map::update(RenderWindow& target)
{
}

void Map::render(RenderWindow& target,char key)
{
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			char ch = j * 5 + i + 65;
			vertex.setPosition({ i * 160.f +50.f,j * 160.f });
			text.setString(ch);
			text.setPosition({ i * 160.f + 50.f,j * 160.f-15.f });

				
			horEdge.setPosition({ i * 160.f + 50.f ,j * 160.f + 40.f - 20.f });
			vertEdge.setPosition({ i * 160.f + 30.f + 40,j * 160.f });

			if (ch == 'Y') {
				vertex.setFillColor(Color::Black);
			}
			else {
				vertex.setFillColor(Color::Yellow);
			}

			if (j < 4) {
				target.draw(vertEdge);
			}
			if (i < 4) {
				target.draw(horEdge);
			}
			if (ch != key) {
				target.draw(vertex);
				target.draw(text);
			}
			
			
		}
	}
}