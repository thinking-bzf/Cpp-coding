#include<iostream>
#include<iomanip>
#include"Haffmantree.h"
using namespace std;
int main(){
    int n;
    cout << "请输入树叶结点的个数：" << endl;
    cin >> n;
    char ch[256];
    int weight[256];
    for (int i = 0; i < n;i++){
        cout << "请输入第" << i + 1 << "个字符及权值:";
        cin >> ch[i] >> weight[i];
    }
    Huffmantree HT;
    InitHuffmantree(HT, n);
    CreateHaffmantree(HT, n, ch, weight);
    Display(HT);
    HuffmanCoder HC;
    InitHuffmanCoder(HC, n);
    CreateHuffmanCoder(HC, HT);
    DestroyHuffmantree(HT);
    system("pause");
    return 0;
}
