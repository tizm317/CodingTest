//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//#include <utility>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 20. ��
//// ���� ��ȣ	: #11559 
//// ���� �̸�	: Puyo Puyo
//// �˰���	: �ùķ��̼�, BFS
//// �ð����⵵: O()
//
//vector<string> field;
//// R G B P Y
//// . ��ĭ
//
//int combo;
//
//#define ROW first
//#define COL second
//queue<pair<int, int>> Q;
//queue<pair<int, int>> connectedPuyoQueue; // �ѿ� ��Ʈ���� ���ؼ� ����� �ѿ� ť�� ��� ����
//const int dRow[4] = { -1, 0, 1, 0 };
//const int dCol[4] = { 0, 1, 0, -1 };
//
//// �ʵ��� row, col ��
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
//	// �ʵ� �Է�
//	for (int row = 0; row < R; row++)
//	{
//		string s;
//		cin >> s;
//		field.push_back(s);
//	}
//
//	// ���� ����
//	while(true)
//	{
//		// �Ʒ��� �̵��� �� ���ο� ���� ���� ���θ� �Ǵ��ϱ� ���� bool ���� �ʱ�ȭ
//		bool isPuyoPop = false;
//
//		// ��Ʈ����
//		popPuyo(isPuyoPop);
//		
//		// ���� �� ������ Ż��
//		if (!isPuyoPop)
//			break;
//		
//		// �޺� ��
//		combo++;
//
//		// �Ʒ��� �̵�
//		moveDown();
//
//		//printField();
//	}
//
//	// �޺� ���
//	cout << combo;
//
//	//printField();
//
//	return 0;
//}
//
//void popPuyo(bool& isPuyoPop)
//{
//	// �Ʒ������� Flood Fill
//	// vis �迭 �ʱ�ȭ
//	bool vis[R][C] = { false, };
//
//	// ������ ã��
//	for (int r = R - 1; r >= 0; r--)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			// ��ĭ X
//			if (field[r][c] == '.')
//				continue;
//
//			// ������ ã�Ƽ� Q, connectedPuyoQueue �� ����
//			Q.push({ r,c });
//			connectedPuyoQueue.push({ r,c });
//
//			// �湮 ǥ��
//			vis[r][c] = true;
//
//			// 4�� �̻� ����Ǿ����� �ľ��ϱ� ���� cnt ���� 
//			// -> connectedPuyoQueue.size() ����ϸ� �� (cnt ���� üũ�� �ʿ� ����)
//			//int cnt = 1;
//
//			while (!Q.empty())
//			{
//				// ���� �ѿ� ��ġ
//				pair<int, int> curPos = Q.front(); Q.pop();
//				// ���� �ѿ� ����
//				const char curColor = field[curPos.ROW][curPos.COL];
//
//				for (int dir = 0; dir < 4; dir++)
//				{
//					// ���� ��ġ ���
//					int nRow = curPos.ROW + dRow[dir];
//					int nCol = curPos.COL + dCol[dir];
//
//					// �迭 ���� �Ѿ�� �� üũ
//					if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C)
//						continue;
//
//					// �ߺ� �湮 ����
//					if (vis[nRow][nCol])
//						continue;
//
//					// ���� �ѿ� �����ϰ� ��
//					const char nColor = field[nRow][nCol];
//					if (curColor != nColor)
//						continue;
//
//					// ���� ���̸� Q, connectedPuyoQueue �� �ְ�, �湮 ǥ��
//					Q.push({ nRow, nCol });
//					connectedPuyoQueue.push({ nRow, nCol });
//					vis[nRow][nCol] = true;
//					//cnt++;
//				}
//			}
//
//			// �ѿ� ��Ʈ����
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
//			// ť ����ֱ�
//			while (!connectedPuyoQueue.empty())
//				connectedPuyoQueue.pop();
//		}
//	}
//}
//
//void moveDown()
//{
//	// 1���� column �� �Ʒ��� �̵���Ŵ
//	for (int c = 0; c < C; c++)
//	{
//		// �Ʒ����� �̵���Ŵ
//		for (int r = R - 1; r >= 0; r--)
//		{
//			// ��ĭ X
//			if (field[r][c] == '.')
//				continue;
//
//			int curRow = r;
//			int nRow = curRow;
//			while (true)
//			{
//				// �Ʒ��� �̵�
//				nRow += dRow[2];
//
//				// �迭 ���� �Ѵ��� üũ
//				if (nRow >= R)
//					break;
//
//				// �Ʒ�ĭ�� �� ĭ���� üũ
//				if (field[nRow][c] != '.')
//					break;
//
//				// �Ʒ��� �̵�
//					// �Ʒ�ĭ ���� �ٲٰ�, ����ĭ ����
//				field[nRow][c] = field[curRow][c];
//				field[curRow][c] = '.';
//				// ���� ��ġ�� ���� ��ġ�� ����
//				curRow = nRow;
//			}
//		}
//	}
//}
//
//void printField()
//{
//	// ����� ��
//	// �ʵ� ��ü ���
//	for (int row = 0; row < R; row++)
//	{
//		cout << field[row] << '\n';
//	}
//}
