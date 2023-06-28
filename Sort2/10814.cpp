//#include <iostream>
//#include <utility> // pair
//#include <algorithm> // sort
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 06. 28. 수
//// 문제 번호	: #10814 
//// 문제 이름	: 나이순 정렬
//// 알고리즘	: 정렬
//// 시간복잡도: O()
//
//int N;
//pair<int, string> boj[100'005];
//
//bool compare(pair<int, string> a, pair<int, string> b)
//{
//	// 나이로만 비교하면, 자연스럽게 가입순은 유지 (stable_sort 일 때만)
//	return a.first < b.first;
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
//		cin >> boj[i].first >> boj[i].second;
//	}
//
//	// 나이순 -> 가입순
//	stable_sort(boj, boj + N, compare); // 그냥 sort는 stable_sort 가 아님;;
//
//
//	for (int i = 0; i < N; i++)
//	{
//		cout << boj[i].first << " " << boj[i].second << '\n';
//	}
//
//	return 0;
//}