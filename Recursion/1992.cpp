//#include <iostream>
//#include <string>
////#include <queue>
//#include <deque>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 10. ��.
//// ���� ��ȣ	: #1992 
//// ���� �̸�	: ����Ʈ��
//// �˰���	: 
//// �ð����⵵: O()
//
//int N; // <= 2^6 = 64
//int video[70][70];
//
//int colorCnt[3];
//deque<char> Q;
//
//int func(int n, int r, int c)
//{
//	if (n == 1)
//		return video[r][c];
//
//	int arr[3] = { 0, };
//	//deque<int> Q;
//	Q.push_back('(');
//	for (int row = 0; row < 2; row++)
//	{
//		for (int col = 0; col < 2; col++)
//		{
//			int x = func(n / 2, r + row * n / 2, c + col * n / 2);
//			arr[x]++;
//			
//			if(x != 2)
//				Q.push_back('0' + x);
//		}
//	}
//	Q.push_back(')');
//
//
//	for (int i = 0; i < 2; i++)
//	{
//		if (arr[i] == 4)
//		{
//			while (Q.back() != '(')
//			{
//				Q.pop_back();
//			}
//			Q.pop_back();
//
//			return i;
//		}
//	}
//
//	return 2;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	for (int r = 0; r < N; r++)
//	{
//		string s;
//		cin >> s;
//
//		// int �迭�� ��ȯ
//		for (int c = 0; c < N; c++)
//		{
//			video[r][c] = s[c] - '0';
//		}
//	}
//
//	//colorCnt[func(N, 0, 0)]++;
//	if (func(N, 0, 0) != 2)
//	{
//		cout << func(N, 0, 0);
//	}
//
//
//	while (!Q.empty())
//	{
//		cout << Q.front(); Q.pop_front();
//	}
//	
//
//	return 0;
//}
//
//
////8
////00000000
////00000000
////00001111
////00001111
////00011111
////00111111
////00111111
////00111111