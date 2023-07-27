//#include <iostream>
//#include <vector>
//#include <utility>
//#include <tuple> // tie
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 27. 목
//// 문제 번호	: #15685 
//// 문제 이름	: 드래곤 커브
//// 알고리즘	: 시뮬레이션
//// 시간복잡도: O()
//
//int N; // 커브 개수 <= 20
//
//// 좌표계 (row 가 y축, col 이 x축)
//int coord[105][105];
//
//// 4점이 모두 드래곤 커브 일부인 사각형의 개수
//int squareCntAroundedDragonCurve;
//
//void dragonCurve(vector<pair<int, int>>& V, int dir, int gen, const int targetGen);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	while (N--)
//	{
//		int x, y, d, g;
//		cin >> x >> y >> d >> g;
//
//		// 드래곤 커브가 지나는 점 담을 벡터
//		vector<pair<int, int>> V;
//
//		// 드래곤 커브의 시작점
//		V.push_back({ x,y });
//
//		// 1. 드래곤 커브
//		dragonCurve(V, d, 0, g);
//
//		// 2. 결과물을 좌표계에 표시
//		for (auto x : V)
//		{
//			// 여기서 row 가 y축, col 이 x축임.
//			int row = x.second; // y축
//			int col = x.first; // x축
//
//			// 좌표계에 드래곤 커브 지나는 점 표시
//			coord[row][col] = 1;
//		}
//	}
//
//	// 2. 전체 좌표계 돌면서 체크
//	// 100 * 100 * 4 = 4만
//	for (int r = 0; r < 100; r++)
//	{
//		for (int c = 0; c < 100; c++)
//		{
//			// (r,c) 기준으로 (r,c+1), (r+1,c), (r+1,c+1) 모두 1이면 네꼭지점이 사각형
//			if (coord[r][c] == 1 && coord[r][c + 1] == 1 && coord[r + 1][c] == 1 && coord[r + 1][c + 1] == 1)
//				squareCntAroundedDragonCurve++;
//		}
//	}
//
//	// 결과 출력
//	cout << squareCntAroundedDragonCurve;
//
//	return 0;
//}
//
//void dragonCurve(vector<pair<int, int>>& V, int dir, int gen, const int targetGen)
//{
//	// 목표 세대까지 진화 완료
//	if (gen > targetGen)
//	{
//		// [디버깅용] 드래곤커브 지나는 점 출력
//		//for (auto x : V)
//		//{
//		//	cout << x.first << " " << x.second << '\n';
//		//}
//		//cout << '\n';
//
//		return;
//	}
//
//	// 0세대
//	if (gen == 0)
//	{
//		int x, y;
//		tie(x, y) = V.front();
//
//		// dir 방향 이동
//		switch (dir)
//		{
//		case 0:
//			V.push_back({ x + 1, y });
//			break;
//		case 1:
//			V.push_back({ x , y - 1 });
//			break;
//		case 2:
//			V.push_back({ x - 1, y });
//			break;
//		case 3:
//			V.push_back({ x , y + 1 });
//			break;
//		}
//	}
//	else
//	{
//		// n 세대는 n-1 세대 끝점 기준으로 시계방향 회전한 결과를 추가
//
//		vector<pair<int, int>> V_before = V;
//
//		//for (auto& p : V_before) 
//		// 끝점 -> 시작점 순으로 돌아야 순서가 맞는다(시작점이 다음 끝점이 됨) <<<<
//		for (auto it = V_before.rbegin(); it != V_before.rend(); it++)
//		{
//			int x = it->first;
//			int y = it->second;
//
//			// 전 세대의 끝점
//			int x_end = V_before.back().first;
//			int y_end = V_before.back().second;
//
//			// 끝점은 기준점이라 추가 안 해도 됨.
//			if (tie(x, y) == tie(x_end, y_end))
//				continue;
//
//			// 전 세대 끝점 기준으로 회전한 결과를 벡터에 추가
//				// (x_end, y_end) 기준으로 시계방향 90도 회전 식 적용
//			V.push_back({ -y + y_end + x_end, x - x_end + y_end });
//		}
//	}
//
//	// 1세대 진화
//	dragonCurve(V, dir, gen + 1, targetGen);
//}