//#include <iostream>
//#include <vector>
//#include <utility>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 26. 수
//// 문제 번호	: #14890 
//// 문제 이름	: 경사로
//// 알고리즘	: 시뮬레이션
//// 시간복잡도: O()
//
//int N; // <= 100
//int map[105][105];
//
//int L; // 1 <= L <= N
//
//// 지나갈 수 있는 길 갯수
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
//	// 지도, L 입력
//	cin >> N >> L;
//	for (int r = 0; r < N; r++)
//		for (int c = 0; c < N; c++)
//			cin >> map[r][c];
//
//	findHorizontalPath();
//	findVerticalPath();
//
//	// 지나갈 수 있는 길 갯수 출력
//	cout << pathCnt;
//
//	return 0;
//}
//
//void findHorizontalPath()
//{
//	// 가로 Scan : N*N
//	for (int r = 0; r < N; r++)
//	{
//		// 경사로 배치 여부 체크용 bool 배열
//		bool tmp[1][105] = { false, };
//
//		// 지나갈 수 있는 곳 체크할 bool 변수
//		bool isPassable = true;
//		for (int c = 0; c < N - 1;)
//		{
//			// 기준
//			const int h1 = map[r][c];
//
//			// 비교 대상
//			int c2 = c + 1;
//			const int h2 = map[r][c2];
//
//			// 높이 같은 경우
//			if (h1 == h2)
//			{
//				// 기준 idx 이동(+1)
//				c++;
//			}
//			else // 높이 다른 경우
//			{
//				// 경사로 놓을 수 있는지 확인
//
//				// 1. 높이 차이 1 인지
//				const int diff = std::abs(h1 - h2);
//				if (diff != 1)
//				{
//					isPassable = false;
//					break;
//				}
//
//				// 2. 어느 방향으로 경사로를 놓을 지 (누가 더 높은지)
//					// 그 방향으로 L 범위만큼 체크
//
//				// 경사로 이미 배치된 경우 <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 경사로 체크 위치 조정
//				//if (ramp[r][c2] || tmp[0][c2])
//				////if (tmp[0][c2])
//				//{
//				//	isPassable = false;
//				//	break;
//				//}
//
//				if (h1 > h2) // 왼쪽으로 높은 (오른쪽 범위 체크)
//				{
//					// 배열 범위 넘는 경우
//					if (c + L >= N)
//					{
//						isPassable = false;
//						break;
//					}
//
//					// C+L 까지 h2 와 같은지 비교
//					bool isSuccess = true;
//					//for (c2 += 1; c2 <= c + L; c2++) // tmp 배열 체크 한번에 하려고, 아래로 다시 수정함.
//					for (; c2 <= c + L; c2++)
//					{
//						// 경사로 체크
//						if (tmp[0][c2])
//						{
//							isSuccess = false;
//							isPassable = false;
//							break;
//						}
//
//						// 낮은 지점의 칸의 높이 같아야 함
//						if (map[r][c2] != h2)
//						{
//							isSuccess = false;
//							isPassable = false;
//							break;
//						}
//
//						// 경사로 배치 표시
//						tmp[0][c2] = true;
//					}
//
//					if (!isSuccess)
//					{
//						isPassable = false;
//						break;
//					}
//
//					// 성공한 경우 (L+1) 칸 이동 <<<<<<<<<<<< L 칸 이동! (L, L+1 비교 안함)
//					//c += (L + 1);
//					c += L;
//				}
//				else // h1 < h2 // 오른쪽으로 높은 (왼쪽 범위 체크)
//				{
//					// 배열 범위 넘는 경우
//					if (c2 - L < 0)
//					{
//						isPassable = false;
//						break;
//					}
//
//					// c2 - L 까지 h1 이랑 같은지 비교
//					bool isSuccess = true;
//					int c1 = c; // c 직접 안 움직이기 위한 변수
//					//for (c1 -= 1; c1 >= c2 - L; c1--)
//					for (; c1 >= c2 - L; c1--)
//					{
//						// 경사로 체크
//						if (tmp[0][c1])
//						{
//							isSuccess = false;
//							isPassable = false;
//							break;
//						}
//
//						//if (c1 < 0) break; <<< 없어도 여기 안으로 못 들어오긴 함
//
//						// 낮은 지점의 칸의 높이 같아야 함
//						if (map[r][c1] != h1)
//						{
//							isSuccess = false;
//							isPassable = false;
//							break;
//						}
//
//						// 경사로 배치 표시
//						tmp[0][c1] = true;
//					}
//
//					if (!isSuccess)
//					{
//						isPassable = false;
//						break;
//					}
//
//					// 성공한 경우 c 1칸 이동
//					c++;
//				}
//
//			}
//		}
//
//		// 지나갈 수 있는 길 카운팅
//		if (isPassable)
//		{
//			pathCnt++;
//
//			// 경사로 배치 >> 가로로 배치한 경사로 와 세로로 배치한 경사로는 겹칠 수 있음 (예제 2) >> 빼버림
//			/*for (int c = 0; c < N; c++)
//				ramp[r][c] = tmp[0][c];*/
//		}
//	}
//}
//void findVerticalPath()
//{
//	// 세로 Scan : N*N
//	for (int c = 0; c < N; c++)
//	{
//		bool tmp[105][1] = { false, };
//
//		// 지나갈 수 있는 곳 체크할 bool 변수
//		bool isPassable = true;
//		for (int r = 0; r < N - 1;)
//		{
//			// 기준
//			const int h1 = map[r][c];
//
//			// 비교 대상
//			int r2 = r + 1;
//			const int h2 = map[r2][c];
//
//			// 높이 같은 경우
//			if (h1 == h2)
//			{
//				// 기준 idx 이동(+1)
//				r++;
//			}
//			else // 높이 다른 경우
//			{
//				// 경사로 놓을 수 있는지 확인
//
//				// 1. 높이 차이 1 인지
//				const int diff = std::abs(h1 - h2);
//				if (diff != 1)
//				{
//					isPassable = false;
//					break;
//				}
//
//				// 2. 어느 방향으로 경사로를 놓을 지 (누가 더 높은지)
//					// 그 방향으로 L 범위만큼 체크
//
//				if (h1 > h2) // 위쪽으로 높은 (아래쪽 범위 체크)
//				{
//					// 배열 범위 넘는 경우
//					if (r + L >= N)
//					{
//						isPassable = false;
//						break;
//					}
//					// R+L 까지 h2 와 같은지 비교
//					bool isSuccess = true;
//					for (; r2 <= r + L; r2++)
//					{
//						// 경사로 체크
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
//					// 성공한 경우 L 칸 이동
//					r += L;
//				}
//				else // h1 < h2 // 아래쪽으로 높은 (위쪽 범위 체크)
//				{
//					// 배열 범위 넘는 경우
//					if (r2 - L < 0)
//					{
//						isPassable = false;
//						break;
//					}
//
//					// r2 - L 까지 h1 이랑 같은지 비교
//					bool isSuccess = true;
//					int r1 = r; // r 직접 안 움직이기 위한 변수
//					for (; r1 >= r2 - L; r1--)
//					{
//						// 경사로 체크
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
//					// 성공한 경우 c 1칸 이동
//					r++;
//				}
//
//			}
//		}
//
//		// 지나갈 수 있는 길 카운팅
//		if (isPassable)
//		{
//			pathCnt++;
//		}
//	}
//
//}
//
///*
//예외 처리
//1) 경사로를 놓은 곳에 또 경사로를 놓는 경우 <- 이거만 남은듯? -> 새로운 배열로 체크
//	-> 가로로 배치한 경사로 와 세로로 배치한 경사로는 겹칠 수 있음 (예제 2) <<<
//2) 낮은 칸과 높은 칸의 높이 차이가 1이 아닌 경우 -> 이미 체크함 (O)
//3) 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우 -> 이미 체크함 (O)
//4) 경사로를 놓다가 범위를 벗어나는 경우 -> 이미 배열 범위 체크함 (O)
//*/
//
//// continue, break 는 조심
//// 아랫쪽 실행해야 하는데 그냥 넘어갈 수 있음
//// 조건문으로 잘 나눴다면 안 써도 되고,
//// 만약 써야한다면 continue, break 전에 실행하도록 수정해야 함