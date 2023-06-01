//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 06. 01. 목
//// 문제 번호	: #1431
//// 문제 이름	: 시리얼 번호
//// 알고리즘	: 정렬
//// 시간복잡도: O()
//
//int N;			// <= 50
//string arr[55];
//
//bool cmp(const string& a, const string& b)
//{
//	// A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
//	if (a.size() != b.size())
//	{
//		return a.size() < b.size();
//	}
//	// 만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
//	else
//	{
//		int aSum = 0, bSum = 0;
//		for (int i = 0; i < a.size(); i++)
//		{
//			if (a[i] >= '0' && a[i] <= '9')
//				aSum += (a[i] - '0');
//
//			if (b[i] >= '0' && b[i] <= '9')
//				bSum += (b[i] - '0');
//		}
//
//		if(aSum != bSum)
//			return aSum < bSum;
//		// 만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
//		else
//			return a < b;
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> arr[i];
//	}
//
//	sort(arr, arr + N, cmp);
//
//	for (int i = 0; i < N; i++)
//	{
//		cout << arr[i] << '\n';
//	}
//
//	return 0;
//}