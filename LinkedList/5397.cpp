//#include <iostream>
//#include <list>
//#include <iterator>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 24. 월
//// 문제 번호	: #5397 
//// 문제 이름	: 키로거
//// 알고리즘	: 연결 리스트
//// 시간복잡도: O()
//
//int T;
//string s;
//list<char> strList;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 1. STL list 풀이
//
//	// 1) 테스트 케이스 개수 입력
//	cin >> T;
//
//	// 2) 테케 개수 만큼 문자열 입력
//	for (int i = 0; i < T; i++)
//	{
//		// list 초기화
//		strList.clear();
//		cin >> s;
//
//		//  커서 역할 iterator 초기화
//		list<char>::iterator cursor = strList.begin();
//
//		// string 에 입력 받은 문자열을 list에 넣음
//		for (char c : s)
//		{
//			// 문자 따라서 다르게 작동
//			switch (c)
//			{
//				// 커서 이동
//			case '<':
//				if(cursor != strList.begin())
//					cursor--;
//				break;
//			case '>':
//				if (cursor != strList.end())
//					cursor++;
//				break;
//				// 백스페이스
//			case '-':
//				if (cursor != strList.begin())
//				{
//					cursor--;
//					cursor = strList.erase(cursor);
//				}
//				break;
//				// 나머지 문자
//			default:
//				strList.insert(cursor, c);
//				break;
//			}
//		}
//
//		// 결과물 출력
//		for (const char& c : strList)
//		{
//			cout << c;
//		}
//
//		cout << '\n';
//	}
//	
//
//	return 0;
//}