//#include <iostream>
//#include <stack>
//#include <string> // getline
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 04. 24. ��
//// ���� ��ȣ	: #3986 
//// ���� �̸�	: ���� �ܾ�
//// �˰���	: ����
//// �ð����⵵: O()
//
//int N;
//stack<char> charStack;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// �ܾ� �� �Է�
//	cin >> N;
//
//	// ���๮�� ���ۿ� ���� ���� -> �Է� ���� ����
//	cin.ignore();
//
//	// ���� �ܾ� ���� �ʱ�ȭ
//	int goodWordCnt = 0;
//
//	for (int i = 0; i < N; i++)
//	{
//		// ���ڿ� �Է�
//		string str;
//		getline(cin, str);
//
//		// ���� �� a, b ���� ����
//		//int aCnt = 0, bCnt = 0;
//		bool isGoodWord = true;
//
//		// �ݷ� : ABABBABA : ���� �ܾ��ε�, ���� ���� § �ڵ�δ� �ȵ�.
//		// -> ���ÿ� �� �ִ� ������� ���� (���������� ���ÿ� ���� ���ڰ� ������ ���� �ܾ�, ������ ���� �ܾ�� �Ǵ�)
//		// ���� ������δ� ABA.. ���� �̹� ���� �ܾ�� �����ϰ� break �Ǿ����
//
//		for (char c : str)
//		{
//			// ������� �ʰ�, top�� �ִ� ���� == c(������ ����)
//			if (!charStack.empty() && charStack.top() == c)
//			{
//				charStack.pop();
//			}
//			else
//			{
//				charStack.push(c);
//			}
//		}
//
//		// ���ÿ� ����������, false �� �ٲٰ� ���� ���
//		while (!charStack.empty())
//		{
//			isGoodWord = false;
//			charStack.pop();
//		}
//
//		// ���� �ܾ� ���� ����
//		if (isGoodWord)
//			goodWordCnt++;
//	}
//
//	cout << goodWordCnt;
//
//	return 0;
//}