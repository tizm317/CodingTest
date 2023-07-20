//#include <iostream>
//#include <deque>
//#include <vector>
//#include <cmath> // pow
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 20. 목
//// 문제 번호	: #14891 
//// 문제 이름	: 톱니바퀴
//// 알고리즘	: 시뮬레이션, 덱(원형 큐)
//// 시간복잡도: O()
//
//int K; // 회전 횟수
//int score; // 점수
//
//// 좌우 방향
//const int dx[2] = { -1, 1 };
//
//const int GearCnt = 4; // 톱니바퀴 개수
//
//// deque 으로 원형 큐 구현
//// front 가 12시 방향, 시계방향 순서
//vector<deque<int>> GearCircularQ_Vec;
//
//bool vis[GearCnt]; // 회전 여부 체크용 배열
//
//
//void printGearState(deque<int>& gear);
//void rotateGear(int idx, int dir);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 톱니바퀴 상태 입력
//	for (int i = 0; i < GearCnt; i++)
//	{
//		int x;
//		cin >> x;
//
//		deque<int> tmp;
//		while (x)
//		{
//			tmp.push_front(x % 10);
//			x /= 10;
//		}
//
//		// 안 들어간 0 채우기
//		while(tmp.size() < 8)
//		{
//			tmp.push_front(0);
//		}
//
//		GearCircularQ_Vec.push_back(tmp);
//	}
//
//	// 회전 횟수 입력
//	cin >> K;
//
//	for (int i = 0; i < K; i++)
//	{
//		// 회전 여부 배열 초기화		
//		fill(vis, vis + 4, false);
//
//		int idx, dir;
//		cin >> idx >> dir;
//
//		// 회전
//		// idx 는 n번째 -> idx-1 로 변경
//		rotateGear(idx - 1, dir);
//	}
//
//	// 점수 계산
//	for (int i = 0; i < GearCnt; i++)
//	{
//		// pow(2, i) 대신 반복문 사용
//		int m = 1;
//		for (int j = 0; j < i; j++)
//		{
//			m *= 2;
//		}
//		score += (GearCircularQ_Vec[i].front() * m); // i 매우 작기 때문에 pow 함수 오차 없음 -> 아니면 그냥 for문 반복
//		
//		//score += (GearCircularQ_Vec[i].front() * int(pow(2, i))); // i 매우 작기 때문에 pow 함수 오차 없음 -> 아니면 그냥 for문 반복
//	}
//
//	// 점수 출력
//	cout << score;
//
//	return 0;
//}
//
//void rotateGear(const int idx, const int dir)
//{
//	// idx 가 배열 범위 넘어가면 탈출
//	if (idx < 0 || idx >= GearCnt)
//		return;
//
//	// idx 번째 톱니바퀴 회전
//	deque<int>& curGear = GearCircularQ_Vec[idx];
//
//	// 회전하기 전 맞닿는 부분 값 저장
//	// 왼쪽, 오른쪽
//	const int connectedParts[2] = { *(curGear.end() - 2), *(curGear.begin() + 2) };
//	//cout << connectedParts[0] << " " << connectedParts[1] << '\n';
//
//	// printGearState(curGear);
//
//	// 회전
//	if (dir == 1) // 시계
//	{
//		// back 을 꺼내서 push_front
//		int back = curGear.back(); curGear.pop_back();
//		curGear.push_front(back);
//	}
//	else // 반시계
//	{
//		// front 를 꺼내서 push_back
//		int frnt = curGear.front(); curGear.pop_front();
//		curGear.push_back(frnt);
//	}
//
//	// 회전 여부 표시
//	vis[idx] = true;
//
//	// printGearState(curGear);
//
//	// 나머지 톱니바퀴 영향
//	// 좌우로 퍼져나감
//	// 재귀적으로 해결
//
//	// 양 옆 맞닿는 부분과 비교하고 회전시킴
//	for (int d = 0; d < 2; d++)
//	{
//		// 다음 톱니바퀴 idx 계산
//		int nxtIdx = idx + dx[d];
//
//		// 배열 범위 벗어나는 지 체크
//		if (nxtIdx < 0 || nxtIdx >= GearCnt)
//			continue;
//
//		// 이미 회전한 경우 (중복(무한) 회전 방지)
//		if (vis[nxtIdx])
//			continue;
//
//		// 다음 인덱스의 톱니바퀴의 맞닿는 부분 구하기
//		int nxtConnectedPart;
//		if (d == 0) // 좌측
//		{
//			nxtConnectedPart = *(GearCircularQ_Vec[nxtIdx].begin() + 2);
//		}
//		else if (d == 1) // 우측
//		{
//			nxtConnectedPart = *(GearCircularQ_Vec[nxtIdx].end() - 2);
//		}
//
//		// 맞닿는 부분이 서로 다른 극일 때
//		if (nxtConnectedPart != connectedParts[d])
//		{
//			// dir 반대 방향 회전
//			rotateGear(nxtIdx, -dir);
//		}
//	}
//}
//
//void printGearState(deque<int>& gear)
//{
//	// 디버깅 용
//	// 톱니바퀴 상태 출력
//
//	cout << "12시 방향 ->";
//	for (auto x : gear)
//	{
//		cout << x << " ";
//	}
//	cout << '\n';
//}