#include <iostream>
using namespace std;

// ���� ���� Ǯ��
// ��¥		: 2023. 05. 03. ��
// ���� ��ȣ	: #15683 
// ���� �̸�	: ����
// �˰���	: 
// �ð����⵵: O()

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

	// 0 : ����� / 6 : ��
	// 1 : 1���� -> ����� �� 4��
	// 2 : 2���� , �ݴ� -> ����� �� 2��
	// 3 : 2���� , ���� -> ����� �� 4��
	// 4 : 3���� -> ����� �� 4��
	// 5 : 4���� -> ����� �� 1��

	return 0;
}