//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 20xx. xx. xx.
//// ���� ��ȣ	: #00000 
//// ���� �̸�	: 
//// �˰���	: 
//// �ð����⵵: O()
//
//int x;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int odd = 0;
//	int minOdd = 100;
//	for (int i = 0; i < 7; i++)
//	{
//		cin >> x;
//		if (x % 2 != 0)
//		{
//			odd += x;
//			if (minOdd >= x)
//			{
//				minOdd = x;
//			}
//		}
//	}
//
//	if (minOdd == 100)
//	{
//		cout << -1 << '\n';
//		return 0;
//	}
//
//	cout << odd << '\n';
//	cout << minOdd << '\n';
//
//	return 0;
//}