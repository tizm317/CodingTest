//#include <iostream>
//#include <queue>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2024. 04. 24. ��
//// ���� ��ȣ	: #10845, #18258
//// ���� �̸�	: ť, ť2 (�迭 ũ�� ����)
//// �˰���	: ť
//// �ð����⵵: O()
//
//// 1. STL ť
//int N;
//queue<int> intQueue;
//
//// 2. �迭 ���� ť
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
//	// 1. STL ť
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
//	// 2. �迭 ���� ť
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