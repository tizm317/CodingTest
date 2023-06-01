//#include <iostream>
//#include <queue>
//#include <utility>	// pair
//
//using namespace std;
//
//#define ROW first
//#define COL second
//
//const int board[502][502] =
//{ 
//	{1,1,1,0,1,0,0,0,0,0},
//	{1,0,0,0,1,0,0,0,0,0},
//	{1,1,1,0,1,0,0,0,0,0},
//	{1,1,0,0,1,0,0,0,0,0},
//	{0,1,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0} 
//}; // 1이 파란 칸, 0이 빨간 칸에 대응
//
//// 행, 열 크기
//const int r = 7, c = 10;
//
//int visit[502][502]; // 1 : 방문 여부 체크
//
//// 시작지점 좌표
//const pair<int, int> start = { 0, 0 };
//
//// 큐
//queue<pair<int, int>> Q;
//
//// 우하좌상
//int dRow[4] = {0, 1, 0, -1};
//int dCol[4] = {1, 0, -1, 0};
//
//int main()
//{
//	// 1. 큐에 시작 좌표 넣음
//	Q.push(start);
//
//	// 2. 시작 좌표 방문 표시
//	visit[start.ROW][start.COL] = 1;
//
//	// 큐가 빌 때 까지 반복
//	while (!Q.empty())
//	{
//		// 현재 좌표
//		pair<int, int> curPos = Q.front(); Q.pop();
//
//		// 출력
//		cout << "(" << curPos.ROW << ", " << curPos.COL << ") ";
//
//		// 다음 좌표
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nRow = curPos.ROW + dRow[dir];
//			int nCol = curPos.COL + dCol[dir];
//
//			// 이동 가능한 좌표(범위 내)인지 확인
//			if (nRow < 0 || nRow >= r || nCol < 0 || nCol >= c)
//				continue;
//
//			// 방문한 적 있는지 확인
//			// 있으면 continue
//			if (visit[nRow][nCol] == 1)
//				continue;
//			else // 없으면 방문 표시
//				visit[nRow][nCol] = 1;
//
//			// board 가 파란칸(1) 인지 확인 후,
//			// 큐에 넣기
//			if(board[nRow][nCol] == 1)
//				Q.push({ nRow, nCol });
//		}
//		
//	}
//
//	return 0;
//}
