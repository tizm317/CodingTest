//#include <iostream>
//
//using namespace std;
//
//void doSomething1(int N)
//{
//	if (N == 0)
//		return;
//
//	doSomething1(N - 1);
//	cout << N << '\n';
//}
//
//int doSomething2(int N)
//{
//	if (N == 1)
//		return N;
//
//	return (N + doSomething2(N - 1));
//}
//
//// a^b % m
//long long func3(long long a, long long b, long long m)
//{
//	// O(b)
//
//	long long res = 1;
//	while (b-- != 0)
//	{
//		res *= a;
//		res %= m; // <- int overflow ����
//		// 6^100 : int ���� ����
//
//		// ���� : m �� 2^32 ���� ũ��, long long ������ ���� �� ����
//		// __int128
//	}
//	//res %= m;
//
//	return res;
//}
//
//int main()
//{
//	//int n;
//	//cin >> n;
//
//	// 1 ~ N ���� ����ϴ� ��� �Լ�
//	//doSomething1(n);
//
//	// 1 ~ N ���� ���� ����ϴ� ��� �Լ�
//	//cout << doSomething2(n) << '\n';
//
//	//long long a = 6;
//	//long long b = 100;
//	//long long val = 1;
//	//long long m = 10;
//	//while (b-- != 0)
//	//{
//	//	//val *= a; // int overflow 
//	//	//val %= m;
//
//	//	val = val * a % m;
//	//}
//	//cout << val;
//
//	cout << func3(6, 100, 5);
//
//	return 0;
//}
