//////#include <iostream>
//////#include <vector>
//////using namespace std;
//////
//////// ���� ���� Ǯ��
//////// ��¥		: 20xx. xx. xx.
//////// ���� ��ȣ	: #00000 
//////// ���� �̸�	: 
//////// �˰���	: 
//////// �ð����⵵: O()
//////
//////int N, M;
//////int isUsed[9];
//////vector<int> vec;
////////
////////void func(int m)
////////{
////////	if (m == 0)
////////	{
////////		int size = vec.size();
////////		for (int i = 0; i < size; i++)
////////		{
////////			cout << vec[i] << " ";
////////		}
////////		cout << '\n';
////////		return;
////////	}
////////
////////	for (int i = 1; i <= N; i++)
////////	{
////////		if (isUsed[i] == 1)
////////			continue;
////////
////////		isUsed[i] = 1;
////////		vec.push_back(i);
////////
////////		func(m - 1);
////////
////////		isUsed[i] = 0;
////////		vec.pop_back();
////////	}
////////}
//////
//////int arr[10];
//////
//////// arr[k] �����ϴ� �Լ�
//////void func(int k)
//////{
//////	if (k == M)
//////	{
//////		// �迭 ���
//////		for (int i = 0; i < k; i++)
//////			cout << arr[i] << " ";
//////		cout << '\n';
//////		
//////		return;
//////	}
//////
//////	for (int i = 1; i <= N; i++)
//////	{
//////		// �̹� ������̸� pass
//////		if (isUsed[i] == 1)
//////			continue;
//////
//////		isUsed[i] = 1;
//////		arr[k] = i;
//////		
//////		func(k + 1);
//////		
//////		isUsed[i] = 0;
//////		//arr[k] = -1; // �ʱ�ȭ �� �ص� ������ k��° ���� ����
//////	}
//////}
//////
//////int main()
//////{
//////	ios_base::sync_with_stdio(false);
//////	cin.tie(NULL);
//////
//////	cin >> N >> M;
//////	//func(M);
//////	func(0);
//////
//////	return 0;
//////}
////
////#include <iostream>
////
////using namespace std;
////
////int M, N;
////int arr[9]; // ���� �迭
////bool isused[9];	// �ߺ��� ������� �ʱ� ���� ex : (1,1)
////
////// parameter �� ���� ���� ���¸� �ǹ�
////void func(int cnt)
////{
////	// ���� ���� ������ N�� ������ ��,
////	// ������ ��� �� Ż��
////	if (cnt == N)
////	{
////		for (int i = 0; i < N; i++)
////			cout << arr[i] << " ";
////		cout << '\n';
////
////		return;
////	}
////
////	// ������ �� �� 1 ~ M ����
////	for (int i = 1; i <= M; i++)
////	{
////		// �̹� ����� ���(�ߺ� (1,1)) pass
////		if (isused[i] == true)
////			continue;
////
////		// ��������� ǥ��
////		isused[i] = true;
////		arr[cnt] = i;
////		
////		func(cnt + 1);		// ���� ���·� �̵�
////
////		// ��� ������ ǥ��
////		isused[i] = false;
////
////		// arr[cnt + 1] �ʱ�ȭ �� �ʿ� ���� -> ������ ������.
////	}
////
////}
////
////int main()
////{
////	cin >> M >> N;
////
////	func(0);
////
////	return 0;
////}
//
//
//// next_permuation
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int N, M;
////int num[8];
//vector<int> num;
//
//int main()
//{
//	cin >> N >> M;
//	// 4 2
//
//	for (int i = 1; i <= N; i++)
//		num.push_back(i);
//	 
//
//	do 
//	{
//		for (int i = 0; i < M; i++)
//			cout << num[i] << " ";
//		cout << '\n';
//
//		//    1 2 |3 4
//		// -> 1 2 |4 3 -> 2 1 | 3 4
//		reverse(num.begin() + M, num.end());
//	
//	} while (next_permutation(num.begin(), num.end()));
//
//	return 0;
//}