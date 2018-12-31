//
//  binary tree.hpp
//  二叉树
//
//  Created by 陈新朋 on 2018/11/7.
//  Copyright © 2018年 陈新朋. All rights reserved.
//

#ifndef binary_tree_hpp
#define binary_tree_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct Node
{
    char data;
    Node *lc,*rc;
}*BiTree,BitNode;
void CreateBiTree(BiTree *T);//创建一个树
void PreOrderTraverse(BiTree T);//递归先序遍历
void InOrderTraverse(BiTree T);//递归中序遍历
void PostOrderTraverse(BiTree T);//递归后序遍历

void UPreOrderTraverse(BiTree T);//非递归先序遍历
void UInOrderTraverse(BiTree T);//非递归中序遍历
void UPostOrderTraverse(BiTree T);//非递归后序遍历
#endif /* binary_tree_hpp */
