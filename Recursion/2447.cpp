//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 12. ��
//// ���� ��ȣ	: #2447 
//// ���� �̸�	: �� ��� - 10
//// �˰���	: 
//// �ð����⵵: O()
//
//int N;
//
//int arr[2200][2200];
//
//void func(int n, int r, int c)
//{
//	if (n == 3)
//	{
//		// ��� ��ĭ(1) ǥ��
//		arr[r + 1][c + 1] = 1;
//
//		return;
//	}
//
//	for (int row = 0; row < 3; row++)
//	{
//		for (int col = 0; col < 3; col++)
//		{
//			if (row == 1 && col == 1)
//			{
//				for (int i = r + row * n / 3; i < r + row * n / 3 * 2; i++)
//				{
//					for (int j = c + col * n / 3; j < c + col * n / 3 * 2; j++)
//					{
//						arr[i][j] = 1;
//					}
//				}
//				continue;
//			}
//
//			func(n / 3, r + row * n / 3, c + col * n / 3);
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	func(N, 0, 0);
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			if (arr[r][c] == 0)
//			{
//				cout << '*';
//			}
//			else
//			{
//				cout << " ";
//			}
//		}
//		cout << '\n';
//	}
//
//	return 0;
//}