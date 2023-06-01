//#include <iostream>
//#include <queue>
//#include <utility>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 04. 28. ��
//// ���� ��ȣ	: #1697 
//// ���� �̸�	: ���ٲ��� 1
//// �˰���	: BFS
//// �ð����⵵: O()
//
//int N, K;
//queue<int> Q;
//
//int visit[100005];
//int dist[100005];
//
//const int dx[3] = { 1, -1, 2 };
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> K;
//
//	// 1. ���� ���� ��ġ
//	Q.push(N);
//	visit[N] = 1;
//
//	while (!Q.empty())
//	{
//		int curPos = Q.front(); Q.pop();
//
//		// ã��
//		if (curPos == K)
//		{
//			cout << dist[curPos];
//			break;
//		}
//
//		// �����ؾ��� ��!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		// �������� �����̰� 100000�� ����� �� �ȴ� ��� ������ ���� -> �׷��� �ڴ�� ���� X
//		// 0 ~ 200000 ����
//		// �Ǵ�, ���ϱ⸦ �ؼ� 100000 ������ �Ѿ �� -1 �� �ϴ� �� ����,
//		// -1 �� ���� �� �� ���ϸ� �ȴ�..
//		// ���� ���⼭�� 0 ~ 100000 ���� �ص� �ȴ�.
//		// ������ �ٸ� ���������� ��� �� �� �𸣴� �ű� ������ �� �����غ����Ѵ�.. ������!
//
//		// �̵�
//		for (int dir = 2; dir >= 0; dir--)
//		{
//			// ���� ��ġ
//			int nX = 0;
//
//			// �¿� �̵� , �����̵�
//			if (dir < 2)
//				nX = curPos + dx[dir];
//			else // dir == 2
//				nX = curPos * dx[dir];
//
//			// ���� �Ѿ���� üũ
//			if (nX < 0 || nX > 100000)
//				continue;
//
//			// �湮 ���� üũ
//			if (visit[nX] != 0)
//				continue;
//
//			Q.push(nX);
//			
//			// ���� �̵��� 0�� , �¿� �̵��� 1��
//			if (dir == 2)
//				dist[nX] = dist[curPos];
//			else
//				dist[nX] = dist[curPos] + 1;
//			
//			visit[nX] = 1;
//
//		}
//
//		//// 1. ���� �̵�
//		//if (curPos != 0 && curPos * 2 <= 100000)
//		//{
//		//	// �湮���� ���� ����
//		//	if (visit[curPos * 2] == 0)
//		//	{
//		//		Q.push(curPos * 2);
//		//		visit[curPos * 2] = visit[curPos] + 1;
//		//	}
//		//}
//
//		//// 2. �ȱ�
//		//if (curPos - 1 >= 0)
//		//{
//		//	// �湮 üũ
//		//	if (visit[curPos - 1] == 0)
//		//	{
//		//		Q.push(curPos - 1);
//		//		visit[curPos - 1] = visit[curPos] + 1;
//		//	}
//		//}
//
//		//if (curPos + 1 <= 100000)
//		//{
//		//	// �湮 üũ
//		//	if (visit[curPos + 1] == 0)
//		//	{
//		//		Q.push(curPos + 1);
//		//		visit[curPos + 1] = visit[curPos] + 1;
//		//	}
//		//}
//	}
//
//	return 0;
//}