//#include <iostream>
//#include <algorithm>
//#include <tuple>
//#include <vector>
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
//int num[1'005];		
//int freq[1'005];
//
//// {수, 등장횟수, 등장순서}
//vector<tuple<int, int, int>> v;
//
//bool cmp(const tuple<int, int, int>& a, const tuple<int, int, int>& b)
//{
//	//if(get<0>(a) == get<0>(b))
//
//
//	if (get<1>(a) == get<1>(b))
//		return get<2>(a) < get<2>(b);
//
//	return get<1>(a) > get<1>(b);
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
//		v.push_back({ x, 0, i });
//	}
//
//	// x 크기순 정렬
//	// 2 1 2 1 2
//	sort(v.begin(), v.end());
//	// 1 1 2 2 2
//
//	for (int i = 0; i < N;)
//	{
//		int j;
//		for (j = i + 1; j < N; j++)
//		{
//			if (get<0>(v[i]) != get<0>(v[j]))
//			{
//				// j - i개
//				// i 부터 j 전까지
//				for (int k = i; k < j; k++)
//					get<1>(v[k]) = (j - i);
//
//				i = j;
//				break;
//			}
//			else
//			{
//				// 등장 순서를 맨 첫번째거(최초 등장 순서)로 통일시킴
//				get<2>(v[j]) = get<2>(v[i]);
//			}
//		}
//
//		if (j == N)
//		{
//			for (int k = i; k < j; k++)
//				get<1>(v[k]) = (j - i);
//
//			i = j;
//		}
//	}
//
//	sort(v.begin(), v.end(), cmp);
//
//
//	for (int i = 0; i < N; i++)
//	{
//		cout << get<0>(v[i]) << " ";
//	}
//
//	return 0;
//}