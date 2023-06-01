#include <iostream>
using namespace std;

// 백준 문제 풀이
// 날짜		: 2023. 05. 03. 수
// 문제 번호	: #15683 
// 문제 이름	: 감시
// 알고리즘	: 
// 시간복잡도: O()

int N, M;
int map[8][8];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cin >> map[r][c];
		}
	}

	// 0 : 빈공간 / 6 : 벽
	// 1 : 1방향 -> 경우의 수 4개
	// 2 : 2방향 , 반대 -> 경우의 수 2개
	// 3 : 2방향 , 직각 -> 경우의 수 4개
	// 4 : 3방향 -> 경우의 수 4개
	// 5 : 4방향 -> 경우의 수 1개

	return 0;
}