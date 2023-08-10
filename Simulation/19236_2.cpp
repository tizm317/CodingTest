//#include <iostream>
//#include <vector>
//#include <tuple>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 08. 10. 목
//// 문제 번호	: #19236
//// 문제 이름	: 청소년 상어
//// 알고리즘	: 시뮬레이션, 백트래킹
//// 시간복잡도: O()
//
//const int N = 4;
//int board[N + 1][N + 1];
//
//// 0 : shark
//// 1~16 : fish
//vector<tuple<int, int, int>> fishVec = vector<tuple<int,int,int>>(17); // (r, c, dir)
//
//const int dRow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
//const int dCol[8] = {0, -1, -1, -1, 0, 1, 1, 1};
//
//int maxDeadFishNumSum;
//
//void printBoard(const int curBoard[][5], const vector<tuple<int, int, int>> curFishVec);
//void Move(const vector<tuple<int, int, int>> curFishVec, const int curBoard[][5]);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int fishNum = 0, dir = 0;
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cin >> fishNum >> dir;
//
//			if (r == 0 && c == 0)
//			{
//				// 상어 위치 Vec 와 board 모두 추가
//				fishVec[0] = { r,c, dir - 1 };
//				board[0][0] = 0;
//
//				// 죽은 물고기
//				fishVec[fishNum] = { -1,-1,-1 };
//				continue;
//			}
//
//			// 물고기 Vec 와 board 에 모두 추가
//			fishVec[fishNum] = { r, c, dir - 1 };
//			board[r][c] = fishNum;
//		}
//	}
//
//	cout << "초기 상태 : " << '\n';
//	printBoard(board, fishVec);
//
//	Move(fishVec, board);
//	
//	// 결과 출력
//	cout << maxDeadFishNumSum;
//
//	return 0;
//}
//
//void printBoard(const int curBoard[][5], const vector<tuple<int, int, int>> curFishVec)
//{
//	// 디버깅용 print 함수
//	// 물고기 번호, 방향 모두 출력
//
//	cout << "물고기 번호 " << '\n';
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cout << curBoard[r][c] << " ";
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//
//	cout << "물고기 방향 " << '\n';
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			// 죽은 물고기 방향 X 표시
//			if (curBoard[r][c] < 0)
//			{
//				cout << "X ";
//				continue;
//			}
//
//			// 나머지 물고기 방향 표시
//			cout << get<2>(curFishVec[curBoard[r][c]]) << " ";
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//}
//
//void Move(const vector<tuple<int, int, int>> curFishVec, const int curBoard[][5])
//{
//	// 다음 board판 초기화
//	int nextBoard[N + 1][N + 1];
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			nextBoard[i][j] = curBoard[i][j];
//
//	// 다음 FishVec 초기화
//	vector<tuple<int, int, int>> nextFishVec = curFishVec;
//
//	// 1. 물고기 이동
//	// 물고기 : 1 ~ 16
//	for (int fishNum = 1; fishNum <= 16; fishNum++)
//	{
//		const tuple<int, int, int> fish = nextFishVec[fishNum];
//		const int curR = get<0>(fish);
//		const int curC = get<1>(fish);
//		const int curDir = get<2>(fish);
//		// 죽은 물고기 제외
//		if (curR == -1 || curC == -1 || curDir == -1) continue;
//
//		// 다음 위치 계산
//		int nextDir = curDir;
//		while (true)
//		{
//			int nextR = curR + dRow[nextDir];
//			int nextC = curC + dCol[nextDir];
//
//			// 범위 넘어가는 경우
//			// 상어인 경우
//			if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N || nextBoard[nextR][nextC] == 0)
//			{
//				// 45도 반시계 회전
//				nextDir = (nextDir + 1) % 8;
//				if (nextDir == curDir)
//				{
//					// 360도 회전
//					break;
//				}
//				continue;
//			}
//
//			const int nextFishNum = nextBoard[nextR][nextC];
//
//			// 위치 교환
//			// 1. fishVec 수정
//				// 1) 내 위치 변경
//			nextFishVec[fishNum] = { nextR, nextC, nextDir };
//
//				// 2) 상대 위치 변경
//			// 상대 공간이 빈공간이 아닌 경우에 (빈공간은 바꿀 필요 X)
//			if (nextFishNum != -1)
//			{
//				const int nextFishDir = get<2>(nextFishVec[nextFishNum]);
//				nextFishVec[nextFishNum] = { curR, curC, nextFishDir }; // 방향은 자기의 방향 가짐
//			}
//
//			// 2. board 수정
//			swap(nextBoard[curR][curC], nextBoard[nextR][nextC]);
//
//			//cout << "fishNum : " << fishNum << " <-> " << nextFishNum << '\n';
//			//printBoard(nextBoard, nextFishVec);
//			break;
//		}
//	}
//
//	cout << "모든 물고기 이동 후 : " << '\n';
//	printBoard(nextBoard, nextFishVec);
//
//	// 2. 상어 이동
//	// 상어가 모든 이동을 못 하는 경우 체크하기 위한 bool 변수
//	bool isSharkMoved = false;
//
//	const tuple<int, int, int> shark = nextFishVec[0];
//	const int curSharkR = get<0>(shark);
//	const int curSharkC = get<1>(shark);
//	const int curSharkDir = get<2>(shark);
//
//	// 다음 위치 계산
//		// 거리 1~3까지 이동 가능
//	for (int dist = 1; dist < N; dist++)
//	{
//		int nextSharkR = curSharkR + dRow[curSharkDir] * dist;
//		int nextSharkC = curSharkC + dCol[curSharkDir] * dist;
//
//		// 범위 넘는 경우 제외
//		if (nextSharkR < 0 || nextSharkR >= N || nextSharkC < 0 || nextSharkC >= N)
//			continue;
//
//		const int deadFishNum = nextBoard[nextSharkR][nextSharkC];
//		// 빈공간 제외
//		if (deadFishNum == -1) continue;
//
//		// 상대방 물고기
//		const tuple<int, int, int> deadFish = nextFishVec[deadFishNum];
//
//		// 1. FishVec 수정
//			// 1) 상어 위치 변경, 방향 변경
//		nextFishVec[0] = { nextSharkR, nextSharkC, get<2>(deadFish) };
//			// 2) 물고기 죽음
//		nextFishVec[deadFishNum] = { -1, -1, -1 };
//
//		// 2. board 수정
//			// 1) 다음 상어 위치 - 0
//		nextBoard[nextSharkR][nextSharkC] = 0;
//			// 2) 이전 상어 위치 - 빈 공간(-1)
//		nextBoard[curSharkR][curSharkC] = -1;
//
//		cout << "상어 " << curSharkDir << " 방향으로 " << dist << "만큼 이동" << '\n';
//		printBoard(nextBoard, nextFishVec);
//
//		// 재귀호출
//		Move(nextFishVec, nextBoard);
//		// 이동했음을 표시
//		isSharkMoved = true;
//
//		// 복구
//		// 1. board 복구
//		nextBoard[curSharkR][curSharkC] = 0; // 상어 위치
//		nextBoard[nextSharkR][nextSharkC] = deadFishNum; // [주의] -1 이 아니고 원래 물고기 번호
//		// 2. FishVec 수정
//		nextFishVec[deadFishNum] = deadFish;
//		nextFishVec[0] = shark;
//	}
//
//	// 탈출 조건
//		// 상어가 모든 거리에 대해서 이동 불가인 경우!
//	if (!isSharkMoved)
//	{
//		cout << '\n';
//
//		// 죽은 물고기 번호의 합 계산
//		int deadFishNumSum = 0;
//		for (int i = 1; i <= 16; i++)
//		{
//			if (get<0>(nextFishVec[i]) != -1) continue;
//			if (get<1>(nextFishVec[i]) != -1) continue;
//			if (get<2>(nextFishVec[i]) != -1) continue;
//
//			deadFishNumSum += i;
//		}
//		cout << deadFishNumSum << '\n';
//
//		// 최대 값 계산
//		maxDeadFishNumSum = max(maxDeadFishNumSum, deadFishNumSum);
//
//		return;
//	}
//}