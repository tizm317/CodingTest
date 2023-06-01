//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <math.h>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 20xx. xx. xx.
//// 문제 번호	: #1475 
//// 문제 이름	: 방 번호
//// 알고리즘	: 배열
//// 시간복잡도: O(N)
//
//string N;		// 방번호
//int num[10];	// 0 ~ 9 숫자 출연 빈도 배열
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 1. 내 풀이
//	// 방 번호 입력
//	//cin >> N;
//
//	//// 숫자 출연 빈도
//	//for (char c : N)
//	//{
//	//	num[c - '0']++;
//	//}
//
//	//// 필요한 셋트의 최소값을 구함.
//	//// 6, 9 호환 가능 -> 평균 내고 올림
//	//// 99999 -> 9[5] -> 9[2.5] 6[2.5] -> 9[3] 6[3]
//	//num[6] = num[9] = ceil(((double)num[6] + num[9]) / 2.0);
//
//	//// 숫자 빈도의 최댓값 출력
//	//cout << *max_element(num, num + 10) << '\n';
//
//	// 2. 다른 풀이
//	int N;
//	cin >> N;
//
//	// 자리수 추출
//	while (N)
//	{
//		num[N % 10]++;
//		N /= 10;
//	}
//
//	int ans = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		if (i == 6 || i == 9) 
//			continue;
//
//		ans = max(ans, num[i]);
//	}
//
//	// 6, 9 호환 가능 -> 6, 9 빈도 평균을 올림한 값
//	ans = max(ans, (num[6] + num[9] + 1) / 2);
//
//	cout << ans;
//
//	return 0;
//}