//#include <iostream>
//#include <algorithm> // sort
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 15. ��
//// ���� ��ȣ	: #15665
//// ���� �̸�	: N �� M - 11
//// �˰���	: 
//// �ð����⵵: O()
//
//int N, M;
//int num[8];	
//int arr[8];
//int numCnt[10000];
//
//// 2. �񳻸�����
//void func(int k)
//{
//	if (k == M)
//	{
//		for (int i = 0; i < M; i++)
//			cout << arr[i] << " ";
//		cout << '\n';
//		return;
//	}
//	
//	for (int i = 0; i < N; i++)
//	{
//		arr[k] = num[i];
//
//		func(k + 1);
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
//	for (int i = 0; i < N; i++)
//	{
//		cin >> num[i];
//	}
//
//	sort(num, num + N);
//
//	func(0);
//
//
//	return 0;
//}