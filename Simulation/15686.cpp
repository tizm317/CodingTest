//#include <iostream>
//#include <queue>
//#include <utility>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 19. ��
//// ���� ��ȣ	: #15686 
//// ���� �̸�	: ġŲ ���
//// �˰���	: �ùķ��̼�
//// �ð����⵵: O()
//
//#define ROW first
//#define COL second
//
//const int dRow[4] = {-1, 0, 1, 0};
//const int dCol[4] = {0, 1, 0, -1};
//
//int N; // 2 <= N <= 50
//int M; // 1 <= M <= 13 
//
//int map[60][60]; // 0 �� ĭ, 1 ��, 2 ġŲ��
//
//queue<pair<int, int>> Q;
//int dist[60][60];
//
//int chickenShopCnt;
//vector<pair<int, int>> chickenShopVec; // ġŲ�� ��ġ ����
//vector<pair<int, int>> houseVec; // �� ��ġ ����
//
//int minCityChickenDistance = 10'000;
//
//void myfunc(int (*map)[60])
//{
//	int cityChickenDistance = 0;
//
//	// ġŲ �Ÿ� ���ϱ� - BFS
//	// ���� ��ġ (��) ã��
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			if (map[r][c] != 1)
//				continue;
//
//			// dist �迭 -1�� �ʱ�ȭ
//			for (int r = 0; r < N; r++)
//				fill(&dist[r][0], &dist[r][N], -1);
//
//			// �� Q �� �ְ�, dist = 0
//			Q.push({ r,c });
//			dist[r][c] = 0;
//
//			while (!Q.empty())
//			{
//				pair<int, int> curPos = Q.front(); Q.pop();
//
//				if (map[curPos.ROW][curPos.COL] == 2)
//				{
//					// ġŲ �Ÿ� d
//					int d = dist[curPos.ROW][curPos.COL];
//					//cout << "ġŲ �Ÿ� : " << d << '\n';
//
//					cityChickenDistance += d;
//
//					while (!Q.empty())
//						Q.pop();
//					break;
//				}
//
//				for (int dir = 0; dir < 4; dir++)
//				{
//					int nRow = curPos.ROW + dRow[dir];
//					int nCol = curPos.COL + dCol[dir];
//
//					if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
//						continue;
//
//					Q.push({ nRow, nCol });
//					dist[nRow][nCol] = dist[curPos.ROW][curPos.COL] + 1;
//				}
//			}
//		}
//	}
//
//	//cout << cityChickenDistance << '\n';
//
//	minCityChickenDistance = min(minCityChickenDistance, cityChickenDistance);
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cin >> map[r][c];
//
//			// ġŲ�� ī����
//			if (map[r][c] == 2)
//			{
//				chickenShopVec.push_back({ r,c });
//				chickenShopCnt++;
//			}
//			else if (map[r][c] == 1)
//			{
//				houseVec.push_back({ r,c });
//			}
//		}
//	}
//
//
//	// ���� nCr
//	// n : ġŲ�� ����
//	// r : M
//	vector<int> a;
//	// M��ŭ 0 ����ְ�
//	for (int i = 0; i < M; i++)
//	{
//		a.push_back(0);
//	}
//	// ġŲ�� ���� - M ��ŭ 1 ���� ����
//	for (int i = 0; i < chickenShopCnt - M; i++)
//	{
//		a.push_back(1);
//	}
//
//	do
//	{
//		int cityChikenDist = 0;
//
//		// �ӽ� �� �ʱ�ȭ
//		int tmp[60][60];
//		for (int r = 0; r < N; r++)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				tmp[r][c] = map[r][c];
//			}
//		}
//
//		//////////////////////////////////////////////////////////////////////////////////
//		// �� �ϰ� �Ÿ� ��� (ġŲ �Ÿ�)
//		for (auto x : houseVec)
//		{
//			int chickenDist = 10000; // <<
//
//			//for (auto x : a)
//			for (int idx = 0; idx < chickenShopCnt; idx++)
//			{
//				//cout << x << " ";
//				if (a[idx] == 1) // 0�ΰ� �츰��? 1�ΰ� �����Ų��.
//				{
//					// �����ų ġŲ��
//					//pair<int, int> closingShop = chickenShopVec[idx];
//
//					// ��ǥ
//					//cout << closingShop.first << " " << closingShop.second << '\n';
//
//					// ��� ǥ��
//					//tmp[closingShop.first][closingShop.second] = 0;
//				}
//				else // ��� �ƴ� ġŲ�� �ϰ�,
//				{
//					auto y = chickenShopVec[idx];
//					int d = abs(x.first - y.first) + abs(x.second - y.second);
//					chickenDist = min(chickenDist, d);
//				}
//			}
//			//cout << '\n';
//
//			cityChikenDist += chickenDist;
//		}
//
//		// Ȯ�ο�
//		//for (int r = 0; r < N; r++)
//		//{
//		//	for (int c = 0; c < N; c++)
//		//	{
//		//		cout << tmp[r][c] << " ";
//		//	}
//		//	cout << '\n';
//		//}
//		//cout << '\n';
//
//		// myfunc(tmp);
//
//		//cout << cityChikenDist << '\n';
//		minCityChickenDistance = min(minCityChickenDistance, cityChikenDist);
//
//	} while (next_permutation(a.begin(), a.end()));
//
//	cout << minCityChickenDistance;
//
//	return 0;
//}
//
//
//// �ִ� M�� ��� ���� �����ϴ�..? (�ƴϿ���)