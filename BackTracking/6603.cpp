//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 15. ��
//// ���� ��ȣ	: #6603
//// ���� �̸�	: �ζ�
//// �˰���	: 
//// �ð����⵵: O()
//
//int S[13];
//int lotto[6];
//bool isused[13];
//int K = -1;
//
//void func(int cnt, int st)
//{
//	// �ζǹ�ȣ 6�� ���
//	if (cnt == 6)
//	{
//		for (int i = 0; i < 6; i++)
//			cout << lotto[i] << " ";
//		cout << '\n';
//
//		return;
//	}
//
//	for (int i = st; i < K; i++)
//	{
//		if (isused[i] == 1)
//			continue;
//
//		isused[i] = 1;
//		
//		lotto[cnt] = S[i];
//
//		func(cnt + 1, i + 1);
//
//		isused[i] = 0;
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	while (K != 0)
//	{
//		cin >> K;
//		for (int i = 0; i < K; i++)
//		{
//			cin >> S[i];
//		}
//
//		func(0, 0);
//
//		cout << '\n';
//	}
//	
//
//	return 0;
//}