//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <utility> // pair
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 06. 01. 목
//// 문제 번호	: #7795
//// 문제 이름	: 먹을 것인가 먹힐 것인가
//// 알고리즘	: 정렬  (또는 이분 탐색)
//// 시간복잡도: O()
//
//int T;
//int N, M;
//
//
//bool cmp(int a, int b)
//{
//	return a > b;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		cin >> N >> M;
//
//		vector<pair<int, int>> vec(N+M);
//		for (int j = 0; j < N; j++)
//		{
//			int x;
//			cin >> x;
//			vec[j] = { x, 0 }; // A 물고기
//		}
//
//		for (int j = N; j < N + M; j++)
//		{
//			int x;
//			cin >> x;
//			vec[j] = { x, 1 }; // B 물고기
//		}
//
//		// 8 1 7 3 1 3 6 1
//		// 0 0 0 0 0 1 1 1
//		sort(vec.begin(), vec.end());
//		// 1 1 1 3 3 6 7 8
//		// 0 0 1 0 1 1 0 0
//		// A A B A B B A A
//		// A는 왼쪽 B 개수만큼 먹을 수 있다
//		// A, B 의 크기가 같은 경우 먹지 못 하기 때문에, 크기가 같을 경우 A를 왼쪽에 두도록 한다(second 값이 A가 0인 이유)
//		// 만약 크기가 같을 때 먹을 수 있다면, second 값이 A가 B보다 커야 함
//
//		int eatableFishCnt = 0;
//		int totalCnt = 0;
//		for (int j = 0; j < N + M; j++)
//		{
//			// 현재 물고기가 A인 경우, 토탈 개수에 (먹을수 있는 물고기 개수) 더함
//			if (vec[j].second == 0)
//				totalCnt += eatableFishCnt;
//
//			// B 인 경우, 먹을 수 있는 물고기 개수 증가
//			if (vec[j].second == 1)
//				eatableFishCnt++;
//		}
//
//		cout << totalCnt << '\n';
//	}
//
//	return 0;
//}