//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 19. ��
//// ���� ��ȣ	: #12100 
//// ���� �̸�	: 2048 (Easy)
//// �˰���	: �ùķ��̼�
//// �ð����⵵: O()
//
//int N; // 1 <= N <= 20
//int board[30][30];
//
//const int dRow[4] = {-1, 0, 1, 0};
//const int dCol[4] = {0, 1, 0, -1};
//
//int ans;
//
//void myfunc(int r, int c, int dir, int(*board)[30], bool(*check)[30])
//{
//	// ���� ĭ�� ����
//	int curNum = board[r][c];
//
//	// ��ĭ�� pass
//	if (curNum != 0)
//	{
//		// if(curNum == 0)
//		//	 continue;
//
//		int nRow = r;
//		int nCol = c;
//
//		while (true)
//		{
//			nRow += dRow[dir];
//			nCol += dCol[dir];
//
//			// �迭 �� ���� : ����
//			if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
//				break;
//
//			// �ٸ� ���ڿ� ������ ��� (0�� �ƴ�..) : ����
//			if (curNum != board[nRow][nCol] && board[nRow][nCol] != 0)
//				break;
//
//			// ���� ���ڿ� ������ ��� : ��������, ����
//			if (curNum == board[nRow][nCol])
//			{
//				// ����ĭ, ����ĭ ��� ������ �� ����� ��! 
//				if ((check[r][c] == false && check[nRow][nCol] == false))
//				{
//					// ���� ĭ�� ���� ���ϰ�,
//					board[nRow][nCol] += curNum;
//
//					// üũ �迭 ǥ�� <<
//					check[nRow][nCol] = true;
//
//					// ���� ĭ�� �����(0)
//					board[r][c] = 0;
//				}
//
//				// �� �� �ϳ��� ������ �� ������, �׳� ����
//				break;
//			}
//
//			// ���� ĭ�� ��ĭ�� ���(0) : ��� �̵�
//			if (board[nRow][nCol] == 0)
//			{
//				// ���� ĭ�� �־��ְ�, ���� ĭ ���
//				board[nRow][nCol] = curNum;
//				board[r][c] = 0;
//			
//				// �̵� ������, ��ġ�� ����
//				r = nRow;
//				c = nCol;
//			}
//		}
//	}
//}
//
//void slide(int dir, int (*board)[30])
//{
//	// �� ���� �̵����� �̹� ������ ����� �� �ٸ� ��ϰ� �ٽ� ������ �� ����. 
//	bool check[30][30] = { false, };
//
//	switch (dir)
//	{
//	case 0:
//		for (int r = 0; r < N; r++)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				myfunc(r, c, dir, board, check);
//			}
//		}
//		break;
//	case 1:
//		for (int c = N - 1; c >= 0; c--)
//		{
//			for (int r = 0; r < N; r++)
//			{
//				myfunc(r, c, dir, board, check);
//			}
//		}
//		break;
//	case 2:
//		for (int r = N - 1; r >= 0; r--)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				myfunc(r, c, dir, board, check);
//			}
//		}
//		break;
//	case 3:
//		for (int c = 0; c < N; c++)
//		{
//			for (int r = 0; r < N; r++)
//			{
//				myfunc(r, c, dir, board, check);
//			}
//		}
//		break;
//	}
//
//
//}
//
//void myGamePlay(int avaliableSlideCnt, const int (*board)[30])
//{
//	if (avaliableSlideCnt <= 0)
//	{
//		//int maxNum = 0;
//		for (int r = 0; r < N; r++)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				ans = max(ans, board[r][c]);
//				//maxNum = max(maxNum, board[r][c]);
//			}
//		}
//
//		//ans = max(ans, maxNum);
//
//		return;
//	}
//
//	// 4���� ��� slide
//	int tmp[30][30] = { 0, };
//	for (int dir = 0; dir < 4; dir++)
//	{
//		for (int r = 0; r < N; r++)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				tmp[r][c] = board[r][c];
//			}
//		}
//
//		slide(dir, tmp); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,
//
//		myGamePlay(avaliableSlideCnt - 1, tmp);
//	}
//
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ������ �Է�
//	cin >> N;
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cin >> board[r][c];
//		}
//	}
//
//	// 5�� �÷���
//	myGamePlay(5, board);
//
//	cout << ans;
//
//	return 0;
//}