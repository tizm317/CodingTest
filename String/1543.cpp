//#include <iostream>
//#include <string>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 20xx. xx. xx.
//// ���� ��ȣ	: #1543 
//// ���� �̸�	: ���� �˻�
//// �˰���	: ���ڿ�
//// �ð����⵵: O()
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ���� �Է�
//	string str;
//	getline(cin, str);
//	
//	// ã������ �ܾ� �Է�
//	string word;
//	getline(cin, word);
//
//	int cnt = 0;
//	/*for (int pos = 0; pos < str.size(); )
//	{
//		pos = str.find(word, pos);
//		if (pos == string::npos)
//			break;
//		
//		cnt++;
//
//		pos += word.size();
//	}*/
//
//	int f = str.find(word, 0);
//	while (f != -1)
//	{
//		cnt++;
//
//		// �ε��� �򰥸� ���� ���� ���� ��츦 ������ ���鼭 ����
//		f = str.find(word, f + word.size());
//	}
//
//	cout << cnt;
//
//	return 0;
//}