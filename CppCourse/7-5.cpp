#include <iostream>
#include <iomanip>
using namespace std;
class shape
{
private:
    double area;
    static int count;

public:
    shape()
    {
        cout << "creat shape " << ++count << endl;
    }
    void display() { cout << setprecision(3) << area << endl; }
    ~shape() { cout << "delete the shape " << count-- << endl; }
    void setArea(double a) { area = a; }
};
int shape::count = 0;
class retangle : public shape
{
private:
    double width, height;

public:
    retangle(double w = 1, double h = 1) : width(w), height(h) { cout << "creat a retangle" << endl; }
    ~retangle() { cout << "delete a retangle" << endl; }
    void getArea()
    {
        shape::setArea(width * height);
        shape::display();
    }
};

class square:public retangle
{
private:
    double side;

public:
    square(double s) : side(s) { cout << "craet a square" << endl; };
    void getArea()
    {
        shape::setArea(side*side);
        shape::display();
    }
    ~square() { cout << "delete a square" << endl; };
};

class circle : public shape
{
private:
    double radius;

public:
    circle(double r) : radius(r) { cout << "creat a circle" << endl; };
    ~circle() { cout << "delete a circle" << endl; }
    void getArea()
    {
        shape::setArea(3.14 * radius * radius);
        shape::display();
    }
};

int main()
{
    retangle a(2.2, 3.3);
    a.getArea();

    circle b(1.5);
    b.getArea();

    square c(5.3);
    c.getArea();
}