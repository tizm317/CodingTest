//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 26. 수
//// 문제 번호	: #15684 
//// 문제 이름	: 사다리 조작
//// 알고리즘	: 시뮬레이션, 백트래킹?
//// 시간복잡도: O()
//
//int N; // 세로 선의 개수 <= 10
//int M; // 가로 선의 개수 (최대 270)
//int H; // 가로 선 놓을 수 있는 위치 개수 <= 30
//
//// 사다리 배열
//// 가로 1 <= a <= H
//// 세로 1 <= b : b, b+1 연결 <= N-1
//int ladder[35][15]; // 가로 H, 세로 N
//// 0 : 연결 되지 않은 가로선 위치
//// 1 : 연결된 가로선 (위치)
//// -1 : 연결할 수 없는 가로선 위치 (옆에 연결된 가로선이 있을 경우)
//
//int ans = -1;
//
//// 전체 사다리 타기
//bool ladderMove(const int ladder[35][15]);
//
//// 사다리에 가로줄 추가하는 함수
//void addVerticalLine(int addedVerticalLineCnt, int ladder[35][15], int rr, int cc);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M >> H;
//
//	// 가로 선 위치 입력
//	for (int r = 0; r < M; r++)
//	{
//		int a, b;
//		cin >> a >> b;
//		
//		// a번 점선 위치에 b, b+1 연결 표시
//		ladder[a][b] = 1;
//		
//		// 좌우 인접한 점선 위치 연결 불가능 -1 표시
//			// a번 점선 위치에 b-1, b 연결 불가능	
//		ladder[a][b - 1] = -1;
//			// a번 점선 위치에 b, b+1 연결 불가능	
//		ladder[a][b + 1] = -1;
//	}
//
//	addVerticalLine(0, ladder, 1, 1);
//
//	cout << ans;
//
//	return 0;
//}
//
//// 전체 사다리 타기
//bool ladderMove(const int ladder[35][15])
//{
//	// O(N*H)
//
//	// 세로줄 시작넘버 
//	for (int startLine = 1; startLine <= N; startLine++)
//	{
//		// 현재 줄넘버
//		int curLineNum = startLine;
//
//		// 아래로 이동
//		for (int c = 1; c <= H; c++)
//		{
//			// (우/좌) 연결되지 않으면 아래로 이동 continue
//			if (ladder[c][curLineNum] != 1 && ladder[c][curLineNum - 1] != 1)
//				continue;
//
//			// 오른쪽 이동 (curLineNum, curLineNum+1) 연결
//			if (ladder[c][curLineNum] == 1)
//			{
//				curLineNum++;
//				continue;
//			}
//
//			// 왼쪽 이동 (curLineNum-1, curLineNum) 연결
//			if (ladder[c][curLineNum - 1] == 1)
//			{
//				curLineNum--;
//				continue;
//			}
//		}
//
//		// 맨 아래 도착 - 시작라인넘버랑 도착라인넘버 다른 경우 false
//		if (curLineNum != startLine)
//			return false;
//	}
//
//	// 모든 세로줄이 시작라인넘버와 도착라인넘버 같은 경우 true
//	return true;
//}
//
//// 사다리에 가로줄 추가하는 함수
////bool isSuccess = false;
//void addVerticalLine(const int addedVerticalLineCnt, int ladder[35][15], int rr, int cc)
//{
//	// 0. i번 세로선의 결과가 i번 나오는지 확인
//	if (ladderMove(ladder) == true)
//	{
//		ans = (ans == -1) ? addedVerticalLineCnt : min(ans, addedVerticalLineCnt);
//		//isSuccess = true; // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 시간초과 개선하려고 했던 게 오히려 문제였네, cnt 더 작은 경우 가능함
//		return;
//	}
//
//	// 추가한 가로선이 3개 이상이면 return
//	if (addedVerticalLineCnt >= 3)
//		return;
//
//	//// 다음 사다리 배치 초기화
//	//int nextLadder[35][15] = { 0, };
//	//for (int r = 0; r < 35; r++)
//	//	for (int c = 0; c < 15; c++)
//	//		nextLadder[r][c] = ladder[r][c];
//
//	// 가로선 추가 경우의 수
//	for (int r = 1; r <= H; r++) // 1 ~ H
//	{
//		for (int c = 1; c <= N - 1; c++) // 1 ~ N-1
//		{
//			// 사다리 둘 수 없는 곳 제외
//			if (ladder[r][c] != 0)
//				continue;
//
//			// 같은 사다리 가로선 선택하는 경우 제외<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//			if (r * (N - 1) + c < rr * (N - 1) + cc)
//				continue;
//
//			// 새로운 사다리 배치
//			ladder[r][c] = 1;
//			// 인접한 좌우 사다리 위치 불가능해짐
//			const int tmp1 = ladder[r][c - 1];
//			ladder[r][c - 1] = -1;
//			
//			const int tmp2 = ladder[r][c + 1];
//			ladder[r][c + 1] = -1;
//
//			addVerticalLine(addedVerticalLineCnt + 1, ladder, r, c); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//			/*if (isSuccess)
//				return;*/
//
//			// 추가한 사다리 제거
//			ladder[r][c] = 0;
//			ladder[r][c - 1] = tmp1;
//			ladder[r][c + 1] = tmp2;
//		}
//	}
//
//}