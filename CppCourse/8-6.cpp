#include <iostream>
#define PI 3.14
using namespace std;

class Shape
{
public:
    virtual double getArea() = 0;
    virtual double getPerim() = 0;
};
class Rectangle : public Shape
{
private:
    double width, length;

public:
    Rectangle(double w, double l) : width(w), length(l){};
    double getArea() { return width * length; }
    double getPerim() { return 2 * (width + length); }
    ~Rectangle() {}
};
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r){};
    double getArea() { return PI * radius * radius; }
    double getPerim() { return 2 * PI * radius; }
    ~Circle() {}
};
int main()
{
    Shape *p;
    
    cout << "retangle:width = 4,length = 3;circle: radius = 3" << endl;
    p = new Rectangle(4, 3);
    cout << "The area of rectangle is " << p->getArea() << " the perim of retangle is " << p->getPerim() << endl;
    delete p;
    p = new Circle(3);
    cout << "The area of ciecle is " << p->getArea() << " the perim of circle is " << p->getPerim() << endl;
    delete p;
}