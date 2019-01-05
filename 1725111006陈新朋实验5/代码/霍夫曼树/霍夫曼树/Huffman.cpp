#include "stdafx.h"
#include "Huffman.h"

void select(HuffmanTree HfmT[], int k, int &most_min, int &sub_min)
{
	int i;
	most_min;
	sub_min;
	for (i = 0; i<k&&HfmT[i].parent>0; i++)
	{
	}
	most_min = i;
	for (i = 0; i < k; i++)
	{
		if (HfmT[i].parent > 0)
			continue;
		else if (HfmT[most_min].weight>HfmT[i].weight)
			most_min = i;
	}
	HfmT[most_min].parent = k;

	for (i = 0; i<k&&HfmT[i].parent>0; i++)
	{
	}
	sub_min = i;
	for (i = 0; i < k; i++)
	{
		if (HfmT[i].parent > 0)
			continue;
		else if (HfmT[sub_min].weight>HfmT[i].weight)
			sub_min = i;
	}
	HfmT[sub_min].parent = k;
}
void initial(HuffmanTree HfmT[], string &cod)
{
	int n, i;
	cout << "输入字母个数：";
	cin >> n;
	length = n;
	HfmT = new HuffmanTree[2 * n - 1];
	cod = new char[n];
	for (i = 0; i < n; i++)
		cod[i] = -1;
	for (i = 0; i < 2 * n - 1; i++)
	{
		HfmT[i].lchild = -1;
		HfmT[i].parent = -1;
		HfmT[i].rchild = -1;
		HfmT[i].weight = -1;
	}
	cout << "输入字符以及权重：" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> cod[i];
		cin >> HfmT[i].weight;
	}
	int most_min, sub_min;
	for (i = n; i < 2 * n - 1; i++)
	{
		select(HfmT, i, most_min, sub_min);
		HfmT[i].lchild = most_min;
		HfmT[i].rchild = sub_min;
		HfmT[i].weight = HfmT[most_min].weight + HfmT[sub_min].weight;
	}
	//将HfmT数组输入到文件中
	for (i = 0; i < n; i++)
	{
		cout << setw(3) << cod[i];
		cout << setw(3) << HfmT[i].weight;
		cout << setw(3) << HfmT[i].parent;
		cout << setw(3) << HfmT[i].lchild;
		cout << setw(3) << HfmT[i].rchild << endl;
	}
	for (i = n; i < 2 * n - 1; i++)
	{
		cout << setw(3) << ' ';
		cout << setw(3) << HfmT[i].weight;
		cout << setw(3) << HfmT[i].parent;
		cout << setw(3) << HfmT[i].lchild;
		cout << setw(3) << HfmT[i].rchild << endl;
	}

	//将霍夫曼树转换为霍夫曼编码
	HfmCode = new string[n];//存储霍夫曼编码
	char *cd = new char[n - 1];//编码长度最大不超过n-1
	int signal, j, k;
	for (j = 0; j < n; j++)//n个字符依次遍历
	{
		for (i = 0; i < n - 1; i++)//初始化为#
			cd[i] = '#';
		int temp = j;//temp用于作为中间变量

		for (signal = n - 2; HfmT[temp].parent != (-1); signal--)//存储霍夫曼编码
		{
			if (HfmT[HfmT[temp].parent].lchild == temp)
				cd[signal] = '0';
			else
				cd[signal] = '1';
			temp = HfmT[temp].parent;
		}

		HfmCode[j] = new char[n - signal];
		for (k = 0; k < n - signal - 1; k++)
			HfmCode[j][k] = cd[signal + k];
		HfmCode[j][k + 1] = '\0';
	}
	ofstream out("F:\\大学学习\\VS程序代码\\霍夫曼树\\霍夫曼树\\test\\hfmTree.txt", ios::out);
	for (i = 0; i < n; i++)
	{
		out << cod[i] << ' ';
		/*
		for (j = 1;j<=HfmCode[i][0]; j++)
		{
		if(HfmCode[i][j])*/
		out << HfmCode[i];
		/*
		}
		out << endl;*/
	}
}
void Encoding(string tobetran, string cod)
{
	int i, j = 0;
	string finish;
	int it = 0;
	cout << cod.length() << endl;
	for (i = 0; i<tobetran.length(); i++)//要翻译的字符
	{
		for (j = 0; j < cod.length(); j++)
		{
			if (cod[j] == tobetran[i])
			{
				for (int k = 0; k < HfmCode[j][0]; k++)
				{
					finish[it] = HfmCode[j][k];
					it++;
				}
				break;
			}
		}
	}
	cout << "CODE:" << endl;
	for (i = 0; i < finish.length(); i++)
		cout << finish[i] << ' ';
}
void Decoding()
{

}