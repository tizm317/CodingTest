//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 08. ��.
//// ���� ��ȣ	: #15486 
//// ���� �̸�	: ��� 2
//// �˰���	: DP
//// �ð����⵵: O()
//
//int N;
//int T[1'500'005];	// ��� �ҿ� �Ⱓ
//int P[1'500'005];	// ����
//int D[1'500'005];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//		cin >> T[i] >> P[i];
//
//
//	if (1 + T[1] <= N + 1)
//	{
//		D[1] = P[1];
//		fill(D + 1 + T[1], D + N, P[1]);
//	}
//	else // N �� 1�� ��, T[1] �� 1���� ũ��, �Ұ����ϴϱ� �ʱ�ȭ 0���� �ؾ���
//		D[1] = 0;
//
//	for (int i = 2; i <= N; i++)
//	{
//		// �Ⱓ �ʰ��Ǵ� �� pass
//		if (i + T[i] > N + 1)
//			continue;
//
//		D[i] = D[i] + P[i];
//		
//		for (int j = i + T[i]; j <= N; j++)
//			D[j] = max(D[j], D[i]);
//	}
//
//	cout << *max_element(D, D + N + 1);
//
//	return 0;
//}