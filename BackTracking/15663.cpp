//#include <iostream>
//#include <algorithm> // sort
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 15. ��
//// ���� ��ȣ	: #15663 , #15664, #15665, #15666
//// ���� �̸�	: N �� M - 9, 10, 11, 12
//// �˰���	: 
//// �ð����⵵: O()
//
//int N, M;
//int num[10'000];	// idx���� cnt ���� �迭
//int arr[8];
//bool isused[8];
//
////void func(int k)
//
//// 2. �񳻸�����
//void func(int k, int st)
//{
//	if (k == M)
//	{
//		for (int i = 0; i < M; i++)
//			cout << arr[i] << " ";
//		cout << '\n';
//		return;
//	}
//
//	// ������ 0�� �ƴ� i ã��
//	for (int i = st; i < 10000; i++)
//	{
//		if (num[i] == 0)
//			continue;
//
//		// ���� ���̱�
//		//num[i]--;
//
//		// ����
//		arr[k] = i;
//
//		//func(k + 1);
//		func(k + 1, i);
//
//		//num[i]++;
//	}
//
//	/*
//	for (int i = 0; i < N; i++)
//	{
//		if (isused[i] == 1)
//			continue;
//
//		isused[i] = 1;
//	
//		arr[k] = num[i];
//
//		func(k + 1);
//
//		isused[i] = 0;
//	}*/
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
//		int x;
//		cin >> x;
//
//		num[x]++;
//	}
//
//	//sort(num, num + N);
//
//	//func(0);
//	func(0, 0);
//
//
//	return 0;
//}