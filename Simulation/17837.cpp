//#include <iostream>
//#include <tuple>
//#include <vector>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 20xx. xx. xx.
//// 문제 번호	: #00000 
//// 문제 이름	: 
//// 알고리즘	: 
//// 시간복잡도: O()
//
//int N;
//int board[15][15]; // 0 흰, 1 빨, 2 파
//vector<int> chessPieceInBoard[15][15];
//
//int K;
//
//vector<tuple<int, int, int>> chessPiecesVec; // {r, c, 현재 칸에서 몇번째 위치에 있는지 idx}
//int chessDirs[15] = { 0, }; // 체스말의 방향 저장용 배열
//
//// 우좌상하
//const int dRow[4] = { 0, 0, -1, 1 };
//const int dCol[4] = { 1, -1, 0, 0 };
//
//const int WHITE = 0;
//const int RED = 1;
//const int BLUE = 2;
//
//void blueSpace()
//{
//
//}
//
//void redSpace()
//{
//
//}
//
//void whiteSpace()
//{
//
//}
//
//void print()
//{
//	cout << '\n';
//	for (auto& chess : chessPiecesVec)
//	{
//		cout << get<0>(chess) << " " << get<1>(chess) << " " << get<2>(chess);
//
//		cout << '\n';
//	}
//}
//
//void printBoard(int chessNum)
//{
//	cout << '\n';
//	cout << chessNum << " 이동 후 :\n";
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cout << chessPieceInBoard[r][c].size() << " ";
//		}
//		cout << '\n';
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> K;
//	// 체스판 입력
//	for (int r = 0; r < N; r++)
//		for (int c = 0; c < N; c++)
//			cin >> board[r][c];
//
//	// 체스말 위치, 방향 입력
//	for (int k = 0; k < K; k++)
//	{
//		int r, c, dir;
//		cin >> r >> c >> dir;
//		
//		const int chessNum = chessPiecesVec.size();
//
//		// 체스말 순서 벡터
//		// 현재 칸의 가장 아래(0) 에 배치됨. (중복 X)
//		chessPiecesVec.push_back({ r - 1,c - 1, 0}); // 1-based -> 0-based idx 수정
//
//		// 체스말의 방향 저장
//		chessDirs[chessNum] = dir - 1;
//
//		// 
//		chessPieceInBoard[r - 1][c - 1].push_back(chessNum);
//	}
//
//	int turnNum = 1;
//	//print();
//	//printBoard(-1);
//	while (true)
//	{
//		//cout << " >>>>>>" << turnNum << "턴 : ";
//
//		// 그 값이 1,000보다 크거나 절대로 게임이 종료되지 않는 경우에는 -1을 출력한다.
//		if (turnNum > 1000)
//		{
//			turnNum = -1;
//			break;
//		}
//
//		// 체스말 순서대로 이동
//		//for (auto& chess : chessPiecesVec)
//		for(int chessNum = 0; chessNum < chessPiecesVec.size(); chessNum++)
//		{
//			//printBoard();
//
//			// 체스말
//			auto& chess = chessPiecesVec[chessNum];
//
//			// 현재 위치
//			int& curR = get<0>(chess);
//			int& curC = get<1>(chess);
//			
//			// 현재 방향
//			int& dir = chessDirs[chessNum];
//
//			// 다음 위치
//			int nextR = curR + dRow[dir];
//			int nextC = curC + dCol[dir];
//
//			
//			// 파란색인 경우에는 A번 말의 이동 방향을 반대로 하고 한 칸 이동한다. 
//			// 체스판을 벗어나는 경우에는 파란색과 같은 경우이다.
//			if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N || board[nextR][nextC] == BLUE)
//			{
//				// 방향 반대
//				if (dir % 2 == 0) dir++;
//				else dir--;
//
//				// 반대 방향으로 1칸 이동한 다음 위치
//				nextR = curR + dRow[dir];
//				nextC = curC + dCol[dir];
//
//				// {r,c} 위치 몇번째 idx
//				int& idx = get<2>(chess);
//				// temp 벡터에 저장
//				vector<int> temp;
//				for (int i = idx; i < chessPieceInBoard[curR][curC].size(); i++)
//					temp.push_back(chessPieceInBoard[curR][curC][i]);
//
//				// 1. 다음 칸이 Blue
//					// 방향을 반대로 바꾼 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 가만히 있는다.
//				if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N || board[nextR][nextC] == BLUE)
//				{
//
//					// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<, 이게 아니였음.. 근데 그럼 마지막 테케는 왜 틀렸던거고, 뭐 때문에 다시 맞았지??
//					// 방향만 다 바꿔줘
//					//for (int i = 1; i < temp.size(); i++) // i == 0 은 이미 바꿈
//					//{
//					//	const int chessNum = temp[i];
//					//	int& dir = chessDirs[chessNum];
//					//	// 방향 반대
//					//	if (dir % 2 == 0) dir++;
//					//	else dir--;
//					//}
//
//					// 4개 쌓였는지 체크
//					if (chessPieceInBoard[curR][curC].size() >= 4)
//					{
//						cout << turnNum;
//						//printBoard(chessNum);
//						//print();
//						return 0;
//					}
//				
//					//printBoard(chessNum);
//					continue;
//				}
//
//				//// {r,c} 위치 몇번째 idx
//				//int& idx = get<2>(chess);
//				//// temp 벡터에 저장
//				//vector<int> temp;
//				//for (int i = idx; i < chessPieceInBoard[curR][curC].size(); i++)
//				//	temp.push_back(chessPieceInBoard[curR][curC][i]);
//
//				// 나간 놈들 지우기
//				const int size = chessPieceInBoard[curR][curC].size();
//				for (int i = idx; i < size; i++)
//					chessPieceInBoard[curR][curC].pop_back();
//
//				int nextIdx = chessPieceInBoard[nextR][nextC].size();
//
//				if (board[nextR][nextC] == RED)
//				{
//					// 2. 다음 칸이 Red
//					// 순서 거꾸로
//					for (int i = temp.size() - 1; i >= 0; i--)
//					{
//						chessPieceInBoard[nextR][nextC].push_back(temp[i]);
//
//						const int chessNum = temp[i];
//						// 위치 변경
//						int& curR = get<0>(chessPiecesVec[chessNum]);
//						curR = nextR;
//						int& curC = get<1>(chessPiecesVec[chessNum]);
//						curC = nextC;
//
//						// idx 변경
//						int& idx = get<2>(chessPiecesVec[chessNum]);
//						idx = nextIdx + (temp.size() - i - 1);
//					}
//				}
//				
//				if (board[nextR][nextC] == WHITE)
//				{
//					// 3. 다음 칸이 White
//					// 순서 그대로
//					//for (auto& chess : temp)
//					for (int i = 0; i < temp.size(); i++)
//					{
//						chessPieceInBoard[nextR][nextC].push_back(temp[i]);
//
//						const int chessNum = temp[i];
//						// 위치 변경
//						int& curR = get<0>(chessPiecesVec[chessNum]);
//						curR = nextR;
//						int& curC = get<1>(chessPiecesVec[chessNum]);
//						curC = nextC;
//
//						// idx 변경
//						int& idx = get<2>(chessPiecesVec[chessNum]);
//						idx = nextIdx + i;
//					}
//				}
//
//				// 현재 위치 변경
//				//curR = nextR;
//				//curC = nextC;
//
//				// 4개 쌓였는지 체크
//				if (chessPieceInBoard[nextR][nextC].size() >= 4)
//				{
//					cout << turnNum;
//					//printBoard(chessNum);
//					//print();
//					return 0;
//				}
//
//				//printBoard(chessNum);
//				continue;
//			}
//
//			// {r,c} 위치 몇번째 idx
//			const int& idx = get<2>(chess);
//			// temp 벡터에 저장
//			vector<int> temp;
//			for (int i = idx; i < chessPieceInBoard[curR][curC].size(); i++)
//				temp.push_back(chessPieceInBoard[curR][curC][i]);
//
//			// 나간 놈들 지우기
//			const int size = chessPieceInBoard[curR][curC].size();
//			for (int i = idx; i < size; i++)
//				chessPieceInBoard[curR][curC].pop_back();
//
//			int nextIdx = chessPieceInBoard[nextR][nextC].size();
//
//			if (board[nextR][nextC] == RED)
//			{
//				// 2. 다음 칸이 Red
//				// 순서 거꾸로
//				for (int i = temp.size() - 1; i >= 0; i--)
//				{
//					chessPieceInBoard[nextR][nextC].push_back(temp[i]);
//					const int chessNum = temp[i];
//
//					// 위치 변경
//					int& curR = get<0>(chessPiecesVec[chessNum]);
//					curR = nextR;
//					int& curC = get<1>(chessPiecesVec[chessNum]);
//					curC = nextC;
//
//					// idx 변경
//					int& idx = get<2>(chessPiecesVec[chessNum]);
//					idx = nextIdx + (temp.size() - i - 1);
//				}
//
//				//continue;
//			}
//
//			if (board[nextR][nextC] == WHITE)
//			{
//				// 3. 다음 칸이 White
//				// 순서 그대로
//				//for (auto& chess : temp)
//				for (int i = 0; i < temp.size(); i++)
//				{
//					chessPieceInBoard[nextR][nextC].push_back(temp[i]);
//					const int chessNum = temp[i];
//					// 위치 변경
//					int& curR = get<0>(chessPiecesVec[chessNum]);
//					curR = nextR;
//					int& curC = get<1>(chessPiecesVec[chessNum]);
//					curC = nextC;
//
//					// idx 변경
//					int& idx = get<2>(chessPiecesVec[chessNum]);
//					idx = nextIdx + i;
//				}
//			}
//
//			// 현재 위치 변경
//			//curR = nextR;
//			//curC = nextC;
//
//			// 4개 쌓였는지 체크
//			if (chessPieceInBoard[nextR][nextC].size() >= 4)
//			{
//				cout << turnNum;
//				//printBoard(chessNum);
//				//print();
//				return 0;
//			}
//
//			//printBoard(chessNum);
//		}
//
//		// 턴 증가
//		turnNum++;
//
//		//printBoard();
//		//print();
//	}
//
//	// 게임이 종료되는 턴의 번호를 출력한다
//	cout << turnNum;
//
//	return 0;
//}
//
///*
//12 10
//0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0
//2 1 1
//3 2 3
//2 2 1
//4 1 2
//1 1 1
//1 2 1
//1 3 1
//1 4 1
//2 4 3
//3 3 3
//*/