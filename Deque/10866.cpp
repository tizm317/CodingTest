//#include <iostream>
//#include <deque>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 24
//// 문제 번호	: #10866 
//// 문제 이름	: 덱
//// 알고리즘	: 덱
//// 시간복잡도: O()
//
//int N;
//deque<int> intDeque;
//
//// 2. 배열 구현 덱
//const int MX = 10005;
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
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 1. STL Deque 
//	//cin >> N;
//	//for (int i = 0; i < N; i++)
//	//{
//	//	string command = "\0";
//	//	cin >> command;
//
//	//	if (command == "push_front")
//	//	{
//	//		int x;
//	//		cin >> x;
//
//	//		intDeque.push_front(x);
//	//	}
//	//	else if (command == "push_back")
//	//	{
//	//		int x;
//	//		cin >> x;
//
//	//		intDeque.push_back(x);
//	//	}
//	//	else if (command == "pop_front")
//	//	{
//	//		if (intDeque.empty())
//	//		{
//	//			cout << -1 << '\n';
//	//		}
//	//		else
//	//		{
//	//			cout << intDeque.front() << '\n';
//	//			intDeque.pop_front();
//	//		}
//	//	}
//	//	else if (command == "pop_back")
//	//	{
//	//		if (intDeque.empty())
//	//		{
//	//			cout << -1 << '\n';
//	//		}
//	//		else
//	//		{
//	//			cout << intDeque.back() << '\n';
//	//			intDeque.pop_back();
//	//		}
//	//	}
//	//	else if (command == "size")
//	//	{
//	//		cout << intDeque.size() << '\n';
//	//	}
//	//	else if (command == "empty")
//	//	{
//	//		cout << intDeque.empty() << '\n';
//	//	}
//	//	else if (command == "front")
//	//	{
//	//		if (intDeque.empty())
//	//		{
//	//			cout << -1 << '\n';
//	//		}
//	//		else
//	//		{
//	//			cout << intDeque.front() << '\n';
//	//		}
//	//	}
//	//	else if (command == "back")
//	//	{
//	//		if (intDeque.empty())
//	//		{
//	//			cout << -1 << '\n';
//	//		}
//	//		else
//	//		{
//	//			cout << intDeque.back() << '\n';
//	//		}
//	//	}
//	//}
//
//
//	// 2. 배열 구현 Deque
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		string command = "\0";
//		cin >> command;
//
//		if (command == "push_front")
//		{
//			int x;
//			cin >> x;
//
//			pushFront(x);
//		}
//		else if (command == "push_back")
//		{
//			int x;
//			cin >> x;
//
//			pushBack(x);
//		}
//		else if (command == "pop_front")
//		{
//			if (head == tail)
//			{
//				cout << -1 << '\n';
//			}
//			else
//			{
//				cout << front() << '\n';
//				popFront();
//			}
//		}
//		else if (command == "pop_back")
//		{
//			if (head == tail)
//			{
//				cout << -1 << '\n';
//			}
//			else
//			{
//				cout << back() << '\n';
//				popBack();
//			}
//		}
//		else if (command == "size")
//		{
//			cout << tail - head << '\n';
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
//
//
//	return 0;
//}