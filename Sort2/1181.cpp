//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 01. ��
//// ���� ��ȣ	: #1181 
//// ���� �̸�	: �ܾ� ����
//// �˰���	: ����
//// �ð����⵵: O()
//
//
//int N; // 20'000
//string arr[20'005];
//vector<string> vec;
//
//// ���̰� ª�� �ͺ���
//// ���̰� ������ ���� ������
//// ��, �ߺ��� �ܾ�� �ϳ��� ����� �����ؾ� �Ѵ�.
//
//bool cmp(const string& a, const string& b)
//{
//	if (a.size() != b.size())
//		return a.size() < b.size();
//
//	return a < b;
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
//		string s;
//		cin >> s;
//		vec.push_back(s);
//		//cin >> arr[i];
//	}
//
//	//sort(arr, arr + N, cmp);
//	sort(vec.begin(), vec.end(), cmp);
//
//	// �ߺ� �ѹ� ���
//	//cout << arr[0] << '\n';
//	//for (int i = 1; i < N; i++)
//	//{
//	//	if(arr[i] != arr[i-1])
//	//		cout << arr[i] << '\n';
//	//}
//
//	// 1 1 2 3 3 4 5 5 5 6 -> 1 2 3 4 5 6 '5 5 5 6'
//	// unique �Լ��� �ߺ� ������
//	// ������ �޺κ�(5 5 5 6) �� ���� ������ ������� ��
//	// unique �Լ� ���ϰ��� ����� �� ������ end() iterator
//	vec.erase(unique(vec.begin(), vec.end()), vec.end());
//
//	for (auto x : vec)
//	{
//		cout << x << '\n';
//	}
//
//	return 0;
//}