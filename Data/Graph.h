#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f

enum GraphStyle // 图的类型
{
    DG = 1,  // 有向图
    DN = 2,  // 有向网
    UDG = 3, // 无向图
    UDN = 4  // 无向网
};

class Graph
{
private:
    GraphStyle style;              // 图的类型
    int numVertices;               // 顶点个数
    int numEdges;                  // 边或弧的条数
    vector<char> vertices;         // 顶点数组
    vector<vector<int>> adjMatrix; // 邻接矩阵 行表示出度，列表示入度
    void DFS(int, vector<int> &);  //DFS内部实现
    void BFS(int, vector<int> &);  //BFS内部实现
    // vector<int> *vis;

public:
    Graph(GraphStyle s = DG, int NV = 0); //构造函数
    void init(GraphStyle s, int NV);      //初始化
    GraphStyle GetStyle() { return style; }
    char GetNode(int i) { return vertices[i]; }
    int GetnumEdges() { return numEdges; }       //获取边数
    int GetnumVertices() { return numVertices; } //获取节点数
    bool addGEdge(char, char);                   //添加图边
    bool addNEdge(char, char, int);              //添加网边
    void Show();                                 //显示邻接矩阵
    bool addNode(char);                          //插入节点
    bool DeleteNode(char);                       //删除节点
    bool DeleteEdge(char, char);                 //删除边
    bool FindNode(char);                         //查找节点
    bool FindNode(char, int &);                  //查找节点 并返回距离
    int GetInDegree(char);                       //获取入度
    int GetOutDegree(char);                      //获取出度
    void BFS();                                  //BFS遍历外部接口
    void DFS();                                  //DFS遍历外部接口
    ~Graph()
    {
        numVertices = numEdges = 0;
    }
};

