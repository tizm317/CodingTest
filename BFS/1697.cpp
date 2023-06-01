//#include <iostream>
//#include <queue>
//#include <utility>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 28. 금
//// 문제 번호	: #1697 
//// 문제 이름	: 숨바꼭질 1
//// 알고리즘	: BFS
//// 시간복잡도: O()
//
//int N, K;
//queue<int> Q;
//
//int visit[100005];
//int dist[100005];
//
//const int dx[3] = { 1, -1, 2 };
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> K;
//
//	// 1. 수빈 현재 위치
//	Q.push(N);
//	visit[N] = 1;
//
//	while (!Q.empty())
//	{
//		int curPos = Q.front(); Q.pop();
//
//		// 찾음
//		if (curPos == K)
//		{
//			cout << dist[curPos];
//			break;
//		}
//
//		// 생각해야할 점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		// 문제에서 수빈이가 100000을 벗어나면 안 된다 라고 써있지 않음 -> 그렇게 멋대로 생각 X
//		// 0 ~ 200000 범위
//		// 또는, 곱하기를 해서 100000 범위를 넘어간 뒤 -1 을 하는 것 보다,
//		// -1 을 먼저 한 후 곱하면 된다..
//		// 따라서 여기서는 0 ~ 100000 으로 해도 된다.
//		// 하지만 다른 문제에서는 어떻게 될 지 모르는 거기 때문에 잘 생각해봐야한다.. 범위를!
//
//		// 이동
//		for (int dir = 2; dir >= 0; dir--)
//		{
//			// 다음 위치
//			int nX = 0;
//
//			// 좌우 이동 , 순간이동
//			if (dir < 2)
//				nX = curPos + dx[dir];
//			else // dir == 2
//				nX = curPos * dx[dir];
//
//			// 범위 넘어가는지 체크
//			if (nX < 0 || nX > 100000)
//				continue;
//
//			// 방문 여부 체크
//			if (visit[nX] != 0)
//				continue;
//
//			Q.push(nX);
//			
//			// 순간 이동은 0초 , 좌우 이동은 1초
//			if (dir == 2)
//				dist[nX] = dist[curPos];
//			else
//				dist[nX] = dist[curPos] + 1;
//			
//			visit[nX] = 1;
//
//		}
//
//		//// 1. 순간 이동
//		//if (curPos != 0 && curPos * 2 <= 100000)
//		//{
//		//	// 방문한적 없을 때만
//		//	if (visit[curPos * 2] == 0)
//		//	{
//		//		Q.push(curPos * 2);
//		//		visit[curPos * 2] = visit[curPos] + 1;
//		//	}
//		//}
//
//		//// 2. 걷기
//		//if (curPos - 1 >= 0)
//		//{
//		//	// 방문 체크
//		//	if (visit[curPos - 1] == 0)
//		//	{
//		//		Q.push(curPos - 1);
//		//		visit[curPos - 1] = visit[curPos] + 1;
//		//	}
//		//}
//
//		//if (curPos + 1 <= 100000)
//		//{
//		//	// 방문 체크
//		//	if (visit[curPos + 1] == 0)
//		//	{
//		//		Q.push(curPos + 1);
//		//		visit[curPos + 1] = visit[curPos] + 1;
//		//	}
//		//}
//	}
//
//	return 0;
//}