//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <queue>
//#include <utility>
//#include <tuple>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 20xx. xx. xx.
//// ���� ��ȣ	: #1941 �ٸ� Ǯ�� 
//// ���� �̸�	: 
//// �˰���	: 
//// �ð����⵵: O()
//
//const int dx[4] = {1,0,-1,0};
//const int dy[4] = {0,1,0,-1};
//
//string students[5];
//int a[25]; // ���տ� ����� �迭
//int ans;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	for (int i = 0; i < 5; i++)
//		cin >> students[i];
//
//	// 0 - 7�� , 1 - 18��
//	fill(a + 7, a + 25, 1);
//
//	do
//	{
//		bool visit[5][5] = { 0, };
//		queue<pair<int, int>> Q;
//		int dasomCnt = 0;
//		int memberCnt = 0;
//
//		for (int r = 0; r < 5; r++)
//		{
//			for (int c = 0; c < 5; c++)
//			{
//				if (a[r * 5 + c] == 1)
//					continue;
//
//				// <- ���⼭ �ϸ� �ȵǰ�! , �������ִ� ��쵵 �������ݾ�..
//				//if (students[r][c] == 'S')
//				//	dasomCnt++;
//
//				//memberCnt++;
//
//				if (Q.empty())
//				{
//					visit[r][c] = true;
//					Q.push({ r,c });
//				}
//			}
//		}
//
//		while (!Q.empty())
//		{
//			int r, c;
//			tie(r, c) = Q.front(); Q.pop();
//
//			// <- ���⼭ üũ! �̾����ִ��� Ȯ���ϱ� ���� 
//			if (students[r][c] == 'S')
//				dasomCnt++;
//
//			memberCnt++;
//
//			for (int dir = 0; dir < 4; dir++)
//			{
//				int nr = r + dy[dir];
//				int nc = c + dx[dir];
//
//				if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5 || visit[nr][nc] == true || a[nr * 5 + nc] == 1)
//					continue;
//
//				visit[nr][nc] = true;
//
//				Q.push({ nr, nc });
//
//				/*if (students[nr][nc] == 'S')
//					dasomCnt++;*/
//
//				//memberCnt++;
//			}
//		}
//
//		ans += (memberCnt == 7 && dasomCnt >= 4);
//
//	} while (next_permutation(a, a + 25));
//
//	cout << ans;
//
//	return 0;
//}
//
///*
//YYYYY
//SYSYS
//YYYYY
//YSYYS
//YYYYY
//*/
