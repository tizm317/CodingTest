////#include <iostream>
////#include <algorithm> // sort
////using namespace std;
////
////// ���� ���� Ǯ��
////// ��¥		: 2023. 05. 15. ��
////// ���� ��ȣ	: #15655, #15656
////// ���� �̸�	: N�� M 6,7
////// �˰���	: 
////// �ð����⵵: O()
////
////int N, M;
////int arr[9]; // �־��� ����
////int answerArr[9]; // �� ����
//////bool isused[9];
////
////void func(int cnt, int st)
////{
////	if (cnt == M)
////	{
////		for (int i = 0; i < M; i++)
////			cout << answerArr[i] << " ";
////		cout << '\n';
////
////		return;
////	}
////
////
////	for (int i = st; i < N; i++)
////	{
////		// #15655. �ߺ� X
////		// #15656. �ߺ� ���
////		//if (isused[i] == 1)
////			//continue;
////
////		// #15657. �񳻸�����
////	/*	if (cnt != 0 && answerArr[cnt - 1] > arr[i])
////			continue;*/
////
////		//isused[i] = 1;
////		answerArr[cnt] = arr[i];
////
////		func(cnt + 1, i);
////
////		//isused[i] = 0;
////
////	}
////}
////
////int main()
////{
////	ios_base::sync_with_stdio(false);
////	cin.tie(NULL);
////
////	cin >> N >> M;
////	for (int i = 0; i < N; i++)
////		cin >> arr[i];
////
////	// �������� ����
////	sort(arr, arr + N);
////
////	func(0, 0);
////
////	return 0;
////}
//
//
////// 15654
////#include <iostream>
////#include <algorithm>
////#include <vector>
////using namespace std;
////
////int N, M;
////vector<int> num;
////
////int main()
////{
////	cin >> N >> M;
////	for (int i = 0; i < N; i++)
////	{
////		int x;
////		cin >> x;
////		num.push_back(x);
////	}
////	sort(num.begin(), num.end());
////
////	do
////	{
////		for (int i = 0; i < M; i++)
////			cout << num[i] << " ";
////		cout << '\n';
////
////		reverse(num.begin() + M, num.end());
////
////	} while (next_permutation(num.begin(), num.end()));
////
////	return 0;
////}
//
//// 15655
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int N, M;
//vector<int> num;
//int arr[8];
//
//int main()
//{
//	cin >> N >> M;
//
//	// 9 8 7 1
//	for (int i = 0; i < N; i++)
//	{
//		int x;
//		cin >> x;
//		num.push_back(x);
//	}
//
//	// 1 7 8 9
//	sort(num.begin(), num.end());
//
//	// ���� -> 1 7 �� ���� ���ͼ� ( 7 1 �ȳ���)
//	// 0 0 1 1
//	for (int i = 0; i < N; i++)
//	{
//		arr[i] = (i < M ? 0 : 1);
//	}
//
//	do
//	{
//		for (int i = 0; i < N; i++)
//		{
//			if (arr[i] == 0)
//				cout << num[i] << " ";
//		}
//		cout << '\n';
//
//	} while (next_permutation(arr, arr + N));
//	
//	return 0;
//}