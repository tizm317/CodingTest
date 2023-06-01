//#include <iostream>
//#include <algorithm> // sort
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 15. 월
//// 문제 번호	: #15665
//// 문제 이름	: N 과 M - 11
//// 알고리즘	: 
//// 시간복잡도: O()
//
//int N, M;
//int num[8];	
//int arr[8];
//int numCnt[10000];
//
//// 2. 비내림차순
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