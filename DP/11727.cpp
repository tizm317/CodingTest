//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 08. ��
//// ���� ��ȣ	: #11727 
//// ���� �̸�	: 2xn Ÿ�ϸ� 2
//// �˰���	: DP
//// �ð����⵵: O()
//
//int N;
//int D[1005];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	// D[n] = D[n-1] + 2 * D[n-2]
//	// D[1] = 1
//	// D[2] = 3
//	D[1] = 1;
//	D[2] = 3;
//	for (int i = 3; i <= N; i++)
//	{
//		D[i] = (D[i - 1] + 2 * D[i - 2]) % 10'007;
//	}
//
//	cout << D[N];
//
//	return 0;
//}