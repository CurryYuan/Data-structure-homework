// experiment2.cpp : 定义控制台应用程序的入口点。
//
#include "Stack.h"
#include "Quene.h"
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
	cout << "1----建立堆栈" << endl;
	cout << "2----建立队列" << endl;
	string s;
	cin >> s;
	system("pause");
	system("cls");
	if (s == "1") {
		Stack st;
		while (true) {
			cout << "1----入栈" << endl;
			cout << "2----出栈" << endl;
			cout << "3----退出" << endl;
			cin >> s;
			if (s == "1") {
				cout << "请输入要入栈的字符: " << endl;
				char a;
				cin >> a;
				if (st.push(a))
					cout << "入栈成功" << endl;
				else
					cout << "入栈失败" << endl;
				st.display();
			}
			else if (s == "2") {
				if (st.pop())
					cout << "出栈成功" << endl;
				else
					cout << "出栈失败" << endl;
				st.display();
			}
			else if(s=="3")
				break;
			else {
				cout << "错误指令，请重新输入" << endl;
			}
			system("pause");
			system("cls");
		}
		
	}
	else if (s == "2") {
		Quene qu;
		while (true) {
			cout << "1----入队" << endl;
			cout << "2----出队" << endl;
			cout << "3----退出" << endl;
			cin >> s;
			if (s == "1") {
				cout << "请输入要入队的字符: " << endl;
				char a;
				cin >> a;
				if (qu.append(a))
					cout << "入队成功" << endl;
				else
					cout << "入队失败" << endl;
				qu.display();
			}
			else if (s == "2") {
				if (qu.pop())
					cout << "出队成功" << endl;
				else
					cout << "出队失败" << endl;
				qu.display();
			}
			else if (s == "3")
				break;
			else {
				cout << "错误指令，请重新输入" << endl;
			}
			system("pause");
			system("cls");
		}
	}
	else {
		cout << "指令错误" << endl;
	}
    return 0;
}

