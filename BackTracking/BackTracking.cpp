//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	// 1. ����
//
//	int a[3] = { 1,2,3 };
//	do
//	{
//		for (int i = 0; i < 3; i++)
//			cout << a[i];
//		cout << '\n';
//	} while (next_permutation(a, a + 3));
//
//	cout << '\n';
//	
//	// �ߺ� ���Ե� ����
//	int b[3] = { 1,1,3 };
//	do
//	{
//		for (int i = 0; i < 3; i++)
//			cout << b[i];
//		cout << '\n';
//	} while (next_permutation(b, b + 3));
//	cout << '\n';
//
//	// 2. ����
//	int c[4] = { 0,0,1,1 }; // 4���� 2�� �̱�
//	do
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			if(c[i] == 1)
//				cout << i+1;
//		}
//		cout << '\n';
//	} while (next_permutation(c, c + 4));
//	// 0,1 �� ��ġ�� �ٸ��� ��
//	// 1 1 0 0
//	// 1 0 1 0
//	// 1 0 0 1
//	// 0 1 1 0
//	// 0 1 0 1
//	// 0 0 1 1
//
//	return 0;
//}
