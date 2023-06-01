//#include <iostream>
//#include <utility>
//#include <queue>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 28. 금
//// 문제 번호	: #10026 
//// 문제 이름	: 적록색약
//// 알고리즘	: BFS
//// 시간복잡도: O()
//
//#define ROW first
//#define COL second
//
//int N;
//
//char board[105][105];
//int visit[105][105];
//
//queue<pair<int, int>> Q;
//
//const int dRow[4] = { 0, 1, 0, -1 };
//const int dCol[4] = { 1, 0, -1, 0 };
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	int M;
//	for (int i = 0; i < N; i++)
//	{
//		string s;
//		cin >> s;
//
//		M = 0;
//		for (char c : s)
//		{
//			board[i][M++] = c;
//		}
//	}
//
//	//
//
//	for (int k = 0; k < 2; k++)
//	{
//		int count = 0;
//
//		for (int l = 0; l < N; l++)
//			fill(visit[l], visit[l] + N, 0);
//
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				if (visit[i][j] == 1)
//					continue;
//
//				Q.push({ i, j });
//				visit[i][j] = 1;
//
//				count++;
//
//				while (!Q.empty())
//				{
//					pair<int, int> curPos = Q.front(); Q.pop();
//
//					for (int dir = 0; dir < 4; dir++)
//					{
//						int nRow = curPos.ROW + dRow[dir];
//						int nCol = curPos.COL + dCol[dir];
//
//						if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= M)
//							continue;
//
//						if (visit[nRow][nCol] == 1)
//							continue;
//
//						if (k == 0)
//						{
//							if (board[nRow][nCol] != board[curPos.ROW][curPos.COL])
//								continue;
//
//							visit[nRow][nCol] = 1;
//							Q.push({ nRow, nCol });
//						}
//						else
//						{
//							if (board[nRow][nCol] == 'R')
//								board[nRow][nCol] = 'G';
//
//							if (board[curPos.ROW][curPos.COL] == 'R')
//								board[curPos.ROW][curPos.COL] = 'G';
//
//							if (board[nRow][nCol] != board[curPos.ROW][curPos.COL])
//								continue;
//
//							visit[nRow][nCol] = 1;
//							Q.push({ nRow, nCol });
//						}
//					}
//				}
//			}
//		}
//
//		cout << count << " ";
//	}
//
//
//	return 0;
//}