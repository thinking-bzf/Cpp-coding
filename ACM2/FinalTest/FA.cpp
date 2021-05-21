#include <iostream>
using namespace std;
int main()
{
    int n;
    int L, t1, t2, v1, v2;
    cin >> n;
    while (n--)
    {
        cin >> L >> t1 >> t2 >> v1 >> v2;
        double sum1 = t1 + t2; //bike
        double sum2 = 0;       //foot
        sum1 += L * 1.0 / v1;
        sum2 += L * 1.0 / v2;
        if (sum1 < sum2)
            cout << "Bike is OK!" << endl;
        else if (sum1 > sum2)
            cout << "Walk is OK!" << endl;
        else if (sum1 == sum2)
            cout << "Both are OK!" << endl;
    }
}