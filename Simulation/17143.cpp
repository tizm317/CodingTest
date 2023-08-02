//#include <iostream>
//#include <utility>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 08. 02. 수.
//// 문제 번호	: #17143 
//// 문제 이름	: 낚시왕
//// 알고리즘	: 시뮬레이션
//// 시간복잡도: O()
//
//int R, C; // <= 100
//int board[105][105];
//
//int M; //0 <=  <= R * C
//
//// 상어 정보(속력, 방향) 담는 배열 - 상어 크기가 index 역할
//// z <= 10000
//pair<int, int> sharkInfo[10005]; // {속력 s, 방향 d}
//
//// 상, 하, 우, 좌
////const int dRow[4] = { -1, 1, 0, 0 };
////const int dCol[4] = { 0, 0, 1, -1 };
//
//// 같은 크기 상어 X -> 상어 크기로 구분
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
//		// board 배열 상어 위치에 크기 저장
//		board[r][c] = z;
//
//		// 상어의 속력, 방향은 sharkInfo 배열에 저장
//		sharkInfo[z] = { s,d-1 }; // d = d-1; 0~3으로 수정
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
//	// 0. 낚시왕은 처음에 1번 열의 한 칸 왼쪽에 있다. 
//	pair<int, int> fishingKingPos = { 0,0 };
//	int cnt = 0;
//	while (true)
//	{
//		if(cnt == M) break;
//
//		// 1. 낚시왕이 오른쪽으로 한 칸 이동한다.
//		fishingKingPos.second++;
//		const int c = fishingKingPos.second;
//
//		// 낚시왕은 가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.
//		if (c > C) break;
//
//		// 2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
//		for (int r = 1; r < R; r++)
//		{
//			// 없으면 pass
//			if (board[r][c] == 0) continue;
//
//			// 있으면 크기 더해주고 break (제일 가까운 상어 잡으면 break)
//			sum_shark_size += board[r][c];
//			
//			// 잡은 상어 개수
//			cnt++;
//
//			// 상어 사라짐
//			board[r][c] = 0;
//			break;
//		}
//
//		// 3. 상어가 이동한다.
//		int movedSharkBoard[105][105] = { 0, };
//		for (int r = 1; r < R; r++)
//		{
//			for (int c = 1; c < C; c++)
//			{
//				// 상어 크기
//				const int sharkSize = board[r][c];
//				// 0이면 상어 X -> pass
//				if (sharkSize == 0) continue;
//				if (sharkSize == 9)
//				{
//					int a = 1 + 1;
//				}
//
//				// 상어 크기 이용해서 정보 가져옴
//				pair<int, int>& info = sharkInfo[sharkSize]; // <<<<<<<<<<<<<<<<<<<<<<<<<<< 복사 일어나서 안 바뀜! 레퍼런스
//				int dist = info.first;
//				int& dir = info.second;
//
//				// 상어 위치
//				int sharkR = r;
//				int sharkC = c;
//
//				switch (dir)
//				{
//				case 0: // 상
//					if (sharkR - dist <= 1)
//					{
//						// 이동 거리 감소
//						dist -= (sharkR -1);
//
//						// 1 로 위치 이동
//						sharkR = 1;
//
//						// 방향 전환
//						dir++;
//
//						// 나머지 이동
//						if ((dist / (R - 2)) % 2 == 0)
//						{
//							// 짝수면 1 위치에서 down 방향
//							// dist % (R-2) 만큼 이동
//							sharkR += (dist % (R - 2));
//						}
//						else
//						{
//							// 홀수면 R-1 위치에서 up 방향
//							// dist % (R-2) 만큼 이동
//							dir--;
//							sharkR = R-1;
//							sharkR -= (dist % (R - 2));
//						}
//					}
//					else
//					{
//						// 위치 이동
//						sharkR = sharkR - dist;
//					}
//					break;
//				case 1: // 하
//					if (sharkR + dist >= (R - 1))
//					{
//						// 이동 거리 감소
//						dist -= ((R - 1) - sharkR);
//
//						// R-1 로 위치 이동
//						sharkR = R - 1;
//
//						// 방향 전환
//						dir--;
//
//						// 나머지 이동
//						if ((dist / (R - 2)) % 2 == 0)
//						{
//							// 짝수면 (R-1) 위치에서 up 방향
//							// dist % (R-2) 만큼 이동
//							sharkR -= (dist % (R - 2));
//						}
//						else
//						{
//							// 홀수면 1 위치에서 down 방향
//							// dist % (R-2) 만큼 이동
//							dir++; // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 빼먹음
//							sharkR = 1;
//							sharkR += (dist % (R - 2));
//						}
//					}
//					else
//					{
//						// 위치 이동
//						sharkR = sharkR + dist;
//					}
//					break;
//				case 2: // 우
//					if (sharkC + dist >= (C - 1))
//					{
//						// 이동 거리 감소
//						dist -= ((C - 1) - sharkC);
//
//						// C-1 로 위치 이동
//						sharkC = C-1;
//
//						// 방향 전환
//						dir++;
//
//						// 나머지 이동
//						if ((dist / (C - 2)) % 2 == 0)
//						{
//							// 짝수면 (C-1) 위치에서 <- 방향
//							// dist % (C-2) 만큼 이동
//							sharkC -= (dist % (C - 2));
//						}
//						else
//						{
//							// 홀수면 1 위치에서 -> 방향
//							// dist % (C-2) 만큼 이동
//							dir--;
//							sharkC = 1;
//							sharkC += (dist % (C - 2));
//						}
//					}
//					else
//					{
//						// 위치 이동
//						sharkC = sharkC + dist;
//					}
//					break;
//				case 3: // 좌
//					if (sharkC - dist <= 1)
//					{
//						// 이동 거리 감소
//						dist -= (sharkC - 1);
//
//						// 1 로 위치 이동
//						sharkC = 1;
//
//						// 방향 전환
//						dir--;
//
//						// 나머지 이동
//						if ((dist / (C - 2)) % 2 == 0)
//						{
//							// 짝수면 1 위치에서 -> 방향
//							// dist % (C-2) 만큼 이동
//							sharkC += (dist % (C - 2));
//						}
//						else
//						{
//							// 홀수면 C-1 위치에서 <- 방향
//							// dist % (C-2) 만큼 이동
//							dir++;
//							sharkC = C-1;
//							sharkC -= (dist % (C - 2));
//						}
//					}
//					else
//					{
//						// 위치 이동
//						sharkC = sharkC - dist;
//					}
//					break;
//				}
//
//				// 큰 상어 1마리만 남음
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
//	// 낚시왕이 잡은 상어 크기의 합을 출력한다.
//	cout << sum_shark_size;
//
//	return 0;
//}