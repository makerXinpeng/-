//
//  main.cpp
//  DS_exp1
//
//  Created by 陈新朋 on 2018/9/20.
//  Copyright © 2018年 陈新朋. All rights reserved.
//

#include <iostream>
using namespace std;

class list
{
private:
    int *base;
    int length;
public:
    list(int n)
    {
        base=new int[n];
        length=n;
    }
/*    ~list()
    {
        length = 0;
        delete base;
        base = NULL;
    }*/
    void listin()
    {
        cout<<"请输入"<<length<<"个数:";
        for(int i=0;i<length;i++)
            cin>>base[i];
    }
    void listout()
    {
        cout<<"元素：";
        for(int i=0;i<length;i++)
            cout<<base[i]<<" ";
        cout<<endl;
    }

    void ListInsert(int i,int p);
    void ListDelete(int i);
    
    void GetElem(int i,int &p);
    void LocateElem(int e);
    void MaxElem();
    void MinElem();
    
    void listsort();
    void listdissort();
    friend void listMerge(list L1,list L2);
};

void list::ListInsert(int i,int p)
{
    if(i<0||i>length)
        cout<<"input error"<<endl;
    else
    {
        length++;
        int j,*newbase=new int[length];
        for(j = 0;j<i-1;j++)
            newbase[j]=base[j];
        newbase[j] = p;
        j=j+1;
        for(;j<length;j++)
            newbase[j]=base[j-1];
        delete base;
        base=newbase;
    }
}
void list::ListDelete(int i)
{
    if(i<=0||i>length)
        cout<<"input error"<<endl;
    for(int j=i-1;j<length-1;j++)
        base[j]=base[j+1];
    base[length-1]=NULL;
    length--;
}
void list::GetElem(int i,int &p)
{
    if(i<0||i>length)
        cout<<"Input error"<<endl;
    else
    {
        p=base[i-1];
        cout<<p<<endl;
    }
}
void list::LocateElem(int e)
{
    bool is=false;
    for(int i=0;i<length;i++)
    {
        if(base[i]==e)
        {
            cout<<i+1<<endl;
            is=true;
            break;
        }
    }
    if(is==false)
        cout<<"The element is not exist"<<endl;
}
void list::MaxElem()
{
    int max=base[0];
    for(int i=1;i<length;i++)
    {
        if (max<base[i])
            max=base[i];
    }
    cout<<"最大值为："<<max<<endl;
}
void list::MinElem()
{
    int min=base[0];
    for(int i=1;i<length;i++)
    {
        if (min>base[i])
            min=base[i];
    }
    cout<<"最小值为："<<min<<endl;
}

void list::listsort()
{
    int temp,i,j;
    for(i=0;i<length;i++)
    {
        for(j=0;j<length-i-1;j++)
        {
            if(base[j]>base[j+1])
            {
                temp=base[j];
                base[j]=base[j+1];
                base[j+1]=temp;
            }
        }
    }
}
void list::listdissort()
{
    int temp;
    int n=length/2;
    for(int i=0;i<n;i++)
    {
        temp=base[i];
        base[i]=base[length-i-1];
        base[length-i-1]=temp;
    }
}


void listMerge(list L1,list L2)
{
    int i=1,j=1,k=0;
    list L3(L1.length+L2.length);
    while((i<=L1.length)&&(j<=L2.length))
    {
        if(L1.base[i-1]<L2.base[j-1])
        {
            L3.base[k]=L1.base[i-1];
            k++;
            i++;
        }
        else
        {
            L3.base[k]=L2.base[j-1];
            k++;
            j++;
        }
    }
    for(;i<=L1.length;i++)
    {
        L3.base[k]=L1.base[i-1];
        k++;
    }
    for(;j<=L2.length;j++)
    {
        L3.base[k]=L2.base[j-1];
        k++;
    }
    for(int m=0;m<L3.length;m++)
    {
        if(L3.base[m]==L3.base[m-1])
        {
            L3.ListDelete(m);
            m--;
        }
    }
    L3.listout();
}
int main()
{
    //基本操作
    int a=5;
    list l1(5),l2(6);
    l1.listin();
    l2.listin();
    l1.listout();
    l1.GetElem(3, a);
    l1.GetElem(7, a);
    l1.LocateElem(4);
    l1.LocateElem(7);
    l1.MaxElem();
    l1.MinElem();

    l1.listsort();
    l1.listout();

    l1.listdissort();
    l1.listout();
    a=100;
    l1.ListInsert(1, a);
    l1.ListDelete(3);
    
    //合并操作
    list l3(4),l4(3);
    l3.listin();
    l4.listin();
    listMerge(l3, l4);
    
    return 0;
}
