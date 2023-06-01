////#include <iostream>
////using namespace std;
////
////// 백준 문제 풀이
////// 날짜		: 2023. 05. 02. 화
////// 문제 번호	: #1629 
////// 문제 이름	: 곱셈
////// 알고리즘	: 재귀
////// 시간복잡도: O(log b) : b가 절반씩 줄어들기 때문
////
////
////// 틀리는 경우
////// int overflow / pow 함수 내에서 pow 함수 두번 호출시 O(log b) / base 컨디션 빼먹거나..
////
////int pow(long long a, long long b, long long c)
////{
////	if (b == 1)
////		return a % c;
////
////
////	// 12^58 * 12^58 = 12^116
////	// 12^58 * 12^58 * 12 = 12^117
////
////	// a^n * a^n = a^2n
////	// a^n * a^n * a = a^(2n+1)
////
////	long long temp = pow(a, b / 2, c);
////	if (b % 2 == 0)
////	{
////		return temp * temp % c;
////	}
////	else
////	{
////		// 반례 : 2147483645 3 2147483647
////		// temp * temp 할 때 범위를 넘어갈 수 있기 때문에 %c 해주고 다시 곱해줘야 함
////		return (((temp * temp) % c) * (a % c)) % c;
////	}
////	
////}
////
////// 2147483647 
////
////int main()
////{
////	ios_base::sync_with_stdio(false);
////	cin.tie(NULL);
////
////	long long  A, B, C;
////	cin >> A >> B >> C;
////	cout << pow(A, B, C);
////
////	return 0;
////}
//
////
//#include <iostream>
//
//using namespace std;
//
//int A, B, C;
//
//// 귀납적
//// 1. a의 1승을 구할 수 있다. 
//// a^1 = a
//// 2. a의 k승을 구할 수 있음을 가정하면, a의 2k승, 2k+1승 구할 수 있음을 보여라.
//// a^k -> a^k * a^k = a^2k , a^2k * a = a^2k+1
//
//// a^n * a^n = a^2n
//// 12^116 % 67 = (12^58 % 67)^2 % 67
//
//using ll = long long;
//
//ll func(ll a, ll b, ll c)
//{
//	if (b == 1)
//		return a % c;
//
//	// a^b = a^(b/2) * a^(b-b/2)
//	//return (func(a, b / 2, c) * func(a, b - b / 2, c)) % c; // O(b) -> 시간초과
//
//	ll res = func(a, b / 2, c); // O(logb)
//	res = res * res % c;
//	if (b % 2 != 0) // b가 홀수면
//		res = res * a % c;
//
//	return res;
//
//	// 한번만 호출해야 함.
//}
//
//int main()
//{
//	cin >> A >> B >> C;
//
//	cout << func(A, B, C);
//
//	return 0;
//}