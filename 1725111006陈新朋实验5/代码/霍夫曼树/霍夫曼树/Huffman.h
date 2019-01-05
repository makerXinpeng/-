#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct HuffmanTree
{
	int parent, lchild, rchild, weight;
};
HuffmanTree *HfmTree;
string *HfmCode;
int length;



#endif //_HUFFMAN_H_