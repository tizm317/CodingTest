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
//int N , x, y = 0, m = 0;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> x;
//		
//		y += (x / 30 + 1) * 10;
//		m += (x / 60 + 1) * 15;
//	}
//
//	if (y < m)
//	{
//		cout << 'Y' << " " << y;
//	}
//	else if (y > m)
//	{
//		cout << 'M' << " " << m;
//	}
//	else
//	{
//		cout << 'Y' << " " << 'M' << " " << y;
//	}
//
//	return 0;
//}