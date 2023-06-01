//#include <iostream>
//#include <utility>
//#include <queue>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 26. 수
//// 문제 번호	: #4179 
//// 문제 이름	: 불!
//// 알고리즘	: 
//// 시간복잡도: O()
//
//#define ROW first
//#define COL second
//
//int r, c;
//
//int maze[1005][1005];
//int visit[1005][1005];
//
//queue<pair<int, int>> Q;
//
//const int dRow[4] = { 0, 1, 0, -1 };
//const int dCol[4] = { 1, 0, -1, 0 };
//
//pair<int, int> JPos;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> r >> c;
//
//	//for(int i = 0; i < r; i++)
//	//	fill(visit[i], visit[i] + c, -1);
//
//	for (int i = 0; i < r; i++)
//	{
//		string s;
//		cin >> s;
//		for (int j = 0; j < c; j++)
//		{
//			if (s[j] == '#' || s[j] == 'F')
//			{
//				if (s[j] == 'F')
//				{
//					// 2. 불 시작점
//					Q.push({ i, j });
//					visit[i][j] = -1;
//					//visit[i][j] = 0;
//				}
//
//				maze[i][j] = 1;
//			}
//			else
//			{
//				if (s[j] == 'J')
//				{
//					// 1. 지훈 시작점
//					JPos = { i, j };
//					//Q.push({ i, j });
//					visit[i][j] = 0;
//				}
//
//				maze[i][j] = 0;
//			}
//		}
//	}
//
//	// 지훈이 먼저 움직임
//	pair<int, int> curPos = JPos;
//
//	do
//	{
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nRow = curPos.ROW + dRow[dir];
//			int nCol = curPos.COL + dCol[dir];
//
//			// 불, 벽에 막힘
//			if (maze[nRow][nCol] == 1)
//				continue;
//
//			// 탈출
//			if (nRow < 0 || nRow == r || nCol < 0 || nCol == c)
//			{
//				// 불 빼고
//				if (maze[curPos.ROW][curPos.COL] == 1)
//					continue;
//
//				//cout << "탈출" << '\n';
//				cout << visit[curPos.ROW][curPos.COL] + 1 << '\n';
//				return 0;
//			}
//
//			// 불인 경우
//			if (maze[curPos.ROW][curPos.COL] == 1)
//			{
//				maze[nRow][nCol] = 1;
//
//				visit[nRow][nCol] = -1;
//			}
//			else // 지훈
//			{
//				// 불에 잡힌 경우
//				if (visit[curPos.ROW][curPos.COL] == -1)
//					continue;
//
//				// 지나간 곳 중복X
//				if (visit[nRow][nCol] != 0)
//					continue;
//
//				visit[nRow][nCol] = visit[curPos.ROW][curPos.COL] + 1;
//			}
//
//			Q.push({ nRow, nCol });
//		}
//
//		if (Q.empty())
//			break;
//
//		// 다음
//		curPos = Q.front(); Q.pop();
//	
//	} while (true);
//	
//	cout << "IMPOSSIBLE";
//
//
//
//
//	// 2. 다른 풀이 -> 메모리 초과
//	// 불에 대한 BFS + 지훈이에 대한 BFS 따로 해서 시간 비교 후 가능한지 여부 체크
//	
//	// 불에 대한 BFS
//	/*while (true)
//	{
//		pair<int, int> curPos = Q.front(); Q.pop();
//
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nRow = curPos.ROW + dRow[dir];
//			int nCol = curPos.COL + dCol[dir];
//
//			if (maze[nRow][nCol] == 1 || visit[nRow][nCol] != 0)
//				continue;
//
//			if (nRow < 0 || nRow >= r || nCol < 0 || nCol >= c)
//				continue;
//
//			visit[nRow][nCol] = visit[curPos.ROW][curPos.COL] + 1;
//			Q.push({ nRow, nCol });
//		}
//
//		if (Q.empty())
//		{
//			Q.push(JPos);
//			visit[JPos.ROW][JPos.COL] = 0;
//
//			while (!Q.empty())
//			{
//				pair<int, int> curPos = Q.front(); Q.pop();
//
//				for (int dir = 0; dir < 4; dir++)
//				{
//					int nRow = curPos.ROW + dRow[dir];
//					int nCol = curPos.COL + dCol[dir];
//
//					if (maze[nRow][nCol] == 1)
//						continue;
//
//					if (nRow < 0 || nRow >= r || nCol < 0 || nCol >= c)
//					{
//						cout << visit[curPos.ROW][curPos.COL] + 1 << '\n';
//						return 0;
//					}
//
//					if (visit[nRow][nCol] == -1 || visit[nRow][nCol] >= visit[curPos.ROW][curPos.COL] + 1)
//					{
//						visit[nRow][nCol] = visit[curPos.ROW][curPos.COL] + 1;
//						Q.push({ nRow, nCol });
//					}
//				}
//			}
//
//		}
//	}*/
//
//	
//
//	return 0;
//}