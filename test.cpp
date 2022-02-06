#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


////交换两个整型函数
//void swapInt(int &a,int &b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
////交换两个浮点型函数
//void swapDouble(double& a, double& b)
//{
//	double tmp = a;
//	a = b;
//	b = tmp;
//}
//函数模板
//template<typename T>//声明一个模板告诉编译器后面代码中紧跟的T不要报错，是通用类型
//void mySwap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	//swapInt(a, b);
//	//函数模板
//	//两种方式
//	//1、自动类型推导
//	//mySwap(a, b);
//	//2、显式指定类型
//	mySwap<int>(a, b);
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	double c = 1.1;
//	double d = 2.2;
//	//swapDouble(c, d);
//	cout << "c=" << c << endl;
//	cout << "d=" << d << endl;
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//函数模板注意事项
//template<class T>//typename可以替换成class
//void mySwap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
////1、自动类型推导,必须要推导出一致的数据类型T才可以使用
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	char c = 'c';
//	//mySwap(a, b);//正确
//	//mySwap(a, c);//错误,推导不出一致T类型
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//}
////2、模板必须要确定出T的数据类型，才可以使用
//template<class T>
//void func()
//{
//	cout << "func调用" << endl;
//}
//void test02()
//{
//	func<int>();
//}
//int main()
//{
//	//test01();
//	test02();
//	system("pause");
//  return 0;
//}

//实现通用 对数组进行排序的函数
//规则 从大到小
//算法 选择
//测试 char int 数组
//template<typename T>
//void mySwap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
////排序
//template<class T>
//void mySort(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		int max = i;//认定最大值下标
//		for (int j = i + 1; j < len; j++)
//		{
//			//认定最大值比遍历出的数值小，说明j下标大
//			if (arr[max] < arr[j])
//			{
//				max = j;
//			}
//		}
//		if (max != i)
//		{
//			//交换max  i下标元素
//			mySwap(arr[max], arr[i]);
//		}
//	}
//}
////打印数组
//template<class T>
//void printArr(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	//测试char数组
//	char charArr[] = "badcfe";
//	int num = sizeof(charArr) / sizeof(char);
//	mySort(charArr, num);
//	printArr(charArr, num);
//}
//void test02()
//{
//	//测试int数组
//	int intArr[] = { 7,5,1,3,9,2,4,6,8 };
//	int num = sizeof(intArr) / sizeof(int);
//	mySort(intArr, num);
//	printArr(intArr, num);
//}
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//	return 0;
//}


//普通函数与函数模板区别
//1、普通函数调用可发生隐式类型转换
//2、函数模板 用自动类型推导 不可以发生隐式类型转换
//3、函数模板 用显式指定类型 可以发生隐式类型转换
//普通函数
//int myAdd01(int a,int b)
//{
//	return a + b;
//}
////函数模板
//template<class T>
//T myAdd02(T a,T b)
//{
//	return a + b;
//}
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	char c = 'c';
//	cout << myAdd01(a, c) << endl;
//	//cout << myAdd02(a, c) << endl;
//	cout << myAdd02<int>(a, c) << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//模板局限性
//有些特定类型数据需要具体化方式实现
#include<string>
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	//姓名
	string m_Name;
	//年龄
	int m_Age;
};

//对比两数据是否相等
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
		return true;
	else
		return false;
}
//利用具体化Person的版本，实现代码，具体化优先调用
template<> bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
		return true;
	else
		return false;
}
void test01()
{
	int a = 10;
	int b = 20;
	bool ret = myCompare(a, b);
	if (ret)
		cout << "a==b" << endl;
	else
		cout << "a!=b" << endl;
}
void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	bool ret = myCompare(p1, p2);
	if (ret)
		cout << "p1==p2" << endl;
	else
		cout << "p1!=p2" << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}