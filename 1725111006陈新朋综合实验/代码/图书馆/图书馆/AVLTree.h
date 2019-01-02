#ifndef _AVLTree_H
#define _AVLTree_H
#include "string"
#include <iostream>

using namespace std;
struct Node
{
	int height;
	Node * lchild;
	Node * rchild;

	string booknum;
	string bookname;
	string author;
	unsigned int stillhave;
	unsigned int total;

	Node(unsigned int stillhave = 0, unsigned int total = 0, int key = 0)
	{
		this->booknum = booknum;
		this->bookname = bookname;
		this->author = author;
		this->stillhave = stillhave;
		this->total = total;
		this->height = 1;
		this->lchild = this->rchild = NULL;
	}
};
struct bookmsg
{
	string booknum;
	int borrowdate;
	int returndate;
	bool is;
	bookmsg *next;
};
struct borrower
{
	string IDnum;
	bookmsg *borrowlist;
};

class AVLTree
{
public:
	borrower * borrowerlist;
	void borrowbook(string IDnum, string booknum, int borrowdate, int returndate);
	void returnbook(string IDnum, string booknum);
	void Insert(Node key);
	void Insertber(string name);
	Node *GetPos(string key);
	void print();
	AVLTree()
	{
		header = new Node;
		bor = 0;
		borrowerlist = new borrower[50];
	}

	Node * header;
private:
	int bor;//借书人总数
	Node *InsAVLTree(Node *T, Node key);
	int GetHeight(Node *T);
	int GetBalance(Node * T);

	Node *GetPos_true(Node *T, string key);

	Node *LL_rotate(Node * T);
	Node *RR_rotate(Node * T);
	Node *LR_rotate(Node * T);
	Node *RL_rotate(Node * T);

	void InOrder(Node * node);
};

#endif // _AVLTree_H

