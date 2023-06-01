//#include <iostream>
//#include <list>
//#include <iterator>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 20xx. xx. xx.
//// ���� ��ȣ	: #1406 
//// ���� �̸�	: ������
//// �˰���	: ���� ����Ʈ
//// �ð����⵵: O()
//
////list<char> strList;
////int M;
////char command;
////
////int main()
////{
////	ios_base::sync_with_stdio(false);
////	cin.tie(NULL);
////
////	// 1. STL list Ǯ��
////	
////	// string ���� �Է� ���� ��, list�� ����
////	string s;
////	cin >> s;
////	for (char c : s)
////		strList.push_back(c);
////	
////	// Ŀ�� ���� iterator
////	list<char>::iterator cursor = strList.end();
////
////	// ��ɾ� �Է� �� ó��
////	cin >> M;
////	for (int i = 0; i < M; i++)
////	{
////		cin >> command;
////		switch (command)
////		{
////		case 'L':
////			// Ŀ�� ���� �̵�
////			// ���� �� ���̸� ����
////			if(cursor != strList.begin())
////				cursor--;
////			break;
////		case 'D':
////			// Ŀ�� ������ �̵�
////			// ���� �� ���̸� ����
////			if (cursor != strList.end())
////				cursor++;
////			break;
////		case 'B':
////			// Ŀ�� ���� ���� ����
////			// ���� �� ���̸� ����
////
////			if (cursor != strList.begin())
////			{
////				// ���� ���� ���� ���� ���� �� ����
////				cursor--;
////				cursor = strList.erase(cursor);
////			}
////			break;
////		case 'P':
////			// c��� ���� �߰� �Է� �޾Ƽ�
////			char c;
////			cin >> c;
////			
////			// Ŀ�� ��ġ�� �߰�
////			strList.insert(cursor, c);
////			break;
////		}
////	}
////
////	// ����� ���
////	for (const char& c : strList)
////	{
////		cout << c;
////	}
////
////	return 0;
////}
//
//char dat[600'005];
//int pre[600'005];
//int nxt[600'005];
//int unused = 1;
//int cursor;
//
//int M;
//
//void insert(int addr, char value)
//{
//	// unused ��ġ�� ���ο� �� �߰�
//	dat[unused] = value;
//	pre[unused] = addr;
//	nxt[unused] = nxt[addr];
//
//	// ���� ��� pre ����
//	if(nxt[unused] != -1)
//		pre[nxt[unused]] = unused;
//
//	// �� ����� nxt�� unused ����Ŵ
//	nxt[addr] = unused;
//	
//	// Ŀ�� ������ �̵�*
//	cursor = unused;
//	
//	unused++;
//}
//
//void erase(int addr)
//{
//	// ���� ��� pre ����
//	if (nxt[addr] != -1)
//		pre[nxt[addr]] = pre[addr];
//
//	// ���� ��� nxt ����
//	nxt[pre[addr]] = nxt[addr];
//
//	// Ŀ�� ���� �̵�*
//	cursor = pre[addr];
//}
//
//void traverse()
//{
//	int cur = nxt[0];
//	while (cur != -1)
//	{
//		cout << dat[cur];
//		cur = nxt[cur];
//	}
//}
//
//int main()
//{
//	// 2. �߸� ����
//
//	fill(pre, pre + 100'005, -1);
//	fill(nxt, nxt + 100'005, -1);
//
//	// �Է�
//	string s;
//	cin >> s;
//	for (char c : s)
//	{
//		insert(unused - 1, c);
//	}
//
//	// 
//	cin >> M;
//	for (int i = 0; i < M; i++)
//	{
//		char command = '\0';
//		cin >> command;
//
//		switch (command)
//		{
//		case 'L':
//			// Ŀ�� ���� �̵�
//			// ���� �� ���̸� ����
//			if (pre[cursor] != -1) // cursor == 0
//				cursor = pre[cursor];
//			break;
//		case 'D':
//			// Ŀ�� ������ �̵�
//			// ���� �� ���̸� ����
//			if (nxt[cursor] != -1)
//				cursor = nxt[cursor];
//			break;
//		case 'B':
//			// Ŀ�� ���� ���� ����
//			// ���� �� ���̸� ����
//			if(pre[cursor] != -1)
//				erase(cursor);
//			break;
//		case 'P':
//			// c��� ���� �߰� �Է� �޾Ƽ�
//			char c;
//			cin >> c;
//
//			// Ŀ�� ��ġ�� �߰�
//			insert(cursor, c);
//			break;
//		}
//	}
//
//	traverse();
//
//	return 0;
//}