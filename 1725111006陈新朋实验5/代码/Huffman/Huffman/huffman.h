#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_
#include <iostream>
using namespace std;
struct Node
{
	Node *parent, *lchild, *rchild;
	int weight;
	char ch;
	Node( Node *parent = NULL, Node *lchild = NULL, Node *rchild = NULL, int weight = -1)
	{
		this->parent = parent;
		this->lchild = lchild;
		this->rchild = rchild;
		this->weight = weight;
	}
};
class huffman
{
public:
	int NodeNum;
	huffman()
	{
		header = 0;
	}
	void init();
	void CreatHuffmanCode();
	void printHelp(Node* p, string ss);
	void print();
private:
	Node * header;
	void select(Node T[], int n, int &min, int &sub);
};

#endif //_HUFFMAN_H_