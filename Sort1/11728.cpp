//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 16. 화
//// 문제 번호	: #11728 
//// 문제 이름	: 배열 합치기
//// 알고리즘	: 
//// 시간복잡도: O()
//
//int M, N;
//
//// 정렬된 두 배열
//int A[1'000'000];
//int B[1'000'000];
//int resultArr[1'000'000];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> M >> N;
//	for (int i = 0; i < M; i++)
//		cin >> A[i];
//
//	for (int i = 0; i < N; i++)
//		cin >> B[i];
//
//	int aPos = 0;
//	int bPos = 0;
//	int cnt = 0;
//
//	// aPos, bPos 둘 중 하나가 M, N 에 도달할 때까지
//	while (aPos < M && bPos < N)
//	{
//		if (A[aPos] <= B[bPos])
//		{
//			resultArr[cnt++] = A[aPos++];
//		}
//		else
//		{
//			resultArr[cnt++] = B[bPos++];
//		}
//	}
//
//	// 남은 것들
//	for (; aPos < M; aPos++)
//	{
//		resultArr[cnt++] = A[aPos];
//	}
//
//	for (; bPos < N; bPos++)
//	{
//		resultArr[cnt++] = B[bPos];
//	}
//
//	// 정렬된 배열 출력
//	for (int i = 0; i < cnt; i++)
//	{
//		cout << resultArr[i] << " ";
//	}
//
//	return 0;
//}