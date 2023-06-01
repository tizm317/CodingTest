////#include <iostream>
////using namespace std;
////
////// 백준 문제 풀이
////// 날짜		: 2023. 05. 15. 월
////// 문제 번호	: #1182 
////// 문제 이름	: 부분수열의 합
////// 알고리즘	: 
////// 시간복잡도: O()
////
////int	N, S;
////int arr[20];
////bool isUsed[20];
////int cnt;
////int sum;
////
////void func(int col)
////{
////	// 이 때 return 시키면 2개만 고르는 셈
////	// 5 0
////	// 1 -1 0 4 5 이런 경우
////	// (1, -1) 이면 sum 이 0 만족해서 return 해버리는데
////	// (1, -1, 0) 도 가능하다는 것을 놓침.
////	// col 이 N-1에 도달할 때 return 하는 것이 맞다.
////	if (sum == S)
////	{
////		cnt++;
////	}
////
////	if (col >= N)
////	{
////		return;
////	}
////
////	for (int i = col; i < N; i++)
////	{
////		if (isUsed[i] == 1)
////			continue;
////
////		sum += arr[i];
////		isUsed[i] = true;
////
////		func(i + 1);
////
////		sum -= arr[i];
////		isUsed[i] = false;
////	}
////}
////
////int main()
////{
////	ios_base::sync_with_stdio(false);
////	cin.tie(NULL);
////
////	cin >> N >> S;
////	for (int i = 0; i < N; i++)
////		cin >> arr[i];
////
////	for (int i = 0; i < N; i++)
////	{
////		sum = arr[i];
////
////		isUsed[i] = 1;
////		
////		func(i+1);
////		
////		isUsed[i] = 0;
////	}
////
////	cout << cnt;
////	
////	return 0;
////}
//
//
////#include <iostream>
////using namespace std;
////
////int N, S;
////int arr[20]; // 수열 배열
////bool isused[20];
////int totalCnt; // 부분 수열 갯수
////int sum;
////
////void func(int col)
////{
////	if (col == N)
////	{
////		return;
////	}
////
////	for (int i = col; i < N; i++)
////	{
////		if (isused[i] == 1)
////			continue;
////
////		isused[i] = 1;
////		sum += arr[i];
////		
////		if (sum == S)
////			totalCnt++;
////		
////		func(col + 1);
////
////		isused[i] = 0;
////		sum -= arr[i];
////	}
////
////}
////
////int main()
////{
////	cin >> N >> S;
////	for (int i = 0; i < N; i++)
////		cin >> arr[i];
////
////	// 첫 시작 원소 선택
////	for (int i = 0; i < N; i++)
////	{
////		// sum 초기화
////		sum = arr[i];
////
////		isused[i] = 1;
////
////		func(i + 1);
////		
////		isused[i] = 0;
////	}
////
////	cout << totalCnt;
////
////	return 0;
////}
//
//
//#include <iostream>
//using namespace std;
//
//int N, S;
//int arr[20];
//int cnt;
//int isused[20];
//
//void func(int i)
//{
//	if (i == N)
//	{
//		int sum = 0;
//		bool empty = true;
//		for (int idx = 0; idx < N; idx++)
//		{
//			if (isused[idx] == 1)
//			{
//				sum += arr[idx];
//				empty = false;
//			}
//
//		}
//
//		// 공집합 제외
//		if (empty && S == 0)
//			return;
//
//		if (sum == S)
//			cnt++;
//
//		return;
//	}
//
//	// 사용할지 말지
//	for (int j = 0; j < 2; j++)
//	{
//		isused[i] = j;
//		func(i + 1);
//	}
//	
//}
//
//// 현재 위치와 , 현재까지 합
//void func2(int cur, int tot)
//{
//	if (cur == N)
//	{
//		if (tot == S)
//		{
//			cnt++;
//		}
//
//		return;
//	}
//
//	// 현재꺼 더하거나,
//	func2(cur + 1, tot);
//
//	// 안 더하거나
//	func2(cur + 1, tot + arr[cur]);
//}
//
//int main()
//{
//	cin >> N >> S;
//	for (int i = 0; i < N; i++)
//		cin >> arr[i];
//
//	//func(0);
//	//cout << cnt;
//
//	func2(0, 0);
//
//	if (S == 0) // S가 0이면 공집합 제외
//		cnt--;
//	
//	cout << cnt;
//
//
//
//	return 0;
//}
