//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 06. 08. 목.
//// 문제 번호	: #14501 
//// 문제 이름	: 퇴사
//// 알고리즘	: DP
//// 시간복잡도: O()
//
//int N;
//int T[20];	// 상담 소요 기간
//int P[20];	// 페이
//int D[20]; 
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//		cin >> T[i] >> P[i];
//
//	
//	if (1 + T[1] <= N + 1)
//		D[1] = P[1];
//	else // N 이 1일 때, T[1] 이 1보다 크면, 불가능하니까 초기화 0으로 해야함
//		D[1] = 0;
//
//	for (int i = 2; i <= N; i++)
//	{
//		// 기간 초과되는 거 pass
//		if (i + T[i] > N + 1)
//			continue;
//
//		// 최대 페이 구하기
//		// 0~i-1 까지 최대 페이 + i번째 페이
//		int maxPay = 0;
//		for (int j = i - 1; j >= 0; j--)
//		{
//			// 기간 초과되는 거 pass
//			if (j + T[j] > i)
//				continue;
//
//			maxPay = max(maxPay, D[j]);
//		}
//		D[i] = maxPay + P[i];
//	}
//
//	cout << *max_element(D, D + N + 1);
//
//	return 0;
//}