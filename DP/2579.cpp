//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 23. 화
//// 문제 번호	: #2579
//// 문제 이름	: 계단 오르기
//// 알고리즘	: DP
//// 시간복잡도: O()
//
//int N;
//int stairs[300];
//
//int D[300][3];
//
//int D2[300];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	int sum = 0;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> stairs[i];
//		sum += stairs[i];
//	}
//	
//	// N: 0,1 일 때, 인덱스 접근 문제 때문에 return 시킴
//	//if (N <= 1)
//	//{
//	//	cout << stairs[1];
//	//	return 0;
//	//}
//
//	//// 초기값 정하기
//	//D[0][1] = stairs[0];
//	//D[0][2] = 0;
//
//	//D[1][1] = stairs[1];
//	//D[1][2] = D[0][1] + stairs[1];
//
//	//// 점화식 반복문
//	//for (int k = 2; k < N; k++)
//	//{
//	//	// k번째 계단까지 1번연속
//	//	D[k][1] = max(D[k - 2][1], D[k - 2][2]) + stairs[k];
//
//	//	// k번째 계단까지 2번연속
//	//	D[k][2] = D[k - 1][1] + stairs[k];
//	//}
//	//
//	//cout << max(D[N - 1][1], D[N - 1][2]);
//
//	// 2. 1차원 배열 DP 풀이
//
//	D2[0] = stairs[0];
//	D2[1] = stairs[1];
//	D2[2] = stairs[2];
//
//	if (N <= 2)
//	{
//		cout << sum;
//		return 0;
//	}
//
//	for (int k = 3; k < N; k++)
//	{
//		D2[k] = stairs[k] + min(D2[k - 2], D2[k - 3]);
//	}
//
//	// 마지막 계단 밟아야하므로,
//	// 가장 마지막으로 밟지 않을 계단 N-1 or N-2 
//	cout << sum - min(D2[N - 2], D2[N - 3]);
//
//	return 0;
//}