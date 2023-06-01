//#include <iostream>
//#include <tuple>
//#include <queue>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 09. 화
//// 문제 번호	: #1600 
//// 문제 이름	: 말이 되고픈 원숭이
//// 알고리즘	: 
//// 시간복잡도: O()
//
//
//int K, W, H, moveCnt;
//int board[205][205];
//int visit[205][205];
//int horseMove[205][205]; // 
//
//// 상하좌우(4가지) -> 말 이동(8가지)
//const int dRow[12] = {-1, 0, 1, 0, -2, -1, 1, 2, 2, 1, -1, -2};
//const int dCol[12] = {0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1};
//
//// (row, col, horseMove 말 이동 횟수)
//queue<tuple<int, int, int>> Q;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	
//	cin >> K >> W >> H;
//
//	// (H, W) 보드판 입력
//	for (int r = 0; r < H; r++)
//	{
//		for (int c = 0; c < W; c++)
//		{
//			cin >> board[r][c];
//		}
//	}
//
//	// 시작점 : (0,0)
//	Q.push({ 0,0,0 });
//	visit[0][0] = 1;
//	horseMove[0][0] = 0;
//
//	while (!Q.empty())
//	{
//		// 현재 위치 + horseMove 횟수
//		tuple<int, int, int> curPos = Q.front(); Q.pop();
//
//		int row = get<0>(curPos);
//		int col = get<1>(curPos);
//		int horseMoveCnt = get<2>(curPos);
//		//cout << "(" << row << ", " << col << ", " << horseMoveCnt << ")" << '\n';
//
//		// 도착 여부 체크
//		if (get<0>(curPos) == H - 1 && get<1>(curPos) == W - 1)
//		{
//			//cout << "도착" << '\n';
//			//for (int r = 0; r < H; r++)
//			//{
//			//	for (int c = 0; c < W; c++)
//			//	{
//			//		cout << visit[r][c] << " ";
//			//	}
//			//	cout << '\n';
//			//}
//
//			cout << visit[H - 1][W - 1] - 1 << '\n';
//			return 0;
//		}
//
//		for (int dir = 0; dir < 12; dir++)
//		{
//			// horseMove 체크
//			// K번 이상이면 문제 있는 거
//			//if (get<2>(curPos) > K)
//			//{
//			//	cout << "Something Wrong" << '\n';
//			//	break;
//			//}
//
//			//  K번이면 continue (상하좌우 이동만 가능)
//			if (dir > 3 && get<2>(curPos) == K)
//				break;
//
//			// 다음 위치
//			int nRow = get<0>(curPos) + dRow[dir];
//			int nCol = get<1>(curPos) + dCol[dir];
//
//			// 다음 horseMove 횟수
//			int nHorseMove;
//			if (dir > 3)
//			{
//				nHorseMove = get<2>(curPos) + 1;
//			}
//			else
//			{
//				nHorseMove = get<2>(curPos);
//			}
//
//			// 1. 범위 체크
//			if (nRow < 0 || nRow >= H || nCol < 0 || nCol >= W)
//				continue;
//
//			// 2. 벽 체크
//			if (board[nRow][nCol] == 1)
//				continue;
//
//			// 3. 방문 체크 (?)
//			// 디테일하게 할 필요가 있다
//			// 점프로 방문한 것과, 인접이동으로 방문한 것은 차이가 있음
//			//if (dir < 4) // 인접 이동인 경우
//			//{
//			//	// 인접 이동(1), 인접+점프 이동(3) 방문한 경우 X
//			//	if (visit[nRow][nCol] % 2 == 1)
//			//		continue;
//			//}
//			//else // 점프 이동인 경우
//			//{
//			//	// 점프 이동(2), 인접+점프 이동(3) 방문한 경우 X
//			//	if (visit[nRow][nCol] > 1)
//			//		continue;
//			//}
//
//			// 방문한 적 있으면서, 남은 말 이동 횟수가 적거나 같으면 continue
//			// 방문한 적 없으면, 무조건 가능
//			// 방문한 적 있지만, 남은 말 이동 횟수가 많으면 이동 가능
//			if (visit[nRow][nCol] != 0)
//			{
//				if (horseMove[nRow][nCol] <= nHorseMove)
//					continue;
//			}
//
//			Q.push({ nRow, nCol, nHorseMove });
//			visit[nRow][nCol] = visit[get<0>(curPos)][get<1>(curPos)] + 1;
//			horseMove[nRow][nCol] = nHorseMove;
//
//			//if (dir < 4) // 인접 이동 (더하기 1)
//			//{
//			//	visit[nRow][nCol]++;
//			//}
//			//else // 점프 이동 (더하기 2)
//			//{
//			//	visit[nRow][nCol] += 2;
//			//}
//
//		}
//	
//		//moveCnt++;
//	}
//
//	cout << -1 << '\n';
//
//	return 0;
//}