//#include <iostream>
//#include <queue>
//#include <utility>	// pair
//
//using namespace std;
//
//#define ROW first
//#define COL second
//
//const int board[502][502] =
//{ 
//	{1,1,1,0,1,0,0,0,0,0},
//	{1,0,0,0,1,0,0,0,0,0},
//	{1,1,1,0,1,0,0,0,0,0},
//	{1,1,0,0,1,0,0,0,0,0},
//	{0,1,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0} 
//}; // 1�� �Ķ� ĭ, 0�� ���� ĭ�� ����
//
//// ��, �� ũ��
//const int r = 7, c = 10;
//
//int visit[502][502]; // 1 : �湮 ���� üũ
//
//// �������� ��ǥ
//const pair<int, int> start = { 0, 0 };
//
//// ť
//queue<pair<int, int>> Q;
//
//// �����»�
//int dRow[4] = {0, 1, 0, -1};
//int dCol[4] = {1, 0, -1, 0};
//
//int main()
//{
//	// 1. ť�� ���� ��ǥ ����
//	Q.push(start);
//
//	// 2. ���� ��ǥ �湮 ǥ��
//	visit[start.ROW][start.COL] = 1;
//
//	// ť�� �� �� ���� �ݺ�
//	while (!Q.empty())
//	{
//		// ���� ��ǥ
//		pair<int, int> curPos = Q.front(); Q.pop();
//
//		// ���
//		cout << "(" << curPos.ROW << ", " << curPos.COL << ") ";
//
//		// ���� ��ǥ
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nRow = curPos.ROW + dRow[dir];
//			int nCol = curPos.COL + dCol[dir];
//
//			// �̵� ������ ��ǥ(���� ��)���� Ȯ��
//			if (nRow < 0 || nRow >= r || nCol < 0 || nCol >= c)
//				continue;
//
//			// �湮�� �� �ִ��� Ȯ��
//			// ������ continue
//			if (visit[nRow][nCol] == 1)
//				continue;
//			else // ������ �湮 ǥ��
//				visit[nRow][nCol] = 1;
//
//			// board �� �Ķ�ĭ(1) ���� Ȯ�� ��,
//			// ť�� �ֱ�
//			if(board[nRow][nCol] == 1)
//				Q.push({ nRow, nCol });
//		}
//		
//	}
//
//	return 0;
//}
