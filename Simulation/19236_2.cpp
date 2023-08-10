//#include <iostream>
//#include <vector>
//#include <tuple>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 08. 10. ��
//// ���� ��ȣ	: #19236
//// ���� �̸�	: û�ҳ� ���
//// �˰���	: �ùķ��̼�, ��Ʈ��ŷ
//// �ð����⵵: O()
//
//const int N = 4;
//int board[N + 1][N + 1];
//
//// 0 : shark
//// 1~16 : fish
//vector<tuple<int, int, int>> fishVec = vector<tuple<int,int,int>>(17); // (r, c, dir)
//
//const int dRow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
//const int dCol[8] = {0, -1, -1, -1, 0, 1, 1, 1};
//
//int maxDeadFishNumSum;
//
//void printBoard(const int curBoard[][5], const vector<tuple<int, int, int>> curFishVec);
//void Move(const vector<tuple<int, int, int>> curFishVec, const int curBoard[][5]);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int fishNum = 0, dir = 0;
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cin >> fishNum >> dir;
//
//			if (r == 0 && c == 0)
//			{
//				// ��� ��ġ Vec �� board ��� �߰�
//				fishVec[0] = { r,c, dir - 1 };
//				board[0][0] = 0;
//
//				// ���� �����
//				fishVec[fishNum] = { -1,-1,-1 };
//				continue;
//			}
//
//			// ����� Vec �� board �� ��� �߰�
//			fishVec[fishNum] = { r, c, dir - 1 };
//			board[r][c] = fishNum;
//		}
//	}
//
//	cout << "�ʱ� ���� : " << '\n';
//	printBoard(board, fishVec);
//
//	Move(fishVec, board);
//	
//	// ��� ���
//	cout << maxDeadFishNumSum;
//
//	return 0;
//}
//
//void printBoard(const int curBoard[][5], const vector<tuple<int, int, int>> curFishVec)
//{
//	// ������ print �Լ�
//	// ����� ��ȣ, ���� ��� ���
//
//	cout << "����� ��ȣ " << '\n';
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cout << curBoard[r][c] << " ";
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//
//	cout << "����� ���� " << '\n';
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			// ���� ����� ���� X ǥ��
//			if (curBoard[r][c] < 0)
//			{
//				cout << "X ";
//				continue;
//			}
//
//			// ������ ����� ���� ǥ��
//			cout << get<2>(curFishVec[curBoard[r][c]]) << " ";
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//}
//
//void Move(const vector<tuple<int, int, int>> curFishVec, const int curBoard[][5])
//{
//	// ���� board�� �ʱ�ȭ
//	int nextBoard[N + 1][N + 1];
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			nextBoard[i][j] = curBoard[i][j];
//
//	// ���� FishVec �ʱ�ȭ
//	vector<tuple<int, int, int>> nextFishVec = curFishVec;
//
//	// 1. ����� �̵�
//	// ����� : 1 ~ 16
//	for (int fishNum = 1; fishNum <= 16; fishNum++)
//	{
//		const tuple<int, int, int> fish = nextFishVec[fishNum];
//		const int curR = get<0>(fish);
//		const int curC = get<1>(fish);
//		const int curDir = get<2>(fish);
//		// ���� ����� ����
//		if (curR == -1 || curC == -1 || curDir == -1) continue;
//
//		// ���� ��ġ ���
//		int nextDir = curDir;
//		while (true)
//		{
//			int nextR = curR + dRow[nextDir];
//			int nextC = curC + dCol[nextDir];
//
//			// ���� �Ѿ�� ���
//			// ����� ���
//			if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N || nextBoard[nextR][nextC] == 0)
//			{
//				// 45�� �ݽð� ȸ��
//				nextDir = (nextDir + 1) % 8;
//				if (nextDir == curDir)
//				{
//					// 360�� ȸ��
//					break;
//				}
//				continue;
//			}
//
//			const int nextFishNum = nextBoard[nextR][nextC];
//
//			// ��ġ ��ȯ
//			// 1. fishVec ����
//				// 1) �� ��ġ ����
//			nextFishVec[fishNum] = { nextR, nextC, nextDir };
//
//				// 2) ��� ��ġ ����
//			// ��� ������ ������� �ƴ� ��쿡 (������� �ٲ� �ʿ� X)
//			if (nextFishNum != -1)
//			{
//				const int nextFishDir = get<2>(nextFishVec[nextFishNum]);
//				nextFishVec[nextFishNum] = { curR, curC, nextFishDir }; // ������ �ڱ��� ���� ����
//			}
//
//			// 2. board ����
//			swap(nextBoard[curR][curC], nextBoard[nextR][nextC]);
//
//			//cout << "fishNum : " << fishNum << " <-> " << nextFishNum << '\n';
//			//printBoard(nextBoard, nextFishVec);
//			break;
//		}
//	}
//
//	cout << "��� ����� �̵� �� : " << '\n';
//	printBoard(nextBoard, nextFishVec);
//
//	// 2. ��� �̵�
//	// �� ��� �̵��� �� �ϴ� ��� üũ�ϱ� ���� bool ����
//	bool isSharkMoved = false;
//
//	const tuple<int, int, int> shark = nextFishVec[0];
//	const int curSharkR = get<0>(shark);
//	const int curSharkC = get<1>(shark);
//	const int curSharkDir = get<2>(shark);
//
//	// ���� ��ġ ���
//		// �Ÿ� 1~3���� �̵� ����
//	for (int dist = 1; dist < N; dist++)
//	{
//		int nextSharkR = curSharkR + dRow[curSharkDir] * dist;
//		int nextSharkC = curSharkC + dCol[curSharkDir] * dist;
//
//		// ���� �Ѵ� ��� ����
//		if (nextSharkR < 0 || nextSharkR >= N || nextSharkC < 0 || nextSharkC >= N)
//			continue;
//
//		const int deadFishNum = nextBoard[nextSharkR][nextSharkC];
//		// ����� ����
//		if (deadFishNum == -1) continue;
//
//		// ���� �����
//		const tuple<int, int, int> deadFish = nextFishVec[deadFishNum];
//
//		// 1. FishVec ����
//			// 1) ��� ��ġ ����, ���� ����
//		nextFishVec[0] = { nextSharkR, nextSharkC, get<2>(deadFish) };
//			// 2) ����� ����
//		nextFishVec[deadFishNum] = { -1, -1, -1 };
//
//		// 2. board ����
//			// 1) ���� ��� ��ġ - 0
//		nextBoard[nextSharkR][nextSharkC] = 0;
//			// 2) ���� ��� ��ġ - �� ����(-1)
//		nextBoard[curSharkR][curSharkC] = -1;
//
//		cout << "��� " << curSharkDir << " �������� " << dist << "��ŭ �̵�" << '\n';
//		printBoard(nextBoard, nextFishVec);
//
//		// ���ȣ��
//		Move(nextFishVec, nextBoard);
//		// �̵������� ǥ��
//		isSharkMoved = true;
//
//		// ����
//		// 1. board ����
//		nextBoard[curSharkR][curSharkC] = 0; // ��� ��ġ
//		nextBoard[nextSharkR][nextSharkC] = deadFishNum; // [����] -1 �� �ƴϰ� ���� ����� ��ȣ
//		// 2. FishVec ����
//		nextFishVec[deadFishNum] = deadFish;
//		nextFishVec[0] = shark;
//	}
//
//	// Ż�� ����
//		// �� ��� �Ÿ��� ���ؼ� �̵� �Ұ��� ���!
//	if (!isSharkMoved)
//	{
//		cout << '\n';
//
//		// ���� ����� ��ȣ�� �� ���
//		int deadFishNumSum = 0;
//		for (int i = 1; i <= 16; i++)
//		{
//			if (get<0>(nextFishVec[i]) != -1) continue;
//			if (get<1>(nextFishVec[i]) != -1) continue;
//			if (get<2>(nextFishVec[i]) != -1) continue;
//
//			deadFishNumSum += i;
//		}
//		cout << deadFishNumSum << '\n';
//
//		// �ִ� �� ���
//		maxDeadFishNumSum = max(maxDeadFishNumSum, deadFishNumSum);
//
//		return;
//	}
//}