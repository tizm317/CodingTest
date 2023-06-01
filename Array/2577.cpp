//#include <iostream>
//#include <string>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 20xx. xx. xx.
//// 문제 번호	: #2577 
//// 문제 이름	: 숫자의 개수
//// 알고리즘	: 배열
//// 시간복잡도: O(N)
//
//int a, b, c;
//int num[10]; // 0~9 숫자 출연 빈도
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 숫자 3개 입력
//	cin >> a >> b >> c;
//
//	// 문자열로 변환
//	string s = to_string(a * b * c);
//
//	// 숫자 출연 빈도 계산
//	for (char i : s)
//	{
//		num[i - '0']++;
//	}
//
//	// 숫자 출연 빈도 출력
//	for (int i : num)
//	{
//		cout << i << '\n';
//	}
//
//	// 2. 다른 풀이
//	
//	// 숫자 3개 입력
//	cin >> a >> b >> c;
//
//	int mult = a * b * c;
//	
//	// 자리수 추출 및 출연 빈도 계산
//	while (mult)
//	{
//		num[mult % 10]++;
//		mult /= 10;
//	}
//
//	// 숫자 출연 빈도 출력
//	for (int i : num)
//	{
//		cout << i << '\n';
//	}
//
//	return 0;
//}