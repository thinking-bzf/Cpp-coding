#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <bitset>
using namespace std;
int main()
{
    fstream in("Data/HuffmanOutData.txt", ios_base::in | ios_base::binary);
    ostringstream temp;
    temp << in.rdbuf();
    string str = temp.str();
    // cout << str << endl;
    string code = "";
    for (int i = 0; i < str.length(); i++)
    {
        bitset<64> bit(str[i]);
        int flag = 0;
        string bite = "";
        int size = bit.size();
        for (int i = bit.size() - 1; i >= 0; i--)
        {

            if (flag == 0)
                if (bit[i] == 1)
                    flag = 1;
            if (flag)
                bite += bit[i] + '0';
        }
        code += bite;
    }
    cout << code << endl;
    cout << R"+*(ΆΎ�λή#/µ†ώ¬#)+*" << endl;
}