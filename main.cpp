#include<iostream>



using namespace std;

//class A1
//{
//public:
//	void f1(){}
//private:
//	int _a;
//};
//// 类中仅有成员函数
//class A2
//{
//public:
//	void f2() {}
//};
//// 类中什么都没有---空类
//class A3
//{};
//
//int a(int b)
//{
//	cout << b << endl;
//}
//
//int main()
//{
//	cout << "sizeof(A1)=" << sizeof(A1) << endl;
//	cout << "sizeof(A2)=" << sizeof(A2) << endl;
//	cout << "sizeof(A3)=" << sizeof(A3) << endl;
//}


class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}

	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main()
{
	A* p = NULL;
	p->PrintA();
	p->Show();
}

//#include <time.h>
//struct A{ int a[10000]; };
//void TestFunc1(A a){}
//void TestFunc2(A& a){}
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}



//void add(int &a)
//{
//	a++;
//}

//int main()
//{
//	int a[] = {1, 2, 3, 4};
//	
//	for (auto& e : a)
//		cout << e << " " << typeid(e).name() << " ";
//	cout << endl;
//
//
//	return 0;
//}


//void add(int a)
//{
//	cout << "int" << endl;
//}
//void add(char a)
//{
//	cout << "char" << endl;
//}
//
//int main()
//{
//	int a = 0;
//	int flag = 0;
//	cin >> flag;
//	if (flag == 1)
//		(char)a;
//	cout << typeid(a).name() << endl;
//	add(a);
//	cout << typeid(a).name() << endl;
//	return 0;
//}






