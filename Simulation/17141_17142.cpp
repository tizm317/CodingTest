//#include <iostream>
//#include <algorithm> // next_permutation
//#include <utility>
//#include <queue>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 31. ��.
//// ���� ��ȣ	: #17141 , #17142
//// ���� �̸�	: ������ 2 , ������ 3
//// �˰���	: �ùķ��̼�, BFS ������, ����
//// �ð����⵵: O()
//
//int N; // <= 50
//int room[55][55]; // 0 ��ĭ, 1 ��, 2 ���̷��� ���� �� �ִ� ��ġ
//
//int M; // <= 10
//
//int minTime = -1;
//
//const int dRow[4] = { -1, 0, 1, 0 };
//const int dCol[4] = { 0, 1, 0, -1 };
//
//vector<pair<int, int>> virusPosVec;
//
//queue<pair<int, int>> Q;
//int dist[55][55];
//
//void BFS();
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ������ ���� �Է�
//	cin >> N >> M;
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cin >> room[r][c];
//
//			// ���̷��� ����
//			if (room[r][c] == 2)
//			{
//				virusPosVec.push_back({ r,c });
//			}
//		}
//	}
//
//	// ���� ����� ��
//	int idx[10] = { 0, };
//	// �޺κ��� 1�� �ʱ�ȭ
//	for (int i = virusPosVec.size() - M; i < virusPosVec.size(); i++)
//		idx[i] = 1;
//
//	do
//	{
//		// dist �迭 �ʱ�ȭ
//		for (int r = 0; r < 55; r++)
//			fill(&dist[r][0], &dist[r][55], -1);
//
//		for (int i = 0; i < virusPosVec.size(); i++)
//		{
//			// ������ 2 -> ���̷��� �ƴϸ� ��ĭ���� �ٲ�
//			if (idx[i] == 0)
//				room[virusPosVec[i].first][virusPosVec[i].second] = 0;
//
//			// ������ 3 -> ��Ȱ�� ���̷��� 2�� ���� (����� �����ϳ�, ��ĭ�� ���Ե����� �ʾƼ� maxDist ��꿡���� ����)
//				// [����] ������ �ٲٸ� �ƿ� ����� �� �ż�, �Ÿ��� ���ϰų� �������� �� �ϴ� ��� ����(������ �ƴѵ�!)
//			//room[virusPosVec[i].first][virusPosVec[i].second] = 2;
//			else
//			{
//				room[virusPosVec[i].first][virusPosVec[i].second] = 2;
//
//				// ���̷���
//				Q.push(virusPosVec[i]);
//				dist[virusPosVec[i].first][virusPosVec[i].second] = 0;
//			}
//		}
//
//		BFS();
//
//	} while (next_permutation(idx, idx + virusPosVec.size()));
//
//	cout << minTime;
//
//	return 0;
//}
//
//// BFS ���ÿ� ������!
//
//// #17142 ������ 3
//// ��Ȱ�� ���̷����� ���� �ƴ�
//// ��� ���� ������ �׷��ٰ� ��ĭ���� �ƿ� �ٲٸ� �ȵ�
//// maxDist ���� ���� ��ĭ�� �ƴϹǷ� �����ϰ�!
//// ���̷����� ���� ���� ���� �ƴϹǷ� �����Ѵ�
//
//void BFS()
//{
//	while (!Q.empty())
//	{
//		pair<int, int> curPos = Q.front(); Q.pop();
//
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nRow = curPos.first + dRow[dir];
//			int nCol = curPos.second + dCol[dir];
//
//			if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N || room[nRow][nCol] == 1)
//				continue;
//
//			if (dist[nRow][nCol] != -1)
//				continue;
//
//			Q.push({ nRow, nCol });
//			dist[nRow][nCol] = dist[curPos.first][curPos.second] + 1;
//		}
//	}
//
//	int maxDist = 0;
//	bool fail = false;
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			// ��ĭ �߿���!
//			if (room[r][c] != 0)
//				continue;
//
//			// �������� �� �� ���
//			if (dist[r][c] == -1)
//			{
//				fail = true;
//				continue;
//			}
//
//			maxDist = max(maxDist, dist[r][c]);
//		}
//	}
//
//	if (!fail)
//	{
//		minTime = (minTime == -1) ? maxDist : min(minTime, maxDist);
//	}
//}