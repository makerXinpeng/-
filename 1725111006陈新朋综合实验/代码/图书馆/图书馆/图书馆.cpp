// 图书馆.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
#include "AVLTree.h"

void printHelp(Node* p, string ss)
{
	if (p == NULL)
		return;
	ss += "         ";
	printHelp(p->rchild, ss);
	cout << ss << p->booknum << " " << p->stillhave<< " " << p->total<< endl;
	printHelp(p->lchild, ss);
}
 
void print(Node*p)
{
	string ss = "";
	printHelp(p, ss);
}

int main()
{
	char cmd;
	AVLTree avl;
	Node temp;
	time_t now;

	string bor;
	string IDnum;
	string booknum;
	ifstream in("init_input.txt");
	while (1)
	{
		in >> temp.booknum;
		if (temp.booknum == "#")
			break;
		in >> temp.bookname >> temp.author >> temp.stillhave >> temp.total;
		avl.Insert(temp);
	}
	in.close();

	ifstream inn("borrowmsg.txt");
	while (!inn.eof())
	{
		inn >> IDnum;
		avl.Insertber(IDnum);
	}
	inn.close();
	while (1)
	{
		cout << "N：图书入库  B:借书  R:还书  Q：退出  S：凹入表打印现有书号:";
		cin >> cmd;
		if (cmd == 'Q')
			break;
		else if (cmd == 'B')
		{
			cout << "请输入借阅ID、书号：" << endl;
			cin >> IDnum >> booknum ;
			avl.borrowbook(IDnum, booknum, (int)time(&now), (int)time(&now)+3600*24);
		}
		else if (cmd == 'R')
		{
			cout << "请输入借阅ID、书号：" << endl;
			cin >> IDnum >> booknum;
			avl.returnbook(IDnum, booknum);
		}
		else if (cmd == 'S')
			print(avl.header->lchild);
			//avl.print();//中序遍历打印
		else if (cmd == 'N')
		{
			int i,n;
			ofstream out("init_input.txt",ios::app);
			cout << "输入想要添加的书的种类数量:";
			cin >> n;
			cout << "输入数据:书号、书名、作者、现存量、库存量";
			for (i = 0; i < n; i++)
			{
				cin >> temp.booknum >> temp.bookname >> temp.author >> temp.stillhave>> temp.total;
				out << temp.booknum << ' ' << temp.bookname << ' ' << temp.author << ' ' << temp.stillhave << ' ' << temp.total << ' ' << endl;
				avl.Insert(temp);
			}
			out.close();
		}
	}
	return 0;
}
