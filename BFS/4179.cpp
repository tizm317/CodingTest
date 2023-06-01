//#include <iostream>
//#include <utility>
//#include <queue>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 04. 26. ��
//// ���� ��ȣ	: #4179 
//// ���� �̸�	: ��!
//// �˰���	: 
//// �ð����⵵: O()
//
//#define ROW first
//#define COL second
//
//int r, c;
//
//int maze[1005][1005];
//int visit[1005][1005];
//
//queue<pair<int, int>> Q;
//
//const int dRow[4] = { 0, 1, 0, -1 };
//const int dCol[4] = { 1, 0, -1, 0 };
//
//pair<int, int> JPos;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> r >> c;
//
//	//for(int i = 0; i < r; i++)
//	//	fill(visit[i], visit[i] + c, -1);
//
//	for (int i = 0; i < r; i++)
//	{
//		string s;
//		cin >> s;
//		for (int j = 0; j < c; j++)
//		{
//			if (s[j] == '#' || s[j] == 'F')
//			{
//				if (s[j] == 'F')
//				{
//					// 2. �� ������
//					Q.push({ i, j });
//					visit[i][j] = -1;
//					//visit[i][j] = 0;
//				}
//
//				maze[i][j] = 1;
//			}
//			else
//			{
//				if (s[j] == 'J')
//				{
//					// 1. ���� ������
//					JPos = { i, j };
//					//Q.push({ i, j });
//					visit[i][j] = 0;
//				}
//
//				maze[i][j] = 0;
//			}
//		}
//	}
//
//	// ������ ���� ������
//	pair<int, int> curPos = JPos;
//
//	do
//	{
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nRow = curPos.ROW + dRow[dir];
//			int nCol = curPos.COL + dCol[dir];
//
//			// ��, ���� ����
//			if (maze[nRow][nCol] == 1)
//				continue;
//
//			// Ż��
//			if (nRow < 0 || nRow == r || nCol < 0 || nCol == c)
//			{
//				// �� ����
//				if (maze[curPos.ROW][curPos.COL] == 1)
//					continue;
//
//				//cout << "Ż��" << '\n';
//				cout << visit[curPos.ROW][curPos.COL] + 1 << '\n';
//				return 0;
//			}
//
//			// ���� ���
//			if (maze[curPos.ROW][curPos.COL] == 1)
//			{
//				maze[nRow][nCol] = 1;
//
//				visit[nRow][nCol] = -1;
//			}
//			else // ����
//			{
//				// �ҿ� ���� ���
//				if (visit[curPos.ROW][curPos.COL] == -1)
//					continue;
//
//				// ������ �� �ߺ�X
//				if (visit[nRow][nCol] != 0)
//					continue;
//
//				visit[nRow][nCol] = visit[curPos.ROW][curPos.COL] + 1;
//			}
//
//			Q.push({ nRow, nCol });
//		}
//
//		if (Q.empty())
//			break;
//
//		// ����
//		curPos = Q.front(); Q.pop();
//	
//	} while (true);
//	
//	cout << "IMPOSSIBLE";
//
//
//
//
//	// 2. �ٸ� Ǯ�� -> �޸� �ʰ�
//	// �ҿ� ���� BFS + �����̿� ���� BFS ���� �ؼ� �ð� �� �� �������� ���� üũ
//	
//	// �ҿ� ���� BFS
//	/*while (true)
//	{
//		pair<int, int> curPos = Q.front(); Q.pop();
//
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nRow = curPos.ROW + dRow[dir];
//			int nCol = curPos.COL + dCol[dir];
//
//			if (maze[nRow][nCol] == 1 || visit[nRow][nCol] != 0)
//				continue;
//
//			if (nRow < 0 || nRow >= r || nCol < 0 || nCol >= c)
//				continue;
//
//			visit[nRow][nCol] = visit[curPos.ROW][curPos.COL] + 1;
//			Q.push({ nRow, nCol });
//		}
//
//		if (Q.empty())
//		{
//			Q.push(JPos);
//			visit[JPos.ROW][JPos.COL] = 0;
//
//			while (!Q.empty())
//			{
//				pair<int, int> curPos = Q.front(); Q.pop();
//
//				for (int dir = 0; dir < 4; dir++)
//				{
//					int nRow = curPos.ROW + dRow[dir];
//					int nCol = curPos.COL + dCol[dir];
//
//					if (maze[nRow][nCol] == 1)
//						continue;
//
//					if (nRow < 0 || nRow >= r || nCol < 0 || nCol >= c)
//					{
//						cout << visit[curPos.ROW][curPos.COL] + 1 << '\n';
//						return 0;
//					}
//
//					if (visit[nRow][nCol] == -1 || visit[nRow][nCol] >= visit[curPos.ROW][curPos.COL] + 1)
//					{
//						visit[nRow][nCol] = visit[curPos.ROW][curPos.COL] + 1;
//						Q.push({ nRow, nCol });
//					}
//				}
//			}
//
//		}
//	}*/
//
//	
//
//	return 0;
//}