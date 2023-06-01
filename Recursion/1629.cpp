////#include <iostream>
////using namespace std;
////
////// ���� ���� Ǯ��
////// ��¥		: 2023. 05. 02. ȭ
////// ���� ��ȣ	: #1629 
////// ���� �̸�	: ����
////// �˰���	: ���
////// �ð����⵵: O(log b) : b�� ���ݾ� �پ��� ����
////
////
////// Ʋ���� ���
////// int overflow / pow �Լ� ������ pow �Լ� �ι� ȣ��� O(log b) / base ����� ���԰ų�..
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
////		// �ݷ� : 2147483645 3 2147483647
////		// temp * temp �� �� ������ �Ѿ �� �ֱ� ������ %c ���ְ� �ٽ� ������� ��
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
//// �ͳ���
//// 1. a�� 1���� ���� �� �ִ�. 
//// a^1 = a
//// 2. a�� k���� ���� �� ������ �����ϸ�, a�� 2k��, 2k+1�� ���� �� ������ ������.
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
//	//return (func(a, b / 2, c) * func(a, b - b / 2, c)) % c; // O(b) -> �ð��ʰ�
//
//	ll res = func(a, b / 2, c); // O(logb)
//	res = res * res % c;
//	if (b % 2 != 0) // b�� Ȧ����
//		res = res * a % c;
//
//	return res;
//
//	// �ѹ��� ȣ���ؾ� ��.
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