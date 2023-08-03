//#include <iostream>
//#include <tuple>
//#include <vector>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 20xx. xx. xx.
//// ���� ��ȣ	: #00000 
//// ���� �̸�	: 
//// �˰���	: 
//// �ð����⵵: O()
//
//int N;
//int board[15][15]; // 0 ��, 1 ��, 2 ��
//vector<int> chessPieceInBoard[15][15];
//
//int K;
//
//vector<tuple<int, int, int>> chessPiecesVec; // {r, c, ���� ĭ���� ���° ��ġ�� �ִ��� idx}
//int chessDirs[15] = { 0, }; // ü������ ���� ����� �迭
//
//// ���»���
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
//	cout << chessNum << " �̵� �� :\n";
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
//	// ü���� �Է�
//	for (int r = 0; r < N; r++)
//		for (int c = 0; c < N; c++)
//			cin >> board[r][c];
//
//	// ü���� ��ġ, ���� �Է�
//	for (int k = 0; k < K; k++)
//	{
//		int r, c, dir;
//		cin >> r >> c >> dir;
//		
//		const int chessNum = chessPiecesVec.size();
//
//		// ü���� ���� ����
//		// ���� ĭ�� ���� �Ʒ�(0) �� ��ġ��. (�ߺ� X)
//		chessPiecesVec.push_back({ r - 1,c - 1, 0}); // 1-based -> 0-based idx ����
//
//		// ü������ ���� ����
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
//		//cout << " >>>>>>" << turnNum << "�� : ";
//
//		// �� ���� 1,000���� ũ�ų� ����� ������ ������� �ʴ� ��쿡�� -1�� ����Ѵ�.
//		if (turnNum > 1000)
//		{
//			turnNum = -1;
//			break;
//		}
//
//		// ü���� ������� �̵�
//		//for (auto& chess : chessPiecesVec)
//		for(int chessNum = 0; chessNum < chessPiecesVec.size(); chessNum++)
//		{
//			//printBoard();
//
//			// ü����
//			auto& chess = chessPiecesVec[chessNum];
//
//			// ���� ��ġ
//			int& curR = get<0>(chess);
//			int& curC = get<1>(chess);
//			
//			// ���� ����
//			int& dir = chessDirs[chessNum];
//
//			// ���� ��ġ
//			int nextR = curR + dRow[dir];
//			int nextC = curC + dCol[dir];
//
//			
//			// �Ķ����� ��쿡�� A�� ���� �̵� ������ �ݴ�� �ϰ� �� ĭ �̵��Ѵ�. 
//			// ü������ ����� ��쿡�� �Ķ����� ���� ����̴�.
//			if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N || board[nextR][nextC] == BLUE)
//			{
//				// ���� �ݴ�
//				if (dir % 2 == 0) dir++;
//				else dir--;
//
//				// �ݴ� �������� 1ĭ �̵��� ���� ��ġ
//				nextR = curR + dRow[dir];
//				nextC = curC + dCol[dir];
//
//				// {r,c} ��ġ ���° idx
//				int& idx = get<2>(chess);
//				// temp ���Ϳ� ����
//				vector<int> temp;
//				for (int i = idx; i < chessPieceInBoard[curR][curC].size(); i++)
//					temp.push_back(chessPieceInBoard[curR][curC][i]);
//
//				// 1. ���� ĭ�� Blue
//					// ������ �ݴ�� �ٲ� �Ŀ� �̵��Ϸ��� ĭ�� �Ķ����� ��쿡�� �̵����� �ʰ� ������ �ִ´�.
//				if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N || board[nextR][nextC] == BLUE)
//				{
//
//					// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<, �̰� �ƴϿ���.. �ٵ� �׷� ������ ���ɴ� �� Ʋ�ȴ��Ű�, �� ������ �ٽ� �¾���??
//					// ���⸸ �� �ٲ���
//					//for (int i = 1; i < temp.size(); i++) // i == 0 �� �̹� �ٲ�
//					//{
//					//	const int chessNum = temp[i];
//					//	int& dir = chessDirs[chessNum];
//					//	// ���� �ݴ�
//					//	if (dir % 2 == 0) dir++;
//					//	else dir--;
//					//}
//
//					// 4�� �׿����� üũ
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
//				//// {r,c} ��ġ ���° idx
//				//int& idx = get<2>(chess);
//				//// temp ���Ϳ� ����
//				//vector<int> temp;
//				//for (int i = idx; i < chessPieceInBoard[curR][curC].size(); i++)
//				//	temp.push_back(chessPieceInBoard[curR][curC][i]);
//
//				// ���� ��� �����
//				const int size = chessPieceInBoard[curR][curC].size();
//				for (int i = idx; i < size; i++)
//					chessPieceInBoard[curR][curC].pop_back();
//
//				int nextIdx = chessPieceInBoard[nextR][nextC].size();
//
//				if (board[nextR][nextC] == RED)
//				{
//					// 2. ���� ĭ�� Red
//					// ���� �Ųٷ�
//					for (int i = temp.size() - 1; i >= 0; i--)
//					{
//						chessPieceInBoard[nextR][nextC].push_back(temp[i]);
//
//						const int chessNum = temp[i];
//						// ��ġ ����
//						int& curR = get<0>(chessPiecesVec[chessNum]);
//						curR = nextR;
//						int& curC = get<1>(chessPiecesVec[chessNum]);
//						curC = nextC;
//
//						// idx ����
//						int& idx = get<2>(chessPiecesVec[chessNum]);
//						idx = nextIdx + (temp.size() - i - 1);
//					}
//				}
//				
//				if (board[nextR][nextC] == WHITE)
//				{
//					// 3. ���� ĭ�� White
//					// ���� �״��
//					//for (auto& chess : temp)
//					for (int i = 0; i < temp.size(); i++)
//					{
//						chessPieceInBoard[nextR][nextC].push_back(temp[i]);
//
//						const int chessNum = temp[i];
//						// ��ġ ����
//						int& curR = get<0>(chessPiecesVec[chessNum]);
//						curR = nextR;
//						int& curC = get<1>(chessPiecesVec[chessNum]);
//						curC = nextC;
//
//						// idx ����
//						int& idx = get<2>(chessPiecesVec[chessNum]);
//						idx = nextIdx + i;
//					}
//				}
//
//				// ���� ��ġ ����
//				//curR = nextR;
//				//curC = nextC;
//
//				// 4�� �׿����� üũ
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
//			// {r,c} ��ġ ���° idx
//			const int& idx = get<2>(chess);
//			// temp ���Ϳ� ����
//			vector<int> temp;
//			for (int i = idx; i < chessPieceInBoard[curR][curC].size(); i++)
//				temp.push_back(chessPieceInBoard[curR][curC][i]);
//
//			// ���� ��� �����
//			const int size = chessPieceInBoard[curR][curC].size();
//			for (int i = idx; i < size; i++)
//				chessPieceInBoard[curR][curC].pop_back();
//
//			int nextIdx = chessPieceInBoard[nextR][nextC].size();
//
//			if (board[nextR][nextC] == RED)
//			{
//				// 2. ���� ĭ�� Red
//				// ���� �Ųٷ�
//				for (int i = temp.size() - 1; i >= 0; i--)
//				{
//					chessPieceInBoard[nextR][nextC].push_back(temp[i]);
//					const int chessNum = temp[i];
//
//					// ��ġ ����
//					int& curR = get<0>(chessPiecesVec[chessNum]);
//					curR = nextR;
//					int& curC = get<1>(chessPiecesVec[chessNum]);
//					curC = nextC;
//
//					// idx ����
//					int& idx = get<2>(chessPiecesVec[chessNum]);
//					idx = nextIdx + (temp.size() - i - 1);
//				}
//
//				//continue;
//			}
//
//			if (board[nextR][nextC] == WHITE)
//			{
//				// 3. ���� ĭ�� White
//				// ���� �״��
//				//for (auto& chess : temp)
//				for (int i = 0; i < temp.size(); i++)
//				{
//					chessPieceInBoard[nextR][nextC].push_back(temp[i]);
//					const int chessNum = temp[i];
//					// ��ġ ����
//					int& curR = get<0>(chessPiecesVec[chessNum]);
//					curR = nextR;
//					int& curC = get<1>(chessPiecesVec[chessNum]);
//					curC = nextC;
//
//					// idx ����
//					int& idx = get<2>(chessPiecesVec[chessNum]);
//					idx = nextIdx + i;
//				}
//			}
//
//			// ���� ��ġ ����
//			//curR = nextR;
//			//curC = nextC;
//
//			// 4�� �׿����� üũ
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
//		// �� ����
//		turnNum++;
//
//		//printBoard();
//		//print();
//	}
//
//	// ������ ����Ǵ� ���� ��ȣ�� ����Ѵ�
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