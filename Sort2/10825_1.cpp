//#include <iostream>
//#include <algorithm>	
//#include <tuple>
//#include <vector>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 28. ��.
//// ���� ��ȣ	: #10825 
//// ���� �̸�	: ������
//// �˰���	: �迭
//// �ð����⵵: O()
//
//// ���� ����
//// ���� -> ���� -> ���� -> �̸�
//// ���� -> ���� -> ���� -> ����
//
//int N; // 100'000
//
//vector<tuple<int, int, int, string>> students;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	while (N--)
//	{
//		string name;
//		int k, e, m; // ������
//		cin >> name >> k >> e >> m;
//
//		// ����, ���� ���Ҽ� -> ������ �ٲٸ� ��**
//		// ex) 50, 80 -> -80, -50 ������ �ٲ�� ��
//		students.push_back({ -k,e,-m,name });
//	}
//
//	sort(students.begin(), students.end());
//
//	for (auto x : students)
//	{
//		// �̸��� ���
//		cout << get<3>(x) << '\n';
//	}
//
//	return 0;
//}