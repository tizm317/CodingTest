//#include <iostream>
//#include <utility>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 21. 금
//// 문제 번호	: #14503 
//// 문제 이름	: 로봇 청소기
//// 알고리즘	: 시뮬레이션,
//// 시간복잡도: O()
//
//// 방
//int R, C; // 3 <= <= 50
//int room[55][55];  // 0 청소되지 않은 빈칸, 1 벽 , 2 청소함
//
//// 북, 동, 남, 서
//const int dRow[4] = {-1, 0, 1, 0};
//const int dCol[4] = {0, 1, 0, -1};
//
//int clearRoomCnt;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> R >> C;
//
//	// 청소기 시작 위치, 방향
//	int r, c, dir;
//	cin >> r >> c >> dir;
//
//	// 방 상태 입력
//	for (int r = 0; r < R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			cin >> room[r][c];
//		}
//	}
//
//	// 청소 시작
//	pair<int, int> curPos = { r,c };
//	while (true)
//	{
//		// 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
//		if (room[curPos.first][curPos.second] == 0)
//		{
//			room[curPos.first][curPos.second] = 2;
//			clearRoomCnt++;
//		}
//
//		// 현재 칸의 주변 4칸 체크
//		bool isClear = true;
//		for (int d = 0; d < 4; d++)
//		{
//			int nRow = curPos.first + dRow[d];
//			int nCol = curPos.second + dCol[d];
//
//			// 배열 범위 벗어나는 지 체크
//			if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C)
//				continue;
//
//			// 벽이나, 청소한 구역인 지 체크
//			if (room[nRow][nCol] != 0)
//				continue;
//
//			// 주변 4칸 중 청소해야 하는 칸 존재(1개 이상만 존재하면 되고, 존재 여부만 파악하면 돼서 break)
//			isClear = false;
//			break;
//		}
//
//		// 주변 4칸 모두 청소된 경우
//		if (isClear)
//		{
//			// 바라보는 방향을 유지(dir 자체는 안 건듦)한 채로 한 칸 후진
//			int nRow = curPos.first + dRow[(dir + 2) % 4];
//			int nCol = curPos.second + dCol[(dir + 2) % 4];
//
//			// 벽이면 작동 정지
//			if (room[nRow][nCol] == 1)
//				break;
//
//			//  한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
//			curPos = { nRow, nCol }; // 후진한 위치로 갱신
//			continue;
//		}
//		else // 청소되지 않은 빈 칸이 있는 경우
//		{
//			// 반시계 방향으로 90도 회전
//			dir += 3; 
//			dir %= 4;
//
//			// 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
//			int nRow = curPos.first + dRow[dir];
//			int nCol = curPos.second + dCol[dir];
//			if (room[nRow][nCol] == 0)
//			{
//				curPos = { nRow, nCol };
//				continue;
//			}
//		}
//	}
//
//	cout << clearRoomCnt;
//
//	return 0;
//}