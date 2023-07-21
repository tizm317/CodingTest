//#include <iostream>
//#include <vector>
//#include <algorithm> // permutation
//#include <queue>
//#include <tuple>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 21. 금
//// 문제 번호	: #16985 
//// 문제 이름	: Maaaaaaaaaze
//// 알고리즘	: 시뮬레이션, 순열, BFS
//// 시간복잡도: O()
//
//const int SIZE = 5;
//vector<vector<vector<int>>> V; // 5x5 배열을 담는 벡터
//
//const int SHORTEST_DISTANCE = 12;
//int ans = -1;
//
//// 북동남서, 상하
//const int dRow[6] = { -1,0,1,0,0,0 };
//const int dCol[6] = { 0,1,0,-1,0,0 };
//const int dHeight[6] = { 0,0,0,0,-1,1 };
//
//
//// 쌓는 순서 결정 짓는 함수
//void stackMaze();
//
//// 회전 결정 짓는 함수
//void rotateMaze(int h, vector<vector<vector<int>>>& maze);
//
//// 모든 경우의 수 마다 최단 거리 찾는 함수
//void BFS(vector<vector<vector<int>>>& maze);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 5x5 판 5개 입력
//	for (int i = 0; i < SIZE; i++)
//	{
//		vector<vector<int>> tmp(SIZE, vector<int>(SIZE));
//		for (int r = 0; r < SIZE; r++)
//		{
//			for (int c = 0; c < SIZE; c++)
//			{
//				cin >> tmp[r][c];
//			}
//		}
//		V.push_back(tmp);
//	}
//
//	// 판 쌓기
//	stackMaze();
//
//	// 최단거리 출력
//	cout << ans;
//
//	return 0;
//}
//
//void BFS(vector<vector<vector<int>>>& maze)
//{
//	// 입구 출구 막힌 경우
//	if (maze[0][0][0] == 0 || maze[SIZE - 1][SIZE - 1][SIZE - 1] == 0)
//		return;
//
//	// 거리 배열 -1 초기화
//	int dist[SIZE][SIZE][SIZE];
//	for (int h = 0; h < SIZE; h++)
//		for (int r = 0; r < SIZE; r++)
//			for (int c = 0; c < SIZE; c++)
//				dist[h][r][c] = -1;
//
//	// 입구 위치 [0][0][0]
//	// 출구 위치 [4][4][4]
//	queue<tuple<int, int, int>> Q;
//	Q.push({ 0,0,0 });
//	dist[0][0][0] = 0;
//
//	while (!Q.empty())
//	{
//		// 현재 위치
//		tuple<int, int, int> curPos = Q.front(); Q.pop();
//
//		// 출구인지 체크
//		if (curPos == tuple<int, int, int>{SIZE - 1, SIZE - 1, SIZE - 1})
//		{
//			if (ans == -1)
//				ans = dist[get<0>(curPos)][get<1>(curPos)][get<2>(curPos)];
//			else
//				ans = min(ans, dist[get<0>(curPos)][get<1>(curPos)][get<2>(curPos)]);
//
//			break;
//		}
//
//		// 다음 위치 계산
//		for (int dir = 0; dir < 6; dir++)
//		{
//			int nHeight = get<0>(curPos) + dHeight[dir];
//			int nRow = get<1>(curPos) + dRow[dir];
//			int nCol = get<2>(curPos) + dCol[dir];
//
//			// 배열 범위 체크
//			if (nRow < 0 || nRow >= SIZE || nCol < 0 || nCol >= SIZE || nHeight < 0 || nHeight >= SIZE)
//				continue;
//
//			// 벽
//			if (maze[nHeight][nRow][nCol] == 0)
//				continue;
//
//			// 중복 방문 체크
//			if (dist[nHeight][nRow][nCol] != -1)
//				continue;
//
//			Q.push({ nHeight, nRow, nCol });
//			dist[nHeight][nRow][nCol] = dist[get<0>(curPos)][get<1>(curPos)][get<2>(curPos)] + 1;
//		}
//	}
//}
//void rotateMaze(int h, vector<vector<vector<int>>>& maze)
//{
//	if (h >= SIZE)
//	{
//		BFS(maze);
//
//		return;
//	}
//
//	vector<vector<vector<int>>> tmp = maze;
//	// 90, 180, 270, 360
//	for (int rot = 0; rot < 4; rot++)
//	{
//		for (int r = 0; r < SIZE; r++)
//		{
//			for (int c = 0; c < SIZE; c++)
//			{
//				// 90도 회전
//				tmp[h][r][c] = maze[h][c][SIZE - 1 - r];
//			}
//		}
//
//		maze = tmp;
//		rotateMaze(h + 1, maze);
//
//		// 최소경로 SHORTEST_DISTANCE(12) 일 경우 빠르게 끝내기 위함
//		if (ans == SHORTEST_DISTANCE)
//			return;
//	}
//
//}
//void stackMaze()
//{
//	// 판 쌓는 순서 - 순열 이용
//	int idxes[SIZE] = { 0,1,2,3,4 };
//	do
//	{
//		vector<vector<vector<int>>> maze;
//		// 순열 결과에 따라 판 쌓기
//		for (int i = 0; i < SIZE; i++)
//		{
//			const int idx = idxes[i];
//			maze.push_back(V[idx]);
//		}
//
//		// 회전
//		rotateMaze(0, maze);
//
//	} while (next_permutation(idxes, idxes + SIZE));
//}
