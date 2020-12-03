#include <iostream>
#include <cstring>
using namespace std;
class CQueue
{
private:
	int length;
	int flag;
	string tp;
	string *s;
	int *num;

public:
	CQueue(string x);		   //队列构造
	CQueue(const CQueue &rhs); //队列拷贝构造
	//~CQueue();				   //队列析构，
	void push(int x);	   //X入队列
	void push(string x);   //字符入队
	void pop();			   //出队列
	void front();		   //取队首元素
	bool empty() const;	   //判队空
	int GetLength() const; //取队列长度
	CQueue operator=(const CQueue rhs);
};

CQueue::CQueue(string x) //队列构造
{
	length = 0;
	flag = 0;
	if (x == "int")
	{
		tp = "int";
		num = new int[1];
		memset(num, 0, sizeof(num));
	}
	else if (x == "string")
	{
		tp = "string";
		s = new string[1];
	}
}

CQueue::CQueue(const CQueue &rhs)
{
	length = rhs.length;
	flag = rhs.flag;
	if (rhs.tp == "int")
	{
		this->num = new int[rhs.length];
		for (int i = 0; i < length; i++)
		{
			num[i] = rhs.num[i];
		}
	}
	else if (rhs.tp == "string")
	{
		this->s = new string[rhs.length];
		for (int i = 0; i < length; i++)
		{
			s[i] = rhs.s[i];
		}
	}
}
// CQueue::~CQueue()
// {
// 	flag = 0;
// 	if (tp == "int")
// 		delete[] num;
// 	else if (tp == "string")
// 		delete[] s;
// }

void CQueue::push(int x)
{
	if (!flag)
		flag = 1;
	int *temp;
	temp = new int[length + 1];
	for (int i = 0; i < length; i++)
	{
		temp[i] = num[i];
	}
	temp[length] = x;
	num = temp;
	length++;
}
bool CQueue::empty() const
{
	return flag;
}

void CQueue::push(string x)
{
	string *temp;
	temp = new string[length + 1];
	for (int i = 0; i < length; i++)
	{
		temp[i] = s[i];
	}
	temp[length] = x;
	s = temp;
	length++;
}
void CQueue::pop()
{

	if (tp == "int")
	{
		if (length == 1)
			flag = 0;
		else
		{
			int *temp;
			temp = new int[length - 1];
			for (int i = 1; i < length; i++)
			{
				temp[i - 1] = num[i];
			}
			num = temp;
		}
	}
	else if (tp == "string")
	{
		if (length == 1)
			flag = 0;
		else
		{
			string *temp;
			temp = new string[length - 1];
			for (int i = 1; i < length; i++)
			{
				temp[i] = num[i];
			}
			s = temp;
		}
	}
	if (length > 1)
		length--;
	else if (length == 1)
		flag = 0;
}
CQueue CQueue::operator=(const CQueue rhs)
{
	//delete[] num;
	if (rhs.tp == "int")
	{
		CQueue temp("int");
		temp.length = rhs.length;
		temp.flag = rhs.flag;
		temp.num = new int[rhs.length];
		for (int i = 0; i < length; i++)
		{
			temp.num[i] = rhs.num[i];
		}
		return temp;
	}
	else if (rhs.tp == "string")
	{
		CQueue temp("string");
		temp.length = rhs.length;
		temp.flag = rhs.flag;
		temp.s = new string[rhs.length];
		for (int i = 0; i < length; i++)
		{
			temp.s[i] = rhs.s[i];
		}
		return temp;
	}
}
void CQueue::front()
{
	if (tp == "int")
	{
		cout << num[0];
	}
	else if (tp == "string")
	{
		cout << s[0];
	}
}
int main()
{
	string a, b;
	int c;
	cin >> a;
	cin >> c;
	cout << "start:" << endl;
	if (a == "int")
	{
		CQueue cq[5] = {
			CQueue("int"),
			CQueue("int"),
			CQueue("int"),
			CQueue("int"),
			CQueue("int"),
		};
		while (c--)
		{

			cin >> b;
			if (b == "push")
			{
				int m, n; //队列序号和入队元素
				cin >> m >> n;
				cq[m].push(n);
			}
			else if (b == "pop")
			{
				int m; //队列序号
				cin >> m;
				cq[m].front();
				cq[m].pop();
				cout << " ";
			}
			else if (b == "assign")
			{
				int m, n; //被复制队列序号和被赋值的队列序号
				cin >> m >> n;
				cq[n] = cq[m];
			}
		}
		cout << endl
			 << "final:\n";
		cq[4] = cq[1];
		for (int i = 1; i <= 4; i++)
		{
			while (!cq[i].empty())
			{
				cq[i].front();
				cq[i].pop();
				cout << " ";
			}
			cout << endl;
		}
	}
	else if (a == "string")
	{
		CQueue cq[5] = {
			CQueue("string"),
			CQueue("string"),
			CQueue("string"),
			CQueue("string"),
			CQueue("string"),
		};
		while (c--)
		{
			cin >> b;
			if (b == "push")
			{
				int m;	  //队列序号
				string n; //入队·元素
				cin >> m >> n;
				cq[m].push(n);
			}
			else if (b == "pop")
			{
				int m; //队列序号
				cin >> m;
				cq[m].front();
				cq[m].pop();
				cout << " ";
			}
			else if (b == "assign")
			{
				int m, n; //被复制的队列和被赋值的队列
				cin >> m >> n;
				cq[n] = cq[m];
			}
		}
		cout << endl
			 << "final:\n";
		cq[4] = cq[1];
		for (int i = 1; i <= 4; i++)
		{
			while (!cq[i].empty())
			{
				cq[i].front();
				cq[i].pop();
				cout << " ";
			}
			cout << endl;
		}
	}
}