#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;

// 백준 문제 풀이
// 날짜		: 2023. 08. 10. 목
// 문제 번호	: #19237
// 문제 이름	: 어른 상어
// 알고리즘	: 시뮬레이션
// 시간복잡도: O()

int N; // <= 20
vector<tuple<int, int, int>> sharkVec; // {r,c, dir}
pair<int, int> smell[25][25]; // {상어 번호, 남은시간}

int M; // <= 400
// [상어][방향]
vector<int> sharkMovePriorityArr[405][4];

int K; // <= 1000

// 상하좌우
const int dRow[4] = { -1, 1, 0, 0 };
const int dCol[4] = { 0, 0, -1, 1 };

void printBoard(vector<tuple<int, int, int>> curSharkVec, const pair<int, int> smell[][25]);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> tempVec;

	cin >> N >> M >> K;

	// 초기화
	sharkVec = vector<tuple<int, int, int>>(M + 1);
	for (auto& shark : sharkVec)
	{
		shark = { -1,-1,-1 };
	}

	// 상어 위치 배열 입력
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			int num;
			cin >> num;

			if (num != 0)
			{
				sharkVec[num] = { r,c, 0 };

				smell[r][c] = { num, K };
			}
		}
	}

	// 상어 초기 방향 입력
	for (int sharkNum = 1; sharkNum <= M; sharkNum++)
	{
		int d;
		cin >> d;

		get<2>(sharkVec[sharkNum]) = d - 1;
	}

	// 상어 방향 우선순위 배열 입력
	for (int sharkNum = 1; sharkNum <= M; sharkNum++)
	{
		// 상하좌우 기준
		for (int d = 0; d < 4; d++)
		{
			// 우선순위 방향 4개 입력
			for (int t = 0; t < 4; t++)
			{
				int dir;
				cin >> dir;

				sharkMovePriorityArr[sharkNum][d].push_back(dir - 1);
			}
		}
	}

	cout << "초기 상태 : " << '\n';
	printBoard(sharkVec, smell);

	int tick = 0;
	int sharkCnt = M;
	while (true)
	{
		// 상어 1마리(1번 상어만 생존) 종료
		if (sharkCnt == 1)
			break;

		// 단, 1,000초가 넘어도 다른 상어가 격자에 남아 있으면 -1을 출력한다.
			// 왜 1000초 이상 인거지? 초과가 아니고..
			// 맞네! 1바퀴 돌고나서 sharkCnt 체크하면 -> 1초 지난 후 남은 상어 수
			// 그러면 1000바퀴 돌고나서 체크하면 -> 1000초 지난 후 남은 상어 수!
			// 따라서, tick >= 1000 이 맞음
			// tick > 1000 으로 하면, 1001초 지난 후 체크하는 상어 수 이기 때문에 틀림!!
		if (tick >= 1000) // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		{
			tick = -1;
			break;
		}

		// 1. 상어 이동
		for(int sharkNum = 1; sharkNum <= M; sharkNum++)
		{
			int curR = get<0>(sharkVec[sharkNum]);
			int curC = get<1>(sharkVec[sharkNum]);
			int curDir = get<2>(sharkVec[sharkNum]);
			// 죽은 상어 제외
			if (curR == -1 || curC == -1 || curDir == -1) continue;

			const vector<int>& priorityVec = sharkMovePriorityArr[sharkNum][curDir];

			// 2가지 케이스
			for (int k = 0; k < 2; k++)
			{
				// k = 0, 냄새 없는 위치 찾기
				// k = 1, 내 냄새 위치 찾기

				bool isSuccess = false;
				for (int i = 0; i < 4; i++)
				{
					int nextDir = priorityVec[i];
					int nextR = curR + dRow[nextDir];
					int nextC = curC + dCol[nextDir];

					if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N)
						continue;

					// 냄새 없는 곳 찾을 때
					if (k == 0 && smell[nextR][nextC].second != 0)
						continue;

					// 내 냄새 찾을 때
					if(k == 1 && smell[nextR][nextC].first != sharkNum)
						continue;

					sharkVec[sharkNum] = { nextR, nextC, nextDir };
					isSuccess = true;
					break;
				}

				// 찾으면 탈출
				if (isSuccess)
					break;
			}
		}

		// 2. 냄새 지속 시간 감소
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				// 냄새 없는 곳 제외
				if (smell[r][c].second <= 0) continue;

				// 냄새 지속 시간 감소
				smell[r][c].second--;
			}
		}

		// 3. 냄새 뿌리기
		for (int sharkNum = 1; sharkNum <= M; sharkNum++)
		{
			int curR = get<0>(sharkVec[sharkNum]);
			int curC = get<1>(sharkVec[sharkNum]);
			int curDir = get<2>(sharkVec[sharkNum]);
			// 죽은 상어 제외
			if (curR == -1 || curC == -1 || curDir == -1) continue;

			// 냄새 아예 없는 경우, 내 냄새인 경우
			if (smell[curR][curC].second == 0 || smell[curR][curC].first == sharkNum)
			{
				smell[curR][curC] = { sharkNum, K };
			}
			else //  냄새 있는데, 남의 냄새인 경우
			{
				// == 위치가 겹친다는 얘기
				// == 겹친놈 중 num 큰 놈 죽음
				const int otherSharkNum = smell[curR][curC].first;
				
				// 이긴 놈의 냄새 덮음
				const int  winnerSharkNum = min(sharkNum, otherSharkNum);
				smell[curR][curC] = { winnerSharkNum, K};

				// 진 놈 vec에 표시
				const int  loserSharkNum = max(sharkNum, otherSharkNum);
				sharkVec[loserSharkNum] = { -1,-1,-1 };

				// 상어 개수 감소
				sharkCnt--;
			}
		}

		tick++;

		cout << "상어 이동 후 : " << '\n';
		printBoard(sharkVec, smell);
	}

	cout << tick;

	return 0;
}

void printBoard(vector<tuple<int, int, int>> curSharkVec, const pair<int, int> smell[][25])
{
	cout << "상어 : " << '\n';
	for (auto& shark : curSharkVec)
	{
		int r = get<0>(shark);
		int c = get<1>(shark);
		int dir = get<2>(shark);
		if (r == -1 || c == -1 || dir == -1) continue;

		cout << r << " " << c << " " << dir << '\n';
	}
	cout << '\n';

	cout << "냄새 위치 : " << '\n';
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cout << "(" << smell[r][c].first << "," << smell[r][c].second << ") ";
		}
		cout << '\n';
	}
	cout << '\n';
}
