//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <utility> // pair
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 01. ��
//// ���� ��ȣ	: #2910 
//// ���� �̸�	: �� ����
//// �˰���	: ����
//// �ð����⵵: O()
//
//int N, C; // 1'000 , 1'000'000'000
//vector<pair<int, int>> v; // {cnt, num} -> cnt�� ����
//
//bool cmp(const pair<int, int>& a, const pair<int, int>& b)
//{
//	return a.first > b.first;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> C;
//
//	for (int i = 0; i < N; i++)
//	{
//		int x;
//		cin >> x;
//
//		// ���Ϳ� ���� ���� üũ
//		bool isExist = false;
//		for (auto & a : v)
//		{
//			// �̹� ����
//			if (a.second == x)
//			{
//				a.first++;
//				isExist = true;
//				break;
//			}
//		}
//
//		// ���� ���� ���� ���� �߰�
//		if (!isExist) v.push_back({ 1,x });
//	}
//
//	// cnt ���� ����, ������ ���� �����ϱ� ���� stable_sort ���(�� ��Ʈ�� unstable sort�� �� �� �� ���� ����)
//	stable_sort(v.begin(), v.end(), cmp); 
//	//sort(v.begin(), v.end(), cmp); // <- Ʋ��! ���ɿ� ����
//
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		while (v[i].first--)
//		{
//			cout << v[i].second << " ";
//		}
//	}
//
//	return 0;
//}