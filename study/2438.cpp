//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 04. 17. 월
//// 문제 번호	: #2438 
//// 문제 이름	: 별 찍기 - 1 ~ 9
//// 알고리즘	: 반복문
//// 시간복잡도: O(N^2)
//
//int N;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	// 1. row 행에 row 개수만큼 '*' 출력
//	for (int row = 1; row <= N; ++row)
//	{
//		for (int col = 1; col <= row; ++col)
//		{
//			cout << '*';
//		}
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 2. 오른쪽 정렬
//	for (int row = 1; row <= N; ++row)
//	{
//		// " " 출력
//		for (int col = 1; col <= N - row; ++col)
//		{
//			cout << " ";
//		}
//
//		// '*' 출력
//		for (int col = 1; col <= row; ++col)
//		{
//			cout << '*';
//		}
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 3. 역삼각형
//	for (int row = 1; row <= N; ++row)
//	{
//		for (int col = 1; col <= N - row + 1; ++col)
//		{
//			cout << '*';
//		}
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 4. 역삼각형 + 우측 정렬
//	for (int row = 1; row <= N; ++row)
//	{
//		// 공백 출력
//		for (int col = 1; col <= row - 1; ++col)
//		{
//			cout << " ";
//		}
//
//		// * 출력
//		for (int col = 1; col <= N - row + 1; ++col)
//		{
//			cout << '*';
//		}
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 5. 1 3 5 7 9
//	for (int row = 1; row <= N; ++row)
//	{
//		// 공백 출력
//		for (int col = 1; col <= N - 1 / 2 - row; ++col)
//		{
//			cout << " ";
//		}
//
//		// * 출력
//		for (int col = 1; col <= 2 * row - 1; ++col)
//		{
//			cout << '*';
//		}
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 6. 5 역피라미드
//	for (int row = 1; row <= N; ++row)
//	{
//		// 공백 출력
//		for (int col = 1; col <= row - 1; ++col)
//		{
//			cout << " ";
//		}
//
//		// * 출력
//		for (int col = 1; col <= 2 * (N - row) + 1; ++col)
//		{
//			cout << '*';
//		}
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 7. 5번 + 6번
//	for (int row = 1; row <= 2 * N - 1; ++row)
//	{
//		if (row < 5)
//		{
//			// 공백 출력
//			for (int col = 1; col <= N - 1 / 2 - row; ++col)
//			{
//				cout << " ";
//			}
//
//			// * 출력
//			for (int col = 1; col <= 2 * row - 1; ++col)
//			{
//				cout << '*';
//			}
//		}
//		else
//		{
//			// 공백 출력
//			for (int col = 1; col <= (row - 4) - 1; ++col)
//			{
//				cout << " ";
//			}
//
//			// * 출력
//			for (int col = 1; col <= 2 * (N - (row - 4)) + 1; ++col)
//			{
//				cout << '*';
//			}
//		}
//
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 8. 
//	for (int row = 1; row <= 2 * N - 1; ++row)
//	{
//		// 파트 1
//		if (row < N)
//		{
//			for (int col = 1; col <= row; ++col)
//			{
//				cout << '*';
//			}
//
//			// 파트 2
//			for (int col = 1; col <= 2 * (N - row); ++col)
//			{
//				cout << " ";
//			}
//
//			// 파트 3
//			for (int col = 1; col <= row; ++col)
//			{
//				cout << '*';
//			}
//		}
//		else
//		{
//			// 5 6 7 8 9
//			// 5 4 3 2 1
//			for (int col = 1; col <=  2 * N - row; ++col)
//			{
//				cout << '*';
//			}
//			
//			// 파트 2
//			for (int col = 1; col <= 2 * (row - N); ++col)
//			{
//				cout << " ";
//			}
//
//			// 파트 3
//			for (int col = 1; col <= 2 * N - row; ++col)
//			{
//				cout << '*';
//			}
//		}
//
//		cout << '\n';
//	}
//
//	cout << '\n';
//	// 9. 8번 반대
//	for (int row = 1; row <= 2 * N - 1; ++row)
//	{
//		if (row <= N)
//		{
//			// 공백 출력
//			for (int col = 1; col <= row - 1; ++col)
//			{
//				cout << " ";
//			}
//
//			// * 출력
//			for (int col = 1; col <= 2 * (N - row) + 1; ++col)
//			{
//				cout << '*';
//			}
//		}
//		else
//		{
//			// 공백 출력
//			for (int col = 1; col <= N - 1 / 2 - (row - N + 1); ++col)
//			{
//				cout << " ";
//			}
//
//			// * 출력
//			for (int col = 1; col <= 2 * (row - N + 1) - 1; ++col)
//			{
//				cout << '*';
//			}
//		}
//
//		cout << '\n';
//	}
//
//
//	return 0;
//}