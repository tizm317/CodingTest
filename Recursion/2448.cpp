//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 12. ��
//// ���� ��ȣ	: #2448
//// ���� �̸�	: �� ��� - 11
//// �˰���	: 
//// �ð����⵵: O()
//
//int N; // 3 * 2^k
//int arr[3 * 1024][3 * 1024 * 2 - 1];
//
//void func(int n, int centerRow, int centerCol)
//{
//	// �ﰢ���� �� ������ ���� ����
//
//	if (n == 3)
//	{
//		arr[centerRow][centerCol - 1] = 1;
//
//		arr[centerRow + 1][centerCol - 2] = 1;
//		arr[centerRow + 1][centerCol] = 1;
//
//		for(int i = 0; i < 5; i++)
//			arr[centerRow + 2][centerCol - 3 + i] = 1;
//
//		return;
//	}
//
//	func(n / 2, centerRow, centerCol);
//	func(n / 2, centerRow + n/2, centerCol - n/2);
//	func(n / 2, centerRow + n/2, centerCol + n/2);
//
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	func(N, 0, N);
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < 2 * N - 1; c++)
//		{
//			if (arr[r][c] == 0)
//			{
//				cout << " ";
//			}
//			else
//			{
//				cout << '*';
//			}
//		}
//
//		cout << '\n';
//	}
//
//	return 0;
//}