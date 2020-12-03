#include <iostream>
using namespace std;
class Object
{
private:
    int weight;

public:
    Object(int w = 0) : weight(w) { cout << "creat a object" << endl; }
    void setWeight(int w) { weight = w; }
    void getWeight() { cout << weight; }
    ~Object() { cout << "delete a Object" << endl; }
};
class Box:public Object
{
    private:
        int width;
        int height;
    public:
        Box(int wi = 0, int h = 0, int w = 0) : width(wi), height(h), Object(w) { cout << "creat a Box" << endl; }
        void getWidth() { cout << width<<endl; }
        void getHeight() { cout << height << endl; }
        void setWidth(int w) { width = w; }
        void setHeight(int h) { height = h; }
        void getWeight() { Object::getWeight(); }
        ~Box() { cout << "delete a Box" << endl; }
};
int main()
{
    Box b(1, 1, 1);
}
