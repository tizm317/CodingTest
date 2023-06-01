//#include <iostream>
//#include <queue>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 22. ��
//// ���� ��ȣ	: #1463, #12852
//// ���� �̸�	: 1�� �����, 1�� ����� 2
//// �˰���	: BFS / DP
//// �ð����⵵: O()
//
//
//// *3 , *2 , +1
//
//queue<int> Q;
//int dist[1000005];
//
//int N;
//
//int D[1000005];
//int pre[1000005];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 1. BFS Ǯ��
//	cin >> N;
//
//	//Q.push(1);
//
//	//while (!Q.empty())
//	//{
//	//	int cur = Q.front(); Q.pop();
//	//	if (cur == N)
//	//	{
//	//		cout << dist[cur];
//	//		break;
//	//	}
//
//	//	for (int dir = 0; dir < 3; dir++)
//	//	{
//	//		int next;
//	//		if (dir == 0)
//	//			next = cur * 3;
//	//		else if (dir == 1)
//	//			next = cur * 2;
//	//		else
//	//			next = cur + 1;
//
//	//		if (next >= 1000005 || next < 0)
//	//			continue;
//
//	//		if (dist[next] != 0)
//	//			continue;
//
//	//		dist[next] = dist[cur] + 1;
//
//	//		Q.push(next);
//	//	}
//	//}
//
//	// 2. DP Ǯ��
//	D[1] = 0;
//	for (int k = 2; k <= N; k++)
//	{
//		D[k] = D[k - 1] + 1;
//		pre[k] = k - 1;
//
//		if (k % 3 == 0 && D[k] > D[k / 3] + 1)
//		{
//			D[k] = D[k / 3] + 1;
//			pre[k] = k / 3;
//			//D[k] = min(D[k], D[k / 3] + 1);
//
//		}
//		if (k % 2 == 0 && D[k] > D[k / 2] + 1)
//		{
//			D[k] = D[k / 2] + 1;
//			pre[k] = k / 2;
//			//D[k] = min(D[k], D[k / 2] + 1);
//
//		}
//	}
//
//	cout << D[N] << '\n';
//	int k = N;
//	while (pre[k] != 0)
//	{
//		cout << k << " ";
//		k = pre[k];
//	}
//	cout << k;
//	
//
//	return 0;
//}