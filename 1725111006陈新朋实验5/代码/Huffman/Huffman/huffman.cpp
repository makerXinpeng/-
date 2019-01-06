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
	cout << "��ѡ���ʼ����ʽ��1.�½�һ����������  2.���ļ��ж�ȡ" << endl;
	cin >> cmd;
	if (cmd != 1 && cmd != 2)
		cout << "��������";
	else if (cmd == 1)
	{
		cout << "��������Ҫ����Ľڵ������";
		cin >> NodeNum;
		if (NodeNum <= 0)
			cout << "�������" << endl;
		else//�½�һ����������
		{
			fstream out("hfmTree.txt");
			out << NodeNum << endl;

			Node *temp = new Node[2 * NodeNum - 1];
			cout << "����n�Σ��ڵ��ַ����ڵ�Ȩ�أ�";
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
			header = &temp[i - 1];//��ͷ�ڵ㸳��ͷָ��
			CreatHuffmanCode();
		}
	}
	else
	{
		fstream in("hfmTree.txt");
		in >> NodeNum;
		if (NodeNum <= 0)
		cout << "�������" << endl;
		else//��һ����������
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
			header = &temp[i - 1];//��ͷ�ڵ㸳��ͷָ��
			CreatHuffmanCode();
		}
	}
}

void huffman::CreatHuffmanCode()
{
	int i;
	//��ʼ��
	char *cd = new char[NodeNum + 1];
	SumCode = new char[NodeNum];
	int cdlen = 0;
	HuffmanCode = new char*[NodeNum];
	int hfmcodelen = 0;
	for (i = 0; i < NodeNum; i++)
	{
		HuffmanCode[i] = new char[NodeNum];
	}
	//��ʼ��end
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
	ofstream out("TreePrint.txt", ios::trunc);//����ļ�
	out.close();
	cout << "�Թ����������а�����ӡ����д���ļ�TreePrint��" << endl;
	string ss = "  ";
	printHelp(header, ss);
	cout << endl << "ӡ���������ɹ�" << endl;
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
	cout << "���ļ�ToBeTran���б���" << endl;
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
	cout << "����ɹ�" << endl;
}
void huffman::Decoding()
{
	char temp;
	Node *p = header;
	cout << "���ļ�CodeFile���н���" << endl;
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
	cout <<endl<< "����ɹ�" << endl;
}

void huffman::PrintCode()
{
	char temp;
	int count=0;
	cout << "���ļ�CodeFile����ӡ�������" << endl;
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
	cout << endl << "ӡ����ɹ�" << endl;
}