//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 19. ��
//// ���� ��ȣ	: #1969 
//// ���� �̸�	: DNA
//// �˰���	: ���ڿ�
//// �ð����⵵: O()
//
//int N, M, ans;
//string DNA[1005];
//string s;
//
//char acgt[4] = { 'A', 'C', 'G', 'T' };
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> DNA[i];
//	}
//
//	for (int i = 0; i < M; i++)
//	{
//		// Hamming Distance ���� ���̱� ����,
//		// �־��� DNA �� �� �ڸ�����, (A,C,G,T) ��� �� ���Դ� �� �����ϰ�,
//		// ���� ���� ���� ����
//
//		// (a,c,g,t) �� �迭
//		int freq[4] = { 0, }; // ������ ACGT
//		
//		// �ڸ����� ���鼭 ����
//		for (int j = 0; j < N; j++)
//		{
//			char c = DNA[j][i];
//
//			switch (c)
//			{
//			case 'A':
//				freq[0]++;
//				break;
//			case 'C':
//				freq[1]++;
//				break;
//			case 'G':
//				freq[2]++;
//				break;
//			case 'T':
//				freq[3]++;
//				break;
//			}
//		}
//
//		for (int i = 0; i < 4; i++)
//		{
//			// �̹� acgt ������ ������ ���ĵǾ� �־,
//			// ã���� break �ϸ� ��.
//			if (freq[i] == *max_element(freq, freq + 4))
//			{
//				// DNA s 
//				s += acgt[i];
//
//				// Hamming Distance ������
//				ans += (N - freq[i]); // ��ü ���� - ���� �� ���� = �ٸ� �� ����
//				break;
//			}
//		}
//
//		//bool alreadyFound = false; // ������ �켱���� ����
//		//for (int i = 0; i < 4; i++)
//		//{
//		//	if (alreadyFound == false && freq[i] == *max_element(freq, freq + 4))
//		//	{
//		//		s += acgt[i];
//		//		alreadyFound = true;
//		//	}
//		//	else
//		//	{
//		//		ans += freq[i];
//		//	}
//		//}
//	}
//
//	cout << s << '\n';
//	cout << ans << '\n';
//
//	return 0;
//}