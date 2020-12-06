#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <sstream>
#include <bitset>
#include "HuffmanTree.h"
using namespace std;
void input(int *x, int start, int end);
void ShowMenu();
int Encode(string x);                                                           //二进制转换
void InputText(HuffmanTree &, map<char, string> &, map<string, char> &);        //从键盘输入文本
void LoadText(HuffmanTree &, map<char, string> &, map<string, char> &);         //从文件导入文本
void ShowHuffmanCodes(HuffmanTree &, map<char, string> &, map<string, char> &); //显示哈夫曼编码
void TexttoCodes(HuffmanTree &, map<char, string> &, map<string, char> &);      //文本编码(加密)
void CompressFile(HuffmanTree &, map<char, string> &, map<string, char> &);     //文件压缩(加密)
void DecompressFile(HuffmanTree &, map<char, string> &, map<string, char> &);   //解压文件(解密)
void PrintHuffmanTree(HuffmanTree &, map<char, string> &, map<string, char> &); //显示哈夫曼树
int main()
{
    int choice;
    HuffmanTree HT;
    map<char, string> Map;
    map<string, char> Code;
    while (1)
    {

        int size;
        ShowMenu();
        cout << "\nPlease input a integer from 1 to 16 for choice:";
        input(&choice, 1, 16);
        if (choice == 16)
            break;
        switch (choice)
        {
        case 1:
            //从键盘输入文本
            InputText(HT, Map, Code);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 2:
            //从文件导入文本
            LoadText(HT, Map, Code);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 3:
            //显示哈夫曼编码
            if (HT.IsEmpty())
                cout << "You haven't create the Huffman Tree" << endl;
            else
                ShowHuffmanCodes(HT, Map, Code);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 4:
            //文本编码(加密)
            TexttoCodes(HT, Map, Code);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 5:
            //文件压缩(加密)
            CompressFile(HT, Map, Code);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 6:
            //解压文件(解密)
            DecompressFile(HT, Map, Code);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 7:
            //显示哈夫曼树
            PrintHuffmanTree(HT, Map, Code);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        }
    }
    return 0;
}
void ShowMenu()
{
    cout << "************************I Love JLJ**********************" << endl;
    cout << endl;
    cout << "*******************Huffman Tree System******************" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     1. Input Text             2. Load Text           *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     3. Show Huffman Codes     4. Text to Codes       *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     5. Compress File          6. Decompress File     *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     7. Print Huffman Tree     8. Exit                *" << endl;
    cout << "*                                                      *" << endl;
    cout << "********************************************************" << endl;
}
void input(int *x, int start, int end)
{
    while (!(cin >> *x) || (*x < start) || (*x > end))
    {
        // 确保获取的是整数
        cout << "InputError:please input again";
        cin.clear(); //恢复错误的状态
        cin.sync();  //清楚之前的输入数据
    }
}

int Encode(string x)
{
    int value = 0;
    stack<char> s;
    for (int i = 0; i < x.length(); i++)
        s.push(x[i]);
    int power = 1;
    while (!s.empty())
    {
        char str;
        str = s.top();
        value += (str - '0') * power;
        power *= 2;
        s.pop();
    }
    return value;
}

