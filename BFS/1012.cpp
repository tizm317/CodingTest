//#include <iostream>
//#include <queue>
//#include <utility>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 20xx. xx. xx.
//// 문제 번호	: #00000 
//// 문제 이름	: 
//// 알고리즘	: 
//// 시간복잡도: O()
//
//#define ROW first
//#define COL second
//
//int T, Row, Col, Count;
//int board[55][55] = { 0, }; // 배추밭
//int visit[55][55] = { 0, };
//
//queue<pair<int, int>> Q;
//
//
//const int dRow[4] = { 0, 1, 0, -1 };
//const int dCol[4] = { 1, 0, -1, 0 };
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 테스트 케이스 여러개 일 때, 전역 변수 초기화!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		// 행, 열, 배추 개수
//		cin >> Col >> Row >> Count; // 가로, 세로 거꾸로 받았었음
//
//		// 테케마다 밭, 방문 여부 초기화
//		for (int r = 0; r < Row; r++)
//		{
//			fill(board[r], board[r] + 55, 0);
//			fill(visit[r], visit[r] + 55, 0);
//		}
//
//		// 배추
//		for (int j = 0; j < Count; j++)
//		{
//			int r, c;
//			cin >> c >> r; // 거꾸로 받았네
//			board[r][c] = 1;
//		}
//
//		int wormCnt = 0;
//
//		// 2중 for문으로 배추 찾기
//		for (int r = 0; r < Row; r++)
//		{
//			for (int c = 0; c < Col; c++)
//			{
//				// 배추 찾기
//				if (board[r][c] == 0)
//					continue;
//
//				// 방문 여부 확인
//				if (visit[r][c] == 1)
//					continue;
//
//				// 아직 방문하지 않은 배추 구역 확인
//				Q.push({ r, c });
//				visit[r][c] = 1;
//
//				// 구역 1개 당 배추벌레 갯수 + 1
//				wormCnt++;
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
//						// 범위 체크
//						if (nRow < 0 || nRow >= Row || nCol < 0 || nCol >= Col)
//							continue;
//
//						// 배추인지 체크
//						if (board[nRow][nCol] == 0)
//							continue;
//
//						// 방문 체크
//						if (visit[nRow][nCol] == 1)
//							continue;
//
//						visit[nRow][nCol] = 1;
//						Q.push({ nRow, nCol });
//					}
//				}
//			}
//		}
//
//		cout << wormCnt << '\n';
//	}
//
//	// 이건 없어도 맞게 처리해주네
//	// 테케 0일 때,
//	//if(T == 0)
//	//	cout << 0;
//
//	return 0;
//}