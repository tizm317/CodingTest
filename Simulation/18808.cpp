//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 19. ��.
//// ���� ��ȣ	: #18808 
//// ���� �̸�	: ��ƼĿ ���̱�
//// �˰���	: �ùķ��̼�
//// �ð����⵵: O()
//
//// ��Ʈ�� ũ��
//int ROW, COL; // 1 <= x <= 40
//int notebook[50][50];
//
//// ��ƼĿ ����
//int K; // 1 <= k <= 100
////vector<vector<vector<int>>> stickerVec;
//queue<vector<vector<int>>> stickerQ; // ������� ���̴ϱ� queue ���
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ��Ʈ�� ����, ����, ��ƼĿ ���� �Է�
//	cin >> ROW >> COL >> K;
//
//	// ��ƼĿ ���� �Է�
//	for (int k = 0; k < K; k++)
//	{
//		// �� ���� ũ��
//		int r, c;
//		cin >> r >> c;
//
//		// ��ƼĿ �Է�
//		vector<vector<int>> sticker;
//		for (int rr = 0; rr < r; rr++)
//		{
//			vector<int> tmp;
//			for (int cc = 0; cc < c; cc++)
//			{
//				int x;
//				cin >> x;
//
//				// ��ƼĿ�� 1��
//				tmp.push_back(x);
//			}
//			// ��ƼĿ 1��
//			sticker.push_back(tmp);
//		}
//
//		// ��ƼĿ ����
//		//stickerVec.push_back(sticker);
//		stickerQ.push(sticker);
//	}
//	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
//	// 0. ���� ��ƼĿ
//	//vector<vector<int>> curSticker = stickerVec[0];
//	//vector<vector<int>> curSticker = stickerQ.front(); stickerQ.pop();
//	// ���� ��ƼĿ�� row, col ������
//	//const int curStickerRowSize = curSticker.size();
//	//const int curStickerColSize = curSticker[0].size();
//
//	/*
//		�ð� ���⵵ ��������.
//		��ƼĿ ���� �ִ� 100 * ȸ�� ����� �� 4�� * (N*M) (40*40) * ������ ũ�� �ִ� 10*10 = 64'000'000
//	*/
//
//	// ��ƼĿ ���� ��ŭ �ݺ�
//	const int stickerCnt = stickerQ.size(); // == K
//	for (int i = 0; i < stickerCnt; i++)
//	{
//		vector<vector<int>> curSticker = stickerQ.front(); stickerQ.pop();
//		int curStickerRowSize = curSticker.size();
//		int curStickerColSize = curSticker[0].size();
//
//		// ȸ�� 0(�⺻), 90, 180, 270
//		for (int rotate = 0; rotate < 4; rotate++)
//		{
//			// 1. ��ƼĿ ���� ������ ã��
//			bool isStickerSuccess = false;
//			for (int rowStart = 0; rowStart < ROW; rowStart++)
//			{
//				//bool isStickerSuccess = false;
//				for (int colStart = 0; colStart < COL; colStart++)
//				{
//					//if (notebook[rowStart][colStart] == 1) // <- notebook ���� �����ϸ� �� ��. (�ؿ��� üũ)
//					//{
//					//	//colStart++;
//					//	continue;
//					//}
//
//					// 2. ��Ʈ�� ����� �� Ȯ��
//					if (rowStart + curStickerRowSize > ROW || colStart + curStickerColSize > COL)
//					{
//						//colStart++;
//						continue;
//					}
//
//					// �� �����?
//					// 3. ���� �� �̹� ��ƼĿ �پ� �ִ� �� Ȯ��
//					bool isSuccess = true;
//					for (int r = rowStart; r < rowStart + curStickerRowSize; r++)
//					{
//						for (int c = colStart; c < colStart + curStickerColSize; c++)
//						{
//							// ��ƼĿ�� �ٿ����ϴ� ���� �̹� ��ƼĿ �پ� ����
//							// curSticker �� 1 �̸鼭(��ƼĿ �κ�) && ��Ʈ�ϵ� ��ƼĿ �κ��� ��� : �� ����!
//							if (curSticker[r - rowStart][c - colStart] == 1 && notebook[r][c] == 1)
//							{
//								isSuccess = false;
//								break;
//							}
//						}
//						if (!isSuccess)
//							break;
//					}
//
//					// 4. ��ƼĿ ���̱�
//					// ���� �� �ִ� ���, notebook �迭 ����
//					if (isSuccess)
//					{
//						for (int r = rowStart; r < rowStart + curStickerRowSize; r++)
//						{
//							for (int c = colStart; c < colStart + curStickerColSize; c++)
//							{
//								if (curSticker[r - rowStart][c - colStart] == 1)
//								{
//									notebook[r][c] = 1;
//								}
//							}
//						}
//
//						// 5. ��ƼĿ�� �ٿ�����, �ٽ� ó������ üũ
//						isStickerSuccess = true;
//						//rowStart = colStart = 0;
//						break;
//					}
//
//				}
//
//				if (isStickerSuccess)
//					break;
//
//				/*if (!isStickerSuccess)
//					rowStart++;*/
//			}
//			
//			// ��ƼĿ ���� ��쿡�� ȸ�� �ʿ����
//			if (isStickerSuccess)
//				break;
//			
//			// ���̱� ������ ���, ȸ�� (rotate �Լ��� ���� �ɵ�)
//			// ��� �ð���� 90�� ȸ��
//			// [R][C] -> [C][size() - 1 - R]
//			vector<vector<int>> resultVec(curStickerColSize, vector<int>(curStickerRowSize, 0));
//			for (int r = 0; r < curStickerRowSize; r++)
//			{
//				for (int c = 0; c < curStickerColSize; c++)
//				{
//					resultVec[c][curStickerRowSize - 1 - r] = curSticker[r][c];
//				}
//			}
//
//			// ȸ���� ����� �ٲٱ�
//			curSticker = resultVec;
//			curStickerRowSize = curSticker.size();
//			curStickerColSize = curSticker[0].size();
//		}
//
//	}
//	
//	// ��Ʈ�� ����ؼ� ��� Ȯ��
//	int cnt = 0;
//	//cout << '\n';
//	for (int r = 0; r < ROW; r++)
//	{
//		for (int c = 0; c < COL; c++)
//		{
//			//cout << notebook[r][c] << " ";
//			if (notebook[r][c] == 1)
//				cnt++;
//		}
//		//cout << '\n';
//	}
//	cout << cnt;
//
//	return 0;
//}
//
//
//
///*
//5 4 3
//3 3
//1 0 1
//1 1 1
//1 0 1
//5 1
//1
//1
//1
//1
//1
//3 3
//0 1 0
//0 1 0
//1 1 1
//
//*/