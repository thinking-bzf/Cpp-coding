#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
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
// 用来记录到某个点的最短路径
struct dist
{
    int prePos; //最短路径中该节点的前一个节点
    int value;  //该路径的距离
    bool visit; //判断是否被访问
};

struct Node
{
    int value; //表示i-j的路径长度
    int pre;   //表示点i到点j的 "跳板"
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
    vector<pair<int, int>> Prim();                             //Prim实现最小生成树
    vector<pair<int, int>> Kruskal();                          //kursual 实现最小生成树
    vector<int> TopologicalSort();                             //拓扑排序
    vector<struct dist> Dijkstra(int);                         //最短路径的Dijkstra算法实现
    vector<vector<struct Node>> Floyd();                       //最短路径Floyd算法实现
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
                if (adjMatrix[dis][i] != inf && adjMatrix[i][dis] != 0)
                    count++;
            }
        return count;
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
                if (adjMatrix[i][dis] != inf && adjMatrix[i][dis] != 0)
                    count++;
            }
        return count;
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
        set[findx(x)] = findx(y);
        return true;
    }
    return false;
}

vector<pair<int, int>> Graph::Kruskal()
{
    vector<pair<int, int>> MST;
    set.assign(numVertices, 0);
    for (int i = 0; i < numVertices; i++)
        set[i] = i;
    sort(Edges.begin(), Edges.end(), compare);
    for (int i = 0; i < Edges.size(); i++)
    {
        if (merge(Edges[i].start, Edges[i].end))
            MST.push_back(make_pair(Edges[i].start, Edges[i].end));
    }
    return MST;
}

vector<int> Graph::TopologicalSort()
{
    vector<int> Degree;
    // 获取所有点的入度
    for (int i = 0; i < numVertices; i++)
        Degree.push_back(GetInDegree(vertices[i]));
    vector<vector<int>> temp = adjMatrix;
    stack<int> s;
    vector<int> vec;
    // 首先遍历全部节点查找入度为0的节点下标
    for (int i = 0; i < numVertices; i++)
        if (!Degree[i])
            s.push(i);

    int count = 0; // 用来计数的输出的顶点
    while (!s.empty())
    {
        int index = s.top();
        s.pop();
        vec.push_back(index);
        // 将该点去除 并遍历修改后的数组 压入入度为0的节点下标

        for (int i = 0; i < numVertices; i++)
        {
            if (adjMatrix[index][i] == 1)
            {
                adjMatrix[index][i] = 0;
                Degree[i]--;
                if (!Degree[i])
                    s.push(i);
            }
        }
        count++;
    }
    if (count == numVertices)
        cout << "There is no loop." << endl;
    else
        cout << "There is loop(s)" << endl;
    return vec;
}

vector<struct dist> Graph::Dijkstra(int begin)
{
    vector<struct dist> dis;
    // 初始化该点到到所有的点的距离
    for (int i = 0; i < numVertices; i++)
    {
        struct dist temp;
        temp.value = adjMatrix[begin][i];
        // 如果路径的长度是无限大则将该点的前向设成-1，否则将他的前向变成起点
        if (temp.value != inf)
            temp.prePos = begin;
        else
            temp.prePos = -1;
        temp.visit = false;
        dis.push_back(temp);
    }
    // 将初始点的访问状态设为真，表示起点到起点的距离为0
    dis[begin].visit = true;
    int count = 1;
    while (1)
    {
        // temp 用来存储当前dis数组中最小的下标
        int temp = -1;
        // min 表示当前dis数组中最小的值
        int min = inf;
        // 寻找当前dis数组的最小值
        for (int i = 0; i < numVertices; i++)
        {
            if (!dis[i].visit && dis[i].value < min)
            {
                min = dis[i].value;
                temp = i;
            }
        }
        // 如果找不到没有访问过的点，则退出循环
        if (temp == -1)
            break;
        // 将该节点的访问状态设为True
        dis[temp].visit = true;
        for (int i = 0; i < numVertices; i++)
        {
            // 对剩余出度点的遍历
            if (!dis[i].visit && adjMatrix[temp][i] != inf)
                // 如果存在一个点：目前存储的距离中，起点到temp，temp到i点的值(begin-...-temp-i)比begin-...-i的距离短，
                // 则将存储距离的数组中的值更新成较短的值，将i点的前向更新为temp
                if (dis[temp].value + adjMatrix[temp][i] < dis[i].value)
                {
                    dis[i].value = dis[temp].value + adjMatrix[temp][i];
                    dis[i].prePos = temp;
                }
        }
    }
    return dis;
}

vector<vector<struct Node>> Graph::Floyd()
{
    vector<vector<struct Node>> Dis;
    // 将图的邻接矩阵赋值给现在的矩阵
    for (int i = 0; i < numVertices; i++)
    {
        vector<struct Node> LsitTemp;
        for (int j = 0; j < numVertices; j++)
        {
            struct Node NodeTemp;
            NodeTemp.pre = i;
            NodeTemp.value = adjMatrix[i][j];
            LsitTemp.push_back(NodeTemp);
        }
        Dis.push_back(LsitTemp);
    }
    // k表示中间跳板节点 如果通过跳板的节点的路径比直接到达的路径长度短，就更新两者之间的距离
    // 并且把跳板的节点记录到pre中
    for (int k = 0; k < numVertices; k++)
        for (int i = 0; i < numVertices; i++)
            for (int j = 0; j < numVertices; j++)
                if (Dis[i][k].value != inf && Dis[k][j].value != inf && Dis[i][k].value + Dis[k][j].value < Dis[i][j].value)
                {
                    Dis[i][j].value = Dis[i][k].value + Dis[k][j].value;
                    Dis[i][j].pre = k;
                }
    return Dis;
}
