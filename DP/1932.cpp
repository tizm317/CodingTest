//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 23. 화.
//// 문제 번호	: #1932
//// 문제 이름	: 정수 삼각형
//// 알고리즘	: DP
//// 시간복잡도: O()
//
//int N;
//int arr[500];
//int D[500];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	// k번째 줄
//	for (int k = 1; k <= N; k++)
//	{
//		// 배열 크기 하나씩 커짐
//		// 맨앞, 맨 뒤는 그대로 내려오고,
//		// 중간 원소들은 max(i-1, i) 로 채워짐
//		for (int m = k - 1; m > 0; m--)
//		{
//			D[m] = max(D[m - 1], D[m]);
//		}
//
//		for (int j = 0; j < k; j++)
//		{
//			cin >> arr[j];
//			D[j] += arr[j];
//		}
//	}
//
//	cout << *max_element(D, D + N);
//
//	return 0;
//}