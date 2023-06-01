//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 20xx. xx. xx.
//// 문제 번호	: #00000 
//// 문제 이름	: 
//// 알고리즘	: 
//// 시간복잡도: O()
//
//int arr[9];
//int arr2[7];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	for (int i = 0; i < 9; i++)
//	{
//		cin >> arr[i];
//	}
//
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = i + 1; j < 9; j++)
//		{
//			int sum = 0;
//			int count = 0;
//			for (int k = 0; k < 9; k++)
//			{
//				if (k == i || k == j) continue;
//				arr2[count++] = arr[k];
//				sum += arr[k];
//			}
//			if (sum == 100)
//			{
//				sort(arr2, arr2 + 7);
//				for (int m = 0; m < 7; m++)
//				{
//					cout << arr2[m] << '\n';
//				}
//				return 0;
//
//			}
//		}
//	}
//
//	return 0;
//}