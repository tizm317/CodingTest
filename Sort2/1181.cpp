//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 06. 01. 목
//// 문제 번호	: #1181 
//// 문제 이름	: 단어 정렬
//// 알고리즘	: 정렬
//// 시간복잡도: O()
//
//
//int N; // 20'000
//string arr[20'005];
//vector<string> vec;
//
//// 길이가 짧은 것부터
//// 길이가 같으면 사전 순으로
//// 단, 중복된 단어는 하나만 남기고 제거해야 한다.
//
//bool cmp(const string& a, const string& b)
//{
//	if (a.size() != b.size())
//		return a.size() < b.size();
//
//	return a < b;
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
//		string s;
//		cin >> s;
//		vec.push_back(s);
//		//cin >> arr[i];
//	}
//
//	//sort(arr, arr + N, cmp);
//	sort(vec.begin(), vec.end(), cmp);
//
//	// 중복 한번 출력
//	//cout << arr[0] << '\n';
//	//for (int i = 1; i < N; i++)
//	//{
//	//	if(arr[i] != arr[i-1])
//	//		cout << arr[i] << '\n';
//	//}
//
//	// 1 1 2 3 3 4 5 5 5 6 -> 1 2 3 4 5 6 '5 5 5 6'
//	// unique 함수가 중복 지워줌
//	// 하지만 뒷부분(5 5 5 6) 이 남기 때문에 지워줘야 함
//	// unique 함수 리턴값이 지우고 난 벡터의 end() iterator
//	vec.erase(unique(vec.begin(), vec.end()), vec.end());
//
//	for (auto x : vec)
//	{
//		cout << x << '\n';
//	}
//
//	return 0;
//}