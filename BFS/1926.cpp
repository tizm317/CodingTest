//#include <iostream>
//#include <utility>
//#include <queue>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 26 수
//// 문제 번호	: #1926 
//// 문제 이름	: 그림
//// 알고리즘	: BFS
//// 시간복잡도: O(rc) : 칸 갯수만큼
//
//#define ROW first
//#define COL second
//
//int r, c; 
//int board[501][501];
//int visit[501][501];
//
//// 그림 개수, 최대넓이
//int artCnt, maxArtSize;
//
//queue<pair<int, int>> Q;
//
//// 우하좌상
//const int dRow[4] = {0, 1, 0, -1};
//const int dCol[4] = {1, 0, -1, 0};
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 행, 열 크기 입력
//	cin >> r >> c;
//
//	// 그림 입력
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			cin >> board[i][j];
//		}
//	}
//
//	// 1. 시작 위치 설정 2중 for문
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			// 방문한 적 있거나, 그림이 아니면 continue
//			if (visit[i][j] == 1 || board[i][j] == 0)
//				continue;
//
//			// 그림인 경우, 방문 체크 및 그림 개수 증가, 큐에 푸시
//			visit[i][j] = 1;
//			artCnt++;
//			int curArtSize = 1; // 그림 크기 초기화
//			Q.push({ i, j });
//
//			// 2. 이어지는 그림 체크하는 반복문
//			while (!Q.empty())
//			{
//				pair<int, int> curPos = Q.front(); Q.pop();
//
//				for (int dir = 0; dir < 4; dir++)
//				{
//					int nRow = curPos.ROW + dRow[dir];
//					int nCol = curPos.COL + dCol[dir];
//
//					// 범위 체크
//					if (nRow < 0 || nRow >= r || nCol < 0 || nCol >= c)
//						continue;
//
//					// 방문 여부 체크
//					if (visit[nRow][nCol] == 1)
//						continue;
//					else
//						visit[nRow][nCol] = 1;
//
//					// 그림 체크
//					if (board[nRow][nCol] == 1)
//					{
//						Q.push({ nRow, nCol });
//						
//						// 그림 크기 증가
//						curArtSize++;
//					}
//				}
//			}
//
//			// 그림 maxSize 확인
//			maxArtSize = (maxArtSize > curArtSize) ? maxArtSize : curArtSize;
//		}
//	}
//
//	cout << artCnt << '\n' << maxArtSize;
//
//	return 0;
//}