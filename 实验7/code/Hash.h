#pragma once
#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
struct student
{
	string name;
	string sex;      
	string id;
	string phone;
	student(){}
	student(string a, string b, string c, string d) {
		name = a;
		sex = b;
		id = c;
		phone = d;
	}
};

class Hash
{
public:
	Hash();
	bool find(string a,bool p=true);
	void insert(student a);
	void dele(string a);
	void display();
	~Hash();
private:
	void print(student a);
	vector<list<student>> sto;
};

