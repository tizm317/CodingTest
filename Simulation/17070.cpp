#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// 백준 문제 풀이
// 날짜		: 20xx. xx. xx.
// 문제 번호	: #00000 
// 문제 이름	: 
// 알고리즘	: 
// 시간복잡도: O()

int N; // <= 16
int room[20][20]; // 0 빈칸, 1 벽

int ans;

// dir : 0 가로, 1 세로, 2 대각선
bool finish = false;
void move(vector<pair<int,int>> pipe, int dir)
{
	if (ans == 1'000'000)
	{
		finish = true;
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		if (pipe[i].first < 0 || pipe[i].first >= N || pipe[i].second < 0 || pipe[i].second >= N || room[pipe[i].first][pipe[i].second] == 1)
			return;

		// 대각선일 때 범위
		if (dir == 2)
		{
			int r = pipe[0].first;
			int c = pipe[0].second;
			if (room[r][c + 1] == 1 || room[r + 1][c] == 1)
				return;
		}

		if (pipe[i].first == N - 1 && pipe[i].second == N - 1)
		{
			ans++;
			return;
		}
	}

	//vector<pair<int, int>> pipe = pipe;

	if (dir == 0)
	{
		// 가로
		for (auto& p : pipe)
		{
			p.second++;
		}
		move(pipe, dir);
		if (finish) return;
		//for (auto& p : pipe)
		//{
		//	p.second--;
		//}

		// 대각선
		//pipe[0].second++;
		//pipe[1].first++; pipe[1].second++;
		pipe[1].first++;
		move(pipe, 2);
		if (finish) return;
		pipe[1].first--;
		for (auto& p : pipe)
		{
			p.second--;
		}
		//pipe[0].second--;
		//pipe[1].first--; pipe[1].second--;
	}
	else if (dir == 1)
	{
		// 세로
		for (auto& p : pipe)
		{
			p.first++;
		}
		move(pipe, dir);
		if (finish) return;
		//for (auto& p : pipe)
		//{
		//	p.first--;
		//}

		// 대각선
		//pipe[0].first++;
		//pipe[1].first++; pipe[1].second++;
		pipe[1].second++;
		move(pipe, 2);
		if (finish) return;
		pipe[1].second--;
		for (auto& p : pipe)
		{
			p.first--;
		}
		//pipe[0].first--;
		//pipe[1].first--; pipe[1].second--;
	}
	else
	{
		// 가로
		pipe[0].first++; pipe[0].second++;
		pipe[1].second++;
		move(pipe, 0);
		if (finish) return;
		//pipe[0].first--; pipe[0].second--;
		//pipe[1].second--;

		// 대각선
		//pipe[0].first++; pipe[0].second++;
		//pipe[1].first++; pipe[1].second++;
		pipe[1].first++;
		move(pipe, dir);
		if (finish) return;

		// 세로
		//pipe[0].first++; pipe[0].second++;
		//pipe[1].first++;
		pipe[1].second--;
		move(pipe, 1);
		//if (finish) return;
		//pipe[0].first--; pipe[0].second--;
		//pipe[1].first--;


	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cin >> room[r][c];
		}
	}

	// 꼼수 같은데???????????????????????? 마지막 테케가 이거인듯?
	if (room[N - 1][N - 1] == 1)
	{
		cout << 0;
		return 0;
	}

	//pair<int, int> pipe[2] = { {0,0}, {0,1} };
	vector<pair<int, int>> pipe;
	pipe.push_back({ 0,0 });
	pipe.push_back({ 0,1 });

	move(pipe, 0);

	cout << ans;

	return 0;
}