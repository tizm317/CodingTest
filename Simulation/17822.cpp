//#include <iostream>
//#include <deque>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 20xx. xx. xx.
//// ���� ��ȣ	: #00000 
//// ���� �̸�	: 
//// �˰���	: 
//// �ð����⵵: O()
//
//int N; // ���� ���� <= 50
//
//deque<int> pizza[55];	// ���� ���� �迭
//// front �� 12�� ����
//deque<int> temp[55];
//
//int M; // ���� ���� <= 50
//
//int T; // ȸ���� <= 50
//
//const int CW = 0;
//const int CCW = 1;
//
//void print()
//{
//	cout << '\n';
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 0; j < M; j++)
//			cout << pizza[i][j] << " ";
//		cout << '\n';
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M >> T;
//	
//	// ���� �ʱ� ���� �Է�
//	for (int i = 1; i <= N; i++)
//	{
//		int x;
//		for (int j = 0; j < M; j++)
//		{
//			cin >> x;
//
//			pizza[i].push_back(x);
//			temp[i].push_back(x);
//		}
//	}
//
//	//cout << "�ʱ� ��ġ";
//	//print();
//
//	// T�� ȸ��
//	while (T--)
//	{
//		int x, dir, rotateNum;
//		cin >> x >> dir >> rotateNum;
//
//		// 1. ���� ȸ��
//		// ���� 1~N
//		for (int i = 1; i <= N; i++)
//		{
//			// x�� ��� ã��
//			if (i % x != 0) continue;
//			if (pizza[i].empty()) continue;
//
//			if (dir == CW)
//			{
//				// rotateNum ��ŭ �ݺ�
//				// �ð���� (�� �� ����, �� ������)
//				for (int k = 0; k < rotateNum; k++)
//				{
//					pizza[i].push_front(pizza[i].back());
//					pizza[i].pop_back();
//				}
//				
//			}
//			else // CCW
//			{
//				// rotateNum ��ŭ �ݺ�
//				// �ݽð���� (�� �� ����, �� �ڷ�)
//				for (int k = 0; k < rotateNum; k++)
//				{
//					pizza[i].push_back(pizza[i].front());
//					pizza[i].pop_front();
//				}
//				
//			}
//		}
//
//		//cout << "ȸ��";
//		//print();
//
//		// 2. ���ǿ� ���� ���� ������, �����ϸ鼭 ���� ���� ���� ��� ã�´�.
//		int totalSum = 0; // << ������ �� ���� ��� Ȱ��
//		int totalCnt = 0; // <<
//		for (int i = 1; i <= N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				temp[i][j] = pizza[i][j];
//
//				// ���� ��ü ���� ��
//				// ���� ��ü ���� ����
//				if (pizza[i][j] != -1)
//				{
//					totalSum += pizza[i][j];
//					totalCnt++;
//				}
//			}
//		}
//
//		bool isClosedSameNum = false;
//		for (int i = 1; i <= N; i++)
//		{
//			// ���� , ���� ��¥
//			int prev_i = i - 1;
//			int next_i = i + 1;
//
//			for (int j = 0; j < M; j++)
//			{
//				// 0. ���� ������ j ��ġ�� ���� ���� ���
//				if (pizza[i][j] == -1)
//					continue;
//
//				// 1. ���� ��ġ����, ���� ����, ���� ���� ���� ��
//				if (!pizza[prev_i].empty())
//				{
//					// �������
//					if (pizza[i][j] == pizza[prev_i][j])
//					{
//						isClosedSameNum = true;
//						temp[i][j] = -1;
//					}
//						//temp[i].push_back(-1);
//					//else // �ٸ� ���
//					//	temp[i].push_back(pizza[i][j]);
//				}
//
//				if (!pizza[next_i].empty())
//				{
//					// �������
//					if (pizza[i][j] == pizza[next_i][j])
//					{
//						isClosedSameNum = true;
//						temp[i][j] = -1;
//					}
//						//temp[i].push_back(-1);
//					//else // �ٸ� ���
//					//	temp[i].push_back(pizza[i][j]);
//				}
//
//				// ���� , ���� ����
//				int prev_j = j - 1;
//				if (prev_j < 0) prev_j = M - 1;
//
//				int next_j = j + 1;
//				if (next_j >= M) next_j = 0;
//
//				// 2. ���� ���ڿ��� ����, ���� ���� ��
//				if (pizza[i][prev_j] != -1)
//				{
//					// �������
//					if (pizza[i][j] == pizza[i][prev_j])
//					{
//						isClosedSameNum = true;
//						temp[i][j] = -1;
//					}
//					//	temp[i].push_back(-1);
//					//else // �ٸ� ���
//					//	temp[i].push_back(pizza[i][j]);
//				}
//
//				if (pizza[i][next_j] != -1)
//				{
//					// �������
//					if (pizza[i][j] == pizza[i][next_j])
//					{
//						isClosedSameNum = true;
//						temp[i][j] = -1;
//					}
//					//	temp[i].push_back(-1);
//					//else // �ٸ� ���
//					//	temp[i].push_back(pizza[i][j]);
//				}
//			}
//		}
//
//		for (int i = 1; i <= N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				if (isClosedSameNum)
//				{
//					pizza[i][j] = temp[i][j];
//				}
//				// �����ϸ鼭 ���� �� ���� ��쿡�� ���ǿ� ���� ���� ����� ���ϰ�, ��պ��� ū ������ 1�� ����, ���� ������ 1�� ���Ѵ�.
//				else
//				{
//					if (temp[i][j] == -1) pizza[i][j] = -1;
//					else
//					{
//						const float avg = totalSum / (float)totalCnt; // <<<<<<<<<<<<<<<<<<< int/ int ���� float ����ȯ ���� ����� ��...;;
//						if (temp[i][j] > avg) pizza[i][j] = temp[i][j] - 1;
//						else if (temp[i][j] < avg) pizza[i][j] = temp[i][j] + 1;
//						else pizza[i][j] = temp[i][j]; // ���� �� �״��
//					}
//				}
//			}
//		}
//
//		//cout << "������ ���� ����";
//		//print();
//	}
//
//	int sum = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (pizza[i][j] == -1) continue;
//			sum += pizza[i][j];
//		}
//	}
//	cout << sum;
//
//	return 0;
//}