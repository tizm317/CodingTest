//#include <iostream>
//#include <vector>
//#include <queue>
//#include <utility>
//#include <algorithm> // next_permutation
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 31. 월.
//// 문제 번호	: #4991 
//// 문제 이름	: 로봇 청소기
//// 알고리즘	: 시뮬레이션, BFS(여러개), 순열
//// 시간복잡도: O()
//
//// 거리 배열
//	// 3차원 배열
//	// dist[0] : 로봇 청소기 기준 거리 배열
//	// dist[1~10] : 더러운 곳 기준 거리 배열
//int dist[15][25][25];
//
//const int dRow[4] = { -1,0,1,0 };
//const int dCol[4] = { 0,1,0,-1};
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// TC 여러개
//	while (true)
//	{
//		// R, C 입력
//		int R, C;
//		cin >> C >> R; // [주의] 입력 순서 주의할 것! 특히 w, h 로 주어질 때..
//
//		// 0 0 입력 시 종료
//		if (C == 0 && R == 0)
//			break;
//
//		// dist 배열 -1로 초기화
//		for (int i = 0; i < 15; i++)
//			for (int j = 0; j < 25; j++)
//				for (int k = 0; k < 25; k++)
//					dist[i][j][k] = -1;
//
//		// 최소 이동 횟수 (= 최단 거리) 초기화
//		int minDist = -1;
//
//		// 방 상태 배열
//		vector<string> room;
//
//		// 더러운 곳 위치 벡터
//		vector<pair<int, int>> messyPosVec;
//		messyPosVec.push_back({ -1,-1 });// dummy -> index 맞추기 위함(1부터 시작)
//
//		// 로봇청소기 시작 위치
//		pair<int, int> startPos;
//
//		for (int r = 0; r < R; r++)
//		{
//			// 방 상태 입력
//			string s;
//			cin >> s;
//			room.push_back(s);
//
//			// 더러운 곳, 로봇 청소기 위치 입력
//			for (int c = 0; c < C; c++)
//			{
//				if (s[c] == '*')
//					messyPosVec.push_back({ r,c });
//				if (s[c] == 'o')
//					startPos = { r,c };
//			}
//
//		}
//
//		// 로봇, 더러운 곳 모두에 대해서 BFS 를 돌리고, 각각의 dist배열을 만듦
//			// O(R * C * messyPosVec.size() + 1)
//			// R*C*V.size() -> 최대 20*20*10 = 4000
//		queue<pair<int, int>> robotNmessPosQ; // 로봇 + 더러운 곳 담는 큐 for BFS
//		for (int i = 0; i < messyPosVec.size(); i++)
//		{
//			if (i == 0) // dummy 대신 startPos
//			{
//				// 큐에 로봇 청소기 위치 넣고, dist[0] 0 초기화
//				robotNmessPosQ.push(startPos);
//				dist[0][startPos.first][startPos.second] = 0;
//			}
//			else
//			{
//				// 큐에 더러운 곳 위치 넣고, dist[i] 0 초기화
//				robotNmessPosQ.push(messyPosVec[i]);
//				dist[i][messyPosVec[i].first][messyPosVec[i].second] = 0;
//			}
//
//			// BFS
//			while (!robotNmessPosQ.empty())
//			{
//				const pair<int, int> curPos = robotNmessPosQ.front(); robotNmessPosQ.pop();
//				for (int dir = 0; dir < 4; dir++)
//				{
//					int nRow = curPos.first + dRow[dir];
//					int nCol = curPos.second + dCol[dir];
//
//					if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C || room[nRow][nCol] == 'x')
//						continue;
//
//					// dist[i] 기준으로, 중복 제거
//					if (dist[i][nRow][nCol] != -1)
//						continue;
//
//					// 큐에 넣고, dist[i] 계산
//					robotNmessPosQ.push({ nRow, nCol });
//					dist[i][nRow][nCol] = dist[i][curPos.first][curPos.second] + 1;
//				}
//			}
//		}
//
//		// 더러운 곳 청소 순서 정하기 위한 idx 배열 초기화
//			// dummy(0) 제외 1~10
//		int idx[11] = { 0, };
//		for (int i = 0; i <= 10; i++)
//			idx[i] = i;
//
//		// 로봇청소기 청소 순서 (순열, 최대 경우의 수 : 10!)
//			// O(messyPosVec.size()!)
//		do
//		{
//			// 순서대로 청소했을 때 총합 거리
//			int totalDist = 0;
//
//			bool unableToVisit = false;
//
//			// 시작위치-> 다음 위치 반복
//				// i == 0, idx[0] = 0, 로봇 시작 위치
//			for (int i = 0; i < messyPosVec.size() - 1; i++)
//			{
//				// 시작 위치 인덱스
//				const int startIdx = idx[i];
//				// 목적지 위치 인덱스
//				const int destIdx = idx[i + 1];
//
//				// 시작 위치->목적지 위치 의 거리
//					// -1 이면, 도달할 수 없음
//				if (dist[startIdx][messyPosVec[destIdx].first][messyPosVec[destIdx].second] == -1)
//				{
//					unableToVisit = true;
//					break;
//				}
//
//				// 총합 거리에 더함
//				totalDist += dist[startIdx][messyPosVec[destIdx].first][messyPosVec[destIdx].second];
//			}
//
//			// 도달할 수 없는 경우 - 다음 경우의 수..
//			if (unableToVisit)
//				continue;
//
//			// 최단 거리
//			minDist = (minDist == -1) ? totalDist : min(minDist, totalDist);
//
//		} while (next_permutation(idx + 1, idx + messyPosVec.size())); // 1~size() 전까지
//
//		// 최단 거리 출력
//		cout << minDist << '\n';
//	}
//
//	return 0;
//}