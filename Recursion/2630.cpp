//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 10. 수.
//// 문제 번호	: #2630 
//// 문제 이름	: 색종이 만들기
//// 알고리즘	: 
//// 시간복잡도: O()
//
//int N; // <= 2^7 = 128
//int paper[130][130];
//
//int colorCnt[3];
//// 0 : 하얀색 , 1 : 파란색
//// 2 : 섞임
//
//// (r,c) 시작점
//int func(int n, int r, int c)
//{
//	if (n == 1)
//		return paper[r][c];
//
//	int arr[3] = { 0, };
//	for (int row = 0; row < 2; row++)
//	{
//		for (int col = 0; col < 2; col++)
//		{
//			arr[func(n / 2, r + row * n / 2, c + col * n / 2)]++;
//		}
//	}
//
//	// 하나의 종이
//	for (int i = 0; i < 2; i++)
//	{
//		if (arr[i] == 4)
//		{
//			return i;
//		}
//	}
//
//	// 섞인 경우
//	for (int i = 0; i < 2; i++)
//	{
//		colorCnt[i] += arr[i];
//	}
//
//	return 2;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	for (int r = 0; r < N; r++)
//		for (int c = 0; c < N; c++)
//			cin >> paper[r][c];
//
//	colorCnt[func(N, 0, 0)]++;
//
//	cout << colorCnt[0] << '\n';
//	cout << colorCnt[1] << '\n';
//
//	return 0;
//}