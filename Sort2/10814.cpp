//#include <iostream>
//#include <utility> // pair
//#include <algorithm> // sort
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 28. ��
//// ���� ��ȣ	: #10814 
//// ���� �̸�	: ���̼� ����
//// �˰���	: ����
//// �ð����⵵: O()
//
//int N;
//pair<int, string> boj[100'005];
//
//bool compare(pair<int, string> a, pair<int, string> b)
//{
//	// ���̷θ� ���ϸ�, �ڿ������� ���Լ��� ���� (stable_sort �� ����)
//	return a.first < b.first;
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
//		cin >> boj[i].first >> boj[i].second;
//	}
//
//	// ���̼� -> ���Լ�
//	stable_sort(boj, boj + N, compare); // �׳� sort�� stable_sort �� �ƴ�;;
//
//
//	for (int i = 0; i < N; i++)
//	{
//		cout << boj[i].first << " " << boj[i].second << '\n';
//	}
//
//	return 0;
//}