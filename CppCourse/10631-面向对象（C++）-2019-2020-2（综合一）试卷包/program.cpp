// demo.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

/*
class student
{
private:
	int number;
	float score;
public:
	void input(){cin>>number>>score;}
	void output() const{cout<<number<<" ";cout<<setiosflags(ios::fixed)<<setprecision(1)<<score<<endl;}
};

void main()
{
	student st[5],*ptr=st;

	for(int i=0; i<5; i++)
		ptr[i].input();

	for(int i=0; i<5; i++)
		ptr[i].output();
}
*/

/*
class Saler
{
private:
	int num;
	int quantity;
	float price;
	static float sum;
	static int n;
	static float discout;
	static float average;
public:
	Saler(int number, float p):num(number),price(p){quantity=0;}
	void sale(int count);
	static void display();
};

float Saler::sum=0;
int Saler::n=0;
float Saler::discout=0.98;
float Saler::average=0;

void Saler::sale(int count)
{
	n+=count;
	quantity+=count;
	if(count>=10)
		sum+=price*discout*count;
	else
		sum+=price*count;
}

void Saler::display()
{
	average=sum/n;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum<<" "<<average<<endl;
}

void main()
{
	Saler saler1(101,23.5),saler2(102,24.56),saler3(103,21.5);

	saler1.sale(5);
	saler2.sale(12);
	saler3.sale(100);

	Saler::display();
}
*/

class Employee
{
protected:
	int nu;
	float wg;
	char nm[18];
	char sx[3];
	static float totalWage;
	static int count;
public:
	Employee(int ind,const char* name, const char* sex, float wage);
	void showBase() const;
	static void showStatic(){cout<<"人数："<<count<<endl; cout<<"总工资："<<totalWage<<endl;}
};

float Employee::totalWage=0;
int Employee::count=0;


Employee::Employee(int ind,const char* name, const char* sex, float wage)
{
	nu=ind;
	memcpy(nm,name,18);
	memcpy(sx,sex,3);
	wg=wage;
	totalWage+=wage;
	count++;
}
void Employee::showBase() const
{
	cout<<"个人基本信息："<<endl;
	cout<<"编号："<<nu<<endl;
	cout<<"姓名："<<nm<<endl;
	cout<<"性别："<<sx<<endl;
	cout<<"工资："<<wg<<endl;
}

void main()
{
	const int number=2;
	int index;
	string name,sex;
	float wage;
	Employee* employee[number];


	for(int i=0; i<number;i++)
	{
		cin>>index>>name>>sex>>wage;
		employee[i]=new Employee(index,name.c_str(),sex.c_str(),wage);
	}

	Employee::showStatic();
	for(int i=0; i<number;i++)
	{
		employee[i]->showBase();
		delete employee[i];
	}
}