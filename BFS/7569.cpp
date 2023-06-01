//#include <iostream>
//#include <tuple>
//#include <queue>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 28. 금
//// 문제 번호	: #7569 
//// 문제 이름	: 토마토(3차원)
//// 알고리즘	: BFS
//// 시간복잡도: O()
//
//int COL, ROW, HEIGHT;
//
//int tomato[105][105][105];
//int dist[105][105][105];
//
//queue<tuple<int, int, int>> Q;
//
//// 우하좌상, 위, 아래
//const int dHeight[6] = { 0, 0, 0, 0, 1, -1 };
//const int dRow[6]	 = { 0, 1, 0, -1, 0, 0 };
//const int dCol[6]	 = { 1, 0, -1, 0, 0, 0};
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 가로, 세로, 높이
//	cin >> COL >> ROW >> HEIGHT;
//
//	for (int h = 0; h < HEIGHT; h++)
//	{
//		for (int r = 0; r < ROW; r++)
//		{
//			for (int c = 0; c < COL; c++)
//			{
//				cin >> tomato[h][r][c];
//
//				// 거리 초기화
//				dist[h][r][c] = -1;
//
//				// 익은 토마토 찾기
//				if (tomato[h][r][c] == 1)
//				{
//					Q.push({ h, r, c });
//					dist[h][r][c]++;
//				}
//			}
//		}
//	}
//
//	while (!Q.empty())
//	{
//		tuple<int, int, int> curPos = Q.front(); Q.pop();
//
//		for (int dir = 0; dir < 6; dir++)
//		{
//			// 다음 위치
//			int nHeight = get<0>(curPos) + dHeight[dir];
//			int nRow = get<1>(curPos) + dRow[dir];
//			int nCol = get<2>(curPos) + dCol[dir];
//
//			// 1. 범위 체크
//			if (nHeight < 0 || nHeight >= HEIGHT || nRow < 0 || nRow >= ROW || nCol < 0 || nCol >= COL)
//				continue;
//
//			// 2. 토마토 체크 (익지 않은 토마토)
//			if (tomato[nHeight][nRow][nCol] != 0)
//				continue;
//
//
//			// 3. 방문 체크
//			if (dist[nHeight][nRow][nCol] == -1)
//			{
//				// 처음인 경우
//				dist[nHeight][nRow][nCol] = dist[get<0>(curPos)][get<1>(curPos)][get<2>(curPos)] + 1;
//			}
//			else
//			{
//				// 방문한 적 있는 경우, 최소값으로 변경
//				dist[nHeight][nRow][nCol] = (dist[nHeight][nRow][nCol] < dist[get<0>(curPos)][get<1>(curPos)][get<2>(curPos)] + 1) ? dist[nHeight][nRow][nCol] : dist[get<0>(curPos)][get<1>(curPos)][get<2>(curPos)] + 1;
//			}
//
//			// 푸시
//			Q.push({ nHeight, nRow, nCol });
//		
//			// 토마토 익음
//			tomato[nHeight][nRow][nCol] = 1;
//		}
//	}
//
//	int days = -1;
//	for (int h = 0; h < HEIGHT; h++)
//	{
//		for (int r = 0; r < ROW; r++)
//		{
//			for (int c = 0; c < COL; c++)
//			{
//				// 토마토 없는 곳 패스
//				if (tomato[h][r][c] == -1)
//					continue;
//
//				// 갈 수 없는 곳 존재
//				if (tomato[h][r][c] == 0)
//				{
//					cout << -1;
//					return 0;
//				}
//				
//				days = max(days, dist[h][r][c]);
//			}
//		}
//	}
//
//	cout << days;
//
//	return 0;
//}