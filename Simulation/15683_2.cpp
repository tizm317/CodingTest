//#include <iostream>
//#include <vector>
//#include <utility>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 19. ��
//// ���� ��ȣ	: #15683 
//// ���� �̸�	: ����
//// �˰���	: �ùķ��̼�
//// �ð����⵵: O()
//
//int ROW, COL; // 1 <= x <= 8
//vector<vector<int>> mapVec;
//vector<vector<int>> sightVec; // �þ� ǥ�� 1(�� �� �ִ°�+��,CCTV��ġ) , 0 �簢����
//vector<pair<int, int>> cctvVec; // CCTV ��ġ
//
//// ��->��->��->��
//const int dROW[4] = {-1, 0, 1, 0};
//const int dCOL[4] = {0, 1, 0, -1};
//
//int minBlindSpotCnt = 64;
//
//bool isInArrBounds(const int row, const int col)
//{
//	if (row < 0 || row >= ROW || col < 0 || col >= COL)
//		return false;
//	else
//		return true;
//}
//
//void cctv1(const int curRow, const int curCol, const int dir, vector<vector<int>>& vec)
//{
//	//cout << &vec << '\n';
//	//cout << &vec[0][0] << '\n';
//
//	// CCTV 1
//	// dir �������� ��, �迭 ������ ����
//	
//	int nRow = curRow;
//	int nCol = curCol;
//
//	while (true)
//	{
//		/*if (dir < 0 || dir >= 4)
//			cout << dir << '\n'; */
//
//		nRow += dROW[dir % 4];
//		nCol += dCOL[dir % 4];
//
//		// �迭 ���� ����ų�, �� ������ Ż��
//		if (isInArrBounds(nRow, nCol) == false || mapVec[nRow][nCol] == 6)
//			break;
//
//		// �þ� ǥ��
//		vec[nRow][nCol] = 1;
//	}
//
//}
//void cctv2(const int curRow, const int curCol, const int dir, vector<vector<int>>& vec)
//{
//	//cout << &vec << '\n';
//	//cout << &vec[0][0] << '\n';
//
//	// CCTV 2
//	// dir ����, -dir �������� ��, �迭 ������ ����
//	//const initializer_list<int> il = (dir % 2 == 0) ? initializer_list<int>{ 0,2 } : initializer_list<int>{ 1,3 };
//
//	//cout << &il;
//	//cout << il.begin() << " " << (il.begin() + 1);
//	//cout << *il.begin() << " " << *(il.begin() + 1);
//
//	// ������, ������ �� 2��
//	//for (int d : il)
//	int d = dir;
//	for(int i = 0; i < 2; i++)
//	{
//		if (i == 1)
//		{
//			d = dir + 2;
//		}
//
//		int nRow = curRow;
//		int nCol = curCol;
//
//		while (true)
//		{
//			/*if (d < 0 || d >= 4)
//				cout << d << '\n';*/
//			nRow += dROW[d];
//			nCol += dCOL[d];
//
//			// �迭 ���� ����ų�, �� ������ Ż��
//			if (isInArrBounds(nRow, nCol) == false || mapVec[nRow][nCol] == 6)
//				break;
//
//			// �þ� ǥ��
//			vec[nRow][nCol] = 1;
//		}
//	}
//
//}
//void cctv3(const int curRow, const int curCol, const int dir, vector<vector<int>>& vec)
//{
//	//cout << &vec << '\n';
//	//cout << &vec[0][0] << '\n';
//
//	// CCTV 3 (2����)
//	// dir ����, dir �� ���� ������ �������� ��, �迭 ������ ����
//	// 0 -> 0,1
//	// 1 -> 1,2
//	// 2 -> 2,3
//	// 3 -> 3,4 -> 3,0
//	//const initializer_list<int> il = (dir == 0) ? initializer_list<int>{ 0, 1 } 
//	//: (dir == 1) ? initializer_list<int>{ 1, 2 }
//	//: (dir == 2) ? initializer_list<int>{ 2, 3 }
//	//: initializer_list<int>{ 3, 0 };
//
//	//for (int d : il)
//	for(int d = dir; d <= dir + 1; d++)
//	{
//		int nRow = curRow;
//		int nCol = curCol;
//
//		while (true)
//		{
//			/*if (d < 0 || d >= 4)
//				cout << d << '\n';*/
//			nRow += dROW[d % 4];
//			nCol += dCOL[d % 4];
//
//			// �迭 ���� ����ų�, �� ������ Ż��
//			if (isInArrBounds(nRow, nCol) == false || mapVec[nRow][nCol] == 6)
//				break;
//
//			// �þ� ǥ��
//			vec[nRow][nCol] = 1;
//		}
//	}
//}
//void cctv4(const int curRow, const int curCol, const int dir, vector<vector<int>>& vec)
//{
//	//cout << &vec << '\n';
//	//cout << &vec[0][0] << '\n';
//
//	// CCTV 4 (3����)
//	// dir ����, dir �� ������ ���� ���� 2�� �� ��, �迭 ������ ����
//	//const initializer_list<int> il = (dir == 0) ? initializer_list<int>{ 3, 0, 1}
//	//: (dir == 1) ? initializer_list<int>{ 0, 1, 2 }
//	//: (dir == 2) ? initializer_list<int>{ 1, 2, 3 }
//	//: initializer_list<int>{ 2, 3, 0 };
//
//	//for (int d : il)
//	for(int d = 0; d < 4; d++)
//	{
//		if (dir == 0 && d == 2) continue;
//		if (dir == 1 && d == 3) continue;
//		if (dir == 2 && d == 0) continue;
//		if (dir == 3 && d == 1) continue;
//
//		int nRow = curRow;
//		int nCol = curCol;
//
//		while (true)
//		{
//			/*if (d < 0 || d >= 4)
//				cout << d << '\n';*/
//			nRow += dROW[d];
//			nCol += dCOL[d];
//
//			// �迭 ���� ����ų�, �� ������ Ż��
//			if (isInArrBounds(nRow, nCol) == false || mapVec[nRow][nCol] == 6)
//				break;
//
//			// �þ� ǥ��
//			vec[nRow][nCol] = 1;
//		}
//	}
//}
//void cctv5(const int curRow, const int curCol, const int dir, vector<vector<int>>& vec)
//{
//	//cout << &vec << '\n';
//	//cout << &vec[0][0] << '\n';
//
//	// CCTV 5 (4����)
//	// ��� �������� ��, �迭 ������ ����
//	//const initializer_list<int> il = { 0,1,2,3 };
//
//	//for (int d : il)
//	for(int d = 0; d < 4; d++)
//	{
//		int nRow = curRow;
//		int nCol = curCol;
//
//		while (true)
//		{
//			/*if(d < 0 || d >= 4)
//				cout << d << '\n';*/
//			nRow += dROW[d];
//			nCol += dCOL[d];
//
//			// �迭 ���� ����ų�, �� ������ Ż��
//			if (isInArrBounds(nRow, nCol) == false || mapVec[nRow][nCol] == 6)
//				break;
//
//			// �þ� ǥ��
//			vec[nRow][nCol] = 1;
//		}
//	}
//}
//
//void myfunc(const int cctvIdx, const vector<vector<int>>& curSightVec)
//{
//	// idx �� �Ѿ�� ����
//	if (cctvIdx >= cctvVec.size())
//	{
//		// �簢���� ī����
//		int blindSpotCnt = 0;
//		for (auto row : curSightVec)
//		{
//			for (auto x : row)
//			{
//				if (x == 0)
//					blindSpotCnt++;
//			}
//		}
//
//		minBlindSpotCnt = std::min(minBlindSpotCnt, blindSpotCnt);
//
//		return;
//	}
//
//	// ���� cctv �� ���� ����
//	const pair<int, int> curPos = *(cctvVec.begin() + cctvIdx);
//
//	// cctv Type �� mapVec ���� ������
//	const int cctvTypeNum = mapVec[curPos.first][curPos.second];
//
//	// 4���⿡ ���ؼ�...
//	vector<vector<int>> nxtSightVec;
//	for (int dir = 0; dir < 4; dir++)
//	{
//		// sightVec ������� ����
//		nxtSightVec = curSightVec;
//
//		// Type���� ���� ����
//		switch (cctvTypeNum)
//		{
//		case 1:
//			//cout << &tmpVec << '\n';
//			//cout << &tmpVec[0][0] << '\n';
//			cctv1(curPos.first, curPos.second, dir, nxtSightVec);
//			break;
//		case 2:
//			if(dir < 2)
//				cctv2(curPos.first, curPos.second, dir, nxtSightVec);
//			break;
//		case 3:
//			cctv3(curPos.first, curPos.second, dir, nxtSightVec);
//			break;
//		case 4:
//			cctv4(curPos.first, curPos.second, dir, nxtSightVec);
//			break;
//		case 5:
//			if(dir == 0)
//				cctv5(curPos.first, curPos.second, dir, nxtSightVec);
//			break;
//		default:
//			cout << "WRONG" << '\n';
//			break;
//		}
//
//		// ���� cctv�� ���� ����
//		myfunc(cctvIdx + 1, nxtSightVec);
//	}
//	
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// �繫�� map �Է�
//	cin >> ROW >> COL;
//	for (int r = 0; r < ROW; r++)
//	{
//		vector<int> tmpVec;
//		vector<int> tmpVec2;
//
//		for (int c = 0; c < COL; c++)
//		{
//			int x;
//			cin >> x;
//
//			tmpVec.push_back(x);
//
//			// ������� �þ� 0���� ä��
//			if (x == 0)
//				tmpVec2.push_back(0);
//			else
//			{
//				// cctv, �� �þ� 1�� ä��
//				tmpVec2.push_back(1);
//
//				// cctv ��ġ ����
//				if (x != 6)
//				{
//					cctvVec.push_back({ r,c });
//				}
//			}
//		}
//		mapVec.push_back(tmpVec);
//		sightVec.push_back(tmpVec2);
//	}
//
//	myfunc(0, sightVec);
//
//	cout << minBlindSpotCnt;
//
//	return 0;
//}
//
//
//// ���� �ù� �׷��� �ᱹ �׳� initialize_list ����� ����(�� ������ ����???) �� ������ ������ų�?
//// ���� ������ ã��
//// 1) initialize_list -> ��Ȯ���� �𸣰�����! for������ ��������� ������� ����. (�ʱ�ȭ ������ �� �������..)
////	- �ӽ� �迭�� ����Ű�� ��ü
////  - �ʱ�ȭ �� �ӽ� �迭 �����
////  - ���簡 �ȵ�
////  - [] ������ ��� �Ұ�
////  - �⺻ �迭�� const T[N] ���� �� �ӽ� �迭�̸� , 
//// ���⼭ �� ��Ҵ� ���� �ʱ�ȭ ����� �ش� ��ҿ��� ���� �ʱ�ȭ �˴ϴ�(��� ��ȯ�� ��ȿ���� ���� ����). 
//// �⺻ �迭�� ������ �迭���� initializer_list ��ü�� �ʱ�ȭ�ϴ� ���� �ӽÿ� ���� ������ ���ε��ϴ� �Ͱ� �Ȱ��� �迭�� ������ �����Ѵٴ� ���� �����ϸ�
////  �ٸ� �ӽ� ��ü �� �����մϴ�(�� -���� Ŭ���� ���). 
//// �⺻ �迭�� �б� ���� �޸𸮿� �Ҵ�� �� �ֽ��ϴ�. const T[N]
//// std::initializer_list �� ��� �� �Ǵ� �κ� Ư��ȭ �� ���� �Ǹ� ���α׷��� �߸� �����˴ϴ� . -> �����, �κ� Ư��ȭ�� ����?
//// https://runebook.dev/ko/docs/cpp/utility/initializer_list
//
//// 2) 3�� ������ -> �ϴ� �̰� �ƴ�, �� ����ϰ� �־���