string Decode(long x)
{
    string result;
    stack<char> s;
    while (x)
    {
        s.push('0' + abs(x % 2));
        x /= 2;
    }
    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }
    return result;
}
void InputText(HuffmanTree &HT, map<char, string> &Map, map<string, char> &Code) //从键盘输入文本
{
    // 获取字符串
    string str;
    cout << "Please input the string to encode:\n";
    getchar();
    getline(cin, str);
    // 创建哈夫曼树
    HT.Create(str);
    vector<pair<char, string>> vec;
    vec = HT.Code(Map);
    for (map<char, string>::iterator iter = Map.begin(); iter != Map.end(); ++iter)
        Code[iter->second] = iter->first;

    // 输出编码后得文本
    cout << "The text after encoding:" << endl;
    for (int i = 0; i < str.length(); i++)
        cout << Map[str[i]];
    // 输出哈夫曼编码
    cout << "The Huffman code as follow:" << endl;
    for (vector<pair<char, string>>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
        cout << iter->first << " :" << iter->second << endl;
    // 打印哈夫曼树
    cout << "The Huffman Tree as follow" << endl;
    HT.PrintTree();
}
void LoadText(HuffmanTree &HT, map<char, string> &Map, map<string, char> &Code) //从文件导入文本
{
    // 创建输入文件流
    string inPath;
    cout << "Please input the path of original text:";
    cin >> inPath;
    fstream in(inPath, ios_base::in | ios_base::binary);

    // 创建输出文件流
    fstream outFile("Data/HuffmanOutData.txt", ios_base::out | ios_base::trunc | ios_base::binary);
    ostringstream temp;
    temp << in.rdbuf();
    string str = temp.str();
    HT.Create(str);
    // 构造哈夫曼树
    vector<pair<char, string>> vec;
    vec = HT.Code(Map);
    for (map<char, string>::iterator iter = Map.begin(); iter != Map.end(); ++iter)
        Code[iter->second] = iter->first;
    string result = "";
    for (int i = 0; i < str.length(); i++)
        result += Map[str[i]];
    //将01编码串组成一个字符
    string binary;
    for (int i = 0; i < result.length(); i++)
    {
        binary += result[i];
        if (binary.length() == 8)
        {
            bitset<8> bit(binary);
            outFile << char(bit.to_ullong());
            binary = "";
        }
    }
    cout
        << "The text has been encoded, the result has been saved to HuffmanOutData.txt." << endl;
    in.close();
    outFile.close();
}
void ShowHuffmanCodes(HuffmanTree &HT, map<char, string> &Map, map<string, char> &Code) //显示哈夫曼编码
{
    vector<pair<char, string>> vec;
    vec = HT.Code(Map);
    // 输出哈夫曼编码
    cout << "The Huffman code as follow:" << endl;
    for (vector<pair<char, string>>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
        cout << iter->first << " :" << iter->second << endl;
    // 打印哈夫曼树
    cout << "The Huffman Tree as follow" << endl;
    HT.PrintTree();
}
void TexttoCodes(HuffmanTree &HT, map<char, string> &Map, map<string, char> &Code) //文本编码(加密)
{
    // 创建输入文件流
    string inPath;
    // 创建输出文件流
    fstream outFile("Data/HuffmanCompressData.txt", ios_base::out | ios_base::trunc | ios_base::binary);
    cout << "Please input the path of original text:";
    cin >> inPath;
    fstream in(inPath, ios_base::in | ios_base::binary);
    ostringstream temp;
    temp << in.rdbuf();
    string str = temp.str();
    HT.Create(str);
}
void CompressFile(HuffmanTree &HT, map<char, string> &Map, map<string, char> &Code) //文件压缩(加密)
{
}
void DecompressFile(HuffmanTree &HT, map<char, string> &Map, map<string, char> &Code) //解压文件(解密)
{
    // 创建输入文件流
    string inPath;
    // 创建输出文件流
    fstream outFile("Data/HuffmanCompressData.txt", ios_base::out | ios_base::trunc);
    cout << "Please input the path of encoded text:";
    cin >> inPath;
    fstream in(inPath);
    ostringstream temp;
    temp << in.rdbuf();
    string str = temp.str();
    cout << str << endl;
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

    string tmp;
    tmp = "";
    for (int i = 0; i < code.length(); i++)
    {
        tmp = tmp + code[i];
        if (Code.count(tmp) > 0)
        {
            outFile << Code[tmp];
            tmp = "";
        }
    }
    cout << "The text has been decoded to HuffmanCompressData.txt" << endl;
}
void PrintHuffmanTree(HuffmanTree &HT, map<char, string> &Map, map<string, char> &Code) //显示哈夫曼树
{
}