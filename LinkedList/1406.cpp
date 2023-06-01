//#include <iostream>
//#include <list>
//#include <iterator>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 20xx. xx. xx.
//// 문제 번호	: #1406 
//// 문제 이름	: 에디터
//// 알고리즘	: 연결 리스트
//// 시간복잡도: O()
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
////	// 1. STL list 풀이
////	
////	// string 으로 입력 받은 후, list에 넣음
////	string s;
////	cin >> s;
////	for (char c : s)
////		strList.push_back(c);
////	
////	// 커서 역할 iterator
////	list<char>::iterator cursor = strList.end();
////
////	// 명령어 입력 및 처리
////	cin >> M;
////	for (int i = 0; i < M; i++)
////	{
////		cin >> command;
////		switch (command)
////		{
////		case 'L':
////			// 커서 왼쪽 이동
////			// 문장 맨 앞이면 무시
////			if(cursor != strList.begin())
////				cursor--;
////			break;
////		case 'D':
////			// 커서 오른쪽 이동
////			// 문장 맨 뒤이면 무시
////			if (cursor != strList.end())
////				cursor++;
////			break;
////		case 'B':
////			// 커서 왼쪽 문자 제거
////			// 문장 맨 앞이면 무시
////
////			if (cursor != strList.begin())
////			{
////				// 왼쪽 문자 제거 위해 감소 후 제거
////				cursor--;
////				cursor = strList.erase(cursor);
////			}
////			break;
////		case 'P':
////			// c라는 문자 추가 입력 받아서
////			char c;
////			cin >> c;
////			
////			// 커서 위치에 추가
////			strList.insert(cursor, c);
////			break;
////		}
////	}
////
////	// 결과물 출력
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
//	// unused 위치에 새로운 값 추가
//	dat[unused] = value;
//	pre[unused] = addr;
//	nxt[unused] = nxt[addr];
//
//	// 다음 노드 pre 수정
//	if(nxt[unused] != -1)
//		pre[nxt[unused]] = unused;
//
//	// 전 노드의 nxt가 unused 가리킴
//	nxt[addr] = unused;
//	
//	// 커서 오른쪽 이동*
//	cursor = unused;
//	
//	unused++;
//}
//
//void erase(int addr)
//{
//	// 다음 노드 pre 수정
//	if (nxt[addr] != -1)
//		pre[nxt[addr]] = pre[addr];
//
//	// 이전 노드 nxt 수정
//	nxt[pre[addr]] = nxt[addr];
//
//	// 커서 왼쪽 이동*
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
//	// 2. 야매 버전
//
//	fill(pre, pre + 100'005, -1);
//	fill(nxt, nxt + 100'005, -1);
//
//	// 입력
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
//			// 커서 왼쪽 이동
//			// 문장 맨 앞이면 무시
//			if (pre[cursor] != -1) // cursor == 0
//				cursor = pre[cursor];
//			break;
//		case 'D':
//			// 커서 오른쪽 이동
//			// 문장 맨 뒤이면 무시
//			if (nxt[cursor] != -1)
//				cursor = nxt[cursor];
//			break;
//		case 'B':
//			// 커서 왼쪽 문자 제거
//			// 문장 맨 앞이면 무시
//			if(pre[cursor] != -1)
//				erase(cursor);
//			break;
//		case 'P':
//			// c라는 문자 추가 입력 받아서
//			char c;
//			cin >> c;
//
//			// 커서 위치에 추가
//			insert(cursor, c);
//			break;
//		}
//	}
//
//	traverse();
//
//	return 0;
//}