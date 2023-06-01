//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 22. 월
//// 문제 번호	: #9095 
//// 문제 이름	: 1,2,3 더하기
//// 알고리즘	: DP
//// 시간복잡도: O()
//
//int T;
//int D[12];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 초기값 정하기
//	D[1] = 1; // 1
//	D[2] = 2; // 1+1 , 2
//	D[3] = 4; // 1+1+1, 1+2, 2+1, 3
//
//	// 점화식 반복문
//	for (int k = 4; k < 11; k++)
//	{
//		D[k] = D[k - 1] + D[k - 2] + D[k - 3];
//	}
//
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		int x;
//		cin >> x;
//
//		cout << D[x] << '\n';
//	}
//
//	return 0;
//}