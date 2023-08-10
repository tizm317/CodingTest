#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;

// ���� ���� Ǯ��
// ��¥		: 2023. 08. 10. ��
// ���� ��ȣ	: #19237
// ���� �̸�	: � ���
// �˰���	: �ùķ��̼�
// �ð����⵵: O()

int N; // <= 20
vector<tuple<int, int, int>> sharkVec; // {r,c, dir}
pair<int, int> smell[25][25]; // {��� ��ȣ, �����ð�}

int M; // <= 400
// [���][����]
vector<int> sharkMovePriorityArr[405][4];

int K; // <= 1000

// �����¿�
const int dRow[4] = { -1, 1, 0, 0 };
const int dCol[4] = { 0, 0, -1, 1 };

void printBoard(vector<tuple<int, int, int>> curSharkVec, const pair<int, int> smell[][25]);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> tempVec;

	cin >> N >> M >> K;

	// �ʱ�ȭ
	sharkVec = vector<tuple<int, int, int>>(M + 1);
	for (auto& shark : sharkVec)
	{
		shark = { -1,-1,-1 };
	}

	// ��� ��ġ �迭 �Է�
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

	// ��� �ʱ� ���� �Է�
	for (int sharkNum = 1; sharkNum <= M; sharkNum++)
	{
		int d;
		cin >> d;

		get<2>(sharkVec[sharkNum]) = d - 1;
	}

	// ��� ���� �켱���� �迭 �Է�
	for (int sharkNum = 1; sharkNum <= M; sharkNum++)
	{
		// �����¿� ����
		for (int d = 0; d < 4; d++)
		{
			// �켱���� ���� 4�� �Է�
			for (int t = 0; t < 4; t++)
			{
				int dir;
				cin >> dir;

				sharkMovePriorityArr[sharkNum][d].push_back(dir - 1);
			}
		}
	}

	cout << "�ʱ� ���� : " << '\n';
	printBoard(sharkVec, smell);

	int tick = 0;
	int sharkCnt = M;
	while (true)
	{
		// ��� 1����(1�� �� ����) ����
		if (sharkCnt == 1)
			break;

		// ��, 1,000�ʰ� �Ѿ �ٸ� �� ���ڿ� ���� ������ -1�� ����Ѵ�.
			// �� 1000�� �̻� �ΰ���? �ʰ��� �ƴϰ�..
			// �³�! 1���� ������ sharkCnt üũ�ϸ� -> 1�� ���� �� ���� ��� ��
			// �׷��� 1000���� ������ üũ�ϸ� -> 1000�� ���� �� ���� ��� ��!
			// ����, tick >= 1000 �� ����
			// tick > 1000 ���� �ϸ�, 1001�� ���� �� üũ�ϴ� ��� �� �̱� ������ Ʋ��!!
		if (tick >= 1000) // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		{
			tick = -1;
			break;
		}

		// 1. ��� �̵�
		for(int sharkNum = 1; sharkNum <= M; sharkNum++)
		{
			int curR = get<0>(sharkVec[sharkNum]);
			int curC = get<1>(sharkVec[sharkNum]);
			int curDir = get<2>(sharkVec[sharkNum]);
			// ���� ��� ����
			if (curR == -1 || curC == -1 || curDir == -1) continue;

			const vector<int>& priorityVec = sharkMovePriorityArr[sharkNum][curDir];

			// 2���� ���̽�
			for (int k = 0; k < 2; k++)
			{
				// k = 0, ���� ���� ��ġ ã��
				// k = 1, �� ���� ��ġ ã��

				bool isSuccess = false;
				for (int i = 0; i < 4; i++)
				{
					int nextDir = priorityVec[i];
					int nextR = curR + dRow[nextDir];
					int nextC = curC + dCol[nextDir];

					if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N)
						continue;

					// ���� ���� �� ã�� ��
					if (k == 0 && smell[nextR][nextC].second != 0)
						continue;

					// �� ���� ã�� ��
					if(k == 1 && smell[nextR][nextC].first != sharkNum)
						continue;

					sharkVec[sharkNum] = { nextR, nextC, nextDir };
					isSuccess = true;
					break;
				}

				// ã���� Ż��
				if (isSuccess)
					break;
			}
		}

		// 2. ���� ���� �ð� ����
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				// ���� ���� �� ����
				if (smell[r][c].second <= 0) continue;

				// ���� ���� �ð� ����
				smell[r][c].second--;
			}
		}

		// 3. ���� �Ѹ���
		for (int sharkNum = 1; sharkNum <= M; sharkNum++)
		{
			int curR = get<0>(sharkVec[sharkNum]);
			int curC = get<1>(sharkVec[sharkNum]);
			int curDir = get<2>(sharkVec[sharkNum]);
			// ���� ��� ����
			if (curR == -1 || curC == -1 || curDir == -1) continue;

			// ���� �ƿ� ���� ���, �� ������ ���
			if (smell[curR][curC].second == 0 || smell[curR][curC].first == sharkNum)
			{
				smell[curR][curC] = { sharkNum, K };
			}
			else //  ���� �ִµ�, ���� ������ ���
			{
				// == ��ġ�� ��ģ�ٴ� ���
				// == ��ģ�� �� num ū �� ����
				const int otherSharkNum = smell[curR][curC].first;
				
				// �̱� ���� ���� ����
				const int  winnerSharkNum = min(sharkNum, otherSharkNum);
				smell[curR][curC] = { winnerSharkNum, K};

				// �� �� vec�� ǥ��
				const int  loserSharkNum = max(sharkNum, otherSharkNum);
				sharkVec[loserSharkNum] = { -1,-1,-1 };

				// ��� ���� ����
				sharkCnt--;
			}
		}

		tick++;

		cout << "��� �̵� �� : " << '\n';
		printBoard(sharkVec, smell);
	}

	cout << tick;

	return 0;
}

void printBoard(vector<tuple<int, int, int>> curSharkVec, const pair<int, int> smell[][25])
{
	cout << "��� : " << '\n';
	for (auto& shark : curSharkVec)
	{
		int r = get<0>(shark);
		int c = get<1>(shark);
		int dir = get<2>(shark);
		if (r == -1 || c == -1 || dir == -1) continue;

		cout << r << " " << c << " " << dir << '\n';
	}
	cout << '\n';

	cout << "���� ��ġ : " << '\n';
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
