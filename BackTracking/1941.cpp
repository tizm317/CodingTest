//#include <iostream>
//#include <string>
//#include <utility>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 18. ��
//// ���� ��ȣ	: #1941 
//// ���� �̸�	: �ҹ��� ĥ����
//// �˰���	: 
//// �ð����⵵: O()
//
//#define ROW first
//#define COL second
//
//const int dRow[4] = { 0, 1, 0, -1 };
//const int dCol[4] = { 1, 0, -1, 0 };
//
//int students[5][5]; // S : 0 , Y : 1
//int a[25]; // 1 - 7��
//int totalCnt; // 7���� ����� ��
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	for (int i = 0; i < 5; i++)
//	{
//		string str;
//		getline(cin, str);
//		for (int j = 0; j < 5; j++)
//		{
//			if (str[j] == 'S')
//			{
//				students[i][j] = 0;
//			}
//			else // 'Y'
//			{
//				students[i][j] = 1;
//			}
//		}
//	}
//
//	// 25�� �߿��� 7�� �̴� ����� ��(����)
//	// 25C7 = 480'700
//
//	// 1 - 7��, 0 - 18��
//	fill(a + 18, a + 25, 1);
//
//	queue<pair<int, int>> Q;
//
//	do
//	{
//		int memberCnt = 0; // 7���� �����
//		int yCnt = 0; // �ִ� 3��
//
//		bool isused[5][5] = { 0, };
//
//		// ������ ã��
//		bool find = false;
//		for (int r = 0; r < 5; r++)
//		{
//			for (int c = 0; c < 5; c++)
//			{
//				if (a[c + r * 5] == 0)
//					continue;
//
//				// �ӵ����� ī��Ʈ
//				if (students[r][c] == 1)
//					yCnt = 1;
//
//				isused[r][c] = true;
//				memberCnt = 1;
//				Q.push({r,c});
//				find = true;
//				break;
//			}
//
//			if (find)
//				break;
//		}
//
//		bool success = true;
//		while (!Q.empty())
//		{
//			if (memberCnt == 7)
//				break;
//
//			pair<int, int> curPos = Q.front(); Q.pop();
//
//
//			// ��ó 4������ ���캽
//			bool isConnected = false;
//			for (int dir = 0; dir < 4; dir++)
//			{
//				int nRow = curPos.ROW + dRow[dir];
//				int nCol = curPos.COL + dCol[dir];
//
//				// ���� ������� üũ
//				if (nRow < 0 || nRow >= 5 || nCol < 0 || nCol >= 5)
//					continue;
//
//				// �湮 ���� üũ
//				if (isused[nRow][nCol])
//					continue;
//
//
//				// 7����
//				if (a[nCol + nRow * 5] == 1)
//				{
//					// �ӵ����� ī��Ʈ
//					if (students[nRow][nCol] == 1)
//					{
//						// �ӵ����� �ִ밹�� ���� ��� pass
//						if (yCnt == 3)
//							break;
//
//						yCnt++;
//					}
//
//					memberCnt++;
//					Q.push({ nRow, nCol });
//					isConnected = true;
//
//					isused[nRow][nCol] = true;
//
//				}
//			}
//
//			// �ݷ�) ���� S�� ��Ȳ
//			// 
//			// �ذ�)
//			// ť�� ���� �ٸ��� ���� ���� ������(ť�� �ٸ��� ���ٴ°� ���ݲ��� �������̴ϱ�, ������ �� �Ǿ� �ִٸ�, fail)
//			// (ť�� ������ �ִٸ�, success ���ɼ� ����)
//			// ������� ���� ���(Ȥ��, �ӵ����� �ִ밹�� ���� ���)�� pass
//			if (Q.size() == 0 && !isConnected)
//			{
//				success = false;
//				break;
//			}
//		}
//
//		if (success)
//			totalCnt++;
//
//		// ť ����
//		while (!Q.empty())
//			Q.pop();
//
//	} while (next_permutation(a, a + 25));
//
//	cout << totalCnt;
//
//	return 0;
//}
//
//
//
///*
//SSSSS
//SSSSS
//SSSSS
//SSSSS
//SSSSS
//*/