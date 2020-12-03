#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
class Node
{
private:
    Node<T> *next; //指向下一个节点的指针

public:
    T data;                                 //数据域
    Node(const T &data, Node<T> *next = 0); //构造函数
    void insertAfter(Node<T> *p);           //在本节点之后插入一个p节点
    Node<T> *deleteAfter();                 //删除本节点的后继节点，返回地址
    const Node<T> *nextNode() const;        //获取后继节点
    Node<T> *&nextNode();                   //获取后继节点
};

template <class T>
Node<T>::Node(const T &data, Node<T> *next) : data(data), next(next) {}

template <class T>
void Node<T>::insertAfter(Node<T> *p)
{
    p->next = this->next;
    this->next = p;
}

template <class T>
Node<T> *Node<T>::deleteAfter()
{
    Node<T> *temp = next;
    if (next == 0)
        return 0;
    next = temp->next;
    return *temp;
}

template <class T>
const Node<T> *Node<T>::nextNode() const
{
    return next;
}

template <class T>
Node<T> *&Node<T>::nextNode()
{
    return next;
}

//define LinkedList
template <class T>
class LinkedList
{
private:
    Node<T> *front, *rear;      //表头和表尾指针
    Node<T> *prevPtr, *currPtr; //记录表当前遍历位置的指针，由插入和删除操作更新
    int size;                   //表中元素个数
    int position;               //当前元素的位置序号，由函数reset使用

    Node<T> *newNode(const T &item, Node<T> *ptrNext = NULL) { return new Node<T>(item, ptrNext); } //生成节点，数据为item指针域为ptrNext
    void freeNode(Node<T> *p) { delete p; }                                                         //释放节点
    void copy(const LinkedList<T> &L);                                                              //将L链表复制到当前表（假定当前表为空），被复制构造和函数“operator”调用

public:
    LinkedList() : front(NULL), rear(NULL), prevPtr(NULL), currPtr(NULL) { size = position = 0; } //构造函数
    LinkedList(const LinkedList<T> &L) { copy(L); }                                               //复制构造函数
    ~LinkedList() { clear(); }                                                                    //析构链表
    LinkedList<T> &operator=(const LinkedList<T> &L)                                              //重载赋值链表
    {
        clear();
        copy(L);
        return *this;
    }
    int getSize() const { return size; }                           //得到链表元素个数
    bool isEmpty() const { return (size == 0); }                   //判断链表是否为空
    void reset(int pos = 0);                                       //初始化游标的位置
    void next();                                                   //使游标移动到下一个节点
    bool endOfList() const { return currPtr->nextNode() == NULL; } //判断游标是否到链表尾部
    int currentPosition(void) const { return position; }           //返回游标当前位置
    void insertFront(const T &item);                               //在表头插入一个节点
    void insertRear(const T &item);                                //在表尾插入一个节点
    void insertAt(const T &item);                                  //在当前节点前插入一个节点
    void insertAfter(const T &item);                               //在当前节点后插入一个节点
    T deleteFront();                                               //删除表头节点
    void deleteCurrent();                                          //删除当前节点
    T &data() { return currPtr->data; }                            //返回当前节点数据的引用
    const T &data() const { return currPtr->data; }                //返回当前节点数据的常引用
    void clear();                                                  //清空链表
    void display() const;                                          //显示链表元素
    void insertlist(const LinkedList<T> &L);                       //在表后插入另一个链表
};
template <class T>
void LinkedList<T>::clear()
{
    Node<T> *tmp = front;
    while (front)
    {
        tmp = front;
        front = front->nextNode();
        freeNode(tmp);
    }
    front = rear = prevPtr = currPtr = 0;
}

template <class T>
void LinkedList<T>::copy(const LinkedList<T> &L)
{
    Node<T> *tmp = NULL, *cur = NULL, *pre = NULL;
    int pos = L.currentPosition();
    int i = 0;
    tmp = L.front;
    while (tmp)
    {
        cur = newNode(tmp->data);
        if (i == 0)
        {
            front = cur;
        }
        else
        {
            pre->insertAfter(cur);
            if (pos == i) //if用来复制位置
            {
                prevPtr = pre;
                currPtr = cur;
            }
        }
        pre = cur;
        rear = cur;
        tmp = tmp->nextNode();
        i++;
    }
    position = pos;
    size = L.size;
}

