////#include <iostream>
////using namespace std;
////
////// ���� ���� Ǯ��
////// ��¥		: 20xx. xx. xx.
////// ���� ��ȣ	: #00000 
////// ���� �̸�	: 
////// �˰���	: 
////// �ð����⵵: O()
////
////int N;
////int board[15][15];
////int possibleCnt;
////
////int row[15]; // 0 ~ 14
////int col[15];
////int rightUp[15 * 2 - 1]; // ����� �밢�� //  0 ~ 28
////int leftDown[15 * 2 - 1];// ������ �밢�� // 29
////
////void func(int queenCnt, int nextRow)
////{
////	// �� ������ N����, ����
////	if (queenCnt == N)
////	{
////		possibleCnt++;
////		return;
////	}
////
////	for (int r = nextRow; r < N; r++)
////	{
////		// 1. �ش� row�� �̹� ���� �����ϸ� continue
////		if (row[r] == 1)
////			continue;
////
////		for (int c = 0; c < N; c++)
////		{
////			if (board[r][c] == 1)
////				continue;
////
////			// 2. �ش� col�� �̹� ���� �����ϸ� continue
////			if (col[c] == 1)
////				continue;
////
////			// 3. �ش� �밢�� �ٿ� �̹� �� �����ϸ�,
////			if (rightUp[r + c] == 1)
////				continue;
////
////			// ���� ���� ������ + (N-1)
////			if (leftDown[r - c + N - 1] == 1)
////				continue;
////
////			// ��� ��츦 ����ϸ�,
////
////			board[r][c] = 1;
////			row[r] = 1;
////			col[c] = 1;
////			rightUp[r + c] = 1;
////			leftDown[r - c + N - 1] = 1;
////			
////			func(queenCnt + 1, r + 1);
////
////			board[r][c] = 0;
////			row[r] = 0;
////			col[c] = 0;
////			rightUp[r + c] = 0;
////			leftDown[r - c + N - 1] = 0;
////		}
////		
////		// row �� r�� ��쿡��, ��� col�� ����ģ ���
////		// ������ �ƿ� ���������
////		if (row[r] == 0)
////		{
////			return;
////		}
////	}
////}
////
////int main()
////{
////	ios_base::sync_with_stdio(false);
////	cin.tie(NULL);
////
////	cin >> N;
////	func(0, 0);
////	cout << possibleCnt;
////
////	return 0;
////}
//
//#include <iostream>
//using namespace std;
//
//int N;
//int totalCnt; // ������ ����� ��
//
//bool col[15];
//bool rightUp[15 * 2 - 1];
//bool leftDown[15 * 2 - 1];
//
//// row
//void func(int row)
//{
//	// row�� N��° �����ϸ� (= �� ���� N�� �������ٸ�)
//	if (row == N)
//	{
//		// ����� �� ����
//		totalCnt++;
//		return;
//	}
//
//	// row �� �� ��, col ���� �ݺ���
//	for (int c = 0; c < N; c++)
//	{
//		if (col[c] == 1)
//			continue;
//
//		if (rightUp[row + c] == 1)
//			continue;
//
//		if (leftDown[row - c + N - 1] == 1) // ���� ���� (N-1)
//			continue;
//
//		col[c] = 1;
//		rightUp[row + c] = 1;
//		leftDown[row - c + N - 1] = 1;
//		
//		// ���� ��
//		func(row + 1);
//
//		col[c] = 0;
//		rightUp[row + c] = 0;
//		leftDown[row - c + N - 1] = 0;
//	}
//
//}
//
//int main()
//{
//	cin >> N;
//	func(0);
//
//	cout << totalCnt;
//
//	return 0;
//}