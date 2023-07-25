//#include <iostream>
//#include <algorithm> // next_permutation
//#include <queue>
//#include <utility>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 25. ȭ
//// ���� ��ȣ	: #14502 
//// ���� �̸�	: ������
//// �˰���	: �ùķ��̼�, BFS, ����
//// �ð����⵵: O()
//
//int R, C; // <= 8
//int map[10][10]; // 0 ��ĭ, 1 ��, 2 ���̷���
//
//int max_safe_area_cnt;
//
//const int dRow[4] = {-1, 0, 1, 0};
//const int dCol[4] = {0, 1, 0, -1};
//
//void BFS(int map[10][10]);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ���� �Է�
//	cin >> R >> C;
//	for (int r = 0; r < R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			cin >> map[r][c];
//		}
//	}
//
//	// 1. �� ��ġ ����� �� (����) nC3
//	//int* idx = new int[R * C]{ 0, };
//	int idx[64] = { 0,}; // ����� �� 2���� �迭ó�� ����ϱ�
//	fill(idx, idx + 64, 1);
//	idx[0] = idx[1] = idx[2] = 0; // 0 3��(��) , ������ 1
//	// ���� ������ ���� ���� �տ� �η��� 0�� ������ ��
//
//	do
//	{
//		// �� ��ġ�� ��
//		int tmp[10][10] = { 0, };
//		bool impossibleCase = false; // ���̳�, ���̷��� ��ġ üũ�� bool ����
//		for (int r = 0; r < R; r++)
//		{
//			for (int c = 0; c < C; c++)
//			{
//				// �� ��ġ
//				if (idx[c + r * C] == 0) // 2���� �迭ó�� ��� <<<<<<<<<<<<<<<<< �ε��� ����! (c + r * R �� �� �� ����)
//				{
//					// �̹� ���̰ų�, ���̷��� ��ġ�� ��� �� ��ġ fail
//					if (map[r][c] != 0)
//					{
//						impossibleCase = true;
//						break;
//					}
//					// �� �����̸� �� ��ġ
//					tmp[r][c] = 1;
//				}
//				else
//				{
//					tmp[r][c] = map[r][c];
//				}
//			}
//
//			if (impossibleCase)
//				break;
//		}		
//
//		// 2. BFS ���̷��� ����
//		if(!impossibleCase)
//			BFS(tmp);
//
//	} while (next_permutation(idx, idx + R*C));
//
//	// ��� ���
//	cout << max_safe_area_cnt;
//
//	return 0;
//}
//
//
//void BFS(int map[10][10])
//{
//	// ť, vis �迭 �ʱ�ȭ
//	queue<pair<int, int>> Q;
//	bool vis[10][10] = { false, };
//
//	// ���̷��� ã��(������)
//	for (int r = 0; r < R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			if (map[r][c] != 2)
//				continue;
//
//			if (vis[r][c])
//				continue;
//
//			// �湮 �� �� ����, ���̷��� ť�� �߰��ϰ�, �湮 ǥ��
//			Q.push({ r,c });
//			vis[r][c] = true;
//
//			while (!Q.empty())
//			{
//				// ���� ��ġ
//				pair<int, int> curPos = Q.front(); Q.pop();
//
//				// ���� ��ġ ���
//				for (int dir = 0; dir < 4; dir++)
//				{
//					int nRow = curPos.first + dRow[dir];
//					int nCol = curPos.second + dCol[dir];
//
//					// �迭 ���� üũ, �� üũ
//					if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C || map[nRow][nCol] == 1)
//						continue;
//
//					// �湮 ���� üũ
//					if (vis[nRow][nCol])
//						continue;
//
//					// ť�� �ְ�, �湮 ǥ�� �ϰ�
//					Q.push({ nRow,nCol });
//					vis[nRow][nCol] = true;
//
//					// ���̷��� ���� ǥ��
//					map[nRow][nCol] = 2;
//				}
//			}
//		}
//	}
//
//	// 3. ���� ���� ����
//	// ���̷���, �� �ƴ� �� ����(0) ����
//	int cnt = 0;
//	for (int r = 0; r < R; r++)
//		for (int c = 0; c < C; c++)
//			if (map[r][c] == 0) cnt++;
//
//	// �ƽø� ���
//	max_safe_area_cnt = max(max_safe_area_cnt, cnt);
//}