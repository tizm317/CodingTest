//#include <iostream>
//#include <vector>
//#include <utility>
//#include <tuple> // tie
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 27. ��
//// ���� ��ȣ	: #15685 
//// ���� �̸�	: �巡�� Ŀ��
//// �˰���	: �ùķ��̼�
//// �ð����⵵: O()
//
//int N; // Ŀ�� ���� <= 20
//
//// ��ǥ�� (row �� y��, col �� x��)
//int coord[105][105];
//
//// 4���� ��� �巡�� Ŀ�� �Ϻ��� �簢���� ����
//int squareCntAroundedDragonCurve;
//
//void dragonCurve(vector<pair<int, int>>& V, int dir, int gen, const int targetGen);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	while (N--)
//	{
//		int x, y, d, g;
//		cin >> x >> y >> d >> g;
//
//		// �巡�� Ŀ�갡 ������ �� ���� ����
//		vector<pair<int, int>> V;
//
//		// �巡�� Ŀ���� ������
//		V.push_back({ x,y });
//
//		// 1. �巡�� Ŀ��
//		dragonCurve(V, d, 0, g);
//
//		// 2. ������� ��ǥ�迡 ǥ��
//		for (auto x : V)
//		{
//			// ���⼭ row �� y��, col �� x����.
//			int row = x.second; // y��
//			int col = x.first; // x��
//
//			// ��ǥ�迡 �巡�� Ŀ�� ������ �� ǥ��
//			coord[row][col] = 1;
//		}
//	}
//
//	// 2. ��ü ��ǥ�� ���鼭 üũ
//	// 100 * 100 * 4 = 4��
//	for (int r = 0; r < 100; r++)
//	{
//		for (int c = 0; c < 100; c++)
//		{
//			// (r,c) �������� (r,c+1), (r+1,c), (r+1,c+1) ��� 1�̸� �ײ������� �簢��
//			if (coord[r][c] == 1 && coord[r][c + 1] == 1 && coord[r + 1][c] == 1 && coord[r + 1][c + 1] == 1)
//				squareCntAroundedDragonCurve++;
//		}
//	}
//
//	// ��� ���
//	cout << squareCntAroundedDragonCurve;
//
//	return 0;
//}
//
//void dragonCurve(vector<pair<int, int>>& V, int dir, int gen, const int targetGen)
//{
//	// ��ǥ ������� ��ȭ �Ϸ�
//	if (gen > targetGen)
//	{
//		// [������] �巡��Ŀ�� ������ �� ���
//		//for (auto x : V)
//		//{
//		//	cout << x.first << " " << x.second << '\n';
//		//}
//		//cout << '\n';
//
//		return;
//	}
//
//	// 0����
//	if (gen == 0)
//	{
//		int x, y;
//		tie(x, y) = V.front();
//
//		// dir ���� �̵�
//		switch (dir)
//		{
//		case 0:
//			V.push_back({ x + 1, y });
//			break;
//		case 1:
//			V.push_back({ x , y - 1 });
//			break;
//		case 2:
//			V.push_back({ x - 1, y });
//			break;
//		case 3:
//			V.push_back({ x , y + 1 });
//			break;
//		}
//	}
//	else
//	{
//		// n ����� n-1 ���� ���� �������� �ð���� ȸ���� ����� �߰�
//
//		vector<pair<int, int>> V_before = V;
//
//		//for (auto& p : V_before) 
//		// ���� -> ������ ������ ���ƾ� ������ �´´�(�������� ���� ������ ��) <<<<
//		for (auto it = V_before.rbegin(); it != V_before.rend(); it++)
//		{
//			int x = it->first;
//			int y = it->second;
//
//			// �� ������ ����
//			int x_end = V_before.back().first;
//			int y_end = V_before.back().second;
//
//			// ������ �������̶� �߰� �� �ص� ��.
//			if (tie(x, y) == tie(x_end, y_end))
//				continue;
//
//			// �� ���� ���� �������� ȸ���� ����� ���Ϳ� �߰�
//				// (x_end, y_end) �������� �ð���� 90�� ȸ�� �� ����
//			V.push_back({ -y + y_end + x_end, x - x_end + y_end });
//		}
//	}
//
//	// 1���� ��ȭ
//	dragonCurve(V, dir, gen + 1, targetGen);
//}