//#include <iostream>
//#include <utility>
//#include <queue>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 04. ��
//// ���� ��ȣ	: #2573 
//// ���� �̸�	: ����
//// �˰���	: BFS
//// �ð����⵵: O()
//
//#define ROW first
//#define COL second
//
//int N, M;
//int iceberg[305][305];
////int visit[305][305];
//int year;
//
//// �ϵ�����
//const int dRow[4] = { -1, 0, 1, 0 };
//const int dCol[4] = { 0, 1, 0, -1 };
//
//queue<pair<int, int>> Q;
//
//bool isMelting = false;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cin >> iceberg[i][j];
//		}
//	}
//
//	int iceCnt = 0;
//	while (true)
//	{
//		iceCnt = 0;
//		int visit[305][305] = { 0, };
//		isMelting = false;
//
//		// ���� ������ ã��
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				// �ٴ幰 (0) �н�
//				if (iceberg[i][j] == 0)
//					continue;
//
//				if (visit[i][j] == 1)
//					continue;
//
//				isMelting = true;
//
//				// ���� ����
//				Q.push({ i, j });
//				visit[i][j] = 1;
//				iceCnt++;
//
//				while (!Q.empty())
//				{
//					// ���� ��ġ
//					pair<int, int> curPos = Q.front(); Q.pop();
//
//					for (int dir = 0; dir < 4; dir++)
//					{
//						// ���� ��ġ
//						int nRow = curPos.ROW + dRow[dir];
//						int nCOL = curPos.COL + dCol[dir];
//
//						if (visit[nRow][nCOL] == 1)
//							continue;
//
//						// �ٴ幰�̸�
//						if (iceberg[nRow][nCOL] == 0)
//						{
//							// 1 ���� (�ּ� 0)
//							iceberg[curPos.ROW][curPos.COL] = max(0, iceberg[curPos.ROW][curPos.COL] - 1);
//						}
//						else // �����̸�
//						{
//							Q.push({ nRow, nCOL });
//							visit[nRow][nCOL] = 1;
//						}
//					}
//				}
//			}
//		}
//
//		// �� ���� ���
//		if (isMelting == false && iceCnt < 2)
//		{
//			year = 0;
//			break;
//		}
//
//		if (iceCnt >= 2)
//			break;
//
//		year++;
//	}
//	
//	cout << year << '\n';
//
//
//	return 0;
//}