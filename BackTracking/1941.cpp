#include <iostream>
#include <string>
#include <utility>
#include <queue>
using namespace std;

// 백준 문제 풀이
// 날짜		: 2023. 05. 18. 목
// 문제 번호	: #1941 
// 문제 이름	: 소문난 칠공주
// 알고리즘	: 
// 시간복잡도: O()

#define ROW first
#define second COL

// 우 하 (좌 상)
int dRow[2] = { 0, 1 };//, 0, -1};
int dCol[2] = { 1, 0 };//, -1, 0};

int students[5][5]; // S : 0 , Y : 1
bool isused[5][5];

int yCnt; // 임도연파 숫자 ( <= 3)
int ans;


// 파라미터가 7공주 선택 개수
void func(int r, int c, int cnt)
{
	if (cnt == 7)
	{
		ans++;
		//cout << "7공주 달성" << '\n';
		return;
	}

	// 다음 위치
	for (int dir = 0; dir < 2; dir++)
	{
		int nRow = r + dRow[dir];
		int nCol = c + dCol[dir];

		// 배열 범위 벗어나는 경우 X
		if (nRow < 0 || nRow >= 5 || nCol < 0 || nCol >= 5)
			continue;

		// 이미 포함된 경우
		if (isused[nRow][nCol])
			continue;

		// Y 임도연파 할당량 다 채운 경우 X
		if (students[nRow][nCol] == 1 && yCnt == 3)
			continue;

		// Y 임도연파 <= 3
		if (students[nRow][nCol] == 1)
			yCnt++;

		isused[nRow][nCol] = true;

		func(nRow, nCol, cnt + 1);

		if (students[nRow][nCol] == 1)
			yCnt--;

		isused[nRow][nCol] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; i++)
	{
		string str;
		getline(cin, str);
		for (int j = 0; j < 5; j++)
		{
			if (str[j] == 'S')
			{
				students[i][j] = 0;
			}
			else // 'Y'
			{
				students[i][j] = 1;
			}
		}
	}

	// 시작점
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			isused[r][c] = true;
			
			// Y 임도연파 <= 3
			if (students[r][c] == 1)
				yCnt++;

			queue<pair<int, int>> q;
			q.push({ r,c });

			func(q, 1);
			//func(r, c, 1);
			
			if (students[r][c] == 1)
				yCnt--;

			isused[r][c] = false;
		}
	}

	cout << ans;

	return 0;
}


/*
	.....    .....
	SYSYS    SYSYS
	....Y    .Y...
	....S    .S...
	.....    .....
	-> 첫번째 케이스는 어떻게 처리했음(중복되는 경우 있었음) (이것도 문제 있을수도)
	-> 두번째는 어떻게 하냐고!!
	->	BFS??? 우/하/우+하 ? 큐로 보내??

*/