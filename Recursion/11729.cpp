//#include <iostream>
//#include <utility>
//#include <queue>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 02. ȭ
//// ���� ��ȣ	: #11729 
//// ���� �̸�	: �ϳ���ž �̵� ����
//// �˰���	: ���
//// �ð����⵵: O()
//
//int N , cnt;
//
//queue<pair<int, int>> Q;
//
//void doSomething(int n, int from, int to)
//{
//	// ���� n ���� from ���� to�� �̵�
//
//	if (n == 1)
//	{
//		//Q.push({ from, to });
//		cout << from << " " << to << '\n';
//		//cnt++;
//		return;
//	}
//
//	// 1 ~ n-1 ���� from���� (from, to �ƴ� ������) �� �̵�
//	doSomething(n - 1, from, 6 - from - to);
//	
//	// n�� from ���� to�� �̵�
//	Q.push({ from, to });
//	cout << from << " " << to << '\n';
//	
//	//cnt++;
//
//	// 1 ~ n - 1 ���� (from, to, �ƴ� ������)���� to �� �̵�
//	doSomething(n - 1, 6 - from - to, to);
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	//cout << (int)pow(2, N) - 1 << '\n'; // 2^N - 1
//	cout << (1 << N) - 1 << '\n'; // 2^N // bit������
//	
//	doSomething(N, 1, 3);
//
//
//	//cout << cnt << '\n';
//	//while (!Q.empty())
//	//{
//	//	cout << Q.front().first << " " << Q.front().second << '\n';
//	//	Q.pop();
//	//}
//
//	return 0;
//}