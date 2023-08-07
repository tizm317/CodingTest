//#include <iostream>
//#include <tuple>
//#include <queue>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 20xx. xx. xx.
//// 문제 번호	: #00000 
//// 문제 이름	: 
//// 알고리즘	: 
//// 시간복잡도: O()
//
//int N; // <= 50
//queue<tuple<int,int,int>> board[55][55]; // {질량, 속도, 방향}
//
//// 파이어볼 개수
//int M; // <= 2500
//
//// 이동 명령 개수
//int K; // <= 1000
//
//const int dRow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
//const int dCol[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M >> K;
//	for (int i = 0; i < M; i++)
//	{
//		int r, c, m, s, d;
//		cin >> r >> c >> m >> s >> d;
//
//		//board[r - 1][c - 1] = { m, s, d };
//		board[r - 1][c - 1].push({ m,s,d });
//	}
//
//	while (K--)
//	{
//		// 이동 후 배열
//		queue<tuple<int, int, int>> movedBoard[55][55];
//
//		// 이동
//		for (int r = 0; r < N; r++)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				if (board[r][c].empty()) continue;
//
//				while (!board[r][c].empty())
//				{
//					tuple<int, int, int> fireball = board[r][c].front(); board[r][c].pop();
//					int s = get<1>(fireball);
//					int d = get<2>(fireball);
//				
//					int nextR = (r + (N + dRow[d]) * s) % N;
//					int nextC = (c + (N + dCol[d]) * s) % N;
//
//					movedBoard[nextR][nextC].push(fireball);
//				}
//			}
//		}
//
//		for (int r = 0; r < N; r++)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				if (movedBoard[r][c].size() < 2) continue;
//
//				const int fireballCnt = movedBoard[r][c].size();
//				int mSum = 0;
//				int sSum = 0;
//				bool isAllEven = true; bool isAllOdd = true;
//				while (!movedBoard[r][c].empty())
//				{
//					tuple<int, int, int> fire = movedBoard[r][c].front(); movedBoard[r][c].pop();
//					mSum += get<0>(fire);
//					sSum += get<1>(fire);
//					const int d = get<2>(fire);
//					if (d % 2 == 0)
//						isAllOdd = false;
//					else
//						isAllEven = false;
//				}
//
//				// 버림 맞나?
//				const int nextM = int(mSum / 5);
//				if (nextM <= 0) continue;
//
//				const int nextS = int(sSum / fireballCnt);
//
//				// 합쳐진 방향이 모두 홀수이거나 모두 짝수이면
//				if (isAllEven || isAllOdd)
//				{
//					for (int dir = 0; dir < 4; dir++)
//					{
//						movedBoard[r][c].push({ nextM, nextS, (dir * 2) });
//
//						//int nRow = (r + dRow[dir * 2] + N) % N; // <<< ??
//						//int nCol = (c + dCol[dir * 2] + N) % N;
//
//						/*if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
//							continue;*/
//
//					}
//				}
//				else
//				{
//					for (int dir = 0; dir < 4; dir++)
//					{
//						movedBoard[r][c].push({ nextM, nextS, (dir * 2 + 1) });
//
//						/*int nRow = (r + dRow[dir * 2 + 1] + N) % N;
//						int nCol = (c + dCol[dir * 2 + 1] + N) % N;*/
//
//						/*if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
//							continue;*/
//					}
//				}
//			}
//		}
//
//		for (int r = 0; r < N; r++)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				board[r][c] = movedBoard[r][c];
//			}
//		}
//	}
//
//	int totalMSum = 0;
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			if (board[r][c].empty()) continue;
//
//			while (!board[r][c].empty())
//			{
//				tuple<int, int, int> fire = board[r][c].front(); board[r][c].pop();
//
//				totalMSum += get<0>(fire);
//			}
//		}
//	}
//
//	cout << totalMSum;
//
//
//	return 0;
//}