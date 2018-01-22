#pragma once
#include <iostream>
using namespace std;

class Array{
public:
	Array(int max) {
		max_size = max;
		entry = new char[max];
		size = 0;
	}
	~Array() {
		delete[] entry;
	}
	bool insert(char a,int p) {
		if (size >= max_size||p<0||p>size)
			return false;
		for (int i = size-1; i >p; --i) {
			entry[i] = entry[i-1];
		}
		entry[p] = a;
		++size;
		return true;
	}
	bool del(int p) {
		if (p < 0 || p >= size)
			return false;
		for (int i = p; i < size - 1; ++i)
			entry[i] = entry[i + 1];
		--size;
		return true;
	}

	void display() {
		cout << "Array: ";
		for (int i = 0; i < size; ++i) {
			cout << entry[i] << " ";
		}
		cout << endl;
	}
private:
	char* entry;
	int size;
	int max_size;
};