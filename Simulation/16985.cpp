//#include <iostream>
//#include <vector>
//#include <algorithm> // permutation
//#include <queue>
//#include <tuple>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 21. ��
//// ���� ��ȣ	: #16985 
//// ���� �̸�	: Maaaaaaaaaze
//// �˰���	: �ùķ��̼�, ����, BFS
//// �ð����⵵: O()
//
//const int SIZE = 5;
//vector<vector<vector<int>>> V; // 5x5 �迭�� ��� ����
//
//const int SHORTEST_DISTANCE = 12;
//int ans = -1;
//
//// �ϵ�����, ����
//const int dRow[6] = { -1,0,1,0,0,0 };
//const int dCol[6] = { 0,1,0,-1,0,0 };
//const int dHeight[6] = { 0,0,0,0,-1,1 };
//
//
//// �״� ���� ���� ���� �Լ�
//void stackMaze();
//
//// ȸ�� ���� ���� �Լ�
//void rotateMaze(int h, vector<vector<vector<int>>>& maze);
//
//// ��� ����� �� ���� �ִ� �Ÿ� ã�� �Լ�
//void BFS(vector<vector<vector<int>>>& maze);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 5x5 �� 5�� �Է�
//	for (int i = 0; i < SIZE; i++)
//	{
//		vector<vector<int>> tmp(SIZE, vector<int>(SIZE));
//		for (int r = 0; r < SIZE; r++)
//		{
//			for (int c = 0; c < SIZE; c++)
//			{
//				cin >> tmp[r][c];
//			}
//		}
//		V.push_back(tmp);
//	}
//
//	// �� �ױ�
//	stackMaze();
//
//	// �ִܰŸ� ���
//	cout << ans;
//
//	return 0;
//}
//
//void BFS(vector<vector<vector<int>>>& maze)
//{
//	// �Ա� �ⱸ ���� ���
//	if (maze[0][0][0] == 0 || maze[SIZE - 1][SIZE - 1][SIZE - 1] == 0)
//		return;
//
//	// �Ÿ� �迭 -1 �ʱ�ȭ
//	int dist[SIZE][SIZE][SIZE];
//	for (int h = 0; h < SIZE; h++)
//		for (int r = 0; r < SIZE; r++)
//			for (int c = 0; c < SIZE; c++)
//				dist[h][r][c] = -1;
//
//	// �Ա� ��ġ [0][0][0]
//	// �ⱸ ��ġ [4][4][4]
//	queue<tuple<int, int, int>> Q;
//	Q.push({ 0,0,0 });
//	dist[0][0][0] = 0;
//
//	while (!Q.empty())
//	{
//		// ���� ��ġ
//		tuple<int, int, int> curPos = Q.front(); Q.pop();
//
//		// �ⱸ���� üũ
//		if (curPos == tuple<int, int, int>{SIZE - 1, SIZE - 1, SIZE - 1})
//		{
//			if (ans == -1)
//				ans = dist[get<0>(curPos)][get<1>(curPos)][get<2>(curPos)];
//			else
//				ans = min(ans, dist[get<0>(curPos)][get<1>(curPos)][get<2>(curPos)]);
//
//			break;
//		}
//
//		// ���� ��ġ ���
//		for (int dir = 0; dir < 6; dir++)
//		{
//			int nHeight = get<0>(curPos) + dHeight[dir];
//			int nRow = get<1>(curPos) + dRow[dir];
//			int nCol = get<2>(curPos) + dCol[dir];
//
//			// �迭 ���� üũ
//			if (nRow < 0 || nRow >= SIZE || nCol < 0 || nCol >= SIZE || nHeight < 0 || nHeight >= SIZE)
//				continue;
//
//			// ��
//			if (maze[nHeight][nRow][nCol] == 0)
//				continue;
//
//			// �ߺ� �湮 üũ
//			if (dist[nHeight][nRow][nCol] != -1)
//				continue;
//
//			Q.push({ nHeight, nRow, nCol });
//			dist[nHeight][nRow][nCol] = dist[get<0>(curPos)][get<1>(curPos)][get<2>(curPos)] + 1;
//		}
//	}
//}
//void rotateMaze(int h, vector<vector<vector<int>>>& maze)
//{
//	if (h >= SIZE)
//	{
//		BFS(maze);
//
//		return;
//	}
//
//	vector<vector<vector<int>>> tmp = maze;
//	// 90, 180, 270, 360
//	for (int rot = 0; rot < 4; rot++)
//	{
//		for (int r = 0; r < SIZE; r++)
//		{
//			for (int c = 0; c < SIZE; c++)
//			{
//				// 90�� ȸ��
//				tmp[h][r][c] = maze[h][c][SIZE - 1 - r];
//			}
//		}
//
//		maze = tmp;
//		rotateMaze(h + 1, maze);
//
//		// �ּҰ�� SHORTEST_DISTANCE(12) �� ��� ������ ������ ����
//		if (ans == SHORTEST_DISTANCE)
//			return;
//	}
//
//}
//void stackMaze()
//{
//	// �� �״� ���� - ���� �̿�
//	int idxes[SIZE] = { 0,1,2,3,4 };
//	do
//	{
//		vector<vector<vector<int>>> maze;
//		// ���� ����� ���� �� �ױ�
//		for (int i = 0; i < SIZE; i++)
//		{
//			const int idx = idxes[i];
//			maze.push_back(V[idx]);
//		}
//
//		// ȸ��
//		rotateMaze(0, maze);
//
//	} while (next_permutation(idxes, idxes + SIZE));
//}
