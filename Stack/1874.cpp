//#include <iostream>
//#include <stack>
//#include <queue>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 24. 월
//// 문제 번호	: #1874 
//// 문제 이름	: 스택 수열
//// 알고리즘	: 스택
//// 시간복잡도: O()
//
//int n;
//
//queue<int> sequence;// 수열 큐에 저장
//stack<int> S;		// 숫자 스택에 저장
//queue<char> answer; // push(+), pop(-) 연산 출력하기 위해 큐에 저장  (실패 경우 때문에 큐에 저장해두고 마지막에 출력)
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> n;
//	
//	// 결과 수열 입력
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		sequence.push(x); // 4 3 6 8 7 5 2 1
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		// 1 ~ n 까지 순서대로 스택에 push 
//		S.push(i);
//		answer.push('+');
//		//cout << '+' << '\n';
//
//		// 수열 큐 front 랑 숫자 스택 top 비교
//		while (sequence.front() == S.top())
//		{
//			// 같으면 둘다 pop (-)
//			S.pop();
//			sequence.pop();
//			answer.push('-');
//			//cout << '-' << '\n';
//
//			// 둘 중 하나 empty 일 경우 탈출
//			if (sequence.empty() || S.empty())
//				break;
//		}
//	}
//
//	// 둘 중 하나라도 empty 가 아니면, 실패
//	if (!sequence.empty() || !S.empty())
//	{
//		cout << "NO" << '\n';
//	}
//	else
//	{
//		// 성공한 경우, 큐에 저장된 순서대로 출력
//		while (!answer.empty())
//		{
//			cout << answer.front() << '\n';
//			answer.pop();
//		}
//	}
//
//	return 0;
//}