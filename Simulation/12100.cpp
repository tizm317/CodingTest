//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 19. 수
//// 문제 번호	: #12100 
//// 문제 이름	: 2048 (Easy)
//// 알고리즘	: 시뮬레이션
//// 시간복잡도: O()
//
//int N; // 1 <= N <= 20
//int board[30][30];
//
//const int dRow[4] = {-1, 0, 1, 0};
//const int dCol[4] = {0, 1, 0, -1};
//
//int ans;
//
//void myfunc(int r, int c, int dir, int(*board)[30], bool(*check)[30])
//{
//	// 현재 칸의 숫자
//	int curNum = board[r][c];
//
//	// 빈칸은 pass
//	if (curNum != 0)
//	{
//		// if(curNum == 0)
//		//	 continue;
//
//		int nRow = r;
//		int nCol = c;
//
//		while (true)
//		{
//			nRow += dRow[dir];
//			nCol += dCol[dir];
//
//			// 배열 끝 도달 : 멈춤
//			if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
//				break;
//
//			// 다른 숫자와 만나는 경우 (0이 아닌..) : 멈춤
//			if (curNum != board[nRow][nCol] && board[nRow][nCol] != 0)
//				break;
//
//			// 같은 숫자와 만나는 경우 : 합쳐지고, 멈춤
//			if (curNum == board[nRow][nCol])
//			{
//				// 현재칸, 다음칸 모두 합쳐진 적 없어야 함! 
//				if ((check[r][c] == false && check[nRow][nCol] == false))
//				{
//					// 다음 칸에 숫자 더하고,
//					board[nRow][nCol] += curNum;
//
//					// 체크 배열 표시 <<
//					check[nRow][nCol] = true;
//
//					// 현재 칸은 비워줌(0)
//					board[r][c] = 0;
//				}
//
//				// 둘 중 하나라도 합쳐진 적 있으면, 그냥 멈춤
//				break;
//			}
//
//			// 다음 칸이 빈칸인 경우(0) : 계속 이동
//			if (board[nRow][nCol] == 0)
//			{
//				// 다음 칸에 넣어주고, 현재 칸 비움
//				board[nRow][nCol] = curNum;
//				board[r][c] = 0;
//			
//				// 이동 했으니, 위치도 갱신
//				r = nRow;
//				c = nCol;
//			}
//		}
//	}
//}
//
//void slide(int dir, int (*board)[30])
//{
//	// 한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다. 
//	bool check[30][30] = { false, };
//
//	switch (dir)
//	{
//	case 0:
//		for (int r = 0; r < N; r++)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				myfunc(r, c, dir, board, check);
//			}
//		}
//		break;
//	case 1:
//		for (int c = N - 1; c >= 0; c--)
//		{
//			for (int r = 0; r < N; r++)
//			{
//				myfunc(r, c, dir, board, check);
//			}
//		}
//		break;
//	case 2:
//		for (int r = N - 1; r >= 0; r--)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				myfunc(r, c, dir, board, check);
//			}
//		}
//		break;
//	case 3:
//		for (int c = 0; c < N; c++)
//		{
//			for (int r = 0; r < N; r++)
//			{
//				myfunc(r, c, dir, board, check);
//			}
//		}
//		break;
//	}
//
//
//}
//
//void myGamePlay(int avaliableSlideCnt, const int (*board)[30])
//{
//	if (avaliableSlideCnt <= 0)
//	{
//		//int maxNum = 0;
//		for (int r = 0; r < N; r++)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				ans = max(ans, board[r][c]);
//				//maxNum = max(maxNum, board[r][c]);
//			}
//		}
//
//		//ans = max(ans, maxNum);
//
//		return;
//	}
//
//	// 4방향 모두 slide
//	int tmp[30][30] = { 0, };
//	for (int dir = 0; dir < 4; dir++)
//	{
//		for (int r = 0; r < N; r++)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				tmp[r][c] = board[r][c];
//			}
//		}
//
//		slide(dir, tmp); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,
//
//		myGamePlay(avaliableSlideCnt - 1, tmp);
//	}
//
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 보드판 입력
//	cin >> N;
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cin >> board[r][c];
//		}
//	}
//
//	// 5번 플레이
//	myGamePlay(5, board);
//
//	cout << ans;
//
//	return 0;
//}