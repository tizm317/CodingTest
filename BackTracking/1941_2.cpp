//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <queue>
//#include <utility>
//#include <tuple>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 20xx. xx. xx.
//// 문제 번호	: #1941 다른 풀이 
//// 문제 이름	: 
//// 알고리즘	: 
//// 시간복잡도: O()
//
//const int dx[4] = {1,0,-1,0};
//const int dy[4] = {0,1,0,-1};
//
//string students[5];
//int a[25]; // 조합에 사용할 배열
//int ans;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	for (int i = 0; i < 5; i++)
//		cin >> students[i];
//
//	// 0 - 7개 , 1 - 18개
//	fill(a + 7, a + 25, 1);
//
//	do
//	{
//		bool visit[5][5] = { 0, };
//		queue<pair<int, int>> Q;
//		int dasomCnt = 0;
//		int memberCnt = 0;
//
//		for (int r = 0; r < 5; r++)
//		{
//			for (int c = 0; c < 5; c++)
//			{
//				if (a[r * 5 + c] == 1)
//					continue;
//
//				// <- 여기서 하면 안되고! , 떨어져있는 경우도 세버리잖아..
//				//if (students[r][c] == 'S')
//				//	dasomCnt++;
//
//				//memberCnt++;
//
//				if (Q.empty())
//				{
//					visit[r][c] = true;
//					Q.push({ r,c });
//				}
//			}
//		}
//
//		while (!Q.empty())
//		{
//			int r, c;
//			tie(r, c) = Q.front(); Q.pop();
//
//			// <- 여기서 체크! 이어져있는지 확인하기 위함 
//			if (students[r][c] == 'S')
//				dasomCnt++;
//
//			memberCnt++;
//
//			for (int dir = 0; dir < 4; dir++)
//			{
//				int nr = r + dy[dir];
//				int nc = c + dx[dir];
//
//				if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5 || visit[nr][nc] == true || a[nr * 5 + nc] == 1)
//					continue;
//
//				visit[nr][nc] = true;
//
//				Q.push({ nr, nc });
//
//				/*if (students[nr][nc] == 'S')
//					dasomCnt++;*/
//
//				//memberCnt++;
//			}
//		}
//
//		ans += (memberCnt == 7 && dasomCnt >= 4);
//
//	} while (next_permutation(a, a + 25));
//
//	cout << ans;
//
//	return 0;
//}
//
///*
//YYYYY
//SYSYS
//YYYYY
//YSYYS
//YYYYY
//*/
