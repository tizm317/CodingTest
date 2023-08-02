//#include <iostream>
//#include <utility>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 08. 02. ��.
//// ���� ��ȣ	: #17143 
//// ���� �̸�	: ���ÿ�
//// �˰���	: �ùķ��̼�
//// �ð����⵵: O()
//
//int R, C; // <= 100
//int board[105][105];
//
//int M; //0 <=  <= R * C
//
//// ��� ����(�ӷ�, ����) ��� �迭 - ��� ũ�Ⱑ index ����
//// z <= 10000
//pair<int, int> sharkInfo[10005]; // {�ӷ� s, ���� d}
//
//// ��, ��, ��, ��
////const int dRow[4] = { -1, 1, 0, 0 };
////const int dCol[4] = { 0, 0, 1, -1 };
//
//// ���� ũ�� ��� X -> ��� ũ��� ����
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> R >> C >> M;
//	R++; C++; // +1
//
//	for (int i = 0; i < M; i++)
//	{
//		int r, c, s, d, z;
//		cin >> r >> c >> s >> d >> z;
//
//		// board �迭 ��� ��ġ�� ũ�� ����
//		board[r][c] = z;
//
//		// ����� �ӷ�, ������ sharkInfo �迭�� ����
//		sharkInfo[z] = { s,d-1 }; // d = d-1; 0~3���� ����
//	}
//
//	int sum_shark_size = 0;
//
//	cout << '\n';
//	for (int r = 1; r < R; r++)
//	{
//		for (int c = 1; c < C; c++)
//		{
//			cout << board[r][c] << " ";
//		}
//		cout << '\n';
//	}
//
//	// 0. ���ÿ��� ó���� 1�� ���� �� ĭ ���ʿ� �ִ�. 
//	pair<int, int> fishingKingPos = { 0,0 };
//	int cnt = 0;
//	while (true)
//	{
//		if(cnt == M) break;
//
//		// 1. ���ÿ��� ���������� �� ĭ �̵��Ѵ�.
//		fishingKingPos.second++;
//		const int c = fishingKingPos.second;
//
//		// ���ÿ��� ���� ������ ���� ������ ĭ�� �̵��ϸ� �̵��� �����.
//		if (c > C) break;
//
//		// 2. ���ÿ��� �ִ� ���� �ִ� ��� �߿��� ���� ���� ����� �� ��´�. �� ������ �����ǿ��� ���� �� �������.
//		for (int r = 1; r < R; r++)
//		{
//			// ������ pass
//			if (board[r][c] == 0) continue;
//
//			// ������ ũ�� �����ְ� break (���� ����� ��� ������ break)
//			sum_shark_size += board[r][c];
//			
//			// ���� ��� ����
//			cnt++;
//
//			// ��� �����
//			board[r][c] = 0;
//			break;
//		}
//
//		// 3. �� �̵��Ѵ�.
//		int movedSharkBoard[105][105] = { 0, };
//		for (int r = 1; r < R; r++)
//		{
//			for (int c = 1; c < C; c++)
//			{
//				// ��� ũ��
//				const int sharkSize = board[r][c];
//				// 0�̸� ��� X -> pass
//				if (sharkSize == 0) continue;
//				if (sharkSize == 9)
//				{
//					int a = 1 + 1;
//				}
//
//				// ��� ũ�� �̿��ؼ� ���� ������
//				pair<int, int>& info = sharkInfo[sharkSize]; // <<<<<<<<<<<<<<<<<<<<<<<<<<< ���� �Ͼ�� �� �ٲ�! ���۷���
//				int dist = info.first;
//				int& dir = info.second;
//
//				// ��� ��ġ
//				int sharkR = r;
//				int sharkC = c;
//
//				switch (dir)
//				{
//				case 0: // ��
//					if (sharkR - dist <= 1)
//					{
//						// �̵� �Ÿ� ����
//						dist -= (sharkR -1);
//
//						// 1 �� ��ġ �̵�
//						sharkR = 1;
//
//						// ���� ��ȯ
//						dir++;
//
//						// ������ �̵�
//						if ((dist / (R - 2)) % 2 == 0)
//						{
//							// ¦���� 1 ��ġ���� down ����
//							// dist % (R-2) ��ŭ �̵�
//							sharkR += (dist % (R - 2));
//						}
//						else
//						{
//							// Ȧ���� R-1 ��ġ���� up ����
//							// dist % (R-2) ��ŭ �̵�
//							dir--;
//							sharkR = R-1;
//							sharkR -= (dist % (R - 2));
//						}
//					}
//					else
//					{
//						// ��ġ �̵�
//						sharkR = sharkR - dist;
//					}
//					break;
//				case 1: // ��
//					if (sharkR + dist >= (R - 1))
//					{
//						// �̵� �Ÿ� ����
//						dist -= ((R - 1) - sharkR);
//
//						// R-1 �� ��ġ �̵�
//						sharkR = R - 1;
//
//						// ���� ��ȯ
//						dir--;
//
//						// ������ �̵�
//						if ((dist / (R - 2)) % 2 == 0)
//						{
//							// ¦���� (R-1) ��ġ���� up ����
//							// dist % (R-2) ��ŭ �̵�
//							sharkR -= (dist % (R - 2));
//						}
//						else
//						{
//							// Ȧ���� 1 ��ġ���� down ����
//							// dist % (R-2) ��ŭ �̵�
//							dir++; // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ������
//							sharkR = 1;
//							sharkR += (dist % (R - 2));
//						}
//					}
//					else
//					{
//						// ��ġ �̵�
//						sharkR = sharkR + dist;
//					}
//					break;
//				case 2: // ��
//					if (sharkC + dist >= (C - 1))
//					{
//						// �̵� �Ÿ� ����
//						dist -= ((C - 1) - sharkC);
//
//						// C-1 �� ��ġ �̵�
//						sharkC = C-1;
//
//						// ���� ��ȯ
//						dir++;
//
//						// ������ �̵�
//						if ((dist / (C - 2)) % 2 == 0)
//						{
//							// ¦���� (C-1) ��ġ���� <- ����
//							// dist % (C-2) ��ŭ �̵�
//							sharkC -= (dist % (C - 2));
//						}
//						else
//						{
//							// Ȧ���� 1 ��ġ���� -> ����
//							// dist % (C-2) ��ŭ �̵�
//							dir--;
//							sharkC = 1;
//							sharkC += (dist % (C - 2));
//						}
//					}
//					else
//					{
//						// ��ġ �̵�
//						sharkC = sharkC + dist;
//					}
//					break;
//				case 3: // ��
//					if (sharkC - dist <= 1)
//					{
//						// �̵� �Ÿ� ����
//						dist -= (sharkC - 1);
//
//						// 1 �� ��ġ �̵�
//						sharkC = 1;
//
//						// ���� ��ȯ
//						dir--;
//
//						// ������ �̵�
//						if ((dist / (C - 2)) % 2 == 0)
//						{
//							// ¦���� 1 ��ġ���� -> ����
//							// dist % (C-2) ��ŭ �̵�
//							sharkC += (dist % (C - 2));
//						}
//						else
//						{
//							// Ȧ���� C-1 ��ġ���� <- ����
//							// dist % (C-2) ��ŭ �̵�
//							dir++;
//							sharkC = C-1;
//							sharkC -= (dist % (C - 2));
//						}
//					}
//					else
//					{
//						// ��ġ �̵�
//						sharkC = sharkC - dist;
//					}
//					break;
//				}
//
//				// ū ��� 1������ ����
//				movedSharkBoard[sharkR][sharkC] = max(movedSharkBoard[sharkR][sharkC], sharkSize);
//			}
//		}
//
//		cout << '\n';
//		for (int r = 1; r < R; r++)
//		{
//			for (int c = 1; c < C; c++)
//			{
//				board[r][c] = movedSharkBoard[r][c];
//				cout << board[r][c] << " ";
//			}
//			cout << '\n';
//		}
//	}
//
//	// ���ÿ��� ���� ��� ũ���� ���� ����Ѵ�.
//	cout << sum_shark_size;
//
//	return 0;
//}