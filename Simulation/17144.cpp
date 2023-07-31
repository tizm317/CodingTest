#include <iostream>
#include <utility>
//#include <queue>
#include <vector>
using namespace std;

// 백준 문제 풀이
// 날짜		: 2023. 07. 31. 월
// 문제 번호	: #17144 
// 문제 이름	: 미세먼지 안녕!
// 알고리즘	: 시뮬레이션, BFS
// 시간복잡도: O()

int R, C;
int room[55][55];

int T;

const int dRow[4] = { -1, 0, 1, 0 };
const int dCol[4] = { 0, 1, 0, -1 };

//vector<pair<int, int>> microdustVec;
//queue<pair<int, int>> Q;
int dist[55][55];

vector<pair<int, int>> airCleaner;


// 미세먼지 확산 BFS
void microdustDiffuse()
{
	//pair<int, int> curPos = Q.front(); Q.pop();

	int room2[55][55] = { 0, };

	//vector<pair<int, int>> tmpVec = microdustVec;

	//for (auto microdust : tmpVec)
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (room[r][c] == 0 || room[r][c] == -1)
				continue;

			// 현재 위치의 미세먼지 양
			//const int dust = room[microdust.first][microdust.second];
			const int dust = room[r][c];

			// 퍼지는 미세먼지 양 계산
			const int diffuseDust = dust / 5;

			// 0 이하면 퍼져도 의미 없으므로 pass
			if (diffuseDust <= 0) continue;

			// 상하좌우 퍼지는 과정
			for (int dir = 0; dir < 4; dir++)
			{
				//int nRow = microdust.first + dRow[dir];
				int nRow = r + dRow[dir];
				//int nCol = microdust.second + dCol[dir];
				int nCol = c + dCol[dir];

				// 배열 범위 넘으면 X
				if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C)
					continue;

				// 공기청정기 위치 X
				if (room[nRow][nCol] == -1)
					continue;

				// 퍼진만큼 현재 위치 미세먼지 감소
				//room[microdust.first][microdust.second] -= diffuseDust;
				room[r][c] -= diffuseDust;

				// '새롭게' 퍼진 위치를 벡터에 추가함 (이미 있는 위치는 추가하면 여러번 퍼지게 됨)
				// 원래 미세먼지 없던 곳이면서 새로 퍼진 경우에도 1번만 추가하기 위한 조건 <<<<<<<<<<<<<<<<<<<<<<<<<,,
				//if (room[nRow][nCol] == 0 && room2[nRow][nCol] == 0)
				//{
				//	microdustVec.push_back({ nRow, nCol });
				//}


				// 다른 배열에 퍼진 미세먼지 양 더해줌
				room2[nRow][nCol] += diffuseDust;
			}
		}
	}
	

	//cout << '\n';
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			// 새로 확산된 곳 추가
			/*if (room[r][c] == 0 && room2[r][c] != 0 && room2[r][c] / 5 > 0)
			{
				microdustVec.push_back({ r, c });
			}*/
			room[r][c] += room2[r][c];
			//cout << room[r][c] << " ";
		}
		//cout << '\n';
	}

}

void runAirCleaner()
{
	// 위쪽 공기청정기 : 반시계
	// airCleaner[0]
	int r = airCleaner[0].first;
	int c = airCleaner[0].second;
	for (int rr = r - 2; rr >= 0; rr--)
	{
		room[rr + 1][c] = room[rr][c];
	}
	for (int cc = 1; cc <= C - 1; cc++)
	{
		room[0][cc - 1] = room[0][cc];
	}
	for (int rr = 1; rr <= r; rr++)
	{
		room[rr - 1][C - 1] = room[rr][C - 1];
	}
	for (int cc = C - 2; cc > c; cc--)
	{
		room[r][cc + 1] = room[r][cc];
	}
	room[r][c + 1] = 0;

	// 아랫쪽 공기청정기 : 시계
	// airCleaner[1]
	r = airCleaner[1].first;
	c = airCleaner[1].second;
	for (int rr = r + 2; rr < R; rr++)
	{
		room[rr - 1][c] = room[rr][c];
	}
	for (int cc = 1; cc <= C - 1; cc++)
	{
		room[R-1][cc - 1] = room[R-1][cc];
	}
	for (int rr = R-2; rr >= r; rr--)
	{
		room[rr + 1][C - 1] = room[rr][C - 1];
	}
	for (int cc = C - 2; cc > c; cc--)
	{
		room[r][cc + 1] = room[r][cc];
	}
	room[r][c + 1] = 0;

	// 공기청정기로 들어오면 정화됨

	/*cout << '\n';
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			cout << room[r][c] << " ";
		}
		cout << '\n';
	}*/
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 방 상태 배열 입력
	cin >> R >> C >> T;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			cin >> room[r][c];
			/*if (room[r][c] != 0 && room[r][c] != -1 && room[r][c] / 5 > 0)
			{
				microdustVec.push_back({ r,c });
			}*/
			if (room[r][c] == -1)
			{
				airCleaner.push_back({ r,c });
			}
				//Q.push({ r,c });
		}
	}

	// 0. T번 반복
	while (T--)
	{
		// 1. 미세먼지 확산
		microdustDiffuse();

		// 2. 공기청정기 작동
		runAirCleaner();
	}

	int microdusts = 0;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (room[r][c] == 0 || room[r][c] == -1)
				continue;

			microdusts += room[r][c];
		}
	}

	cout << microdusts;

	return 0;
}