//#include <iostream>
//#include <tuple>
//#include <queue>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 04. 28. ��
//// ���� ��ȣ	: #7569 
//// ���� �̸�	: �丶��(3����)
//// �˰���	: BFS
//// �ð����⵵: O()
//
//int COL, ROW, HEIGHT;
//
//int tomato[105][105][105];
//int dist[105][105][105];
//
//queue<tuple<int, int, int>> Q;
//
//// �����»�, ��, �Ʒ�
//const int dHeight[6] = { 0, 0, 0, 0, 1, -1 };
//const int dRow[6]	 = { 0, 1, 0, -1, 0, 0 };
//const int dCol[6]	 = { 1, 0, -1, 0, 0, 0};
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ����, ����, ����
//	cin >> COL >> ROW >> HEIGHT;
//
//	for (int h = 0; h < HEIGHT; h++)
//	{
//		for (int r = 0; r < ROW; r++)
//		{
//			for (int c = 0; c < COL; c++)
//			{
//				cin >> tomato[h][r][c];
//
//				// �Ÿ� �ʱ�ȭ
//				dist[h][r][c] = -1;
//
//				// ���� �丶�� ã��
//				if (tomato[h][r][c] == 1)
//				{
//					Q.push({ h, r, c });
//					dist[h][r][c]++;
//				}
//			}
//		}
//	}
//
//	while (!Q.empty())
//	{
//		tuple<int, int, int> curPos = Q.front(); Q.pop();
//
//		for (int dir = 0; dir < 6; dir++)
//		{
//			// ���� ��ġ
//			int nHeight = get<0>(curPos) + dHeight[dir];
//			int nRow = get<1>(curPos) + dRow[dir];
//			int nCol = get<2>(curPos) + dCol[dir];
//
//			// 1. ���� üũ
//			if (nHeight < 0 || nHeight >= HEIGHT || nRow < 0 || nRow >= ROW || nCol < 0 || nCol >= COL)
//				continue;
//
//			// 2. �丶�� üũ (���� ���� �丶��)
//			if (tomato[nHeight][nRow][nCol] != 0)
//				continue;
//
//
//			// 3. �湮 üũ
//			if (dist[nHeight][nRow][nCol] == -1)
//			{
//				// ó���� ���
//				dist[nHeight][nRow][nCol] = dist[get<0>(curPos)][get<1>(curPos)][get<2>(curPos)] + 1;
//			}
//			else
//			{
//				// �湮�� �� �ִ� ���, �ּҰ����� ����
//				dist[nHeight][nRow][nCol] = (dist[nHeight][nRow][nCol] < dist[get<0>(curPos)][get<1>(curPos)][get<2>(curPos)] + 1) ? dist[nHeight][nRow][nCol] : dist[get<0>(curPos)][get<1>(curPos)][get<2>(curPos)] + 1;
//			}
//
//			// Ǫ��
//			Q.push({ nHeight, nRow, nCol });
//		
//			// �丶�� ����
//			tomato[nHeight][nRow][nCol] = 1;
//		}
//	}
//
//	int days = -1;
//	for (int h = 0; h < HEIGHT; h++)
//	{
//		for (int r = 0; r < ROW; r++)
//		{
//			for (int c = 0; c < COL; c++)
//			{
//				// �丶�� ���� �� �н�
//				if (tomato[h][r][c] == -1)
//					continue;
//
//				// �� �� ���� �� ����
//				if (tomato[h][r][c] == 0)
//				{
//					cout << -1;
//					return 0;
//				}
//				
//				days = max(days, dist[h][r][c]);
//			}
//		}
//	}
//
//	cout << days;
//
//	return 0;
//}