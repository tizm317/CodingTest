//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 20xx. xx. xx.
//// 문제 번호	: #3273 
//// 문제 이름	: 두 수의 합
//// 알고리즘	: 배열
//// 시간복잡도: O(N)
//
//int n, x;
//int num[2'000'005]; // 숫자 출연 빈도
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 수열의 크기 n 입력
//	cin >> n;
//
//	// 수열 담는 배열 동적 할당 후 입력 받음
//	int* arr = new int[n] {0, };
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//
//		// 숫자 출연 빈도 계산
//		num[arr[i]]++;
//	}
//	
//	// 두 수의 합 결과물 입력
//	cin >> x;
//
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		// arr[i]의 대응하는 숫자 계산
//		int correspondNum = x - arr[i];
//
//		// 숫자가 0보다 작으면 안 됨.
//		if (correspondNum < 0)
//			continue;
//
//		// 존재하면 count 증가
//		if (num[correspondNum] == 1)
//			count++;
//	}
//
//	// 대응되는 숫자 전체 개수 / 2 = 대응 쌍의 개수
//	cout << count / 2 << '\n';
//
//	return 0;
//}