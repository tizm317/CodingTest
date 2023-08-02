//#include <iostream>
//#include <deque>
//#include <utility>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 08. 02. 수
//// 문제 번호	: #20055 
//// 문제 이름	: 컨베이어 벨트 위의 로봇
//// 알고리즘	: 시뮬레이션, 덱
//// 시간복잡도: O()
//
//int N; // <= 100
//
//// {내구도, 로봇 존재 여부} 의 deque
//deque<pair<int, bool>> durability_DQ; // 2N
//
//int K;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> K;
//
//	int d = 0;
//	for (int i = 0; i < 2 * N; i++)
//	{
//		cin >> d;
//
//		durability_DQ.push_back({ d,false });
//	}
//
//	// front 에서 로봇 올리고
//	// begin + (N-1) 에서 로봇 내림  (deque 은 indexing 가능하니까)
//	// 굳이 저렇게 안하고 [N-1] 에 있는 거 내리면 됨.
//
//	int zeroDurabilityCnt = 0;
//	int level = 1;
//	while (true)
//	{
//		// 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
//		pair<int, bool> last = durability_DQ.back(); durability_DQ.pop_back();
//		durability_DQ.push_front(last);
//
//		// N번째 위치에 로봇 있으면 내림.
//		if (durability_DQ[N - 1].second)
//		{
//			durability_DQ[N - 1].second = false;
//		}
//
//		// 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
//		for (int i = N - 2; i >= 0; i--)
//		{
//			// 현재 칸
//			pair<int, bool>& cur = durability_DQ[i];
//			
//			// 현재 칸에 로봇 없으면 pass
//			if (cur.second == false) continue;
//
//			// 다음 칸
//			pair<int, bool>& next = durability_DQ[i + 1];
//
//			// 다음 칸 내구도 1 이상, 로봇 없는 경우에
//			if (next.first >= 1 && next.second == false)
//			{
//				// 다음 칸 내구도 1 감소, 로봇 true
//				next = { next.first - 1, true };
//				
//				// 내구도 0인 칸 개수 체크 << 내구도 감소할 때 마다 체크
//				if (next.first == 0)
//					zeroDurabilityCnt++;
//
//				// 현재 칸 로봇 false
//				cur.second = false;
//			}
//		}
//
//		// N번째 위치에 로봇 있으면 내림.
//		if (durability_DQ[N - 1].second)
//		{
//			durability_DQ[N - 1].second = false;
//		}
//
//		// 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
//			// + 로봇이 없어야 함
//		pair<int, bool>& frnt = durability_DQ.front();
//		if (frnt.first != 0 && frnt.second == false)
//		{
//			frnt = { frnt.first - 1, true };
//
//			// 내구도 0인 칸 개수 체크 << 내구도 감소할 때 마다 체크
//			if (frnt.first == 0)
//				zeroDurabilityCnt++;
//		}
//
//		// 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
//		if (zeroDurabilityCnt >= K) break;
//		level++;
//	}
//
//	cout << level;
//
//	return 0;
//}