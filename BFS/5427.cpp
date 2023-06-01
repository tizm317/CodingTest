#include <iostream>
#include <utility>
#include <queue>
using namespace std;

// 백준 문제 풀이
// 날짜		: 2023. 05. 24. 수
// 문제 번호	: #5427 
// 문제 이름	: 불
// 알고리즘	: BFS
// 시간복잡도: O()

#define ROW first
#define COL second

// 상하좌우
const int dRow[4] = { -1,0,1,0 };
const int dCol[4] = { 0,1,0,-1 };

int T;
int w, h;

// 이동 가능 여부 배열
// 1 (불,벽 = 이동불가) , 0 빈공간 2 상근  이동가능
int maze[1000][1000];

// 방문 여부 배열
int visit[1000][1000];
int dist[1000][1000];

// 방문할 곳 담는 큐
queue<pair<int, int>> Q;

// 상근 시작 위치
pair<int, int> startPos;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		// 테케별로, 배열 초기화
		for (int r = 0; r < 1000; r++)
		{
			fill(maze[r], maze[r] + 1000, 0);
			fill(visit[r], visit[r] + 1000, 0);
			fill(dist[r], dist[r] + 1000, 0);
		}

		cin >> w >> h;

		// 미로(빌딩) 입력
		for (int r = 0; r < h; r++)
		{
			string s;
			cin >> s;

			// int로 변경
			for (int c = 0; c < w; c++)
			{
				const char& ch = s[c];
				switch (ch)
				{
				case '#':
					maze[r][c] = 1; // 벽
					break;
				case '*':
					maze[r][c] = 1; // 불

					// 불 먼저 이동
					Q.push({ r, c });
					//visit[r][c] = 1;
					break;
				case '@':
					maze[r][c] = 2; // 상근 시작 위치

					startPos = { r,c };
					
					break;
				case '.':
					maze[r][c] = 0; // 빈 공간
					break;
				}

			}
		}

		//
		// 불이 붙으려는 칸으로 이동할 수 없다 => 불이 먼저 이동
		// 마지막으로 상근이 위치 넣음
		Q.push(startPos);
		dist[startPos.ROW][startPos.COL] = 1;
		//visit[startPos.ROW][startPos.COL] = 1;

		// 현재 위치가 탈출구인 경우
		// 바로 탈출
		if (startPos.ROW == 0 || startPos.ROW == h - 1 || startPos.COL == 0 || startPos.COL == w - 1)
		{
			cout << 1 << '\n';

			// break 아니고 continue!!!
			continue;
		}

		// 불이 이동하는 경우와 상근이가 이동하는 경우 case 분리가 중요하다!!!!
		// 불이 먼저 이동해야해서, 이동 후 불의 위치와 이동 전 상근이의 위치가 겹치는 것이 중요 포인트!
		// 4179번과의 차이!

		bool success = false;
		while (!Q.empty())
		{
			// 현재 위치
			pair<int, int> curPos = Q.front(); Q.pop();
			visit[curPos.ROW][curPos.COL] = 1;

			// 상근이 이동하는 경우 : 탈출구 도달 체크
			if (maze[curPos.ROW][curPos.COL] >= 2 && ( curPos.ROW == 0 || curPos.ROW == h - 1 || curPos.COL == 0 || curPos.COL == w - 1))
			{
				cout << dist[curPos.ROW][curPos.COL] << '\n';
				success = true;
				break;
			}

			for (int dir = 0; dir < 4; dir++)
			{
				// 다음 위치
				int nRow = curPos.ROW + dRow[dir];
				int nCol = curPos.COL + dCol[dir];

				// 미로 배열 범위(w,h) 넘어가는지 체크
				if (nRow < 0 || nRow >= h || nCol < 0 || nCol >= w)
					continue;

				// 벽이나 불인지 체크(벽,불 1 / 이동후 불+이동전 상근 3)
				if (maze[nRow][nCol] == 1 || maze[nRow][nCol] == 3)
					continue;

				// 전에 방문했는지 체크
				if (visit[nRow][nCol] == 1)
					continue;

				// 다음 위치 큐에 넣음
				Q.push({ nRow, nCol });
				//visit[nRow][nCol] = 1;

				// 불이 움직이는 경우(큐에 있는 것중 maze값이 1이면 '불' // 벽은 큐에 못들어옴)
				// 반례:
				// *@ 인경우
				// 불이 먼저 움직여서 @의 maze 값도 1이됨..

				// 1. 불이 움직이는 경우
				// -> 현재 불이 움직이고, 다음 위치가 불,벽 아닌 경우(0,2)
				if (maze[curPos.ROW][curPos.COL] == 1 && (maze[nRow][nCol] == 0 || maze[nRow][nCol] == 2))
					maze[nRow][nCol] += 1;

				// 2. 상근이 움직이는 경우
				// 상근 혼자(2) , 상근(이동전) + 불(이동후) = 3
				if (maze[curPos.ROW][curPos.COL] >= 2)
				{
					// 다음 위치 2
					maze[nRow][nCol] = 2;

					dist[nRow][nCol] = dist[curPos.ROW][curPos.COL] + 1;
				}
			}

			// 상근이 모든 이동(상하좌우) 케이스 돌고 난 후 현 위치에서 제거
			// 상하좌우 다 try 한 후에 변경
			if (maze[curPos.ROW][curPos.COL] >= 2)
			{
				// 지금 위치 -2
				maze[curPos.ROW][curPos.COL] -= 2;
			}
		}

		while (!Q.empty())
			Q.pop();
		
		if (!success)
			cout << "IMPOSSIBLE" << '\n';
	}

	return 0;
}