//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <math.h>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 20xx. xx. xx.
//// ���� ��ȣ	: #1475 
//// ���� �̸�	: �� ��ȣ
//// �˰���	: �迭
//// �ð����⵵: O(N)
//
//string N;		// ���ȣ
//int num[10];	// 0 ~ 9 ���� �⿬ �� �迭
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 1. �� Ǯ��
//	// �� ��ȣ �Է�
//	//cin >> N;
//
//	//// ���� �⿬ ��
//	//for (char c : N)
//	//{
//	//	num[c - '0']++;
//	//}
//
//	//// �ʿ��� ��Ʈ�� �ּҰ��� ����.
//	//// 6, 9 ȣȯ ���� -> ��� ���� �ø�
//	//// 99999 -> 9[5] -> 9[2.5] 6[2.5] -> 9[3] 6[3]
//	//num[6] = num[9] = ceil(((double)num[6] + num[9]) / 2.0);
//
//	//// ���� ���� �ִ� ���
//	//cout << *max_element(num, num + 10) << '\n';
//
//	// 2. �ٸ� Ǯ��
//	int N;
//	cin >> N;
//
//	// �ڸ��� ����
//	while (N)
//	{
//		num[N % 10]++;
//		N /= 10;
//	}
//
//	int ans = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		if (i == 6 || i == 9) 
//			continue;
//
//		ans = max(ans, num[i]);
//	}
//
//	// 6, 9 ȣȯ ���� -> 6, 9 �� ����� �ø��� ��
//	ans = max(ans, (num[6] + num[9] + 1) / 2);
//
//	cout << ans;
//
//	return 0;
//}