//#include <iostream>
////#include <string>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 28. ��.
//// ���� ��ȣ	: #11656 
//// ���� �̸�	: ���̻� �迭
//// �˰���	: ����
//// �ð����⵵: O()
//
//string S; // 1000�� ����
//string suffixs[1005]; // ���̻� �迭, �ִ� 1000��
//
//vector<string> suffixVec;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> S;
//
//	// ���̻� �迭 �����
//	for (int i = 0; i < S.size(); i++)
//	{
//		//suffixs[i] = S.substr(i, S.size() - i);
//		suffixVec.push_back(S.substr(i));
//	}
//
//	// ������ ����
//	//sort(suffixs, suffixs + S.size());
//	sort(suffixVec.begin(), suffixVec.end());
//	
//	// ���
//	/*for (int i = 0; i < S.size(); i++)
//	{
//		cout << suffixs[i] << '\n';
//	}*/
//	for (auto x: suffixVec)
//	{
//		cout << x << '\n';
//	}
//
//
//	return 0;
//}