//#include <iostream>
//#include <deque>
//#include <utility>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 08. 02. ��
//// ���� ��ȣ	: #20055 
//// ���� �̸�	: �����̾� ��Ʈ ���� �κ�
//// �˰���	: �ùķ��̼�, ��
//// �ð����⵵: O()
//
//int N; // <= 100
//
//// {������, �κ� ���� ����} �� deque
//deque<pair<int, bool>> durability_DQ; // 2N
//
//int K;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> K;
//
//	int d = 0;
//	for (int i = 0; i < 2 * N; i++)
//	{
//		cin >> d;
//
//		durability_DQ.push_back({ d,false });
//	}
//
//	// front ���� �κ� �ø���
//	// begin + (N-1) ���� �κ� ����  (deque �� indexing �����ϴϱ�)
//	// ���� ������ ���ϰ� [N-1] �� �ִ� �� ������ ��.
//
//	int zeroDurabilityCnt = 0;
//	int level = 1;
//	while (true)
//	{
//		// 1. ��Ʈ�� �� ĭ ���� �ִ� �κ��� �Բ� �� ĭ ȸ���Ѵ�.
//		pair<int, bool> last = durability_DQ.back(); durability_DQ.pop_back();
//		durability_DQ.push_front(last);
//
//		// N��° ��ġ�� �κ� ������ ����.
//		if (durability_DQ[N - 1].second)
//		{
//			durability_DQ[N - 1].second = false;
//		}
//
//		// 2. ���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵��Ѵ�. ���� �̵��� �� ���ٸ� ������ �ִ´�.
//		for (int i = N - 2; i >= 0; i--)
//		{
//			// ���� ĭ
//			pair<int, bool>& cur = durability_DQ[i];
//			
//			// ���� ĭ�� �κ� ������ pass
//			if (cur.second == false) continue;
//
//			// ���� ĭ
//			pair<int, bool>& next = durability_DQ[i + 1];
//
//			// ���� ĭ ������ 1 �̻�, �κ� ���� ��쿡
//			if (next.first >= 1 && next.second == false)
//			{
//				// ���� ĭ ������ 1 ����, �κ� true
//				next = { next.first - 1, true };
//				
//				// ������ 0�� ĭ ���� üũ << ������ ������ �� ���� üũ
//				if (next.first == 0)
//					zeroDurabilityCnt++;
//
//				// ���� ĭ �κ� false
//				cur.second = false;
//			}
//		}
//
//		// N��° ��ġ�� �κ� ������ ����.
//		if (durability_DQ[N - 1].second)
//		{
//			durability_DQ[N - 1].second = false;
//		}
//
//		// 3. �ø��� ��ġ�� �ִ� ĭ�� �������� 0�� �ƴϸ� �ø��� ��ġ�� �κ��� �ø���.
//			// + �κ��� ����� ��
//		pair<int, bool>& frnt = durability_DQ.front();
//		if (frnt.first != 0 && frnt.second == false)
//		{
//			frnt = { frnt.first - 1, true };
//
//			// ������ 0�� ĭ ���� üũ << ������ ������ �� ���� üũ
//			if (frnt.first == 0)
//				zeroDurabilityCnt++;
//		}
//
//		// 4. �������� 0�� ĭ�� ������ K�� �̻��̶�� ������ �����Ѵ�. �׷��� �ʴٸ� 1������ ���ư���.
//		if (zeroDurabilityCnt >= K) break;
//		level++;
//	}
//
//	cout << level;
//
//	return 0;
//}