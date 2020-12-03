#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void DisplayVector(const vector<int> &V)
{
    vector<int>::const_iterator it;

    for (it = V.begin(); it != V.end(); it++)
        cout << *it << '\t';
    cout << endl;
}
int main()
{
    vector<int> V(6);
    for (int i = 0; i < V.size(); i++)
        V[i] = 3 * i;
    V.push_back(8);
    V.push_back(9);
    V.push_back(10);

    DisplayVector(V);
    sort(V.begin(), V.end());
    DisplayVector(V);

    return 0;
}
