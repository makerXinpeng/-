// Huffman.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "huffman.h"
#include <iostream>
using namespace std;
void SystemCall()
{
	huffman tree;
	char cmd;
	cout << "请输入命令：I、初始化  E、编码  D、译码  P、印代码文件  T、印哈夫曼树  Q、退出" << endl;
	while (cin >> cmd)
	{
		if (cmd == 'Q')
			break;
		switch (cmd)
		{
		case 'I':
			tree.init();
			break;
		case 'E':
			tree.Encoding();
			break;
		case 'D':
			tree.Decoding();
			break;
		case'P':
			tree.PrintCode();
			break;
		case'T':
			tree.print();
			break;
		}
		cout << "请输入命令：I、初始化  E、编码  D、译码  P、印代码文件  T、印哈夫曼树  Q、退出" << endl;
	}
}
int main()
{
	SystemCall();
    return 0;
}

