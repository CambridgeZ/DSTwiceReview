//
// Created by Mac on 2023/4/16.
//

#include <iostream>
using namespace std;

struct Graph {
    int n, m;//n个顶点，m条边
    int **edge;
};

struct Graph *createGraph(int n, int m) {
    struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph));
    graph->n = n;
    graph->m = m;
    graph->edge = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        graph->edge[i] = (int *) malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            graph->edge[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(struct Graph *graph, int u, int v, int w) {
    graph->edge[u][v] = w;
    graph->edge[v][u] = w;
}

int Find(int unionfindset[],int n,int i) {
    if(i>n||i<0)
        return -1;
    while(unionfindset[i]>0)
        i=unionfindset[i];
    return i;
}

void Union(int unionfindset[],int n,int x,int y){
    int rootx= Find(unionfindset,n,x);
    int rooty= Find(unionfindset,n,y);
    if(rootx==-1||rooty==-1)
        return ;
    unionfindset[rooty]=rootx;
}

//Kruskal
int Kruskal(int n,Graph *graph){
    int unionfindset[n];
    for(int i=0;i<n;i++)
        unionfindset[i]=0;
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph->edge[i][j]!=0){
                int rooti=Find(unionfindset,n,i);
                int rootj=Find(unionfindset,n,j);
                if(rooti!=rootj){
                    sum+=graph->edge[i][j];
                    Union(unionfindset,n,i,j);
                }
            }
        }
    }
    return sum;
}

//test

int main() {
    int n, m;
    cin >> n >> m;
    struct Graph *graph = createGraph(n, m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(graph, u, v, w);
    }
    cout << Kruskal(n,graph);
    return 0;
}