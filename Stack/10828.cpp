//#include <iostream>
//#include <stack>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 04. 24. ��
//// ���� ��ȣ	: #10828 
//// ���� �̸�	: ����
//// �˰���	: ����
//// �ð����⵵: O()
//
//int N;
//
//// 1. STL ����
//stack<int> intStack;
//
//// 2. �迭 ���� ����
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
//	// 1. STL Stack Ǯ��
//	//cin >> N;
//	//for (int i = 0; i < N; i++)
//	//{
//	//	// ��ɾ� �Է�
//	//	string command = "\0";
//	//	cin >> command;
//
//	//	// ��ɾ ó��
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
//	// 2. ���� ���� Stack Ǯ��
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		// ��ɾ� �Է�
//		string command = "\0";
//		cin >> command;
//
//		// ��ɾ ó��
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