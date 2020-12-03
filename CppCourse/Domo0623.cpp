// demo.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <deque>
#include <string>
#include <fstream>
#include <assert.h>

using namespace std;

/*
class Point
{
private:
	int x,y;
public:
	Point(int a=0,int b=0):x(a),y(b){}
	int GetX() const{return x;}
	int GetY() const{return y;}	
	void Print() const{cout<<"start point: "<<"["<<x<<","<<y<<"]"<<",";}
};

class Line:public Point
{
private:
	Point EndPoint;
public:
	Line(int a,int b, int c, int d):Point(a,b),EndPoint(c,d){}
	float Length() const;
	void Print() const;
};

float Line::Length() const
{
	int x0=GetX();
	int y0=GetY();
	int x1=EndPoint.GetX();
	int y1=EndPoint.GetY();

	return sqrt(static_cast<float>((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1)));
}

void Line::Print() const
{
	Point::Print();
	cout<<"End point: "<<"["<<EndPoint.GetX()<<","<<EndPoint.GetY()<<"]"<<endl;
}

void main()
{
	Line line(1,1,10,10);

	cout<<"line的";
	line.Print();
	cout<<"\nline的长度:";
	cout<<line.Length()<<endl;
}
*/
/*
class CArray
{
public:
    int len ;
    float *arp ;
public:
    CArray (int n=0) ;
    ~ CArray() {if (arp) delete [ ] arp ;}
    int GetLen() const {return len ;}
    void SetLen (int l)
    {
        if (1>0)
        {
            if (arp) delete [ ] arp;
            arp=new float [1 ] ;
            memset (arp , 0 ,sizeof (float ) *l ) ; //A 调用库函数，将所分配的存储空间均置为0。
            len = l ;
        }
    }
    float & operator [ ] (int index); //定义重载的下标运算符
};

CArray ::CArray (int n)
{
    if ( n>0)
    {
        arp = new float [ n ] ;
        memset (arp , 0 ,sizeof (float ) *n) ;
        len = n ;
    }
    else 
	{
        len=0 ;
        arp =0 ;
    }
}

float& CArray::operator [ ] (int index)
{
	assert(index>=0&&index<len);

	return arp[index];
}

int main (void)
{
    CArray m1(10) ,m2 (3) ;
    int i ;

    for (i=0 ; i<10; i++)
        m1[i] = (float)i ;//重载数组下标的使用

    for(i=1 ; i<10 ; i++) //B m1 中的*arp 最多为10 个字符
        cout<<m1[i]<<" " ; //C 输出m1[10]时，下标越界终止程序的执行。

    cout<<'\n';

    m2.arp[2]=26 ;
    cout<<"m2[2]="<<m2.arp[2]<<'\n' ;
    return 0;
}
*/
/*
class Shape
{
public:
	virtual ~Shape(){}
	virtual void ShowArea() const=0;
};

class Circle:public Shape
{
private:
	float rad;
	static float PI;
public:
	Circle(float r=0):rad(r){}
	void ShowArea() const{cout<<"Circle Area: "<<PI*rad*rad<<endl;}
};
float Circle::PI=3.14;

class Square:public Shape
{
private:
	float len;
public:
	Square(float l):len(l){}
	void ShowArea() const{cout<<"square area: "<<len*len<<endl;}
};

void main()
{
	deque<Shape*> dq;

	dq.push_front(new Circle(10));
	dq.push_front(new Square(20));

	for(deque<Shape*>::iterator it=dq.begin(); it!=dq.end(); it++)
	{
		(*it)->ShowArea();
		delete *it;
	}
}
*/

class student
{
private:
    int index;
    string name;
    float score;

public:
    student(int ind = 0, string nm = "", float sc = 0) : index(ind), name(nm), score(sc) {}
    friend ostream &operator<<(ostream &out, const student &st);
    friend istream &operator>>(istream &in, student &st);
};

ostream &operator<<(ostream &out, const student &st)
{
    out << st.index << " " << st.name << " " << st.score << endl;
    return out;
}

istream &operator>>(istream &in, student &st)
{
    in >> st.index >> st.name >> st.score;
    return in;
}

int main()
{
    student st;

    cout << "please input: " << endl;
    cin >> st;

    fstream fs("test.txt", ios::out);
    fs << 2 << endl;

    fs << st;
    cout << "please input: " << endl;
    cin >> st;
    fs << st;
    fs.close();

    student ob;
    fs.open("test.txt");
    int num;
    fs >> num;
    cout << num << endl;
    for (int i = 0; i < num; i++)
    {
        fs >> ob;
        cout << ob;
    }
    fs.close();
}
