//#include <iostream>
//#include <algorithm> // sort
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 15. 월
//// 문제 번호	: #15663 , #15664, #15665, #15666
//// 문제 이름	: N 과 M - 9, 10, 11, 12
//// 알고리즘	: 
//// 시간복잡도: O()
//
//int N, M;
//int num[10'000];	// idx값의 cnt 저장 배열
//int arr[8];
//bool isused[8];
//
////void func(int k)
//
//// 2. 비내림차순
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
//	// 개수가 0이 아닌 i 찾기
//	for (int i = st; i < 10000; i++)
//	{
//		if (num[i] == 0)
//			continue;
//
//		// 개수 줄이기
//		//num[i]--;
//
//		// 수열
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