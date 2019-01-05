#include "stdafx.h"
#include "Huffman.h"
#include <string>

void huffman::select(Node T[], int n, int &min, int &sub)
{
	int i;
	for (i = 0; i<n&&T[i].parent!=NULL; i++){}
	min = i;
	for (i = 0; i < n; i++)
	{
		if (T[i].parent != NULL)
			continue;
		else if (T[min].weight>T[i].weight)
			min = i;
	}
	T[min].parent = &T[n];

	for (i = 0; i<n&&T[i].parent!=NULL; i++){}
	sub = i;
	for (i = 0; i < n; i++)
	{
		if (T[i].parent !=NULL)
			continue;
		else if (T[min].weight>T[i].weight)
			sub = i;
	}
	T[sub].parent = &T[n];
}

void huffman::init()
{
	cout << "请输入想要加入的节点个数：";
	int i;
	cin >> NodeNum;
	if (NodeNum <= 0)
		cout << "输入错误" << endl;
	else
	{
		Node *temp = new Node[2* NodeNum -1];
		cout << "输入n次（节点字符，节点权重）";
		for (i = 0; i < NodeNum; i++)
			cin >> temp[i].ch >> temp[i].weight;
		for (i = NodeNum; i < 2 * NodeNum - 1; i++)
		{
			int s1, s2;
			select(temp, i, s1, s2);
			temp[i].lchild = &temp[s1];
			temp[i].rchild = &temp[s2];
			temp[i].weight = temp[s1].weight + temp[s2].weight;
		}
		header = &temp[i - 1];
	}
}
void CreatHuffmanCode()
{
	
}
void huffman::printHelp(Node* p, string ss)
{
	if (p == NULL)
		return;
	ss += "   ";
	printHelp(p->rchild, ss);
	cout << ss <<p->weight << endl;
	printHelp(p->lchild, ss);
}
void huffman::print()
{
	string ss = "  ";
	printHelp(header, ss);
}
