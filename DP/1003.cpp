//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 22. 월
//// 문제 번호	: #1003 
//// 문제 이름	: 피보나치 함수
//// 알고리즘	: 
//// 시간복잡도: O()
//
//int zero[40];
//int one[40];
//
//void fibo(int n)
//{
//	zero[0] = 1;
//	one[1] = 1;
//	
//	for (int i = 2; i <= n; i++)
//	{
//		zero[i] = zero[i - 2] + zero[i - 1];
//		one[i] = one[i - 2] + one[i - 1];
//	}
//
//	cout << zero[n] << " " << one[n] << '\n';
//}
//
//int T;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		int x;
//		cin >> x;
//		fibo(x);
//		//cout << fibo(x) << '\n';
//	}
//
//	return 0;
//}