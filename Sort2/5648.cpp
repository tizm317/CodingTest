//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 01. ��
//// ���� ��ȣ	: #5648
//// ���� �̸�	: ������ ����
//// �˰���	: ����
//// �ð����⵵: O()
//
//int N; // <= 1'000'000
//string arr[1'000'005];
//
//bool cmp(const string& a, const string& b)
//{
//	// ���� �ٸ���, ª���� ��
//	if (a.size() != b.size())
//		return a.size() < b.size();
//
//	// ������, �� �ڸ��� ��
//	for (int i = 0; i < a.size(); i++)
//	{
//		if (a[i] != b[i])
//			return a[i] < b[i];
//	}
//
//	// ��� ������ false ����
//	return false;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> arr[i];
//
//		// ���� �Ųٷ� ������
//		reverse(arr[i].begin(), arr[i].end());
//
//		// 0�� ����Ǵ� ��� 0 ����� �۾�
//		int size = arr[i].size();
//		for (int j = 0; j < size; j++)
//		{
//			if (arr[i][j] != '0')
//			{
//				arr[i].erase(arr[i].begin(), arr[i].begin() + j);
//				break;
//			}
//		}
//	}
//
//	sort(arr, arr + N, cmp);
//
//	for (int i = 0; i < N; i++)
//	{
//		cout << arr[i] << '\n';
//	}
//
//	return 0;
//}