//#include <iostream>
//#include <stack>
//#include <queue>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 04. 24. ��
//// ���� ��ȣ	: #1874 
//// ���� �̸�	: ���� ����
//// �˰���	: ����
//// �ð����⵵: O()
//
//int n;
//
//queue<int> sequence;// ���� ť�� ����
//stack<int> S;		// ���� ���ÿ� ����
//queue<char> answer; // push(+), pop(-) ���� ����ϱ� ���� ť�� ����  (���� ��� ������ ť�� �����صΰ� �������� ���)
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> n;
//	
//	// ��� ���� �Է�
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		sequence.push(x); // 4 3 6 8 7 5 2 1
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		// 1 ~ n ���� ������� ���ÿ� push 
//		S.push(i);
//		answer.push('+');
//		//cout << '+' << '\n';
//
//		// ���� ť front �� ���� ���� top ��
//		while (sequence.front() == S.top())
//		{
//			// ������ �Ѵ� pop (-)
//			S.pop();
//			sequence.pop();
//			answer.push('-');
//			//cout << '-' << '\n';
//
//			// �� �� �ϳ� empty �� ��� Ż��
//			if (sequence.empty() || S.empty())
//				break;
//		}
//	}
//
//	// �� �� �ϳ��� empty �� �ƴϸ�, ����
//	if (!sequence.empty() || !S.empty())
//	{
//		cout << "NO" << '\n';
//	}
//	else
//	{
//		// ������ ���, ť�� ����� ������� ���
//		while (!answer.empty())
//		{
//			cout << answer.front() << '\n';
//			answer.pop();
//		}
//	}
//
//	return 0;
//}