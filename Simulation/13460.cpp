//#include <iostream>
//#include <utility>
//#include <queue>
//#include <tuple>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 27. 목
//// 문제 번호	: #13460 
//// 문제 이름	: 구슬 탈출 2
//// 알고리즘	: 시뮬레이션, 큐
//// 시간복잡도: O()
//
//int R, C; // <= 10
//char board[15][15]; // # 벽, . 빈칸, O 출구
//
//const int dRow[4] = { -1, 0, 1, 0 };
//const int dCol[4] = { 0, 1, 0, -1 };
//
//int min_move_cnt = -1;
//
//queue<tuple<int, int, char>> Q;
//
//void moveMarble(int moveCnt, const queue<tuple<int, int, char>>& Q);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 보드판 입력
//	cin >> R >> C;	
//	for (int r = 0; r < R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			char x;
//			cin >> x;
//
//			// 보드판 입력 및 구슬 큐 입력
//			if (x == 'R' || x == 'B')
//			{
//				// 구슬은 큐에 넣고
//				Q.push({ r, c, x });
//				// 대신 보드판에는 빈칸(.) 표시
//				board[r][c] = '.';
//			}
//			else
//				board[r][c] = x;
//		}
//	}
//
//	// 기울이기
//	moveMarble(1, Q);
//
//	// 결과 출력
//	cout << min_move_cnt;
//
//	return 0;
//}
//
//void moveMarble(int moveCnt, const queue<tuple<int, int, char>>& Q)
//{
//	// 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력
//		// moveCnt 10 초과 시 return
//	if (moveCnt > 10)
//		return;
//
//	// 방향을 정하고,
//	for (int dir = 0; dir < 4; dir++)
//	{
//		// 이동한 구슬 담을 새로운 큐 선언
//		queue<tuple<int, int, char>> nextQ;
//
//		// R, B 공 나갔는지 체크하기 위한 bool 변수
//		bool isRedBallOut = false;
//		bool isBlueBallOut = false;
//
//		queue<tuple<int, int, char>> tmp = Q;
//		tuple<int, int, char> firstMarble = tmp.front();
//		tuple<int, int, char> secondMarble = tmp.back();
//
//		// 1. dir 에 따라, 먼저 굴릴 구슬 순서 정함
//			// 순서 변경하는 경우	만 바꿔줌
//		switch (dir)
//		{
//		case 0: // 북쪽
//			// row가 작아야 먼저 (크면 순서 뒤로)
//			if (get<0>(firstMarble) > get<0>(secondMarble))
//			{
//				tmp.push(tmp.front());
//				tmp.pop();
//			}
//			break;
//		case 1: // 동쪽
//			// col가 커야 먼저 (작으면 순서 뒤로)
//			if (get<1>(firstMarble) < get<1>(secondMarble))
//			{
//				tmp.push(tmp.front());
//				tmp.pop();
//			}
//			break;
//		case 2: // 남쪽
//			// row가 커야 먼저 (작으면 순서 뒤로)
//			if (get<0>(firstMarble) < get<0>(secondMarble))
//			{
//				tmp.push(tmp.front());
//				tmp.pop();
//			}
//			break;
//		case 3:
//			// col가 작아야 먼저 (크면 순서 뒤로)
//			if (get<1>(firstMarble) > get<1>(secondMarble))
//			{
//				tmp.push(tmp.front());
//				tmp.pop();
//			}
//			break;
//		}
//
//		// 2. 정한 방향으로 2개의 볼 모두 움직인다.
//		while (!tmp.empty())
//		{
//			// 현재 공
//			tuple<int, int, char> curPos = tmp.front(); tmp.pop();
//
//			int nRow = get<0>(curPos);// +dRow[dir];
//			int nCol = get<1>(curPos);// +dCol[dir];
//
//			// 벽 부딪히기 전 까지 이동
//			while (board[nRow + dRow[dir]][nCol + dCol[dir]] != '#') // 공끼리 안 겹치도록해야함
//			{
//				// [나간 공이 없고, 두번째 구슬을 이동시키는 경우]
//					// tmp 가 비어있다는 것은 두번째로 움직이는 구슬이라는 뜻 <<<<<
//					// 첫번째 구슬의 위치 전까지 이동
//					//	나간 공이 없어야 함(이미 나간거에 부딪힐 수는 없음)!!!!!!!!!
//				if (tmp.empty() && !isRedBallOut && !isBlueBallOut)
//				{
//					// 공에 부딪히기 전까지 이동
//						// 첫번째 이동한 공의 좌표와 비교
//					if ((get<0>(nextQ.front()) == nRow + dRow[dir]) && (get<1>(nextQ.front()) == nCol + dCol[dir]))
//						break;
//				}
//
//				// 벽이나 공에 부딪히지 않는 경우
//				// 다음 위치로 이동
//				nRow += dRow[dir];
//				nCol += dCol[dir];
//
//				// 3. 다음 위치가 출구인 경우 bool 체크 후
//				// (해당 공은) 더이상 이동 불가하므로 break
//				if (board[nRow][nCol] == 'O')
//				{
//					if (get<2>(curPos) == 'R')
//						isRedBallOut = true;
//					else
//						isBlueBallOut = true;
//
//					break;
//				}
//			}
//
//			// 파란공 out 시 fail 이므로 그냥 break
//			if (isBlueBallOut)
//				break;
//
//			// 4. 다음 큐에 이동 후 공 넣음
//			nextQ.push({ nRow, nCol, get<2>(curPos) });
//		}
//
//
//		// 모든 공이 나가지 않은 경우
//		if (!isRedBallOut && !isBlueBallOut)
//		{
//			// 기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.
//				// 어쨌거나 모든 공이 기울여도 같은 위치라는 것은 moveMarble을 또 호출할 필요가 없다는 것(현재 lv에서와 결과가 같음
//				// 현재 구슬 큐와 이동후 구슬 큐가 같다면, 두개의 공 모두 움직이지 않은 경우
//			if (Q != nextQ)
//				moveMarble(moveCnt + 1, nextQ);
//		}
//
//		// 빨간 공만 나간 경우 - 성공
//		if (!isBlueBallOut && isRedBallOut)
//		{
//			min_move_cnt = (min_move_cnt == -1) ? moveCnt : min(min_move_cnt, moveCnt);
//			return;
//		}
//	}
//}
