#pragma once
#include<unordered_map>
#include<string.h>
#include<vector>
using namespace std;

class Graph
{
	unordered_map<int, string>temp;
	unordered_map<string, int>town;
	vector<pair<int,int>>v[1005];
	int num_of_towns = 0;
	int distance[105][105];
	int prev[105][105];
	int mn1[100][100];
	int OO = 0x3f3f3f3f;
    public:
	Graph();
	void AddTown(string);
	void AddWay(string, string, int);
	void update(string,string,int);
	void display();
	void Delete(string);
	void Shortest_Path(string , string);
	void generate_dis();
	void Path(int,int);
	~Graph();
};

