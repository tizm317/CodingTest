//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 20xx. xx. xx.
//// ���� ��ȣ	: #3273 
//// ���� �̸�	: �� ���� ��
//// �˰���	: �迭
//// �ð����⵵: O(N)
//
//int n, x;
//int num[2'000'005]; // ���� �⿬ ��
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ������ ũ�� n �Է�
//	cin >> n;
//
//	// ���� ��� �迭 ���� �Ҵ� �� �Է� ����
//	int* arr = new int[n] {0, };
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//
//		// ���� �⿬ �� ���
//		num[arr[i]]++;
//	}
//	
//	// �� ���� �� ����� �Է�
//	cin >> x;
//
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		// arr[i]�� �����ϴ� ���� ���
//		int correspondNum = x - arr[i];
//
//		// ���ڰ� 0���� ������ �� ��.
//		if (correspondNum < 0)
//			continue;
//
//		// �����ϸ� count ����
//		if (num[correspondNum] == 1)
//			count++;
//	}
//
//	// �����Ǵ� ���� ��ü ���� / 2 = ���� ���� ����
//	cout << count / 2 << '\n';
//
//	return 0;
//}