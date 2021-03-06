// 邻接表建图遍历.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<queue>
#include <string>
using namespace std;

#define Max_Vertex_Num 30
struct ArcNode
{
	int adjvex;
	ArcNode *nextarc;
	int weight;
};
typedef struct VNode
{
	int data;
	ArcNode *firstarc;
}vertices[Max_Vertex_Num];
struct ALGraph
{
	vertices vertices;
	int vexnum, arcnum;
};
int local(ALGraph G, int val)
{
	for (int i = 0; i<G.vexnum; i++)
	{
		if (G.vertices[i].data == val)
			return i;
	}
	return -1;
}
void CreateGraph(ALGraph & G)
{
	int i, j, k;
	int v1, v2;
	ArcNode * e, *p, *q;
	cout << "请输入顶点数和边数:" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "请输入顶点的数据：" << endl;
	for (i = 0; i<(G.vexnum); i++)
	{
		cout << "第" << i + 1 << "个顶点：" << endl;
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	for (k = 0; k<(G.arcnum); k++)
	{
		int wei;
		cout << "请输入（Vi,Vj,W）信息:" << endl;
		cin >> v1 >> v2>>wei;
		i = local(G, v1);
		j = local(G, v2);

		if (G.vertices[i].firstarc == NULL)
		{
			e = new ArcNode;
			e->adjvex = j;
			e->nextarc = NULL;
			G.vertices[i].firstarc = e;
			G.vertices[i].firstarc->weight = wei;
		}
		else
		{
			p = G.vertices[i].firstarc;
			while (p->nextarc != NULL)
			{
				p = p->nextarc;
			}
			e = new ArcNode;
			e->adjvex = j;
			e->nextarc = NULL;
			p->nextarc = e;
			G.vertices[i].firstarc = e;
			G.vertices[i].firstarc->weight = wei;
		}
		if (G.vertices[j].firstarc == NULL)
		{
			e = new ArcNode;
			e->adjvex = i;
			e->nextarc = NULL;
			G.vertices[j].firstarc = e;
			G.vertices[j].firstarc->weight = wei;
		}
		else
		{
			p = G.vertices[j].firstarc;
			while (p->nextarc != NULL)
			{
				p = p->nextarc;
			}
			e = new ArcNode;
			e->adjvex = i;
			e->nextarc = NULL;
			p->nextarc = e;
			G.vertices[j].firstarc->weight = wei;
		}
	}
}
bool DFSvisited[Max_Vertex_Num];
void DFS(ALGraph  G, int i)
{
	ArcNode * p;
	DFSvisited[i] = true;
	cout << G.vertices[i].data << "  ";
	p = G.vertices[i].firstarc;
	while (p)
	{
		if (!DFSvisited[p->adjvex])
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}
void DFSTraverse(ALGraph  G)
{
	cout << "请输入起始节点：";
	int n;
	cin >> n;
	for (int i = 0; i<G.vexnum; i++)
		DFSvisited[i] = false;
	for (int i = n; i<G.vexnum; i++)
	{
		if (!DFSvisited[i])
			DFS(G, i);
	}
	for (int i = 0; i<n; i++)
	{
		if (!DFSvisited[i])
			DFS(G, i);
	}
}
bool BFSvisited[Max_Vertex_Num];
void BFSTraverse(ALGraph  G)
{
	ArcNode * p;
	queue<int>q;
	for (int i = 0; i<G.vexnum; i++)
		BFSvisited[i] = false;
	cout << "请输入起始节点：";
	int n;
	cin >> n;
	for (int i = n; i<G.vexnum; i++)
	{
		if (!BFSvisited[i])
		{
			BFSvisited[i] = true;
			cout << G.vertices[i].data << "  ";
			q.push(i);
			while (!q.empty())
			{
				int count = q.front();
				q.pop();
				p = G.vertices[count].firstarc;
				while (p)
				{
					if (!BFSvisited[p->adjvex])
					{
						BFSvisited[p->adjvex] = true;
						cout << G.vertices[p->adjvex].data << "  ";
						q.push(p->adjvex);
					}
					p = p->nextarc;
				}
			}
		}
	}
	for (int i = 0; i<n; i++)
	{
		if (!BFSvisited[i])
		{
			BFSvisited[i] = true;
			cout << G.vertices[i].data << "  ";
			q.push(i);
			while (!q.empty())
			{
				int count = q.front();
				q.pop();
				p = G.vertices[count].firstarc;
				while (p)
				{
					if (!BFSvisited[p->adjvex])
					{
						BFSvisited[p->adjvex] = true;
						cout << G.vertices[p->adjvex].data << "  ";
						q.push(p->adjvex);
					}
					p = p->nextarc;
				}
			}
		}
	}
}
int main()
{
	ALGraph test;
	CreateGraph(test);
	cout << "深度优先遍历：" << endl;
	DFSTraverse(test);
	cout << endl;
	cout << "广度度优先遍历：" << endl;
	BFSTraverse(test);
    return 0;
}

