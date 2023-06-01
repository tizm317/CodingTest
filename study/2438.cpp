//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 04. 17. ��
//// ���� ��ȣ	: #2438 
//// ���� �̸�	: �� ��� - 1 ~ 9
//// �˰���	: �ݺ���
//// �ð����⵵: O(N^2)
//
//int N;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	// 1. row �࿡ row ������ŭ '*' ���
//	for (int row = 1; row <= N; ++row)
//	{
//		for (int col = 1; col <= row; ++col)
//		{
//			cout << '*';
//		}
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 2. ������ ����
//	for (int row = 1; row <= N; ++row)
//	{
//		// " " ���
//		for (int col = 1; col <= N - row; ++col)
//		{
//			cout << " ";
//		}
//
//		// '*' ���
//		for (int col = 1; col <= row; ++col)
//		{
//			cout << '*';
//		}
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 3. ���ﰢ��
//	for (int row = 1; row <= N; ++row)
//	{
//		for (int col = 1; col <= N - row + 1; ++col)
//		{
//			cout << '*';
//		}
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 4. ���ﰢ�� + ���� ����
//	for (int row = 1; row <= N; ++row)
//	{
//		// ���� ���
//		for (int col = 1; col <= row - 1; ++col)
//		{
//			cout << " ";
//		}
//
//		// * ���
//		for (int col = 1; col <= N - row + 1; ++col)
//		{
//			cout << '*';
//		}
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 5. 1 3 5 7 9
//	for (int row = 1; row <= N; ++row)
//	{
//		// ���� ���
//		for (int col = 1; col <= N - 1 / 2 - row; ++col)
//		{
//			cout << " ";
//		}
//
//		// * ���
//		for (int col = 1; col <= 2 * row - 1; ++col)
//		{
//			cout << '*';
//		}
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 6. 5 ���Ƕ�̵�
//	for (int row = 1; row <= N; ++row)
//	{
//		// ���� ���
//		for (int col = 1; col <= row - 1; ++col)
//		{
//			cout << " ";
//		}
//
//		// * ���
//		for (int col = 1; col <= 2 * (N - row) + 1; ++col)
//		{
//			cout << '*';
//		}
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 7. 5�� + 6��
//	for (int row = 1; row <= 2 * N - 1; ++row)
//	{
//		if (row < 5)
//		{
//			// ���� ���
//			for (int col = 1; col <= N - 1 / 2 - row; ++col)
//			{
//				cout << " ";
//			}
//
//			// * ���
//			for (int col = 1; col <= 2 * row - 1; ++col)
//			{
//				cout << '*';
//			}
//		}
//		else
//		{
//			// ���� ���
//			for (int col = 1; col <= (row - 4) - 1; ++col)
//			{
//				cout << " ";
//			}
//
//			// * ���
//			for (int col = 1; col <= 2 * (N - (row - 4)) + 1; ++col)
//			{
//				cout << '*';
//			}
//		}
//
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 8. 
//	for (int row = 1; row <= 2 * N - 1; ++row)
//	{
//		// ��Ʈ 1
//		if (row < N)
//		{
//			for (int col = 1; col <= row; ++col)
//			{
//				cout << '*';
//			}
//
//			// ��Ʈ 2
//			for (int col = 1; col <= 2 * (N - row); ++col)
//			{
//				cout << " ";
//			}
//
//			// ��Ʈ 3
//			for (int col = 1; col <= row; ++col)
//			{
//				cout << '*';
//			}
//		}
//		else
//		{
//			// 5 6 7 8 9
//			// 5 4 3 2 1
//			for (int col = 1; col <=  2 * N - row; ++col)
//			{
//				cout << '*';
//			}
//			
//			// ��Ʈ 2
//			for (int col = 1; col <= 2 * (row - N); ++col)
//			{
//				cout << " ";
//			}
//
//			// ��Ʈ 3
//			for (int col = 1; col <= 2 * N - row; ++col)
//			{
//				cout << '*';
//			}
//		}
//
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 9. 8�� �ݴ�
//	for (int row = 1; row <= 2 * N - 1; ++row)
//	{
//		if (row <= N)
//		{
//			// ���� ���
//			for (int col = 1; col <= row - 1; ++col)
//			{
//				cout << " ";
//			}
//
//			// * ���
//			for (int col = 1; col <= 2 * (N - row) + 1; ++col)
//			{
//				cout << '*';
//			}
//		}
//		else
//		{
//			// ���� ���
//			for (int col = 1; col <= N - 1 / 2 - (row - N + 1); ++col)
//			{
//				cout << " ";
//			}
//
//			// * ���
//			for (int col = 1; col <= 2 * (row - N + 1) - 1; ++col)
//			{
//				cout << '*';
//			}
//		}
//
//		cout << '\n';
//	}
//
//
//	return 0;
//}