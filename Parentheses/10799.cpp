//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2024. 04. 24. ��
//// ���� ��ȣ	: #10799
//// ���� �̸�	: �踷���
//// �˰���	: ����
//// �ð����⵵: O()
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	string str;
//	cin >> str;
//
//	//int overlappedBarCnt = 0;	// ���� �ִ� �� ���� -> �׳� ���� size �ᵵ ��
//	int totalBarCnt = 0;		// �ڸ� �� �� ����
//
//	// ���� ���� ����� -> ���������� ��������� �ľ��ϱ� ����.
//	// 1. ���� ���ڰ� '(' �̸� ������ "()"
//	// 2. ���� ���ڰ� ')' �̸� ����� why? "(())" ���� �̷� ���¶�� ���
//	//char beforChar = '\0';
//
//	bool isPopped = false;
//
//	stack<char> charStack;
//
//	for (char c : str)
//	{
//		if (c == '(')
//		{
//			charStack.push(c);
//
//			// ����� ���ɼ� �ֱ� ������ overlappedBarCnt ����
//			//overlappedBarCnt++; 
//
//			isPopped = false;
//		}
//		else if (c == ')')
//		{
//			// ���� ���ڰ� '(' �̸� ���� ����(c) �� ������ 
//			//if (beforChar == '(')
//			
//			// isPopped �� false : '('
//			if(isPopped == false)
//			{
//				// "()" : ������
//				if (charStack.top() == '(')
//				{
//					// ����� �ƴ϶� overlappedBarCnt ����;
//					//overlappedBarCnt--;
//					charStack.pop();
//					isPopped = true;
//
//					// ������ ����� ������ŭ �ڸ�
//					//totalBarCnt += overlappedBarCnt;
//					totalBarCnt += charStack.size();
//				}
//			}
//			else // ���� ���� ')' �̸�, ���� ����(c) �� �����
//			{
//				// ����� ��������,
//				// ��ģ ����� ���� -1 
//				//overlappedBarCnt--;
//
//				charStack.pop();
//				isPopped = true;
//
//				// ��ü ����� ���� +1 (�߷��� �߰��� ����� ����, ����� ����ü �ϳ� �߰������ ��)
//				totalBarCnt++;
//
//			}
//
//		}
//
//		// ���� ���� ���� 
//		//beforChar = c;
//	}
//
//	// ����� ���� ���
//	cout << totalBarCnt;
//
//	return 0;
//}