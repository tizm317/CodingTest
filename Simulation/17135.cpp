//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <utility>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 08. 07. 월
//// 문제 번호	: #17135
//// 문제 이름	: 캐슬 디펜스
//// 알고리즘	: 시뮬레이션
//// 시간복잡도: O()
//
//int R, C; // <= 15
//int board[20][20]; // 0 빈칸, 1 적, 2 궁수
//
//int D;
//
//const int dRow[3] = {0, -1, 0};
//const int dCol[3] = {-1, 0, 1};
//
//void printBoard(int board[][20]);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> R >> C >> D;
//	
//	// 적 배열 입력
//	for (int r = 0; r < R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			cin >> board[r][c];
//		}
//	}
//
//	int maxDeadEnemyCnt = 0;
//
//	// idx 배열 초기화
//		// 뒷부분 3개(C-1, C-2, C-3)를 1로 초기화 (순열)
//	int idx[20] = { 0, }; // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 이걸 크기를 잘 못 잡아둠...;;
//	for (int i = 1; i <= 3; i++)
//		idx[C - i] = 1;
//
//	do
//	{	
//		//cout << "Case <<<<<" << '\n';
//
//		int tempBoard[20][20] = { 0, };
//		for (int r = 0; r <= R; r++)
//		{
//			for (int c = 0; c < C; c++)
//			{
//				tempBoard[r][c] = board[r][c];
//			}
//		}
//
//		// 궁수 배치
//		for (int i = 0; i < C; i++)
//		{
//			// 0 : 궁수 X
//			if (idx[i] == 0)
//				tempBoard[R][i] = 0;
//			else // 1 : 궁수 O
//				tempBoard[R][i] = 2;
//		}
//
//		//cout << "초기 상태" << '\n';
//		//printBoard(tempBoard);
//
//		//
//		int killCnt = 0;
//		while (true)
//		{
//			int nextBoard[20][20] = { 0, };
//			for (int r = 0; r <= R; r++)
//			{
//				for (int c = 0; c < C; c++)
//				{
//					nextBoard[r][c] = tempBoard[r][c];
//				}
//			}
//
//			// dist 배열 초기화
//			int dist[20][20];
//			for (int r = 0; r < 20; r++)
//				for (int c = 0; c < 20; c++)
//					dist[r][c] = -1;
//
//			// 턴 시작
//			// 왼쪽부터 시작
//			for (int c = 0; c < C; c++)
//			{
//				// 궁수 X
//				if (tempBoard[R][c] == 0) continue;
//
//				queue<pair<int, int>> Q;
//
//				// 시작점 : (R-1, c) 큐에 넣고, dist = 1 로 초기화
//				Q.push({ R - 1, c });
//				dist[R - 1][c] = 1;
//
//				while (!Q.empty())
//				{
//					pair<int, int> curPos = Q.front(); Q.pop();
//					const int curR = curPos.first;
//					const int curC = curPos.second;
//					const int curDist = dist[curR][curC];
//
//					if (tempBoard[curR][curC] == 1)
//					{
//						// Kill
//						if (nextBoard[curR][curC] != 0)
//						{
//							killCnt++;
//						}
//						nextBoard[curR][curC] = 0;
//						break;
//					}
//
//					// 쏠 수 있는 범위 체크하기 위한 bool 변수
//					bool found = false;
//					for (int dir = 0; dir < 3; dir++)
//					{
//						const int nextR = curR + dRow[dir];
//						const int nextC = curC + dCol[dir];
//
//						if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C)
//							continue;
//
//						// 이미 q에 넣음 << 여기서 문제
//						if (dist[nextR][nextC] != -1 && tempBoard[nextR][nextC] == 0) continue;
//
//						const int nextDist = curDist + 1;
//
//						if (nextDist <= D)
//						{
//							Q.push({ nextR, nextC });
//							dist[nextR][nextC] = nextDist;
//
//							// 가장 가까운 한명만 죽여야 하기 때문에 for문 break // << 
//							if (tempBoard[nextR][nextC] == 1)
//							{
//								found = true;
//								// Kill
//								if (nextBoard[nextR][nextC] != 0)
//								{
//									killCnt++;
//								}
//								nextBoard[nextR][nextC] = 0;
//								break;
//							}
//						}
//					}
//					if (found) break;
//
//					//// 범위 넘어간 경우 (break 하면 아직 큐 안에 체크 못한게 남아있어서 안됨)
//					//if (isInDist == false)
//					//	continue;
//				}
//			}
//
//
//			// 갱신
//			for (int r = 0; r < R; r++)
//			{
//				for (int c = 0; c < C; c++)
//				{
//					tempBoard[r][c] = nextBoard[r][c];
//				}
//			}
//
//			//cout << "kill 이후" << '\n';
//			//printBoard(tempBoard);
//
//			// 적 이동
//			fill(&tempBoard[R - 1][0], &tempBoard[R - 1][C], 0); // 마지막줄 다음은 탈출
//			int enemyCnt = 0;
//			for (int r = R - 2; r >= 0; r--)
//			{
//				for (int c = 0; c < C; c++)
//				{
//					tempBoard[r + 1][c] = tempBoard[r][c];
//
//					if (tempBoard[r][c] == 1)
//						enemyCnt++;
//				}
//			}
//			fill(&tempBoard[0][0], &tempBoard[0][C], 0); // 맨 윗줄 0
//
//
//			//cout << "적 이동 이후" << '\n';
//			//printBoard(tempBoard);
//			//cout << "kill Count : " << killCnt << '\n';
//
//			// 배열 내에 적이 없으면, maxDeadEnemyCnt 계산 후 break
//			if (enemyCnt == 0)
//			{
//				maxDeadEnemyCnt = max(killCnt, maxDeadEnemyCnt);
//				break;
//			}
//		}
//	} while (next_permutation(idx, idx + C)); // <<<
//
//	//  궁수의 공격으로 제거할 수 있는 적의 최대 수를 출력
//	cout << maxDeadEnemyCnt;
//
//	return 0;
//}
//
//
//void printBoard(int board[][20])
//{
//	cout << '\n';
//	for (int r = 0; r <= R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			cout << board[r][c] << " ";
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//}