Graph::Graph(GraphStyle s, int NV)
{
    init(s, NV);
}
void Graph::init(GraphStyle s, int NV)
{
    adjMatrix.clear();
    style = s;
    for (int i = 0; i < NV; i++)
        vertices.push_back('A' + i);
    numVertices = NV;
    for (int i = 0; i < NV; i++)
    {
        if (s == DN || s == UDN)
        {
            vector<int> temp(NV, inf);
            adjMatrix.push_back(temp);
        }
        else if (s == DG || s == UDG)
        {
            vector<int> temp(NV, 0);
            adjMatrix.push_back(temp);
        }
    }
    if (s == DN || s == UDN)
        for (int i = 0; i < NV; i++)
            adjMatrix[i][i] = 0;
    numEdges = 0;
}
bool Graph::FindNode(char x)
{
    vector<char>::iterator iter = find(vertices.begin(), vertices.end(), x);
    if (iter == vertices.end())
    {
        cout << "Can't find the vertice." << endl;
        return false;
    }
    return true;
}
bool Graph::FindNode(char x, int &dis)
{
    vector<char>::iterator iter = find(vertices.begin(), vertices.end(), x);
    if (iter == vertices.end())
    {
        cout << "Can't find the vertice." << endl;
        return false;
    }
    else
        dis = distance(vertices.begin(), iter);
    return true;
}
bool Graph::addGEdge(char start, char end)
{
    int StartIndex;
    int EndIndex;
    FindNode(end);
    if (!FindNode(start, StartIndex))
    {
        cout << "Can't find the start vertice." << endl;
        return false;
    }

    if (!FindNode(end, EndIndex))
    {
        cout << "Can't find the end vertice." << endl;
        return false;
    }
    numEdges++;
    if (style == UDG)
    {
        adjMatrix[StartIndex][EndIndex] = 1;
        adjMatrix[EndIndex][StartIndex] = 1;
        return true;
    }
    else if (style == DG)
    {
        adjMatrix[StartIndex][EndIndex] = 1;
        return true;
    }
    return false;
}
bool Graph::addNEdge(char start, char end, int power)
{
    int StartIndex;
    int EndIndex;
    if (!FindNode(start, StartIndex))
    {
        cout << "Can't find the start vertice." << endl;
        return false;
    }

    if (!FindNode(end, EndIndex))
    {
        cout << "Can't find the end vertice." << endl;
        return false;
    }
    numEdges++;
    if (style == UDN)
    {
        adjMatrix[StartIndex][EndIndex] = power;
        adjMatrix[EndIndex][StartIndex] = power;
        return true;
    }
    else if (style == DN)
    {
        adjMatrix[StartIndex][EndIndex] = power;
        return true;
    }
    return false;
}
void Graph::Show()
{
    cout << "\t";
    for (int i = 0; i < numVertices; i++)
        cout << vertices[i] << "\t";
    cout << endl;
    for (int i = 0; i < numVertices; i++)
    {
        cout << vertices[i] << "\t";
        for (int j = 0; j < numVertices; j++)
        {
            if (adjMatrix[i][j] == inf)
                cout << "oo"
                     << "\t";
            else
                cout << adjMatrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
bool Graph::addNode(char Node)
{
    if (FindNode(Node))
    {
        vertices.push_back(Node);
        for (int i = 0; i < numVertices; i++)
            adjMatrix[i].push_back(0);
        numVertices++;
        vector<int> temp(numVertices, 0);
        adjMatrix.push_back(temp);
        return true;
    }
    else
    {
        cout << "the Node has existed." << endl;
        return false;
    }
    return false;
}

bool Graph::DeleteNode(char Node)
{
    vector<char>::iterator iter = find(vertices.begin(), vertices.end(), Node);
    int dis = distance(vertices.begin(), iter);
    if (iter == vertices.end())
    {
        cout << "Can't find the Node." << endl;
        return false;
    }
    else
    {
        int Indegree = this->GetInDegree(Node);
        int Outdegree = this->GetOutDegree(Node);
        numEdges = numEdges - Indegree - Outdegree;
        vertices.erase(iter);
        adjMatrix.erase(adjMatrix.begin() + dis);
        numVertices--;
        for (int i = 0; i < numVertices; i++)
            adjMatrix[i].erase(adjMatrix[i].begin() + dis);
    }
    return true;
}
bool Graph::DeleteEdge(char start, char end)
{
    int StartIndex;
    int EndIndex;
    if (!FindNode(start, StartIndex))
    {
        cout << "Can't find the start vertice." << endl;
        return false;
    }

    if (!FindNode(end, EndIndex))
    {
        cout << "Can't find the end vertice." << endl;
        return false;
    }
    numEdges++;

    if (style == UDN)
    {
        adjMatrix[StartIndex][EndIndex] = inf;
        adjMatrix[EndIndex][StartIndex] = inf;
        return true;
    }
    else if (style == DN)
    {
        adjMatrix[StartIndex][EndIndex] = inf;
        return true;
    }
    else if (style == UDG)
    {
        adjMatrix[StartIndex][EndIndex] = 0;
        adjMatrix[EndIndex][StartIndex] = 0;
        return true;
    }
    else if (style == DG)
    {
        adjMatrix[StartIndex][EndIndex] = 0;
        return true;
    }
    numEdges--;
    return false;
}

int Graph::GetOutDegree(char x)
{
    vector<char>::iterator iter = find(vertices.begin(), vertices.end(), x);
    if (iter == vertices.end())
    {
        cout << "Can't find the Node." << endl;
        return -1;
    }
    else
    {
        // 获取该节点在数组中的下标
        int dis = distance(vertices.begin(), iter);
        int count = 0;
        for (int i = 0; i < numVertices; i++)
            if (style == DG || style == UDG)
            {
                if (adjMatrix[dis][i] == 1)
                    count++;
            }
            else if (style == DN || style == UDN)
            {
                if (adjMatrix[dis][i] != inf)
                    count++;
            }
        return count - 1;
    }
}
int Graph::GetInDegree(char x)
{
    vector<char>::iterator iter = find(vertices.begin(), vertices.end(), x);
    if (iter == vertices.end())
    {
        cout << "Can't find the Node." << endl;
        return -1;
    }
    else
    {
        int dis = distance(vertices.begin(), iter);
        int count = 0;
        for (int i = 0; i < numVertices; i++)
            if (style == DG || style == UDG)
            {
                if (adjMatrix[i][dis] == 1)
                    count++;
            }
            else if (style == DN || style == UDN)
            {
                if (adjMatrix[i][dis] != inf)
                    count++;
            }
        return count - 1;
    }
}

void Graph::BFS()
{
    queue<int> q;
    vector<int> vis(numVertices, 0);
    for (int i = 0; i < numVertices; i++)
        BFS(i, vis);
    cout << endl;
}
void Graph::BFS(int n, vector<int> &vis)
{
    queue<int> q;
    if (vis[n] == 0)
        q.push(n);
    while (!q.empty())
    {
        int cur = q.front();
        cout << vertices[cur] << " ";
        vis[cur] = 1;
        for (int i = 0; i < numVertices; i++)
            if (!vis[cur] && adjMatrix[cur][i])
                q.push(adjMatrix[cur][i]);
        q.pop();
    }
}
void Graph::DFS()
{
    vector<int> vis(numVertices, 0);
    for (int i = 0; i < numVertices; i++)
        if (!vis[i])
            DFS(i, vis);
    cout << endl;
}
void Graph::DFS(int n, vector<int> &vis)
{
    cout << vertices[n] << " ";
    vis[n] = 1;
    for (int i = 0; i < numVertices; i++)
    {
        if (!vis[i] && adjMatrix[n][i] && adjMatrix[n][i] != inf)
        {
            DFS(i, vis);
        }
    }
}
// int main()
// {
//     Graph G1(DG, 2);
//     G1.addGEdge('a', 'b');
//     G1.Show();
//     G1.addNode('a');
//     G1.Show();
// }