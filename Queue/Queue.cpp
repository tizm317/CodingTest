//#include <iostream>
//
//using namespace std;
//
//// ���� �迭�� ť ����
//const int MX = 100005;
//int dat[MX];
//int head = 0;
//int tail = 0;
//
//// ���� �迭�� �����Ϸ���, MX ������ 0���� ���� �ϸ� ��.
//// ���׿����� ����� ����� Ű��⸸ �ϸ� ��.
//
//void push(int x)
//{
//	dat[tail++] = x;
//}
//
//void pop()
//{
//	head++;
//}
//
//int front()
//{
//	return dat[head];
//}
//
//int back()
//{
//	return dat[tail - 1];
//}
//
//void test()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		push(i);
//		cout << back() << " ";
//	}
//	cout << '\n';
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << front() << " ";
//		pop();
//	}
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}
//
