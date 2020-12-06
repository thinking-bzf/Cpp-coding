#include <iostream>
#include <string.h>
#include "Graph.h"
using namespace std;
void input(int *x, int start, int end);
void ShowMenu();
void CreateUG(Graph &);           //创建无向图
void CreateUN(Graph &);           //创建无向网
void CreateDN(Graph &);           //创建有向图
void CreateDG(Graph &);           //创建有向网
void ShowMatrix(Graph &);         //显示存储矩阵
void GraphTraverse(Graph &);      //图的遍历
void InsertVertices(Graph &);     //插入节点
void InsertEdge(Graph &);         //插入边
void DeleteVertices(Graph &);     //删除节点
void DeleteEdge(Graph &);         //删除边
void MinSpanningTree(Graph &);    //最小生成树
void TopologicalSorting(Graph &); //拓扑排序
void Dijkstra(Graph &);           //最短路径(Dijkstra)
void Floyd(Graph &);              //最短路径(Floyd)
void OptimalAddress(Graph &);     //最优地址

int main()
{
    int choice;
    Graph G;
    while (1)
    {
        int size;
        ShowMenu();
        cout << "\nPlease input a integer from 1 to 16 for choice:";
        input(&choice, 1, 16);
        if (choice == 16)
            break;
        switch (choice)
        {
        case 1:
            // 创建无向图
            CreateUG(G);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 2:
            // 创建无向网
            CreateUN(G);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 3:
            // 创建有向图
            CreateDG(G);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 4:
            // 创建有向网
            CreateDN(G);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 5:
            // 显示存储矩阵
            ShowMatrix(G);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 6:
            // 图的遍历
            GraphTraverse(G);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 7:
            // 插入顶点
            InsertVertices(G);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 8:
            // 插入边
            InsertEdge(G);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 9:
            // 删除顶点
            DeleteVertices(G);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 10:
            // 删除边
            DeleteEdge(G);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 11:
            // 最小生成树
            MinSpanningTree(G);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 12:
            // 拓扑排序
            TopologicalSorting(G);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 13:
            // 最短路径(Dijkstra)
            Dijkstra(G);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 14:
            // 最短路径(Floyd)
            Floyd(G);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 15:
            // 最优选址
            OptimalAddress(G);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        }
    }
    return 0;
}
void ShowMenu()
{
    cout << "*********************I Love JLJ*************************" << endl;
    cout << endl;
    cout << "***********************Graph System*********************" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     1. Create UG           2. Create UN              *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     3. Create DG           4. Create DN              *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     5. Show Matrix         6. BFS/DFS                *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     7. Insert Vertices     8. Insert Edge            *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     9. Delete Vertices    10. Delete Edge            *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*    11. Min-Spanning Tree  12. Topological Sorting    *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*    13. Dijkstra           14. Floyd                  *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*    15. Optimal Address    16. Exit                   *" << endl;
    cout << "*                                                      *" << endl;
    cout << "********************************************************" << endl;
}
void input(int *x, int start = 1, int end = 2333)
{
    while (!(cin >> *x) || (*x < start) || (*x > end))
    {
        // 确保获取的是整数
        cout << "InputError:please input again";
        cin.clear(); //恢复错误的状态
        cin.sync();  //清楚之前的输入数据
    }
}
void CreateUG(Graph &G) //创建无向图
{
    getchar();
    cout << "=================Create Undirected Graph==================" << endl;
    cout << "--------------Press Enter for default Graph---------------" << endl;
    cout << "Please input the Node of the Graph:";
    char s[200];
    int NodeCount;
    int EdgeCount;
    cin.getline(s, 200);
    string x(s);
    if (x.empty())
    {
        G.init(UDG, 6);
        G.addGEdge('C', 'B');
        G.addGEdge('D', 'B');
        G.addGEdge('E', 'C');
        G.addGEdge('E', 'C');
        G.addGEdge('E', 'D');
        G.addGEdge('F', 'C');
        G.addGEdge('F', 'D');
        G.addGEdge('F', 'E');
        cout << "Create Graph successfully." << endl;
        cout << "The current Graph is:" << endl;
        G.Show();
    }
    else
    {
        NodeCount = stoi(x);
        cout << "Please input the count of the Edges:";
        cin >> EdgeCount;
        G.init(UDG, NodeCount);
        for (int i = 0; i < EdgeCount; i++)
        {
            char s, e;
            cout << "Please input the first of the edges:";
            cin >> s;
            cout << "Please input the second of the edges:";
            cin >> e;
            G.addGEdge(s, e);
        }
    }
    cout << "The Graph has " << G.GetnumVertices() << " Nodes, " << G.GetnumEdges() << " Edges." << endl;
}
void CreateUN(Graph &G) //创建无向网
{
    getchar();
    cout << "=================Create Undirected Network==================" << endl;
    cout << "--------------Press Enter for default Network---------------" << endl;
    cout << "Please input the Node of the Network:";
    char s[200];
    int NodeCount;
    int EdgeCount;
    cin.getline(s, 200);
    string x(s);
    if (x.empty())
    {
        G.init(UDN, 6);
        G.addNEdge('E', 'D', 3);
        G.addNEdge('C', 'B', 1);
        cout << "Create Network successfully." << endl;
        cout << "The current Network is:" << endl;
        G.Show();
    }
    else
    {
        NodeCount = stoi(x);
        cout << "Please input the count of the Edges:";
        cin >> EdgeCount;
        G.init(UDN, NodeCount);
        for (int i = 0; i < EdgeCount; i++)
        {
            char s, e;
            int value;
            cout << "Please input the first of the edges:";
            cin >> s;
            cout << "Please input the second of the edges:";
            cin >> e;
            input(&value);
            G.addNEdge(s, e, value);
        }
    }
    cout << "The Network has " << G.GetnumVertices() << " Nodes, " << G.GetnumEdges() << " Edges." << endl;
}
void CreateDG(Graph &G) //创建有向图
{
    getchar();
    cout << "=================Create directed Graph====================" << endl;
    cout << "--------------Press Enter for default Graph---------------" << endl;
    cout << "Please input the Node of the Graph:";
    char s[200];
    int NodeCount;
    int EdgeCount;
    cin.getline(s, 200);
    string x(s);
    if (x.empty())
    {
        G.init(DG, 6);
        G.addGEdge('A', 'D');
        G.addGEdge('A', 'F');
        G.addGEdge('B', 'C');
        G.addGEdge('B', 'F');
        G.addGEdge('C', 'D');
        G.addGEdge('D', 'C');
        G.addGEdge('E', 'A');
        G.addGEdge('E', 'B');
        G.addGEdge('F', 'D');
        cout << "Create Graph successfully." << endl;
        cout << "The current Graph is:" << endl;
        G.Show();
    }
    else
    {
        NodeCount = stoi(x);
        cout << "Please input the count of the Edges:";
        cin >> EdgeCount;
        G.init(UDG, NodeCount);
        for (int i = 0; i < EdgeCount; i++)
        {
            char s, e;
            cout << "Please input the start of the edges:";
            cin >> s;
            cout << "Please input the end of the edges:";
            cin >> e;
            G.addGEdge(s, e);
        }
    }
    cout << "The Graph has " << G.GetnumVertices() << " Nodes, " << G.GetnumEdges() << " Edges." << endl;
}
void CreateDN(Graph &G) //创建有向网
{

    getchar();
    cout << "===================Create directed Network================" << endl;
    cout << "--------------Press Enter for default Network-------------" << endl;
    cout << "Please input the Node of the Graph:";
    char s[200];
    int NodeCount;
    int EdgeCount;
    cin.getline(s, 200);
    string x(s);
    if (x.empty())
    {
        G.init(DN, 6);
        G.addNEdge('A', 'E', 3);
        G.addNEdge('B', 'E', 7);
        G.addNEdge('B', 'F', 4);
        G.addNEdge('C', 'D', 2);
        G.addNEdge('C', 'F', 6);
        G.addNEdge('E', 'F', 2);
        G.addNEdge('D', 'A', 5);
        G.addNEdge('D', 'C', 5);
        G.addNEdge('D', 'E', 3);
        G.addNEdge('F', 'B', 8);
        G.addNEdge('F', 'C', 7);
        G.addNEdge('F', 'D', 6);
        cout << "Create Network successfully." << endl;
        cout << "The current Network is:" << endl;
        G.Show();
    }
    else
    {
        NodeCount = stoi(x);
        cout << "Please input the count of the Edges:";
        cin >> EdgeCount;
        G.init(DN, NodeCount);
        for (int i = 0; i < EdgeCount; i++)
        {
            char s, e;
            int value;
            cout << "Please input the start of the edges:";
            cin >> s;
            cout << "Please input the end of the edges:";
            cin >> e;
            input(&value);
            G.addNEdge(s, e, value);
        }
    }
    cout << "The Network has " << G.GetnumVertices() << " Nodes, " << G.GetnumEdges() << " Edges." << endl;
}
void ShowMatrix(Graph &G) //显示存储矩阵
{
    cout << "The current Graph/Network is:" << endl;
    G.Show();
    cout << "The Network has " << G.GetnumVertices() << " Nodes, " << G.GetnumEdges() << " Edges." << endl;
    cout << "The Drgree of the Node is:" << endl;
    for (int i = 0; i < G.GetnumVertices(); i++)
    {
        char Node = G.GetNode(i);
        int InDegree = G.GetInDegree(Node);
        int OutDegree = G.GetOutDegree(Node);
        GraphStyle style = G.GetStyle();
        if (style == DG || style == DN)
            cout << "The Degree of " << Node << " is :" << InDegree + OutDegree << "; InDegree: " << InDegree << ",OutDegree: " << OutDegree << endl;
        if (style == UDG || style == UDN)
            cout << "The Degree of " << Node << " is :" << InDegree + OutDegree;
    }
}
void GraphTraverse(Graph &G) //图的遍历
{
    cout << "the BFS of Graph:";
    G.BFS();
    cout << endl;
    cout << "the DFS of Graph:";
    G.DFS();
    cout << endl;
}
void InsertEdge(Graph &G) //插入边
{
    GraphStyle style = G.GetStyle();

    if (style == DG || style == UDG)
    {
        char s, e;
        cout << "Please input the start of the edges to insert:";
        cin >> s;
        cout << "Please input the end of the edges to insert:";
        cin >> e;
        if (G.addGEdge(s, e))
            cout << "Insert successfully." << endl;
        else
            cout << "Fail to Insert." << endl;
    }
    else if (style == UDN || style == UDG)
    {
        char s, e;
        int value;
        cout << "Please input the start of the edges to insert:";
        cin >> s;
        cout << "Please input the end of the edges to insert:";
        cin >> e;
        input(&value);
        if (G.addNEdge(s, e, value))
            cout << "Insert successfully." << endl;
        else
            cout << "Fail to Insert." << endl;
    }
}
void InsertVertices(Graph &G) //插入节点
{
    char Node;
    cout << "Please input the Node wanted to insert:";
    cin >> Node;
    if (G.addNode(Node))
        cout << "Insert successfully." << endl;
    else
        cout << "Fail to Insert." << endl;
}
void DeleteEdge(Graph &G) //删除边
{
    GraphStyle style = G.GetStyle();
    if (style == DG || style == UDG)
    {
        char s, e;
        cout << "Please input the start of the edges to delete:";
        cin >> s;
        cout << "Please input the end of the edges to delete:";
        cin >> e;
        if (G.DeleteEdge(s, e))
            cout << "Delete successfully." << endl;
        else
            cout << "Fail to delete." << endl;
    }
    else if (style == UDN || style == UDG)
    {
        char s, e;
        int value;
        cout << "Please input the start of the edges to delete:";
        cin >> s;
        cout << "Please input the end of the edges to delete:";
        cin >> e;
        if (G.DeleteEdge(s, e))
            cout << "Delete successfully." << endl;
        else
            cout << "Fail to delete." << endl;
    }
}
void DeleteVertices(Graph &G) //删除节点
{
    getchar();
    char Node;
    cout << "Please input the Node wanted to delete:";
    cin >> Node;
    if (G.DeleteNode(Node))
        cout << "Delete successfully." << endl;
    else
        cout << "Fail to delete." << endl;
}
void MinSpanningTree(Graph &G) //最小生成树
{
    G.init(UDN, 6);
    G.addNEdge('A', 'B', 34);
    G.addNEdge('A', 'C', 46);
    G.addNEdge('A', 'F', 19);
    G.addNEdge('B', 'E', 12);
    G.addNEdge('C', 'D', 17);
    G.addNEdge('C', 'F', 25);
    G.addNEdge('D', 'E', 38);
    G.addNEdge('D', 'F', 25);
    G.addNEdge('E', 'F', 26);
    vector<pair<int, int>> MST = G.Prim();
    int sum = 0;
    for (int i = 0; i < MST.size(); i++) //按照放入MST的顺序依次输出
    {
        cout << G.GetNode(MST[i].first) << "->" << G.GetNode(MST[i].second)<<" value: " << G.GetEdgeValue(MST[i].first, MST[i].second) << endl;
        sum += G.GetEdgeValue(MST[i].first, MST[i].second);
    }
    cout << "the total value is " << sum << endl;
    vector<pair<int, int>> MST2 = G.Kruskal();
    sum = 0;
    for (int i = 0; i < MST2.size(); i++) //按照放入MST的顺序依次输出
    {
        cout << G.GetNode(MST2[i].first) << "->" << G.GetNode(MST2[i].second)<<" value: " << G.GetEdgeValue(MST2[i].first, MST2[i].second) << endl;
        sum += G.GetEdgeValue(MST2[i].first, MST2[i].second);
    }
    cout << "the total value is " << sum << endl;
}
void TopologicalSorting(Graph &) //拓扑排序
{
}
void Dijkstra(Graph &) //最短路径(Dijkstra)
{
}
void Floyd(Graph &) //最短路径(Floyd)
{
}
void OptimalAddress(Graph &) //最优地址
{
}