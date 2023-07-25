//#include <iostream>
//#include <algorithm> // next_permutation
//#include <queue>
//#include <utility>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 25. 화
//// 문제 번호	: #14502 
//// 문제 이름	: 연구소
//// 알고리즘	: 시뮬레이션, BFS, 순열
//// 시간복잡도: O()
//
//int R, C; // <= 8
//int map[10][10]; // 0 빈칸, 1 벽, 2 바이러스
//
//int max_safe_area_cnt;
//
//const int dRow[4] = {-1, 0, 1, 0};
//const int dCol[4] = {0, 1, 0, -1};
//
//void BFS(int map[10][10]);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 지도 입력
//	cin >> R >> C;
//	for (int r = 0; r < R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			cin >> map[r][c];
//		}
//	}
//
//	// 1. 벽 설치 경우의 수 (조합) nC3
//	//int* idx = new int[R * C]{ 0, };
//	int idx[64] = { 0,}; // 사용할 때 2차원 배열처럼 사용하기
//	fill(idx, idx + 64, 1);
//	idx[0] = idx[1] = idx[2] = 0; // 0 3개(벽) , 나머지 1
//	// 조합 때문에 작은 수를 앞에 두려고 0을 벽으로 함
//
//	do
//	{
//		// 벽 설치한 맵
//		int tmp[10][10] = { 0, };
//		bool impossibleCase = false; // 벽이나, 바이러스 위치 체크용 bool 변수
//		for (int r = 0; r < R; r++)
//		{
//			for (int c = 0; c < C; c++)
//			{
//				// 벽 설치
//				if (idx[c + r * C] == 0) // 2차원 배열처럼 사용 <<<<<<<<<<<<<<<<< 인덱스 주의! (c + r * R 로 잘 못 썼음)
//				{
//					// 이미 벽이거나, 바이러스 위치인 경우 벽 설치 fail
//					if (map[r][c] != 0)
//					{
//						impossibleCase = true;
//						break;
//					}
//					// 빈 공간이면 벽 설치
//					tmp[r][c] = 1;
//				}
//				else
//				{
//					tmp[r][c] = map[r][c];
//				}
//			}
//
//			if (impossibleCase)
//				break;
//		}		
//
//		// 2. BFS 바이러스 진행
//		if(!impossibleCase)
//			BFS(tmp);
//
//	} while (next_permutation(idx, idx + R*C));
//
//	// 결과 출력
//	cout << max_safe_area_cnt;
//
//	return 0;
//}
//
//
//void BFS(int map[10][10])
//{
//	// 큐, vis 배열 초기화
//	queue<pair<int, int>> Q;
//	bool vis[10][10] = { false, };
//
//	// 바이러스 찾기(시작점)
//	for (int r = 0; r < R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			if (map[r][c] != 2)
//				continue;
//
//			if (vis[r][c])
//				continue;
//
//			// 방문 한 적 없는, 바이러스 큐에 추가하고, 방문 표시
//			Q.push({ r,c });
//			vis[r][c] = true;
//
//			while (!Q.empty())
//			{
//				// 현재 위치
//				pair<int, int> curPos = Q.front(); Q.pop();
//
//				// 다음 위치 계산
//				for (int dir = 0; dir < 4; dir++)
//				{
//					int nRow = curPos.first + dRow[dir];
//					int nCol = curPos.second + dCol[dir];
//
//					// 배열 범위 체크, 벽 체크
//					if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C || map[nRow][nCol] == 1)
//						continue;
//
//					// 방문 여부 체크
//					if (vis[nRow][nCol])
//						continue;
//
//					// 큐에 넣고, 방문 표시 하고
//					Q.push({ nRow,nCol });
//					vis[nRow][nCol] = true;
//
//					// 바이러스 전염 표시
//					map[nRow][nCol] = 2;
//				}
//			}
//		}
//	}
//
//	// 3. 안전 영역 개수
//	// 바이러스, 벽 아닌 빈 공간(0) 개수
//	int cnt = 0;
//	for (int r = 0; r < R; r++)
//		for (int c = 0; c < C; c++)
//			if (map[r][c] == 0) cnt++;
//
//	// 맥시멈 계산
//	max_safe_area_cnt = max(max_safe_area_cnt, cnt);
//}