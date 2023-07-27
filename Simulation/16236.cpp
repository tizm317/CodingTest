#include <iostream>
#include <utility>
#include <queue>
using namespace std;

// ���� ���� Ǯ��
// ��¥		: 2023. 07. 27. ��
// ���� ��ȣ	: #16236 
// ���� �̸�	: �Ʊ� ���
// �˰���	: �ùķ��̼�, BFS
// �ð����⵵: O()

int N; // <= 20
int aquarium[25][25];

// �Ʊ� ��� ��ġ�� ������ ���� ��� ����
pair<int, int> babySharkPos;
int babySharkSize = 2; // (����)

// ���� ����� �� (����ġ)
int eatCnt;

// ����� ��ƸԴ� �ð�
int t;

// BFS ��
int dist[25][25];
const int dRow[4] = { -1, 0, 1, 0 };
const int dCol[4] = { 0, 1, 0, -1 };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ����Ƹ��� ��ġ�� �Է�
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

			// �Ʊ� ��� ��ġ�� ���� ��� ���� (�迭���� ���� ��)
			//if (aquarium[r][c] == 9) babySharkPos = { r,c };
		}
	}

	// �� �̻� ���� �� ���� ������ �ݺ�
	while (true)
	{
		// dist �迭 �ʱ�ȭ
		for (int r = 0; r < N; r++)
			fill(&dist[r][0], &dist[r][25], -1);

		// ���� ��ġ ť�� ����, dist = 0 �ʱ�ȭ
		queue<pair<int, int>> Q;
		Q.push(babySharkPos);
		dist[babySharkPos.first][babySharkPos.second] = 0;

		// �ִܰŸ� �ʱ�ȭ
		int min_dist = N * N;

		// 1. BFS ���鼭 ���� �� �ִ� �������� �Ÿ� ���
		while (!Q.empty())
		{
			// �Ʊ� ��� ���� ��ġ
			pair<int, int> curPos = Q.front(); Q.pop();

			// ���� ��ġ
			for (int dir = 0; dir < 4; dir++)
			{
				int nRow = curPos.first + dRow[dir];
				int nCol = curPos.second + dCol[dir];

				// �迭 ����
				if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
					continue;

				// ��湮 ����
				if (dist[nRow][nCol] != -1)
					continue;

				// ����⺸�� ������ �̵� �Ұ�
				if (babySharkSize < aquarium[nRow][nCol])
					continue;

				// ť�� �ְ�, dist ���
				Q.push({ nRow, nCol });
				dist[nRow][nCol] = dist[curPos.first][curPos.second] + 1;

				// ��ĭ �ƴ� �� �߿�, ���� �� �ִ� ����� ���� �ִܰŸ� ���� !!!
				if (aquarium[nRow][nCol] != 0 &&  aquarium[nRow][nCol] < babySharkSize)
				{
					min_dist = min(min_dist, dist[nRow][nCol]);
				}
			}
		}

		// 2. �ִܰŸ��� �ִ� ����� �Դ� ����

		// ������ �� �ִ��� üũ�ϱ� ���� bool ����
		bool isMoved = false;
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				// ����� ���� �� pass
				if (aquarium[r][c] == 0)
					continue;

				// �� �� ���� �� pass
				if (dist[r][c] == -1)
					continue;

				// ���� �� ���� ����� pass (�Ʊ� ���� �۾ƾ� ��)
				if (babySharkSize <= aquarium[r][c])
					continue;

				// �ִܰŸ��� ����� 
					//(for�� ���� ������ �»��->���ϴ� �̱� ������ �ִܰŸ� ���������� �� ���� �˾Ƽ� ������)
				if (min_dist == dist[r][c]) ///////////////////////////////////////////
				{
					// �̵������� ǥ��
					isMoved = true;
					
					// �̵� �� ��ġ �����ְ�
					//aquarium[babySharkPos.first][babySharkPos.second] = 0;
					
					// �̵� �� ��ġ�� ǥ�����ְ�
					babySharkPos = { r,c };
					//aquarium[r][c] = 9;
					aquarium[r][c] = 0; // ������

					// �̵� �ð� ������
					t += dist[r][c];

					// ���� ����� ī����
					eatCnt++;

					// �ڱ� ũ��� ���� ���� ���� ������, ũ�� 1 ����
					if (eatCnt == babySharkSize)
					{
						babySharkSize++;

						// ����ġ �ʱ�ȭ
						eatCnt = 0;
					}

					break;
				}
			}
			if (isMoved) break;
		}

		// �� �̻� ���� �� ������ ��
		if (!isMoved) break;
	}

	// �ð� ���
	cout << t;

	return 0;
}