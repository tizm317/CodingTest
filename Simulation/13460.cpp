//#include <iostream>
//#include <utility>
//#include <queue>
//#include <tuple>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 27. ��
//// ���� ��ȣ	: #13460 
//// ���� �̸�	: ���� Ż�� 2
//// �˰���	: �ùķ��̼�, ť
//// �ð����⵵: O()
//
//int R, C; // <= 10
//char board[15][15]; // # ��, . ��ĭ, O �ⱸ
//
//const int dRow[4] = { -1, 0, 1, 0 };
//const int dCol[4] = { 0, 1, 0, -1 };
//
//int min_move_cnt = -1;
//
//queue<tuple<int, int, char>> Q;
//
//void moveMarble(int moveCnt, const queue<tuple<int, int, char>>& Q);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ������ �Է�
//	cin >> R >> C;	
//	for (int r = 0; r < R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			char x;
//			cin >> x;
//
//			// ������ �Է� �� ���� ť �Է�
//			if (x == 'R' || x == 'B')
//			{
//				// ������ ť�� �ְ�
//				Q.push({ r, c, x });
//				// ��� �����ǿ��� ��ĭ(.) ǥ��
//				board[r][c] = '.';
//			}
//			else
//				board[r][c] = x;
//		}
//	}
//
//	// ����̱�
//	moveMarble(1, Q);
//
//	// ��� ���
//	cout << min_move_cnt;
//
//	return 0;
//}
//
//void moveMarble(int moveCnt, const queue<tuple<int, int, char>>& Q)
//{
//	// 10�� ���Ϸ� �������� ���� ������ ������ ���� ���� �� ������ -1�� ���
//		// moveCnt 10 �ʰ� �� return
//	if (moveCnt > 10)
//		return;
//
//	// ������ ���ϰ�,
//	for (int dir = 0; dir < 4; dir++)
//	{
//		// �̵��� ���� ���� ���ο� ť ����
//		queue<tuple<int, int, char>> nextQ;
//
//		// R, B �� �������� üũ�ϱ� ���� bool ����
//		bool isRedBallOut = false;
//		bool isBlueBallOut = false;
//
//		queue<tuple<int, int, char>> tmp = Q;
//		tuple<int, int, char> firstMarble = tmp.front();
//		tuple<int, int, char> secondMarble = tmp.back();
//
//		// 1. dir �� ����, ���� ���� ���� ���� ����
//			// ���� �����ϴ� ���	�� �ٲ���
//		switch (dir)
//		{
//		case 0: // ����
//			// row�� �۾ƾ� ���� (ũ�� ���� �ڷ�)
//			if (get<0>(firstMarble) > get<0>(secondMarble))
//			{
//				tmp.push(tmp.front());
//				tmp.pop();
//			}
//			break;
//		case 1: // ����
//			// col�� Ŀ�� ���� (������ ���� �ڷ�)
//			if (get<1>(firstMarble) < get<1>(secondMarble))
//			{
//				tmp.push(tmp.front());
//				tmp.pop();
//			}
//			break;
//		case 2: // ����
//			// row�� Ŀ�� ���� (������ ���� �ڷ�)
//			if (get<0>(firstMarble) < get<0>(secondMarble))
//			{
//				tmp.push(tmp.front());
//				tmp.pop();
//			}
//			break;
//		case 3:
//			// col�� �۾ƾ� ���� (ũ�� ���� �ڷ�)
//			if (get<1>(firstMarble) > get<1>(secondMarble))
//			{
//				tmp.push(tmp.front());
//				tmp.pop();
//			}
//			break;
//		}
//
//		// 2. ���� �������� 2���� �� ��� �����δ�.
//		while (!tmp.empty())
//		{
//			// ���� ��
//			tuple<int, int, char> curPos = tmp.front(); tmp.pop();
//
//			int nRow = get<0>(curPos);// +dRow[dir];
//			int nCol = get<1>(curPos);// +dCol[dir];
//
//			// �� �ε����� �� ���� �̵�
//			while (board[nRow + dRow[dir]][nCol + dCol[dir]] != '#') // ������ �� ��ġ�����ؾ���
//			{
//				// [���� ���� ����, �ι�° ������ �̵���Ű�� ���]
//					// tmp �� ����ִٴ� ���� �ι�°�� �����̴� �����̶�� �� <<<<<
//					// ù��° ������ ��ġ ������ �̵�
//					//	���� ���� ����� ��(�̹� �����ſ� �ε��� ���� ����)!!!!!!!!!
//				if (tmp.empty() && !isRedBallOut && !isBlueBallOut)
//				{
//					// ���� �ε����� ������ �̵�
//						// ù��° �̵��� ���� ��ǥ�� ��
//					if ((get<0>(nextQ.front()) == nRow + dRow[dir]) && (get<1>(nextQ.front()) == nCol + dCol[dir]))
//						break;
//				}
//
//				// ���̳� ���� �ε����� �ʴ� ���
//				// ���� ��ġ�� �̵�
//				nRow += dRow[dir];
//				nCol += dCol[dir];
//
//				// 3. ���� ��ġ�� �ⱸ�� ��� bool üũ ��
//				// (�ش� ����) ���̻� �̵� �Ұ��ϹǷ� break
//				if (board[nRow][nCol] == 'O')
//				{
//					if (get<2>(curPos) == 'R')
//						isRedBallOut = true;
//					else
//						isBlueBallOut = true;
//
//					break;
//				}
//			}
//
//			// �Ķ��� out �� fail �̹Ƿ� �׳� break
//			if (isBlueBallOut)
//				break;
//
//			// 4. ���� ť�� �̵� �� �� ����
//			nextQ.push({ nRow, nCol, get<2>(curPos) });
//		}
//
//
//		// ��� ���� ������ ���� ���
//		if (!isRedBallOut && !isBlueBallOut)
//		{
//			// ����̴� ������ �׸��ϴ� ���� �� �̻� ������ �������� ���� �� �����̴�.
//				// ��·�ų� ��� ���� ��￩�� ���� ��ġ��� ���� moveMarble�� �� ȣ���� �ʿ䰡 ���ٴ� ��(���� lv������ ����� ����
//				// ���� ���� ť�� �̵��� ���� ť�� ���ٸ�, �ΰ��� �� ��� �������� ���� ���
//			if (Q != nextQ)
//				moveMarble(moveCnt + 1, nextQ);
//		}
//
//		// ���� ���� ���� ��� - ����
//		if (!isBlueBallOut && isRedBallOut)
//		{
//			min_move_cnt = (min_move_cnt == -1) ? moveCnt : min(min_move_cnt, moveCnt);
//			return;
//		}
//	}
//}
