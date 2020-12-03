#include <iostream>
using namespace std;

template <class T>
void Downsort(T a[], int n)
{
    int i = n - 1;
    int cnt = 1;
    while (i > 0)
    {
        int k = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                T temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
                k = j;
            }
            cout << "第" << cnt++ << "次: ";
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        i = k;
    }
}

int main()
{
    int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    Downsort(data, 20);
    return 0;
}