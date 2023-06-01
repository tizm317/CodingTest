//////#include <iostream>
//////#include <vector>
//////using namespace std;
//////
//////// 백준 문제 풀이
//////// 날짜		: 20xx. xx. xx.
//////// 문제 번호	: #00000 
//////// 문제 이름	: 
//////// 알고리즘	: 
//////// 시간복잡도: O()
//////
//////int N, M;
//////int isUsed[9];
//////vector<int> vec;
////////
////////void func(int m)
////////{
////////	if (m == 0)
////////	{
////////		int size = vec.size();
////////		for (int i = 0; i < size; i++)
////////		{
////////			cout << vec[i] << " ";
////////		}
////////		cout << '\n';
////////		return;
////////	}
////////
////////	for (int i = 1; i <= N; i++)
////////	{
////////		if (isUsed[i] == 1)
////////			continue;
////////
////////		isUsed[i] = 1;
////////		vec.push_back(i);
////////
////////		func(m - 1);
////////
////////		isUsed[i] = 0;
////////		vec.pop_back();
////////	}
////////}
//////
//////int arr[10];
//////
//////// arr[k] 결정하는 함수
//////void func(int k)
//////{
//////	if (k == M)
//////	{
//////		// 배열 출력
//////		for (int i = 0; i < k; i++)
//////			cout << arr[i] << " ";
//////		cout << '\n';
//////		
//////		return;
//////	}
//////
//////	for (int i = 1; i <= N; i++)
//////	{
//////		// 이미 사용중이면 pass
//////		if (isUsed[i] == 1)
//////			continue;
//////
//////		isUsed[i] = 1;
//////		arr[k] = i;
//////		
//////		func(k + 1);
//////		
//////		isUsed[i] = 0;
//////		//arr[k] = -1; // 초기화 안 해도 어차피 k번째 원소 덮힘
//////	}
//////}
//////
//////int main()
//////{
//////	ios_base::sync_with_stdio(false);
//////	cin.tie(NULL);
//////
//////	cin >> N >> M;
//////	//func(M);
//////	func(0);
//////
//////	return 0;
//////}
////
////#include <iostream>
////
////using namespace std;
////
////int M, N;
////int arr[9]; // 수열 배열
////bool isused[9];	// 중복을 허용하지 않기 위함 ex : (1,1)
////
////// parameter 가 수열 갯수 상태를 의미
////void func(int cnt)
////{
////	// 수열 원소 갯수가 N인 상태일 때,
////	// 수열을 출력 후 탈출
////	if (cnt == N)
////	{
////		for (int i = 0; i < N; i++)
////			cout << arr[i] << " ";
////		cout << '\n';
////
////		return;
////	}
////
////	// 수열에 들어갈 수 1 ~ M 선택
////	for (int i = 1; i <= M; i++)
////	{
////		// 이미 사용한 경우(중복 (1,1)) pass
////		if (isused[i] == true)
////			continue;
////
////		// 사용중임을 표시
////		isused[i] = true;
////		arr[cnt] = i;
////		
////		func(cnt + 1);		// 다음 상태로 이동
////
////		// 사용 끝남을 표시
////		isused[i] = false;
////
////		// arr[cnt + 1] 초기화 할 필요 없음 -> 어차피 덮혀짐.
////	}
////
////}
////
////int main()
////{
////	cin >> M >> N;
////
////	func(0);
////
////	return 0;
////}
//
//
//// next_permuation
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int N, M;
////int num[8];
//vector<int> num;
//
//int main()
//{
//	cin >> N >> M;
//	// 4 2
//
//	for (int i = 1; i <= N; i++)
//		num.push_back(i);
//	 
//
//	do 
//	{
//		for (int i = 0; i < M; i++)
//			cout << num[i] << " ";
//		cout << '\n';
//
//		//    1 2 |3 4
//		// -> 1 2 |4 3 -> 2 1 | 3 4
//		reverse(num.begin() + M, num.end());
//	
//	} while (next_permutation(num.begin(), num.end()));
//
//	return 0;
//}