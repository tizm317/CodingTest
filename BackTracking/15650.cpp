////#include <iostream>
////using namespace std;
////
////// 백준 문제 풀이
////// 날짜		: 2023. 05. 15. 월
////// 문제 번호	: #15650
////// 문제 이름	: N과 M 2
////// 알고리즘	: 
////// 시간복잡도: O()
////
////int N, M;
////int arr[9];
////bool isused[9];
////
////void func(int cnt)
////{
////	if (cnt == M)
////	{
////		for (int i = 0; i < M; i++)
////			cout << arr[i] << " ";
////		cout << '\n';
////
////		return;
////	}
////
////	// 시작점 설정
////	//int start = 1; // cnt = 0이면 1부터
////	//if (cnt != 0) start = arr[cnt - 1] + 1; // 아니면 arr 다음 원소
////
////	//for (int i = start; i <= N; i++)
////	for (int i = 1; i <= N; i++)
////	{
////		if (isused[i] == 1)
////			continue;
////
////		// 오름차순 X
////		if (cnt > 0 && arr[cnt - 1] > i)
////			continue;
////
////		isused[i] = 1;
////		arr[cnt] = i;
////		
////		func(cnt + 1);
////
////		isused[i] = 0;
////	}
////}
////
////int main()
////{
////	ios_base::sync_with_stdio(false);
////	cin.tie(NULL);
////
////	cin >> N >> M;
////
////	func(0);
////
////	return 0;
////}
//
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int N, M;
//vector<int> num;
//
//int main()
//{
//	cin >> N >> M;
//	// 4 2
//
//	// 0 1 2 3
//	for (int i = 0; i < N; i++)
//	{
//		num.push_back(i < M ? 0 : 1); // 0 0 1 1
//	}
//
//	// 조합을 이용해서 1 2 먼저 출력되고 나서, 2 1 안나옴 (증가순인것만 출력됨)
//
//	do
//	{
//		for (int i = 0; i < N; i++)
//		{
//			if (num[i] == 0)
//				cout << i + 1 << " ";
//		}
//		cout << '\n';
//
//	} while (next_permutation(num.begin(), num.end()));
//
//	return 0;
//}