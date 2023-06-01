//#include <iostream>
//
//using namespace std;
//
//// Deque 배열로 구현
//const int MX = 1000005;
//int dat[2 * MX + 1];
//int head = MX, tail = MX;
//
//void pushBack(int x)
//{
//	dat[tail++] = x;
//}
//
//void pushFront(int x)
//{
//	dat[--head] = x;
//}
//
//void popBack()
//{
//	tail--;
//}
//
//void popFront()
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
//	for (int i = 1; i <= 10; i++)
//	{
//		pushBack(i);
//		cout << back() << " ";
//	}
//	cout << '\n';
//
//	for (int i = 11; i <= 20; i++)
//	{
//		pushFront(i);
//		cout << front() << " ";
//	}
//	cout << '\n';
//
//	// 20 19 18 17 16 15 14 13 12 11 1 2 3 4 5 6 7 8 9 10
//
//	// 앞뒤 번갈아가면서 출력
//	for (int i = 0; i < 20; i++)
//	{
//		if (i % 2 == 0)
//		{
//			cout << front() << " ";
//			popFront();
//		}
//		else
//		{
//			cout << back() << " ";
//			popBack();
//		}
//	}
//
//	// 출력 결과 : 20 10 19 9 18 8 17 7 16 6 15 5 14 4 13 3 12 2 11 1
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}
//
