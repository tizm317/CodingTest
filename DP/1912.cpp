//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 06. 08. 목
//// 문제 번호	: #1912 
//// 문제 이름	: 연속합
//// 알고리즘	: DP
//// 시간복잡도: O()
//
//int N;
//int num[100'005];
//int D[100'005];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> num[i];
//	}
//
//	// D[i] : 뒤에서부터 i번째 원소까지 연속합 중 최댓값
//	// D[i] = D[i+1] + S[i]
//	
//	// 맨 뒤 원소 초기화
//	D[N - 1] = num[N - 1]; // N >= 1 보장
//	
//	// 뒤에서부터 순회
//	for (int i = N - 2; i >= 0; i--)
//	{
//		// 연속합 과 현재값 비교 후 더 큰 값 저장
//		D[i] = max(D[i + 1] + num[i], num[i]);
//	}
//
//	cout << *max_element(D, D + N);
//
//	//----------------------------------
//	// 아래 방식은 O(N^2)
//	// 100'000 제곱 으로 시간초과..
//
//	//fill(D, D + 100'005, -100'005);
//
//	//D[0] = num[0];
//	//for (int i = 0; i < N; i++)
//	//{
//	//	if (i != 0)
//	//		D[i] = max(num[i], D[i - 1]);
//
//	//	int sum = num[i];
//	//	for (int j = i + 1; j < N + 1; j++)
//	//	{
//	//		sum += num[j];
//	//		D[i] = max(D[i], sum);
//	//	}
//	//}
//
//	//if(N >= 1)
//	//	cout << D[N - 1];
//
//
//	return 0;
//}