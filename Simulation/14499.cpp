//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 20. ��
//// ���� ��ȣ	: #14499 
//// ���� �̸�	: �ֻ��� ������
//// �˰���	: �ùķ��̼�
//// �ð����⵵: O()
//
//// ����
//int R, C; // 1 <= R,C <= 20
//int map[30][30];
//
//// �ֻ��� ���� ��ǥ
//int x, y;
//
//// �̵� Ƚ��
//int K;
//
//// �����ϳ� ��ǥ �̵�
//const int dRow[4] = {0, 0, -1, 1};
//const int dCol[4] = {1, -1, 0, 0};
//
//// �ֻ��� ĭ ���� �迭
//// idx  : 0  1  2  3  4  5
//// ��ġ : �� �� �� ��  �� ��
//const int diceSideCnt = 6;
//int dice[diceSideCnt];
//
//// �迭 2���� �� ���� ����
//// dice1[0] = dice2[0]
//// dice1[2] = dice2[2]
//int dice1[4]; // ���� ���� (��,��,��,��)
//int dice2[4]; // ���� ���� (��,��,��,��)
//
//enum Edice
//{
//	BOTTOM,
//	EAST,
//	NORTH,
//	SOUTH,
//	WEST,
//	TOP,
//};
//
//void diceMove(int dir);
//void diceRotate(int dir);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ���� ũ��, �ֻ��� ��ǥ, �̵� Ƚ�� �Է�
//	cin >> R >> C >> x >> y >> K;
//
//	// ���� �Է�
//	for (int r = 0; r < R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			cin >> map[r][c];
//		}
//	}
//
//	// �̵�
//	while (K--)
//	{
//		// �̵� ��� ����
//		int dir;
//		cin >> dir;
//
//		// ���� ��ǥ ���
//		int nRow = x + dRow[dir - 1];
//		int nCol = y + dCol[dir - 1];
//
//		// �迭 ���� üũ -> ȸ�� ���� �ϴ���, �� �κп��� üũ ����� ��. (�� �׷��� ȸ���� �ϰ� �̵��� �� �ϴ� ������ ����)
//		if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C)
//			continue;
//
//		// dir�� 1-based -> 0-based idx �� ��ȯ (dir - 1)
//		
//		// 1. �ֻ��� ȸ��
//		diceRotate(dir - 1);
//
//		// 2. �ֻ��� �̵�
//		diceMove(dir - 1); 
//		
//		// 3. ȸ�� ��, �ֻ��� ���� ���
//		//cout << dice[diceSideCnt - 1] << '\n';
//		cout << dice1[2] << '\n';
//		//cout << "�ֻ��� ���� : " << dice[5] << '\n';
//	}
//
//	return 0;
//}
//
//void diceMove(int dir)
//{
//	// ���� ��ǥ ���
//	int nRow = x + dRow[dir];
//	int nCol = y + dCol[dir];
//
//	// �迭 ���� üũ
//	if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C)
//		return;
//
//	// ������ 0�� ���
//	if (map[nRow][nCol] == 0)
//	{
//		// �ֻ��� �ٴڸ��� ���� ���� ���� ����
//			// map[nRow][nCol] = ȸ�� �� �ֻ��� �Ʒ���;
//		//map[nRow][nCol] = dice[Edice::BOTTOM];
//		map[nRow][nCol] = dice1[0];
//
//	}
//	else // ������ ���� 0�� �ƴ� �ٸ� ���� ���
//	{
//		// ���� ���� ���� �ֻ����� ����
//			// ȸ�� ��!(ȸ�� �����ϵ��� ���� ����) �ֻ��� �Ʒ��� = map[nRow][nCol];
//		//dice[Edice::BOTTOM] = map[nRow][nCol];
//		dice1[0] = map[nRow][nCol];
//		dice2[0] = dice1[0];
//
//		// ���� ���� ���� 0�� ��.
//		map[nRow][nCol] = 0;
//	}
//
//	// �ֻ��� ��ǥ �̵�
//	x = nRow;
//	y = nCol;
//}
//
//void diceRotate(int dir)
//{
//	// ȸ���� ����� ���� �ӽ� �迭 �ʱ�ȭ
//	//int tmp[diceSideCnt];
//	//for (int i = 0; i < diceSideCnt; i++)
//	//	tmp[i] = dice[i];
//
//
//
//	// <<< �� �κ� �����غ���! >>>
//	// >> enum ����ؼ� ���� �ϱ� �ߴµ�, �������̾� ���� �ö��� �ϴ���, 
//	// >> �ߺ��� �κ��� �ʹ� ����.
//	// >> >> ��� �� dir �� enum ���� �ٲٴ� ���� ���ƺ��̴µ�..
//
//	// >> �ٸ� ������� �ٲ�ôµ� �׷��� ���� ��ħ.
//
//	int tmp;
//	switch (dir)
//	{
//		// ��, �� ȸ�� dice1 �̿�
//	case 0:
//		tmp = dice1[0];
//		copy(dice1 + 1, dice1 + 4, dice1);
//		dice1[3] = tmp;
//
//		// ��� dice1, dice2 ����ȭ
//		dice2[0] = dice1[0];
//		dice2[2] = dice1[2];
//		break;
//	case 1:
//		tmp = dice1[3];
//		copy(dice1, dice1 + 3, dice1 + 1);
//		dice1[0] = tmp;
//
//		// ��� dice1, dice2 ����ȭ
//		dice2[0] = dice1[0];
//		dice2[2] = dice1[2];
//		break;
//		// ��, �� ȸ�� dice2 �̿�
//	case 2:
//		tmp = dice2[0];
//		copy(dice2 + 1, dice2 + 4, dice2);
//		dice2[3] = tmp;
//
//		// ��� dice1, dice2 ����ȭ
//		dice1[0] = dice2[0];
//		dice1[2] = dice2[2];
//		break;
//	case 3:
//		tmp = dice2[3];
//		copy(dice2, dice2 + 3, dice2 + 1);
//		dice2[0] = tmp;
//
//		// ��� dice1, dice2 ����ȭ
//		dice1[0] = dice2[0];
//		dice1[2] = dice2[2];
//		break;
//	}
//
//	
//
//
//	/*
//	switch (dir)
//	{
//		// ��, �� ȸ�� (��/�� ����)
//	case 0:
//		tmp[Edice::WEST] = dice[BOTTOM];
//		tmp[EAST] = dice[TOP];
//		tmp[TOP] = dice[WEST];
//		tmp[BOTTOM] = dice[EAST];
//		break;
//	case 1:
//		tmp[EAST] = dice[BOTTOM];
//		tmp[WEST] = dice[TOP];
//		tmp[BOTTOM] = dice[WEST];
//		tmp[TOP] = dice[EAST];
//		break;
//
//		// ��, �� ȸ�� (��/�� ����)
//	case 2:
//		tmp[SOUTH] = dice[BOTTOM];
//		tmp[NORTH] = dice[TOP];
//		tmp[BOTTOM] = dice[NORTH];
//		tmp[TOP] = dice[SOUTH];
//		break;
//	case 3:
//		tmp[NORTH] = dice[BOTTOM];
//		tmp[SOUTH] = dice[TOP];
//		tmp[TOP] = dice[NORTH];
//		tmp[BOTTOM] = dice[SOUTH];
//		break;
//	}
//
//	// ��� �迭�� dice �迭 ������
//	for (int i = 0; i < diceSideCnt; i++)
//		dice[i] = tmp[i];
//	*/
//	
//}