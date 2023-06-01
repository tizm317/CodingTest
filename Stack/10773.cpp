//#include <iostream>
//#include <stack>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 24. 월
//// 문제 번호	: #10773 
//// 문제 이름	: 제로
//// 알고리즘	: 스택
//// 시간복잡도: O()
//
//int K;	
//stack<int> intStack;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> K;
//	for (int i = 0; i < K; i++)
//	{
//		int x;
//		cin >> x;
//
//		// x 가 0 일 경우 최근 값 지움 (pop)
//		if (x == 0)
//		{
//			intStack.pop();
//		}
//		else
//		{
//			intStack.push(x);
//		}
//	}
//
//	// Stack 내 모든 값 더하기
//	int sum = 0;
//	while (!intStack.empty())
//	{
//		sum += intStack.top();
//		intStack.pop();
//	}
//
//	// 결과 출력
//	cout << sum;
//
//	// int 4byte
//	// 4 * 8bit = 32bit
//	// 2^32
//	// 문제에서 합 <= 2^31 - 1 인 정수라 했으니 int 가능
//
//	return 0;
//}