//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 06. 27. 화.
//// 문제 번호	: #10807
//// 문제 이름	: 개수 세기
//// 알고리즘	: 배열
//// 시간복잡도: O()
//
//int N, v;
//int num[205]; 
//// -100 ~ 100
//// + 100
//// 0 ~ 200
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	
//	for(int i = 0; i < N; i++)
//	{
//		int x;
//		cin >> x;
//		num[x + 100]++;
//	}
//	
//	cin >> v;
//	cout << num[v + 100];
//
//	return 0;
//}