#include <iostream>
#include <stack>
using namespace std;

// 백준 문제 풀이
// 날짜		: 2023. 06. 28. 수.
// 문제 번호	: #9012 
// 문제 이름	: 괄호
// 알고리즘	: 스택의 괄호쌍
// 시간복잡도: O()

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N--)
	{
		string s;
		cin >> s;

		// (, ) 괄호가 한가지 뿐이라 , 좀 더 간단하게 풀음

		stack<char> psStack;
		bool vps = true;

		for (auto c : s)
		{
			// 여는 괄호 스택에 추가
			if (c == '(')
			{
				psStack.push(c);
			}
			// 닫는 괄호
			else // if ')'
			{
				// 스택이 비어있는 경우, 올바르지 않은 괄호쌍
				if (psStack.empty())
				{
					vps = false;
					break;
				}
				// pop
				else
				{
					psStack.pop();
				}
			}
		}

		// 모든 과정을 끝낸 후, 스택에 괄호가 남아있으면, 올바르지 않은 괄호쌍
		if (!psStack.empty())
			vps = false;

		// 결과 출력
		if (vps)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}


	}

	return 0;
}