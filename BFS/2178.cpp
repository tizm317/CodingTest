//#include <iostream>
//#include <queue>
//#include <utility>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 04. 26. ��
//// ���� ��ȣ	: #2178
//// ���� �̸�	: �̷�
//// �˰���	: BFS
//// �ð����⵵: O()
//
//#define ROW first
//#define COL second
//
//int N, M;
//
//int maze[101][101];
//int visit[101][101];
//
//queue<pair<int, int>> Q;
//
//const int dRow[4] = {0, 1, 0, -1};
//const int dCol[4] = {1, 0, -1, 0};
//
////
//string board[101];
//int dist[101][101];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 1. ���� Ǯ��
//	//for (int i = 0; i < 101; i++)
//	//	fill(visit[i], visit[i] + 101, 0);
//
//	//cin >> N >> M;
//	//
//	//string str;
//	//for (int i = 0; i < N; i++)
//	//{
//	//	cin >> str;
//
//	//	for (int j = 0; j < M; j++)
//	//	{
//	//		if (str[j] == '1')
//	//			maze[i][j] = 1;
//	//		else
//	//			maze[i][j] = 0;
//	//	}
//	//}
//
//	////
//	//visit[0][0]++;
//	//Q.push({ 0, 0 });
//
//	//while (!Q.empty())
//	//{
//	//	pair<int, int> curPos = Q.front(); Q.pop();
//
//
//	//	for (int dir = 0; dir < 4; dir++)
//	//	{
//	//		int nRow = curPos.ROW + dRow[dir];
//	//		int nCol = curPos.COL + dCol[dir];
//	//	
//	//		if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= M)
//	//			continue;
//
//	//		if (visit[nRow][nCol] != 0)
//	//			continue;
//
//	//		if (maze[nRow][nCol] == 1)
//	//		{
//	//			visit[nRow][nCol] = visit[curPos.ROW][curPos.COL] + 1;
//
//	//			Q.push({ nRow, nCol });
//	//		}
//	//	}
//	//	
//	//}
//	//
//	//cout << visit[N - 1][M - 1];
//
//
//	// 2. �ٸ� Ǯ��
//
//	// �Ÿ� -1 �ʱ�ȭ
//	for (int i = 0; i < 101; i++)
//		fill(dist[i], dist[i] + 101, -1);
//
//	cin >> N >> M;
//
//	// string �迭 �Է� ����
//	string str;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> board[i];
//	}
//
//	//
//	dist[0][0]++;
//	Q.push({ 0, 0 });
//
//	while (!Q.empty())
//	{
//		pair<int, int> curPos = Q.front(); Q.pop();
//
//
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nRow = curPos.ROW + dRow[dir];
//			int nCol = curPos.COL + dCol[dir];
//
//			if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= M)
//				continue;
//
//			if (dist[nRow][nCol] != -1)
//				continue;
//
//			if (board[nRow][nCol] == '1')
//			{
//				dist[nRow][nCol] = dist[curPos.ROW][curPos.COL] + 1;
//
//				Q.push({ nRow, nCol });
//			}
//		}
//
//	}
//
//	cout << dist[N - 1][M - 1] + 1;
//
//
//	return 0;
//}