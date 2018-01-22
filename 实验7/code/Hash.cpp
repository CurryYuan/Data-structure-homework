#include "Hash.h"

Hash::Hash()
{
	sto.resize(200);
	ifstream in("name.txt", ios::in);
	string a, b, c, d, e;
	while (in >> a >> b >> c >> d >> e) {
		a = a + " " + b;
		if (!find(a, false))
			insert(student(a, c, d, e));
	}
}

bool Hash::find(string a,bool p)
{
	int x = 0;
	for (auto f : a) {
		x += f;
	}
	x %= 200;
	int y = 0;
	for (auto c : sto[x]) {
		++y;
		if (c.name == a) {
			if (p) {
				cout << "查找成功。查找次数： " << y << " 次" << endl;
				print(c);
			}
			return true;
		}
	}
	if (p)
		cout << "查找失败。查找次数： " << y << " 次" << endl;
	return false;
}


void Hash::insert(student a)
{
	int x = 0;
	for (auto f : a.name) {
		x += f;
	}
	x %= 200;
	sto[x].push_back(a);
}

void Hash::print(student a)
{
	cout << "Student Information" << endl
		<< "Name: " << a.name << endl
		<< "Sex: " << a.sex << endl
		<< "Id: " << a.id << endl
		<< "Phone: " << a.phone << endl;
}

void Hash::dele(string a)
{
	int x = 0;
	for (auto f : a) {
		x += f;
	}
	x %= 200;
	for (auto c=sto[x].begin();c!=sto[x].end();++c) {
		if (c->name == a) {
			sto[x].erase(c);
			cout << "删除成功" << endl;
			return;
		}
	}
	cout << "删除失败，学生不存在" << endl;
}

void Hash::display()
{
	cout << setw(15) << "Hash Table" << endl;
	cout << setw(20) << left << "key" << "Address" << endl;
	for (int i = 0; i < 200;++i) {
		for (auto d : sto[i]) {
			cout <<setw(20)<<left<< d.name  << i << endl;
		}
	}
}

Hash::~Hash()
{
	ofstream out("name.txt", ios::out);
	for (auto c : sto) {
		for (auto d : c) {
			out << d.name << " " << d.sex << " " << d.id << " " << d.phone << "\n";
		}
	}
}
