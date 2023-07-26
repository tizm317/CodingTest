//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 26. ��
//// ���� ��ȣ	: #15684 
//// ���� �̸�	: ��ٸ� ����
//// �˰���	: �ùķ��̼�, ��Ʈ��ŷ?
//// �ð����⵵: O()
//
//int N; // ���� ���� ���� <= 10
//int M; // ���� ���� ���� (�ִ� 270)
//int H; // ���� �� ���� �� �ִ� ��ġ ���� <= 30
//
//// ��ٸ� �迭
//// ���� 1 <= a <= H
//// ���� 1 <= b : b, b+1 ���� <= N-1
//int ladder[35][15]; // ���� H, ���� N
//// 0 : ���� ���� ���� ���μ� ��ġ
//// 1 : ����� ���μ� (��ġ)
//// -1 : ������ �� ���� ���μ� ��ġ (���� ����� ���μ��� ���� ���)
//
//int ans = -1;
//
//// ��ü ��ٸ� Ÿ��
//bool ladderMove(const int ladder[35][15]);
//
//// ��ٸ��� ������ �߰��ϴ� �Լ�
//void addVerticalLine(int addedVerticalLineCnt, int ladder[35][15], int rr, int cc);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M >> H;
//
//	// ���� �� ��ġ �Է�
//	for (int r = 0; r < M; r++)
//	{
//		int a, b;
//		cin >> a >> b;
//		
//		// a�� ���� ��ġ�� b, b+1 ���� ǥ��
//		ladder[a][b] = 1;
//		
//		// �¿� ������ ���� ��ġ ���� �Ұ��� -1 ǥ��
//			// a�� ���� ��ġ�� b-1, b ���� �Ұ���	
//		ladder[a][b - 1] = -1;
//			// a�� ���� ��ġ�� b, b+1 ���� �Ұ���	
//		ladder[a][b + 1] = -1;
//	}
//
//	addVerticalLine(0, ladder, 1, 1);
//
//	cout << ans;
//
//	return 0;
//}
//
//// ��ü ��ٸ� Ÿ��
//bool ladderMove(const int ladder[35][15])
//{
//	// O(N*H)
//
//	// ������ ���۳ѹ� 
//	for (int startLine = 1; startLine <= N; startLine++)
//	{
//		// ���� �ٳѹ�
//		int curLineNum = startLine;
//
//		// �Ʒ��� �̵�
//		for (int c = 1; c <= H; c++)
//		{
//			// (��/��) ������� ������ �Ʒ��� �̵� continue
//			if (ladder[c][curLineNum] != 1 && ladder[c][curLineNum - 1] != 1)
//				continue;
//
//			// ������ �̵� (curLineNum, curLineNum+1) ����
//			if (ladder[c][curLineNum] == 1)
//			{
//				curLineNum++;
//				continue;
//			}
//
//			// ���� �̵� (curLineNum-1, curLineNum) ����
//			if (ladder[c][curLineNum - 1] == 1)
//			{
//				curLineNum--;
//				continue;
//			}
//		}
//
//		// �� �Ʒ� ���� - ���۶��γѹ��� �������γѹ� �ٸ� ��� false
//		if (curLineNum != startLine)
//			return false;
//	}
//
//	// ��� �������� ���۶��γѹ��� �������γѹ� ���� ��� true
//	return true;
//}
//
//// ��ٸ��� ������ �߰��ϴ� �Լ�
////bool isSuccess = false;
//void addVerticalLine(const int addedVerticalLineCnt, int ladder[35][15], int rr, int cc)
//{
//	// 0. i�� ���μ��� ����� i�� �������� Ȯ��
//	if (ladderMove(ladder) == true)
//	{
//		ans = (ans == -1) ? addedVerticalLineCnt : min(ans, addedVerticalLineCnt);
//		//isSuccess = true; // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< �ð��ʰ� �����Ϸ��� �ߴ� �� ������ ��������, cnt �� ���� ��� ������
//		return;
//	}
//
//	// �߰��� ���μ��� 3�� �̻��̸� return
//	if (addedVerticalLineCnt >= 3)
//		return;
//
//	//// ���� ��ٸ� ��ġ �ʱ�ȭ
//	//int nextLadder[35][15] = { 0, };
//	//for (int r = 0; r < 35; r++)
//	//	for (int c = 0; c < 15; c++)
//	//		nextLadder[r][c] = ladder[r][c];
//
//	// ���μ� �߰� ����� ��
//	for (int r = 1; r <= H; r++) // 1 ~ H
//	{
//		for (int c = 1; c <= N - 1; c++) // 1 ~ N-1
//		{
//			// ��ٸ� �� �� ���� �� ����
//			if (ladder[r][c] != 0)
//				continue;
//
//			// ���� ��ٸ� ���μ� �����ϴ� ��� ����<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//			if (r * (N - 1) + c < rr * (N - 1) + cc)
//				continue;
//
//			// ���ο� ��ٸ� ��ġ
//			ladder[r][c] = 1;
//			// ������ �¿� ��ٸ� ��ġ �Ұ�������
//			const int tmp1 = ladder[r][c - 1];
//			ladder[r][c - 1] = -1;
//			
//			const int tmp2 = ladder[r][c + 1];
//			ladder[r][c + 1] = -1;
//
//			addVerticalLine(addedVerticalLineCnt + 1, ladder, r, c); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//			/*if (isSuccess)
//				return;*/
//
//			// �߰��� ��ٸ� ����
//			ladder[r][c] = 0;
//			ladder[r][c - 1] = tmp1;
//			ladder[r][c + 1] = tmp2;
//		}
//	}
//
//}