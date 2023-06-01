//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <utility> // pair
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 01. ��
//// ���� ��ȣ	: #7795
//// ���� �̸�	: ���� ���ΰ� ���� ���ΰ�
//// �˰���	: ����  (�Ǵ� �̺� Ž��)
//// �ð����⵵: O()
//
//int T;
//int N, M;
//
//
//bool cmp(int a, int b)
//{
//	return a > b;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		cin >> N >> M;
//
//		vector<pair<int, int>> vec(N+M);
//		for (int j = 0; j < N; j++)
//		{
//			int x;
//			cin >> x;
//			vec[j] = { x, 0 }; // A �����
//		}
//
//		for (int j = N; j < N + M; j++)
//		{
//			int x;
//			cin >> x;
//			vec[j] = { x, 1 }; // B �����
//		}
//
//		// 8 1 7 3 1 3 6 1
//		// 0 0 0 0 0 1 1 1
//		sort(vec.begin(), vec.end());
//		// 1 1 1 3 3 6 7 8
//		// 0 0 1 0 1 1 0 0
//		// A A B A B B A A
//		// A�� ���� B ������ŭ ���� �� �ִ�
//		// A, B �� ũ�Ⱑ ���� ��� ���� �� �ϱ� ������, ũ�Ⱑ ���� ��� A�� ���ʿ� �ε��� �Ѵ�(second ���� A�� 0�� ����)
//		// ���� ũ�Ⱑ ���� �� ���� �� �ִٸ�, second ���� A�� B���� Ŀ�� ��
//
//		int eatableFishCnt = 0;
//		int totalCnt = 0;
//		for (int j = 0; j < N + M; j++)
//		{
//			// ���� ����Ⱑ A�� ���, ��Ż ������ (������ �ִ� ����� ����) ����
//			if (vec[j].second == 0)
//				totalCnt += eatableFishCnt;
//
//			// B �� ���, ���� �� �ִ� ����� ���� ����
//			if (vec[j].second == 1)
//				eatableFishCnt++;
//		}
//
//		cout << totalCnt << '\n';
//	}
//
//	return 0;
//}