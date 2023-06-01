#include <iostream>
#include <utility>
#include <queue>
using namespace std;

// ���� ���� Ǯ��
// ��¥		: 2023. 05. 24. ��
// ���� ��ȣ	: #5427 
// ���� �̸�	: ��
// �˰���	: BFS
// �ð����⵵: O()

#define ROW first
#define COL second

// �����¿�
const int dRow[4] = { -1,0,1,0 };
const int dCol[4] = { 0,1,0,-1 };

int T;
int w, h;

// �̵� ���� ���� �迭
// 1 (��,�� = �̵��Ұ�) , 0 ����� 2 ���  �̵�����
int maze[1000][1000];

// �湮 ���� �迭
int visit[1000][1000];
int dist[1000][1000];

// �湮�� �� ��� ť
queue<pair<int, int>> Q;

// ��� ���� ��ġ
pair<int, int> startPos;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		// ���ɺ���, �迭 �ʱ�ȭ
		for (int r = 0; r < 1000; r++)
		{
			fill(maze[r], maze[r] + 1000, 0);
			fill(visit[r], visit[r] + 1000, 0);
			fill(dist[r], dist[r] + 1000, 0);
		}

		cin >> w >> h;

		// �̷�(����) �Է�
		for (int r = 0; r < h; r++)
		{
			string s;
			cin >> s;

			// int�� ����
			for (int c = 0; c < w; c++)
			{
				const char& ch = s[c];
				switch (ch)
				{
				case '#':
					maze[r][c] = 1; // ��
					break;
				case '*':
					maze[r][c] = 1; // ��

					// �� ���� �̵�
					Q.push({ r, c });
					//visit[r][c] = 1;
					break;
				case '@':
					maze[r][c] = 2; // ��� ���� ��ġ

					startPos = { r,c };
					
					break;
				case '.':
					maze[r][c] = 0; // �� ����
					break;
				}

			}
		}

		//
		// ���� �������� ĭ���� �̵��� �� ���� => ���� ���� �̵�
		// ���������� ����� ��ġ ����
		Q.push(startPos);
		dist[startPos.ROW][startPos.COL] = 1;
		//visit[startPos.ROW][startPos.COL] = 1;

		// ���� ��ġ�� Ż�ⱸ�� ���
		// �ٷ� Ż��
		if (startPos.ROW == 0 || startPos.ROW == h - 1 || startPos.COL == 0 || startPos.COL == w - 1)
		{
			cout << 1 << '\n';

			// break �ƴϰ� continue!!!
			continue;
		}

		// ���� �̵��ϴ� ���� ����̰� �̵��ϴ� ��� case �и��� �߿��ϴ�!!!!
		// ���� ���� �̵��ؾ��ؼ�, �̵� �� ���� ��ġ�� �̵� �� ������� ��ġ�� ��ġ�� ���� �߿� ����Ʈ!
		// 4179������ ����!

		bool success = false;
		while (!Q.empty())
		{
			// ���� ��ġ
			pair<int, int> curPos = Q.front(); Q.pop();
			visit[curPos.ROW][curPos.COL] = 1;

			// ����� �̵��ϴ� ��� : Ż�ⱸ ���� üũ
			if (maze[curPos.ROW][curPos.COL] >= 2 && ( curPos.ROW == 0 || curPos.ROW == h - 1 || curPos.COL == 0 || curPos.COL == w - 1))
			{
				cout << dist[curPos.ROW][curPos.COL] << '\n';
				success = true;
				break;
			}

			for (int dir = 0; dir < 4; dir++)
			{
				// ���� ��ġ
				int nRow = curPos.ROW + dRow[dir];
				int nCol = curPos.COL + dCol[dir];

				// �̷� �迭 ����(w,h) �Ѿ���� üũ
				if (nRow < 0 || nRow >= h || nCol < 0 || nCol >= w)
					continue;

				// ���̳� ������ üũ(��,�� 1 / �̵��� ��+�̵��� ��� 3)
				if (maze[nRow][nCol] == 1 || maze[nRow][nCol] == 3)
					continue;

				// ���� �湮�ߴ��� üũ
				if (visit[nRow][nCol] == 1)
					continue;

				// ���� ��ġ ť�� ����
				Q.push({ nRow, nCol });
				//visit[nRow][nCol] = 1;

				// ���� �����̴� ���(ť�� �ִ� ���� maze���� 1�̸� '��' // ���� ť�� ������)
				// �ݷ�:
				// *@ �ΰ��
				// ���� ���� �������� @�� maze ���� 1�̵�..

				// 1. ���� �����̴� ���
				// -> ���� ���� �����̰�, ���� ��ġ�� ��,�� �ƴ� ���(0,2)
				if (maze[curPos.ROW][curPos.COL] == 1 && (maze[nRow][nCol] == 0 || maze[nRow][nCol] == 2))
					maze[nRow][nCol] += 1;

				// 2. ����� �����̴� ���
				// ��� ȥ��(2) , ���(�̵���) + ��(�̵���) = 3
				if (maze[curPos.ROW][curPos.COL] >= 2)
				{
					// ���� ��ġ 2
					maze[nRow][nCol] = 2;

					dist[nRow][nCol] = dist[curPos.ROW][curPos.COL] + 1;
				}
			}

			// ����� ��� �̵�(�����¿�) ���̽� ���� �� �� �� ��ġ���� ����
			// �����¿� �� try �� �Ŀ� ����
			if (maze[curPos.ROW][curPos.COL] >= 2)
			{
				// ���� ��ġ -2
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