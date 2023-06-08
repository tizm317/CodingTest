#include <iostream>
#include <algorithm>
using namespace std;

// 백준 문제 풀이
// 날짜		: 2023. 06. 08. 목
// 문제 번호	: #11055
// 문제 이름	: 가장 큰 증가하는 부분 수열
// 알고리즘	: DP
// 시간복잡도: O()

int N;
int A[1'005]; // 수열 A
int D[1'005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	// D[i] : (증가 수열) D[i+1] + A[i]
	// (증가 하지 않는 수열 -> i, i+1번째 원소들 끊기는 경우, i를 택할지, D[i+1]을 택할지 선택) , MAX(A[i], D[i+1])  
	//  
	// 초기화
	//D[N - 1] = A[N - 1]; // N >= 1 보장


	//for (int i = N - 2; i >= 0; i--)
	//{
	//	// 증가하는 수열
	//	if (A[i] < A[i + 1])
	//		D[i] = A[i] + D[i + 1];
	//	else // 증가하지 않는 수열(같거나 작음)
	//		D[i] = max(A[i], D[i + 1]);
	//}


	// 반례) 3 1 4
	// 뒤에서부터하면
	//       5 5 4
	// 앞에서부터하면
	//       3 3 7
	// --------------------------------
	
	// 초기화
	//D[N - 1] = A[N - 1]; // N >= 1 보장됨

	//// 뒤에서 앞으로 순회
	//for (int i = N - 2; i >= 0; i--)
	//{
	//	// 증가수열되는 위치 찾기
	//	int j = i + 1;
	//	while (j < N)
	//	{
	//		if (A[i] < A[j])
	//		{
	//			D[j] += A[i];
	//		}
	//		j++;
	//	}
	//	// j == N 이면 찾지 못한 경우

	//	//if (j == N)
	//	D[i] = A[i];
	//	/*else
	//		D[i] = D[j] + A[i];*/
	//}


	//cout << *max_element(D, D + N);

	//


	return 0;
}