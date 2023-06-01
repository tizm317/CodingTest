#include <iostream>
#include <stack>
#include <queue>
#include <utility> // pair
using namespace std;

// ���� ���� Ǯ��
// ��¥		: 2023. 05. 09. ȭ
// ���� ��ȣ	: #2493 
// ���� �̸�	: ž
// �˰���	: 
// �ð����⵵: O()

#define HEIGHT first
#define IDX second

int N;
stack<pair<int, int>> S;
//queue<int> temp;
int building[500005];

pair<int, int> isUsed[500005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ž ���� �Է�
	cin >> N;

	// N��
	// �ִ�
	// 0��, 1��, 2��, ... N-1��
	// N * (N-1)/2
	// O(N^2) -> X

	// pair<int, int> �� ���� ��ġ �����ϸ� �ɰ� ������...

	// ���� ���� ���� ū ������ �ε����� ���� ����
	// ���ߴµ�, �� ������ ���� �������� ũ�ٸ� -> ����
	// �۴ٸ� -> �� �������� ū ������ �־�� ����
	//  6 9  5 7 4
	// -1 -1 1 1 2

	for (int i = 0; i < N; i++)
	{
		cin >> building[i];
	}

	// ������
	isUsed[0] = { building[0], -1 };
	cout << isUsed[0].IDX + 1 << " ";

	//S.push({ building[0], -1 });
	//cout << S.top().second + 1 << " ";

	// index�� ���� �򰥸��� �Ǿ���;; <<<<<<<<<<<<<<<<<<<<<<< ���� �ʿ�!

	for (int i = 1; i < N; i++)
	{
		//pair<int, int> prev = S.top();
		pair<int, int> prev = isUsed[i - 1];
		int curIdx = i - 1;

		while (true)
		{
			// ���� ����(i - 1)�� ���� ����(i)���� ū ���
			if (prev.HEIGHT > building[i])
			{
				isUsed[i] = { building[i], curIdx};
				cout << curIdx + 1<< " ";
				break;

				//S.push({ building[i], i - 1 }); // �ε���	
				//cout << i << " ";				// ����(�ε��� + 1)
			}

			// �� �������� ū ������ ���� ���
			if (prev.IDX == -1)
			{
				isUsed[i] = { building[i], -1 };
				cout << 0 << " ";
				break;
			}

			// ���� ���, �� �������� ū ���� IDX
			curIdx = prev.IDX;
			prev = isUsed[curIdx];
		}
		
	}

	return 0;
}