////#include <iostream>
////using namespace std;
////
////// ���� ���� Ǯ��
////// ��¥		: 2023. 05. 15. ��
////// ���� ��ȣ	: #15650
////// ���� �̸�	: N�� M 2
////// �˰���	: 
////// �ð����⵵: O()
////
////int N, M;
////int arr[9];
////bool isused[9];
////
////void func(int cnt)
////{
////	if (cnt == M)
////	{
////		for (int i = 0; i < M; i++)
////			cout << arr[i] << " ";
////		cout << '\n';
////
////		return;
////	}
////
////	// ������ ����
////	//int start = 1; // cnt = 0�̸� 1����
////	//if (cnt != 0) start = arr[cnt - 1] + 1; // �ƴϸ� arr ���� ����
////
////	//for (int i = start; i <= N; i++)
////	for (int i = 1; i <= N; i++)
////	{
////		if (isused[i] == 1)
////			continue;
////
////		// �������� X
////		if (cnt > 0 && arr[cnt - 1] > i)
////			continue;
////
////		isused[i] = 1;
////		arr[cnt] = i;
////		
////		func(cnt + 1);
////
////		isused[i] = 0;
////	}
////}
////
////int main()
////{
////	ios_base::sync_with_stdio(false);
////	cin.tie(NULL);
////
////	cin >> N >> M;
////
////	func(0);
////
////	return 0;
////}
//
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int N, M;
//vector<int> num;
//
//int main()
//{
//	cin >> N >> M;
//	// 4 2
//
//	// 0 1 2 3
//	for (int i = 0; i < N; i++)
//	{
//		num.push_back(i < M ? 0 : 1); // 0 0 1 1
//	}
//
//	// ������ �̿��ؼ� 1 2 ���� ��µǰ� ����, 2 1 �ȳ��� (�������ΰ͸� ��µ�)
//
//	do
//	{
//		for (int i = 0; i < N; i++)
//		{
//			if (num[i] == 0)
//				cout << i + 1 << " ";
//		}
//		cout << '\n';
//
//	} while (next_permutation(num.begin(), num.end()));
//
//	return 0;
//}