//
//  main.cpp
//  二叉树
//
//  Created by 陈新朋 on 2018/10/31.
//  Copyright © 2018年 陈新朋. All rights reserved.
//

#include <iostream>
#include "binary tree.hpp"
using namespace std;

int main() {
    BitNode tree;
    BiTree P=&tree;
    cout<<"创建二叉树：";
    CreateBiTree(&P);
    cout<<endl<<"先序遍历：";
    PreOrderTraverse(P);
    cout<<endl<<"非递归先序遍历：";
    UPreOrderTraverse(P);
    cout<<endl<<"中序遍历：";
    InOrderTraverse(P);
    cout<<endl<<"非递归中序遍历：";
    UInOrderTraverse(P);
    cout<<endl<<"后序遍历：";
    PostOrderTraverse(P);
    cout<<endl<<"非递归后序遍历";
    UPostOrderTraverse(P);
    cout<<endl;
    return 0;
}
