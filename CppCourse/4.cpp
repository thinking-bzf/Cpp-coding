#include <iostream>
#include <fstream>
using namespace std;
//实现student类
class student
{
private:
    int index;
    string name;
    float score;

public:
    student(int ind = 0, string nm = "", float sc = 0) : index(ind), name(nm), score(sc) {}
    friend ostream &operator<<(ostream &out, const student &st);
    friend istream &operator>>(istream &in, student &st);
};
ostream &operator<<(ostream &out, const student &st)
{
    out << st.index << " " << st.name << " " << st.score << endl;
    return out;
}
istream &operator>>(istream &in, student &st)
{
    in >> st.index >> st.name >> st.score;
    return in;
}
//使用fstream写入两个student对象，而后再读出进行显示。
int main()
{
    student s1(1, "bzf", 100), s2(2, "xxx", 95);
    student y1, y2;
    fstream file("student.dat", ios_base::out);
    // file << s1;
    // file << s2;
    // file.close();
    // file.open("student.txt");
    // student obj;
    // for (int i = 0; i < 2; i++)
    // {
    //     file >> obj;
    //     cout << obj;
    // }
    file << s1 << s2;
    file.close();
    file.open("student.dat");
    file >> y1 >> y2;
    cout << y1 << y2;
    file.close();
}