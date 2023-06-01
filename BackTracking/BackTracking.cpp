//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	// 1. 순열
//
//	int a[3] = { 1,2,3 };
//	do
//	{
//		for (int i = 0; i < 3; i++)
//			cout << a[i];
//		cout << '\n';
//	} while (next_permutation(a, a + 3));
//
//	cout << '\n';
//	
//	// 중복 포함된 수열
//	int b[3] = { 1,1,3 };
//	do
//	{
//		for (int i = 0; i < 3; i++)
//			cout << b[i];
//		cout << '\n';
//	} while (next_permutation(b, b + 3));
//	cout << '\n';
//
//	// 2. 조합
//	int c[4] = { 0,0,1,1 }; // 4개중 2개 뽑기
//	do
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			if(c[i] == 1)
//				cout << i+1;
//		}
//		cout << '\n';
//	} while (next_permutation(c, c + 4));
//	// 0,1 을 배치를 다르게 함
//	// 1 1 0 0
//	// 1 0 1 0
//	// 1 0 0 1
//	// 0 1 1 0
//	// 0 1 0 1
//	// 0 0 1 1
//
//	return 0;
//}
