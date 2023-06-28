//#include <iostream>
//#include <algorithm>	
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
//class student
//{
//public:
//	string name;
//	int korean;
//	int english;
//	int math;
//};
//
//student students[100'005];
//
//bool compare(student& a, student& b)
//{
//	// 국어 감소순 -> 영어 증가순 -> 수학 감소순 -> 이름 사전순
//	return (a.korean != b.korean) ? (a.korean > b.korean)
//		: a.english != b.english ? (a.english < b.english)
//		: a.math != b.math ? (a.math > b.math)
//		: a.name < b.name;
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
//		cin >> students[i].name >> students[i].korean >> students[i].english >> students[i].math;
//	}
//
//	sort(students, students + N, compare);
//
//	for (int i = 0; i < N; i++)
//	{
//		cout << students[i].name << '\n';
//	}
//
//	return 0;
//}