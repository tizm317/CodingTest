//#include <iostream>
//#include <stack>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 04. 25. ȭ
//// ���� ��ȣ	: #2504 
//// ���� �̸�	: ��ȣ�� ��
//// �˰���	: ����
//// �ð����⵵: O()
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ���ڿ� �Է�
//	string str;
//	cin >> str;
//
//	bool isValid = true;
//
//	// ���� : ���ڶ� ���ڸ� ���� �����Ϸ��ٺ��� ����
//	// ���� ���ϴٰ� �쿬�� (, ), [, ] ���� �ƽ�Ű �ڵ�� �������� �̻�����
//	// �׸��� char �� �� ��, ���� ���ϴٰ� ���� ���
//	// string 2^30 ���� �ϱ� int ���� �� �ذ�Ǳ� ��.
//
//	// ->>>>>>>>>>>> ���� 2���� �ذ�
//
//	// string 2^30 ���� -> int ����
//	stack<char> expStack; // ���� ���� <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//	stack<int> numStack; // �� ����
//
//	for (char c : str)
//	{
//		// 1. ���� ��ȣ (, [ : ���ÿ� push
//		if (c == '(' || c == '[')
//		{
//			expStack.push(c);
//		}
//		else if (c == ')') // 2. �ݴ� ��ȣ )
//		{
//			// 0. ����ִ� ��� : �ùٸ��� ����
//			if (expStack.empty())
//			{
//				isValid = false;
//				break;
//			}
//
//			// 1. "()" : ���� ��ȣ�� 2�� �ٲ�
//			if (expStack.top() == '(')
//			{
//				expStack.pop();		// ( ����
//				expStack.push(2);	// 2 ����
//
//				numStack.push(2);	// ������
//			}
//			// 2. [) : �ùٸ��� ���� ���
//			else if(expStack.top() == '[') 
//			{
//				isValid = false;
//				break;
//			}
//			else // 3. ���� �ִ� ���
//			{
//				// ��ȣ ���� ���ڵ� ����
//				int sum = 0;
//
//				// ���� ��ȣ ���� ������, ���� ����
//				while (!expStack.empty() && expStack.top() != '(')
//				{
//					if (expStack.top() == '[')
//					{
//						isValid = false;
//						break;
//					}
//
//					expStack.pop();
//
//					sum += numStack.top();
//					numStack.pop();
//				}
//
//				// ���� ���� ���� ��ȣ�� ���� ���! : �ùٸ��� ����
//				if (expStack.empty())
//				{
//					isValid = false;
//					break;
//				}
//				else // �������� ���
//				{
//					// ��ȣ ����
//					expStack.pop();
//				}
//
//				expStack.push(2); // �������� ǥ��
//
//				// sum�� 2 ���� �� push
// 				numStack.push(sum * 2);
//			}
//		}
//		else if (c == ']')
//		{
//			// 0. ����ִ� ��� : �ùٸ��� ����
//			if (expStack.empty())
//			{
//				isValid = false;
//				break;
//			}
//
//			// 1. "[]"
//			if (expStack.top() == '[')
//			{
//				expStack.pop();		// ( ����
//				expStack.push(3);	// 3 ����
//
//				numStack.push(3);
//			}
//			// 2. "(]"
//			else if (expStack.top() == '(')
//			{
//				// �ùٸ��� ����
//				isValid = false;
//				break;
//			}
//			else // 3. ���� �ִ� ���
//			{
//				// ��ȣ ���� '���ڵ�' ����
//				int sum = 0;
//				while (!expStack.empty() && expStack.top() != '[')
//				{
//					if (expStack.top() == '(')
//					{
//						isValid = false;
//						break;
//					}
//
//					expStack.pop();
//
//					sum += numStack.top();
//					numStack.pop();
//				}
//
//				// ���� ���� ���� ��ȣ�� ���� ���! : �ùٸ��� ����
//				if (expStack.empty())
//				{
//					isValid = false;
//					break;
//				}
//				else // �������� ���
//				{
//					// ��ȣ ����
//					expStack.pop();
//				}
//				
//				expStack.push(3); // ���ڰ� ���� ǥ��
//
//				// sum�� 3 ���� �� push
//				numStack.push(sum * 3);
//			}
//		}
//	}
//
//	// ���������� ���ÿ� ���� ���ڵ� ����
//	int res = 0;
//	while (!expStack.empty())
//	{
//		// ���� ���� ���� ��ȣ ���� ������, �ùٸ��� ���� ���
//		if (expStack.top() == '(' || expStack.top() == '[')
//		{
//			isValid = false;
//			break;
//		}
//
//		expStack.pop();
//
//		res += numStack.top();
//		numStack.pop();
//	}
//
//	// ����� ���
//	if (isValid)
//		cout << res;
//	else
//		cout << 0;
//
//
//	return 0;
//}