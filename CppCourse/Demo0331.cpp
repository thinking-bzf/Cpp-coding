// Demo0331.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>

using namespace std;

/*
class Circle
{
private:
	float radius;
	static int number;
	const float PI;
public:
	Circle(float r, float pi):radius(r),PI(pi){number++;}
	~Circle(){number--;}

	float getArea() const{return PI*radius*radius;}
	static int getNumber(){return number;}
};

int Circle::number=0;


int _tmain(int argc, _TCHAR* argv[])
{
	cout<<Circle::getNumber()<<endl;
	Circle m1(10,3.14),m2(20,3.1415);

	cout<<Circle::getNumber()<<" "<<m1.getNumber()<<" "<<m2.getNumber()<<endl;
	{
		Circle m3(30,3.141);
		cout<<Circle::getNumber()<<endl;
	}

	cout<<Circle::getNumber()<<endl;


	return 0;
}
*/
/*
#define DEBUG

class B;
class A
{
	int weight;
public:
	A(int input):weight(input){}
	friend int getTotalWeight(A& a, B& b);
};

class B
{
	int weight;
public:
	B(int input):weight(input){}
	friend int getTotalWeight(A& a, B& b);
};

int getTotalWeight(A& a, B& b)
{
	return a.weight+b.weight;
}

void main()
{
	A aa(10);
	B bb(20);

#ifdef DEBUG
	cout<<getTotalWeight(aa,bb)<<endl;
#else
	cout<<"hello"<<endl;
#endif
}
*/

class Point
{
	int x,y;
public:
	Point(int a=0,int b=0):x(a),y(b){cout<<"constructor"<<endl;}
	~Point(){cout<<"deconstructor"<<endl;}
	void display() const{cout<<this->x<<","<<(*this).y<<endl;}
};

typedef int (*ff)();

int display()
{
	cout<<"world"<<endl;
	return 1;
}
int* func(ff f)
{
	int a=10;
	int *p=(int*)malloc(sizeof(int));

	f();
	return p;
}

void main()
{
	Point arr[2]={Point(1,2),Point(6,7)};

	for(int i=0; i<2; i++)
		arr[i].display();

	int i=100;
	void* ptr=&i;

	cout<<*((int*)ptr)<<endl;

	const int* const p=&i;
	int b=20;

	cout<<*p<<endl;

	int* pp=func(display);
	free(pp);

	Point *mptr=new Point[2];//&(arr[1]);
	for(int i=0;i<2; i++)
		mptr->display();

	delete []mptr;

	int *aa=new int(10);
	/*
	for(int i=0;i<10;i++)
		aa[i]=i*10+3;*/

	delete aa;

	for(int i=0;i<2; i++)
	{
		mptr=&(arr[i]);
		mptr->display();
		(*mptr).display();
	}
}
