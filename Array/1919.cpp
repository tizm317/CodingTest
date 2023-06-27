//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 06. 27. 화.
//// 문제 번호	: #1919 
//// 문제 이름	: 애너그램 만들기
//// 알고리즘	: 배열
//// 시간복잡도: O()
//
//int freqX[26];
//int freqY[26];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	string x, y;
//	cin >> x >> y;
//
//	// 알파벳 빈도수
//	for (auto c : x)
//		freqX[c - 'a']++;
//	
//	for (auto c : y)
//		freqY[c - 'a']++;
//
//	// 지워야 하는 문자 개수 =
//	// 두 문자열 알파벳 빈도수 중 큰 값 - 작은 값 계산 후 ans 에 더함
//	int ans = 0;
//	for (int i = 0; i < 26; i++)
//	{
//		ans += (max(freqX[i], freqY[i]) - min(freqX[i], freqY[i]));
//	}
//	
//	cout << ans;
//
//	return 0;
//}