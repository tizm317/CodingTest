//#include <iostream>
////#include <string>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 06. 28. 수.
//// 문제 번호	: #11656 
//// 문제 이름	: 접미사 배열
//// 알고리즘	: 정렬
//// 시간복잡도: O()
//
//string S; // 1000자 이하
//string suffixs[1005]; // 접미사 배열, 최대 1000개
//
//vector<string> suffixVec;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> S;
//
//	// 접미사 배열 만들기
//	for (int i = 0; i < S.size(); i++)
//	{
//		//suffixs[i] = S.substr(i, S.size() - i);
//		suffixVec.push_back(S.substr(i));
//	}
//
//	// 사전순 정렬
//	//sort(suffixs, suffixs + S.size());
//	sort(suffixVec.begin(), suffixVec.end());
//	
//	// 출력
//	/*for (int i = 0; i < S.size(); i++)
//	{
//		cout << suffixs[i] << '\n';
//	}*/
//	for (auto x: suffixVec)
//	{
//		cout << x << '\n';
//	}
//
//
//	return 0;
//}