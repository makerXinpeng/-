//
//  Stack.h
//  表达式运算
//
//  Created by 陈新朋 on 2018/10/17.
//  Copyright © 2018年 陈新朋. All rights reserved.
//

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
using namespace std;
#define NULL 0

struct Node
{
    char data;
    struct Node *next;
};

void InitStack(Node *top);
void Display(Node *top);
int StackEmpty(Node *top);
int PushStack(Node *top, char e);
int PopStack(Node *top, char *e);
int GetTop(Node *top, char *e);
int StackLen(Node *top);
void DestroyStack(Node *top);

#endif /* STACK_H */
