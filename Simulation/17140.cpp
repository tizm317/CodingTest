//#include <iostream>
//#include <vector>
//#include <algorithm> // sort, swap
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 31. ��
//// ���� ��ȣ	: #17140 
//// ���� �̸�	: ������ �迭�� ����
//// �˰���	�ùķ��̼�
//// �ð����⵵: O()
//
//int r, c;
//int k;
//
//// �迭 ũ�� 3 �ʱ�ȭ
//int R = 3, C = 3;
//int arr[105][105];
//
//int freq[105];
//
//bool compare(int x, int y);
//void operationR();
//void operationC();
//
//void transpose();
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> r >> c >> k;
//
//	// 3x3 �ʱ� �迭 �Է�
//	for (int i = 0; i < R; i++)
//	{
//		for (int j = 0; j < C; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//
//	int tick = 0;
//	while (tick <= 100) // 100�� �� ���� Ȯ���ؾ���!!!!!!!!!!
//	{
//		// ��� ���
//			// �������� �迭 �ε��� 1���� �����Ѵٰ� �ؼ� -1 ����
//		if (arr[r-1][c-1] == k)
//		{
//			cout << tick;
//			return 0;
//		}
//
//		// R, C ũ�⿡ ���� R����, C����
//		if (R >= C)
//		{
//			operationR();
//		}
//		else 
//		{
//			//operationC();
//
//			// ��ġ ���
//			transpose();
//			operationR();
//
//			// ��� �������
//			transpose();
//		}
//
//		// �ð� ����
//		tick++;
//	}
//
//	// 100�� �̳� �� ã�� ��� -1 ���
//	cout << -1;
//
//	return 0;
//}
//
//bool compare(int x, int y)
//{
//	// �󵵼��� Ŀ���� ������ ����
//		// �󵵼��� ������, ���� ũ�Ⱑ Ŀ���� ������ ����
//	return (freq[x] != freq[y]) ? (freq[x] < freq[y]) : (x < y);
//
//	/*
//	if (freq[x] < freq[y])
//		return true;
//	else if (freq[x] > freq[y])
//		return false;
//	else
//	{
//		return (x < y);
//	}
//	*/
//}
//
//void operationR()
//{
//	// R ����
//
//	// R ���� �� ����� C �� ��� ���� ����
//	int nextC = 0;
//
//	for (int r = 0; r < R; r++)
//	{
//		// freq �迭 �ʱ�ȭ
//		fill(freq, freq + 105, 0);
//
//		vector<int> numVec;
//		for (int c = 0; c < C; c++)
//		{
//			const int num = arr[r][c];
//			
//			// 0�� ���� <<  '���� ������ �� 0�� �����ؾ� �Ѵ�.' ***
//			if (num == 0)
//				continue;
//
//			// ���Ϳ� 1���� ������ �ϱ� ����(�ߺ� ����)
//			if (freq[num] == 0)
//			{
//				numVec.push_back(num);
//			}
//
//			// �󵵼� ����
//			freq[num]++;
//		}
//
//		// ����
//		sort(numVec.begin(), numVec.end(), compare);
//
//		// C ũ�� ��ȭ (��, �󵵼�) ���� �����ϱ� 2��
//		// 100 �Ѿ�� �� ������ ���� clamp ��� (c++17)
//		const int tempC = std::clamp(int(numVec.size() * 2), 0, 100); 
//
//		// r���� tempC ���ϰ�, ���� ū ���� nextC�� ����
//		nextC = max(tempC, nextC);
//
//		// (��, �󵵼�) 1�־� ���ο� ������ arr�� ����
//			// 2���� ����ֱ� ������ ���� tempC/2 
//		for (int i = 0; i < tempC / 2; i++)
//		{
//			const int idx = 2 * i;
//			const int num = numVec[i];
//
//			arr[r][idx] = num;
//			arr[r][idx + 1] = freq[num];
//		}
//
//		// ���� 0 ���� �ʱ�ȭ! ***
//		fill(&arr[r][tempC], &arr[r][105], 0);
//	}
//
//	// C�� nextC ����
//		// �ٲ� �� ũ�� �߿��� ���� ū �� �������� �ٲ�
//	C = nextC;
//}
//
//void operationC()
//{
//	// C ����
//
//	// C ���� �� ����� R �� ��� ���� ����
//	int nextR = 0;
//	for (int c = 0; c < C; c++)
//	{
//		// freq �迭 �ʱ�ȭ
//		fill(freq, freq + 105, 0);
//
//		vector<int> numVec;
//		for (int r = 0; r < R; r++)
//		{
//			const int num = arr[r][c];
//			// 0�� ����
//			if (num == 0)
//				continue;
//
//			if (freq[num] == 0)
//			{
//				numVec.push_back(num);
//			}
//
//			freq[num]++;
//		}
//
//		// ����
//		sort(numVec.begin(), numVec.end(), compare);
//
//		// R ũ�� ��ȭ (��, �󵵼�) ���� �����ϱ� 2��
//		const int tempR = std::clamp(int(numVec.size() * 2), 0, 100); // 100 �Ѿ�� �� ����
//		nextR = max(tempR, nextR);
//
//		for (int i = 0; i < tempR / 2; i++)
//		{
//			const int idx = 2 * i;
//			const int num = numVec[i];
//
//			arr[idx][c] = num;
//			arr[idx + 1][c] = freq[num];
//		}
//
//		// ���� 0 ���� �ʱ�ȭ! ***
//		for (int r = tempR; r < 105; r++)
//			arr[r][c] = 0;
//
//	}
//
//	// �ٲ� �� ũ�� �߿��� ���� ū �� ����
//	R = nextR;
//}
//
//void transpose()
//{
//	// �迭�� ��ġ
//	const int N = max(R, C);
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = r; c < N; c++)
//		{
//			swap(arr[r][c], arr[c][r]);
//		}
//	}
//
//	swap(R, C);
//}