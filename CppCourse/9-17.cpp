#include <iostream>
using namespace std;

template <class T>
int Found(T a[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (key == a[i])
            return i;
    return -1;
}

int main()
{
    int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    cout << "Input a number" << endl;
    int n;
    cin >> n;
    int m = Found(data, 20, n);
    if (m == -1)
        cout << "No dound." << endl;
    else
        cout << "The number is at " << m + 1 << endl;
}