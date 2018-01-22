#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <list>
#include <fstream>
using namespace std;

struct node {
	int num;
	int val;
	node(int a, int b) {
		num = a;
		val = b;
	}
};

struct head {
	string name;
	string infor;
	list<node> tail;
	head(string a,string b) {
		name = a;
		infor = b;
	}
};

class Map
{
public:
	Map();
	void store(string f);
	void shortest(vector<string>& path, vector<int>& dis, string x, string y);
	void walk();
	void search();
	void printAll();
	void printCar();
	int findSmallest(vector<int> dis, vector<int> visit);
	int find(string a);
	~Map();

	vector<head> lists;
};

