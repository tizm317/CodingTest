#include <iostream>
#include <string>
#include <deque>
//#include <vector>
//#include <algorithm> // reverse
using namespace std;

// ���� ���� Ǯ��
// ��¥		: 2024. 05. 20. ��
// ���� ��ȣ	: #5430
// ���� �̸�	: AC
// �˰���	: 
// �ð����⵵: O()

// AC : ���� �迭 ���� ���
// 1. ������ R : �迭 �� �� ���� ������
// 2. ������ D : ù��° ���� ���� , ������� �� ����
// 1+2 �ѹ��� ��� ����
// "AB" : A -> B
// "RDD" : R -> D -> D

int T, n;
string p;
string arrStr;

//int idx[100005];
deque<int> intDeque;

//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> T;
//	for (int t = 0; t < T; t++)
//	{
//		deque<int> intDeque;
//
//		// �Լ� p
//		cin >> p;
//		cin >> n;
//
//		int reverseCnt = 0;
//		int deleteCnt = 0;
//
//
//		// ���ڿ� ���� �迭 �Է� -> ���� �迭�� ����
//		// [1,2,3,4]
//		// [42,22,3,4]
//		cin >> arrStr;
//		if (arrStr != "[]")
//		{
//			int st = 1;
//			int pos = arrStr.find(',', st);
//			while (pos != -1)
//			{
//				string sub = arrStr.substr(st, pos - st);
//				intDeque.push_back(stoi(sub));
//
//				st = pos + 1;
//				pos = arrStr.find(',', st);
//			}
//
//			string sub = arrStr.substr(st, arrStr.size() - 1);
//			intDeque.push_back(stoi(sub));
//
//			// idx �迭
//			for (int i = 0; i < n; i++)
//				idx[i] = i;
//		}
//		
//
//		for (const char& c : p)
//		{
//			//if (intDeque.empty())
//			//	break;
//
//			if (c == 'R')
//			{
//				//reverse(intDeque.begin(), intDeque.end());
//
//				// idx �迭
//				// 0 1 2 3 -> 3 2 1 0
//				for (int i = 0; i < n; i++)
//				{
//					if (idx[i] == -1)
//						continue;
//
//					idx[i] = (n - 1) - idx[i];
//				}
//
//				reverseCnt++;
//			}
//			else // D
//			{
//				//intDeque.pop_front();
//
//				// idx �迭
//				for (int i = 0; i < n; i++)
//				{
//					if (idx[i] == -1)
//						continue;
//
//					idx[i]--;
//				}
//
//				deleteCnt++;
//			}
//		}
//
//		// ���
//		if (deleteCnt <= n)
//		{
//			cout << '[';
//
//			if (reverseCnt % 2 == 0)
//			{
//				for (int i = 0; i < n; i++)
//				{
//					if (idx[i] == -1)
//						continue;
//
//					cout << intDeque[i];
//					if (i != n-1 && idx[i + 1] != -1)
//						cout << ",";
//				}
//			}
//			else
//			{
//				for (int i = n - 1; i >= 0; i--)
//				{
//					if (idx[i] == -1)
//						continue;
//
//					cout << intDeque[i];
//					if (i != 0 && idx[i - 1] != -1)
//						cout << ",";
//				}
//			}
//
//			cout << ']';
//		}
//		else
//		{
//			cout << "error";
//		}
//
//		cout << '\n';
//	}
//
//	return 0;
//}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �ð��ʰ�..

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		bool isReversed = false;

		// �Լ� p
		cin >> p;
		cin >> n;

		// ���ڿ� ���� �迭 �Է� -> ���� �迭�� ����
		// [1,2,3,4]
		// [42,22,3,4]
		cin >> arrStr;
		if (arrStr != "[]")
		{
			int st = 1;
			int pos = arrStr.find(',', st);
			while (pos != -1)
			{
				string sub = arrStr.substr(st, pos - st);
				intDeque.push_back(stoi(sub));

				st = pos + 1;
				pos = arrStr.find(',', st);
			}

			string sub = arrStr.substr(st, arrStr.size() - 1);
			intDeque.push_back(stoi(sub));
		}

		bool isError = false;
		for (const char& c : p)
		{
			

			if (c == 'R')
			{
				isReversed = !isReversed;

				//reverse(intDeque.begin(), intDeque.end());
			}
			else // D
			{
				if (intDeque.empty())
				{
					isError = true;
					break;
				}

				if (!isReversed)
					intDeque.pop_front();
				else
					intDeque.pop_back();
			}
		}

		// ���
		if (!intDeque.empty())
		{
			cout << '[';

			while (true)
			{
				if (!isReversed)
				{
					cout << intDeque.front();
					intDeque.pop_front();
				}
				else
				{
					cout << intDeque.back();
					intDeque.pop_back();
				}
				

				if (intDeque.empty())
					break;

				cout << ',';
			}

			cout << ']';
		}
		else
		{
			if (isError)
			{
				cout << "error";
			}
			else
			{
				cout << "[]";
			}
		}

		cout << '\n';
	}

	return 0;
}


//
//for (char c : arrStr)
//{
//	if (c == '[' || c == ']' || c == ',')
//		continue;
//
//	// char to int
//	//intDeque.push_back(c - '0'); // 0~9 ������ ����
//}