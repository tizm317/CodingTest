//#include <iostream>
//#include <queue>
//#include <utility>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 19. 수
//// 문제 번호	: #15686 
//// 문제 이름	: 치킨 배달
//// 알고리즘	: 시뮬레이션
//// 시간복잡도: O()
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
//int map[60][60]; // 0 빈 칸, 1 집, 2 치킨집
//
//queue<pair<int, int>> Q;
//int dist[60][60];
//
//int chickenShopCnt;
//vector<pair<int, int>> chickenShopVec; // 치킨집 위치 벡터
//vector<pair<int, int>> houseVec; // 집 위치 벡터
//
//int minCityChickenDistance = 10'000;
//
//void myfunc(int (*map)[60])
//{
//	int cityChickenDistance = 0;
//
//	// 치킨 거리 구하기 - BFS
//	// 시작 위치 (집) 찾기
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			if (map[r][c] != 1)
//				continue;
//
//			// dist 배열 -1로 초기화
//			for (int r = 0; r < N; r++)
//				fill(&dist[r][0], &dist[r][N], -1);
//
//			// 집 Q 에 넣고, dist = 0
//			Q.push({ r,c });
//			dist[r][c] = 0;
//
//			while (!Q.empty())
//			{
//				pair<int, int> curPos = Q.front(); Q.pop();
//
//				if (map[curPos.ROW][curPos.COL] == 2)
//				{
//					// 치킨 거리 d
//					int d = dist[curPos.ROW][curPos.COL];
//					//cout << "치킨 거리 : " << d << '\n';
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
//			// 치킨집 카운팅
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
//	// 조합 nCr
//	// n : 치킨집 개수
//	// r : M
//	vector<int> a;
//	// M만큼 0 집어넣고
//	for (int i = 0; i < M; i++)
//	{
//		a.push_back(0);
//	}
//	// 치킨집 개수 - M 만큼 1 집어 넣음
//	for (int i = 0; i < chickenShopCnt - M; i++)
//	{
//		a.push_back(1);
//	}
//
//	do
//	{
//		int cityChikenDist = 0;
//
//		// 임시 맵 초기화
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
//		// 집 하고 거리 계산 (치킨 거리)
//		for (auto x : houseVec)
//		{
//			int chickenDist = 10000; // <<
//
//			//for (auto x : a)
//			for (int idx = 0; idx < chickenShopCnt; idx++)
//			{
//				//cout << x << " ";
//				if (a[idx] == 1) // 0인걸 살린다? 1인걸 폐업시킨다.
//				{
//					// 폐업시킬 치킨집
//					//pair<int, int> closingShop = chickenShopVec[idx];
//
//					// 좌표
//					//cout << closingShop.first << " " << closingShop.second << '\n';
//
//					// 폐업 표시
//					//tmp[closingShop.first][closingShop.second] = 0;
//				}
//				else // 폐업 아닌 치킨집 하고,
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
//		// 확인용
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
//// 최대 M개 라는 말이 수상하다..? (아니였음)