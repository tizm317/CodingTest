//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 08. ��.
//// ���� ��ȣ	: #14501 
//// ���� �̸�	: ���
//// �˰���	: DP
//// �ð����⵵: O()
//
//int N;
//int T[20];	// ��� �ҿ� �Ⱓ
//int P[20];	// ����
//int D[20]; 
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
//		D[1] = P[1];
//	else // N �� 1�� ��, T[1] �� 1���� ũ��, �Ұ����ϴϱ� �ʱ�ȭ 0���� �ؾ���
//		D[1] = 0;
//
//	for (int i = 2; i <= N; i++)
//	{
//		// �Ⱓ �ʰ��Ǵ� �� pass
//		if (i + T[i] > N + 1)
//			continue;
//
//		// �ִ� ���� ���ϱ�
//		// 0~i-1 ���� �ִ� ���� + i��° ����
//		int maxPay = 0;
//		for (int j = i - 1; j >= 0; j--)
//		{
//			// �Ⱓ �ʰ��Ǵ� �� pass
//			if (j + T[j] > i)
//				continue;
//
//			maxPay = max(maxPay, D[j]);
//		}
//		D[i] = maxPay + P[i];
//	}
//
//	cout << *max_element(D, D + N + 1);
//
//	return 0;
//}