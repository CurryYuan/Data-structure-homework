#include "graph.h"

int main() {
	Graph a;
	while (true) {
		cout << "关于图的小实验" << endl;
		cout << "【1】邻接矩阵储存" << endl;
		cout << "【2】邻接表储存" << endl;
		cout << "【3】邻接矩阵深度优先搜索" << endl;
		cout << "【4】邻接矩阵广度优先搜索" << endl;
		cout << "【5】邻接矩阵最短路径" << endl;
		cout << "【6】邻接表深度优先搜索" << endl;
		cout << "【7】邻接表广度优先搜索" << endl;
		cout << "【8】邻接表最短路径" << endl;
		cout << "【9】退出" << endl;
		int x;
		cin >> x;
		system("cls");
		switch (x)
		{
		case 1:
			a.matrixStore();
			system("pause");
			system("cls");
			break;
		case 2:
			a.listStore();
			system("pause");
			system("cls");
			break;
		case 3:
			a.matrixDfs();
			system("pause");
			system("cls");
			break;
		case 4:
			a.matrixBfs();
			system("pause");
			system("cls");
			break;
		case 5:
			a.matrixShortest();
			system("pause");
			system("cls");
			break;
		case 6:
			a.listsDfs();
			system("pause");
			system("cls");
			break;
		case 7:
			a.listsBfs();
			system("pause");
			system("cls");
			break;
		case 8:
			a.listsShortest();
			system("pause");
			system("cls");
			break;
		case 9:
			return 0;
		default:
			break;
		}
	}
	
}