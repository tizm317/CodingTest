//#include <iostream>
//#include <queue>
//#include <utility>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 08. 07. ��
//// ���� ��ȣ	: #21610
//// ���� �̸�	: ������ ���� ��ٶ��
//// �˰���	: �ùķ��̼�, ť
//// �ð����⵵: O()
//
//int N; // <= 50
//int bucket[55][55];
//
//int M; // <= 100
//queue<pair<int, int>> commandQ; // ��� ť
//
//queue<pair<int, int>> cloudQ; // ���� ť
//
//const int dRow[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
//const int dCol[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
//
//void printBuckets();
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//
//	// �� ĭ�� ����� ���� �� �Է�
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cin >> bucket[r][c];
//		}
//	}
//
//	// �̵� ��� �Է�
//	for (int m = 0; m < M; m++)
//	{
//		int dir, dist;
//		cin >> dir >> dist;
//
//		// ť�� ����
//		commandQ.push({ dir - 1, dist }); // 0-based idx
//	}
//
//	// �񱸸� ��������, �񱸸� ť�� ����
//	for (int r = N - 2; r < N; r++)
//		for (int c = 0; c < 2; c++)
//			cloudQ.push({ r, c });
//	//cloudQ.push({ N - 1, 0 });
//	//cloudQ.push({ N - 1, 1 });
//	//cloudQ.push({ N - 2, 0 });
//	//cloudQ.push({ N - 2, 1 });
//
//	// ������ - ���� ���� ���
//	printBuckets();
//
//	// ����� �� �� ������ �ݺ�
//	while (!commandQ.empty())
//	{
//		// ���� ���
//		pair<int, int> command = commandQ.front(); commandQ.pop();
//		
//		// ����, �Ÿ�
//		const int dir = command.first;
//		const int dist = command.second;
//
//		// �� ���� ��ġ ť -> �� ���� ����
//		queue<pair<int, int>> rainedPosQ;
//
//		// ������ ����� ��ġ üũ�ϱ� ���� �迭 -> ����� ������ ���� ���� ������ ����
//		bool beforeCloud[55][55] = { false, };
//
//		// 1. ��� ������ dir �������� distĭ �̵��Ѵ�.
//		while (!cloudQ.empty())
//		{
//			// ���� ����
//			pair<int, int> cloud = cloudQ.front(); cloudQ.pop(); // ������ ��� �������.
//
//			// �̵��� ��ġ // �ؿ������� �� �����ϰ� ����� ���
//			//int nextR = (cloud.first + dRow[dir] * dist + N * dist) % N;
//			int nextR = (cloud.first + (dRow[dir] + N) * dist) % N; // ���� ����
//			int nextC = (cloud.second + (dCol[dir] + N) * dist) % N;
//
//			// ��ġ ���� ���� �ʿ� (�� ���� ����� ���� �� ������...) <<
//				// ������ ��,
//			//while (nextR < 0)
//			//{
//			//	nextR += N;
//			//}
//			//nextR %= N;
//
//			//while (nextC < 0)
//			//{
//			//	nextC += N;
//			//}
//			//nextC %= N;
//
//			// 2. �� �������� �� ���� ������ �ִ� ĭ�� �ٱ��Ͽ� ����� ���� ���� 1 �����Ѵ�.
//			bucket[nextR][nextC]++;
//
//			// ������ ����� ��ġ üũ
//			beforeCloud[nextR][nextC] = true;
//
//			// ���� ������ ĭ�� ť�� ����
//			rainedPosQ.push({ nextR, nextC });
//		}
//		
//		// ����� �� - �� ���� �� ���� ���
//		printBuckets();
//
//
//		// 2���� ���� ������ ĭ (r, c)�� ��������� ������ �����Ѵ�.
//			// ��������� ������ ����ϸ�, �밢�� �������� �Ÿ��� 1�� ĭ�� ���� �ִ� �ٱ����� ����ŭ (r, c)�� �ִ� �ٱ����� ���� ���� �����Ѵ�.
//		while (!rainedPosQ.empty())
//		{
//			// �� ���� ��ġ
//			pair<int, int> rainedPos = rainedPosQ.front(); rainedPosQ.pop();
//			int rainedRow = rainedPos.first;
//			int rainedCol = rainedPos.second;
//
//			// �� ���� ��ġ�� �밢���� ���� �����ϴ� ������ŭ �� ���� ����
//			for (int rr = -1; rr <= 1; rr++)
//			{
//				if (rr == 0) continue;
//
//				for (int cc = -1; cc <= 1; cc++)
//				{
//					if (cc == 0) continue;
//
//					// �밢�� R, C
//					const int diagnalR = rainedRow + rr;
//					const int diagnalC = rainedCol + cc;
//
//					// �̶��� �̵��� �ٸ��� ��踦 �Ѿ�� ĭ�� �밢�� �������� �Ÿ��� 1�� ĭ�� �ƴϴ�.
//					if (diagnalR < 0 || diagnalR >= N || diagnalC < 0 || diagnalC >= N) continue;
//					
//					if (bucket[diagnalR][diagnalC] > 0)
//					{
//						bucket[rainedRow][rainedCol]++;
//					}
//				}
//			}
//		}
//
//		// ������ - ������ ���� �� ���� ���
//		printBuckets();
//
//		// �ٱ��Ͽ� ����� ���� ���� 2 �̻��� ��� ĭ�� ������ �����, ���� ���� 2 �پ���.
//		for (int r = 0; r < N; r++)
//		{
//			for (int c = 0; c < N; c++)
//			{
//				// �̶� ������ ����� ĭ�� 3���� ������ ����� ĭ�� �ƴϾ�� �Ѵ�.
//				if (beforeCloud[r][c] == true) continue;
//
//				if (bucket[r][c] >= 2)
//				{
//					cloudQ.push({ r,c });
//					bucket[r][c] -= 2;
//				}
//			}
//		}
//
//		// ������ - ���� ���� �� ���� ���
//		printBuckets();
//	}
//
//	// ��ü ���� �� ���� ��� �� ���
//	int totalWaterCnt = 0;
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			totalWaterCnt += bucket[r][c];
//		}
//	}
//	cout << totalWaterCnt;
//
//	return 0;
//}
//
//void printBuckets()
//{
//	cout << '\n';
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = 0; c < N; c++)
//		{
//			cout << bucket[r][c] << " ";
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//}