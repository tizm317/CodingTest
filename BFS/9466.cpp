//#include <iostream>
//#include <utility>
//#include <queue>
//#include <deque>
//#include <algorithm>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 04. 수
//// 문제 번호	: #9466 
//// 문제 이름	: 텀 프로젝트
//// 알고리즘	: BFS
//// 시간복잡도: O()
//
//int T, n;
//
//int partner[100005] = { 0, };
//int visit[100005] = { 0, };
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		cin >> n;
//		//int partner[100005] = { 0, };
//		//int visit[100005] = { 0, };
//		//int* partner = new int[n + 1]{ 0, };	// 파트너
//		//int* visit = new int[n + 1]{ 0, };		// 방문 여부
//		//int* team = new int[n + 1]{ 0, };		// 팀 여부
//
//
//		for (int j = 1; j < n + 1; j++)
//		{
//			cin >> partner[j];
//			visit[j] = 0;
//		}
//
//		int totalCnt = 0;
//
//		//
//		for (int j = 1; j < n + 1; j++)
//		{
//			queue<pair<int, int>> Q;
//
//			// 방문한 적 있으면 pass
//			if (visit[j] != 0)
//				continue;
//
//			// 없으면 큐에 넣고 , visit 은 전보다 1 크게 설정
//			Q.push({ j, partner[j] });
//			//visit[j] = visit[j - 1] + 1;
//			visit[j] = 1;
//			//visit[j] = *max_element(visit, visit + n + 1) + 1;
//
//			while (true)
//			{
//				// 큐의 맨 뒤 원소
//				pair<int, int> curPos = Q.back();
//			
//				// 다음 원소
//				// 방문한 적 있음
//				if (visit[curPos.second] != 0)
//				{
//					if (curPos.second == curPos.first)
//					{
//						Q.pop();
//
//						// 큐 비우고 탈출
//
//						totalCnt += Q.size();
//						break;
//					}
//					else
//					{
//						while (!Q.empty() && Q.front().first != Q.back().second)
//						{
//							totalCnt++;
//							Q.pop();
//						}
//
//						break;
//					}
//				}
//
//				// 방문한 적 없으면,
//				// 큐에 넣고, visit 동일하게 설정
//				Q.push({ curPos.second, partner[curPos.second] });
//				visit[curPos.second] = 1;
//				//visit[curPos.second] = visit[curPos.first];
//			}
//
//		}
//		cout << totalCnt << '\n';
//	}
//
//
//	return 0;
//}
//
//
