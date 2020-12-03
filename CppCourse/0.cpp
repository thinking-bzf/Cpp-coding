#include <iostream>
#include <string>
using namespace std;
struct List
{
    int *list;
    int length;
};
void Listinit(List *L, int *a, int len)
{

    L->list = new int[len];
    L->length = len;
    for (int i = 0; i < len; i++)
        L->list[i] = a[i];
}
bool get(List L, int i, int &e)
{
    if (i < 0 || i > L.length - 1)
        return false;
    e = L.list[i];
    return true;
}
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    struct List L;
    Listinit(&L, a, 5);
    int r;
    get(L, 1, r);
    cout << r << endl;
}