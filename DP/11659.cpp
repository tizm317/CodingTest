//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 23. ȭ
//// ���� ��ȣ	: #11659
//// ���� �̸�	: ���� �� ���ϱ� 4
//// �˰���	: 
//// �ð����⵵: O()
//
//int N, M;
//int arr[100005];
//int D[100005];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++)
//		cin >> arr[i];
//
//	D[1] = arr[1];
//	for(int k = 2; k <= N; k++)
//		D[k] = D[k - 1] + arr[k];
//
//	for (int j = 0; j < M; j++)
//	{
//		int st, end;
//		cin >> st >> end;
//
//		cout << D[end] - D[st - 1] << '\n';
//	}
//
//	return 0;
//}