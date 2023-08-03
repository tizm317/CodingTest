//#include <iostream>
//#include <deque>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 20xx. xx. xx.
//// 문제 번호	: #00000 
//// 문제 이름	: 
//// 알고리즘	: 
//// 시간복잡도: O()
//
//int N; // 원판 개수 <= 50
//
//deque<int> pizza[55];	// 원판 정수 배열
//// front 가 12시 방향
//deque<int> temp[55];
//
//int M; // 정수 개수 <= 50
//
//int T; // 회전수 <= 50
//
//const int CW = 0;
//const int CCW = 1;
//
//void print()
//{
//	cout << '\n';
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 0; j < M; j++)
//			cout << pizza[i][j] << " ";
//		cout << '\n';
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M >> T;
//	
//	// 원판 초기 상태 입력
//	for (int i = 1; i <= N; i++)
//	{
//		int x;
//		for (int j = 0; j < M; j++)
//		{
//			cin >> x;
//
//			pizza[i].push_back(x);
//			temp[i].push_back(x);
//		}
//	}
//
//	//cout << "초기 위치";
//	//print();
//
//	// T번 회전
//	while (T--)
//	{
//		int x, dir, rotateNum;
//		cin >> x >> dir >> rotateNum;
//
//		// 1. 피자 회전
//		// 피자 1~N
//		for (int i = 1; i <= N; i++)
//		{
//			// x의 배수 찾기
//			if (i % x != 0) continue;
//			if (pizza[i].empty()) continue;
//
//			if (dir == CW)
//			{
//				// rotateNum 만큼 반복
//				// 시계방향 (맨 뒤 빼서, 맨 앞으로)
//				for (int k = 0; k < rotateNum; k++)
//				{
//					pizza[i].push_front(pizza[i].back());
//					pizza[i].pop_back();
//				}
//				
//			}
//			else // CCW
//			{
//				// rotateNum 만큼 반복
//				// 반시계방향 (맨 앞 빼서, 맨 뒤로)
//				for (int k = 0; k < rotateNum; k++)
//				{
//					pizza[i].push_back(pizza[i].front());
//					pizza[i].pop_front();
//				}
//				
//			}
//		}
//
//		//cout << "회전";
//		//print();
//
//		// 2. 원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다.
//		int totalSum = 0; // << 인접한 수 없는 경우 활용
//		int totalCnt = 0; // <<
//		for (int i = 1; i <= N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				temp[i][j] = pizza[i][j];
//
//				// 원판 전체 숫자 합
//				// 원판 전체 숫자 개수
//				if (pizza[i][j] != -1)
//				{
//					totalSum += pizza[i][j];
//					totalCnt++;
//				}
//			}
//		}
//
//		bool isClosedSameNum = false;
//		for (int i = 1; i <= N; i++)
//		{
//			// 이전 , 다음 핏짜
//			int prev_i = i - 1;
//			int next_i = i + 1;
//
//			for (int j = 0; j < M; j++)
//			{
//				// 0. 현재 피자의 j 위치에 정수 없는 경우
//				if (pizza[i][j] == -1)
//					continue;
//
//				// 1. 현재 위치에서, 이전 피자, 다음 피자 인접 비교
//				if (!pizza[prev_i].empty())
//				{
//					// 같은경우
//					if (pizza[i][j] == pizza[prev_i][j])
//					{
//						isClosedSameNum = true;
//						temp[i][j] = -1;
//					}
//						//temp[i].push_back(-1);
//					//else // 다른 경우
//					//	temp[i].push_back(pizza[i][j]);
//				}
//
//				if (!pizza[next_i].empty())
//				{
//					// 같은경우
//					if (pizza[i][j] == pizza[next_i][j])
//					{
//						isClosedSameNum = true;
//						temp[i][j] = -1;
//					}
//						//temp[i].push_back(-1);
//					//else // 다른 경우
//					//	temp[i].push_back(pizza[i][j]);
//				}
//
//				// 이전 , 다음 정수
//				int prev_j = j - 1;
//				if (prev_j < 0) prev_j = M - 1;
//
//				int next_j = j + 1;
//				if (next_j >= M) next_j = 0;
//
//				// 2. 현재 피자에서 이전, 다음 정수 비교
//				if (pizza[i][prev_j] != -1)
//				{
//					// 같은경우
//					if (pizza[i][j] == pizza[i][prev_j])
//					{
//						isClosedSameNum = true;
//						temp[i][j] = -1;
//					}
//					//	temp[i].push_back(-1);
//					//else // 다른 경우
//					//	temp[i].push_back(pizza[i][j]);
//				}
//
//				if (pizza[i][next_j] != -1)
//				{
//					// 같은경우
//					if (pizza[i][j] == pizza[i][next_j])
//					{
//						isClosedSameNum = true;
//						temp[i][j] = -1;
//					}
//					//	temp[i].push_back(-1);
//					//else // 다른 경우
//					//	temp[i].push_back(pizza[i][j]);
//				}
//			}
//		}
//
//		for (int i = 1; i <= N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				if (isClosedSameNum)
//				{
//					pizza[i][j] = temp[i][j];
//				}
//				// 인접하면서 같은 수 없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
//				else
//				{
//					if (temp[i][j] == -1) pizza[i][j] = -1;
//					else
//					{
//						const float avg = totalSum / (float)totalCnt; // <<<<<<<<<<<<<<<<<<< int/ int 여서 float 형변환 먼저 해줘야 함...;;
//						if (temp[i][j] > avg) pizza[i][j] = temp[i][j] - 1;
//						else if (temp[i][j] < avg) pizza[i][j] = temp[i][j] + 1;
//						else pizza[i][j] = temp[i][j]; // 같은 수 그대로
//					}
//				}
//			}
//		}
//
//		//cout << "인접한 숫자 지움";
//		//print();
//	}
//
//	int sum = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (pizza[i][j] == -1) continue;
//			sum += pizza[i][j];
//		}
//	}
//	cout << sum;
//
//	return 0;
//}