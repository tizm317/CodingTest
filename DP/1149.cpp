//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 23. 화
//// 문제 번호	: #1149 
//// 문제 이름	: RGB 거리
//// 알고리즘	: DP
//// 시간복잡도: O()
//
//int N;
//int D[1000][3];
////int S[1000][3];
//
//int R[1000];
//int G[1000];
//int B[1000];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> R[i] >> G[i] >> B[i];
//
//		/*for (int j = 0; j < 3; j++)
//		{
//			cin >> S[i][j];
//		}*/
//	}
//
//	// 초기값 정하기
//	D[0][0] = R[0];
//	D[0][1] = G[0];
//	D[0][2] = B[0];
//
//	//D[0][0] = S[0][0];
//	//D[0][1] = S[0][1];
//	//D[0][2] = S[0][2];
//
//	for (int k = 1; k < N; k++)
//	{
//		D[k][0] = min(D[k - 1][1], D[k - 1][2]) + R[k];
//		D[k][1] = min(D[k - 1][0], D[k - 1][2]) + G[k];
//		D[k][2] = min(D[k - 1][0], D[k - 1][1]) + B[k];
//
//		//D[k][0] = min(D[k - 1][1], D[k - 1][2]) + S[k][0];
//		//D[k][1] = min(D[k - 1][0], D[k - 1][2]) + S[k][1];
//		//D[k][2] = min(D[k - 1][0], D[k - 1][1]) + S[k][2];
//	}
//
//	cout << *min_element(D[N - 1], D[N - 1] + 3);
//
//	/*int ans = min(D[N - 1][0], D[N - 1][1]);
//	ans = min(ans, D[N - 1][2]);
//	cout << ans;*/
//
//	return 0;
//}