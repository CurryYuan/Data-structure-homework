#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <list>
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
	list<node> tail;
	head(string a) {
		name = a;
	}
};

class Graph {
public:
	Graph();
	void matrixStore();
	void listStore();
	void matrixDfs();
	void matrixBfs();
	void listsDfs();
	void listsBfs();
	void matrixShortest();
	void listsShortest();
private:
	int findSmallest(vector<int> dis, vector<int> visit);
	void dfs(int i, bool*& visit);
	void dfs1(int i, bool*& visit);
	int find(string a);
	int find1(string a);
	vector<string> point;
	int** matrix;
	vector<head> lists;
};