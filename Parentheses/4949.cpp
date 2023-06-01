//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 04. 24. ��
//// ���� ��ȣ	: #4949
//// ���� �̸�	: ���� ���� ����
//// �˰���	: ���� Ȱ��(������ ��ȣ ��)
//// �ð����⵵: O()
//
//stack<char> Stack_Parentheses;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ���ڿ� �ʱ�ȭ
//	string str = "";
//	while (true)
//	{
//		// ��ȣ�� �´� �� üũ�ϴ� boolean �� �ʱ�ȭ
//		bool balanced = true;
//		
//		// str ���پ� �Է�
//		getline(cin, str);
//
//		// "." �Է� �� �ݺ��� ����
//		if (str == ".")
//			break;
//
//		for (const char& c : str)
//		{
//			// ���� ��ȣ( (, [ ) ��ȣ ���ÿ� Ǫ��
//			if (c == '(' || c == '[')
//			{
//				Stack_Parentheses.push(c);
//			}
//			// ���� ��ȣ��, �����Ǵ� ���� ��ȣ�� ���ÿ� �ִ��� Ȯ��
//			// ������ ����ְų�, �ٸ� ��� balanced = false
//			else if (c == ')' || c == ']')
//			{
//				// 1. ������ ����ִ� ���, 2. �ٸ� ��ȣ�� ���
//				if (Stack_Parentheses.empty() || Stack_Parentheses.top() != '(')
//				{
//					balanced = false;
//					break;
//				}
//
//				// 3. �������� ���
//				Stack_Parentheses.pop();
//			}
//			else if (c == ']')
//			{
//				// ������ ����ִ� ���
//				if (Stack_Parentheses.empty())
//				{
//					balanced = false;
//					break;
//				}
//
//				// �ٸ� ��ȣ�� ���
//				if (Stack_Parentheses.top() != '[')
//				{
//					balanced = false;
//					break;
//				}
//
//				// �������� ���
//				Stack_Parentheses.pop();
//			}
//		}
//
//		// 4. ���ÿ� ���� �ִ� ���
//		// ���ÿ� ���� ������ balanced = false (ex : "[." "(." )
//		// ���� ���� (���� ������ �����ؼ�)
//		while (!Stack_Parentheses.empty())
//		{
//			balanced = false;
//			Stack_Parentheses.pop();
//		}
//
//		// ���ڿ��� Ȯ�� ��, boolean ���� true�� ���������ִ� ���ڿ��̱� ������ yes ���
//		if (balanced)
//			cout << "yes\n";
//		else
//			cout << "no\n";
//	}
//
//	return 0;
//}