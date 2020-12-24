#include <stdio.h>
#include <stdlib.h>

typedef struct SqList
{
    int *ptr;
    int len;  // 已存放数据的大小
    int size; // 表示最大可存放的大小
    SqList()
    {
        size = 5; //初始数组大小 初始最多能存储5个整数 下标0-5
        len = 0;
        ptr = (int *)malloc(size * sizeof(int));
    }
} List;

void display(List L);
// 扩展空间
void DoubleSize(List *L)
{
    int *newptr = (int *)malloc(2 * L->size * sizeof(int));
    for (int i = 0; i < L->len; i++)
        newptr[i] = L->ptr[i];
    L->size = L->size * 2 + 1;
    if (L->ptr)
        free(L->ptr);
    L->ptr = newptr;
    printf("创建两倍空间\n");
}

bool Insert(const int in, int index, List *L)
{
    if (index > L->len || index < 1)
    {
        printf("插入失败,下标超出范围\n");
        return false;
    }
    // 如果最大空间不够，则扩展两倍空间
    if (L->len >= L->size)
        DoubleSize(L);
    if (index == L->len)
    {
        // 如果插入的位置是末尾元素，则调用append方法
        L->ptr[L->len] = in;
        L->len++;
        return true;
        printf("插入成功\n");
    }
    else
    {
        // 每个在目标元素后面的元素往后移动
        for (int i = L->len - 1; i >= index - 1; i--)
        {
            L->ptr[i + 1] = L->ptr[i];
        }
        L->ptr[index - 1] = in;
        L->len++;
        printf("插入成功\n");
        return true;
    }
    printf("插入失败\n");
    return false;
}

bool Delete(int index, List *L)
{
    if (index > L->len || index < 1)
    {
        printf("删除失败,下标越界");
        return false;
    }
    for (int i = index - 1; i < L->len - 1; i++)
    {
        L->ptr[i] = L->ptr[i + 1];
    }
    L->len--;
    printf("删除成功\n");
    return true;
}

void LocateElem(const int in, List *L)
{
    for (int i = 0; i < L->len; i++)
    {
        if (L->ptr[i] == in)
        {
            printf("该元素在数组的第%d位，他的下标为%d\n", i + 1, i);
            return;
        }
    }
    printf("未找到该元素\n");
}
void display(List L)
{
    for (int i = 0; i < L.len; i++)
        printf("%d ", L.ptr[i]);
    printf("\n");
}
int main()
{
    List L;
    for (int i = 0; i < L.size; i++)
    {
        L.ptr[i] = i;
        L.len++;
    }
    display(L);
    printf("在数组第三位插入5:\n");
    Insert(5, 3, &L);
    display(L);
    printf("删除第五位数:\n");
    Delete(5, &L);
    display(L);
    printf("查找2的位置:\n");
    LocateElem(2, &L);
}
