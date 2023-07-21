//#include <iostream>
//#include <utility>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 21. ��
//// ���� ��ȣ	: #14503 
//// ���� �̸�	: �κ� û�ұ�
//// �˰���	: �ùķ��̼�,
//// �ð����⵵: O()
//
//// ��
//int R, C; // 3 <= <= 50
//int room[55][55];  // 0 û�ҵ��� ���� ��ĭ, 1 �� , 2 û����
//
//// ��, ��, ��, ��
//const int dRow[4] = {-1, 0, 1, 0};
//const int dCol[4] = {0, 1, 0, -1};
//
//int clearRoomCnt;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> R >> C;
//
//	// û�ұ� ���� ��ġ, ����
//	int r, c, dir;
//	cin >> r >> c >> dir;
//
//	// �� ���� �Է�
//	for (int r = 0; r < R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			cin >> room[r][c];
//		}
//	}
//
//	// û�� ����
//	pair<int, int> curPos = { r,c };
//	while (true)
//	{
//		// 1. ���� ĭ�� ���� û�ҵ��� ���� ���, ���� ĭ�� û���Ѵ�.
//		if (room[curPos.first][curPos.second] == 0)
//		{
//			room[curPos.first][curPos.second] = 2;
//			clearRoomCnt++;
//		}
//
//		// ���� ĭ�� �ֺ� 4ĭ üũ
//		bool isClear = true;
//		for (int d = 0; d < 4; d++)
//		{
//			int nRow = curPos.first + dRow[d];
//			int nCol = curPos.second + dCol[d];
//
//			// �迭 ���� ����� �� üũ
//			if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C)
//				continue;
//
//			// ���̳�, û���� ������ �� üũ
//			if (room[nRow][nCol] != 0)
//				continue;
//
//			// �ֺ� 4ĭ �� û���ؾ� �ϴ� ĭ ����(1�� �̻� �����ϸ� �ǰ�, ���� ���θ� �ľ��ϸ� �ż� break)
//			isClear = false;
//			break;
//		}
//
//		// �ֺ� 4ĭ ��� û�ҵ� ���
//		if (isClear)
//		{
//			// �ٶ󺸴� ������ ����(dir ��ü�� �� �ǵ�)�� ä�� �� ĭ ����
//			int nRow = curPos.first + dRow[(dir + 2) % 4];
//			int nCol = curPos.second + dCol[(dir + 2) % 4];
//
//			// ���̸� �۵� ����
//			if (room[nRow][nCol] == 1)
//				break;
//
//			//  �� ĭ ������ �� �ִٸ� �� ĭ �����ϰ� 1������ ���ư���.
//			curPos = { nRow, nCol }; // ������ ��ġ�� ����
//			continue;
//		}
//		else // û�ҵ��� ���� �� ĭ�� �ִ� ���
//		{
//			// �ݽð� �������� 90�� ȸ��
//			dir += 3; 
//			dir %= 4;
//
//			// �ٶ󺸴� ������ �������� ���� ĭ�� û�ҵ��� ���� �� ĭ�� ��� �� ĭ �����Ѵ�.
//			int nRow = curPos.first + dRow[dir];
//			int nCol = curPos.second + dCol[dir];
//			if (room[nRow][nCol] == 0)
//			{
//				curPos = { nRow, nCol };
//				continue;
//			}
//		}
//	}
//
//	cout << clearRoomCnt;
//
//	return 0;
//}