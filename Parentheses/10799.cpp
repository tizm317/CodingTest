//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2024. 04. 24. 월
//// 문제 번호	: #10799
//// 문제 이름	: 쇠막대기
//// 알고리즘	: 스택
//// 시간복잡도: O()
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	string str;
//	cin >> str;
//
//	//int overlappedBarCnt = 0;	// 겹쳐 있는 바 갯수 -> 그냥 스택 size 써도 됨
//	int totalBarCnt = 0;		// 자른 후 바 갯수
//
//	// 직전 문자 저장용 -> 레이저인지 막대기인지 파악하기 위함.
//	// 1. 직전 문자가 '(' 이면 레이저 "()"
//	// 2. 직전 문자가 ')' 이면 막대기 why? "(())" 대충 이런 형태라는 얘기
//	//char beforChar = '\0';
//
//	bool isPopped = false;
//
//	stack<char> charStack;
//
//	for (char c : str)
//	{
//		if (c == '(')
//		{
//			charStack.push(c);
//
//			// 막대기 가능성 있기 때문에 overlappedBarCnt 증가
//			//overlappedBarCnt++; 
//
//			isPopped = false;
//		}
//		else if (c == ')')
//		{
//			// 직전 문자가 '(' 이면 현재 문자(c) 는 레이저 
//			//if (beforChar == '(')
//			
//			// isPopped 가 false : '('
//			if(isPopped == false)
//			{
//				// "()" : 레이저
//				if (charStack.top() == '(')
//				{
//					// 막대기 아니라 overlappedBarCnt 감소;
//					//overlappedBarCnt--;
//					charStack.pop();
//					isPopped = true;
//
//					// 겹쳐진 막대기 갯수만큼 자름
//					//totalBarCnt += overlappedBarCnt;
//					totalBarCnt += charStack.size();
//				}
//			}
//			else // 직전 문자 ')' 이면, 현자 문자(c) 는 막대기
//			{
//				// 막대기 끝났으니,
//				// 겹친 막대기 개수 -1 
//				//overlappedBarCnt--;
//
//				charStack.pop();
//				isPopped = true;
//
//				// 전체 막대기 개수 +1 (잘려서 추가된 막대기 말고, 막대기 그자체 하나 추가해줘야 함)
//				totalBarCnt++;
//
//			}
//
//		}
//
//		// 이전 문자 저장 
//		//beforChar = c;
//	}
//
//	// 막대기 갯수 출력
//	cout << totalBarCnt;
//
//	return 0;
//}