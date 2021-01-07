#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cake[5];
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < 5; i++)
        {
            cin >> cake[i];
        }
        if (cake[0] * cake[0] > cake[1] * cake[2] && cake[0] * cake[0] > cake[3] * cake[4] * 0.5)
            cout << "Perch" << endl;
        else if (cake[0] * cake[0] < cake[1] * cake[2] && cake[1] * cake[2] > cake[3] * cake[4] * 0.5)
            cout << "Semon" << endl;
        else
            cout << "Belinda" << endl;
    }
}