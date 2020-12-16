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
#include <assert.h>
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
        input(&choice, 1, 8);
        if (choice == 8)
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
    fstream outFile("Data/Huffman/HuffmanOutData.txt", ios_base::out | ios_base::trunc | ios_base::binary);
    string str;
    char c;
    while (1)
    {
        if (in.peek() == EOF)
            break;
        in.read(&c, 1);
        str += c;
    }
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
            binary.erase(0, 8);
        }
    }
    // 剩余几位
    if (binary.length() > 0)
    {
        int youxiao = binary.length();
        for (int i = youxiao; i < 8; i++)
            binary.append("0");
        int n = binary.length();
        bitset<8> bit(binary);
        outFile << char(bit.to_ullong());
        outFile << youxiao;
    }
    cout << "The text has been encoded, the result has been saved to HuffmanOutData.txt." << endl;
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
    string passwordPath("Data/Huffman/HuffmanPassword.txt");
    fstream password(passwordPath, ios_base::in | ios_base::binary);
    string str;
    char c;
    while (1)
    {
        if (password.peek() == EOF)
            break;
        password.read(&c, 1);
        str += c;
    }
    HT.Create(str);
    // 用密码本构造构造哈夫曼树
    vector<pair<char, string>> vec;
    vec = HT.Code(Map);
    for (map<char, string>::iterator iter = Map.begin(); iter != Map.end(); ++iter)
        Code[iter->second] = iter->first;

    // 获取字符串
    string strOut;
    cout << "Please input the string to encode:\n";
    getchar();
    getline(cin, strOut);

    // 输出编码后得文本
    cout << "The text after encoding:" << endl;
    for (int i = 0; i < strOut.length(); i++)
        cout << Map[strOut[i]];
    cout << endl;
    // 输出哈夫曼编码
    cout << "The Huffman code as follow:" << endl;
    for (vector<pair<char, string>>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
        cout << iter->first << " :" << iter->second << endl;
    
    password.close();
}
void CompressFile(HuffmanTree &HT, map<char, string> &Map, map<string, char> &Code) //文件压缩(加密)
{
    // 创建输入文件流
    string inPath;
    string passwordPath("Data/Huffman/HuffmanPassword.txt");
    // 创建输出文件流
    fstream outFile("Data/Huffman/ZipFile.txt", ios_base::out | ios_base::trunc | ios_base::binary);
    cout << "Please input the path of original text:";
    cin >> inPath;
    fstream password(passwordPath, ios_base::in | ios_base::binary);

    string str;
    char c;
    while (1)
    {
        if (password.peek() == EOF)
            break;
        password.read(&c, 1);
        str += c;
    }
    HT.Create(str);
    // 用密码本构造构造哈夫曼树
    vector<pair<char, string>> vec;
    vec = HT.Code(Map);
    for (map<char, string>::iterator iter = Map.begin(); iter != Map.end(); ++iter)
        Code[iter->second] = iter->first;

    // 将输入路径的文本加密
    fstream fin(inPath, ios::in | ios::binary);
    string outStr;
    char ch;
    while (1)
    {
        if (fin.peek() == EOF)
            break;
        fin.read(&ch, 1);
        outStr += ch;
    }
    string result = "";
    for (int i = 0; i < outStr.length(); i++)
        result += Map[outStr[i]];

    string binary;
    for (int i = 0; i < result.length(); i++)
    {
        binary += result[i];
        if (binary.length() == 8)
        {
            bitset<8> bit(binary);
            outFile << char(bit.to_ullong());
            binary.erase(0, 8);
        }
    }
    // 剩余几位
    if (binary.length() > 0)
    {
        int youxiao = binary.length();
        for (int i = youxiao; i < 8; i++)
            binary.append("0");
        int n = binary.length();
        bitset<8> bit(binary);
        outFile << char(bit.to_ullong());
        outFile << youxiao;
    }
    cout << "The text has been encoded, the result has beefn saved to ZipFile.txt." << endl;
    fin.close();
    password.close();
    outFile.close();
}
void DecompressFile(HuffmanTree &HT, map<char, string> &Map, map<string, char> &Code) //解压文件(解密)
{
    // 创建输入文件流
    string inPath;
    // 创建输出文件流
    fstream outFile("Data/Huffman/UnzipFile.txt", ios_base::out | ios_base::trunc | ios_base::binary);
    cout << "Please input the path of encoded text:";
    cin >> inPath;
    fstream fin(inPath, ios::in | ios::binary);
    char ch;
    char quan;
    char youxiao;
    fin.seekg(-1, ios_base::end);
    // 获取最后一位数字，作为有效数字
    fin >> youxiao;
    string code = "";
    ifstream::pos_type pos;
    fin.seekg(-2, ios_base::end);
    pos = fin.tellg();
    fin.seekg(0, ios_base::beg);
    // 获取压缩后的文件的二进制码 并把他变成二进制编码
    while (1)
    {
        if (fin.tellg() == pos)
            break;
        fin.read(&ch, 1);
        bitset<8> bit;
        bit = ch;
        string x = bit.to_string();
        code += x;
    }
    // 最后的几个字符
    fin >> ch;
    bitset<8> last(ch);
    string lastStr = last.to_string();
    for (int i = 0; i < (youxiao - '0'); i++)
        code = code + lastStr[i];

    ostringstream temp;
    temp << outFile.rdbuf();
    string str = temp.str();
    cout << str << endl;

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
    fin.close();
    outFile.close();
    cout << "The text has been decoded to UnzipFile.txt" << endl;
}
void PrintHuffmanTree(HuffmanTree &HT, map<char, string> &Map, map<string, char> &Code) //显示哈夫曼树
{
    cout << "The HuffmanTree is :" << endl;
    HT.PrintTree();
}