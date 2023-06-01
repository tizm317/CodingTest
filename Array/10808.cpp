//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 20xx. xx. xx.
//// 문제 번호	: #10808 
//// 문제 이름	: 알파벳 개수
//// 알고리즘	: 배열
//// 시간복잡도: O(N)
//
//// 전역으로 선언해서 0으로 초기화
//char word[105];		// 글자 담는 char 배열
//int alphabet[26];	// 알파벳 등장 횟수 담는 배열
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 글자 입력
//	cin >> word;
//
//	// 글자 배열 돌면서 알파벳 등장 횟수 확인
//	for (int i = 0; i < 100; i++)
//	{
//		if (word[i] == '\0')
//			break;
//
//		// a(0) ~ z(25) 글자의 알파벳 등장 횟수 확인 후 증가
//
//		// 'a' 아스키 코드 97
//		// 그냥 'a' 빼도 됨.
//		alphabet[word[i] - 'a'] += 1;
//	}
//
//	// 알파벳별 개수 출력
//	for (int i = 0; i < 26; i++)
//	{
//		cout << alphabet[i] << " ";
//	}
//
//	return 0;
//}