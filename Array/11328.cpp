//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 27. ȭ.
//// ���� ��ȣ	: #11328
//// ���� �̸�	: Strfry
//// �˰���	: �迭
//// �ð����⵵: O()
//
//int N;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		string a, b;
//		cin >> a >> b;
//
//		int freqA[26] = { 0, };
//		for (auto x : a)
//		{
//			freqA[x - 'a']++;
//		}
//
//		int freqB[26] = { 0, };
//		for (auto x : b)
//		{
//			freqB[x - 'a']++;
//		}
//
//		bool isPossible = true;
//		for (int i = 0; i < 26; i++)
//		{
//			if (freqA[i] != freqB[i])
//			{
//				isPossible = false;
//				cout << "Impossible\n";
//				break;
//			}
//		}
//
//
//		if (isPossible)
//			cout << "Possible\n";
//	}
//
//	return 0;
//}