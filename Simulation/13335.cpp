//#include <iostream>
//#include <queue>
//#include <utility>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 20. 목
//// 문제 번호	: #13335 
//// 문제 이름	: 트럭
//// 알고리즘	: 시뮬레이션, 큐
//// 시간복잡도: O()
//
//int N; // 트럭 수 1 <= <= 1000
//int W; // 다리 길이 1 <= <= 100
//int L; // 다리 최대하중 10 <= <= 1000
//
//// 다리 위에 있는 트럭을 담는 큐와 다리에 진입하기 전 트럭을 담는 큐, 총 2개의 큐를 활용함
//queue<int> truckQ; // 트럭 무게 큐 (1<= 무게 <= 10)
//queue<pair<int,int>> bridgeQ; // 다리 위 (트럭 무게, 진입 시각)
//
//#define WEIGHT first
//#define ENTER_TICK second
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 트럭 수, 다리 길이, 최대 하중 입력
//	cin >> N >> W >> L;
//
//	// 트럭 무게 입력
//	for (int i = 0; i < N; i++)
//	{
//		int x;
//		cin >> x;
//
//		truckQ.push(x);
//	}
//
//	// 시간 체크용 변수 tick
//	int tick = 0;
//
//	// 다리 진입 직전 트럭의 무게 담는 변수
//	//int waitingTruckWeight = 0;
//
//	// 현재 다리 위 무게 합 변수
//	int totalWeights = 0;
//	
//	// <<<<< if 에서 예외 처리를 좀 더 깔끔하게 할 수는 없을까?? >>>>>
//	// truckQ, bridgeQ, waitingTruckWeight 모두 트럭 없을 때에 종료되기 때문에,
//	// 하나라도 남아 있다면, while loop 를 돌아야 함.
//	// 그래서 깔끔하게 정리가 안되는데..
//		// waitingTruckWeight 를 안 쓰고 해결할 수 있을까?
//			// 내가 사용한 이유는?
//				// 다리에 바로 못 들어가고, 다리 위에 트럭이 먼저 나간 다음에 진입하기 위한 경우 때문.
//					// front() 로 바로 비교하고, 가능한 경우에만 pop 해버리면 될듯?!
//						// waitingTruckWeight 빼면 좀 더 단순해질 듯함
//
//	// 0. 다리 전, 다리 위 트럭 모두 없을 경우 break
//	while (!truckQ.empty() || !bridgeQ.empty())
//	{
//		// 1. 시간 증가
//		tick++;
//
//		// 2. 다리 위에 트럭이 있는 경우 체크
//		// bridgeQ.front 의 진입 시각 - 현재 시각 계산 후, W 이상이면 다리 지나감
//		if (!bridgeQ.empty() && (tick - bridgeQ.front().ENTER_TICK) >= W)
//		{
//			// 다리 위 무게 합 에서 나가는 트럭 무게 빼주고, pop
//			totalWeights -= bridgeQ.front().WEIGHT;
//			bridgeQ.pop();
//		}
//
//		// truckQ 에 트럭 남아 있는 지 체크
//		if (truckQ.empty())
//			continue;
//
//		// 3. 다리 진입 가능 체크 및 진입
//		// (다리 위 무게 + 기다리는 트럭 무게) 가 L 보다 작은 경우
//		//if(!truckQ.empty() && totalWeights + truckQ.front() <= L)
//		if(totalWeights + truckQ.front() <= L)
//		{
//			// 다리로 진입 (bridgeQ에 push, 무게 더하기)
//			bridgeQ.push({ truckQ.front(), tick}); // (무게, 들어간 시점)
//			totalWeights += truckQ.front();
//
//			// 기다리는 트럭에서 빼줌
//			truckQ.pop();
//		}
//	}
//
//	// 최소 시간 출력
//	cout << tick;
//
//	return 0;
//}
//
//
//// waitingTruckWeight 사용 버전
///*
//while(true)
//	{
//		// 0. 다리 전, 다리 위, 다리 진입 직전 대기 중인 트럭 모두 없을 경우 break
//		if (truckQ.empty() && bridgeQ.empty() && waitingTruckWeight == 0)
//			break;
//
//		// 1. 시간 증가
//		tick++;
//
//		// 2. 다리 위에 트럭이 있는 경우 체크
//		// bridgeQ.front 의 진입 시각 - 현재 시각 계산 후, W 이상이면 다리 지나감
//		if (!bridgeQ.empty() && (tick - bridgeQ.front().ENTER_TICK) >= W)
//		{
//			// 다리 위 무게 합 에서 나가는 트럭 무게 빼주고, pop
//			totalWeights -= bridgeQ.front().WEIGHT;
//			bridgeQ.pop();
//		}
//
//		// 3. 기다리는 트럭 초기화 (기다리는 트럭 없는 경우)
//		if (!truckQ.empty() && waitingTruckWeight == 0)
//		{
//			waitingTruckWeight = truckQ.front(); truckQ.pop();
//		}
//
//		// 4. 다리 진입 가능 체크 및 진입
//		// (다리 위 무게 + 기다리는 트럭 무게) 가 L 보다 작은 경우
//		if(waitingTruckWeight != 0 && totalWeights + waitingTruckWeight <= L)
//		{
//			// 다리로 진입 (bridgeQ에 push, 무게 더하기)
//			bridgeQ.push({ waitingTruckWeight, tick}); // (무게, 들어간 시점)
//			totalWeights += waitingTruckWeight;
//
//			// 기다리는 트럭에서 빼줌
//			waitingTruckWeight = 0;
//		}
//	}
//*/