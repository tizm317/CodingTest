//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 15. 월
//// 문제 번호	: #15651, #15652
//// 문제 이름	: N과 M 3,4
//// 알고리즘	: 
//// 시간복잡도: O()
//
//int N, M;
//int arr[9];
//
//void func(int cnt)
//{
//	if (cnt == M)
//	{
//		for (int i = 0; i < M; i++)
//			cout << arr[i] << " ";
//		cout << '\n';
//
//		return;
//	}
//
//	// 15651. N과 M 3 - 중복 허용 -> isused 배열 필요 X
//	// 15652. N과 M 4 - 비내림차순 조건 추가
//	int start = 1;
//	if (cnt != 0) start = arr[cnt - 1];
//
//	for (int i = start; i <= N; i++)
//	{
//		arr[cnt] = i;
//
//		func(cnt + 1);
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//
//	func(0);
//
//	return 0;
//}