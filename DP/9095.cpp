//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 22. ��
//// ���� ��ȣ	: #9095 
//// ���� �̸�	: 1,2,3 ���ϱ�
//// �˰���	: DP
//// �ð����⵵: O()
//
//int T;
//int D[12];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// �ʱⰪ ���ϱ�
//	D[1] = 1; // 1
//	D[2] = 2; // 1+1 , 2
//	D[3] = 4; // 1+1+1, 1+2, 2+1, 3
//
//	// ��ȭ�� �ݺ���
//	for (int k = 4; k < 11; k++)
//	{
//		D[k] = D[k - 1] + D[k - 2] + D[k - 3];
//	}
//
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		int x;
//		cin >> x;
//
//		cout << D[x] << '\n';
//	}
//
//	return 0;
//}