//#include <iostream>
//#include <utility>
//#include <queue>
//#include <deque>
//#include <algorithm>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 04. ��
//// ���� ��ȣ	: #9466 
//// ���� �̸�	: �� ������Ʈ
//// �˰���	: BFS
//// �ð����⵵: O()
//
//int T, n;
//
//int partner[100005] = { 0, };
//int visit[100005] = { 0, };
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		cin >> n;
//		//int partner[100005] = { 0, };
//		//int visit[100005] = { 0, };
//		//int* partner = new int[n + 1]{ 0, };	// ��Ʈ��
//		//int* visit = new int[n + 1]{ 0, };		// �湮 ����
//		//int* team = new int[n + 1]{ 0, };		// �� ����
//
//
//		for (int j = 1; j < n + 1; j++)
//		{
//			cin >> partner[j];
//			visit[j] = 0;
//		}
//
//		int totalCnt = 0;
//
//		//
//		for (int j = 1; j < n + 1; j++)
//		{
//			queue<pair<int, int>> Q;
//
//			// �湮�� �� ������ pass
//			if (visit[j] != 0)
//				continue;
//
//			// ������ ť�� �ְ� , visit �� ������ 1 ũ�� ����
//			Q.push({ j, partner[j] });
//			//visit[j] = visit[j - 1] + 1;
//			visit[j] = 1;
//			//visit[j] = *max_element(visit, visit + n + 1) + 1;
//
//			while (true)
//			{
//				// ť�� �� �� ����
//				pair<int, int> curPos = Q.back();
//			
//				// ���� ����
//				// �湮�� �� ����
//				if (visit[curPos.second] != 0)
//				{
//					if (curPos.second == curPos.first)
//					{
//						Q.pop();
//
//						// ť ���� Ż��
//
//						totalCnt += Q.size();
//						break;
//					}
//					else
//					{
//						while (!Q.empty() && Q.front().first != Q.back().second)
//						{
//							totalCnt++;
//							Q.pop();
//						}
//
//						break;
//					}
//				}
//
//				// �湮�� �� ������,
//				// ť�� �ְ�, visit �����ϰ� ����
//				Q.push({ curPos.second, partner[curPos.second] });
//				visit[curPos.second] = 1;
//				//visit[curPos.second] = visit[curPos.first];
//			}
//
//		}
//		cout << totalCnt << '\n';
//	}
//
//
//	return 0;
//}
//
//
