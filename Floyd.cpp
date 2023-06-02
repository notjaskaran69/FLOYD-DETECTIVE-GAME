#include "Floyd.h"

void Floyd::initGraph()

{
	int num1,num2,num3,num4;
	srand(time(0));
	for (int i = 1; i < 25; i++) {
		num1 = rand() % 10 + 1;
		num2 = rand() % 10 + 1;
		num3 = rand() % 10 + 1;
		num4 = rand() % 10 + 1;
		if (i % 5 == 0 && i !=25) {
			graph[i][i + 5] = num1;
			graph[i + 5][i] = num2;
		}
		else if (i > 20 && i != 25) {
			graph[i][i + 1] = num3;
			graph[i + 1][i] = num4;
		}
		else {
			graph[i][i + 5] = num1;
			graph[i + 5][i] = num2;
			graph[i][i + 1] = num3;
			graph[i + 1][i] = num4;
		}
	}
	
	for (int i = 0;i < 26;i++) {
		for (int j = 0;j < 26;j++) {
			if (graph[i][j] == 0 && i !=j) {
				graph[i][j] = INF;
				distance[i][j] = INF;
			}
		}
	}
}

Floyd::Floyd()
{
	initGraph();
	calcDist();
	print();
}

Floyd::~Floyd()
{
}

int Floyd::direction(int X)
{
	if (X  == 5) {
		//cout << "E";
		if (distance[X - 1][25] + distance[X][X-1] < distance[X + 5][25] + distance[X][X + 5]) {
			return 1;
		}
		else {
			return 4;
		}
	}
	else if (X == 25) {
		return 0;
		//cout << "Y";
	}
	else if (X == 1) {
		if (distance[X + 1][25] + distance[X][X + 1] < distance[X + 5][25] + distance[X][X + 5]) {
			return 2;
		}
		else {
			return 4;
		}

	}
	else if (X == 21) {
		if (distance[X + 1][25] + distance[X][X + 1] < distance[X - 5][25] + distance[X][X - 5]) {
			return 2;
		}
		else {
			return 3;
		}
	}
	else if (X ==2 || X==3|| X==4) {
		//cout << "1to 5";
		if (distance[X + 1][25]+distance[X][X+1] < distance[X + 5][25] + distance[X][X +5] && distance[X + 1][25] + distance[X][X + 1] < distance[X - 1][25] + distance[X][X - 1]) {
			return 2;
		}
		else if(distance[X - 1][25] + distance[X][X - 1] < distance[X + 5][25] + distance[X][X +  5] && distance[X - 1][25] + distance[X][X - 1] < distance[X + 1][25] + distance[X][X + 1]){
			return 1;
		}
		else {
			return 4;
		}
	}
	else if (X==22||X==23||X==24) {
		//cout << "U to x";
		if (distance[X + 1][25] + distance[X][X + 1] < distance[X - 5][25] + distance[X][X - 5] && distance[X + 1][25] + distance[X][X + 1] < distance[X - 1][25] + distance[X][X - 1]) {
			return 2;
		}
		else if (distance[X - 1][25] + distance[X][X - 1] < distance[X - 5][25] + distance[X][X - 5] && distance[X - 1][25] + distance[X][X - 1] < distance[X + 1][25] + distance[X][X + 1]) {
			return 1;
		}
		else {
			return 3;
		}
	}
	else if (X==6 || X==11||X==16){
		//cout << "f k p u";
		if (distance[X + 5][25] + distance[X][X + 5] < distance[X + 1][25]+ distance[X][X + 1] && distance[X + 5][25] + distance[X][X + 5] < distance[X - 5][25] + distance[X][X -5]) {
			return 4;
		}
		else if (distance[X + 1][25] + distance[X][X + 1] < distance[X - 5][25]+ distance[X][X - 5] && distance[X + 1][25] + distance[X][X + 1] < distance[X + 5][25] + distance[X][X + 5]) {
			return 2;
		}
		return 3;

	}
	else if (X % 5 == 0) {
		//cout << "E to bottom";
		if (distance[X + 5][25] + distance[X][X + 5] < distance[X - 1][25] + distance[X][X - 1] && distance[X + 5][25] + distance[X][X + 5] < distance[X - 5][25] + distance[X][X - 5]) {
			return 4;
		}
		if (distance[X - 1][25] + distance[X][X - 1] < distance[X + 5][25] + distance[X][X + 5] && distance[X - 1][25] + distance[X][X - 1] < distance[X - 5][25] + distance[X][X - 5]){
			return 1;
		}
		return 3;
	}
	else {
		//cout << "middle";
		if (distance[X + 5][25] + distance[X][X + 5] < distance[X - 1][25] + +distance[X][X - 1] && distance[X + 5][25] + distance[X][X + 5] < distance[X - 5][25] + distance[X][X - 5] && distance[X + 5][25] + distance[X][X + 5] < distance[X + 1][25]+distance[X][X + 1]) {
			return 4;
		}
		if (distance[X - 1][25] + distance[X][X - 1] < distance[X - 5][25] + distance[X][X - 5] && distance[X -1][25] + distance[X][X - 1] < distance[X + 1][25] + distance[X][X + 1]) {
			return 1;
		}
		if (distance[X + 1][25] + distance[X][X + 1] > distance[X - 5][25] + distance[X][X - 5]) {
			return 3;
		}
		return 2;

	}

}

void Floyd::print()
{	
	for (int i = 1;i < 26;i++) {
		char ch = 'A' + i-1;
		cout << ch<<": ";
		for (int j = 1;j < 26;j++) {
			if (distance[i][j] == INF) {
				cout << "I ";
			}
			else {
				cout << distance[i][j] << " ";
			}
			
		}
		cout << "\n";
	}
}

int Floyd::dist(int X, int direction)
{
	if (direction == 1) {
		return distance[X][X - 1];
	}
	if (direction == 2) {
		return distance[X][X + 1];
	}
	if (direction == 3) {
		return distance[X][X - 5];
	}
	else {
		return distance[X][X + 5];
	}
}

void Floyd::calcDist()
{
	for (int k = 0;k < 26;k++) {
		for (int i = 1;i < 26;i++) {
			for (int j = 1;j < 26;j++) {
				if (k == 0) {
					distance[i][j] = graph[i][j];
				}
				else if (distance[i][j] > distance[i][k] + distance[k][j]) {
					distance[i][j] = distance[i][k] + distance[k][j];
				}
			}
		}
	}
	//this->print();
}

void Floyd::change(char x,int dir)
{
	//cout << "Direction- " << dir << endl;
	int X = x - 'A' + 1;
	graph[pos[0]][pos[1]] = value;
	pos[0] = X;
	if (dir == 1 && (X - 1) % 5 != 0) {
		pos[1] = X - 1;
		value = graph[X][X - 1];
		graph[X][X - 1] = INF;
	}
	else if (dir == 2 && X % 5 != 0) {
		pos[1] = X + 1;
		//cout << X <<" "<< X + 1;
		value = graph[X][X + 1];
		graph[X][X + 1] = INF;
	}
	else if (dir == 3 && X > 5) {
		pos[1] = X - 5;
		//cout << X << " " << X - 5;
		value = graph[X][X - 5];
		graph[X][X - 5] = INF;
	}
	else if(dir == 4 && X<21){
		pos[1] = X + 5;
		//cout << X << " " << X + 5;
		value = graph[X][X + 5];
		graph[X][X + 5] = INF;
	}
}

int Floyd::printDist(char x, char y)
{
	return distance[x - 'A' + 1][y - 'A' + 1];
}