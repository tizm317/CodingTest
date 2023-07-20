//#include <iostream>
//#include <deque>
//#include <vector>
//#include <cmath> // pow
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 20. ��
//// ���� ��ȣ	: #14891 
//// ���� �̸�	: ��Ϲ���
//// �˰���	: �ùķ��̼�, ��(���� ť)
//// �ð����⵵: O()
//
//int K; // ȸ�� Ƚ��
//int score; // ����
//
//// �¿� ����
//const int dx[2] = { -1, 1 };
//
//const int GearCnt = 4; // ��Ϲ��� ����
//
//// deque ���� ���� ť ����
//// front �� 12�� ����, �ð���� ����
//vector<deque<int>> GearCircularQ_Vec;
//
//bool vis[GearCnt]; // ȸ�� ���� üũ�� �迭
//
//
//void printGearState(deque<int>& gear);
//void rotateGear(int idx, int dir);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ��Ϲ��� ���� �Է�
//	for (int i = 0; i < GearCnt; i++)
//	{
//		int x;
//		cin >> x;
//
//		deque<int> tmp;
//		while (x)
//		{
//			tmp.push_front(x % 10);
//			x /= 10;
//		}
//
//		// �� �� 0 ä���
//		while(tmp.size() < 8)
//		{
//			tmp.push_front(0);
//		}
//
//		GearCircularQ_Vec.push_back(tmp);
//	}
//
//	// ȸ�� Ƚ�� �Է�
//	cin >> K;
//
//	for (int i = 0; i < K; i++)
//	{
//		// ȸ�� ���� �迭 �ʱ�ȭ		
//		fill(vis, vis + 4, false);
//
//		int idx, dir;
//		cin >> idx >> dir;
//
//		// ȸ��
//		// idx �� n��° -> idx-1 �� ����
//		rotateGear(idx - 1, dir);
//	}
//
//	// ���� ���
//	for (int i = 0; i < GearCnt; i++)
//	{
//		// pow(2, i) ��� �ݺ��� ���
//		int m = 1;
//		for (int j = 0; j < i; j++)
//		{
//			m *= 2;
//		}
//		score += (GearCircularQ_Vec[i].front() * m); // i �ſ� �۱� ������ pow �Լ� ���� ���� -> �ƴϸ� �׳� for�� �ݺ�
//		
//		//score += (GearCircularQ_Vec[i].front() * int(pow(2, i))); // i �ſ� �۱� ������ pow �Լ� ���� ���� -> �ƴϸ� �׳� for�� �ݺ�
//	}
//
//	// ���� ���
//	cout << score;
//
//	return 0;
//}
//
//void rotateGear(const int idx, const int dir)
//{
//	// idx �� �迭 ���� �Ѿ�� Ż��
//	if (idx < 0 || idx >= GearCnt)
//		return;
//
//	// idx ��° ��Ϲ��� ȸ��
//	deque<int>& curGear = GearCircularQ_Vec[idx];
//
//	// ȸ���ϱ� �� �´�� �κ� �� ����
//	// ����, ������
//	const int connectedParts[2] = { *(curGear.end() - 2), *(curGear.begin() + 2) };
//	//cout << connectedParts[0] << " " << connectedParts[1] << '\n';
//
//	// printGearState(curGear);
//
//	// ȸ��
//	if (dir == 1) // �ð�
//	{
//		// back �� ������ push_front
//		int back = curGear.back(); curGear.pop_back();
//		curGear.push_front(back);
//	}
//	else // �ݽð�
//	{
//		// front �� ������ push_back
//		int frnt = curGear.front(); curGear.pop_front();
//		curGear.push_back(frnt);
//	}
//
//	// ȸ�� ���� ǥ��
//	vis[idx] = true;
//
//	// printGearState(curGear);
//
//	// ������ ��Ϲ��� ����
//	// �¿�� ��������
//	// ��������� �ذ�
//
//	// �� �� �´�� �κа� ���ϰ� ȸ����Ŵ
//	for (int d = 0; d < 2; d++)
//	{
//		// ���� ��Ϲ��� idx ���
//		int nxtIdx = idx + dx[d];
//
//		// �迭 ���� ����� �� üũ
//		if (nxtIdx < 0 || nxtIdx >= GearCnt)
//			continue;
//
//		// �̹� ȸ���� ��� (�ߺ�(����) ȸ�� ����)
//		if (vis[nxtIdx])
//			continue;
//
//		// ���� �ε����� ��Ϲ����� �´�� �κ� ���ϱ�
//		int nxtConnectedPart;
//		if (d == 0) // ����
//		{
//			nxtConnectedPart = *(GearCircularQ_Vec[nxtIdx].begin() + 2);
//		}
//		else if (d == 1) // ����
//		{
//			nxtConnectedPart = *(GearCircularQ_Vec[nxtIdx].end() - 2);
//		}
//
//		// �´�� �κ��� ���� �ٸ� ���� ��
//		if (nxtConnectedPart != connectedParts[d])
//		{
//			// dir �ݴ� ���� ȸ��
//			rotateGear(nxtIdx, -dir);
//		}
//	}
//}
//
//void printGearState(deque<int>& gear)
//{
//	// ����� ��
//	// ��Ϲ��� ���� ���
//
//	cout << "12�� ���� ->";
//	for (auto x : gear)
//	{
//		cout << x << " ";
//	}
//	cout << '\n';
//}