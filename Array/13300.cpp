//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 27. ȭ.
//// ���� ��ȣ	: #13300 
//// ���� �̸�	: �� ����
//// �˰���	: �迭
//// �ð����⵵: O()
//
//int N, K;
//int students[2][6]; // ����, �г�
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> K;
//	for (int i = 0; i < N; i++)
//	{
//		// ����, �г�
//		int S, Y;
//
//		cin >> S >> Y;
//
//		students[S][Y - 1]++;
//	}
//
//	int ans = 0;
//	for (int s = 0; s < 2; s++)
//	{
//		for (int y = 0; y < 6; y++)
//		{
//			// 0���̸�, �� ���� �ʿ� X
//			if (students[s][y] == 0)
//				continue;
//
//			if (students[s][y] % K == 0)
//			{
//				ans += (students[s][y] / K);
//			}
//			else // K�� �� ���� �������� �� 1�� �� �ʿ�
//			{
//				ans += (students[s][y] / K + 1);
//			}
//
//		}
//	}
//
//	cout << ans;
//
//	return 0;
//}