//#include <iostream>
//#include <utility>
//#include <queue>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 04. 목
//// 문제 번호	: #2573 
//// 문제 이름	: 빙산
//// 알고리즘	: BFS
//// 시간복잡도: O()
//
//#define ROW first
//#define COL second
//
//int N, M;
//int iceberg[305][305];
////int visit[305][305];
//int year;
//
//// 북동남서
//const int dRow[4] = { -1, 0, 1, 0 };
//const int dCol[4] = { 0, 1, 0, -1 };
//
//queue<pair<int, int>> Q;
//
//bool isMelting = false;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cin >> iceberg[i][j];
//		}
//	}
//
//	int iceCnt = 0;
//	while (true)
//	{
//		iceCnt = 0;
//		int visit[305][305] = { 0, };
//		isMelting = false;
//
//		// 빙산 시작점 찾기
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				// 바닷물 (0) 패스
//				if (iceberg[i][j] == 0)
//					continue;
//
//				if (visit[i][j] == 1)
//					continue;
//
//				isMelting = true;
//
//				// 시작 지점
//				Q.push({ i, j });
//				visit[i][j] = 1;
//				iceCnt++;
//
//				while (!Q.empty())
//				{
//					// 현재 위치
//					pair<int, int> curPos = Q.front(); Q.pop();
//
//					for (int dir = 0; dir < 4; dir++)
//					{
//						// 다음 위치
//						int nRow = curPos.ROW + dRow[dir];
//						int nCOL = curPos.COL + dCol[dir];
//
//						if (visit[nRow][nCOL] == 1)
//							continue;
//
//						// 바닷물이면
//						if (iceberg[nRow][nCOL] == 0)
//						{
//							// 1 감소 (최소 0)
//							iceberg[curPos.ROW][curPos.COL] = max(0, iceberg[curPos.ROW][curPos.COL] - 1);
//						}
//						else // 빙산이면
//						{
//							Q.push({ nRow, nCOL });
//							visit[nRow][nCOL] = 1;
//						}
//					}
//				}
//			}
//		}
//
//		// 다 녹은 경우
//		if (isMelting == false && iceCnt < 2)
//		{
//			year = 0;
//			break;
//		}
//
//		if (iceCnt >= 2)
//			break;
//
//		year++;
//	}
//	
//	cout << year << '\n';
//
//
//	return 0;
//}