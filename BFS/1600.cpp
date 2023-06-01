//#include <iostream>
//#include <tuple>
//#include <queue>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 09. ȭ
//// ���� ��ȣ	: #1600 
//// ���� �̸�	: ���� �ǰ��� ������
//// �˰���	: 
//// �ð����⵵: O()
//
//
//int K, W, H, moveCnt;
//int board[205][205];
//int visit[205][205];
//int horseMove[205][205]; // 
//
//// �����¿�(4����) -> �� �̵�(8����)
//const int dRow[12] = {-1, 0, 1, 0, -2, -1, 1, 2, 2, 1, -1, -2};
//const int dCol[12] = {0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1};
//
//// (row, col, horseMove �� �̵� Ƚ��)
//queue<tuple<int, int, int>> Q;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	
//	cin >> K >> W >> H;
//
//	// (H, W) ������ �Է�
//	for (int r = 0; r < H; r++)
//	{
//		for (int c = 0; c < W; c++)
//		{
//			cin >> board[r][c];
//		}
//	}
//
//	// ������ : (0,0)
//	Q.push({ 0,0,0 });
//	visit[0][0] = 1;
//	horseMove[0][0] = 0;
//
//	while (!Q.empty())
//	{
//		// ���� ��ġ + horseMove Ƚ��
//		tuple<int, int, int> curPos = Q.front(); Q.pop();
//
//		int row = get<0>(curPos);
//		int col = get<1>(curPos);
//		int horseMoveCnt = get<2>(curPos);
//		//cout << "(" << row << ", " << col << ", " << horseMoveCnt << ")" << '\n';
//
//		// ���� ���� üũ
//		if (get<0>(curPos) == H - 1 && get<1>(curPos) == W - 1)
//		{
//			//cout << "����" << '\n';
//			//for (int r = 0; r < H; r++)
//			//{
//			//	for (int c = 0; c < W; c++)
//			//	{
//			//		cout << visit[r][c] << " ";
//			//	}
//			//	cout << '\n';
//			//}
//
//			cout << visit[H - 1][W - 1] - 1 << '\n';
//			return 0;
//		}
//
//		for (int dir = 0; dir < 12; dir++)
//		{
//			// horseMove üũ
//			// K�� �̻��̸� ���� �ִ� ��
//			//if (get<2>(curPos) > K)
//			//{
//			//	cout << "Something Wrong" << '\n';
//			//	break;
//			//}
//
//			//  K���̸� continue (�����¿� �̵��� ����)
//			if (dir > 3 && get<2>(curPos) == K)
//				break;
//
//			// ���� ��ġ
//			int nRow = get<0>(curPos) + dRow[dir];
//			int nCol = get<1>(curPos) + dCol[dir];
//
//			// ���� horseMove Ƚ��
//			int nHorseMove;
//			if (dir > 3)
//			{
//				nHorseMove = get<2>(curPos) + 1;
//			}
//			else
//			{
//				nHorseMove = get<2>(curPos);
//			}
//
//			// 1. ���� üũ
//			if (nRow < 0 || nRow >= H || nCol < 0 || nCol >= W)
//				continue;
//
//			// 2. �� üũ
//			if (board[nRow][nCol] == 1)
//				continue;
//
//			// 3. �湮 üũ (?)
//			// �������ϰ� �� �ʿ䰡 �ִ�
//			// ������ �湮�� �Ͱ�, �����̵����� �湮�� ���� ���̰� ����
//			//if (dir < 4) // ���� �̵��� ���
//			//{
//			//	// ���� �̵�(1), ����+���� �̵�(3) �湮�� ��� X
//			//	if (visit[nRow][nCol] % 2 == 1)
//			//		continue;
//			//}
//			//else // ���� �̵��� ���
//			//{
//			//	// ���� �̵�(2), ����+���� �̵�(3) �湮�� ��� X
//			//	if (visit[nRow][nCol] > 1)
//			//		continue;
//			//}
//
//			// �湮�� �� �����鼭, ���� �� �̵� Ƚ���� ���ų� ������ continue
//			// �湮�� �� ������, ������ ����
//			// �湮�� �� ������, ���� �� �̵� Ƚ���� ������ �̵� ����
//			if (visit[nRow][nCol] != 0)
//			{
//				if (horseMove[nRow][nCol] <= nHorseMove)
//					continue;
//			}
//
//			Q.push({ nRow, nCol, nHorseMove });
//			visit[nRow][nCol] = visit[get<0>(curPos)][get<1>(curPos)] + 1;
//			horseMove[nRow][nCol] = nHorseMove;
//
//			//if (dir < 4) // ���� �̵� (���ϱ� 1)
//			//{
//			//	visit[nRow][nCol]++;
//			//}
//			//else // ���� �̵� (���ϱ� 2)
//			//{
//			//	visit[nRow][nCol] += 2;
//			//}
//
//		}
//	
//		//moveCnt++;
//	}
//
//	cout << -1 << '\n';
//
//	return 0;
//}