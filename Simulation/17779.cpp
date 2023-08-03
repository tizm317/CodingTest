//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 20xx. xx. xx.
//// 문제 번호	: #00000 
//// 문제 이름	: 
//// 알고리즘	: 
//// 시간복잡도: O()
//
//int N; // <= 20
//int map[25][25];
//
//int ans = -1;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cin >> map[r][c];
//		}
//	}
//
//	//
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			// 기준점
//			int x = r, y = c;
//			//if (!(x == 1 && y == 3)) continue;
//
//			// 경계 길이
//			int d1 = 1, d2 = 1; // d1, d2 ≥ 1
//			for (; (x >= 0) && (x + d1 + d2 < N); d1++) // 1 ≤ x < x+d1+d2 ≤ N
//			{
//				for (; (y - d1 >= 0) && (y - d1 < y) && (y < y + d2) && (y + d2 < N); d2++) // 1 ≤ y-d1 < y < y+d2 ≤ N
//				{
//					/*if ((d1 == 2 && d2 == 2))
//					{
//						cout << '\n';
//					}*/
//
//					int x1 = x + d1, y1 = y - d1; // 좌
//					if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= N) continue;
//
//					int x2 = x + d2, y2 = y + d2; // 우
//					if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= N) continue;
//
//					int x3 = x + d1 + d2, y3 = y - d1 + d2; // 하
//					if (x3 < 0 || x3 >= N || y3 < 0 || y3 >= N) continue;
//
//					//
//					int cntArr[5] = { 0, };
//					int peopleCntArr[5] = { 0, };
//					for (int r = 0; r < N; r++)
//					{
//						for (int c = 0; c < N; c++)
//						{
//							// equation of line
//							// y-y1 = (y2-y1)/(x2-x1) * (x-x1)
//							
//							// y 가 c , x 가 r 라서 반대로
//							// 아래로 갈수록 x가 커지는거라 반대..
//
//							// eol1, eol 는 직선보다 같거나 위(!)
//							bool eol1 = (r - x1 >= (x - x1) / (y - y1) * (c - y1)); // (x,y) (x1,y1)
//							bool eol2 = (r - x2 >= (x2 - x) / (y2 - y) * (c - y2)); // (x,y) (x2,y2)
//							
//							// eol3, eol4 는 직선보다 같거나 아래(!)
//							bool eol3 = (r - x3 <= (x3 - x1) / (y3 - y1) * (c - y3)); // (x1,y1) (x3,y3)
//							bool eol4 = (r - x3 <= (x2 - x3) / (y2 - y3) * (c - y3)); // (x2,y2) (x3,y3)
//
//							// 5번 선거구
//							if (eol1 && eol2 && eol3 && eol4)
//							{
//								cntArr[4]++;
//								peopleCntArr[4] += map[r][c];
//								continue;
//							}
//
//							// 1번 선거구
//							if (r >= 0 && r < x1 && c >= 0 && c <= y)
//							{
//								cntArr[0]++;
//								peopleCntArr[0] += map[r][c];
//							}
//							// 2번 선거구
//							if (r >= 0 && r <= x2 && c > y && c < N) 
//							{
//								cntArr[1]++;
//								peopleCntArr[1] += map[r][c];
//							}
//							// 3번 선거구
//							if (r >= x1 && r < N && c >= 0 && c < y3)
//							{
//								cntArr[2]++;
//								peopleCntArr[2] += map[r][c];
//							}
//							// 4번 선거구
//							if (r > x2 && r < N && c >= y3 && c < N)
//							{
//								cntArr[3]++;
//								peopleCntArr[3] += map[r][c];
//							}
//						}
//					}
//
//					
//					//cout << '\n';
//					int total = 0;
//					int maxCnt = -1;
//					int minCnt = -1;
//					bool fail = false;
//					for (int i = 0; i < 5; i++)
//					{
//						// 최소 1개 이상의 구역
//						if (cntArr[i] == 0)
//						{
//							fail = true;
//							break;
//						}
//
//						////cout << cntArr[i] << " ";
//						//cout << peopleCntArr[i] << " ";
//						////total += cntArr[i];
//						total += peopleCntArr[i];
//
//						//maxCnt = (maxCnt == -1) ? cntArr[i] : max(maxCnt, cntArr[i]);
//						maxCnt = (maxCnt == -1) ? peopleCntArr[i] : max(maxCnt, peopleCntArr[i]);
//						//minCnt = (minCnt == -1) ? cntArr[i] : min(minCnt, cntArr[i]);
//						minCnt = (minCnt == -1) ? peopleCntArr[i] : min(minCnt, peopleCntArr[i]);
//
//						
//					}
//					//cout << "= " << total;
//					////cout << " max : " << maxCnt << ", min : " << minCnt << ", diff : " << maxCnt - minCnt;
//					//cout << " max : " << maxCnt << ", min : " << minCnt << ", diff : " << maxCnt - minCnt;
//					//cout << '\n';
//
//					const int diff = maxCnt - minCnt;
//					ans = (ans == -1) ? diff : min(ans, diff);
//				}
//				
//				d2 = 1;
//			}
//		}
//	}
//
//	cout << ans;
//
//	return 0;
//}