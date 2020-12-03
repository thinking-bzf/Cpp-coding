#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
class Cstudent
{
    string m_name;
    int m_xuehao;

public:
    Cstudent(string name, int xuehao);
    int Getxuehao();
    string Getname();
};
Cstudent::Cstudent(string name, int xuehao) : m_name(name), m_xuehao(xuehao) {}

int Cstudent::Getxuehao()
{
    return m_xuehao;
}
string Cstudent::Getname()
{
    return m_name;
}

class Cbanji
{
    int m_num;
    vector<shared_ptr<Cstudent>> stu;

public:
    Cbanji(int num);
    void Insert(shared_ptr<Cstudent> S);
    void Dump();
    int Getnum();
};
Cbanji::Cbanji(int num) : m_num(num) {}

void Cbanji::Insert(shared_ptr<Cstudent> S)
{
    stu.push_back(S);
}

void Cbanji::Dump()
{
    for (auto it = stu.begin(); it != stu.end(); it++)
    {
        cout << (*it)->Getxuehao() << " " << (*it)->Getname() << endl;
    }
}

int Cbanji::Getnum()
{
    return m_num;
}

class Cteam
{
    string m_tuandui;
    vector<shared_ptr<Cstudent>> stu2;

public:
    Cteam(string tuandui);
    void Insert(shared_ptr<Cstudent> t);
    string Getname();
    void Dump();
};
Cteam::Cteam(string tuandui) : m_tuandui(tuandui) {}
inline void Cteam::Insert(shared_ptr<Cstudent> s)
{
    stu2.push_back(s);
}
inline void Cteam::Dump()
{
    for (auto it = stu2.begin(); it != stu2.end(); it++)
    {
        cout << (*it)->Getxuehao() << " " << (*it)->Getname() << endl;
    }
}
string Cteam::Getname()
{
    return m_tuandui;
}

int main()
{
    string panduan;
    vector<shared_ptr<Cbanji>> b;
    vector<shared_ptr<Cteam>> t;
    vector<shared_ptr<Cstudent>> s;
    int num, xuehao = 10000;
    while (getline(cin, panduan)) //getline 用来输入每行的内容
    {

        string name, cort, tuandui;
        stringstream a(panduan); //输入流，用来将单词分开的流
        string s1;               //用来接收每个分开的单词流的字符串
        a >> s1;                 //将一个单词流入s1，下面同理 所有的a都会输出一个单词流给">>"后面的变量，做到单词分开，方便管理
        if (s1 == "append")
        {
            a >> name;
            shared_ptr<Cstudent> ptrstudent(new Cstudent(name, xuehao));
            s.push_back(ptrstudent);
            xuehao++;
        }
        else if (s1 == "create")
        {
            a >> cort;
            if (cort == "class")
            {
                //int num;
                a >> num;
                shared_ptr<Cbanji> ptrbanji(new Cbanji(num));
                b.push_back(ptrbanji);
            }
            if (cort == "team")
            {
                a >> tuandui;
                shared_ptr<Cteam> ptrteam(new Cteam(tuandui));
                t.push_back(ptrteam);
            }
        }
        else if (s1 == "join")
        {
            a >> cort;
            if (cort == "class")
            {
                int cnum;
                int snum;
                a >> cnum >> snum;
                auto p = make_shared<Cstudent>(cort, 0);
                for (auto it = s.begin(); it != s.end(); it++)
                {
                    if ((*it)->Getxuehao() == snum)
                        p = (*it);
                }
                for (auto it = b.begin(); it != b.end(); it++)
                {
                    if ((*it)->Getnum() == cnum)
                        (*it)->Insert(p);
                }
            }
            else if (cort == "team")
            {
                string tuandui2;
                int snum;
                a >> tuandui2 >> snum;
                auto p = make_shared<Cstudent>(cort, 0);
                for (auto it = s.begin(); it != s.end(); it++)
                {
                    if ((*it)->Getxuehao() == snum)
                        p = *it;
                }
                for (auto it = t.begin(); it != t.end(); it++)
                {
                    if ((*it)->Getname() == tuandui2)
                        (*it)->Insert(p);
                }
            }
        }
    }
    cout << "student list:" << endl;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << (*it)->Getxuehao() << " " << (*it)->Getname() << endl;
    }
    cout << endl;
    for (auto it = b.begin(); it != b.end(); it++)
    {
        cout << "class " << (*it)->Getnum() << ":" << endl;
        (*it)->Dump();
        cout << endl;
    }

    for (auto it = t.begin(); it != t.end(); it++)
    {
        cout << (*it)->Getname() << " team:" << endl;
        (*it)->Dump();
        cout << endl;
    }
}
