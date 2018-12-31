//
//  main.cpp
//  约瑟夫环
//
//  Created by 陈新朋 on 2018/10/12.
//  Copyright © 2018年 陈新朋. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    int num;
    struct Node *next;
}ListNode,*LinkList;
LinkList CreateList(int n);
void getout(LinkList head,int n,int m,int k);
int main() {
    LinkList h;
    int n,k,m;
    cout<<"输入环中人的个数：";
    cin>>n;
    cout<<endl<<"输入开始报数的序号";
    cin>>k;
    cout<<endl<<"报数为m的人出列 m=";
    cin>>m;
    h=CreateList(n);
    getout(h, n, m, k);
    return 0;
}
LinkList CreateList(int n)
{
    LinkList head=NULL;
    ListNode *s,*r;
    int i;
    for(i=1;i<=n;i++)
    {
        s=new ListNode;
        s->data=i;
        cin>>s->num;
        s->next=NULL;
        if(head==NULL)
            head=s;
        else
            r->next=s;
        r=s;
    }
    r->next=head;
    return head;
}
void getout(LinkList head, int n, int m, int k)
{
    ListNode *p,*q;
    int i;
    p=head;
    for(i=0;i<k;i++)
    {
        q=p;
        p=p->next;
    }
    while(p->next!=p)
    {
        for(i=1;i<m;i++)
        {
            q=p;
            p=p->next;
        }
        m=p->num;
        q->next=p->next;
        cout<<p->data<<endl;
        delete p;
        p=q->next;
    }
    cout<<p->data<<endl;
}
