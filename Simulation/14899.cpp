//#include <iostream>
//#include <algorithm> // next_permutation
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 25. ȭ
//// ���� ��ȣ	: #14899 
//// ���� �̸�	: ��ŸƮ�� ��ũ
//// �˰���	: �ùķ��̼�, ����(nCr, next_permutation)
//// �ð����⵵: O()
//
//int N; // <= 20, ¦��
//int chemistryArr[25][25]; // �ɷ�ġ �迭
//
//int min_diff = 1000; // �̴ϸ� �ɷ�ġ ����, �ִ񰪺��� �� �� ũ�� �ʱ�ȭ
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// �ɷ�ġ �迭 �Է�
//	cin >> N;
//	for (int r = 0; r < N; r++)
//		for (int c = 0; c < N; c++)
//			cin >> chemistryArr[r][c];
//
//	// nC(n/2) ���� ����� ��
//	int idx[20] = { 0, };
//	fill(idx + N / 2, idx + N, 1); // 0 N/2 ��, 1 N/2�� �ʱ�ȭ
//
//	// 20C10 = 184'756��
//	do
//	{
//		// ��ŸƮ��, ��ũ�� �ɷ�ġ ���� �ʱ�ȭ
//		int total_point_start_team = 0;
//		int total_point_link_team = 0;
//
//		// ���� �ɷ�ġ ��� (N/2)C2 ����
//		// N/2 ���� ���� �߿��� 2�� ¦ ���� �ɷ�ġ �� ���
//		// 20 * 20��
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				// ���� �����ϰ�,
//				if (j == i) continue;
//
//				// ���� ������ �ɷ�ġ �� ���
//				if (idx[i] != idx[j]) continue;
//
//				if (idx[i] == 0) total_point_start_team += chemistryArr[i][j];
//				if (idx[i] == 1) total_point_link_team += chemistryArr[i][j];
//			}
//		}
//
//		// �̴ϸ� ����
//		min_diff = std::min(min_diff, std::abs(total_point_start_team - total_point_link_team));
//
//	} while (next_permutation(idx, idx + N));
//
//	// ��� ���
//	cout << min_diff;
//
//	return 0;
//}