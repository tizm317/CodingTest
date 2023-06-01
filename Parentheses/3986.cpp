//#include <iostream>
//#include <stack>
//#include <string> // getline
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 24. 월
//// 문제 번호	: #3986 
//// 문제 이름	: 좋은 단어
//// 알고리즘	: 스택
//// 시간복잡도: O()
//
//int N;
//stack<char> charStack;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 단어 수 입력
//	cin >> N;
//
//	// 개행문자 버퍼에 남는 문제 -> 입력 버퍼 비우기
//	cin.ignore();
//
//	// 좋은 단어 개수 초기화
//	int goodWordCnt = 0;
//
//	for (int i = 0; i < N; i++)
//	{
//		// 문자열 입력
//		string str;
//		getline(cin, str);
//
//		// 스택 내 a, b 갯수 변수
//		//int aCnt = 0, bCnt = 0;
//		bool isGoodWord = true;
//
//		// 반례 : ABABBABA : 좋은 단어인데, 지금 내가 짠 코드로는 안됨.
//		// -> 스택에 다 넣는 방식으로 수정 (최종적으로 스택에 남은 문자가 없으면 좋은 단어, 있으면 나쁜 단어로 판단)
//		// 기존 방식으로는 ABA.. 부터 이미 나쁜 단어로 간주하고 break 되어버림
//
//		for (char c : str)
//		{
//			// 비어있지 않고, top에 있는 문자 == c(들어오는 문자)
//			if (!charStack.empty() && charStack.top() == c)
//			{
//				charStack.pop();
//			}
//			else
//			{
//				charStack.push(c);
//			}
//		}
//
//		// 스택에 남아있으면, false 로 바꾸고 스택 비움
//		while (!charStack.empty())
//		{
//			isGoodWord = false;
//			charStack.pop();
//		}
//
//		// 좋은 단어 개수 세기
//		if (isGoodWord)
//			goodWordCnt++;
//	}
//
//	cout << goodWordCnt;
//
//	return 0;
//}