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
	void init();//��ʼ����Initialization�������ն˶����ַ�����Сn,�Լ�n���ַ���n��Ȩֵ���������������������������ļ�hfmTree�С�
	void print();//ӡ����������Tree printing�����������ڴ��еĹ���������ֱ�۵ķ�ʽ�����������ʽ����ʾ���ն��ϣ�ͬʱ�����ַ���ʽ�Ĺ�������д���ļ�TreePrint�С�
	void printHFMCode();
	void Encoding();//���루Encoding���������ѽ��õĹ����������粻���ڴ棬����ļ�hfmTree�ж��룩�����ļ�ToBeTran�е����Ľ��б��룬Ȼ�󽫽�������ļ�CodeFile�С�
	void Decoding();//���루Decoding���������ѽ��õĹ����������ļ�CodeFile�еĴ���������룬��������ļ�TextFile�С�
	void PrintCode();//ӡ�����ļ���Print�������ļ�CodeFile�Խ��ո�ʽ��ʾ���ն��ϣ�ÿ��50�����롣ͬʱ�����ַ���ʽ�ı����ļ�д���ļ�CodePrin�С�
private:
	Node * header;
	char * SumCode;
	void CreatHuffmanCode();
	void printHelp(Node* p, string ss);
	void select(Node T[], int n, int &min, int &sub);
};

#endif //_HUFFMAN_H_