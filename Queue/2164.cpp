//#include <iostream>
//#include <queue>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2024. 04. 24. ��
//// ���� ��ȣ	: #2164
//// ���� �̸�	: ī��2
//// �˰���	: ť
//// �ð����⵵: O()
//
//int N;
//queue<int> intQueue;
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	// ī�带 ť�� ���� (1~N)
//	for (int i = 1; i <= N; i++)
//	{
//		intQueue.push(i);
//	}
//
//	// ī�� �ϳ� ���� ������ �ݺ�
//	while (intQueue.size() != 1)
//	{
//		// 1. head ��ġ ī�� ����
//		intQueue.pop();
//
//		// 2. head ��ġ ī�带 tail �� push �� pop
//		intQueue.push(intQueue.front());
//		intQueue.pop();
//	}
//
//	// ������ �ϳ����� ī�� ���
//	cout << intQueue.front();
//
//	return 0;
//}