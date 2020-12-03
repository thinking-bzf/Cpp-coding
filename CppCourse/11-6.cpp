#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Dog
{
    int weight;
    int age;

public:
    Dog(int w = 1, int a = 1) : weight(w), age(a) {}
    int getweight() { return weight; }
    int getage() { return age; }
    friend istream &operator>>(istream &in, Dog &d)
    {
        in >> d.weight >> d.age;
        return in;
    }
    friend ostream &operator<<(ostream &out, Dog &d)
    {
        out << d.weight << " " << d.age;
        return out;
    }
};

int main()
{
    Dog dog1(5, 10);
    ofstream fout("dog.dat", ios_base::out | ios_base::trunc);
    fout << dog1;
    fout.close();
    // string ss;
    // getline(cin, ss);
    // stringstream a(ss);
    // string s;
    // a >> s;
    ifstream fin("dog.dat", ios_base::in);
    Dog dog2;
    fin >> dog2;
    cout << dog2;
    fin.close();

    cout << endl;

    ofstream fout2("binary.dat", ios_base::out | ios_base::trunc | ios_base::binary);
    fout2.write((char *)&dog1, sizeof(dog2));
    fout.close();

    ifstream fin2("binary.dat", ios_base::in | ios_base::binary);
    fin2.read((char *)&dog2, sizeof(dog2));
    cout << dog2;
    fin2.close();
    cout << endl;
}