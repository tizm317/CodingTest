#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// ���� ���� Ǯ��
// ��¥		: 2023. 07. 25. ȭ.
// ���� ��ȣ	: #16234 
// ���� �̸�	: �α� �̵�
// �˰���	: �ùķ��̼�, BFS
// �ð����⵵: O()

int N; // <= 50
int map[55][55];

int L, R;

queue<pair<int, int>> Q;

const int dRow[4] = { -1, 0, 1, 0 };
const int dCol[4] = { 0, 1, 0, -1 };

// �α��̵�
void migration(int days);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �α����� �Է�
	cin >> N >> L >> R;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> map[r][c];

	migration(0);

	return 0;
}

void migration(int days)
{
	// vis �迭 �ʱ�ȭ
	bool vis[55][55] = { false, };

	// ������ �̷������� üũ�ϱ� ���� bool ����
	bool isCountryUnite = false;

	// ���� ���� ã��
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			// �̹� �湮�� �� pass
			if (vis[r][c])
				continue;

			// ť�� �ְ�, �湮 ǥ��
			Q.push({ r,c });
			vis[r][c] = true;

			// ���� ���� ���� -> �ؿ��� �α��� ����ϱ� ���� ����
			vector<pair<int, int>> countryVec;
			countryVec.push_back({ r,c });

			// ������ �α��� ���� ��� ����
			int countryPeopleCnt = map[r][c];

			// BFS ���鼭 ���� ������ ���� ã��
			while (!Q.empty())
			{
				// ���� ��ġ
				pair<int, int> curPos = Q.front(); Q.pop();

				// ���� ��ġ ���
				for (int dir = 0; dir < 4; dir++)
				{
					int nRow = curPos.first + dRow[dir];
					int nCol = curPos.second + dCol[dir];

					// �迭 ���� üũ
					if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
						continue;

					// �湮 ���� üũ
					if (vis[nRow][nCol])
						continue;

					// ���� �������� �α��� ���� ��� �� ���� L,R üũ
					const int diff = abs(map[curPos.first][curPos.second] - map[nRow][nCol]);
					if (diff < L || diff > R)
						continue;

					// ���� ������ ����
					// ť�� �߰��ϰ�, �湮 ǥ��
					Q.push({ nRow, nCol });
					vis[nRow][nCol] = true;

					// ���ձ��� ���Ϳ��� �߰��ϰ�, ������ ������ �߻����� ǥ��
					countryVec.push_back({ nRow, nCol });
					countryPeopleCnt += map[nRow][nCol]; // ������ �α��� ���� ��� <<<<<<<
					isCountryUnite = true;
				}
			}

			const int countryCnt = countryVec.size();

			// ���� �α��� ��� >>>>>>>>>>>>>>>>>>> ���Ϳ� �־��� �� ����ϸ�, �ߺ��ؼ� for�� �� ������ �ǰ� ����.
			//int countryPeopleCnt = 0;
			//for (auto x : countryVec)
			//{
			//	pair<int, int> curPos = x;
			//	countryPeopleCnt += map[curPos.first][curPos.second];
			//}

			// ������ ���ο� �α��� ����
			const int newPeopleCnt = countryPeopleCnt / countryCnt;
			for (auto x : countryVec)
			{
				map[x.first][x.second] = newPeopleCnt;
			}
		}
	}

	// ���� �̷�������, migration �Լ� ȣ��
	if (isCountryUnite)
		migration(days + 1);
	else // ���� ��������, �α� �̵� ��ĥ ���� �̷������� ��� �ϰ� return
		cout << days;
}