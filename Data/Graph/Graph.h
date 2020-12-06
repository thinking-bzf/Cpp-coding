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
struct Edge
{
    int start, end, value;
};
bool compare(Edge e1, Edge e2)
{
    return e1.value < e2.value;
}
class Graph
{
private:
    GraphStyle style;                              // 图的类型
    int numVertices;                               // 顶点个数
    int numEdges;                                  // 边或弧的条数
    vector<char> vertices;                         // 顶点数组
    vector<vector<int>> adjMatrix;                 // 邻接矩阵 行表示出度，列表示入度
    vector<Edge> Edges;                            //存放边的结构体
    vector<int> set;                               //并查集数组
    void DFS(int, vector<int> &);                  //DFS内部实现
    void BFS(int, vector<int> &);                  //BFS内部实现
    pair<int, int> GetshortestRdge(vector<int> &); //寻找最短路径
    int findx(int x);                              //并查集查找操作
    bool merge(int x, int y);                      //并查集合并操作

public:
    Graph(GraphStyle s = DG, int NV = 0); //构造函数
    void init(GraphStyle s, int NV);      //初始化
    GraphStyle GetStyle() { return style; }
    char GetNode(int i) { return vertices[i]; }
    int GetEdgeValue(int x, int y) { return adjMatrix[x][y]; } //获取边上的值
    int GetnumEdges() { return numEdges; }                     //获取边数
    int GetnumVertices() { return numVertices; }               //获取节点数
    bool addGEdge(char, char);                                 //添加图边
    bool addNEdge(char, char, int);                            //添加网边
    void Show();                                               //显示邻接矩阵
    bool addNode(char);                                        //插入节点
    bool DeleteNode(char);                                     //删除节点
    bool DeleteEdge(char, char);                               //删除边
    bool FindNode(char);                                       //查找节点
    bool FindNode(char, int &);                                //查找节点 并返回距离
    int GetInDegree(char);                                     //获取入度
    int GetOutDegree(char);                                    //获取出度
    void BFS();                                                //BFS遍历外部接口
    void DFS();                                                //DFS遍历外部接口
    vector<pair<int, int>> Prim();                             //Prim实现
    vector<pair<int, int>> Kruskal();
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
        Edge temp;
        temp.start = StartIndex;
        temp.end = EndIndex;
        temp.value = power;
        Edges.push_back(temp);
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
            DFS(i, vis);
    }
}
// 找到属于生成图和不属于生成图之间最短的路径
pair<int, int> Graph::GetshortestRdge(vector<int> &included)
{
    int min = inf - 1000;
    int MinID = -1;
    pair<int, int> minEdge;
    for (int i = 0; i < numVertices; i++) //i为在MST中的节点
    {
        if (!included[i])
            continue;

        for (int j = 0; j < numVertices; j++)
        {
            if (adjMatrix[i][j] < min && !included[j]) //找到没有在生成树中的节点与在生成树中的节点边的最小值
            {
                MinID = j;
                min = adjMatrix[i][j];
                minEdge = make_pair(i, j);
            }
        }
    }
    if (MinID > 0)
        included[MinID] = 1;
    return minEdge;
}

vector<pair<int, int>> Graph::Prim()
{
    vector<int> included(numVertices, 0);
    vector<pair<int, int>> MST;
    //先假设第一个节点被放进最小生成树
    included[0] = 1;
    // 只要构造n-1条边
    for (int i = 0; i < numVertices - 1; i++)
    {
        pair<int, int> minEdge = GetshortestRdge(included);
        MST.push_back(minEdge);
    }
    return MST;
}

int Graph::findx(int x)
{
    int r = x;
    while (set[r] != r)
        r = set[r];
    return r;
}
bool Graph::merge(int x, int y)
{
    // 如果老大不一样，那就归并在一起，某个元素跟随另外一个元素作为子老大
    if (findx(x) != findx(y))
    {
        set[x] = y;
        return true;
    }
    return false;
}

vector<pair<int, int>> Graph::Kruskal()
{
    vector<pair<int, int>> MST;
    set.assign(numVertces, 0);
    for (int i = 0; i < numVertices; i++)
        set[i] = i;
    sort(Edges.begin(), Edges.end(), compare);
    for (int i = 0; i < Edges.size(); i++)
    {
        if(merge(Edges[i].start, Edges[i].end))
            MST.push_back(make_pair(Edges[i].start,Edges[i].end));
    }
    return MST;
}
// int main()
// {
//     Graph G1(DG, 2);
//     G1.addGEdge('a', 'b');
//     G1.Show();
//     G1.addNode('a');
//     G1.Show();
// }