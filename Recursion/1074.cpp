//#include <iostream>
//#include <cmath> // pow
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 02. 화
//// 문제 번호	: #1074 
//// 문제 이름	: Z
//// 알고리즘	: 
//// 시간복잡도: O()
//
//int N, R, C;
//
//// 2^15, 2^15
////int arr[10000][10000];
//
//int doSomething(int n, int r, int c)
//{
//	// (n : 1일때) 2 x 2 행렬
//	// 0 1
//	// 2 3
//	if (n == 1)
//	{
//		return r * 2 + c;
//	}
//
//	// (r/x) , (c/x)
//	//   0 1 2 3 ->	  0 0 1 1 
//	// 0		 -> 0
//	// 1		 ->	0
//	// 2		 -> 1
//	// 3		 -> 1
//
//	// k : n -1 성립하면, k : n 성립
//
//	// 2^n-1 행렬 사이즈
//	const int size = (int)pow(2, n - 1);
//
//	// n-1일 때 값 + (n-1일 때 사이즈 * 몇번째) = n일 때 값
//	return doSomething(n - 1, r % size, c % size) + (size * size * ((r / size) * 2 + (c / size)));
//
//	// 1. 직접 넣는 방식 -> 범위가 너무 커서 안됨..
//	/*if (n == 1)
//	{
//		for (int r = 0; r < 2; r++)
//		{
//			for (int c = 0; c < 2; c++)
//			{
//				arr[r][c] = r * 2 + c;
//			}
//		}
//		return;
//	}
//
//	doSomething(n - 1);
//
//	int size = (int)pow(2, n - 1);
//
//	for (int r = 0; r < size; r++)
//	{
//		for (int c = 0; c < size; c++)
//		{
//			arr[r][c + size] = arr[r][c] + size * size;
//			arr[r + size][c] = arr[r][c] + size * size * 2;
//			arr[r + size][c + size] = arr[r][c] + size * size * 3;  
//		}
//	}*/
//
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> R >> C;
//	cout << doSomething(N, R, C);
//
//	//cout << arr[R][C];
//
//	return 0;
//}