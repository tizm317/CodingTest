////#include <iostream>
////using namespace std;
////
////// ���� ���� Ǯ��
////// ��¥		: 2023. 05. 15. ��
////// ���� ��ȣ	: #1182 
////// ���� �̸�	: �κм����� ��
////// �˰���	: 
////// �ð����⵵: O()
////
////int	N, S;
////int arr[20];
////bool isUsed[20];
////int cnt;
////int sum;
////
////void func(int col)
////{
////	// �� �� return ��Ű�� 2���� ���� ��
////	// 5 0
////	// 1 -1 0 4 5 �̷� ���
////	// (1, -1) �̸� sum �� 0 �����ؼ� return �ع����µ�
////	// (1, -1, 0) �� �����ϴٴ� ���� ��ħ.
////	// col �� N-1�� ������ �� return �ϴ� ���� �´�.
////	if (sum == S)
////	{
////		cnt++;
////	}
////
////	if (col >= N)
////	{
////		return;
////	}
////
////	for (int i = col; i < N; i++)
////	{
////		if (isUsed[i] == 1)
////			continue;
////
////		sum += arr[i];
////		isUsed[i] = true;
////
////		func(i + 1);
////
////		sum -= arr[i];
////		isUsed[i] = false;
////	}
////}
////
////int main()
////{
////	ios_base::sync_with_stdio(false);
////	cin.tie(NULL);
////
////	cin >> N >> S;
////	for (int i = 0; i < N; i++)
////		cin >> arr[i];
////
////	for (int i = 0; i < N; i++)
////	{
////		sum = arr[i];
////
////		isUsed[i] = 1;
////		
////		func(i+1);
////		
////		isUsed[i] = 0;
////	}
////
////	cout << cnt;
////	
////	return 0;
////}
//
//
////#include <iostream>
////using namespace std;
////
////int N, S;
////int arr[20]; // ���� �迭
////bool isused[20];
////int totalCnt; // �κ� ���� ����
////int sum;
////
////void func(int col)
////{
////	if (col == N)
////	{
////		return;
////	}
////
////	for (int i = col; i < N; i++)
////	{
////		if (isused[i] == 1)
////			continue;
////
////		isused[i] = 1;
////		sum += arr[i];
////		
////		if (sum == S)
////			totalCnt++;
////		
////		func(col + 1);
////
////		isused[i] = 0;
////		sum -= arr[i];
////	}
////
////}
////
////int main()
////{
////	cin >> N >> S;
////	for (int i = 0; i < N; i++)
////		cin >> arr[i];
////
////	// ù ���� ���� ����
////	for (int i = 0; i < N; i++)
////	{
////		// sum �ʱ�ȭ
////		sum = arr[i];
////
////		isused[i] = 1;
////
////		func(i + 1);
////		
////		isused[i] = 0;
////	}
////
////	cout << totalCnt;
////
////	return 0;
////}
//
//
//#include <iostream>
//using namespace std;
//
//int N, S;
//int arr[20];
//int cnt;
//int isused[20];
//
//void func(int i)
//{
//	if (i == N)
//	{
//		int sum = 0;
//		bool empty = true;
//		for (int idx = 0; idx < N; idx++)
//		{
//			if (isused[idx] == 1)
//			{
//				sum += arr[idx];
//				empty = false;
//			}
//
//		}
//
//		// ������ ����
//		if (empty && S == 0)
//			return;
//
//		if (sum == S)
//			cnt++;
//
//		return;
//	}
//
//	// ������� ����
//	for (int j = 0; j < 2; j++)
//	{
//		isused[i] = j;
//		func(i + 1);
//	}
//	
//}
//
//// ���� ��ġ�� , ������� ��
//void func2(int cur, int tot)
//{
//	if (cur == N)
//	{
//		if (tot == S)
//		{
//			cnt++;
//		}
//
//		return;
//	}
//
//	// ���粨 ���ϰų�,
//	func2(cur + 1, tot);
//
//	// �� ���ϰų�
//	func2(cur + 1, tot + arr[cur]);
//}
//
//int main()
//{
//	cin >> N >> S;
//	for (int i = 0; i < N; i++)
//		cin >> arr[i];
//
//	//func(0);
//	//cout << cnt;
//
//	func2(0, 0);
//
//	if (S == 0) // S�� 0�̸� ������ ����
//		cnt--;
//	
//	cout << cnt;
//
//
//
//	return 0;
//}
