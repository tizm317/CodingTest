//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 23. 화
//// 문제 번호	: #11726 
//// 문제 이름	: 2 x n 타일링
//// 알고리즘	: DP
//// 시간복잡도: O()
//
//int D[1005];
//int N;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	// 초기값 정하기
//	D[1] = 1;
//	D[2] = 2;
//
//	// 점화식 반복문
//	for (int k = 4; k <= N; k++)
//		D[k] = (D[k - 1] + D[k - 2]) % 10007;	// int overflow
//
//	cout << D[N];
//
//
//	return 0;
//}