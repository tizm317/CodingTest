//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 01. ��
//// ���� ��ȣ	: #7795
//// ���� �̸�	: ���� ���ΰ� ���� ���ΰ�
//// �˰���	: ����  (�Ǵ� �̺� Ž��)
//// �ð����⵵: O()
//
//int T;
//int N, M;
//int A[20'005];
//int B[20'005];
//
//bool cmp(int a, int b)
//{
//	return a > b;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		cin >> N >> M;
//		
//		for (int j = 0; j < N; j++)
//			cin >> A[j];
//
//		for (int j = 0; j < M; j++)
//			cin >> B[j];
//
//		// �������� ����
//		sort(A, A + N, cmp);
//		sort(B, B + M, cmp);
//
//		int cnt = 0;
//
//		// �ð� ����
//		vector<int> cntVec;
//		cntVec.push_back(M);
//
//		for (int i = 0; i < N; i++)
//		{
//			//for (int j = 0; j < M; j++)
//			for (int j = M - cntVec.back(); j < M; j++)
//			{
//				if (A[i] > B[j])
//				{
//					cntVec.push_back(M - j);
//					cnt += M - j;
//					break;
//				}
//			}
//		}
//
//		cout << cnt << '\n';
//	}
//
//	
//
//	// 8 1 7 3 1 -> 8 7 3 1 1
//	// 3 6 1 -> 6 3 1
//	// 3 0 3 1 0
//
//	return 0;
//}