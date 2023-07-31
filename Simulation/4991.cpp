//#include <iostream>
//#include <vector>
//#include <queue>
//#include <utility>
//#include <algorithm> // next_permutation
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 31. ��.
//// ���� ��ȣ	: #4991 
//// ���� �̸�	: �κ� û�ұ�
//// �˰���	: �ùķ��̼�, BFS(������), ����
//// �ð����⵵: O()
//
//// �Ÿ� �迭
//	// 3���� �迭
//	// dist[0] : �κ� û�ұ� ���� �Ÿ� �迭
//	// dist[1~10] : ������ �� ���� �Ÿ� �迭
//int dist[15][25][25];
//
//const int dRow[4] = { -1,0,1,0 };
//const int dCol[4] = { 0,1,0,-1};
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// TC ������
//	while (true)
//	{
//		// R, C �Է�
//		int R, C;
//		cin >> C >> R; // [����] �Է� ���� ������ ��! Ư�� w, h �� �־��� ��..
//
//		// 0 0 �Է� �� ����
//		if (C == 0 && R == 0)
//			break;
//
//		// dist �迭 -1�� �ʱ�ȭ
//		for (int i = 0; i < 15; i++)
//			for (int j = 0; j < 25; j++)
//				for (int k = 0; k < 25; k++)
//					dist[i][j][k] = -1;
//
//		// �ּ� �̵� Ƚ�� (= �ִ� �Ÿ�) �ʱ�ȭ
//		int minDist = -1;
//
//		// �� ���� �迭
//		vector<string> room;
//
//		// ������ �� ��ġ ����
//		vector<pair<int, int>> messyPosVec;
//		messyPosVec.push_back({ -1,-1 });// dummy -> index ���߱� ����(1���� ����)
//
//		// �κ�û�ұ� ���� ��ġ
//		pair<int, int> startPos;
//
//		for (int r = 0; r < R; r++)
//		{
//			// �� ���� �Է�
//			string s;
//			cin >> s;
//			room.push_back(s);
//
//			// ������ ��, �κ� û�ұ� ��ġ �Է�
//			for (int c = 0; c < C; c++)
//			{
//				if (s[c] == '*')
//					messyPosVec.push_back({ r,c });
//				if (s[c] == 'o')
//					startPos = { r,c };
//			}
//
//		}
//
//		// �κ�, ������ �� ��ο� ���ؼ� BFS �� ������, ������ dist�迭�� ����
//			// O(R * C * messyPosVec.size() + 1)
//			// R*C*V.size() -> �ִ� 20*20*10 = 4000
//		queue<pair<int, int>> robotNmessPosQ; // �κ� + ������ �� ��� ť for BFS
//		for (int i = 0; i < messyPosVec.size(); i++)
//		{
//			if (i == 0) // dummy ��� startPos
//			{
//				// ť�� �κ� û�ұ� ��ġ �ְ�, dist[0] 0 �ʱ�ȭ
//				robotNmessPosQ.push(startPos);
//				dist[0][startPos.first][startPos.second] = 0;
//			}
//			else
//			{
//				// ť�� ������ �� ��ġ �ְ�, dist[i] 0 �ʱ�ȭ
//				robotNmessPosQ.push(messyPosVec[i]);
//				dist[i][messyPosVec[i].first][messyPosVec[i].second] = 0;
//			}
//
//			// BFS
//			while (!robotNmessPosQ.empty())
//			{
//				const pair<int, int> curPos = robotNmessPosQ.front(); robotNmessPosQ.pop();
//				for (int dir = 0; dir < 4; dir++)
//				{
//					int nRow = curPos.first + dRow[dir];
//					int nCol = curPos.second + dCol[dir];
//
//					if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C || room[nRow][nCol] == 'x')
//						continue;
//
//					// dist[i] ��������, �ߺ� ����
//					if (dist[i][nRow][nCol] != -1)
//						continue;
//
//					// ť�� �ְ�, dist[i] ���
//					robotNmessPosQ.push({ nRow, nCol });
//					dist[i][nRow][nCol] = dist[i][curPos.first][curPos.second] + 1;
//				}
//			}
//		}
//
//		// ������ �� û�� ���� ���ϱ� ���� idx �迭 �ʱ�ȭ
//			// dummy(0) ���� 1~10
//		int idx[11] = { 0, };
//		for (int i = 0; i <= 10; i++)
//			idx[i] = i;
//
//		// �κ�û�ұ� û�� ���� (����, �ִ� ����� �� : 10!)
//			// O(messyPosVec.size()!)
//		do
//		{
//			// ������� û������ �� ���� �Ÿ�
//			int totalDist = 0;
//
//			bool unableToVisit = false;
//
//			// ������ġ-> ���� ��ġ �ݺ�
//				// i == 0, idx[0] = 0, �κ� ���� ��ġ
//			for (int i = 0; i < messyPosVec.size() - 1; i++)
//			{
//				// ���� ��ġ �ε���
//				const int startIdx = idx[i];
//				// ������ ��ġ �ε���
//				const int destIdx = idx[i + 1];
//
//				// ���� ��ġ->������ ��ġ �� �Ÿ�
//					// -1 �̸�, ������ �� ����
//				if (dist[startIdx][messyPosVec[destIdx].first][messyPosVec[destIdx].second] == -1)
//				{
//					unableToVisit = true;
//					break;
//				}
//
//				// ���� �Ÿ��� ����
//				totalDist += dist[startIdx][messyPosVec[destIdx].first][messyPosVec[destIdx].second];
//			}
//
//			// ������ �� ���� ��� - ���� ����� ��..
//			if (unableToVisit)
//				continue;
//
//			// �ִ� �Ÿ�
//			minDist = (minDist == -1) ? totalDist : min(minDist, totalDist);
//
//		} while (next_permutation(idx + 1, idx + messyPosVec.size())); // 1~size() ������
//
//		// �ִ� �Ÿ� ���
//		cout << minDist << '\n';
//	}
//
//	return 0;
//}