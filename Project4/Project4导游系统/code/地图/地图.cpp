// 地图.cpp: 定义控制台应用程序的入口点。

#include <vector>
#include <iostream>
#include "Map.h"
using namespace std;

Map che;			 //乘车
Map zou;			 //步行

void car()
{
	string x, y;
	cout << "请输入起点和终点" << endl;
	cin >> x >> y;
	int a = che.find(x);
	int b = che.find(y);
	if (a == -1) {
		cout << "景点 " << x << " 不存在" << endl;
	}
	if (b == -1) {
		cout << "景点 " << y << " 不存在" << endl;
	}
	if (a == -1 || b == -1)
		return;
	if (a == b) {
		cout << "起点和终点不能相同" << endl;
		return;
	}

	int n = che.lists.size();
	vector<string> path(n);
	vector<int> dis(n);
	che.shortest(path, dis, x, y);
	if (dis[b] != INT_MAX) {
		cout << x << " 到 " + y + " 的距离为：" << dis[b] << endl;
		cout << x << " 到 " + y + " 的路径为：" << path[b] << endl;
		return;
	}
	else {
		vector<string> path1(n);
		vector<int> dis1(n);
		zou.shortest(path1, dis1, y, x);
		vector<int> dis2(n);
		for (int i = 0; i < n; ++i) {
			if (dis[i] == INT_MAX || dis1[i] == INT_MAX) {
				dis2[i] = INT_MAX;
			}
			else {
				dis2[i] = dis[i] + dis1[i];
			}
		}
		int longest = -1;
		int small = INT_MAX;
		for (int i = 0; i < n; ++i) {
			if (dis2[i] < small)
				longest = i;
		}
		vector<string> path2(n);
		vector<int> dis3(n);
		zou.shortest(path2, dis3, zou.lists[longest].name, y);
		cout << x << " 到 " + y + " 不能乘车直达，以下是中转方案" << endl;
		cout << "乘车路线： " << path[longest] << endl;
		cout << "步行路线： " << path2[zou.find(y)] << endl;
		cout << x << " 到 " + y + " 的距离为：" << dis2[longest] << endl;
	}

}

int main()
{

	che.store("乘车地图信息.txt");
	zou.store("步行地图信息.txt");
	while (true) {
		cout << "中山大学校园导游系统" << endl
			<< "【1】查询步行路线" << endl
			<< "【2】查询乘车路线" << endl
			<< "【3】查询景点详情" << endl
			<< "【4】查询最短路径" << endl
			<< "【5】退出" << endl;

		int x;
		cin >> x;
		system("cls");
		switch (x)
		{
		case 1:
			zou.printAll();
			system("pause");
			system("cls");
			break;
		case 2:
			zou.printCar();
			system("pause");
			system("cls");
			break;
		case 3:
			zou.search();
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "请输入交通方式" << endl
				<< "【1】乘车" << endl
				<< "【2】步行" << endl;
			int y;
			cin >> y;

			switch (y)
			{
			case 1:
				car();
				break;
			case 2:
				zou.walk();
				break;
			default:
				break;
			}
			system("pause");
			system("cls");
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}
    return 0;
}
