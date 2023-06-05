//#include <iostream>
//#include <string>
//#include <utility>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 18. 목
//// 문제 번호	: #1941 
//// 문제 이름	: 소문난 칠공주
//// 알고리즘	: 
//// 시간복잡도: O()
//
//#define ROW first
//#define COL second
//
//const int dRow[4] = { 0, 1, 0, -1 };
//const int dCol[4] = { 1, 0, -1, 0 };
//
//int students[5][5]; // S : 0 , Y : 1
//int a[25]; // 1 - 7개
//int totalCnt; // 7공주 경우의 수
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	for (int i = 0; i < 5; i++)
//	{
//		string str;
//		getline(cin, str);
//		for (int j = 0; j < 5; j++)
//		{
//			if (str[j] == 'S')
//			{
//				students[i][j] = 0;
//			}
//			else // 'Y'
//			{
//				students[i][j] = 1;
//			}
//		}
//	}
//
//	// 25개 중에서 7명 뽑는 경우의 수(조합)
//	// 25C7 = 480'700
//
//	// 1 - 7개, 0 - 18개
//	fill(a + 18, a + 25, 1);
//
//	queue<pair<int, int>> Q;
//
//	do
//	{
//		int memberCnt = 0; // 7공주 멤버수
//		int yCnt = 0; // 최대 3명
//
//		bool isused[5][5] = { 0, };
//
//		// 시작점 찾기
//		bool find = false;
//		for (int r = 0; r < 5; r++)
//		{
//			for (int c = 0; c < 5; c++)
//			{
//				if (a[c + r * 5] == 0)
//					continue;
//
//				// 임도연파 카운트
//				if (students[r][c] == 1)
//					yCnt = 1;
//
//				isused[r][c] = true;
//				memberCnt = 1;
//				Q.push({r,c});
//				find = true;
//				break;
//			}
//
//			if (find)
//				break;
//		}
//
//		bool success = true;
//		while (!Q.empty())
//		{
//			if (memberCnt == 7)
//				break;
//
//			pair<int, int> curPos = Q.front(); Q.pop();
//
//
//			// 근처 4방위를 살펴봄
//			bool isConnected = false;
//			for (int dir = 0; dir < 4; dir++)
//			{
//				int nRow = curPos.ROW + dRow[dir];
//				int nCol = curPos.COL + dCol[dir];
//
//				// 범위 벗어나는지 체크
//				if (nRow < 0 || nRow >= 5 || nCol < 0 || nCol >= 5)
//					continue;
//
//				// 방문 여부 체크
//				if (isused[nRow][nCol])
//					continue;
//
//
//				// 7공주
//				if (a[nCol + nRow * 5] == 1)
//				{
//					// 임도연파 카운트
//					if (students[nRow][nCol] == 1)
//					{
//						// 임도연파 최대갯수 넘은 경우 pass
//						if (yCnt == 3)
//							break;
//
//						yCnt++;
//					}
//
//					memberCnt++;
//					Q.push({ nRow, nCol });
//					isConnected = true;
//
//					isused[nRow][nCol] = true;
//
//				}
//			}
//
//			// 반례) 모든게 S인 상황
//			// 
//			// 해결)
//			// 큐에 아직 다른게 있을 경우는 괜찮음(큐에 다른게 없다는건 지금꺼가 마지막이니까, 연결이 안 되어 있다면, fail)
//			// (큐에 남은게 있다면, success 가능성 있음)
//			// 연결되지 않은 경우(혹은, 임도연파 최대갯수 넘은 경우)는 pass
//			if (Q.size() == 0 && !isConnected)
//			{
//				success = false;
//				break;
//			}
//		}
//
//		if (success)
//			totalCnt++;
//
//		// 큐 비우기
//		while (!Q.empty())
//			Q.pop();
//
//	} while (next_permutation(a, a + 25));
//
//	cout << totalCnt;
//
//	return 0;
//}
//
//
//
///*
//SSSSS
//SSSSS
//SSSSS
//SSSSS
//SSSSS
//*/