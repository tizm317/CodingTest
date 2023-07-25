//#include <iostream>
//#include <algorithm> // next_permutation
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 25. 화
//// 문제 번호	: #14899 
//// 문제 이름	: 스타트와 링크
//// 알고리즘	: 시뮬레이션, 조합(nCr, next_permutation)
//// 시간복잡도: O()
//
//int N; // <= 20, 짝수
//int chemistryArr[25][25]; // 능력치 배열
//
//int min_diff = 1000; // 미니멈 능력치 차이, 최댓값보다 좀 더 크게 초기화
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 능력치 배열 입력
//	cin >> N;
//	for (int r = 0; r < N; r++)
//		for (int c = 0; c < N; c++)
//			cin >> chemistryArr[r][c];
//
//	// nC(n/2) 조합 경우의 수
//	int idx[20] = { 0, };
//	fill(idx + N / 2, idx + N, 1); // 0 N/2 개, 1 N/2개 초기화
//
//	// 20C10 = 184'756번
//	do
//	{
//		// 스타트팀, 링크팀 능력치 총합 초기화
//		int total_point_start_team = 0;
//		int total_point_link_team = 0;
//
//		// 팀별 능력치 계산 (N/2)C2 조합
//		// N/2 명의 팀원 중에서 2명씩 짝 지어 능력치 합 계산
//		// 20 * 20번
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				// 나를 제외하고,
//				if (j == i) continue;
//
//				// 같은 팀끼리 능력치 합 계산
//				if (idx[i] != idx[j]) continue;
//
//				if (idx[i] == 0) total_point_start_team += chemistryArr[i][j];
//				if (idx[i] == 1) total_point_link_team += chemistryArr[i][j];
//			}
//		}
//
//		// 미니멈 차이
//		min_diff = std::min(min_diff, std::abs(total_point_start_team - total_point_link_team));
//
//	} while (next_permutation(idx, idx + N));
//
//	// 결과 출력
//	cout << min_diff;
//
//	return 0;
//}