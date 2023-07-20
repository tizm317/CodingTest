//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 19. 수.
//// 문제 번호	: #18808 
//// 문제 이름	: 스티커 붙이기
//// 알고리즘	: 시뮬레이션
//// 시간복잡도: O()
//
//// 노트북 크기
//int ROW, COL; // 1 <= x <= 40
//int notebook[50][50];
//
//// 스티커 개수
//int K; // 1 <= k <= 100
////vector<vector<vector<int>>> stickerVec;
//queue<vector<vector<int>>> stickerQ; // 순서대로 붙이니까 queue 사용
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 노트북 세로, 가로, 스티커 개수 입력
//	cin >> ROW >> COL >> K;
//
//	// 스티커 정보 입력
//	for (int k = 0; k < K; k++)
//	{
//		// 모눈 종이 크기
//		int r, c;
//		cin >> r >> c;
//
//		// 스티커 입력
//		vector<vector<int>> sticker;
//		for (int rr = 0; rr < r; rr++)
//		{
//			vector<int> tmp;
//			for (int cc = 0; cc < c; cc++)
//			{
//				int x;
//				cin >> x;
//
//				// 스티커의 1줄
//				tmp.push_back(x);
//			}
//			// 스티커 1장
//			sticker.push_back(tmp);
//		}
//
//		// 스티커 벡터
//		//stickerVec.push_back(sticker);
//		stickerQ.push(sticker);
//	}
//	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
//	// 0. 현재 스티커
//	//vector<vector<int>> curSticker = stickerVec[0];
//	//vector<vector<int>> curSticker = stickerQ.front(); stickerQ.pop();
//	// 현재 스티커의 row, col 사이즈
//	//const int curStickerRowSize = curSticker.size();
//	//const int curStickerColSize = curSticker[0].size();
//
//	/*
//		시간 복잡도 따져보자.
//		스티커 개수 최대 100 * 회전 경우의 수 4개 * (N*M) (40*40) * 모눈종이 크기 최대 10*10 = 64'000'000
//	*/
//
//	// 스티커 개수 만큼 반복
//	const int stickerCnt = stickerQ.size(); // == K
//	for (int i = 0; i < stickerCnt; i++)
//	{
//		vector<vector<int>> curSticker = stickerQ.front(); stickerQ.pop();
//		int curStickerRowSize = curSticker.size();
//		int curStickerColSize = curSticker[0].size();
//
//		// 회전 0(기본), 90, 180, 270
//		for (int rotate = 0; rotate < 4; rotate++)
//		{
//			// 1. 스티커 없는 시작점 찾기
//			bool isStickerSuccess = false;
//			for (int rowStart = 0; rowStart < ROW; rowStart++)
//			{
//				//bool isStickerSuccess = false;
//				for (int colStart = 0; colStart < COL; colStart++)
//				{
//					//if (notebook[rowStart][colStart] == 1) // <- notebook 꺼만 생각하면 안 됨. (밑에서 체크)
//					//{
//					//	//colStart++;
//					//	continue;
//					//}
//
//					// 2. 노트북 벗어나는 지 확인
//					if (rowStart + curStickerRowSize > ROW || colStart + curStickerColSize > COL)
//					{
//						//colStart++;
//						continue;
//					}
//
//					// 안 벗어나면?
//					// 3. 범위 내 이미 스티커 붙어 있는 지 확인
//					bool isSuccess = true;
//					for (int r = rowStart; r < rowStart + curStickerRowSize; r++)
//					{
//						for (int c = colStart; c < colStart + curStickerColSize; c++)
//						{
//							// 스티커를 붙여야하는 곳에 이미 스티커 붙어 있음
//							// curSticker 가 1 이면서(스티커 부분) && 노트북도 스티커 부분인 경우 : 못 붙임!
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
//					// 4. 스티커 붙이기
//					// 붙일 수 있는 경우, notebook 배열 갱신
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
//						// 5. 스티커를 붙였으면, 다시 처음부터 체크
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
//			// 스티커 붙인 경우에는 회전 필요없음
//			if (isStickerSuccess)
//				break;
//			
//			// 붙이기 실패한 경우, 회전 (rotate 함수로 빼도 될듯)
//			// 행렬 시계방향 90도 회전
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
//			// 회전한 결과로 바꾸기
//			curSticker = resultVec;
//			curStickerRowSize = curSticker.size();
//			curStickerColSize = curSticker[0].size();
//		}
//
//	}
//	
//	// 노트북 출력해서 결과 확인
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