//#include <iostream>
//#include <stack>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 24. 월
//// 문제 번호	: #10828 
//// 문제 이름	: 스택
//// 알고리즘	: 스택
//// 시간복잡도: O()
//
//int N;
//
//// 1. STL 스택
//stack<int> intStack;
//
//// 2. 배열 구현 스택
//const int MX = 10005;
//int dat[MX];
//int pos = 0;
//
//void push(int x)
//{
//	dat[pos++] = x;
//}
//
//void pop()
//{
//	pos--;
//}
//
//int top()
//{
//	return dat[pos - 1];
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 1. STL Stack 풀이
//	//cin >> N;
//	//for (int i = 0; i < N; i++)
//	//{
//	//	// 명령어 입력
//	//	string command = "\0";
//	//	cin >> command;
//
//	//	// 명령어별 처리
//	//	if (command == "push")
//	//	{
//	//		int x;
//	//		cin >> x;
//
//	//		intStack.push(x);
//	//	}
//	//	else if (command == "pop")
//	//	{
//	//		if (intStack.empty())
//	//			cout << -1 << '\n';
//	//		else
//	//		{
//	//			cout << intStack.top() << '\n';
//	//			intStack.pop();
//	//		}
//	//	}
//	//	else if (command == "size")
//	//	{
//	//		cout << intStack.size() << '\n';
//	//	}
//	//	else if (command == "empty")
//	//	{
//	//		cout << intStack.empty() << '\n';
//	//	}
//	//	else if (command == "top")
//	//	{
//	//		if (intStack.empty())
//	//			cout << -1 << '\n';
//	//		else
//	//			cout << intStack.top() << '\n';
//	//	}
//
//	//}
//
//
//	// 2. 직접 만든 Stack 풀이
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		// 명령어 입력
//		string command = "\0";
//		cin >> command;
//
//		// 명령어별 처리
//		if (command == "push")
//		{
//			int x;
//			cin >> x;
//
//			push(x);
//		}
//		else if (command == "pop")
//		{
//			if (pos == 0)
//				cout << -1 << '\n';
//			else
//			{
//				cout << top() << '\n';
//				pop();
//			}
//		}
//		else if (command == "size")
//		{
//			cout << pos << '\n';
//		}
//		else if (command == "empty")
//		{
//			cout << (pos == 0) << '\n';
//		}
//		else if (command == "top")
//		{
//			if (pos == 0)
//				cout << -1 << '\n';
//			else
//				cout << top() << '\n';
//		}
//	}
//
//
//	return 0;
//}