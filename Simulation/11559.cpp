//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//#include <utility>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 20. 목
//// 문제 번호	: #11559 
//// 문제 이름	: Puyo Puyo
//// 알고리즘	: 시뮬레이션, BFS
//// 시간복잡도: O()
//
//vector<string> field;
//// R G B P Y
//// . 빈칸
//
//int combo;
//
//#define ROW first
//#define COL second
//queue<pair<int, int>> Q;
//queue<pair<int, int>> connectedPuyoQueue; // 뿌요 터트리기 위해서 연결된 뿌요 큐로 들고 있음
//const int dRow[4] = { -1, 0, 1, 0 };
//const int dCol[4] = { 0, 1, 0, -1 };
//
//// 필드의 row, col 값
//const int R = 12;
//const int C = 6;
//
//void popPuyo(bool& isPuyoPop);
//void moveDown();
//void printField();
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 필드 입력
//	for (int row = 0; row < R; row++)
//	{
//		string s;
//		cin >> s;
//		field.push_back(s);
//	}
//
//	// 게임 진행
//	while(true)
//	{
//		// 아래로 이동할 지 여부와 게임 종료 여부를 판단하기 위한 bool 변수 초기화
//		bool isPuyoPop = false;
//
//		// 터트리기
//		popPuyo(isPuyoPop);
//		
//		// 터진 게 없으면 탈출
//		if (!isPuyoPop)
//			break;
//		
//		// 콤보 업
//		combo++;
//
//		// 아래로 이동
//		moveDown();
//
//		//printField();
//	}
//
//	// 콤보 출력
//	cout << combo;
//
//	//printField();
//
//	return 0;
//}
//
//void popPuyo(bool& isPuyoPop)
//{
//	// 아래서부터 Flood Fill
//	// vis 배열 초기화
//	bool vis[R][C] = { false, };
//
//	// 시작점 찾기
//	for (int r = R - 1; r >= 0; r--)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			// 빈칸 X
//			if (field[r][c] == '.')
//				continue;
//
//			// 시작점 찾아서 Q, connectedPuyoQueue 에 넣음
//			Q.push({ r,c });
//			connectedPuyoQueue.push({ r,c });
//
//			// 방문 표시
//			vis[r][c] = true;
//
//			// 4개 이상 연결되었는지 파악하기 위한 cnt 변수 
//			// -> connectedPuyoQueue.size() 사용하면 됨 (cnt 따로 체크할 필요 없음)
//			//int cnt = 1;
//
//			while (!Q.empty())
//			{
//				// 현재 뿌요 위치
//				pair<int, int> curPos = Q.front(); Q.pop();
//				// 현재 뿌요 색깔
//				const char curColor = field[curPos.ROW][curPos.COL];
//
//				for (int dir = 0; dir < 4; dir++)
//				{
//					// 다음 위치 계산
//					int nRow = curPos.ROW + dRow[dir];
//					int nCol = curPos.COL + dCol[dir];
//
//					// 배열 범위 넘어가는 지 체크
//					if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C)
//						continue;
//
//					// 중복 방문 방지
//					if (vis[nRow][nCol])
//						continue;
//
//					// 다음 뿌요 색깔하고 비교
//					const char nColor = field[nRow][nCol];
//					if (curColor != nColor)
//						continue;
//
//					// 같은 색이면 Q, connectedPuyoQueue 에 넣고, 방문 표시
//					Q.push({ nRow, nCol });
//					connectedPuyoQueue.push({ nRow, nCol });
//					vis[nRow][nCol] = true;
//					//cnt++;
//				}
//			}
//
//			// 뿌요 터트리기
//			//if (cnt >= 4)
//			if (connectedPuyoQueue.size() >= 4)
//			{
//				while (!connectedPuyoQueue.empty())
//				{
//					pair<int, int> Puyo = connectedPuyoQueue.front(); connectedPuyoQueue.pop();
//					//cout << Puyo.ROW << " " << Puyo.COL << '\n';
//					field[Puyo.ROW][Puyo.COL] = '.';
//					isPuyoPop = true;
//				}
//
//			}
//
//			// 큐 비워주기
//			while (!connectedPuyoQueue.empty())
//				connectedPuyoQueue.pop();
//		}
//	}
//}
//
//void moveDown()
//{
//	// 1개의 column 씩 아래로 이동시킴
//	for (int c = 0; c < C; c++)
//	{
//		// 아래부터 이동시킴
//		for (int r = R - 1; r >= 0; r--)
//		{
//			// 빈칸 X
//			if (field[r][c] == '.')
//				continue;
//
//			int curRow = r;
//			int nRow = curRow;
//			while (true)
//			{
//				// 아래로 이동
//				nRow += dRow[2];
//
//				// 배열 범위 넘는지 체크
//				if (nRow >= R)
//					break;
//
//				// 아래칸이 빈 칸인지 체크
//				if (field[nRow][c] != '.')
//					break;
//
//				// 아래로 이동
//					// 아래칸 먼저 바꾸고, 현재칸 비우기
//				field[nRow][c] = field[curRow][c];
//				field[curRow][c] = '.';
//				// 현재 위치를 다음 위치로 갱신
//				curRow = nRow;
//			}
//		}
//	}
//}
//
//void printField()
//{
//	// 디버깅 용
//	// 필드 전체 출력
//	for (int row = 0; row < R; row++)
//	{
//		cout << field[row] << '\n';
//	}
//}
