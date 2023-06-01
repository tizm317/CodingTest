//#include <iostream>
//#include <utility>
//#include <queue>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 02. 화
//// 문제 번호	: #11729 
//// 문제 이름	: 하노이탑 이동 순서
//// 알고리즘	: 재귀
//// 시간복잡도: O()
//
//int N , cnt;
//
//queue<pair<int, int>> Q;
//
//void doSomething(int n, int from, int to)
//{
//	// 원판 n 개를 from 에서 to로 이동
//
//	if (n == 1)
//	{
//		//Q.push({ from, to });
//		cout << from << " " << to << '\n';
//		//cnt++;
//		return;
//	}
//
//	// 1 ~ n-1 까지 from에서 (from, to 아닌 나머지) 로 이동
//	doSomething(n - 1, from, 6 - from - to);
//	
//	// n을 from 에서 to로 이동
//	Q.push({ from, to });
//	cout << from << " " << to << '\n';
//	
//	//cnt++;
//
//	// 1 ~ n - 1 까지 (from, to, 아닌 나머지)에서 to 로 이동
//	doSomething(n - 1, 6 - from - to, to);
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	//cout << (int)pow(2, N) - 1 << '\n'; // 2^N - 1
//	cout << (1 << N) - 1 << '\n'; // 2^N // bit연산자
//	
//	doSomething(N, 1, 3);
//
//
//	//cout << cnt << '\n';
//	//while (!Q.empty())
//	//{
//	//	cout << Q.front().first << " " << Q.front().second << '\n';
//	//	Q.pop();
//	//}
//
//	return 0;
//}