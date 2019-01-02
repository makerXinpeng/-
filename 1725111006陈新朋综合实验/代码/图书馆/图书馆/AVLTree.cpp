#include "stdafx.h"
#include "AVLTree.h"
#include <algorithm>
Node* AVLTree::InsAVLTree(Node *T, Node key)
{
	if (!T)
		return new Node(key);	

	if (key.booknum < T->booknum)
		T->lchild = InsAVLTree(T->lchild, key);
	else if (key.booknum > T->booknum)
		T->rchild = InsAVLTree(T->rchild, key);
	else
	{
		T->total += key.total;
		T->stillhave += key.stillhave;
		return T;
	}
	
	T->height = max(GetHeight(T->lchild), GetHeight(T->rchild)) + 1;

 	int bf = GetBalance(T);

	// 左左失衡
	if (bf > 1 && GetBalance(T->lchild) > 0)
		return LL_rotate(T);

	// 右右失衡
	if (bf < -1 && GetBalance(T->rchild) < 0)
		return RR_rotate(T);

	// 左右失衡
	if (bf > 1 && GetBalance(T->lchild) < 0)
		return LR_rotate(T);

	// 右左失衡
	if (bf < -1 && GetBalance(T->rchild) > 0)
		return RL_rotate(T);

	return T;
}
void AVLTree::Insert(Node key)
{
	header->lchild = InsAVLTree(header->lchild, key);
}
int AVLTree::GetHeight(Node *T)
{
	if (!T)
		return 0;
	return T->height;
}
int AVLTree::GetBalance(Node * T)
{
	if (!T)
		return 0;
	return GetHeight(T->lchild) - GetHeight(T->rchild);
}

Node* AVLTree::GetPos_true(Node *T, string key)
{
	if (T)
	{
		if (T->booknum == key)
			return T;
		else if (T->booknum > key)
			return GetPos_true(T->lchild, key);
		else
			return GetPos_true(T->rchild, key);
	}
	else
		return NULL;
}
Node* AVLTree::GetPos(string key)
{
	return GetPos_true(header->lchild, key);
}

Node* AVLTree::LL_rotate(Node * T)
{
	Node *p = T->lchild;
	T->lchild = p->rchild;
	p->rchild = T;

	T->height = max(GetHeight(T->lchild), GetHeight(T->rchild)) + 1;
	p->height = max(GetHeight(p->lchild), GetHeight(p->rchild)) + 1;

	return p;
}
Node* AVLTree::RR_rotate(Node * T)
{
	Node *p = T->rchild;
	T->rchild = p->lchild;
	p->lchild = T;

	T->height = max(GetHeight(T->lchild), GetHeight(T->rchild)) + 1;
	p->height = max(GetHeight(p->lchild), GetHeight(p->rchild)) + 1;

	return p;
}
Node* AVLTree::LR_rotate(Node * T)
{
	Node *p = T->lchild;
	T->lchild = RR_rotate(p);
	return LL_rotate(T);
}
Node* AVLTree::RL_rotate(Node * T)
{
	Node *p = T->rchild;
	T->rchild = LL_rotate(p);
	return RR_rotate(T);
}

void AVLTree::InOrder(Node * node)
{
	if (node == nullptr)
		return;
	InOrder(node->lchild);
	cout << node->booknum << ' ' << node->bookname << ' ' << node->author << ' ' << node->stillhave << ' ' << node->total << endl;
	InOrder(node->rchild);
}

void AVLTree::print()
{
	InOrder(header->lchild);
	cout << endl;
}

//插入借书者
void AVLTree::Insertber(string name)
{
	borrowerlist[bor].IDnum = name;
	borrowerlist[bor].borrowlist = NULL;
	bor++;
}
//插入借阅图书的信息
void AVLTree::borrowbook(string IDnum, string booknum, int borrowdate, int returndate)
{
	Node *temp = GetPos(booknum);
	if (!GetPos(booknum) || GetPos(booknum)->stillhave<=0)
		cout << "此书不存在或已被借完"<<endl;
	else //是否有超期未还的书、
	{
		int i;
		bookmsg *p,*pre;
		for (i = 0; i < bor; i++)
			if (borrowerlist[i].IDnum == IDnum)
				break;
		
		pre = p = borrowerlist[i].borrowlist;
		if (!p)
		{
			borrowerlist[i].borrowlist = new bookmsg;
			borrowerlist[i].borrowlist->booknum = booknum;
			borrowerlist[i].borrowlist->borrowdate = borrowdate;
			borrowerlist[i].borrowlist->returndate = returndate;
			borrowerlist[i].borrowlist->is = false;
			borrowerlist[i].borrowlist->next = NULL;
			temp->stillhave--;
		}
		else
		{
			while (p)
			{
				p = p->next;
				pre = p;
			}
			pre->next = new bookmsg;
			pre->next->booknum = booknum;
			pre->next->borrowdate = borrowdate;
			pre->next->returndate = returndate;
			pre->next->is = false;
			pre->next->next = NULL;
			temp->stillhave--;
		}
	}
}
void AVLTree::returnbook(string IDnum, string book)
{
	int i;

	bookmsg *p;
	for (i = 0; i < bor; i++)
	{
		if (borrowerlist[i].IDnum == IDnum)
			break;
	}
	if (i == bor)
		cout << "ID错误" << endl;
	else
	{
		p = borrowerlist[i].borrowlist;
		while (p&&p->booknum!=book)
		{
			p = p->next;
		}
		if (p == NULL ||p->is==true)
			cout << "没有借过此书或已经归还" << endl;
		else
		{
			p->is = true;
			Node *temp = GetPos(book);
			temp->stillhave++;
		}
	}
}
