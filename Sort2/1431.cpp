//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 01. ��
//// ���� ��ȣ	: #1431
//// ���� �̸�	: �ø��� ��ȣ
//// �˰���	: ����
//// �ð����⵵: O()
//
//int N;			// <= 50
//string arr[55];
//
//bool cmp(const string& a, const string& b)
//{
//	// A�� B�� ���̰� �ٸ���, ª�� ���� ���� �´�.
//	if (a.size() != b.size())
//	{
//		return a.size() < b.size();
//	}
//	// ���� ���� ���̰� ���ٸ�, A�� ��� �ڸ����� �հ� B�� ��� �ڸ����� ���� ���ؼ� ���� ���� ������ ���� �����´�. (������ �͸� ���Ѵ�)
//	else
//	{
//		int aSum = 0, bSum = 0;
//		for (int i = 0; i < a.size(); i++)
//		{
//			if (a[i] >= '0' && a[i] <= '9')
//				aSum += (a[i] - '0');
//
//			if (b[i] >= '0' && b[i] <= '9')
//				bSum += (b[i] - '0');
//		}
//
//		if(aSum != bSum)
//			return aSum < bSum;
//		// ���� 1,2�� �� �������ε� ���� �� ������, ���������� ���Ѵ�. ���ڰ� ���ĺ����� ���������� �۴�.
//		else
//			return a < b;
//	}
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