//#include <iostream>
//#include <queue>
//#include <utility>
//#include <deque>
//#include <tuple> // tie
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 21. 금
//// 문제 번호	: #3190 
//// 문제 이름	: 뱀
//// 알고리즘	: 시뮬레이션, deque, queue
//// 시간복잡도: O()
//
//// 보드
//int N; // <= 100
//int board[105][105]; // 0 빈칸, 1 뱀, 2 사과
//
//// 사과 개수
//int K; // 0 <= <= 100
//
//// 방향 변환 횟수
//int L;
//
//// 방향 변환 명령 담는 큐
//queue<pair<int, char>> Q; // {시간, 방향}
//
//// 뱀 담는 덱
//deque<pair<int, int>> dq_snake;
//
//// 북,동,남,서
//const int dRow[4] = {-1, 0, 1, 0};
//const int dCol[4] = {0, 1, 0, -1};
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 사과 위치
//	cin >> N >> K;
//	for (int a = 0; a < K; a++)
//	{
//		int r, c;
//		cin >> r >> c;
//
//		board[r - 1][c - 1] = 2;
//	}
//
//	// 방향 변환
//	cin >> L;
//	for (int d = 0; d < L; d++)
//	{
//		int t;
//		char dir;
//		cin >> t >> dir;
//
//		Q.push({ t, dir });
//	}
//
//	// 게임 진행
//	// 뱀 시작 위치  {0,0} 덱에 넣고, 보드판에 표시
//	dq_snake.push_back({ 0,0 });
//	board[0][0] = 1;
//
//	// 뱀 시작 방향 동쪽 1
//	int curDir = 1; // 동
//
//	int tick = 0;
//	while (true)
//	{
//		// 0. 시간 증가
//		tick++;
//
//		// 1. 뱀은 몸길이를 늘려 머리(front())를 다음칸에 위치시킨다
//		// 다음 칸 계산
//		int nRow = dq_snake.front().first + dRow[curDir];
//		int nCol = dq_snake.front().second + dCol[curDir];
//
//		// 2. 만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
//		if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N || board[nRow][nCol] == 1)
//		{
//			// Die
//			break;
//		}
//
//		// 안 부딪히면 다음칸을 뱀 deque 의 front에 넣음 (머리)
//		dq_snake.push_front({ nRow, nCol });
//
//		// 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다.즉, 몸길이는 변하지 않는다.
//		if (board[nRow][nCol] != 2)
//		{
//			// 꼬리를 찾아서 보드판에 0으로 만들고,
//			int x, y;
//			tie(x, y) = dq_snake.back();
//			board[x][y] = 0;
//
//			// 덱에서 빼버림
//			dq_snake.pop_back();
//		}
//
//		// 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
//		// >>> continue 를 해버려서, 방향 설정을 통과하는 오류!
//		// >> 현재 방식으로 수정 해결!
//		// 머리 부분 보드판에 표시(사과 지워짐)
//		board[nRow][nCol] = 1;
//
//
//		// 방향 설정
//		// 게임 시작 시간으로부터 X초가 끝난 뒤에 방향을 회전시킨다는 뜻이다 >> loop 의 마지막에 위치함.
//		
//		// 현재 tick 과 큐에 들어 있는 첫번째 front 명령의 시간(first) 와 같은 지 비교
//		if (!Q.empty() && tick == Q.front().first)
//		{
//			// 오른쪽 90 회전
//			if (Q.front().second == 'D')
//			{
//				curDir += 1;
//				curDir %= 4;
//			}
//			else // L , 왼쪽 90 회전
//			{
//				// 0 1 2 3
//				//curDir -= 1; // -1	0	1	2
//				//curDir += 4; //  3	4	5	6
//				curDir += 3;
//				curDir %= 4; //	 3	0	1	2
//				// 음수 modular 연산 확인해보기!! >> 원하는대로 안 나옴
//			}
//
//			// 명령 실행 후 큐에서 제거
//			Q.pop();
//		}
//
//	}
//
//	// 최단 시간 출력
//	cout << tick;
//
//	return 0;
//}