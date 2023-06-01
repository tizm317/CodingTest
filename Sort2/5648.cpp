//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 06. 01. 목
//// 문제 번호	: #5648
//// 문제 이름	: 역원소 정렬
//// 알고리즘	: 정렬
//// 시간복잡도: O()
//
//int N; // <= 1'000'000
//string arr[1'000'005];
//
//bool cmp(const string& a, const string& b)
//{
//	// 길이 다르면, 짧은게 앞
//	if (a.size() != b.size())
//		return a.size() < b.size();
//
//	// 같으면, 각 자릿수 비교
//	for (int i = 0; i < a.size(); i++)
//	{
//		if (a[i] != b[i])
//			return a[i] < b[i];
//	}
//
//	// 모두 같으면 false 리턴
//	return false;
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
//
//		// 원소 거꾸로 뒤집기
//		reverse(arr[i].begin(), arr[i].end());
//
//		// 0이 선행되는 경우 0 지우는 작업
//		int size = arr[i].size();
//		for (int j = 0; j < size; j++)
//		{
//			if (arr[i][j] != '0')
//			{
//				arr[i].erase(arr[i].begin(), arr[i].begin() + j);
//				break;
//			}
//		}
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