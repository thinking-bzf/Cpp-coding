#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CUIControl
{
    string m_kj, m_bt;

public:
    CUIControl() {}
    CUIControl(string kj, string bt);
    virtual int Clicked() const = 0;
    virtual ~CUIControl() {}
};
CUIControl::CUIControl(string kj, string bt) : m_kj(kj), m_bt(bt) {}
class CMenu : public CUIControl
{
    string m_kj, m_bt;

public:
    CMenu(string kj, string bt);
    virtual int Clicked() const;
};

CMenu::CMenu(string kj, string bt) : m_kj(kj), m_bt(bt) {}

int CMenu::Clicked() const
{
    cout << "menu"
         << "-" << m_bt << " "
         << "Clicked" << endl;
}

class CButton : public CUIControl
{
    string m_kj, m_bt;

public:
    CButton(string kj, string bt);
    virtual int Clicked() const;
};
CButton::CButton(string kj, string bt) : m_kj(kj), m_bt(bt) {}

int CButton::Clicked() const
{
    cout << "button"
         << "-" << m_bt << " "
         << "Clicked" << endl;
}

int main()
{
    vector<CUIControl *> mab1;
    int n;
    cin >> n;
    string kj, bt;
    for (int i = 0; i < n; i++)
    {
        cin >> kj >> bt;
        if (kj == "menu")
            mab1.push_back(new CMenu(kj, bt));
        if (kj == "button")

            mab1.push_back(new CButton(kj, bt));
    }
    string a;
    int num;
    while (cin >> a >> num)
    {
        int i = num - 1;
        mab1[i]->Clicked();
    }

    for (unsigned int i = 0; i < mab1.size(); i++)
    {
        delete mab1[i];
    }
}
