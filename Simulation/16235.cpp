//#include <iostream>
//#include <vector>
//#include <algorithm> // sort
//#include <tuple>
//#include <deque>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 08. 02. 수
//// 문제 번호	: #16235 
//// 문제 이름	: 나무 재테크
//// 알고리즘	: 시뮬레이션
//// 시간복잡도: O()
//
//int N; // 땅 크기 <= 10
//int fertilizerArr[15][15]; // 비료 배열
//int board[15][15]; // 땅 배열
//
//int M; // 나무 갯수 <= N^2
//int K; // year <= 1000
//
//vector<tuple<int, int, int>> treeVec; // (r,c,age)
//vector<int> deadTreeAgesVec; // 죽은 나무 벡터, 여름에 양분으로 변할 때 사용
//
//void spring();
//void summer();
//void autumn();
//void winter();
//
//deque<vector<vector<int>>> dQ;
//int deadTrees[15][15];
////
////
////void print()
////{
////	//for (auto& x : treeVec)
////	//{
////	//	cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << '\n';
////	//}
////
////	for (int y = 0; y < dQ.size(); y++)
////	{
////		cout << "나이 "<< y+1 << " : \n";
////		for (int r = 0; r < N; r++)
////		{
////			for (int c = 0; c < N; c++)
////			{
////				cout << dQ[y][r][c] << " ";
////			}
////			cout << '\n';
////		}
////	}
////	cout << '\n';
////}
//
//
//// 문제 : 번식 과정에서 나무가 너무 많이 늘어나는 게 문제
//// M * 9^K
//// 100 * 9^0 + ... + 100 * 9^100
//// 사이즈를 어떻게 줄여볼 수 있을까?? 근데 제곱승의 시간복잡도인데 그정도로 되나? 아예 바꿔야 할까??
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M >> K;
//
//	// 땅 배열 초기화 - 가장 처음에 양분은 모든 칸에 5만큼 들어있다. ***
//	for (int r = 0; r < N; r++)
//		fill(&board[r][0], &board[r][15], 5);
//
//	// 양분 배열 입력
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cin >> fertilizerArr[r][c];
//			//cin >> board[r][c];
//		}
//	}
//
//	// 3차원 [year][Row][Col]
//	// 초기화
//	for (int y = 0; y < 15; y++)
//	{
//		vector<vector<int>> v(15, vector<int>(15));
//		dQ.push_back(v);
//	}
//
//	// 나무 정보 입력
//	for (int t = 0; t < M; t++)
//	{
//		int r, c, y;
//		cin >> r >> c >> y;
//
//		// 나무 벡터 입력
//		// treeVec.push_back({ r - 1,c - 1,y }); // 1-based idx -> 0-based idx 수정
//
//		//
//		dQ[y - 1][r - 1][c - 1]++;
//	}
//
//	int year = 0;
//	while (year < K) // <- 주의!
//	{
//		 //cout << "\n>>년도 " << year << " : \n";
//		//if (year % 100 == 0)
//		//{
//		//	cout << '\n';
//		//	cout << year << " : ";
//		//}
//		// int treeCnt = 0;
//		// for (int y = 0; y < dQ.size(); y++)
//		// {
//		//	 for (int r = 0; r < N; r++)
//		//	 {
//		//		 for (int c = 0; c < N; c++)
//		//		 {
//		//			 if (dQ[y][r][c] == 0) continue;
//		//			 treeCnt += dQ[y][r][c];
//		//		 }
//		//	 }
//		// }
//
//		// cout << treeCnt << " ";
//		 //print();
//
//		// 나이 어린순 정렬
//		// sort(treeVec.begin(), treeVec.end());	// O(NlogN), N : treeVec.size()
//
//		// 봄,여름,가을,겨울 진행
//		spring();	// O(treeVec.size())
//		summer();	// O(treeVec.size())
//		autumn();	// O(treeVec.size() * 9번)
//		winter();	// O(N^2)
//		
//		// 1년 증가
//		year++;
//	}
//
//	 //cout << ">>년도 " << year << " : \n";
//	// print();
//
//
//	// 살아남은 나무 수 출력
//	//cout << treeVec.size();
//	int treeCnt = 0;
//	for (int y = 0; y < dQ.size(); y++)
//	{
//		for (int r = 0; r < N; r++)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				if (dQ[y][r][c] == 0) continue;
//				treeCnt += dQ[y][r][c];
//			}
//		}
//	}
//
//	cout << treeCnt;
//
//	return 0;
//}
//
//// O(treeVec.size())
//void spring()
//{
//	// 봄
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			// 죽은 나무 배열 초기화
//			deadTrees[r][c] = 0;
//
//			for (int y = 0; y < dQ.size(); y++)
//			{
//				// 나이 y 인 나무 개수
//				int& treeCnt = dQ[y][r][c];
//				// 없으면 pass
//				if (treeCnt == 0) continue;
//				
//				// 해당 위치 영양분
//				int& food = board[r][c];
//
//				// 자랄 수 있는 나무 개수 계산
//				const int growableTreeCnt = food / (y + 1);
//
//				// 0 이하면 break
//				//if (growableTreeCnt <= 0)
//				//{
//				//	// 다 죽음
//
//				//	break;
//				//}
//				
//				// 자랄 수 있는 나무보다 현재 나무가 많은 경우
//				if (treeCnt >= growableTreeCnt) // growableTreeCnt == 0 포함
//				{
//					// 죽은 나무 배열(개수 * 나이)
//					deadTrees[r][c] += ((treeCnt - growableTreeCnt) * int((y + 1) / 2) ); // 오차 쌓일 수도 있을걸? <<<<<<<<<<<<<
//
//					// 자랄 수 있는 나무만큼 남기고, break
//					treeCnt = growableTreeCnt;
//
//					// 영양분 감소 (꼭 0인건 아님, 왜냐? growableTreeCnt 계산할 때 소수점 버림)
//					food -= (treeCnt * (y + 1));
//
//					// y + 1 이후 다 0으로 초기화!!!!!!!!!!!!!!!!!!!!!!!!! << 이거 없으면 문제 생기지 않나???
//					for (int ny = y + 1; ny < dQ.size(); ny++)
//					{
//						// 나무 개수
//						int& cnt = dQ[ny][r][c];
//						if (cnt == 0) continue;
//
//						// [주의] 죽은 나무 배열에 추가 빼먹었다!! ***
//						deadTrees[r][c] += (cnt * int((ny + 1) / 2));
//
//						// 0으로 초기화
//						cnt = 0;
//					}
//
//					break;
//				}
//				else // 현재 나무보다 자랄 수 있는 나무가 많은 경우
//				{
//					// treeCnt 그대로 유지 (모든 나무 자랄 수 있으므로)
//					
//					// 영양분 감소 (현재 나무 개수 * (y+1))
//					food -= (treeCnt * (y + 1));
//				}
//
//			}
//		}
//	}
//
//	
//	//for (auto& tree : treeVec)
//	//{
//	//	const int curR = get<0>(tree);
//	//	const int curC = get<1>(tree);
//	//	int& curAge = get<2>(tree);
//
//	//	// 죽은 나무
//	//	if (curAge == -1)
//	//		continue;
//
//	//	if (board[curR][curC] < curAge)
//	//	{
//	//		// Die
//	//		// 나이 저장해두고, -1로 변경
//	//		deadTreeAgesVec.push_back(curAge);
//	//		curAge = -1;
//	//	}
//	//	else
//	//	{
//	//		// 자기 나이만큼 양분 먹고, 나이 1증가
//	//		board[curR][curC] -= curAge;
//	//		curAge++;
//	//	}
//	//}
//	
//}
//
//// O(treeVec.size())
//void summer()
//{
//	// 여름
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			//board[r][c] += (deadTrees[r][c] / 2);
//			board[r][c] += deadTrees[r][c];
//		}
//	}
//
//
//	
//	//vector<tuple<int, int, int>> aliveTreeVec;
//	//int deadTreeIdx = 0; // 죽은 나무의 나이 찾기 위한 idx
//	//for (auto& tree : treeVec)
//	//{
//	//	const int curR = get<0>(tree);
//	//	const int curC = get<1>(tree);
//	//	int& curAge = get<2>(tree);
//
//	//	// 살아있는 나무 따로 벡터에 넣고, continue
//	//	if (curAge != -1)
//	//	{
//	//		aliveTreeVec.push_back(tree);
//	//		continue;
//	//	}
//
//	//	// 죽은 나무 -> 양분
//	//		// 죽은 나무 나이 저장한 벡터 활용
//	//	const int ageBeforeDie = deadTreeAgesVec[deadTreeIdx++];
//	//	board[curR][curC] += (ageBeforeDie / 2);
//	//}
//	//// 살아남은 나무 벡터로 변경
//	//treeVec = aliveTreeVec;
//
//	//// 죽은 나무 벡터 비워주기
//	//deadTreeAgesVec.clear();
//	
//}
//
//// O(treeVec.size() * 9번)
//void autumn()
//{
//	// 가을
//	vector<vector<int>> newTrees(15, vector<int>(15));
//	// 1년차 나무 추가 (봄에 이미 다른 나무들 1살 증가해야 함 < dQ에 배열 추가하므로써 나이 증가)
//	dQ.push_front(newTrees);
//
//	// 5의 배수 나무 찾기
//	for (int i = 1; i < 210; i++) // 나무 나이 10 + 1000 1010살 정도가 최대 <<<<<<<<<<<<<<<<<, 왜 24를 기준으로 했지?? 120??? 아마 K = 100 으로 착각한듯
//	{
//		int y = 5 * i - 1; // 0-based index 라 1 빼줌 (4, 9, 14, ...)
//		if (y >= dQ.size()) break;
//
//		// R*C 순회
//		for (int r = 0; r < N; r++)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				// 나무 X
//				if (dQ[y][r][c] == 0) continue;
//
//				// 8방향
//				for (int rr = r - 1; rr <= r + 1; rr++)
//				{
//					for (int cc = c - 1; cc <= c + 1; cc++)
//					{
//						// 배열 범위, 내 위치 체크
//						if (rr < 0 || rr >= N || cc < 0 || cc >= N) continue;
//						if (rr == r && cc == c) continue;
//
//						// 나이 1인 나무 생김
//						//newTrees[rr][cc]++;
//						dQ[0][rr][cc] += dQ[y][r][c]; // [주의] 나무 개수만큼 생겨야지!!! (+1 이 아니라...) <<<<<<<<<<<<<
//					}
//				}
//			}
//		}
//	}
//
//	
//
//	
//	////for (auto& tree : treeVec) // 추가되면서 이상해짐 <<<< [주의] 벡터, 배열, 큐, 스택 등 추가,제거할 때 조심
//	//const int treeCnt = treeVec.size();
//	//for (int t = 0; t < treeCnt; t++)
//	//{
//	//	const tuple<int, int, int>& tree = treeVec[t];
//	//	const int curR = get<0>(tree);
//	//	const int curC = get<1>(tree);
//	//	const int curAge = get<2>(tree);
//
//	//	// 현재 나이가 5의 배수여야 함
//	//	if (curAge % 5 != 0)
//	//		continue;
//
//	//	// 주변 8방향 
//	//	for (int nextR = curR - 1; nextR <= curR + 1; nextR++)
//	//	{
//	//		for (int nextC = curC - 1; nextC <= curC + 1; nextC++)
//	//		{
//	//			// 땅 범위 넘어가는 경우 X
//	//			if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N)
//	//				continue;
//
//	//			// 현재 나무 위치 X
//	//			if (nextR == curR && nextC == curC)
//	//				continue;
//
//	//			// 새로운 나무(age:1) 추가
//	//			treeVec.push_back({ nextR, nextC, 1 });
//	//		}
//	//	}
//	//}
//	
//}
//
//// O(N^2)
//void winter()
//{
//	// 겨울
//		// 땅에 비료 더해줌
//	//cout << "\n양분 : \n";
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			board[r][c] += fertilizerArr[r][c];
//
//			//cout << board[r][c] << " ";
//		}
//		//cout << '\n';
//	}
//	//cout << '\n';
//}
//
//
///*
//반례 이어서...
//https://www.acmicpc.net/board/view/99700
//5 2 10
//2 3 2 3 2
//2 3 2 3 2
//2 3 2 3 2
//2 3 2 3 2
//2 3 2 3 2
//2 1 3
//3 2 3
//
//47
//
//10 1 10
//5 5 5 5 5 5 5 5 5 5
//5 5 5 5 5 5 5 5 5 5
//5 5 5 5 5 5 5 5 5 5
//5 5 5 5 5 5 5 5 5 5
//5 5 5 5 5 5 5 5 5 5
//5 5 5 5 5 5 5 5 5 5
//5 5 5 5 5 5 5 5 5 5
//5 5 5 5 5 5 5 5 5 5
//5 5 5 5 5 5 5 5 5 5
//5 5 5 5 5 5 5 5 5 5
//1 1 1
//
//*/