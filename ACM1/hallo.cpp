#include <iostream>
#include <vector>
#include <string>
using namespace std;
class student
{
private:
    int n;

public:
    student(int a) : n(a) {}
    void show() { cout << n; }
};

int main()
{
    int n;
    student s(1);
    s.show();
    cout << endl;
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    cin >> n;

    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}