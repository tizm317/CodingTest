//#include <iostream>
//#include <queue>
//#include <utility>
//#include <algorithm> // next_permutation
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 27. ��
//// ���� ��ȣ	: #17281 
//// ���� �̸�	: �߱�
//// �˰���	: �ùķ��̼�, ����
//// �ð����⵵: O()
//
//int N; // �̴� �� <= 50
//
//int players[55][10]; // 1~9 Ÿ��
//
//pair<int, bool>* base[4]; // 0��, 1��, 2��, 3��
//// ������ �����
//
//int maxScore;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// �ϴ� ť ���� ���ϱ�
//	// 1���� ������ 4��° Ÿ��
//		// ��� ����� �� �ְ�, 1���� 4��°�� �ƴѰ� �����ϴ� ���?
//
//	// �̴׺� player Ÿ�� ��� �Է�
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		for (int p = 1; p <= 9; p++)
//		{
//			cin >> players[i][p];
//		}
//	}
//
//	// ����
//	int idx[9] = { 1,2,3,4,5,6,7,8,9 };
//	do
//	{
//		// 1. Ÿ�� ���� ���ϱ�
//		queue<pair<int, bool>> playerIdxQ;
//
//		// (Ÿ��1 4��° Ÿ�� ����) Ÿ�� 1�� 4��° Ÿ�ڰ� �ƴϸ� X
//		if (idx[3] != 1)
//			continue;
//
//		for (auto x : idx)
//			playerIdxQ.push({ x, false });
//
//		// 2. ������ ������� �̴� ���� �� score ���
//		int score = 0;
//		for(int inning = 0; inning < N; inning++)
//		{
//			// �ƿ� ī��Ʈ �ʱ�ȭ
//			int outCnt = 0;
//
//			// �ƿ� ī��Ʈ 3 �Ǹ� �̴� ����
//			while (outCnt < 3)
//			{
//				// ���� Ÿ��
//				pair<int, bool>& curHitter = playerIdxQ.front();
//
//				// ���� �ڷ� ����
//				playerIdxQ.pop(); playerIdxQ.push(curHitter);
//
//				// �̹� base�� ���� �ִ� ��� pass
//				if (curHitter.second)
//					continue;
//
//				// Ÿ��
//				base[0] = &curHitter;
//				curHitter.second = true;
//
//				// �ƿ�
//				if (players[inning][curHitter.first] == 0)
//				{
//					// �ƿ� ī��Ʈ ����
//					outCnt++;
//
//					// Ÿ������ ��������, false
//					base[0] = nullptr;
//					curHitter.second = false;
//					continue;
//				}
//
//				// �ƿ� �ƴ� ���, ����� ���� ���̽� ����
//				for (int baseIdx = 3; baseIdx >= 0; baseIdx--)
//				{
//					// �ش� base ���� ����
//					pair<int, bool>* runningPlayerPtr = base[baseIdx];
//
//					// �ش� base �� ���� ���� ��� pass
//					if (runningPlayerPtr == nullptr)
//						continue;
//
//					// �̵��� ���� base idx ���
//					const int nxtBaseIdx = baseIdx + players[inning][curHitter.first];
//
//					// ���� ���̽� ��ġ���� ����
//					base[baseIdx] = nullptr;
//
//					// Ȩ�� ���� ���
//					if (nxtBaseIdx >= 4)
//					{
//						// ���� ����
//						score++;
//
//						// ���̽��� �������� ���� false �� ����
//						runningPlayerPtr->second = false;
//					}
//					else
//					{
//						// ���� ��ġ�� �̵�
//						base[nxtBaseIdx] = runningPlayerPtr;
//					}
//				}
//			}
//
//			// �̴� ���� �� �ʱ�ȭ !!!!!!!!!!!!!!!!
//				// base �� ���� ����� �� (���̽� �ʱ�ȭ)
//				// ���� �ִٰ� �Ǿ��ִ� player �� false �� �ʱ�ȭ (�÷��̾� ���� ���� �ʱ�ȭ)
//			for (int i = 0; i < 4; i++)
//			{
//				pair<int, bool>* playerInBasePtr = base[i];
//				if (playerInBasePtr == nullptr)
//					continue;
//
//				// ���� �ִ� player ������ false ����
//				playerInBasePtr->second = false;
//
//				// ���̽� ����ֱ�
//				base[i] = nullptr;
//			}
//		}
//
//		// �ִ� ����
//		maxScore = max(maxScore, score);
//
//		// ���� �ɸ��� Ư�� ���̽� -> ���� �ð��ʰ� X
//		//if (maxScore == 24 * N) // 4 * 8 * N
//		//{
//		//	cout << maxScore;
//		//	return 0;
//		//}
//
//	} while (next_permutation(idx, idx + 9));
//
//	// �ִ����� ���
//	cout << maxScore;
//
//	return 0;
//}