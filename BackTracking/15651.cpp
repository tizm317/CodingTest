//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 15. ��
//// ���� ��ȣ	: #15651, #15652
//// ���� �̸�	: N�� M 3,4
//// �˰���	: 
//// �ð����⵵: O()
//
//int N, M;
//int arr[9];
//
//void func(int cnt)
//{
//	if (cnt == M)
//	{
//		for (int i = 0; i < M; i++)
//			cout << arr[i] << " ";
//		cout << '\n';
//
//		return;
//	}
//
//	// 15651. N�� M 3 - �ߺ� ��� -> isused �迭 �ʿ� X
//	// 15652. N�� M 4 - �񳻸����� ���� �߰�
//	int start = 1;
//	if (cnt != 0) start = arr[cnt - 1];
//
//	for (int i = start; i <= N; i++)
//	{
//		arr[cnt] = i;
//
//		func(cnt + 1);
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//
//	func(0);
//
//	return 0;
//}