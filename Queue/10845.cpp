//#include <iostream>
//#include <queue>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2024. 04. 24. 월
//// 문제 번호	: #10845, #18258
//// 문제 이름	: 큐, 큐2 (배열 크기 차이)
//// 알고리즘	: 큐
//// 시간복잡도: O()
//
//// 1. STL 큐
//int N;
//queue<int> intQueue;
//
//// 2. 배열 구현 큐
//const int MX = 10005; // 2'000'005; // 18258
//int dat[MX];
//int head = 0;
//int tail = 0;
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
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 1. STL 큐
//
//	/*cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		string command = "\0";
//		cin >> command;
//		
//		if (command == "push")
//		{
//			int x;
//			cin >> x;
//
//			intQueue.push(x);
//		}
//		else if (command == "pop")
//		{
//			if (intQueue.empty())
//			{
//				cout << -1 << '\n';
//			}
//			else
//			{
//				cout << intQueue.front() << '\n';
//				intQueue.pop();
//			}
//		}
//		else if (command == "size")
//		{
//			cout << intQueue.size() << '\n';
//		}
//		else if (command == "empty")
//		{
//			cout << intQueue.empty() << '\n';
//		}
//		else if (command == "front")
//		{
//			if (intQueue.empty())
//			{
//				cout << -1 << '\n';
//			}
//			else
//			{
//				cout << intQueue.front() << '\n';
//			}
//		}
//		else if (command == "back")
//		{
//			if (intQueue.empty())
//			{
//				cout << -1 << '\n';
//			}
//			else
//			{
//				cout << intQueue.back() << '\n';
//			}
//		}
//	}*/
//
//	// 2. 배열 구현 큐
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		string command = "\0";
//		cin >> command;
//
//		if (command == "push")
//		{
//			int x;
//			cin >> x;
//
//			push(x);
//		}
//		else if (command == "pop")
//		{
//			if (head == tail)
//			{
//				cout << -1 << '\n';
//			}
//			else
//			{
//				cout << front() << '\n';
//				pop();
//			}
//		}
//		else if (command == "size")
//		{
//			cout << (tail - head) << '\n';
//		}
//		else if (command == "empty")
//		{
//			cout << (head == tail) << '\n';
//		}
//		else if (command == "front")
//		{
//			if (head == tail)
//			{
//				cout << -1 << '\n';
//			}
//			else
//			{
//				cout << front() << '\n';
//			}
//		}
//		else if (command == "back")
//		{
//			if (head == tail)
//			{
//				cout << -1 << '\n';
//			}
//			else
//			{
//				cout << back() << '\n';
//			}
//		}
//	}
//
//	return 0;
//}