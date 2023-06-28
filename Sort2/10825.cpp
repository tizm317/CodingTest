//#include <iostream>
//#include <algorithm>	
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
//class student
//{
//public:
//	string name;
//	int korean;
//	int english;
//	int math;
//};
//
//student students[100'005];
//
//bool compare(student& a, student& b)
//{
//	// ���� ���Ҽ� -> ���� ������ -> ���� ���Ҽ� -> �̸� ������
//	return (a.korean != b.korean) ? (a.korean > b.korean)
//		: a.english != b.english ? (a.english < b.english)
//		: a.math != b.math ? (a.math > b.math)
//		: a.name < b.name;
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
//		cin >> students[i].name >> students[i].korean >> students[i].english >> students[i].math;
//	}
//
//	sort(students, students + N, compare);
//
//	for (int i = 0; i < N; i++)
//	{
//		cout << students[i].name << '\n';
//	}
//
//	return 0;
//}