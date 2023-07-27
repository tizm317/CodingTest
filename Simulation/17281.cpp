//#include <iostream>
//#include <queue>
//#include <utility>
//#include <algorithm> // next_permutation
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 27. 목
//// 문제 번호	: #17281 
//// 문제 이름	: 야구
//// 알고리즘	: 시뮬레이션, 순열
//// 시간복잡도: O()
//
//int N; // 이닝 수 <= 50
//
//int players[55][10]; // 1~9 타자
//
//pair<int, bool>* base[4]; // 0루, 1루, 2루, 3루
//// 포인터 사용함
//
//int maxScore;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 일단 큐 순서 정하기
//	// 1번은 무조건 4번째 타자
//		// 모든 경우의 수 넣고, 1번이 4번째가 아닌거 제외하는 방식?
//
//	// 이닝별 player 타석 결과 입력
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		for (int p = 1; p <= 9; p++)
//		{
//			cin >> players[i][p];
//		}
//	}
//
//	// 순열
//	int idx[9] = { 1,2,3,4,5,6,7,8,9 };
//	do
//	{
//		// 1. 타자 순서 정하기
//		queue<pair<int, bool>> playerIdxQ;
//
//		// (타자1 4번째 타자 고정) 타자 1이 4번째 타자가 아니면 X
//		if (idx[3] != 1)
//			continue;
//
//		for (auto x : idx)
//			playerIdxQ.push({ x, false });
//
//		// 2. 정해진 순서대로 이닝 진행 시 score 계산
//		int score = 0;
//		for(int inning = 0; inning < N; inning++)
//		{
//			// 아웃 카운트 초기화
//			int outCnt = 0;
//
//			// 아웃 카운트 3 되면 이닝 종료
//			while (outCnt < 3)
//			{
//				// 현재 타자
//				pair<int, bool>& curHitter = playerIdxQ.front();
//
//				// 빼서 뒤로 보냄
//				playerIdxQ.pop(); playerIdxQ.push(curHitter);
//
//				// 이미 base에 나가 있는 경우 pass
//				if (curHitter.second)
//					continue;
//
//				// 타자
//				base[0] = &curHitter;
//				curHitter.second = true;
//
//				// 아웃
//				if (players[inning][curHitter.first] == 0)
//				{
//					// 아웃 카운트 증가
//					outCnt++;
//
//					// 타석에서 빼버리고, false
//					base[0] = nullptr;
//					curHitter.second = false;
//					continue;
//				}
//
//				// 아웃 아닌 경우, 결과에 따라 베이스 진출
//				for (int baseIdx = 3; baseIdx >= 0; baseIdx--)
//				{
//					// 해당 base 선수 추출
//					pair<int, bool>* runningPlayerPtr = base[baseIdx];
//
//					// 해당 base 에 선수 없는 경우 pass
//					if (runningPlayerPtr == nullptr)
//						continue;
//
//					// 이동할 다음 base idx 계산
//					const int nxtBaseIdx = baseIdx + players[inning][curHitter.first];
//
//					// 현재 베이스 위치에서 제거
//					base[baseIdx] = nullptr;
//
//					// 홈에 들어온 경우
//					if (nxtBaseIdx >= 4)
//					{
//						// 점수 증가
//						score++;
//
//						// 베이스에 나갔는지 여부 false 로 수정
//						runningPlayerPtr->second = false;
//					}
//					else
//					{
//						// 다음 위치로 이동
//						base[nxtBaseIdx] = runningPlayerPtr;
//					}
//				}
//			}
//
//			// 이닝 끝날 때 초기화 !!!!!!!!!!!!!!!!
//				// base 에 주자 없어야 함 (베이스 초기화)
//				// 나가 있다고 되어있는 player 들 false 로 초기화 (플레이어 진출 여부 초기화)
//			for (int i = 0; i < 4; i++)
//			{
//				pair<int, bool>* playerInBasePtr = base[i];
//				if (playerInBasePtr == nullptr)
//					continue;
//
//				// 나가 있는 player 들어오게 false 설정
//				playerInBasePtr->second = false;
//
//				// 베이스 비워주기
//				base[i] = nullptr;
//			}
//		}
//
//		// 최대 점수
//		maxScore = max(maxScore, score);
//
//		// 오래 걸리는 특이 케이스 -> 빼도 시간초과 X
//		//if (maxScore == 24 * N) // 4 * 8 * N
//		//{
//		//	cout << maxScore;
//		//	return 0;
//		//}
//
//	} while (next_permutation(idx, idx + 9));
//
//	// 최대점수 출력
//	cout << maxScore;
//
//	return 0;
//}