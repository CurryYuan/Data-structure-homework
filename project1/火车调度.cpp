// ConsoleApplication59.cpp : 定义控制台应用程序的入口点。
//

#include <string>
#include <stack>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

vector<stack<int>> temp; //列车的暂存区？ 
vector<int> res;
int j = 1; // j 是指 头车厢 
int most_big_size = 0;
int path = 0;

bool check(int a);
bool out(int a);



int main()
{
	vector<int> s; // 用来存一列随机序的火车 
	cout << "请输入车厢总节数： " << endl;
	int n;
	cin >> n;
	cout << "请输入车厢顺序（每节车厢号以空格间隔）" << endl;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s.push_back(x);
	}
		
	cout << "-----------------------------------------------" << endl;
	
	for (int i = 0; i < s.size(); ++i) {
		if (out(s[i]))
			continue;
		if (temp.size() == 0 || check(s[i])) {
			stack<int> a;
			a.push(s[i]);
			temp.push_back(a);
			if(most_big_size < temp.size()) most_big_size = temp.size();
			cout <<"车厢 "<<left<<setw(2)<<s[i]<<" 放入  "<< "隧道 " << setw(2) << temp.size()<<"（新开）" << endl;
			path++;
		}
	}

	cout << "-----------------------------------------------" << endl;
	cout << "结果：";
	for (auto c : res)
		cout <<setw(3)<< c;
	cout << endl;
	cout << "使用的最少隧道数为： " << most_big_size << endl; 
	cout << "步骤数一共是： " << path << endl;
    return 0;
}

bool check(int a)//把车厢放入隧道 
{
	for (int i = 0; i < temp.size(); ++i) {
		if (!temp[i].empty()&&a < temp[i].top()) {
			temp[i].push(a);
			cout << "车厢 " << setw(2) << a << " 放入  隧道 " << setw(2) << i+1 << endl;
			++path;
			return false;
		}
	}
	for (int i = 0; i < temp.size(); ++i) {
		if (temp[i].empty()) {
			temp[i].push(a); 
			cout << "车厢 " << setw(2) << a << " 放入  隧道 " << setw(2) << i+1 << endl;
			++path;
			return false;
		}
	}
	return true;
}

bool out(int a) //用来把车厢放出 
{
	if (a == j) {
		res.push_back(a);
		++j;
		cout << "车厢 " << left<< setw(2) << a << " 开出         （直接）" << endl; //指车厢直接从原列车开走 不需要进入隧道 
		++path;
		out(a);
		return true;
	}
	for (int i = 0; i < temp.size(); ++i) {
		if (!temp[i].empty()&&temp[i].top() == j) {
			temp[i].pop();
			res.push_back(j);
			cout << "车厢 " << left<< setw(2) << j << " 开出  隧道 " << setw(2) << i + 1 << endl;
			++j;
			++path;
			out(a);
		}
	}
	return false;
}
