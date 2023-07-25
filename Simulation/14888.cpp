//#include <iostream>
//#include <algorithm> // next_permutation
//#include <vector>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 20223. 07. 25. ȭ
//// ���� ��ȣ	: #14888 
//// ���� �̸�	: ������ �����ֱ�
//// �˰���	: �ùķ��̼�, ����(�ߺ�����?)
//// �ð����⵵: O()
//
//int N; // <= 11
//int minValue = 1'000'000'000, maxValue = -1'000'000'000; // �ִ�, �ּ� +- 10��
//int num[15];
//
//// +, -, *, /
//// 0, 1, 2, 3
////int operators[10];
//vector<int> operators;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// �ǿ����� (��) �Է�
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		cin >> num[i];
//
//	// ������ �Է�
//	// +, -, *, / ����
//		// opCnt �Է� �޾Ƽ�, opCnt ��ŭ operators ���Ϳ� �־���
//	for (int i = 0; i < 4; i++)
//	{
//		int opCnt;
//		cin >> opCnt;
//
//		while (opCnt--)
//		{
//			operators.push_back(i);
//		}
//	}
//
//	// nPr ���� ����� ��
//	int idx[10] = { 0, };
//	for (int i = 0; i < N - 1; i++)
//		idx[i] = i;
//	do
//	{
//		// �� ���
//		int res = num[0];
//		for (int i = 1; i < N; i++)
//		{
//			// �����ڿ� ���� ���
//			switch (operators[idx[i - 1]])
//			{
//			case 0: // +
//				res += num[i];
//				break;
//			case 1: // -
//				res -= num[i];
//				break;
//			case 2: // *
//				res *= num[i];
//				break;
//			case 3: // /
//				res /= num[i];
//				break;
//			}
//		}
//
//		minValue = std::min(minValue, res);
//		maxValue = std::max(maxValue, res);
//
//	} while (next_permutation(idx, idx + N - 1));
//
//	cout << maxValue << '\n' << minValue;
//
//	return 0;
//}