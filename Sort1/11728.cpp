//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 16. ȭ
//// ���� ��ȣ	: #11728 
//// ���� �̸�	: �迭 ��ġ��
//// �˰���	: 
//// �ð����⵵: O()
//
//int M, N;
//
//// ���ĵ� �� �迭
//int A[1'000'000];
//int B[1'000'000];
//int resultArr[1'000'000];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> M >> N;
//	for (int i = 0; i < M; i++)
//		cin >> A[i];
//
//	for (int i = 0; i < N; i++)
//		cin >> B[i];
//
//	int aPos = 0;
//	int bPos = 0;
//	int cnt = 0;
//
//	// aPos, bPos �� �� �ϳ��� M, N �� ������ ������
//	while (aPos < M && bPos < N)
//	{
//		if (A[aPos] <= B[bPos])
//		{
//			resultArr[cnt++] = A[aPos++];
//		}
//		else
//		{
//			resultArr[cnt++] = B[bPos++];
//		}
//	}
//
//	// ���� �͵�
//	for (; aPos < M; aPos++)
//	{
//		resultArr[cnt++] = A[aPos];
//	}
//
//	for (; bPos < N; bPos++)
//	{
//		resultArr[cnt++] = B[bPos];
//	}
//
//	// ���ĵ� �迭 ���
//	for (int i = 0; i < cnt; i++)
//	{
//		cout << resultArr[i] << " ";
//	}
//
//	return 0;
//}