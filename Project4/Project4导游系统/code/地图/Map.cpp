#include "Map.h"

Map::Map()
{
}

void Map::store(string f)
{
	fstream file;
	int n;
	string x, y;
	file.open(f, ios::in | ios::out);
	file >> n;
	for (int i = 0; i < n; ++i) {
		file >> x;
		file >> y;
		lists.push_back(head(x, y));
	}
	int m;
	file >> m;
	for (int i = 0; i<m; ++i) {
		file >> x >> y >> n;
		int a = find(x);
		int b = find(y);
		lists[a].tail.push_back(node(b, n));
		lists[b].tail.push_back(node(a, n));
	}
	file.close();
}

void Map::shortest(vector<string>& path,vector<int>& dis,string x,string y)
{
	int n = lists.size();
	int a = find(x);
	int b = find(y);
	vector<int> visit(n);
	for (int i = 0; i < n; ++i) {
		visit[i] = false;
		dis[i] = INT_MAX;
		path[i] = x + " --> " + lists[i].name;
	}
	dis[a] = 0;
	for (auto c : lists[a].tail) {
		dis[c.num] = c.val;
	}
	visit[a] = true;
	while (true) {
		int s = findSmallest(dis, visit);
		if (s <= 0)
			break;
		visit[s] = true;
		for (auto c : lists[s].tail) {
			if (c.val <= 0)
				continue;
			if (c.val + dis[s] < dis[c.num]) {
				dis[c.num] = c.val + dis[s];
				path[c.num] = path[s] + " --> " + lists[c.num].name;
			}
		}
	}
	
}

void Map::walk()
{
	string x, y;
	cout << "请输入起点和终点" << endl;
	cin >> x >> y;
	int a = find(x);
	int b = find(y);
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
	int n = lists.size();
	vector<string> path(n);
	vector<int> dis(n);
	shortest(path, dis, x, y);

	cout << x << " 到 " + y + " 的距离为：" << dis[b] << endl;
	cout << x << " 到 " + y + " 的路径为：" << path[b] << endl;
}

void Map::search()
{
	string a;
	cout << "请输入景点名称" << endl;
	cin >> a;
	if (find(a) == -1) {
		cout << "景点不存在" << endl;
		return;
	}
	auto temp = lists[find(a)];
	cout << "景点简介" << endl;
	cout << temp.infor << endl;
}

void Map::printAll()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                                       北门                                        " << endl;
	cout << "                                       /|\\										" << endl;
	cout << "                                    2 / | \\2										" << endl;
	cout << "                                     /  |  \\										" << endl;
	cout << "                    北学院楼  ―――/   |   \\―――― 公教楼 			           " << endl;
	cout << "                  ／                    |              /							" << endl;
	cout << "                2／                     |4            /			  							" << endl;
	cout << "                ／                      |            /2					" << endl;
	cout << "               ／                       |           /								" << endl;
	cout << "              环院                    图书馆 ―――/								" << endl;
	cout << "             ／   \\                    | \\											" << endl;
	cout << "           1／     \\1                  |  \\ 2     							" << endl;
	cout << "           ／       \\                  |   \\      						" << endl;
	cout << "   	 实验中心    传设院            |2   \\											" << endl;
	cout << "                       \\               |    真草															" << endl;
	cout << "                        \\ 2            |           															" << endl;
	cout << "                        假草           |     							" << endl;
	cout << "                                       南门										" << endl;
	cout << "                                       / \\											" << endl;
	cout << "                                     2/   \\2										" << endl;
	cout << "                                     /     \\										" << endl;
	cout << "                 5         2        /   1   \\		1								" << endl;
	cout << "      大学城北 ―――西门 ―――明德园 ――新天地 ―――贝岗									" << endl;
	cout << "                      |            |           |											" << endl;
	cout << "                      |            |1          |1												" << endl;
	cout << "                      |            |           |													" << endl;
	cout << "                      |     1      |     1     |												" << endl;
	cout << "                  格致园 ――――一饭 ―――至善园										" << endl;
	cout << "                                   |       /   |				" << endl;
	cout << "                                   |1     /    |						" << endl;
	cout << "                                   |     /1    |1		" << endl;
	cout << "                                   |    /      |							" << endl;
	cout << "                                   |   / 1     |								" << endl;
	cout << "                                   四饭 ――慎思园				        " << endl;
	cout << "                                       											" << endl;
	cout << "                                									" << endl;
	cout << "																					" << endl;
	cout << endl;
}

void Map::printCar()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                                       北门                                        " << endl;
	cout << "                                       /|\\										" << endl;
	cout << "                                    2 / | \\2										" << endl;
	cout << "                                     /  |  \\										" << endl;
	cout << "                    北实验楼  ―――/   |   \\―――― 公教楼 			            " << endl;
	cout << "                  ／                    |											" << endl;
	cout << "                2／                     |										" << endl;
	cout << "                ／                    图书馆									" << endl;
	cout << "               ／																	" << endl;
	cout << "              环院																" << endl;
	cout << "             ／																	" << endl;
	cout << "           1／             。                          。							" << endl;
	cout << "           ／               传设院                      真草						" << endl;
	cout << "   	 实验中学																	" << endl;
	cout << "																					" << endl;
	cout << "                           。															" << endl;
	cout << "                            假草													" << endl;
	cout << "                                      南门										" << endl;
	cout << "                                       / \\											" << endl;
	cout << "                                     2/   \\2										" << endl;
	cout << "                                     /     \\										" << endl;
	cout << "                                    /       \\										" << endl;
	cout << "                      西门 ―――明德园	新天地									" << endl;
	cout << "                      /															" << endl;
	cout << "                     /																" << endl;
	cout << "                    /																" << endl;
	cout << "                北实验楼															" << endl;
	cout << "																					" << endl;
	cout << "                    。   		     。													" << endl;
	cout << "                     格致园                   一饭											" << endl;
	cout << "                                                  。至善园						" << endl;
	cout << "                                    。												" << endl;
	cout << "                                      四饭											" << endl;
	cout << "																					" << endl;
	cout << "                                         。											" << endl;
	cout << "                                          慎思园									" << endl;
	cout << "																					" << endl;
	cout << endl;
}


int Map::find(string a)
{
	for (int i = 0; i < lists.size(); ++i) {
		if (a == lists[i].name)
			return i;
	}
	return -1;
}

int Map::findSmallest(vector<int> dis, vector<int> visit) {
	int a = -1;
	int temp = INT_MAX;
	for (int i = 0; i < dis.size(); ++i) {
		if (dis[i] <= 0 || visit[i])
			continue;
		if (dis[i] < temp) {
			a = i;
			temp = dis[i];
		}
	}
	return a;
}

Map::~Map()
{
}
