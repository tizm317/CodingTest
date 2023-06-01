//#include <iostream>
//
//using namespace std;
//
//const int absSize = 1'000'000; // 절댓값 크기
//int N;
//int freq[absSize * 2 + 5]; // -1'000'000 ~ 1'000'000
//// + 1'000'000
//// 0 ~ 2'000'000
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 카운팅 소트
//	// O(N+K)
//
//	cin >> N;
//
//	// O(N)
//	for (int i = 0; i < N; i++)
//	{
//		int x;
//		cin >> x;
//
//		// -1'000'000 ~ 1'000'000 범위 조정
//		freq[x + absSize]++;
//	}
//
//	// O(K)
//	// freq 배열 순회하면서, 값만큼 출력
//	for (int i = 0; i <= 2 * absSize; i++)
//	{
//		while (freq[i]--)
//		{
//			// 범위 조정
//			cout << i - absSize << '\n';
//			//freq[i]--;
//		}
//	}
//
//	return 0;
//}