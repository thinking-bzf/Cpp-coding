#include <iostream>
using namespace std;
class Cat
{
private:
    int weight, age;
    static int numOfCats;

public:
    int a;
    Cat(int w = 1, int a = 1) : weight(w), age(a) { numOfCats++; }
    int getWeight() { return weight; }
    int getAge() { return age; }
    static void getNumOfCats() { cout << numOfCats << endl; }
    ~Cat() { cout << numOfCats-- << "delete completed\n"; }
};
int Cat::numOfCats = 0;
int main()
{
    int (Cat::*ptr)();
    cout << "The initial numOfCats is ";
    Cat::getNumOfCats();
    Cat *c = new Cat[2]; //定义一个cat类的数组，包括两个cat类。
    ptr = Cat::getAge;
    cout << (c[0].*ptr)() << endl;
    cout << "The first cat's numOfCats is ";
    c[0].getNumOfCats();
    cout << "The second cat's numOfCats is ";
    c[1].getNumOfCats();
    delete[] c; //释放
    return 0;
}