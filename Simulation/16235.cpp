//#include <iostream>
//#include <vector>
//#include <algorithm> // sort
//#include <tuple>
//#include <deque>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 08. 02. ��
//// ���� ��ȣ	: #16235 
//// ���� �̸�	: ���� ����ũ
//// �˰���	: �ùķ��̼�
//// �ð����⵵: O()
//
//int N; // �� ũ�� <= 10
//int fertilizerArr[15][15]; // ��� �迭
//int board[15][15]; // �� �迭
//
//int M; // ���� ���� <= N^2
//int K; // year <= 1000
//
//vector<tuple<int, int, int>> treeVec; // (r,c,age)
//vector<int> deadTreeAgesVec; // ���� ���� ����, ������ ������� ���� �� ���
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
////		cout << "���� "<< y+1 << " : \n";
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
//// ���� : ���� �������� ������ �ʹ� ���� �þ�� �� ����
//// M * 9^K
//// 100 * 9^0 + ... + 100 * 9^100
//// ����� ��� �ٿ��� �� ������?? �ٵ� �������� �ð����⵵�ε� �������� �ǳ�? �ƿ� �ٲ�� �ұ�??
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
//	// �� �迭 �ʱ�ȭ - ���� ó���� ����� ��� ĭ�� 5��ŭ ����ִ�. ***
//	for (int r = 0; r < N; r++)
//		fill(&board[r][0], &board[r][15], 5);
//
//	// ��� �迭 �Է�
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cin >> fertilizerArr[r][c];
//			//cin >> board[r][c];
//		}
//	}
//
//	// 3���� [year][Row][Col]
//	// �ʱ�ȭ
//	for (int y = 0; y < 15; y++)
//	{
//		vector<vector<int>> v(15, vector<int>(15));
//		dQ.push_back(v);
//	}
//
//	// ���� ���� �Է�
//	for (int t = 0; t < M; t++)
//	{
//		int r, c, y;
//		cin >> r >> c >> y;
//
//		// ���� ���� �Է�
//		// treeVec.push_back({ r - 1,c - 1,y }); // 1-based idx -> 0-based idx ����
//
//		//
//		dQ[y - 1][r - 1][c - 1]++;
//	}
//
//	int year = 0;
//	while (year < K) // <- ����!
//	{
//		 //cout << "\n>>�⵵ " << year << " : \n";
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
//		// ���� ��� ����
//		// sort(treeVec.begin(), treeVec.end());	// O(NlogN), N : treeVec.size()
//
//		// ��,����,����,�ܿ� ����
//		spring();	// O(treeVec.size())
//		summer();	// O(treeVec.size())
//		autumn();	// O(treeVec.size() * 9��)
//		winter();	// O(N^2)
//		
//		// 1�� ����
//		year++;
//	}
//
//	 //cout << ">>�⵵ " << year << " : \n";
//	// print();
//
//
//	// ��Ƴ��� ���� �� ���
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
//	// ��
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			// ���� ���� �迭 �ʱ�ȭ
//			deadTrees[r][c] = 0;
//
//			for (int y = 0; y < dQ.size(); y++)
//			{
//				// ���� y �� ���� ����
//				int& treeCnt = dQ[y][r][c];
//				// ������ pass
//				if (treeCnt == 0) continue;
//				
//				// �ش� ��ġ �����
//				int& food = board[r][c];
//
//				// �ڶ� �� �ִ� ���� ���� ���
//				const int growableTreeCnt = food / (y + 1);
//
//				// 0 ���ϸ� break
//				//if (growableTreeCnt <= 0)
//				//{
//				//	// �� ����
//
//				//	break;
//				//}
//				
//				// �ڶ� �� �ִ� �������� ���� ������ ���� ���
//				if (treeCnt >= growableTreeCnt) // growableTreeCnt == 0 ����
//				{
//					// ���� ���� �迭(���� * ����)
//					deadTrees[r][c] += ((treeCnt - growableTreeCnt) * int((y + 1) / 2) ); // ���� ���� ���� ������? <<<<<<<<<<<<<
//
//					// �ڶ� �� �ִ� ������ŭ �����, break
//					treeCnt = growableTreeCnt;
//
//					// ����� ���� (�� 0�ΰ� �ƴ�, �ֳ�? growableTreeCnt ����� �� �Ҽ��� ����)
//					food -= (treeCnt * (y + 1));
//
//					// y + 1 ���� �� 0���� �ʱ�ȭ!!!!!!!!!!!!!!!!!!!!!!!!! << �̰� ������ ���� ������ �ʳ�???
//					for (int ny = y + 1; ny < dQ.size(); ny++)
//					{
//						// ���� ����
//						int& cnt = dQ[ny][r][c];
//						if (cnt == 0) continue;
//
//						// [����] ���� ���� �迭�� �߰� ���Ծ���!! ***
//						deadTrees[r][c] += (cnt * int((ny + 1) / 2));
//
//						// 0���� �ʱ�ȭ
//						cnt = 0;
//					}
//
//					break;
//				}
//				else // ���� �������� �ڶ� �� �ִ� ������ ���� ���
//				{
//					// treeCnt �״�� ���� (��� ���� �ڶ� �� �����Ƿ�)
//					
//					// ����� ���� (���� ���� ���� * (y+1))
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
//	//	// ���� ����
//	//	if (curAge == -1)
//	//		continue;
//
//	//	if (board[curR][curC] < curAge)
//	//	{
//	//		// Die
//	//		// ���� �����صΰ�, -1�� ����
//	//		deadTreeAgesVec.push_back(curAge);
//	//		curAge = -1;
//	//	}
//	//	else
//	//	{
//	//		// �ڱ� ���̸�ŭ ��� �԰�, ���� 1����
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
//	// ����
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
//	//int deadTreeIdx = 0; // ���� ������ ���� ã�� ���� idx
//	//for (auto& tree : treeVec)
//	//{
//	//	const int curR = get<0>(tree);
//	//	const int curC = get<1>(tree);
//	//	int& curAge = get<2>(tree);
//
//	//	// ����ִ� ���� ���� ���Ϳ� �ְ�, continue
//	//	if (curAge != -1)
//	//	{
//	//		aliveTreeVec.push_back(tree);
//	//		continue;
//	//	}
//
//	//	// ���� ���� -> ���
//	//		// ���� ���� ���� ������ ���� Ȱ��
//	//	const int ageBeforeDie = deadTreeAgesVec[deadTreeIdx++];
//	//	board[curR][curC] += (ageBeforeDie / 2);
//	//}
//	//// ��Ƴ��� ���� ���ͷ� ����
//	//treeVec = aliveTreeVec;
//
//	//// ���� ���� ���� ����ֱ�
//	//deadTreeAgesVec.clear();
//	
//}
//
//// O(treeVec.size() * 9��)
//void autumn()
//{
//	// ����
//	vector<vector<int>> newTrees(15, vector<int>(15));
//	// 1���� ���� �߰� (���� �̹� �ٸ� ������ 1�� �����ؾ� �� < dQ�� �迭 �߰��ϹǷν� ���� ����)
//	dQ.push_front(newTrees);
//
//	// 5�� ��� ���� ã��
//	for (int i = 1; i < 210; i++) // ���� ���� 10 + 1000 1010�� ������ �ִ� <<<<<<<<<<<<<<<<<, �� 24�� �������� ����?? 120??? �Ƹ� K = 100 ���� �����ѵ�
//	{
//		int y = 5 * i - 1; // 0-based index �� 1 ���� (4, 9, 14, ...)
//		if (y >= dQ.size()) break;
//
//		// R*C ��ȸ
//		for (int r = 0; r < N; r++)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				// ���� X
//				if (dQ[y][r][c] == 0) continue;
//
//				// 8����
//				for (int rr = r - 1; rr <= r + 1; rr++)
//				{
//					for (int cc = c - 1; cc <= c + 1; cc++)
//					{
//						// �迭 ����, �� ��ġ üũ
//						if (rr < 0 || rr >= N || cc < 0 || cc >= N) continue;
//						if (rr == r && cc == c) continue;
//
//						// ���� 1�� ���� ����
//						//newTrees[rr][cc]++;
//						dQ[0][rr][cc] += dQ[y][r][c]; // [����] ���� ������ŭ ���ܾ���!!! (+1 �� �ƴ϶�...) <<<<<<<<<<<<<
//					}
//				}
//			}
//		}
//	}
//
//	
//
//	
//	////for (auto& tree : treeVec) // �߰��Ǹ鼭 �̻����� <<<< [����] ����, �迭, ť, ���� �� �߰�,������ �� ����
//	//const int treeCnt = treeVec.size();
//	//for (int t = 0; t < treeCnt; t++)
//	//{
//	//	const tuple<int, int, int>& tree = treeVec[t];
//	//	const int curR = get<0>(tree);
//	//	const int curC = get<1>(tree);
//	//	const int curAge = get<2>(tree);
//
//	//	// ���� ���̰� 5�� ������� ��
//	//	if (curAge % 5 != 0)
//	//		continue;
//
//	//	// �ֺ� 8���� 
//	//	for (int nextR = curR - 1; nextR <= curR + 1; nextR++)
//	//	{
//	//		for (int nextC = curC - 1; nextC <= curC + 1; nextC++)
//	//		{
//	//			// �� ���� �Ѿ�� ��� X
//	//			if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N)
//	//				continue;
//
//	//			// ���� ���� ��ġ X
//	//			if (nextR == curR && nextC == curC)
//	//				continue;
//
//	//			// ���ο� ����(age:1) �߰�
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
//	// �ܿ�
//		// ���� ��� ������
//	//cout << "\n��� : \n";
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
//�ݷ� �̾...
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