//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 23. ȭ
//// ���� ��ȣ	: #2579
//// ���� �̸�	: ��� ������
//// �˰���	: DP
//// �ð����⵵: O()
//
//int N;
//int stairs[300];
//
//int D[300][3];
//
//int D2[300];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	int sum = 0;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> stairs[i];
//		sum += stairs[i];
//	}
//	
//	// N: 0,1 �� ��, �ε��� ���� ���� ������ return ��Ŵ
//	//if (N <= 1)
//	//{
//	//	cout << stairs[1];
//	//	return 0;
//	//}
//
//	//// �ʱⰪ ���ϱ�
//	//D[0][1] = stairs[0];
//	//D[0][2] = 0;
//
//	//D[1][1] = stairs[1];
//	//D[1][2] = D[0][1] + stairs[1];
//
//	//// ��ȭ�� �ݺ���
//	//for (int k = 2; k < N; k++)
//	//{
//	//	// k��° ��ܱ��� 1������
//	//	D[k][1] = max(D[k - 2][1], D[k - 2][2]) + stairs[k];
//
//	//	// k��° ��ܱ��� 2������
//	//	D[k][2] = D[k - 1][1] + stairs[k];
//	//}
//	//
//	//cout << max(D[N - 1][1], D[N - 1][2]);
//
//	// 2. 1���� �迭 DP Ǯ��
//
//	D2[0] = stairs[0];
//	D2[1] = stairs[1];
//	D2[2] = stairs[2];
//
//	if (N <= 2)
//	{
//		cout << sum;
//		return 0;
//	}
//
//	for (int k = 3; k < N; k++)
//	{
//		D2[k] = stairs[k] + min(D2[k - 2], D2[k - 3]);
//	}
//
//	// ������ ��� ��ƾ��ϹǷ�,
//	// ���� ���������� ���� ���� ��� N-1 or N-2 
//	cout << sum - min(D2[N - 2], D2[N - 3]);
//
//	return 0;
//}