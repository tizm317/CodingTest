//#include <iostream>
//#include <algorithm> // next_permutation
//#include <vector>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 20223. 07. 25. 화
//// 문제 번호	: #14888 
//// 문제 이름	: 연산자 끼워넣기
//// 알고리즘	: 시뮬레이션, 순열(중복순열?)
//// 시간복잡도: O()
//
//int N; // <= 11
//int minValue = 1'000'000'000, maxValue = -1'000'000'000; // 최대, 최소 +- 10억
//int num[15];
//
//// +, -, *, /
//// 0, 1, 2, 3
////int operators[10];
//vector<int> operators;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 피연산자 (수) 입력
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		cin >> num[i];
//
//	// 연산자 입력
//	// +, -, *, / 순서
//		// opCnt 입력 받아서, opCnt 만큼 operators 벡터에 넣어줌
//	for (int i = 0; i < 4; i++)
//	{
//		int opCnt;
//		cin >> opCnt;
//
//		while (opCnt--)
//		{
//			operators.push_back(i);
//		}
//	}
//
//	// nPr 순열 경우의 수
//	int idx[10] = { 0, };
//	for (int i = 0; i < N - 1; i++)
//		idx[i] = i;
//	do
//	{
//		// 식 계산
//		int res = num[0];
//		for (int i = 1; i < N; i++)
//		{
//			// 연산자에 따라 계산
//			switch (operators[idx[i - 1]])
//			{
//			case 0: // +
//				res += num[i];
//				break;
//			case 1: // -
//				res -= num[i];
//				break;
//			case 2: // *
//				res *= num[i];
//				break;
//			case 3: // /
//				res /= num[i];
//				break;
//			}
//		}
//
//		minValue = std::min(minValue, res);
//		maxValue = std::max(maxValue, res);
//
//	} while (next_permutation(idx, idx + N - 1));
//
//	cout << maxValue << '\n' << minValue;
//
//	return 0;
//}