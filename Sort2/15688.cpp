//#include <iostream>
//
//using namespace std;
//
//const int absSize = 1'000'000; // ���� ũ��
//int N;
//int freq[absSize * 2 + 5]; // -1'000'000 ~ 1'000'000
//// + 1'000'000
//// 0 ~ 2'000'000
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ī���� ��Ʈ
//	// O(N+K)
//
//	cin >> N;
//
//	// O(N)
//	for (int i = 0; i < N; i++)
//	{
//		int x;
//		cin >> x;
//
//		// -1'000'000 ~ 1'000'000 ���� ����
//		freq[x + absSize]++;
//	}
//
//	// O(K)
//	// freq �迭 ��ȸ�ϸ鼭, ����ŭ ���
//	for (int i = 0; i <= 2 * absSize; i++)
//	{
//		while (freq[i]--)
//		{
//			// ���� ����
//			cout << i - absSize << '\n';
//			//freq[i]--;
//		}
//	}
//
//	return 0;
//}