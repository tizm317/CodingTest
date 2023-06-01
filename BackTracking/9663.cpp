////#include <iostream>
////using namespace std;
////
////// 백준 문제 풀이
////// 날짜		: 20xx. xx. xx.
////// 문제 번호	: #00000 
////// 문제 이름	: 
////// 알고리즘	: 
////// 시간복잡도: O()
////
////int N;
////int board[15][15];
////int possibleCnt;
////
////int row[15]; // 0 ~ 14
////int col[15];
////int rightUp[15 * 2 - 1]; // 우상향 대각선 //  0 ~ 28
////int leftDown[15 * 2 - 1];// 좌하향 대각선 // 29
////
////void func(int queenCnt, int nextRow)
////{
////	// 퀸 갯수가 N개면, 성공
////	if (queenCnt == N)
////	{
////		possibleCnt++;
////		return;
////	}
////
////	for (int r = nextRow; r < N; r++)
////	{
////		// 1. 해당 row에 이미 퀸이 존재하면 continue
////		if (row[r] == 1)
////			continue;
////
////		for (int c = 0; c < N; c++)
////		{
////			if (board[r][c] == 1)
////				continue;
////
////			// 2. 해당 col에 이미 퀸이 존재하면 continue
////			if (col[c] == 1)
////				continue;
////
////			// 3. 해당 대각선 줄에 이미 퀸 존재하면,
////			if (rightUp[r + c] == 1)
////				continue;
////
////			// 음수 범위 때문에 + (N-1)
////			if (leftDown[r - c + N - 1] == 1)
////				continue;
////
////			// 모든 경우를 통과하면,
////
////			board[r][c] = 1;
////			row[r] = 1;
////			col[c] = 1;
////			rightUp[r + c] = 1;
////			leftDown[r - c + N - 1] = 1;
////			
////			func(queenCnt + 1, r + 1);
////
////			board[r][c] = 0;
////			row[r] = 0;
////			col[c] = 0;
////			rightUp[r + c] = 0;
////			leftDown[r - c + N - 1] = 0;
////		}
////		
////		// row 가 r일 경우에서, 모든 col을 지나친 경우
////		// 한줄이 아예 비워져버림
////		if (row[r] == 0)
////		{
////			return;
////		}
////	}
////}
////
////int main()
////{
////	ios_base::sync_with_stdio(false);
////	cin.tie(NULL);
////
////	cin >> N;
////	func(0, 0);
////	cout << possibleCnt;
////
////	return 0;
////}
//
//#include <iostream>
//using namespace std;
//
//int N;
//int totalCnt; // 가능한 경우의 수
//
//bool col[15];
//bool rightUp[15 * 2 - 1];
//bool leftDown[15 * 2 - 1];
//
//// row
//void func(int row)
//{
//	// row가 N번째 도달하면 (= 퀸 갯수 N개 놓여진다면)
//	if (row == N)
//	{
//		// 경우의 수 증가
//		totalCnt++;
//		return;
//	}
//
//	// row 열 일 때, col 선택 반복문
//	for (int c = 0; c < N; c++)
//	{
//		if (col[c] == 1)
//			continue;
//
//		if (rightUp[row + c] == 1)
//			continue;
//
//		if (leftDown[row - c + N - 1] == 1) // 범위 조정 (N-1)
//			continue;
//
//		col[c] = 1;
//		rightUp[row + c] = 1;
//		leftDown[row - c + N - 1] = 1;
//		
//		// 다음 줄
//		func(row + 1);
//
//		col[c] = 0;
//		rightUp[row + c] = 0;
//		leftDown[row - c + N - 1] = 0;
//	}
//
//}
//
//int main()
//{
//	cin >> N;
//	func(0);
//
//	cout << totalCnt;
//
//	return 0;
//}