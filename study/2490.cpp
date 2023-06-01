//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 20xx. xx. xx.
//// 문제 번호	: #00000 
//// 문제 이름	: 
//// 알고리즘	: 
//// 시간복잡도: O()
//
//
//int x;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 배(0), 등(1)
//	// A,B,C,D,E (도개걸윷모)
//
//	for (int i = 0; i < 3; i++)
//	{
//		int zero = 0;
//		for (int j = 0; j < 4; j++)
//		{
//			cin >> x;
//			if (x == 0)
//				zero++;
//		}
//
//		switch (zero)
//		{
//		case 0: // 모
//			cout << 'E';
//			break;
//		case 1: // 도
//			cout << 'A';
//			break;
//		case 2: // 개
//			cout << 'B';
//			break;
//		case 3: // 걸
//			cout << 'C';
//			break;
//		case 4: // 윷
//			cout << 'D';
//			break;
//		}
//		cout << '\n';
//	}
//
//	return 0;
//}