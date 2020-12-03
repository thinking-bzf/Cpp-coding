#include<iostream>
#include<fstream>
using namespace std;
class Dog {
	int weight;
	int age;
public:
	Dog(int ww,int aa):weight(ww),age(aa) {};
	friend ostream& operator<<(ostream& out, const Dog& d1);
	friend istream& operator>>(istream& in,Dog& d2);
};
istream& operator>>(istream& in,Dog& d2)
{
	in>>d2.weight>>d2.age;
	return in;
}
ostream& operator<<(ostream& out, const Dog& d1)
{
	out<<d1.weight<<" "<<d1.age<<endl;
	return out;
}
int main() {
	Dog dog1(5,10);

	fstream file1("text.dat",ios_base::out);
	file1<<dog1;
	file1.close();
	
	file1.open("text.dat",ios_base::in);
	Dog dog2(0,0);
	file1>>dog2;
	cout<<dog2;
	file1.close();
	
	fstream file2("binary.dat",ios_base::out|ios_base::binary);
	file2<<dog1;
	file2.close();
	
	file2.open("binary.dat",ios_base::in|ios_base::binary);
	file2>>dog2;
	cout<<dog2;
	file2.close();
} 
