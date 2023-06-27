//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 06. 27. 화.
//// 문제 번호	: #13300 
//// 문제 이름	: 방 배정
//// 알고리즘	: 배열
//// 시간복잡도: O()
//
//int N, K;
//int students[2][6]; // 성별, 학년
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> K;
//	for (int i = 0; i < N; i++)
//	{
//		// 성별, 학년
//		int S, Y;
//
//		cin >> S >> Y;
//
//		students[S][Y - 1]++;
//	}
//
//	int ans = 0;
//	for (int s = 0; s < 2; s++)
//	{
//		for (int y = 0; y < 6; y++)
//		{
//			// 0명이면, 방 배정 필요 X
//			if (students[s][y] == 0)
//				continue;
//
//			if (students[s][y] % K == 0)
//			{
//				ans += (students[s][y] / K);
//			}
//			else // K로 안 나눠 떨어지면 방 1개 더 필요
//			{
//				ans += (students[s][y] / K + 1);
//			}
//
//		}
//	}
//
//	cout << ans;
//
//	return 0;
//}