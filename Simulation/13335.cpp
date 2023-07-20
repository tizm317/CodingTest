//#include <iostream>
//#include <queue>
//#include <utility>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 20. ��
//// ���� ��ȣ	: #13335 
//// ���� �̸�	: Ʈ��
//// �˰���	: �ùķ��̼�, ť
//// �ð����⵵: O()
//
//int N; // Ʈ�� �� 1 <= <= 1000
//int W; // �ٸ� ���� 1 <= <= 100
//int L; // �ٸ� �ִ����� 10 <= <= 1000
//
//// �ٸ� ���� �ִ� Ʈ���� ��� ť�� �ٸ��� �����ϱ� �� Ʈ���� ��� ť, �� 2���� ť�� Ȱ����
//queue<int> truckQ; // Ʈ�� ���� ť (1<= ���� <= 10)
//queue<pair<int,int>> bridgeQ; // �ٸ� �� (Ʈ�� ����, ���� �ð�)
//
//#define WEIGHT first
//#define ENTER_TICK second
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// Ʈ�� ��, �ٸ� ����, �ִ� ���� �Է�
//	cin >> N >> W >> L;
//
//	// Ʈ�� ���� �Է�
//	for (int i = 0; i < N; i++)
//	{
//		int x;
//		cin >> x;
//
//		truckQ.push(x);
//	}
//
//	// �ð� üũ�� ���� tick
//	int tick = 0;
//
//	// �ٸ� ���� ���� Ʈ���� ���� ��� ����
//	//int waitingTruckWeight = 0;
//
//	// ���� �ٸ� �� ���� �� ����
//	int totalWeights = 0;
//	
//	// <<<<< if ���� ���� ó���� �� �� ����ϰ� �� ���� ������?? >>>>>
//	// truckQ, bridgeQ, waitingTruckWeight ��� Ʈ�� ���� ���� ����Ǳ� ������,
//	// �ϳ��� ���� �ִٸ�, while loop �� ���ƾ� ��.
//	// �׷��� ����ϰ� ������ �ȵǴµ�..
//		// waitingTruckWeight �� �� ���� �ذ��� �� ������?
//			// ���� ����� ������?
//				// �ٸ��� �ٷ� �� ����, �ٸ� ���� Ʈ���� ���� ���� ������ �����ϱ� ���� ��� ����.
//					// front() �� �ٷ� ���ϰ�, ������ ��쿡�� pop �ع����� �ɵ�?!
//						// waitingTruckWeight ���� �� �� �ܼ����� ����
//
//	// 0. �ٸ� ��, �ٸ� �� Ʈ�� ��� ���� ��� break
//	while (!truckQ.empty() || !bridgeQ.empty())
//	{
//		// 1. �ð� ����
//		tick++;
//
//		// 2. �ٸ� ���� Ʈ���� �ִ� ��� üũ
//		// bridgeQ.front �� ���� �ð� - ���� �ð� ��� ��, W �̻��̸� �ٸ� ������
//		if (!bridgeQ.empty() && (tick - bridgeQ.front().ENTER_TICK) >= W)
//		{
//			// �ٸ� �� ���� �� ���� ������ Ʈ�� ���� ���ְ�, pop
//			totalWeights -= bridgeQ.front().WEIGHT;
//			bridgeQ.pop();
//		}
//
//		// truckQ �� Ʈ�� ���� �ִ� �� üũ
//		if (truckQ.empty())
//			continue;
//
//		// 3. �ٸ� ���� ���� üũ �� ����
//		// (�ٸ� �� ���� + ��ٸ��� Ʈ�� ����) �� L ���� ���� ���
//		//if(!truckQ.empty() && totalWeights + truckQ.front() <= L)
//		if(totalWeights + truckQ.front() <= L)
//		{
//			// �ٸ��� ���� (bridgeQ�� push, ���� ���ϱ�)
//			bridgeQ.push({ truckQ.front(), tick}); // (����, �� ����)
//			totalWeights += truckQ.front();
//
//			// ��ٸ��� Ʈ������ ����
//			truckQ.pop();
//		}
//	}
//
//	// �ּ� �ð� ���
//	cout << tick;
//
//	return 0;
//}
//
//
//// waitingTruckWeight ��� ����
///*
//while(true)
//	{
//		// 0. �ٸ� ��, �ٸ� ��, �ٸ� ���� ���� ��� ���� Ʈ�� ��� ���� ��� break
//		if (truckQ.empty() && bridgeQ.empty() && waitingTruckWeight == 0)
//			break;
//
//		// 1. �ð� ����
//		tick++;
//
//		// 2. �ٸ� ���� Ʈ���� �ִ� ��� üũ
//		// bridgeQ.front �� ���� �ð� - ���� �ð� ��� ��, W �̻��̸� �ٸ� ������
//		if (!bridgeQ.empty() && (tick - bridgeQ.front().ENTER_TICK) >= W)
//		{
//			// �ٸ� �� ���� �� ���� ������ Ʈ�� ���� ���ְ�, pop
//			totalWeights -= bridgeQ.front().WEIGHT;
//			bridgeQ.pop();
//		}
//
//		// 3. ��ٸ��� Ʈ�� �ʱ�ȭ (��ٸ��� Ʈ�� ���� ���)
//		if (!truckQ.empty() && waitingTruckWeight == 0)
//		{
//			waitingTruckWeight = truckQ.front(); truckQ.pop();
//		}
//
//		// 4. �ٸ� ���� ���� üũ �� ����
//		// (�ٸ� �� ���� + ��ٸ��� Ʈ�� ����) �� L ���� ���� ���
//		if(waitingTruckWeight != 0 && totalWeights + waitingTruckWeight <= L)
//		{
//			// �ٸ��� ���� (bridgeQ�� push, ���� ���ϱ�)
//			bridgeQ.push({ waitingTruckWeight, tick}); // (����, �� ����)
//			totalWeights += waitingTruckWeight;
//
//			// ��ٸ��� Ʈ������ ����
//			waitingTruckWeight = 0;
//		}
//	}
//*/