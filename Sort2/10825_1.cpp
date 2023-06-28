//#include <iostream>
//#include <algorithm>	
//#include <tuple>
//#include <vector>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 06. 28. 수.
//// 문제 번호	: #10825 
//// 문제 이름	: 국영수
//// 알고리즘	: 배열
//// 시간복잡도: O()
//
//// 정렬 기준
//// 국어 -> 영어 -> 수학 -> 이름
//// 감소 -> 증가 -> 감소 -> 사전
//
//int N; // 100'000
//
//vector<tuple<int, int, int, string>> students;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	while (N--)
//	{
//		string name;
//		int k, e, m; // 국영수
//		cin >> name >> k >> e >> m;
//
//		// 국어, 수학 감소순 -> 음수로 바꾸면 됨**
//		// ex) 50, 80 -> -80, -50 순으로 바뀌게 됨
//		students.push_back({ -k,e,-m,name });
//	}
//
//	sort(students.begin(), students.end());
//
//	for (auto x : students)
//	{
//		// 이름만 출력
//		cout << get<3>(x) << '\n';
//	}
//
//	return 0;
//}