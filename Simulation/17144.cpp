#include <iostream>
#include <utility>
//#include <queue>
#include <vector>
using namespace std;

// ���� ���� Ǯ��
// ��¥		: 2023. 07. 31. ��
// ���� ��ȣ	: #17144 
// ���� �̸�	: �̼����� �ȳ�!
// �˰���	: �ùķ��̼�, BFS
// �ð����⵵: O()

int R, C;
int room[55][55];

int T;

const int dRow[4] = { -1, 0, 1, 0 };
const int dCol[4] = { 0, 1, 0, -1 };

//vector<pair<int, int>> microdustVec;
//queue<pair<int, int>> Q;
int dist[55][55];

vector<pair<int, int>> airCleaner;


// �̼����� Ȯ�� BFS
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

			// ���� ��ġ�� �̼����� ��
			//const int dust = room[microdust.first][microdust.second];
			const int dust = room[r][c];

			// ������ �̼����� �� ���
			const int diffuseDust = dust / 5;

			// 0 ���ϸ� ������ �ǹ� �����Ƿ� pass
			if (diffuseDust <= 0) continue;

			// �����¿� ������ ����
			for (int dir = 0; dir < 4; dir++)
			{
				//int nRow = microdust.first + dRow[dir];
				int nRow = r + dRow[dir];
				//int nCol = microdust.second + dCol[dir];
				int nCol = c + dCol[dir];

				// �迭 ���� ������ X
				if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C)
					continue;

				// ����û���� ��ġ X
				if (room[nRow][nCol] == -1)
					continue;

				// ������ŭ ���� ��ġ �̼����� ����
				//room[microdust.first][microdust.second] -= diffuseDust;
				room[r][c] -= diffuseDust;

				// '���Ӱ�' ���� ��ġ�� ���Ϳ� �߰��� (�̹� �ִ� ��ġ�� �߰��ϸ� ������ ������ ��)
				// ���� �̼����� ���� ���̸鼭 ���� ���� ��쿡�� 1���� �߰��ϱ� ���� ���� <<<<<<<<<<<<<<<<<<<<<<<<<,,
				//if (room[nRow][nCol] == 0 && room2[nRow][nCol] == 0)
				//{
				//	microdustVec.push_back({ nRow, nCol });
				//}


				// �ٸ� �迭�� ���� �̼����� �� ������
				room2[nRow][nCol] += diffuseDust;
			}
		}
	}
	

	//cout << '\n';
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			// ���� Ȯ��� �� �߰�
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
	// ���� ����û���� : �ݽð�
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

	// �Ʒ��� ����û���� : �ð�
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

	// ����û����� ������ ��ȭ��

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

	// �� ���� �迭 �Է�
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

	// 0. T�� �ݺ�
	while (T--)
	{
		// 1. �̼����� Ȯ��
		microdustDiffuse();

		// 2. ����û���� �۵�
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