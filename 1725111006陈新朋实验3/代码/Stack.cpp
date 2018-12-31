//
//  Stack.cpp
//  表达式运算
//
//  Created by 陈新朋 on 2018/10/17.
//  Copyright © 2018年 陈新朋. All rights reserved.
//

#include "Stack.h"
/**
 * @brief 初始化一个栈
 * 由于有头结点，故将头结点的指针域置为零
 * -top为栈底的地址，*top为现在栈顶的位置
 */
void InitStack(Node *top)
{
    top->next=NULL;
}
/**
 * @brief 打印一个栈
 * -
 */
void Display(Node *top)
{
    Node *p;
    p=top;
    if(!StackEmpty(top))
    {
        while(p->next!=NULL)
        {
            cout<<p->next->data<<" ";
            p=p->next;
        }
    }
}
/**
 * @brief 判断栈是否为空
 * 判断栈顶指针的next是否为空
 * @condition 已有一个栈
 * -top为栈顶指针
 * @return 栈空或非空
 */
int StackEmpty(Node *top)
{
    if(top->next==NULL)
        return 1;
    else
        return 0;
}
/**
 * @brief 进栈
 * 建立一个新节点，给它的数据赋值，并把它压入栈
 * @condition 已有一个栈
 * -top为栈顶指针
 * -p为新节点的指针
 8 -e为入栈元素的值
 * -必须先执行p->next=top->next;再执行top->next=p;顺序不可颠倒
 * @return 进栈是否成功
 */
int PushStack(Node *top, char e)
{
    Node *p=new Node;
    p->data=e;
    p->next=top->next;
    top->next=p;
    return 1;
}
/**
 * @brief 出栈
 * @condition 已有一个栈，且栈不为空
 * -top为栈顶指针，e为出站元素的值
 * @return 出栈是否成功
 */
int PopStack(Node *top, char *e)
{
    if(!StackLen(top))
        return 0;
    else
    {
        Node *p;
        p=top->next;
        top->next = p->next;
        *e=p->data;
        delete p;
        return 1;
    }
}
/**
 * @brief 取栈顶元素
 * 返回栈顶指针指向的元素数据值
 * @condition 已有一个栈，且栈不为空
 * -top为栈顶指针
 * -p为新节点的指针
 * @return 是否成功返回元素数据值
 */
int GetTop(Node *top, char *e)
{
    Node *p;
    p=top->next;
    if(!StackLen(top))
        return 0;
    else
    {
        *e=p->data;
        return 1;
    }
}
/**
 * @brief 求表长
 * 返回栈中元素个数
 * @condition 已有一个栈
 * -top为栈顶指针
 * -p为节点指针
 * -i为计数变量
 * @return 返回栈的长度
 */
int StackLen(Node *top)
{
    Node *p;
    int i=0;
    p=top;
    while(p->next!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}
/**
 * @brief 销毁栈
 * 释放栈空间
 * @condition 已有一个栈
 * -top为栈顶指针
 * -p、q均为节点指针，q用于释放空间
 */
void DestroyStack(Node *top)
{
    Node *p,*q;
    p=top;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        delete q;
    }
}
