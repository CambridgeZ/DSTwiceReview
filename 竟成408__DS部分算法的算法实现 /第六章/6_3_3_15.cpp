//
// Created by Mac on 2023/4/20.
//
#include <iostream>
#include <queue>

using namespace std;

//邻接矩阵存储的图
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
int visited[100];

void BFS(Graph M,int i);

void isExistPathFromiToj(Graph M,int i,int j){
    memset(visited,0, sizeof(visited));
    BFS(M,i);
    if(visited[j]==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

void BFS(Graph M,int i){
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        for(int j=0;j<M.n;j++){
            if(M.edge[i][j]!=0&&visited[j]==0){
                q.push(j);
                visited[j]=1;
            }
        }
    }
}

//test
int main() {
    int n, m;
    cin >> n >> m;
    Graph M = *createGraph(n, m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        M.edge[u][v] = 1;
        M.edge[v][u] = 1;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        isExistPathFromiToj(M,u,v);
    }
    return 0;
}
/*
input:
6 7
0 1
0 2
0 3
1 2
1 4
2 3
3 5
3
0 5
1 5
2 5
output:
YES
 */
