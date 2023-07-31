//#include <iostream>
//#include <algorithm> // next_permutation
//#include <utility>
//#include <queue>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 31. 월.
//// 문제 번호	: #17141 , #17142
//// 문제 이름	: 연구소 2 , 연구소 3
//// 알고리즘	: 시뮬레이션, BFS 여러개, 조합
//// 시간복잡도: O()
//
//int N; // <= 50
//int room[55][55]; // 0 빈칸, 1 벽, 2 바이러스 놓을 수 있는 위치
//
//int M; // <= 10
//
//int minTime = -1;
//
//const int dRow[4] = { -1, 0, 1, 0 };
//const int dCol[4] = { 0, 1, 0, -1 };
//
//vector<pair<int, int>> virusPosVec;
//
//queue<pair<int, int>> Q;
//int dist[55][55];
//
//void BFS();
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 연구실 상태 입력
//	cin >> N >> M;
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cin >> room[r][c];
//
//			// 바이러스 벡터
//			if (room[r][c] == 2)
//			{
//				virusPosVec.push_back({ r,c });
//			}
//		}
//	}
//
//	// 조합 경우의 수
//	int idx[10] = { 0, };
//	// 뒷부분을 1로 초기화
//	for (int i = virusPosVec.size() - M; i < virusPosVec.size(); i++)
//		idx[i] = 1;
//
//	do
//	{
//		// dist 배열 초기화
//		for (int r = 0; r < 55; r++)
//			fill(&dist[r][0], &dist[r][55], -1);
//
//		for (int i = 0; i < virusPosVec.size(); i++)
//		{
//			// 연구소 2 -> 바이러스 아니면 빈칸으로 바꿈
//			if (idx[i] == 0)
//				room[virusPosVec[i].first][virusPosVec[i].second] = 0;
//
//			// 연구소 3 -> 비활성 바이러스 2로 유지 (통과는 가능하나, 빈칸에 포함되지는 않아서 maxDist 계산에서는 빠짐)
//				// [주의] 벽으로 바꾸면 아예 통과가 안 돼서, 거리가 변하거나 도달하지 못 하는 경우 생김(원래는 아닌데!)
//			//room[virusPosVec[i].first][virusPosVec[i].second] = 2;
//			else
//			{
//				room[virusPosVec[i].first][virusPosVec[i].second] = 2;
//
//				// 바이러스
//				Q.push(virusPosVec[i]);
//				dist[virusPosVec[i].first][virusPosVec[i].second] = 0;
//			}
//		}
//
//		BFS();
//
//	} while (next_permutation(idx, idx + virusPosVec.size()));
//
//	cout << minTime;
//
//	return 0;
//}
//
//// BFS 동시에 여러개!
//
//// #17142 연구소 3
//// 비활성 바이러스는 벽은 아님
//// 통과 가능 하지만 그렇다고 빈칸으로 아예 바꾸면 안됨
//// maxDist 구할 때는 빈칸이 아니므로 제외하고!
//// 바이러스가 퍼질 때는 벽이 아니므로 포함한다
//
//void BFS()
//{
//	while (!Q.empty())
//	{
//		pair<int, int> curPos = Q.front(); Q.pop();
//
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nRow = curPos.first + dRow[dir];
//			int nCol = curPos.second + dCol[dir];
//
//			if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N || room[nRow][nCol] == 1)
//				continue;
//
//			if (dist[nRow][nCol] != -1)
//				continue;
//
//			Q.push({ nRow, nCol });
//			dist[nRow][nCol] = dist[curPos.first][curPos.second] + 1;
//		}
//	}
//
//	int maxDist = 0;
//	bool fail = false;
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			// 빈칸 중에서!
//			if (room[r][c] != 0)
//				continue;
//
//			// 도달하지 못 한 경우
//			if (dist[r][c] == -1)
//			{
//				fail = true;
//				continue;
//			}
//
//			maxDist = max(maxDist, dist[r][c]);
//		}
//	}
//
//	if (!fail)
//	{
//		minTime = (minTime == -1) ? maxDist : min(minTime, maxDist);
//	}
//}