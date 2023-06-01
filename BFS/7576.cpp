//#include <iostream>
//#include <utility>
//#include <queue>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 26. 수
//// 문제 번호	: #7576 
//// 문제 이름	: 토마토
//// 알고리즘	: BFS
//// 시간복잡도: O()
//
//#define ROW first
//#define COL second
//
//int r, c;
//int tomatoes[1005][1005];
//int dist[1005][1005];
//
//const int dRow[4] = {0, 1, 0, -1};
//const int dCol[4] = {1, 0, -1, 0};
//
//queue<pair<int, int>> Q;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 행, 열 입력
//	cin >> c >> r;
//
//	// 거리 배열 -1 초기화
//	for (int i = 0; i < r; i++)
//		fill(dist[i], dist[i] + c, -1);
//
//	// 토마토 배열 입력
//	for (int row = 0; row < r; row++)
//	{
//		for (int col = 0; col < c; col++)
//		{
//			cin >> tomatoes[row][col];
//			
//			// 익은 토마토 찾기 (시작점)
//			if (tomatoes[row][col] == 1)
//			{
//				Q.push({ row, col });
//				dist[row][col] = 0;
//			}
//		}
//	}
//
//	while (!Q.empty())
//	{
//		pair<int, int> curPos = Q.front(); Q.pop();
//
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nRow = curPos.ROW + dRow[dir];
//			int nCol = curPos.COL + dCol[dir];
//
//			if (nRow < 0 || nRow >= r || nCol < 0 || nCol >= c)
//				continue;
//
//			if (tomatoes[nRow][nCol] != 0)
//				continue;
//
//			Q.push({ nRow, nCol });
//			tomatoes[nRow][nCol] = 1;
//
//			dist[nRow][nCol] = dist[curPos.ROW][curPos.COL] + 1;
//			//dist[nRow][nCol] = min(dist[nRow][nCol], dist[curPos.ROW][curPos.COL] + 1);
//		}
//	}
//
//	int maxDays = 0;
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			if (tomatoes[i][j] == -1)
//				continue;
//
//			if (dist[i][j] == -1)
//			{
//				cout << -1;
//				return 0;
//			}
//			maxDays = max(maxDays, dist[i][j]);
//		}
//	}
//
//	cout << maxDays;
//
//
//	//for (int row = 0; row < r; row++)
//	//{
//	//	for (int col = 0; col < c; col++)
//	//	{
//	//		// 토마토 찾기
//	//		if (tomatoes[row][col] != 1)
//	//			continue;
//
//	//		Q.push({ row, col });
//	//		dist[row][col] = 0;
//	//		
//	//		// 임시 토마토판 초기화
//	//		for (int i = 0; i < r; i++)
//	//			copy(&tomatoes[i][0], &tomatoes[i][c], &temp[i][0]);
//	//		//copy(&tomatoes[0][0], &tomatoes[0][0] + 1005 * 1005, &temp[0][0]);
//
//	//		while (!Q.empty())
//	//		{
//	//			pair<int, int> curPos = Q.front(); Q.pop();
//
//	//			for (int dir = 0; dir < 4; dir++)
//	//			{
//	//				int nRow = curPos.ROW + dRow[dir];
//	//				int nCol = curPos.COL + dCol[dir];
//
//	//				if (nRow < 0 || nRow >= r || nCol < 0 || nCol >= c)
//	//					continue;
//
//	//				if (temp[nRow][nCol] != 0)
//	//					continue;
//
//	//				Q.push({ nRow, nCol });
//	//				temp[nRow][nCol] = 1;
//
//	//				dist[nRow][nCol] = min(dist[nRow][nCol] ,dist[curPos.ROW][curPos.COL] + 1);
//	//			}
//	//		}
//	//	}
//	//}
//
//	//int maxDays = 0;
//	//for (int row = 0; row < r; row++)
//	//{
//	//	for (int col = 0; col < c; col++)
//	//	{
//	//		if (tomatoes[row][col] == -1)
//	//			continue;
//
//	//		maxDays = max(maxDays, dist[row][col]);
//	//	}
//	//}
//
//	//if (maxDays > r * c)
//	//	maxDays = -1;
//
//
//	return 0;
//}