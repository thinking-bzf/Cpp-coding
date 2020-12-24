#include <stdio.h>
#define inf 0x3f3f3f3f
#define N 7
// #include <stdio.h>
#define MAX 100
#define MAXCOST 0x7fffffff
int vis[100]; //该顶点是否走过

typedef struct Edge
{
    int start, end, value;
} Edge;

typedef struct Graph
{
    int numVertices;       // 顶点个数
    int numEdges;          // 边或弧的条数
    char vertices[10];     // 顶点数组
    int adjMatrix[10][10]; // 邻接矩阵 行表示出度，列表示入度
} Graph;

struct MST
{
    Edge Edges[20];
    int size;
};

Graph G;

// 找到属于生成图和不属于生成图之间最短的路径
Edge GetshortestRdge()
{
    int min = inf - 1000;
    int MinID = -1;
    Edge minEdge;
    for (int i = 0; i < G.numVertices; i++) //i为在MST中的节点
    {
        if (!vis[i])
            continue;

        for (int j = 0; j < G.numVertices; j++)
        {
            if (G.adjMatrix[i][j] < min && !vis[j]) //找到没有在生成树中的节点与在生成树中的节点边的最小值
            {
                MinID = j;
                min = G.adjMatrix[i][j];
                minEdge.start = i;
                minEdge.end = j;
                minEdge.value = min;
            }
        }
    }
    if (MinID > 0)
        vis[MinID] = 1;
    return minEdge;
}

struct MST Prim()
{
    // vector<int> vis(numVertices, 0);
    struct MST mst;
    mst.size = 0;
    for (int i = 0; i < G.numVertices; i++)
        vis[i] = 0;
    // 先假设第一个节点被放进最小生成树
    vis[0] = 1;
    for (int i = 0; i < G.numVertices - 1; i++)
    {
        Edge temp;
        temp = GetshortestRdge();
        mst.Edges[i] = temp;
        mst.size++;
    }
    return mst;
}

int main()
{

    G.numVertices = 6;

    for (int i = 0; i < 6; i++)
        G.vertices[i] = 'A' + i;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            G.adjMatrix[i][j] = inf;
    G.adjMatrix[0][1] = 34; // ('A', 'B', 34);
    G.adjMatrix[1][0] = 34; // ('A', 'B', 34);
    G.adjMatrix[0][2] = 46; // ('A', 'C', 46);
    G.adjMatrix[2][0] = 46; // ('A', 'C', 46);
    G.adjMatrix[0][5] = 19; // ('A', 'F', 19);
    G.adjMatrix[5][0] = 19; // ('A', 'F', 19);
    G.adjMatrix[1][4] = 12; // ('B', 'E', 12);
    G.adjMatrix[4][1] = 12; // ('B', 'E', 12);
    G.adjMatrix[2][3] = 17; // ('C', 'D', 17);
    G.adjMatrix[3][2] = 17; // ('C', 'D', 17);
    G.adjMatrix[2][5] = 25; // ('C', 'F', 25);
    G.adjMatrix[5][2] = 25; // ('C', 'F', 25);
    G.adjMatrix[3][4] = 38; // ('D', 'E', 38);
    G.adjMatrix[4][3] = 38; // ('D', 'E', 38);
    G.adjMatrix[3][5] = 25; // ('D', 'F', 25);
    G.adjMatrix[5][3] = 25; // ('D', 'F', 25);
    G.adjMatrix[4][5] = 26; // ('E', 'F', 26);
    G.adjMatrix[5][4] = 26; // ('E', 'F', 26);
    struct MST result = Prim();
    // vector<pair<int, int>> MST = G.Prim();
    // cout << "The current Graph is:" << endl;
    printf("\t");
    for (int i = 0; i < 6; i++)
        printf("%c\t", 'A' + i);
    printf("\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%c\t", 'A' + i);
        for (int j = 0; j < 6; j++)
        {
            if (G.adjMatrix[i][j] == inf)
                printf("oo\t");
            else
                printf("%d\t", G.adjMatrix[i][j]);
        }
        printf("\n");
    }
    int sum = 0;
    for (int i = 0; i < result.size; i++) //按照放入MST的顺序依次输出
    {
        printf("%c -> %c value: %d\n", G.vertices[result.Edges[i].start], G.vertices[result.Edges[i].end], result.Edges[i].value);
        sum += G.vertices[result.Edges[i].value];
    }

    printf("the total value is %d\n", sum);
}
// G.Show();
// int sum = 0;
