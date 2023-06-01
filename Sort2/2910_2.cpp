//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <utility> // pair
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 06. 01. 목
//// 문제 번호	: #2910 
//// 문제 이름	: 빈도 정렬
//// 알고리즘	: 정렬
//// 시간복잡도: O()
//
//int N, C; // 1'000 , 1'000'000'000
//vector<pair<int, int>> v; // {cnt, num} -> cnt로 정렬
//
//bool cmp(const pair<int, int>& a, const pair<int, int>& b)
//{
//	return a.first > b.first;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> C;
//
//	for (int i = 0; i < N; i++)
//	{
//		int x;
//		cin >> x;
//
//		// 벡터에 존재 여부 체크
//		bool isExist = false;
//		for (auto & a : v)
//		{
//			// 이미 존재
//			if (a.second == x)
//			{
//				a.first++;
//				isExist = true;
//				break;
//			}
//		}
//
//		// 존재 하지 않을 때만 추가
//		if (!isExist) v.push_back({ 1,x });
//	}
//
//	// cnt 기준 정렬, 같으면 순서 유지하기 위해 stable_sort 사용(퀵 소트는 unstable sort라 잘 못 될 수도 있음)
//	stable_sort(v.begin(), v.end(), cmp); 
//	//sort(v.begin(), v.end(), cmp); // <- 틀림! 테케에 따라서
//
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		while (v[i].first--)
//		{
//			cout << v[i].second << " ";
//		}
//	}
//
//	return 0;
//}