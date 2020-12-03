#include <iostream>
using namespace std;
int nums[55] = {0};

int main()
{
    nums[1] = 1;
    nums[2] = 1;
    int n, a, b;
    while (cin >> a >> b >> n)
    {
        if (n == 0 && a == 0 && b == 0)
            break;
        for (int i = 3; i <= 49; i++)
            nums[i] = (a * nums[i - 1] + b * nums[i - 2]) % 7;
        cout << nums[n % 49] << endl;
    }
}