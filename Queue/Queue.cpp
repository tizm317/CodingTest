//#include <iostream>
//
//using namespace std;
//
//// 선형 배열로 큐 구현
//const int MX = 100005;
//int dat[MX];
//int head = 0;
//int tail = 0;
//
//// 원형 배열로 구현하려면, MX 다음을 0으로 가게 하면 됨.
//// 코테에서는 충분히 사이즈를 키우기만 하면 됨.
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
