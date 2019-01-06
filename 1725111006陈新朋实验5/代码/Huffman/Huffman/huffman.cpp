#include "stdafx.h"
#include "Huffman.h"
#include <string>
#include <fstream>

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
		else if (T[sub].weight>T[i].weight&&i!=min)
			sub = i;
	}
	T[sub].parent = &T[n];
}

void huffman::init()
{
	int cmd, i;
	cout << "请选择初始化方式：1.新建一个哈夫曼树  2.从文件中读取" << endl;
	cin >> cmd;
	if (cmd != 1 && cmd != 2)
		cout << "输入有误";
	else if (cmd == 1)
	{
		cout << "请输入想要加入的节点个数：";
		cin >> NodeNum;
		if (NodeNum <= 0)
			cout << "输入错误" << endl;
		else//新建一个霍夫曼树
		{
			fstream out("hfmTree.txt");
			out << NodeNum << endl;

			Node *temp = new Node[2 * NodeNum - 1];
			cout << "输入n次（节点字符，节点权重）";
			for (i = 0; i < NodeNum; i++)
			{
				cin >> temp[i].ch >> temp[i].weight;
				out << temp[i].ch << "  " << temp[i].weight << endl;
			}
			out.close();
			for (i = NodeNum; i < 2 * NodeNum - 1; i++)
			{
				int s1, s2;
				select(temp, i, s1, s2);
				temp[i].lchild = &temp[s1];
				temp[i].rchild = &temp[s2];
				temp[i].weight = temp[s1].weight + temp[s2].weight;
			}
			header = &temp[i - 1];//将头节点赋给头指针
			CreatHuffmanCode();
		}
	}
	else
	{
		fstream in("hfmTree.txt");
		in >> NodeNum;
		if (NodeNum <= 0)
		cout << "输入错误" << endl;
		else//建一个霍夫曼树
		{
			Node *temp = new Node[2 * NodeNum - 1];
			for (i = 0; i < NodeNum; i++)
			{
				in >> temp[i].ch >> temp[i].weight;
			}
			in.close();
			for (i = NodeNum; i < 2 * NodeNum - 1; i++)
			{
				int s1, s2;
				select(temp, i, s1, s2);
				temp[i].lchild = &temp[s1];
				temp[i].rchild = &temp[s2];
				temp[i].weight = temp[s1].weight + temp[s2].weight;
			}
			header = &temp[i - 1];//将头节点赋给头指针
			CreatHuffmanCode();
		}
	}
}

void huffman::CreatHuffmanCode()
{
	int i;
	//初始化
	char *cd = new char[NodeNum + 1];
	SumCode = new char[NodeNum];
	int cdlen = 0;
	HuffmanCode = new char*[NodeNum];
	int hfmcodelen = 0;
	for (i = 0; i < NodeNum; i++)
	{
		HuffmanCode[i] = new char[NodeNum];
	}
	//初始化end
	Node *p = header;
	while (p)
	{
		if (p->mark == 0)
		{
			p->mark = -1;
			if (p->lchild!=NULL)
			{
				p = p->lchild;
				cd[cdlen++] = '0';
			}
			else if (p->rchild == NULL)
			{
				cd[cdlen] = '\0';
				for (i = 0; i <= cdlen; i++)
					HuffmanCode[hfmcodelen][i] = cd[i];
				SumCode[hfmcodelen]=p->ch;
				hfmcodelen++;
			}
		}
		else if (p->mark == -1)
		{
			p->mark = 1;
			if (p->rchild != NULL)
			{
				p = p->rchild;
				cd[cdlen++] = '1';
			}
		}
		else
		{
			p = p->parent;
			cd[cdlen--] = '\0';
		}
	}
	delete cd;
}
void huffman::printHelp(Node* p, string ss)
{
	if (p == NULL)
		return;
	ss += "        ";
	printHelp(p->rchild, ss);
	ofstream out("TreePrint.txt",ios::app);
	cout << ss << p->ch << " " << p->weight << endl;
	out << ss << p->ch << " " << p->weight << endl;
	out.close();
	printHelp(p->lchild, ss);
}
void huffman::print()
{
	ofstream out("TreePrint.txt", ios::trunc);//清空文件
	out.close();
	cout << "对哈夫曼树进行凹入表打印，并写入文件TreePrint中" << endl;
	string ss = "  ";
	printHelp(header, ss);
	cout << endl << "印哈夫曼树成功" << endl;
}
void huffman::printHFMCode()
{
	int i;
	for (i = 0; i < NodeNum; i++)
		cout <<SumCode[i]<<" "<< HuffmanCode[i] << endl;
}

void huffman::Encoding()
{
	char temp;
	int i;
	cout << "对文件ToBeTran进行编码" << endl;
	ifstream in("ToBeTran.txt");
	ofstream out("CodeFile.txt");
	while (!in.eof())
	{
		in >> temp;
		for (i = 0; i < NodeNum; i++)
			if (temp == SumCode[i])
				break;
		out << HuffmanCode[i];
	}
	in.close();
	out.close();
	cout << "编码成功" << endl;
}
void huffman::Decoding()
{
	char temp;
	Node *p = header;
	cout << "对文件CodeFile进行解码" << endl;
	ifstream in("CodeFile.txt");
	ofstream out("TextFile.txt");
	while (!in.eof())
	{
		in >> temp;
		if (temp == '0')
		{
			if (!p->lchild && !p->rchild)
			{
				out << p->ch;
				cout << p->ch;
				p = header->lchild;
			}
			else
			{
				p = p->lchild;
			}
		}
		else if(temp == '1')
		{
			if (!p->lchild && !p->rchild)
			{
				out << p->ch;
				cout << p->ch;
				p = header->rchild;
			}
			else
			{
				p = p->rchild;
			}
		}
	}
	in.close();
	out.close();
	cout <<endl<< "解码成功" << endl;
}

void huffman::PrintCode()
{
	char temp;
	int count=0;
	cout << "对文件CodeFile进行印代码操作" << endl;
	ifstream in("CodeFile.txt");
	ofstream out("CodePrin.txt");
	while (!in.eof())
	{
		in >> temp;
		if (count == 50)
		{
			out << endl;
			cout << endl;
			count = 0;
		}
		out << temp;
		cout << temp;
		count++;
	}
	in.close();
	out.close();
	cout << endl << "印代码成功" << endl;
}