//#include <iostream>
//#include <string>
//#include <cctype>	// isdigit
//#include <algorithm>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 19. ��
//// ���� ��ȣ	: #2870 
//// ���� �̸�	: ���м���
//// �˰���	: ���ڿ�
//// �ð����⵵: O()
//
//int N, M; // M : ã�� ���� ����
//int numArr[5005]; // 100�� * (1�ٴ� �ִ� 50) = 5000
//
//string strArr[5005];
//
//bool compare(string A, string B)
//{
//	// string �񱳴� ������ ��
//	if (A.size() == B.size())
//	{
//		return A < B;
//	}
//	else
//	{
//		return A.size() < B.size();
//	}
//
//
//	// �񳻸����� ����(1 3 4 10 10 99)
//	// 1. ���̰� �ٸ� ���, ª�� ���ڿ��� �տ� ��ġ
//	// 2. ���̰� ���� ���, ���� �ڸ����� �� ��, ���� �� ������
//	// 2.1 ���� ����, �� ��ü�� ���� ��� false ���� -> strict weak ordering
//
//	// ���� ����,
//	//if (A.size() == B.size())
//	//{
//	//	// ���� �ڸ�����, �ڸ��� �� // (= strcmp)
//	//	for (int i = 0; i < A.size(); i++)
//	//	{
//	//		if (A[i] == B[i])
//	//			continue;
//	//	
//	//		// A�� ���� �� true ���� -> �տ� ��ġ
//	//		return A[i] < B[i];
//	//	}
//
//	//	// A == B -> strict weak ordering
//	//	return false;
//	//}
//
//	//// ª�� ���ڿ��� �տ� ��ġ
//	//// A�� ª���� true ���� -> A�� �տ� ��ġ
//	//return (A.size() < B.size());
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		string s;
//		cin >> s;
//
//		// �ݷ� : 10^99 �Է¹�����,,
//		// 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
//
//		// 1. ���� ������ ã��
//		for (int numSt = 0; numSt < s.size(); numSt++)
//		{
//			// ���� �ƴϸ� pass
//			if (!isdigit(s[numSt]))
//				continue;
//
//			// (0~9) ���� ���°� �ƴϰ� 99 ���� �� ���� �ؾ���.
//			// 2. ���� ���� ã��
//			int numLast = numSt + 1; 
//			while (numLast < s.size() && isdigit(s[numLast]))
//			{
//				numLast++;
//			}
//			
//			// 3. �� �ڸ��� ���
//			int numDigit = numLast - numSt; // num �ڸ��� ���
//			//int num = stoi(s.substr(numSt, numDigit));			// out-of-range
//			// ū �� ����.. -> ���ڿ��� �ذ� <<
//			//numArr[M++] = num;
//
//			// 4. ū �� ���� -> ���ڿ� ��ü�� ����
//			string sub = s.substr(numSt, numDigit);
//
//			// ����ó�� : 009 -> 9
//			while (sub.size() > 1 && sub[0] == '0')
//			{
//				sub.erase(0, 1);
//			}
//			
//
//			strArr[M++] = sub;
//
//			// ���� ����������
//			numSt += numDigit;
//		}
//	}
//
//	// string �� ����
//	sort(strArr, strArr + M, compare);
//
//	for (int i = 0; i < M; i++)
//		cout << strArr[i] << '\n';
//
//	return 0;
//}