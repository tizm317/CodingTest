//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 23. ȭ
//// ���� ��ȣ	: #11726 
//// ���� �̸�	: 2 x n Ÿ�ϸ�
//// �˰���	: DP
//// �ð����⵵: O()
//
//int D[1005];
//int N;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	// �ʱⰪ ���ϱ�
//	D[1] = 1;
//	D[2] = 2;
//
//	// ��ȭ�� �ݺ���
//	for (int k = 4; k <= N; k++)
//		D[k] = (D[k - 1] + D[k - 2]) % 10007;	// int overflow
//
//	cout << D[N];
//
//
//	return 0;
//}