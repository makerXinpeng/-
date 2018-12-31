//
//  main.cpp
//  表达式运算
//
//  Created by 陈新朋 on 2018/10/17.
//  Copyright © 2018年 陈新朋. All rights reserved.
//

#include <iostream>
#include "Stack.h"
#include <string>
#include <math.h>
using namespace std;
typedef struct{
    float data[50];
    int top;
}sta;
string TranExp(char *str, string exp);
float ComExp(string s);
int main() {
    
    char str[]="(4 + (2 * exp(3)) / 2";
    //cout<<"输入一个运算表达式：";
    
    char *p=&str[0];
    string e;
    e=TranExp(p, e);
    cout<<"中缀表达式："<<p<<endl;
    cout<<"后缀表达式："<<e<<endl;
    cout<<"计算结果："<<ComExp(e)<<endl;
    return 0;
}
/**
 * @brief 计算后缀表达式并得出结果
 * @condition 已有一个后缀表达式
 * -输出：后缀表达式值
 */
float ComExp(string s)
{
    sta rand;
    rand.top=-1;
    int i=0,value;
    float x1,x2,result;
    for(;i<s.length();i++)
    {
        if(s[i]!=' '&&s[i]>='0'&&s[i]<='9')
        {
            value=0;
            while(s[i]!=' ')
            {
                value=10*value+s[i]-'0';
                i++;
            }
            rand.top+=1;
            rand.data[rand.top]=value;
        }
        else{
            switch(s[i])
            {
                case '+':
                    x1=rand.data[rand.top];
                    rand.top--;
                    x2=rand.data[rand.top];
                    rand.top--;
                    result=x1+x2;
                    rand.top++;
                    rand.data[rand.top]=result;
                    break;
                case '-':
                    x1=rand.data[rand.top];
                    rand.top--;
                    x2=rand.data[rand.top];
                    rand.top--;
                    result=x2-x1;
                    rand.top+=1;
                    rand.data[rand.top]=result;
                    break;
                case '*':
                    x1=rand.data[rand.top];
                    rand.top--;
                    x2=rand.data[rand.top];
                    rand.top--;
                    result=x1*x2;
                    rand.top++;
                    rand.data[rand.top]=result;
                    break;
                case '/':
                    x1=rand.data[rand.top];
                    rand.top--;
                    x2=rand.data[rand.top];
                    rand.top--;
                    result=x2/x1;
                    rand.top++;
                    rand.data[rand.top]=result;
                    break;
                case 'e':
                    x1=rand.data[rand.top];
                    result=exp(x1);
                    rand.data[rand.top]=result;
                    break;
                case 'l':
                    x1=rand.data[rand.top];
                    result=log10(x1);
                    rand.data[rand.top]=result;
                    break;
                case 's':
                    x1=rand.data[rand.top];
                    result=sqrt(x1);
                    rand.data[rand.top]=result;
                    break;
            }
            i++;
        }
    }
    if(!(rand.top!=-1))
    {
        result=rand.data[rand.top];
        rand.top--;
        if(rand.top==-1)
            return result;
        else
        {
            cout<<"表达式错误"<<endl;
            return result;
        }
    }
    else
        return result;
}

/**
 * @brief 将中缀表达式转换成后缀表达式
 * -
 * @condition 已有一个运算表达式
 * -栈S用于存放运算符
 */
string TranExp(char *str, string exp)
{
    Node S;
    char ch,e = '\0';
    int i=0,j=0;
    InitStack(&S);
    PushStack(&S, '#');
    ch=str[i];
    i++;
    while(ch!='\0')
    {
        if(ch=='(')
            PushStack(&S, ch);
        else if(ch==')')
        {
            GetTop(&S,&e);
            while(GetTop(&S,&e)&&e!='('&&e!='e'&&e!='l'&&e!='s')
            {
                PopStack(&S, &e);
                exp+=e;
                exp=exp+' ';
                j++;
            }
            PopStack(&S, &e);
            if(e=='e')
                exp=exp+"e ";
            else if(e=='l')
                exp=exp+"l ";
            else if(e=='s')
                exp=exp+"s ";
        }
        else if(ch=='+'||ch=='-')
        {
            while(!StackEmpty(&S)&&GetTop(&S, &e)&&e!='('&&e!='e'&&e!='l'&&e!='s'&&e!='#')
            {
                PopStack(&S, &e);
                exp+=e;
                exp=exp+' ';
                j++;
            }
            PushStack(&S, ch);
        }
        else if(ch=='*'||ch=='/')
        {
            while(!StackEmpty(&S)&&GetTop(&S, &e)&&e=='/'&&e=='*')
            {
                PopStack(&S, &e);
                exp+=e;
                exp=exp+' ';
                j++;
            }
            PushStack(&S, ch);
        }
        else if(ch=='e')
        {
            PushStack(&S, ch);
            while(ch!='(')
            {
                i++;
                ch=str[i];
            }
            i++;
        }
        else if(ch=='l')
        {
            PushStack(&S, ch);
            while(ch!='(')
            {
                i++;
                ch=str[i];
            }
            i++;
        }
        else if(ch=='s')
        {
            PushStack(&S, ch);
            while(ch!='(')
            {
                i++;
                ch=str[i];
            }
            i++;
        }
        else if(ch==' '){}
        else if(ch=='#')
        {
            while(!(GetTop(&S, &e)&&e=='#'))
            {
                PopStack(&S, &e);
                exp+=e;
                exp=exp+' ';
            }
        }
        else
        {
            while(ch>='0'&&ch<='9')
            {
                exp+=ch;
                j++;
                ch=str[i];
                i++;
            }
            i--;
            exp=exp+' ';
            j++;
        }
        ch=str[i];
        i++;
    }
    return exp;
}
