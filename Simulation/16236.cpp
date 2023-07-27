#include <iostream>
#include <utility>
#include <queue>
using namespace std;

// 백준 문제 풀이
// 날짜		: 2023. 07. 27. 목
// 문제 번호	: #16236 
// 문제 이름	: 아기 상어
// 알고리즘	: 시뮬레이션, BFS
// 시간복잡도: O()

int N; // <= 20
int aquarium[25][25];

// 아기 상어 위치와 사이즈 따로 들고 있음
pair<int, int> babySharkPos;
int babySharkSize = 2; // (레벨)

// 먹은 물고기 수 (경험치)
int eatCnt;

// 물고기 잡아먹는 시간
int t;

// BFS 용
int dist[25][25];
const int dRow[4] = { -1, 0, 1, 0 };
const int dCol[4] = { 0, 1, 0, -1 };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 아쿠아리움 배치도 입력
	cin >> N;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			int x;
			cin >> x;
			if (x == 9)
			{
				babySharkPos = { r,c };
				x = 0;
			}
			aquarium[r][c] = x;

			//cin >> aquarium[r][c];

			// 아기 상어 위치는 따로 들고 있음 (배열에서 빼도 됨)
			//if (aquarium[r][c] == 9) babySharkPos = { r,c };
		}
	}

	// 더 이상 먹을 게 없을 때까지 반복
	while (true)
	{
		// dist 배열 초기화
		for (int r = 0; r < N; r++)
			fill(&dist[r][0], &dist[r][25], -1);

		// 시작 위치 큐에 저장, dist = 0 초기화
		queue<pair<int, int>> Q;
		Q.push(babySharkPos);
		dist[babySharkPos.first][babySharkPos.second] = 0;

		// 최단거리 초기화
		int min_dist = N * N;

		// 1. BFS 돌면서 먹을 수 있는 물고기와의 거리 계산
		while (!Q.empty())
		{
			// 아기 상어 현재 위치
			pair<int, int> curPos = Q.front(); Q.pop();

			// 다음 위치
			for (int dir = 0; dir < 4; dir++)
			{
				int nRow = curPos.first + dRow[dir];
				int nCol = curPos.second + dCol[dir];

				// 배열 범위
				if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
					continue;

				// 재방문 여부
				if (dist[nRow][nCol] != -1)
					continue;

				// 물고기보다 작으면 이동 불가
				if (babySharkSize < aquarium[nRow][nCol])
					continue;

				// 큐에 넣고, dist 계산
				Q.push({ nRow, nCol });
				dist[nRow][nCol] = dist[curPos.first][curPos.second] + 1;

				// 빈칸 아닌 것 중에, 먹을 수 있는 물고기 와의 최단거리 저장 !!!
				if (aquarium[nRow][nCol] != 0 &&  aquarium[nRow][nCol] < babySharkSize)
				{
					min_dist = min(min_dist, dist[nRow][nCol]);
				}
			}
		}

		// 2. 최단거리에 있는 물고기 먹는 과정

		// 움직일 수 있는지 체크하기 위한 bool 변수
		bool isMoved = false;
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				// 물고기 없는 곳 pass
				if (aquarium[r][c] == 0)
					continue;

				// 갈 수 없는 곳 pass
				if (dist[r][c] == -1)
					continue;

				// 먹을 수 없는 물고기 pass (아기 상어보다 작아야 함)
				if (babySharkSize <= aquarium[r][c])
					continue;

				// 최단거리인 물고기 
					//(for문 도는 순서가 좌상단->우하단 이기 때문에 최단거리 여러마리일 때 조건 알아서 만족함)
				if (min_dist == dist[r][c]) ///////////////////////////////////////////
				{
					// 이동했음을 표시
					isMoved = true;
					
					// 이동 전 위치 지워주고
					//aquarium[babySharkPos.first][babySharkPos.second] = 0;
					
					// 이동 후 위치에 표시해주고
					babySharkPos = { r,c };
					//aquarium[r][c] = 9;
					aquarium[r][c] = 0; // 지워줌

					// 이동 시간 더해줌
					t += dist[r][c];

					// 먹은 물고기 카운팅
					eatCnt++;

					// 자기 크기와 같은 수의 물고리 먹으면, 크기 1 증가
					if (eatCnt == babySharkSize)
					{
						babySharkSize++;

						// 경험치 초기화
						eatCnt = 0;
					}

					break;
				}
			}
			if (isMoved) break;
		}

		// 더 이상 먹을 수 없으면 끝
		if (!isMoved) break;
	}

	// 시간 출력
	cout << t;

	return 0;
}