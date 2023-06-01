//#include <iostream>
//#include <string>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 20xx. xx. xx.
//// 문제 번호	: #1543 
//// 문제 이름	: 문서 검색
//// 알고리즘	: 문자열
//// 시간복잡도: O()
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 문서 입력
//	string str;
//	getline(cin, str);
//	
//	// 찾으려는 단어 입력
//	string word;
//	getline(cin, word);
//
//	int cnt = 0;
//	/*for (int pos = 0; pos < str.size(); )
//	{
//		pos = str.find(word, pos);
//		if (pos == string::npos)
//			break;
//		
//		cnt++;
//
//		pos += word.size();
//	}*/
//
//	int f = str.find(word, 0);
//	while (f != -1)
//	{
//		cnt++;
//
//		// 인덱스 헷갈릴 때는 직접 작은 경우를 손으로 쓰면서 하자
//		f = str.find(word, f + word.size());
//	}
//
//	cout << cnt;
//
//	return 0;
//}