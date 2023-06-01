#include <iostream>
#include <string>
#include <utility>
#include <queue>
using namespace std;

// ���� ���� Ǯ��
// ��¥		: 2023. 05. 18. ��
// ���� ��ȣ	: #1941 
// ���� �̸�	: �ҹ��� ĥ����
// �˰���	: 
// �ð����⵵: O()

#define ROW first
#define second COL

// �� �� (�� ��)
int dRow[2] = { 0, 1 };//, 0, -1};
int dCol[2] = { 1, 0 };//, -1, 0};

int students[5][5]; // S : 0 , Y : 1
bool isused[5][5];

int yCnt; // �ӵ����� ���� ( <= 3)
int ans;


// �Ķ���Ͱ� 7���� ���� ����
void func(int r, int c, int cnt)
{
	if (cnt == 7)
	{
		ans++;
		//cout << "7���� �޼�" << '\n';
		return;
	}

	// ���� ��ġ
	for (int dir = 0; dir < 2; dir++)
	{
		int nRow = r + dRow[dir];
		int nCol = c + dCol[dir];

		// �迭 ���� ����� ��� X
		if (nRow < 0 || nRow >= 5 || nCol < 0 || nCol >= 5)
			continue;

		// �̹� ���Ե� ���
		if (isused[nRow][nCol])
			continue;

		// Y �ӵ����� �Ҵ緮 �� ä�� ��� X
		if (students[nRow][nCol] == 1 && yCnt == 3)
			continue;

		// Y �ӵ����� <= 3
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

	// ������
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			isused[r][c] = true;
			
			// Y �ӵ����� <= 3
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
	-> ù��° ���̽��� ��� ó������(�ߺ��Ǵ� ��� �־���) (�̰͵� ���� ��������)
	-> �ι�°�� ��� �ϳİ�!!
	->	BFS??? ��/��/��+�� ? ť�� ����??

*/