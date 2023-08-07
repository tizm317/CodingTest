//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <utility>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 08. 07. ��
//// ���� ��ȣ	: #17135
//// ���� �̸�	: ĳ�� ���潺
//// �˰���	: �ùķ��̼�
//// �ð����⵵: O()
//
//int R, C; // <= 15
//int board[20][20]; // 0 ��ĭ, 1 ��, 2 �ü�
//
//int D;
//
//const int dRow[3] = {0, -1, 0};
//const int dCol[3] = {-1, 0, 1};
//
//void printBoard(int board[][20]);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> R >> C >> D;
//	
//	// �� �迭 �Է�
//	for (int r = 0; r < R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			cin >> board[r][c];
//		}
//	}
//
//	int maxDeadEnemyCnt = 0;
//
//	// idx �迭 �ʱ�ȭ
//		// �޺κ� 3��(C-1, C-2, C-3)�� 1�� �ʱ�ȭ (����)
//	int idx[20] = { 0, }; // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< �̰� ũ�⸦ �� �� ��Ƶ�...;;
//	for (int i = 1; i <= 3; i++)
//		idx[C - i] = 1;
//
//	do
//	{	
//		//cout << "Case <<<<<" << '\n';
//
//		int tempBoard[20][20] = { 0, };
//		for (int r = 0; r <= R; r++)
//		{
//			for (int c = 0; c < C; c++)
//			{
//				tempBoard[r][c] = board[r][c];
//			}
//		}
//
//		// �ü� ��ġ
//		for (int i = 0; i < C; i++)
//		{
//			// 0 : �ü� X
//			if (idx[i] == 0)
//				tempBoard[R][i] = 0;
//			else // 1 : �ü� O
//				tempBoard[R][i] = 2;
//		}
//
//		//cout << "�ʱ� ����" << '\n';
//		//printBoard(tempBoard);
//
//		//
//		int killCnt = 0;
//		while (true)
//		{
//			int nextBoard[20][20] = { 0, };
//			for (int r = 0; r <= R; r++)
//			{
//				for (int c = 0; c < C; c++)
//				{
//					nextBoard[r][c] = tempBoard[r][c];
//				}
//			}
//
//			// dist �迭 �ʱ�ȭ
//			int dist[20][20];
//			for (int r = 0; r < 20; r++)
//				for (int c = 0; c < 20; c++)
//					dist[r][c] = -1;
//
//			// �� ����
//			// ���ʺ��� ����
//			for (int c = 0; c < C; c++)
//			{
//				// �ü� X
//				if (tempBoard[R][c] == 0) continue;
//
//				queue<pair<int, int>> Q;
//
//				// ������ : (R-1, c) ť�� �ְ�, dist = 1 �� �ʱ�ȭ
//				Q.push({ R - 1, c });
//				dist[R - 1][c] = 1;
//
//				while (!Q.empty())
//				{
//					pair<int, int> curPos = Q.front(); Q.pop();
//					const int curR = curPos.first;
//					const int curC = curPos.second;
//					const int curDist = dist[curR][curC];
//
//					if (tempBoard[curR][curC] == 1)
//					{
//						// Kill
//						if (nextBoard[curR][curC] != 0)
//						{
//							killCnt++;
//						}
//						nextBoard[curR][curC] = 0;
//						break;
//					}
//
//					// �� �� �ִ� ���� üũ�ϱ� ���� bool ����
//					bool found = false;
//					for (int dir = 0; dir < 3; dir++)
//					{
//						const int nextR = curR + dRow[dir];
//						const int nextC = curC + dCol[dir];
//
//						if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C)
//							continue;
//
//						// �̹� q�� ���� << ���⼭ ����
//						if (dist[nextR][nextC] != -1 && tempBoard[nextR][nextC] == 0) continue;
//
//						const int nextDist = curDist + 1;
//
//						if (nextDist <= D)
//						{
//							Q.push({ nextR, nextC });
//							dist[nextR][nextC] = nextDist;
//
//							// ���� ����� �Ѹ� �׿��� �ϱ� ������ for�� break // << 
//							if (tempBoard[nextR][nextC] == 1)
//							{
//								found = true;
//								// Kill
//								if (nextBoard[nextR][nextC] != 0)
//								{
//									killCnt++;
//								}
//								nextBoard[nextR][nextC] = 0;
//								break;
//							}
//						}
//					}
//					if (found) break;
//
//					//// ���� �Ѿ ��� (break �ϸ� ���� ť �ȿ� üũ ���Ѱ� �����־ �ȵ�)
//					//if (isInDist == false)
//					//	continue;
//				}
//			}
//
//
//			// ����
//			for (int r = 0; r < R; r++)
//			{
//				for (int c = 0; c < C; c++)
//				{
//					tempBoard[r][c] = nextBoard[r][c];
//				}
//			}
//
//			//cout << "kill ����" << '\n';
//			//printBoard(tempBoard);
//
//			// �� �̵�
//			fill(&tempBoard[R - 1][0], &tempBoard[R - 1][C], 0); // �������� ������ Ż��
//			int enemyCnt = 0;
//			for (int r = R - 2; r >= 0; r--)
//			{
//				for (int c = 0; c < C; c++)
//				{
//					tempBoard[r + 1][c] = tempBoard[r][c];
//
//					if (tempBoard[r][c] == 1)
//						enemyCnt++;
//				}
//			}
//			fill(&tempBoard[0][0], &tempBoard[0][C], 0); // �� ���� 0
//
//
//			//cout << "�� �̵� ����" << '\n';
//			//printBoard(tempBoard);
//			//cout << "kill Count : " << killCnt << '\n';
//
//			// �迭 ���� ���� ������, maxDeadEnemyCnt ��� �� break
//			if (enemyCnt == 0)
//			{
//				maxDeadEnemyCnt = max(killCnt, maxDeadEnemyCnt);
//				break;
//			}
//		}
//	} while (next_permutation(idx, idx + C)); // <<<
//
//	//  �ü��� �������� ������ �� �ִ� ���� �ִ� ���� ���
//	cout << maxDeadEnemyCnt;
//
//	return 0;
//}
//
//
//void printBoard(int board[][20])
//{
//	cout << '\n';
//	for (int r = 0; r <= R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			cout << board[r][c] << " ";
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//}