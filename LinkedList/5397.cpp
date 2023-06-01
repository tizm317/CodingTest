//#include <iostream>
//#include <list>
//#include <iterator>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 04. 24. ��
//// ���� ��ȣ	: #5397 
//// ���� �̸�	: Ű�ΰ�
//// �˰���	: ���� ����Ʈ
//// �ð����⵵: O()
//
//int T;
//string s;
//list<char> strList;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 1. STL list Ǯ��
//
//	// 1) �׽�Ʈ ���̽� ���� �Է�
//	cin >> T;
//
//	// 2) ���� ���� ��ŭ ���ڿ� �Է�
//	for (int i = 0; i < T; i++)
//	{
//		// list �ʱ�ȭ
//		strList.clear();
//		cin >> s;
//
//		//  Ŀ�� ���� iterator �ʱ�ȭ
//		list<char>::iterator cursor = strList.begin();
//
//		// string �� �Է� ���� ���ڿ��� list�� ����
//		for (char c : s)
//		{
//			// ���� ���� �ٸ��� �۵�
//			switch (c)
//			{
//				// Ŀ�� �̵�
//			case '<':
//				if(cursor != strList.begin())
//					cursor--;
//				break;
//			case '>':
//				if (cursor != strList.end())
//					cursor++;
//				break;
//				// �齺���̽�
//			case '-':
//				if (cursor != strList.begin())
//				{
//					cursor--;
//					cursor = strList.erase(cursor);
//				}
//				break;
//				// ������ ����
//			default:
//				strList.insert(cursor, c);
//				break;
//			}
//		}
//
//		// ����� ���
//		for (const char& c : strList)
//		{
//			cout << c;
//		}
//
//		cout << '\n';
//	}
//	
//
//	return 0;
//}