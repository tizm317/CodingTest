//#include <iostream>
//#include <queue>
//#include <utility>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 20xx. xx. xx.
//// ���� ��ȣ	: #00000 
//// ���� �̸�	: 
//// �˰���	: 
//// �ð����⵵: O()
//
//#define ROW first
//#define COL second
//
//int T, Row, Col, Count;
//int board[55][55] = { 0, }; // ���߹�
//int visit[55][55] = { 0, };
//
//queue<pair<int, int>> Q;
//
//
//const int dRow[4] = { 0, 1, 0, -1 };
//const int dCol[4] = { 1, 0, -1, 0 };
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// �׽�Ʈ ���̽� ������ �� ��, ���� ���� �ʱ�ȭ!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		// ��, ��, ���� ����
//		cin >> Col >> Row >> Count; // ����, ���� �Ųٷ� �޾Ҿ���
//
//		// ���ɸ��� ��, �湮 ���� �ʱ�ȭ
//		for (int r = 0; r < Row; r++)
//		{
//			fill(board[r], board[r] + 55, 0);
//			fill(visit[r], visit[r] + 55, 0);
//		}
//
//		// ����
//		for (int j = 0; j < Count; j++)
//		{
//			int r, c;
//			cin >> c >> r; // �Ųٷ� �޾ҳ�
//			board[r][c] = 1;
//		}
//
//		int wormCnt = 0;
//
//		// 2�� for������ ���� ã��
//		for (int r = 0; r < Row; r++)
//		{
//			for (int c = 0; c < Col; c++)
//			{
//				// ���� ã��
//				if (board[r][c] == 0)
//					continue;
//
//				// �湮 ���� Ȯ��
//				if (visit[r][c] == 1)
//					continue;
//
//				// ���� �湮���� ���� ���� ���� Ȯ��
//				Q.push({ r, c });
//				visit[r][c] = 1;
//
//				// ���� 1�� �� ���߹��� ���� + 1
//				wormCnt++;
//
//				while (!Q.empty())
//				{
//					pair<int, int> curPos = Q.front(); Q.pop();
//
//					for (int dir = 0; dir < 4; dir++)
//					{
//						int nRow = curPos.ROW + dRow[dir];
//						int nCol = curPos.COL + dCol[dir];
//
//						// ���� üũ
//						if (nRow < 0 || nRow >= Row || nCol < 0 || nCol >= Col)
//							continue;
//
//						// �������� üũ
//						if (board[nRow][nCol] == 0)
//							continue;
//
//						// �湮 üũ
//						if (visit[nRow][nCol] == 1)
//							continue;
//
//						visit[nRow][nCol] = 1;
//						Q.push({ nRow, nCol });
//					}
//				}
//			}
//		}
//
//		cout << wormCnt << '\n';
//	}
//
//	// �̰� ��� �°� ó�����ֳ�
//	// ���� 0�� ��,
//	//if(T == 0)
//	//	cout << 0;
//
//	return 0;
//}