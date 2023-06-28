//#include <iostream>
//#include <stack>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 25. 화
//// 문제 번호	: #2504 
//// 문제 이름	: 괄호의 값
//// 알고리즘	: 스택
//// 시간복잡도: O()
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 문자열 입력
//	string str;
//	cin >> str;
//
//	bool isValid = true;
//
//	// 문제 : 문자랑 숫자를 같이 저장하려다보니 생김
//	// 숫자 더하다가 우연히 (, ), [, ] 등의 아스키 코드와 같아지면 이상해짐
//	// 그리고 char 로 할 시, 숫자 더하다가 범위 벗어남
//	// string 2^30 이하 니까 int 범위 내 해결되긴 함.
//
//	// ->>>>>>>>>>>> 스택 2개로 해결
//
//	// string 2^30 이하 -> int 범위
//	stack<char> expStack; // 수식 스택 <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//	stack<int> numStack; // 값 스택
//
//	for (char c : str)
//	{
//		// 1. 여는 괄호 (, [ : 스택에 push
//		if (c == '(' || c == '[')
//		{
//			expStack.push(c);
//		}
//		else if (c == ')') // 2. 닫는 괄호 )
//		{
//			// 0. 비어있는 경우 : 올바르지 않음
//			if (expStack.empty())
//			{
//				isValid = false;
//				break;
//			}
//
//			// 1. "()" : 여는 괄호를 2로 바꿈
//			if (expStack.top() == '(')
//			{
//				expStack.pop();		// ( 빼고
//				expStack.push(2);	// 2 넣음
//
//				numStack.push(2);	// 실제값
//			}
//			// 2. [) : 올바르지 않은 경우
//			else if(expStack.top() == '[') 
//			{
//				isValid = false;
//				break;
//			}
//			else // 3. 숫자 있는 경우
//			{
//				// 괄호 사이 숫자들 더함
//				int sum = 0;
//
//				// 여는 괄호 나올 때까지, 숫자 더함
//				while (!expStack.empty() && expStack.top() != '(')
//				{
//					if (expStack.top() == '[')
//					{
//						isValid = false;
//						break;
//					}
//
//					expStack.pop();
//
//					sum += numStack.top();
//					numStack.pop();
//				}
//
//				// 스택 내에 여는 괄호가 없던 경우! : 올바르지 않음
//				if (expStack.empty())
//				{
//					isValid = false;
//					break;
//				}
//				else // 정상적인 경우
//				{
//					// 괄호 제거
//					expStack.pop();
//				}
//
//				expStack.push(2); // 숫자임을 표시
//
//				// sum에 2 곱한 후 push
// 				numStack.push(sum * 2);
//			}
//		}
//		else if (c == ']')
//		{
//			// 0. 비어있는 경우 : 올바르지 않음
//			if (expStack.empty())
//			{
//				isValid = false;
//				break;
//			}
//
//			// 1. "[]"
//			if (expStack.top() == '[')
//			{
//				expStack.pop();		// ( 빼고
//				expStack.push(3);	// 3 넣음
//
//				numStack.push(3);
//			}
//			// 2. "(]"
//			else if (expStack.top() == '(')
//			{
//				// 올바르지 않음
//				isValid = false;
//				break;
//			}
//			else // 3. 숫자 있는 경우
//			{
//				// 괄호 사이 '숫자들' 더함
//				int sum = 0;
//				while (!expStack.empty() && expStack.top() != '[')
//				{
//					if (expStack.top() == '(')
//					{
//						isValid = false;
//						break;
//					}
//
//					expStack.pop();
//
//					sum += numStack.top();
//					numStack.pop();
//				}
//
//				// 스택 내에 여는 괄호가 없던 경우! : 올바르지 않음
//				if (expStack.empty())
//				{
//					isValid = false;
//					break;
//				}
//				else // 정상적인 경우
//				{
//					// 괄호 제거
//					expStack.pop();
//				}
//				
//				expStack.push(3); // 숫자가 들어감을 표시
//
//				// sum에 3 곱한 후 push
//				numStack.push(sum * 3);
//			}
//		}
//	}
//
//	// 최종적으로 스택에 남은 숫자들 더함
//	int res = 0;
//	while (!expStack.empty())
//	{
//		// 스택 내에 여는 괄호 남아 있으면, 올바르지 않은 경우
//		if (expStack.top() == '(' || expStack.top() == '[')
//		{
//			isValid = false;
//			break;
//		}
//
//		expStack.pop();
//
//		res += numStack.top();
//		numStack.pop();
//	}
//
//	// 결과물 출력
//	if (isValid)
//		cout << res;
//	else
//		cout << 0;
//
//
//	return 0;
//}