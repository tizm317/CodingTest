//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 23. ȭ.
//// ���� ��ȣ	: #1932
//// ���� �̸�	: ���� �ﰢ��
//// �˰���	: DP
//// �ð����⵵: O()
//
//int N;
//int arr[500];
//int D[500];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	// k��° ��
//	for (int k = 1; k <= N; k++)
//	{
//		// �迭 ũ�� �ϳ��� Ŀ��
//		// �Ǿ�, �� �ڴ� �״�� ��������,
//		// �߰� ���ҵ��� max(i-1, i) �� ä����
//		for (int m = k - 1; m > 0; m--)
//		{
//			D[m] = max(D[m - 1], D[m]);
//		}
//
//		for (int j = 0; j < k; j++)
//		{
//			cin >> arr[j];
//			D[j] += arr[j];
//		}
//	}
//
//	cout << *max_element(D, D + N);
//
//	return 0;
//}