//#include <iostream>
//#include <string>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 20xx. xx. xx.
//// ���� ��ȣ	: #2577 
//// ���� �̸�	: ������ ����
//// �˰���	: �迭
//// �ð����⵵: O(N)
//
//int a, b, c;
//int num[10]; // 0~9 ���� �⿬ ��
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ���� 3�� �Է�
//	cin >> a >> b >> c;
//
//	// ���ڿ��� ��ȯ
//	string s = to_string(a * b * c);
//
//	// ���� �⿬ �� ���
//	for (char i : s)
//	{
//		num[i - '0']++;
//	}
//
//	// ���� �⿬ �� ���
//	for (int i : num)
//	{
//		cout << i << '\n';
//	}
//
//	// 2. �ٸ� Ǯ��
//	
//	// ���� 3�� �Է�
//	cin >> a >> b >> c;
//
//	int mult = a * b * c;
//	
//	// �ڸ��� ���� �� �⿬ �� ���
//	while (mult)
//	{
//		num[mult % 10]++;
//		mult /= 10;
//	}
//
//	// ���� �⿬ �� ���
//	for (int i : num)
//	{
//		cout << i << '\n';
//	}
//
//	return 0;
//}