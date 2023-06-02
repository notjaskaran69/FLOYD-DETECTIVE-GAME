#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include <time.h>
using namespace std;
class Floyd
{ 
	int graph[26][26];
	int INF = 1e9;
	int distance[27][27];

	vector<int> pos = { 0,0 };
	int value = INF;

	void initGraph();
public:
	Floyd();
	virtual ~Floyd();
	int direction(int X);
	void print();
	int dist(int X, int direction);
	void calcDist();
	void change(char X,int dir);
	int printDist(char x, char y);
};