template <class T>
void LinkedList<T>::reset(int pos)
{
    Node<T> *tmp = front;
    int i = 0;
    assert(pos >= 0 && pos < size);

    while (i <= pos)
    {
        if (i == 0)
            currPtr = prevPtr = tmp;
        else
        {
            currPtr = prevPtr;
            prevPtr = tmp;
        }
        tmp = tmp->nextNode();
        i++;
    }
    position = pos;
}
template <class T>
T LinkedList<T>::deleteFront()
{
    Node<T> *tmp = NULL;
    T res; //记录被删除的元素值
    assert(front || size = 0);

    tmp = front;
    res = tmp->data;
    front = front->nextNode();
    freeNode(tmp);
    size -= 1;
    position = 0;

    return res;
}

template <class T>
void LinkedList<T>::deleteCurrent()
{
    assert(currPtr);
    Node<T> *tmp = currPtr->nextNode();

    if (currPtr == front)
        deleteFront();
    else
    {
        freeNode(currPtr->deleteAfter());
        currPtr = tmp;
    }
    size -= 1;
}

template <class T>
void LinkedList<T>::insertAfter(const T &item)
{
    if (currPtr)
    {
        currPtr->insertAfter(newNode(item));
        prevPtr = currPtr;
        currPtr = currPtr->nextNode();
        rear = currPtr;
        position++;
    }
    else
        prevPtr = front = rear = currPtr = newNode(item);
    size++;
}
template <class T>
void LinkedList<T>::insertFront(const T &item)
{
    Node<T> *tmp = front;
    Node<T> *newnode = newNode(item);

    newnode->nextNode() = front;
    if (front == NULL)
        rear = newnode;
    front = newnode;
    currPtr = front;
    prevPtr = front;
    size++;
    position = 0;
}

template <class T>
void LinkedList<T>::insertRear(const T &item)
{
    Node<T> *tmp = rear;
    Node<T> *newnode = newNode(item);

    if (rear)
    {
        rear->nextNode() = newnode;
        prevPtr = rear;
        rear = newnode;
    }
    else
    {
        rear = newnode;
        prevPtr = rear;
        front = rear;
    }
    currPtr = rear;
    size++;
    position = size - 1;
}
template <class T>
void LinkedList<T>::next()
{
    assert(currPtr);
    if (currPtr->nextNode() == NULL)
    {
        cout << "This is the last item" << endl;
        return;
    }
    else
    {
        prevPtr = currPtr;
        currPtr = currPtr->nextNode();
        position++;
    }
}

template <class T>
void LinkedList<T>::display() const
{
    Node<T> *tmp = front;

    if (front == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }

    while (tmp)
    {
        cout << tmp->data << " ";
        tmp = tmp->nextNode();
    }
    cout << endl;
}

template <class T>
void LinkedList<T>::insertAt(const T &item)
{
    Node<T> *tmp = currPtr;
    Node<T> *newnode = newNode(item);

    if (prevPtr)
    {
        prevPtr->nextNode() = newnode;
        newnode->nextNode() = currPtr;
        currPtr = newnode;
        position--;
    }
    else
    {
        front = currPtr = prevPtr = rear = newnode;
    }
    size++;
}

template <class T>
void LinkedList<T>::insertlist(const LinkedList &L)
{
    Node<T> *tmp = L.front;
    Node<T> *last = rear;
    while (tmp)
    {
        last->nextNode() = newNode(tmp->data);
        last = last->nextNode();
        tmp = tmp->nextNode();
        size++;
        position++;
    }
    rear = last;

}

int main()
{
    LinkedList<int> a, b;
    int m, n;
    for (int i = 0; i < 5; i++)
    {
        cout << "Input the a and b:" << endl;
        cin >> m >> n;
        a.insertAfter(m);
        b.insertAfter(n);
    }
    a.insertlist(b);
    cout << "a inserted b: ";
    a.display();
    return 0;
}