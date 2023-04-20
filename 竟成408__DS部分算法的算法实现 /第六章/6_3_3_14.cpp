//
// Created by Mac on 2023/4/20.
//
#include <iostream>
#include <stack>

using namespace std;
//邻接表存储图
typedef struct ArcNode {
    int adjvex;//该弧所指向的顶点的位置
    struct ArcNode *nextarc;//指向下一条弧的指针
    int info;//网的权值
} ArcNode;

typedef struct VNode {
    char data;//顶点信息
    ArcNode *firstarc;//指向第一条依附该顶点的弧的指针
} VNode, AdjList[100];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;//图的当前顶点数和弧数
} ALGraph;

void CreateUDG(ALGraph &G) {
    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; i++) {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    for (int k = 0; k < G.arcnum; k++) {
        int i, j;
        cin >> i >> j;
        ArcNode *p = new ArcNode;
        p->adjvex = j;
        p->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p;
        p = new ArcNode;
        p->adjvex = i;
        p->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p;
    }
}

void DSK(ALGraph G, int v) {
    int visited[100] = {0};
    stack<int> s;
    s.push(v);
    visited[v] = 1;
    while (!s.empty()) {
        int i = s.top();
        s.pop();
        cout << G.vertices[i].data;
        ArcNode *p = G.vertices[i].firstarc;
        while (p != NULL) {
            if (visited[p->adjvex] == 0) {
                s.push(p->adjvex);
                visited[p->adjvex] = 1;
            }
            p = p->nextarc;
        }
    }
}

//test
/*
6 7
A B C D E F
0 1
0 2
1 3
1 4
2 4
3 5
4 5
 */

int main() {
    ALGraph G;
    CreateUDG(G);
    DSK(G, 0);
    return 0;
}
