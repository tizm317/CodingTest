//#include <iostream>
//
//using namespace std;
//
//// �迭�� �̿��� ���� ����
//
//const int MX = 1000005;
//int dat[MX]; // Stack ������ �� �迭
//int pos = 0; // ���� ���� ���� ��ġ, ������ ���� ���� ����
//
//void push(int value)
//{
//	if (pos == MX)
//	{
//		throw "Stack is full.";
//		return;
//	}
//
//	dat[pos++] = value;
//}
//
//void pop()
//{
//	if (pos == 0)
//	{
//		throw "Stack is empty.";
//		return;
//	}
//
//	pos--;
//}
//
//int top()
//{
//	if (pos == 0)
//	{
//		throw "Stack is empty.";
//		return -1;
//	}
//
//	return dat[pos - 1];
//}
//
//void test()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		push(i);
//		cout << top() << " ";
//	}
//
//	cout << '\n';
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << top() << " ";
//		pop();
//	}
//
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}
