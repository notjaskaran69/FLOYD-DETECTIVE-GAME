#include "Game.h"
#include <time.h>


void Game::initWindow()
{
	this->videomode.width = 1200;
	this->videomode.height = 800;;
	this->window = new RenderWindow(this -> videomode, "MST", Style::Titlebar | Style::Close | Style::Resize);
	this->window->setFramerateLimit(144);
}

void Game::initVariable()
{
	this->count = 0;
	this->direction = func.direction(1);
	if (direction == 2) {
		location = 'B';
	}
	else {
		location = 'F';
	}
	this->distance = this->func.printDist('A', location);
	this->speed = 11 - distance;
	this->speed /= 10;
	this->totalDistance += distance;

	this->font.loadFromFile("Fonts/Roboto-Light.ttf");

	this->text.setFont(font);
	this->text.setString("Distance: ");
	this->text.setPosition({ 750.f,40.f });
	this->text.setCharacterSize(50.f);
	this->text.setFillColor(Color::Blue);

	this->instruct.setFont(font);
	this->instruct.setString("SELECT A KEY");
	this->instruct.setPosition({ 750.f,200.f });
	this->instruct.setCharacterSize(50.f);
	this->instruct.setFillColor(Color::Blue);

	this->dist.setFont(font);
	this->dist.setString("");
	this->dist.setPosition({ 750.f,600.f});
	this->dist.setCharacterSize(50.f);
	this->dist.setFillColor(Color::Blue);
	
}

Game::Game()
{
	this->initWindow();
	this->initVariable();
}

Game::~Game()
{
}

void Game::updateDir()
{
	if (location == 'B') {
		int x = rand() % 2;
		if (x == 0) {
			direction = 2;
		}
		else {
			direction = 3;
		}
	}
}

bool Game::isOpen()
{
	return window->isOpen();
}

void Game::pollEvent()
{
	while (window->pollEvent(ev)) {
		if (ev.type == Event::Closed) {
			window->close();
		}

		if (this->pause) {
			if (ev.type == Event::KeyPressed) {
				int x = ev.key.code;
				if (x <= 26) {
					key = 'A' + ev.key.code;
					for (int i = 0;i < this->sp;i++) {
						if (this->selectionQueue[i] == key) {
							ready = false;
							break;
						}
						else {
							ready = true;
						}
					}
					if (sp < 1  && ready) {
						this->selectionQueue[++sp] = key;
						sp = sp % 2;
					}
				}
				else {
					if (x > 70 && x < 75 && ready) {
						this->func.change(key, x - 70);
						this->func.calcDist();
						this->update();
						this->pause = false;
					}
				}
			}
		}
	}
}

void Game::update()
{
	if (!this->pause) {
		timer++;

		this->car.update(this->direction, speed);
		distance += speed;
		float dist = func.dist(location - 'A' + 1, this->direction);
		if (distance >= 160) {
			count++;
			if (count % 2 == 0) {
				this->pause = true;
				srand(time(0));
				int num = rand() % 25;
				char x = 'A'+num;
				int newDir = rand() % 4 + 1;
				if (num > 20) {
					newDir = rand() % 3 + 1;
				}
				if (newDir == 1) {
					newDir = num - 1;
				}
				else if (newDir == 2) {
					newDir = num + 1;
				}
				else if (newDir == 3) {
					newDir = num - 5;
				}
				else {
					newDir = num + 5;
				}
				if ((num - 1) % 5 == 0) {
					newDir = num + 1;
				}
				else if (num % 5 == 0) {
					newDir = num - 1;
				}
				if (num < 5) {
					newDir = num + 5;
				}
				if (num - 1 == newDir) {
					newDir = num + 1;
				}
				char Dir = 'A' + newDir;
				string ans = string(1, x) + " ->" + string(1,Dir)+": ";
				string value = to_string(this->func.printDist(x,Dir));
				ans.append(value);
				this->dist.setString(ans);
				//cout << ans;
			}
			distance = 0;
			this->direction = func.direction(location - 'A' + 1);
			char x = location;
			if (direction == 1) {
				location -= 1;
			}
			else if (direction == 2) {
				location += 1;
			}
			else if (direction == 3) {
				location -= 5;
			}
			else if (direction == 4) {
				location += 5;
			}
			else {
				speed = 0;
			}
			//cout << x << "-> " << location << ": " << func.printDist(x, location);
			this->distance = this->func.printDist(x, location);
			this->speed = 11 - distance;
			this->speed /= 10;
			if (x == 'Y') {
				speed = 0;
				this->end = true;
			}
			//cout << "S: " << speed << endl;
			string ans = to_string(this->totalDistance);
			string s = "Distance: ";
			s = s.append(ans);
			this->text.setString(s);
			this->totalDistance += distance;

		}
		if (end) {
			this->text.setPosition({ 400.f,250.f });
			string ans = to_string(this->totalDistance-this->func.printDist('A','Y'));
			string s = "Score: ";
			s = s.append(ans);
			this->text.setString(s);
		}
	}

	this->pollEvent();
	this->map.update(*window);
}

void Game::render()
{	
	if (!end) {
		this->window->draw(this->instruct);
		this->window->clear(Color::Green);
		this->map.render(*window, key);
		this->car.render(*window);
		this->window->draw(this->dist);
	}
	else {
		this->window->clear(Color::White);
	}
	this->window->draw(this->text);
	this->window->display();
}