//#include <iostream>
//#include <stack>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 04. 24. ��
//// ���� ��ȣ	: #10773 
//// ���� �̸�	: ����
//// �˰���	: ����
//// �ð����⵵: O()
//
//int K;	
//stack<int> intStack;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> K;
//	for (int i = 0; i < K; i++)
//	{
//		int x;
//		cin >> x;
//
//		// x �� 0 �� ��� �ֱ� �� ���� (pop)
//		if (x == 0)
//		{
//			intStack.pop();
//		}
//		else
//		{
//			intStack.push(x);
//		}
//	}
//
//	// Stack �� ��� �� ���ϱ�
//	int sum = 0;
//	while (!intStack.empty())
//	{
//		sum += intStack.top();
//		intStack.pop();
//	}
//
//	// ��� ���
//	cout << sum;
//
//	// int 4byte
//	// 4 * 8bit = 32bit
//	// 2^32
//	// �������� �� <= 2^31 - 1 �� ������ ������ int ����
//
//	return 0;
//}