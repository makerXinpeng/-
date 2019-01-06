#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_
#include <iostream>
using namespace std;
struct Node
{
	Node *parent, *lchild, *rchild;
	int weight,mark;
	char ch;
	Node(char ch = '0', int mark = 0, Node *parent = NULL, Node *lchild = NULL, Node *rchild = NULL, int weight = -1)
	{
		this->parent = parent;
		this->lchild = lchild;
		this->rchild = rchild;
		this->weight = weight;
		this->mark = mark;
		this->ch = ch;
	}
};
class huffman
{
public:
	int NodeNum;
	char **HuffmanCode;
	huffman()
	{
		NodeNum = 0;
		header = 0;
		HuffmanCode = NULL;
		SumCode = NULL;
	}
	void init();//初始化（Initialization）。从终端读入字符集大小n,以及n个字符和n个权值，建立哈夫曼树，并将它存于文件hfmTree中。
	void print();//印哈夫曼树（Tree printing）。将已在内存中的哈夫曼树以直观的方式（树或凹入表形式）显示在终端上，同时将此字符形式的哈夫曼树写入文件TreePrint中。
	void printHFMCode();
	void Encoding();//编码（Encoding）。利用已建好的哈夫曼树（如不在内存，则从文件hfmTree中读入），对文件ToBeTran中的正文进行编码，然后将结果存入文件CodeFile中。
	void Decoding();//译码（Decoding）。利用已建好的哈夫曼树将文件CodeFile中的代码进行译码，结果存入文件TextFile中。
	void PrintCode();//印代码文件（Print）。将文件CodeFile以紧凑格式显示在终端上，每行50个代码。同时将此字符形式的编码文件写入文件CodePrin中。
private:
	Node * header;
	char * SumCode;
	void CreatHuffmanCode();
	void printHelp(Node* p, string ss);
	void select(Node T[], int n, int &min, int &sub);
};

#endif //_HUFFMAN_H_