//#include <iostream>
//#include <queue>
//#include <utility>
//#include <deque>
//#include <tuple> // tie
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 21. ��
//// ���� ��ȣ	: #3190 
//// ���� �̸�	: ��
//// �˰���	: �ùķ��̼�, deque, queue
//// �ð����⵵: O()
//
//// ����
//int N; // <= 100
//int board[105][105]; // 0 ��ĭ, 1 ��, 2 ���
//
//// ��� ����
//int K; // 0 <= <= 100
//
//// ���� ��ȯ Ƚ��
//int L;
//
//// ���� ��ȯ ��� ��� ť
//queue<pair<int, char>> Q; // {�ð�, ����}
//
//// �� ��� ��
//deque<pair<int, int>> dq_snake;
//
//// ��,��,��,��
//const int dRow[4] = {-1, 0, 1, 0};
//const int dCol[4] = {0, 1, 0, -1};
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ��� ��ġ
//	cin >> N >> K;
//	for (int a = 0; a < K; a++)
//	{
//		int r, c;
//		cin >> r >> c;
//
//		board[r - 1][c - 1] = 2;
//	}
//
//	// ���� ��ȯ
//	cin >> L;
//	for (int d = 0; d < L; d++)
//	{
//		int t;
//		char dir;
//		cin >> t >> dir;
//
//		Q.push({ t, dir });
//	}
//
//	// ���� ����
//	// �� ���� ��ġ  {0,0} ���� �ְ�, �����ǿ� ǥ��
//	dq_snake.push_back({ 0,0 });
//	board[0][0] = 1;
//
//	// �� ���� ���� ���� 1
//	int curDir = 1; // ��
//
//	int tick = 0;
//	while (true)
//	{
//		// 0. �ð� ����
//		tick++;
//
//		// 1. ���� �����̸� �÷� �Ӹ�(front())�� ����ĭ�� ��ġ��Ų��
//		// ���� ĭ ���
//		int nRow = dq_snake.front().first + dRow[curDir];
//		int nCol = dq_snake.front().second + dCol[curDir];
//
//		// 2. ���� ���̳� �ڱ��ڽ��� ���� �ε����� ������ ������.
//		if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N || board[nRow][nCol] == 1)
//		{
//			// Die
//			break;
//		}
//
//		// �� �ε����� ����ĭ�� �� deque �� front�� ���� (�Ӹ�)
//		dq_snake.push_front({ nRow, nCol });
//
//		// ���� �̵��� ĭ�� ����� ���ٸ�, �����̸� �ٿ��� ������ ��ġ�� ĭ�� ����ش�.��, �����̴� ������ �ʴ´�.
//		if (board[nRow][nCol] != 2)
//		{
//			// ������ ã�Ƽ� �����ǿ� 0���� �����,
//			int x, y;
//			tie(x, y) = dq_snake.back();
//			board[x][y] = 0;
//
//			// ������ ������
//			dq_snake.pop_back();
//		}
//
//		// ���� �̵��� ĭ�� ����� �ִٸ�, �� ĭ�� �ִ� ����� �������� ������ �������� �ʴ´�.
//		// >>> continue �� �ع�����, ���� ������ ����ϴ� ����!
//		// >> ���� ������� ���� �ذ�!
//		// �Ӹ� �κ� �����ǿ� ǥ��(��� ������)
//		board[nRow][nCol] = 1;
//
//
//		// ���� ����
//		// ���� ���� �ð����κ��� X�ʰ� ���� �ڿ� ������ ȸ����Ų�ٴ� ���̴� >> loop �� �������� ��ġ��.
//		
//		// ���� tick �� ť�� ��� �ִ� ù��° front ����� �ð�(first) �� ���� �� ��
//		if (!Q.empty() && tick == Q.front().first)
//		{
//			// ������ 90 ȸ��
//			if (Q.front().second == 'D')
//			{
//				curDir += 1;
//				curDir %= 4;
//			}
//			else // L , ���� 90 ȸ��
//			{
//				// 0 1 2 3
//				//curDir -= 1; // -1	0	1	2
//				//curDir += 4; //  3	4	5	6
//				curDir += 3;
//				curDir %= 4; //	 3	0	1	2
//				// ���� modular ���� Ȯ���غ���!! >> ���ϴ´�� �� ����
//			}
//
//			// ��� ���� �� ť���� ����
//			Q.pop();
//		}
//
//	}
//
//	// �ִ� �ð� ���
//	cout << tick;
//
//	return 0;
//}