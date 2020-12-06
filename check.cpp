#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100 //队列的最大长度
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE]; //队列的存储空间
    int front, rear;        //队列的队头指针和队尾指针
} SqQueue;
//初始化队列
void Init_SqQueue(SqQueue *Q)
{
    Q->front = Q->rear = 0;
}
//判断队列是否为空
int Empty_SqQueue(SqQueue *Q)
{
    return Q->rear == Q->front; //为真，返回1 则表示队列为空
}
//数据 e 进队列
void In_SqQueue(SqQueue *Q, int e)
{
    if (Q->rear == MAXSIZE)
    {
        return;
    }
    Q->data[Q->rear] = e;
    Q->rear += 1;
}
//数据出队列，通过将出队列数据赋值给 e
void Out_SqQueue(SqQueue *Q, int *e)
{
    //出队之前，先判断队列是否为空
    if (Q->rear == Q->front)
    {
        return;
    }
    *e = Q->data[Q->front];
    Q->front += 1;
}
//表示农夫状态的函数，返回0 ，表示农夫在南岸，反之在北岸
int farmer(int location)
{
    return (0 != (location & 0x08));
}
//表示狼的状态的函数，返回0 ，表示农夫在南岸，反之在北岸
int wolf(int location)
{
    return (0 != (location & 0x04));
}
//表示白菜状态的函数，返回0 ，表示农夫在南岸，反之在北岸
int cabbage(int location)
{
    return (0 != (location & 0x02));
}
//表示羊状态的函数，返回0 ，表示农夫在南岸，反之在北岸
int goat(int location)
{
    return (0 != (location & 0x01));
}
//判断当前状态是否合理的函数
int safe(int location)
{
    //如果农夫不在羊身边，而羊和白菜在一起，则为不安全
    if (goat(location) == cabbage(location) && goat(location) != farmer(location))
    {
        return 0;
    }
    //如果农夫不在狼身边，而狼和羊在一起，也不安全
    if (goat(location) == wolf(location) && goat(location) != farmer(location))
    {
        return 0;
    }
    //其他情况都安全
    return 1;
}
//农夫过河的实现函数
void farmerproblem()
{
    int movers, location, newlocation;
    int route[16]; //用于记录已考虑的状态路径
    int i;
    SqQueue moveto;
    Init_SqQueue(&moveto);
    //以所有角色都在南岸开始
    In_SqQueue(&moveto, 0x00);
    //对记录路径的数组初始化
    for (i = 0; i < 16; i++)
    {
        route[i] = -1;
    }
    //记录所有角色都在南岸的路径
    route[0] = 0;
    while (!Empty_SqQueue(&moveto) && (route[15] == -1))
    {
        Out_SqQueue(&moveto, &location); //出队列，并将状态赋值给location
        //依次移动羊、白菜、狼和农夫，movers每次左移一位，所以其值每次为1,2,4,8
        int move[4] = {4, 2, 1, 8};
        // int i = 0;
        for (int i = 0; i < 4; i++)
        {
            movers = move[i];
            //判断农夫与要移动的角色是否位于河岸的同一侧
            if (((location & 0x08) != 0) == ((location & movers) != 0))
            {
                //若农夫与该角色在同一侧则尝试移至对岸（异或运算）
                newlocation = location ^ (0x08 | movers);
                //判断此移动是否安全
                if (safe(newlocation) && route[newlocation] == -1)
                {
                    //如果安全，且之前没有移动过，则进行记录，记录方法是在新位置记录之前的移动位置
                    route[newlocation] = location;
                    //将新的移动方案入队
                    In_SqQueue(&moveto, newlocation);
                }
            }
        }
    }
    //如果最终移动成功，即由 0000 变成 1111则视为成功
    if (route[15] != -1)
    {
        printf("the reverse path is :");
        for (i = 15; i >= 0; i = route[i])
        {
            printf("\n the location is:%d", i);
            if (i == 0)
            {
                break;
            }
        }
    }
    else
    {
        printf("no path");
    }
}
int main()
{
    farmerproblem();
    return 0;
}