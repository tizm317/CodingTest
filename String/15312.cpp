//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 19. ��
//// ���� ��ȣ	: #15312
//// ���� �̸�	: �̸� ����
//// �˰���	: ���ڿ�
//// �ð����⵵: O()
//
//// ���ĺ� ȹ��
//int drawCnt[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	string A, B;
//	cin >> A >> B;
//	// CJM
//	// HER
//	// C H J E M R
//	// 1 3 2 3 2 2
//	//  4 5 5 5 4
//	//   9 0 0 9
//	//    9 0 9
//	//     9 9
//
//	int* gunghab = new int[A.size() * 2]{ 0, };
//
//	for (int i = 0; i < A.size(); i++)
//	{
//		gunghab[2 * i] = drawCnt[A[i] - 'A'];	// C6386 
//		gunghab[2 * i + 1] = drawCnt[B[i] - 'A'];
//	}
//
//	// 2�� ���� ������ ��� �ݺ�
//	int size = A.size() * 2;
//	while (size != 2)
//	{
//		for (int i = 0; i < size - 1; i++)
//		{
//			int x = gunghab[i] + gunghab[i + 1];
//			gunghab[i] = x % 10;
//		}
//		size--;
//	}
//	cout << gunghab[0] << gunghab[1];
//	
//
//	return 0;
//}
//
//// A A A A A A
//// 3 3 3 3 3 3
////  6 6 6 6 6
////   2 2 2 2
////    4 4 4
////     8 8