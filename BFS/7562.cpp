//#include <iostream>
//#include <utility>
//#include <queue>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 28. 금
//// 문제 번호	: #7562 
//// 문제 이름	: 나이트의 이동
//// 알고리즘	: BFS
//// 시간복잡도: O()
//
//#define ROW first
//#define COL second
//
//int T, l;
//
//int board[305][305];
//int dist[305][305];
//
//// 나이트 이동 경우의 수
//const int dRow[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
//const int dCol[8] = {1, 2, 2, 1, -1, -2, -2, -1};
//
//queue<pair<int, int>> Q;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 테케
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		// 체스판 크기 l * l
//		cin >> l;
//
//		// 체스판, 거리 초기화
//		for (int j = 0; j < l; j++)
//		{
//			fill(board[j], board[j] + l, 0);
//			fill(dist[j], dist[j] + l, -1);
//		}
//
//		// 시작 지점
//		int r, c;
//		cin >> r >> c;
//		Q.push({ r, c });
//
//		board[r][c] = 1;
//		dist[r][c] = 0;
//
//		// 도착 지점
//		int rTarget, cTarget;
//		cin >> rTarget >> cTarget;
//		board[rTarget][cTarget] = 2;
//
//		if (board[r][c] == 2)
//		{
//			// 바로 도착
//			cout << 0 << '\n';
//			continue;
//		}
//
//		while (!Q.empty())
//		{
//			pair<int, int> curPos = Q.front(); Q.pop();
//
//			for (int dir = 0; dir < 8; dir++)
//			{
//				int nRow = curPos.ROW + dRow[dir];
//				int nCol = curPos.COL + dCol[dir];
//
//				// 범위 체크
//				if (nRow < 0 || nRow >= l || nCol < 0 || nCol >= l)
//					continue;
//
//				if (dist[nRow][nCol] != -1)
//					continue;
//
//				dist[nRow][nCol] = dist[curPos.ROW][curPos.COL] + 1;
//				Q.push({ nRow, nCol });
//
//				if (board[nRow][nCol] == 2)
//				{
//					cout << dist[nRow][nCol] << '\n';
//				}
//			}
//		}
//	}
//
//
//	return 0;
//}