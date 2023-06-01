//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 24. 월
//// 문제 번호	: #4949
//// 문제 이름	: 균형 잡힌 세상
//// 알고리즘	: 스택 활용(수식의 괄호 쌍)
//// 시간복잡도: O()
//
//stack<char> Stack_Parentheses;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 문자열 초기화
//	string str = "";
//	while (true)
//	{
//		// 괄호쌍 맞는 지 체크하는 boolean 값 초기화
//		bool balanced = true;
//		
//		// str 한줄씩 입력
//		getline(cin, str);
//
//		// "." 입력 시 반복문 종료
//		if (str == ".")
//			break;
//
//		for (const char& c : str)
//		{
//			// 열린 괄호( (, [ ) 괄호 스택에 푸시
//			if (c == '(' || c == '[')
//			{
//				Stack_Parentheses.push(c);
//			}
//			// 닫힌 괄호는, 대응되는 열린 괄호가 스택에 있는지 확인
//			// 스택이 비어있거나, 다른 경우 balanced = false
//			else if (c == ')' || c == ']')
//			{
//				// 1. 스택이 비어있는 경우, 2. 다른 괄호인 경우
//				if (Stack_Parentheses.empty() || Stack_Parentheses.top() != '(')
//				{
//					balanced = false;
//					break;
//				}
//
//				// 3. 정상적인 경우
//				Stack_Parentheses.pop();
//			}
//			else if (c == ']')
//			{
//				// 스택이 비어있는 경우
//				if (Stack_Parentheses.empty())
//				{
//					balanced = false;
//					break;
//				}
//
//				// 다른 괄호인 경우
//				if (Stack_Parentheses.top() != '[')
//				{
//					balanced = false;
//					break;
//				}
//
//				// 정상적인 경우
//				Stack_Parentheses.pop();
//			}
//		}
//
//		// 4. 스택에 남아 있는 경우
//		// 스택에 남아 있으면 balanced = false (ex : "[." "(." )
//		// 스택 비우기 (전역 변수로 선언해서)
//		while (!Stack_Parentheses.empty())
//		{
//			balanced = false;
//			Stack_Parentheses.pop();
//		}
//
//		// 문자열을 확인 후, boolean 값이 true면 균형잡혀있는 문자열이기 때문에 yes 출력
//		if (balanced)
//			cout << "yes\n";
//		else
//			cout << "no\n";
//	}
//
//	return 0;
//}