#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


////�����������ͺ���
//void swapInt(int &a,int &b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
////�������������ͺ���
//void swapDouble(double& a, double& b)
//{
//	double tmp = a;
//	a = b;
//	b = tmp;
//}
//����ģ��
//template<typename T>//����һ��ģ����߱�������������н�����T��Ҫ������ͨ������
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
//	//����ģ��
//	//���ַ�ʽ
//	//1���Զ������Ƶ�
//	//mySwap(a, b);
//	//2����ʽָ������
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

//����ģ��ע������
//template<class T>//typename�����滻��class
//void mySwap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
////1���Զ������Ƶ�,����Ҫ�Ƶ���һ�µ���������T�ſ���ʹ��
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	char c = 'c';
//	//mySwap(a, b);//��ȷ
//	//mySwap(a, c);//����,�Ƶ�����һ��T����
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//}
////2��ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
//template<class T>
//void func()
//{
//	cout << "func����" << endl;
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

//ʵ��ͨ�� �������������ĺ���
//���� �Ӵ�С
//�㷨 ѡ��
//���� char int ����
//template<typename T>
//void mySwap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
////����
//template<class T>
//void mySort(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		int max = i;//�϶����ֵ�±�
//		for (int j = i + 1; j < len; j++)
//		{
//			//�϶����ֵ�ȱ���������ֵС��˵��j�±��
//			if (arr[max] < arr[j])
//			{
//				max = j;
//			}
//		}
//		if (max != i)
//		{
//			//����max  i�±�Ԫ��
//			mySwap(arr[max], arr[i]);
//		}
//	}
//}
////��ӡ����
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
//	//����char����
//	char charArr[] = "badcfe";
//	int num = sizeof(charArr) / sizeof(char);
//	mySort(charArr, num);
//	printArr(charArr, num);
//}
//void test02()
//{
//	//����int����
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


//��ͨ�����뺯��ģ������
//1����ͨ�������ÿɷ�����ʽ����ת��
//2������ģ�� ���Զ������Ƶ� �����Է�����ʽ����ת��
//3������ģ�� ����ʽָ������ ���Է�����ʽ����ת��
//��ͨ����
//int myAdd01(int a,int b)
//{
//	return a + b;
//}
////����ģ��
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

//ģ�������
//��Щ�ض�����������Ҫ���廯��ʽʵ��
#include<string>
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	//����
	string m_Name;
	//����
	int m_Age;
};

//�Ա��������Ƿ����
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
		return true;
	else
		return false;
}
//���þ��廯Person�İ汾��ʵ�ִ��룬���廯���ȵ���
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