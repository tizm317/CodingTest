//#include <iostream>
//#include <queue>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2024. 04. 24. 월
//// 문제 번호	: #2164
//// 문제 이름	: 카드2
//// 알고리즘	: 큐
//// 시간복잡도: O()
//
//int N;
//queue<int> intQueue;
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	// 카드를 큐에 담음 (1~N)
//	for (int i = 1; i <= N; i++)
//	{
//		intQueue.push(i);
//	}
//
//	// 카드 하나 남을 때까지 반복
//	while (intQueue.size() != 1)
//	{
//		// 1. head 위치 카드 버림
//		intQueue.pop();
//
//		// 2. head 위치 카드를 tail 로 push 후 pop
//		intQueue.push(intQueue.front());
//		intQueue.pop();
//	}
//
//	// 마지막 하나남은 카드 출력
//	cout << intQueue.front();
//
//	return 0;
//}