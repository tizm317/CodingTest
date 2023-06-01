#include <iostream>
#include <utility> 
#include <stack>

using namespace std;

#define ROW first
#define COL second

// ��, �� ũ��
const int r = 7, c = 10;

const int board[502][502] =
{
	{1,1,1,0,1,0,0,0,0,0},
	{1,0,1,0,1,0,0,0,0,0},
	{1,1,1,0,1,0,0,0,0,0},
	{1,1,0,0,1,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
}; // 1�� �Ķ� ĭ, 0�� ���� ĭ�� ����

int visit[502][502]; // 1 : �湮 ���� üũ

const int dRow[4] = {0, 1, 0, -1};
const int dCol[4] = {1, 0, -1, 0};

stack<pair<int, int>> S;

int main()
{
	// ������ (0, 0)
	S.push({ 0,0 });
	visit[0][0] = 1;

	while (!S.empty())
	{
		pair<int, int> curPos = S.top(); S.pop();

		cout << "(" << curPos.ROW << ", " << curPos.COL << ") ";

		for (int dir = 0; dir < 4; dir++)
		{
			int nRow = curPos.ROW + dRow[dir];
			int nCol = curPos.COL + dCol[dir];

			if (nRow < 0 || nRow >= r || nCol < 0 || nCol >= c)
				continue;

			if (visit[nRow][nCol] == 1)
				continue;

			if (board[nRow][nCol] == 0)
				continue;

			S.push({ nRow, nCol });
			visit[nRow][nCol] = 1;
		}
	}

	return 0;
}
