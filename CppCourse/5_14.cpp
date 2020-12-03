#include <iostream>
using namespace std;
class Boat; //声明类，方便下面友元
class Car
{
private:
    double weight;

public:
    Car(double w = 0) : weight(w) {}
    void showWeight() { cout << weight << " ton" << endl; }
    friend void getTotalWeight(Boat &b, Car &c);
};
class Boat
{
private:
    double weight;

public:
    Boat(double w = 0) : weight(w) {}
    void showWeight() { cout << weight << " ton" << endl; }
    friend void getTotalWeight(Boat &b, Car &c);
};
void getTotalWeight(Boat &b, Car &c)
{
    cout << "The total weight is " << b.weight + c.weight << " ton" << endl;
}

int main()
{
    Boat b1(12000);
    Car c1(11);
    cout << "The weight of boat is ";
    b1.showWeight();
    cout << "The weight of car is ";
    c1.showWeight();
    getTotalWeight(b1, c1);
    return 0;
}