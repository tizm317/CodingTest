//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 27. ȭ.
//// ���� ��ȣ	: #1919 
//// ���� �̸�	: �ֳʱ׷� �����
//// �˰���	: �迭
//// �ð����⵵: O()
//
//int freqX[26];
//int freqY[26];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	string x, y;
//	cin >> x >> y;
//
//	// ���ĺ� �󵵼�
//	for (auto c : x)
//		freqX[c - 'a']++;
//	
//	for (auto c : y)
//		freqY[c - 'a']++;
//
//	// ������ �ϴ� ���� ���� =
//	// �� ���ڿ� ���ĺ� �󵵼� �� ū �� - ���� �� ��� �� ans �� ����
//	int ans = 0;
//	for (int i = 0; i < 26; i++)
//	{
//		ans += (max(freqX[i], freqY[i]) - min(freqX[i], freqY[i]));
//	}
//	
//	cout << ans;
//
//	return 0;
//}