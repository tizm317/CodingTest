//#include <iostream>
//#include <queue>
//#include <utility>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 08. 07. 월
//// 문제 번호	: #21610
//// 문제 이름	: 마법사 상어와 비바라기
//// 알고리즘	: 시뮬레이션, 큐
//// 시간복잡도: O()
//
//int N; // <= 50
//int bucket[55][55];
//
//int M; // <= 100
//queue<pair<int, int>> commandQ; // 명령 큐
//
//queue<pair<int, int>> cloudQ; // 구름 큐
//
//const int dRow[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
//const int dCol[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
//
//void printBuckets();
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//
//	// 각 칸에 저장된 물의 양 입력
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cin >> bucket[r][c];
//		}
//	}
//
//	// 이동 명령 입력
//	for (int m = 0; m < M; m++)
//	{
//		int dir, dist;
//		cin >> dir >> dist;
//
//		// 큐에 저장
//		commandQ.push({ dir - 1, dist }); // 0-based idx
//	}
//
//	// 비구름 시작지점, 비구름 큐에 저장
//	for (int r = N - 2; r < N; r++)
//		for (int c = 0; c < 2; c++)
//			cloudQ.push({ r, c });
//	//cloudQ.push({ N - 1, 0 });
//	//cloudQ.push({ N - 1, 1 });
//	//cloudQ.push({ N - 2, 0 });
//	//cloudQ.push({ N - 2, 1 });
//
//	// 디버깅용 - 시작 상태 출력
//	printBuckets();
//
//	// 명령이 다 빌 때까지 반복
//	while (!commandQ.empty())
//	{
//		// 현재 명령
//		pair<int, int> command = commandQ.front(); commandQ.pop();
//		
//		// 방향, 거리
//		const int dir = command.first;
//		const int dist = command.second;
//
//		// 비가 내린 위치 큐 -> 물 복사 버그
//		queue<pair<int, int>> rainedPosQ;
//
//		// 구름이 사라진 위치 체크하기 위한 배열 -> 사라진 곳에서 새로 구름 생기지 않음
//		bool beforeCloud[55][55] = { false, };
//
//		// 1. 모든 구름이 dir 방향으로 dist칸 이동한다.
//		while (!cloudQ.empty())
//		{
//			// 현재 구름
//			pair<int, int> cloud = cloudQ.front(); cloudQ.pop(); // 구름이 모두 사라진다.
//
//			// 이동한 위치 // 밑에꺼보다 더 간단하고 깔끔한 방법
//			//int nextR = (cloud.first + dRow[dir] * dist + N * dist) % N;
//			int nextR = (cloud.first + (dRow[dir] + N) * dist) % N; // 정리 버전
//			int nextC = (cloud.second + (dCol[dir] + N) * dist) % N;
//
//			// 위치 범위 조정 필요 (더 쉬운 방법이 있을 거 같은데...) <<
//				// 음수일 때,
//			//while (nextR < 0)
//			//{
//			//	nextR += N;
//			//}
//			//nextR %= N;
//
//			//while (nextC < 0)
//			//{
//			//	nextC += N;
//			//}
//			//nextC %= N;
//
//			// 2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
//			bucket[nextR][nextC]++;
//
//			// 구름이 사라진 위치 체크
//			beforeCloud[nextR][nextC] = true;
//
//			// 물이 증가한 칸을 큐에 저장
//			rainedPosQ.push({ nextR, nextC });
//		}
//		
//		// 디버깅 용 - 비 내린 후 상태 출력
//		printBuckets();
//
//
//		// 2에서 물이 증가한 칸 (r, c)에 물복사버그 마법을 시전한다.
//			// 물복사버그 마법을 사용하면, 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수만큼 (r, c)에 있는 바구니의 물이 양이 증가한다.
//		while (!rainedPosQ.empty())
//		{
//			// 비가 내린 위치
//			pair<int, int> rainedPos = rainedPosQ.front(); rainedPosQ.pop();
//			int rainedRow = rainedPos.first;
//			int rainedCol = rainedPos.second;
//
//			// 비가 내린 위치의 대각선의 물이 존재하는 개수만큼 물 복사 버그
//			for (int rr = -1; rr <= 1; rr++)
//			{
//				if (rr == 0) continue;
//
//				for (int cc = -1; cc <= 1; cc++)
//				{
//					if (cc == 0) continue;
//
//					// 대각선 R, C
//					const int diagnalR = rainedRow + rr;
//					const int diagnalC = rainedCol + cc;
//
//					// 이때는 이동과 다르게 경계를 넘어가는 칸은 대각선 방향으로 거리가 1인 칸이 아니다.
//					if (diagnalR < 0 || diagnalR >= N || diagnalC < 0 || diagnalC >= N) continue;
//					
//					if (bucket[diagnalR][diagnalC] > 0)
//					{
//						bucket[rainedRow][rainedCol]++;
//					}
//				}
//			}
//		}
//
//		// 디버깅용 - 물복사 버그 후 상태 출력
//		printBuckets();
//
//		// 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다.
//		for (int r = 0; r < N; r++)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				// 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
//				if (beforeCloud[r][c] == true) continue;
//
//				if (bucket[r][c] >= 2)
//				{
//					cloudQ.push({ r,c });
//					bucket[r][c] -= 2;
//				}
//			}
//		}
//
//		// 디버깅용 - 구름 생긴 후 상태 출력
//		printBuckets();
//	}
//
//	// 전체 남은 물 개수 계산 후 출력
//	int totalWaterCnt = 0;
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			totalWaterCnt += bucket[r][c];
//		}
//	}
//	cout << totalWaterCnt;
//
//	return 0;
//}
//
//void printBuckets()
//{
//	cout << '\n';
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cout << bucket[r][c] << " ";
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//}