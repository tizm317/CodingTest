#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// 백준 문제 풀이
// 날짜		: 2023. 07. 25. 화.
// 문제 번호	: #16234 
// 문제 이름	: 인구 이동
// 알고리즘	: 시뮬레이션, BFS
// 시간복잡도: O()

int N; // <= 50
int map[55][55];

int L, R;

queue<pair<int, int>> Q;

const int dRow[4] = { -1, 0, 1, 0 };
const int dCol[4] = { 0, 1, 0, -1 };

// 인구이동
void migration(int days);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 인구지도 입력
	cin >> N >> L >> R;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> map[r][c];

	migration(0);

	return 0;
}

void migration(int days)
{
	// vis 배열 초기화
	bool vis[55][55] = { false, };

	// 연합이 이뤄졌는지 체크하기 위한 bool 변수
	bool isCountryUnite = false;

	// 시작 지점 찾기
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			// 이미 방문한 곳 pass
			if (vis[r][c])
				continue;

			// 큐에 넣고, 방문 표시
			Q.push({ r,c });
			vis[r][c] = true;

			// 나라 연합 벡터 -> 밑에서 인구수 계산하기 위한 벡터
			vector<pair<int, int>> countryVec;
			countryVec.push_back({ r,c });

			// 연합의 인구수 총합 담는 변수
			int countryPeopleCnt = map[r][c];

			// BFS 돌면서 연합 가능한 나라 찾기
			while (!Q.empty())
			{
				// 현재 위치
				pair<int, int> curPos = Q.front(); Q.pop();

				// 다음 위치 계산
				for (int dir = 0; dir < 4; dir++)
				{
					int nRow = curPos.first + dRow[dir];
					int nCol = curPos.second + dCol[dir];

					// 배열 범위 체크
					if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
						continue;

					// 방문 여부 체크
					if (vis[nRow][nCol])
						continue;

					// 인접 국가와의 인구수 차이 계산 및 조건 L,R 체크
					const int diff = abs(map[curPos.first][curPos.second] - map[nRow][nCol]);
					if (diff < L || diff > R)
						continue;

					// 연합 가능한 국가
					// 큐에 추가하고, 방문 표시
					Q.push({ nRow, nCol });
					vis[nRow][nCol] = true;

					// 연합국가 벡터에도 추가하고, 국가간 연합이 발생함을 표시
					countryVec.push_back({ nRow, nCol });
					countryPeopleCnt += map[nRow][nCol]; // 연합의 인구수 총합 계산 <<<<<<<
					isCountryUnite = true;
				}
			}

			const int countryCnt = countryVec.size();

			// 연합 인구수 계산 >>>>>>>>>>>>>>>>>>> 벡터에 넣어줄 때 계산하면, 중복해서 for문 안 돌려도 되고 좋음.
			//int countryPeopleCnt = 0;
			//for (auto x : countryVec)
			//{
			//	pair<int, int> curPos = x;
			//	countryPeopleCnt += map[curPos.first][curPos.second];
			//}

			// 연합의 새로운 인구수 설정
			const int newPeopleCnt = countryPeopleCnt / countryCnt;
			for (auto x : countryVec)
			{
				map[x.first][x.second] = newPeopleCnt;
			}
		}
	}

	// 연합 이뤄졌으면, migration 함수 호출
	if (isCountryUnite)
		migration(days + 1);
	else // 연합 없었으면, 인구 이동 며칠 동안 이뤄졌는지 출력 하고 return
		cout << days;
}