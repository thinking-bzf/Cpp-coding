
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

/*
template<typename T>
class shape
{
public:
	virtual ~shape(){cout<<"~shape"<<endl;}
	virtual void display() const=0;
};

template<typename T>
class circle:public shape<T>
{
private:
	static T PI;
	T r;
public:
	~circle(){cout<<"~circle"<<endl;}
	circle(T inp):r(inp){}
	void display() const{cout<<"area of circle: "<<PI*r*r<<endl;}
};

template<typename T>
T circle<T>::PI=3.15;


template<typename T>
class rect:public shape<T>
{
private:
	T w,h;
public:
	~rect(){cout<<"~rect"<<endl;}
	rect(T a,T b):w(a),h(b){}
	void display() const{cout<<"area of rect: "<<w*h<<endl;}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<shape<float>*> vec;

	vec.push_back(new circle<float>(1.2));
	vec.push_back(new rect<float>(2.1,3.8));
	vec.push_back(new circle<float>(6.2));

	list<shape<float>*> l;

	for(vector<shape<float>*>::iterator it=vec.begin(); 
		it!=vec.end();it++)
	{
		(*it)->display();
		l.push_front(*it);
		
	}

	for(list<shape<float>*>::iterator it=l.begin(); 
		it!=l.end();it++)
	{
		(*it)->display();
		delete *it;
	}

	return 0;
}
*/

#include <string>
/*
int main() 
{
	string names1[] = { "Alice", "Helen", "Lucy", "Susan" };
	string names2[] = { "Bob", "David", "Levin", "Mike" };
	list<string> s1(names1, names1 + 4); //用names1数组的内容构造列表s1
	list<string> s2(names2, names2 + 4); //用names2数组的内容构造列表s2
	
	list<string>::iterator iter;
	s2.splice(s2.end(), s1, s1.begin());
	
	auto it1=back_inserter(s2);
	*(it1)="hello";

	for(list<string>::const_iterator it=s2.begin(); it!=s2.end();it++)
	{
		
		cout<<*it<<endl;
	}
}*/
/*
int main() 
{
	int intArr[] = { 30, 90, 10, 40, 70, 50, 20, 80 };
	const int N = sizeof(intArr) / sizeof(int);
	vector<int> a(intArr, intArr + N);
	cout << "before sorting:" << endl;
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	sort(a.begin(), a.end());
	cout << "after sorting:" << endl;
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	return 0;
}
*/
/*
void main()
{
	int intArr[] = { 30, 90, 10, 40, 70, 50, 20, 80 };
	const int N = sizeof(intArr) / sizeof(int);

	vector<int> a(intArr, intArr + N);

	vector<int>::iterator p = find_if(a.begin(), a.end(), not1(bind1st(greater<int>(), 40)));
	//vector<int>::iterator p=find(a.begin(),a.end(),40);
	if (p == a.end())
		cout << "no element greater than 40" << endl;
	else
		cout << "first element greater than 40 is: " << *p << endl;

}*/

class obj
{
private:
	int index;
public:
	obj(int inp):index(inp){}
	int getInd(){return index;}
};


bool comp1(int val,obj* o){return o->getInd()>val;}
bool comp2(obj* o1, obj* o2){return o1->getInd()<o2->getInd();}
class comp
{
public:
	bool operator()(int o,int val){return o>val;}
};
/*
void main()
{
	vector<int> vec;

	vec.push_back((12));
	vec.push_back((22));
	vec.push_back((36));

	//int num=count_if(vec.begin(),vec.end(), bind2nd(greater<int>(),20));
	int num=count(vec.begin(),vec.end(), 20);
	cout<<num<<endl;
};*/

void main()
{
	vector<obj*> vec;

	vec.push_back(new obj(32));
	vec.push_back(new obj(22));
	vec.push_back(new obj(36));

	int num=count_if(vec.begin(),vec.end(), bind1st(ptr_fun(comp1),20));
	vector<obj*>::iterator it=find_if(vec.begin(),vec.end(), bind1st(ptr_fun(comp1),20));
	cout<<(*it)->getInd()<<endl;

	sort(vec.begin(),vec.end(),comp2);
	for(vector<obj*>::iterator it=vec.begin(); it!=vec.end(); it++)
	{
		cout<<(*it)->getInd()<<" ";
		delete *it;
	}
	cout<<endl;
	//int num=count(vec.begin(),vec.end(), 20);
	cout<<num<<endl;
};

