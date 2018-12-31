//
//  binary tree.cpp
//  二叉树
//
//  Created by 陈新朋 on 2018/11/7.
//  Copyright © 2018年 陈新朋. All rights reserved.
//

#include "binary tree.hpp"
void CreateBiTree(BiTree *T)
{
    char ch;
    cin>>ch;
    if(ch=='#')
        T=NULL;
    else
    {
        *T=new BitNode;
        (*T)->data=ch;
        (*T)->lc=NULL;
        (*T)->rc=NULL;
        cout<<(*T)->data<<' ';
        CreateBiTree(&((*T)->lc));
        CreateBiTree(&((*T)->rc));
    }
}

void PreOrderTraverse(BiTree T)
{
    if(T！=NULL)
    {
        cout<<T->data<<' ';
        PreOrderTraverse(T->lc);
        PreOrderTraverse(T->rc);
    }
}
void InOrderTraverse(BiTree T)
{
    if(T!=NULL)
    {
        InOrderTraverse(T->lc);
        cout<<T->data<<' ';
        InOrderTraverse(T->rc);
    }
}
void PostOrderTraverse(BiTree T)
{
    if(T！=NULL)
    {
        InOrderTraverse(T->lc);
        InOrderTraverse(T->rc);
        cout<<T->data<<' ';
    }
}
void UPreOrderTraverse(BiTree T)
{
    BiTree stack[50];
    int top;
    BitNode *p;
    top=0;
    p=T;
    while(p!=NULL||top>0)
    {
        while(p!=NULL)
        {
            cout<<p->data;
            stack[top++]=p;
            p=p->lc;
        }
        if(top>0)
        {
            p=stack[--top];
            p=p->rc;
        }
    }
}
void UInOrderTraverse(BiTree T)
{
    BiTree stack[50];
    int top;
    BitNode *p;
    top=0;
    p=T;
    while(p!=NULL||top>0)
    {
        while(p!=NULL)
        {
            stack[top++]=p;
            p=p->lc;
        }
        if(top>0)
        {
            p=stack[--top];
            cout<<p->data;
            p=p->rc;
        }
    }
}
void UPostOrderTraverse(BiTree T)
{
    BiTree stack[50];
    int top;
    BitNode *p,*q;
    top=0;
    p=T;
    while(p!=NULL||top>0)
    {
        while(p!=NULL)
        {
            stack[top++]=p;
            p=p->lc;
        }
        if(top>0)
        {
            p=stack[top-1];
            if(p->rc==NULL||p->rc==q)
            {
                cout<<p->data;
                q=p;
                p=NULL;
                top--;
            }
            else
            {
                p=p->rc;
            }
        }
    }
}
