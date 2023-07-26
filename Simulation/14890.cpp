//#include <iostream>
//#include <vector>
//#include <utility>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 26. ��
//// ���� ��ȣ	: #14890 
//// ���� �̸�	: ����
//// �˰���	: �ùķ��̼�
//// �ð����⵵: O()
//
//int N; // <= 100
//int map[105][105];
//
//int L; // 1 <= L <= N
//
//// ������ �� �ִ� �� ����
//int pathCnt = 0;
//
//void findHorizontalPath();
//void findVerticalPath();
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ����, L �Է�
//	cin >> N >> L;
//	for (int r = 0; r < N; r++)
//		for (int c = 0; c < N; c++)
//			cin >> map[r][c];
//
//	findHorizontalPath();
//	findVerticalPath();
//
//	// ������ �� �ִ� �� ���� ���
//	cout << pathCnt;
//
//	return 0;
//}
//
//void findHorizontalPath()
//{
//	// ���� Scan : N*N
//	for (int r = 0; r < N; r++)
//	{
//		// ���� ��ġ ���� üũ�� bool �迭
//		bool tmp[1][105] = { false, };
//
//		// ������ �� �ִ� �� üũ�� bool ����
//		bool isPassable = true;
//		for (int c = 0; c < N - 1;)
//		{
//			// ����
//			const int h1 = map[r][c];
//
//			// �� ���
//			int c2 = c + 1;
//			const int h2 = map[r][c2];
//
//			// ���� ���� ���
//			if (h1 == h2)
//			{
//				// ���� idx �̵�(+1)
//				c++;
//			}
//			else // ���� �ٸ� ���
//			{
//				// ���� ���� �� �ִ��� Ȯ��
//
//				// 1. ���� ���� 1 ����
//				const int diff = std::abs(h1 - h2);
//				if (diff != 1)
//				{
//					isPassable = false;
//					break;
//				}
//
//				// 2. ��� �������� ���θ� ���� �� (���� �� ������)
//					// �� �������� L ������ŭ üũ
//
//				// ���� �̹� ��ġ�� ��� <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ���� üũ ��ġ ����
//				//if (ramp[r][c2] || tmp[0][c2])
//				////if (tmp[0][c2])
//				//{
//				//	isPassable = false;
//				//	break;
//				//}
//
//				if (h1 > h2) // �������� ���� (������ ���� üũ)
//				{
//					// �迭 ���� �Ѵ� ���
//					if (c + L >= N)
//					{
//						isPassable = false;
//						break;
//					}
//
//					// C+L ���� h2 �� ������ ��
//					bool isSuccess = true;
//					//for (c2 += 1; c2 <= c + L; c2++) // tmp �迭 üũ �ѹ��� �Ϸ���, �Ʒ��� �ٽ� ������.
//					for (; c2 <= c + L; c2++)
//					{
//						// ���� üũ
//						if (tmp[0][c2])
//						{
//							isSuccess = false;
//							isPassable = false;
//							break;
//						}
//
//						// ���� ������ ĭ�� ���� ���ƾ� ��
//						if (map[r][c2] != h2)
//						{
//							isSuccess = false;
//							isPassable = false;
//							break;
//						}
//
//						// ���� ��ġ ǥ��
//						tmp[0][c2] = true;
//					}
//
//					if (!isSuccess)
//					{
//						isPassable = false;
//						break;
//					}
//
//					// ������ ��� (L+1) ĭ �̵� <<<<<<<<<<<< L ĭ �̵�! (L, L+1 �� ����)
//					//c += (L + 1);
//					c += L;
//				}
//				else // h1 < h2 // ���������� ���� (���� ���� üũ)
//				{
//					// �迭 ���� �Ѵ� ���
//					if (c2 - L < 0)
//					{
//						isPassable = false;
//						break;
//					}
//
//					// c2 - L ���� h1 �̶� ������ ��
//					bool isSuccess = true;
//					int c1 = c; // c ���� �� �����̱� ���� ����
//					//for (c1 -= 1; c1 >= c2 - L; c1--)
//					for (; c1 >= c2 - L; c1--)
//					{
//						// ���� üũ
//						if (tmp[0][c1])
//						{
//							isSuccess = false;
//							isPassable = false;
//							break;
//						}
//
//						//if (c1 < 0) break; <<< ��� ���� ������ �� ������ ��
//
//						// ���� ������ ĭ�� ���� ���ƾ� ��
//						if (map[r][c1] != h1)
//						{
//							isSuccess = false;
//							isPassable = false;
//							break;
//						}
//
//						// ���� ��ġ ǥ��
//						tmp[0][c1] = true;
//					}
//
//					if (!isSuccess)
//					{
//						isPassable = false;
//						break;
//					}
//
//					// ������ ��� c 1ĭ �̵�
//					c++;
//				}
//
//			}
//		}
//
//		// ������ �� �ִ� �� ī����
//		if (isPassable)
//		{
//			pathCnt++;
//
//			// ���� ��ġ >> ���η� ��ġ�� ���� �� ���η� ��ġ�� ���δ� ��ĥ �� ���� (���� 2) >> ������
//			/*for (int c = 0; c < N; c++)
//				ramp[r][c] = tmp[0][c];*/
//		}
//	}
//}
//void findVerticalPath()
//{
//	// ���� Scan : N*N
//	for (int c = 0; c < N; c++)
//	{
//		bool tmp[105][1] = { false, };
//
//		// ������ �� �ִ� �� üũ�� bool ����
//		bool isPassable = true;
//		for (int r = 0; r < N - 1;)
//		{
//			// ����
//			const int h1 = map[r][c];
//
//			// �� ���
//			int r2 = r + 1;
//			const int h2 = map[r2][c];
//
//			// ���� ���� ���
//			if (h1 == h2)
//			{
//				// ���� idx �̵�(+1)
//				r++;
//			}
//			else // ���� �ٸ� ���
//			{
//				// ���� ���� �� �ִ��� Ȯ��
//
//				// 1. ���� ���� 1 ����
//				const int diff = std::abs(h1 - h2);
//				if (diff != 1)
//				{
//					isPassable = false;
//					break;
//				}
//
//				// 2. ��� �������� ���θ� ���� �� (���� �� ������)
//					// �� �������� L ������ŭ üũ
//
//				if (h1 > h2) // �������� ���� (�Ʒ��� ���� üũ)
//				{
//					// �迭 ���� �Ѵ� ���
//					if (r + L >= N)
//					{
//						isPassable = false;
//						break;
//					}
//					// R+L ���� h2 �� ������ ��
//					bool isSuccess = true;
//					for (; r2 <= r + L; r2++)
//					{
//						// ���� üũ
//						if (tmp[r2][0])
//						{
//							isSuccess = false;
//							isPassable = false;
//							break;
//						}
//
//						if (map[r2][c] != h2)
//						{
//							isSuccess = false;
//							isPassable = false;
//							break;
//						}
//
//						tmp[r2][0] = true;
//					}
//					if (!isSuccess)
//					{
//						isPassable = false;
//						break;
//					}
//
//					// ������ ��� L ĭ �̵�
//					r += L;
//				}
//				else // h1 < h2 // �Ʒ������� ���� (���� ���� üũ)
//				{
//					// �迭 ���� �Ѵ� ���
//					if (r2 - L < 0)
//					{
//						isPassable = false;
//						break;
//					}
//
//					// r2 - L ���� h1 �̶� ������ ��
//					bool isSuccess = true;
//					int r1 = r; // r ���� �� �����̱� ���� ����
//					for (; r1 >= r2 - L; r1--)
//					{
//						// ���� üũ
//						if (tmp[r1][0])
//						{
//							isSuccess = false;
//							isPassable = false;
//							break;
//						}
//
//						if (map[r1][c] != h1)
//						{
//							isSuccess = false;
//							isPassable = false;
//							break;
//						}
//
//						tmp[r1][0] = true;
//					}
//					if (!isSuccess)
//					{
//						isPassable = false;
//						break;
//					}
//
//					// ������ ��� c 1ĭ �̵�
//					r++;
//				}
//
//			}
//		}
//
//		// ������ �� �ִ� �� ī����
//		if (isPassable)
//		{
//			pathCnt++;
//		}
//	}
//
//}
//
///*
//���� ó��
//1) ���θ� ���� ���� �� ���θ� ���� ��� <- �̰Ÿ� ������? -> ���ο� �迭�� üũ
//	-> ���η� ��ġ�� ���� �� ���η� ��ġ�� ���δ� ��ĥ �� ���� (���� 2) <<<
//2) ���� ĭ�� ���� ĭ�� ���� ���̰� 1�� �ƴ� ��� -> �̹� üũ�� (O)
//3) ���� ������ ĭ�� ���̰� ��� ���� �ʰų�, L���� ���ӵ��� ���� ��� -> �̹� üũ�� (O)
//4) ���θ� ���ٰ� ������ ����� ��� -> �̹� �迭 ���� üũ�� (O)
//*/
//
//// continue, break �� ����
//// �Ʒ��� �����ؾ� �ϴµ� �׳� �Ѿ �� ����
//// ���ǹ����� �� �����ٸ� �� �ᵵ �ǰ�,
//// ���� ����Ѵٸ� continue, break ���� �����ϵ��� �����ؾ� ��