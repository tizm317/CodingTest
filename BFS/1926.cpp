//#include <iostream>
//#include <utility>
//#include <queue>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 04. 26 ��
//// ���� ��ȣ	: #1926 
//// ���� �̸�	: �׸�
//// �˰���	: BFS
//// �ð����⵵: O(rc) : ĭ ������ŭ
//
//#define ROW first
//#define COL second
//
//int r, c; 
//int board[501][501];
//int visit[501][501];
//
//// �׸� ����, �ִ����
//int artCnt, maxArtSize;
//
//queue<pair<int, int>> Q;
//
//// �����»�
//const int dRow[4] = {0, 1, 0, -1};
//const int dCol[4] = {1, 0, -1, 0};
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ��, �� ũ�� �Է�
//	cin >> r >> c;
//
//	// �׸� �Է�
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			cin >> board[i][j];
//		}
//	}
//
//	// 1. ���� ��ġ ���� 2�� for��
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			// �湮�� �� �ְų�, �׸��� �ƴϸ� continue
//			if (visit[i][j] == 1 || board[i][j] == 0)
//				continue;
//
//			// �׸��� ���, �湮 üũ �� �׸� ���� ����, ť�� Ǫ��
//			visit[i][j] = 1;
//			artCnt++;
//			int curArtSize = 1; // �׸� ũ�� �ʱ�ȭ
//			Q.push({ i, j });
//
//			// 2. �̾����� �׸� üũ�ϴ� �ݺ���
//			while (!Q.empty())
//			{
//				pair<int, int> curPos = Q.front(); Q.pop();
//
//				for (int dir = 0; dir < 4; dir++)
//				{
//					int nRow = curPos.ROW + dRow[dir];
//					int nCol = curPos.COL + dCol[dir];
//
//					// ���� üũ
//					if (nRow < 0 || nRow >= r || nCol < 0 || nCol >= c)
//						continue;
//
//					// �湮 ���� üũ
//					if (visit[nRow][nCol] == 1)
//						continue;
//					else
//						visit[nRow][nCol] = 1;
//
//					// �׸� üũ
//					if (board[nRow][nCol] == 1)
//					{
//						Q.push({ nRow, nCol });
//						
//						// �׸� ũ�� ����
//						curArtSize++;
//					}
//				}
//			}
//
//			// �׸� maxSize Ȯ��
//			maxArtSize = (maxArtSize > curArtSize) ? maxArtSize : curArtSize;
//		}
//	}
//
//	cout << artCnt << '\n' << maxArtSize;
//
//	return 0;
//}